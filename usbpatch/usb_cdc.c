/*
 * USB CDC-ACM device on the AT32F415 OTGFS controller. See usb_cdc.h.
 *
 * Endpoints: 0 control (64 B), 0x81 bulk IN / 0x01 bulk OUT (64 B, data),
 * 0x82 interrupt IN (8 B, CDC notifications, never used but required by the class).
 * FIFO RAM (320 words): RX 96, TX0 16, TX1 64, TX2 16.
 */
#include "usb_cdc.h"
#include "fw.h"

#define R(a) (*(volatile uint32_t *)(a))
#define OTG 0x50000000u
#define GOTGCTL     R(OTG + 0x000u)
#define GOTGINT     R(OTG + 0x004u)
#define GAHBCFG     R(OTG + 0x008u)
#define GUSBCFG     R(OTG + 0x00Cu)
#define GRSTCTL     R(OTG + 0x010u)
#define GINTSTS     R(OTG + 0x014u)
#define GINTMSK     R(OTG + 0x018u)
#define GRXSTSP     R(OTG + 0x020u)
#define GRXFSIZ     R(OTG + 0x024u)
#define DIEPTXF0    R(OTG + 0x028u)
#define GCCFG       R(OTG + 0x038u)
#define DIEPTXF(n)  R(OTG + 0x100u + 4u * (n))
#define DCFG        R(OTG + 0x800u)
#define DCTL        R(OTG + 0x804u)
#define DSTS        R(OTG + 0x808u)
#define DIEPMSK     R(OTG + 0x810u)
#define DOEPMSK     R(OTG + 0x814u)
#define DAINT       R(OTG + 0x818u)
#define DAINTMSK    R(OTG + 0x81Cu)
#define DIEPCTL(n)  R(OTG + 0x900u + 0x20u * (n))
#define DIEPINT(n)  R(OTG + 0x908u + 0x20u * (n))
#define DIEPTSIZ(n) R(OTG + 0x910u + 0x20u * (n))
#define DOEPCTL(n)  R(OTG + 0xB00u + 0x20u * (n))
#define DOEPINT(n)  R(OTG + 0xB08u + 0x20u * (n))
#define DOEPTSIZ(n) R(OTG + 0xB10u + 0x20u * (n))
#define PCGCCTL     R(OTG + 0xE00u)
#define FIFO(n)     R(OTG + 0x1000u + 0x1000u * (n))

#define CRM_CFG     R(0x40021004u)
#define CRM_AHBEN   R(0x40021014u)
#define NVIC_ISER2  R(0xE000E108u)
#define NVIC_ICER2  R(0xE000E188u)
#define NVIC_IPR67  (*(volatile uint8_t *)(0xE000E400u + 67u))
#define IRQ_BIT     (1u << (67u - 64u))

/* GUSBCFG */
#define FHMOD       (1u << 29)
#define FDMOD       (1u << 30)
/* GRSTCTL */
#define CSRST       (1u << 0)
#define RXFFLSH     (1u << 4)
#define TXFFLSH     (1u << 5)
#define TXFNUM(n)   ((uint32_t)(n) << 6)
#define AHBIDL      (1u << 31)
/* GINTSTS / GINTMSK */
#define RXFLVL      (1u << 4)
#define USBSUSP     (1u << 11)
#define USBRST      (1u << 12)
#define ENUMDNE     (1u << 13)
#define IEPINT      (1u << 18)
#define OEPINT      (1u << 19)
#define WKUPINT     (1u << 31)
/* GCCFG */
#define PWRDWN      (1u << 16)
#define VBUSASEN    (1u << 18)
#define VBUSBSEN    (1u << 19)
#define VBUSIG      (1u << 21)
/* GOTGINT */
#define SEDET       (1u << 2)
/* DCTL */
#define RWUSIG      (1u << 0)
#define SDIS        (1u << 1)
#define CGINAK      (1u << 8)
/* DxEPCTL */
#define EPENA       (1u << 31)
#define EPDIS       (1u << 30)
#define SD0PID      (1u << 28)
#define SNAK        (1u << 27)
#define CNAK        (1u << 26)
#define STALL       (1u << 21)
#define EPTYP_BULK  (2u << 18)
#define EPTYP_INTR  (3u << 18)
#define USBAEP      (1u << 15)
/* DxEPINT */
#define XFRC        (1u << 0)
#define EPDISD      (1u << 1)
#define TOC         (1u << 3)   /* IN */
#define STUP        (1u << 3)   /* OUT */
#define INEPNE      (1u << 6)
#define PKTCNT(n)   ((uint32_t)(n) << 19)
#define EP0_OUT_SETUP (3u << 29 | PKTCNT(1) | 64u)

#define RX_WORDS  96u
#define TX0_WORDS 16u
#define TX1_WORDS 64u
#define TX2_WORDS 16u

#define WAIT_N 200000u

#define USB_VID 0x2E3Cu   /* Artery */
#define USB_PID 0x5740u   /* Artery's virtual COM port example PID */

#define TXQ 512u   /* power of two */
#define RXQ 128u

static struct {
    uint8_t setup[8];
    uint8_t ep0buf[8];       /* OUT data stage (line coding) */
    uint8_t ep0_rx_expect;   /* waiting for an OUT data stage */
    uint8_t ep0_in_stage;    /* IN data stage in progress */
    uint8_t ep0_zlp;
    const uint8_t *ep0_ptr;
    uint16_t ep0_left;
    uint8_t reply[64];       /* GET_STATUS, string descriptors (<= 31 chars) */
    uint8_t line_coding[7];

    volatile uint8_t configured, suspended, dtr;
    volatile uint8_t tx_busy, tx_zlp, rx_armed;
    volatile uint16_t tx_head, tx_tail, rx_head, rx_tail;
    uint32_t resets;
    uint8_t txpkt[64];
    uint8_t txq[TXQ];
    uint8_t rxq[RXQ];
} u;

/* ---- descriptors ------------------------------------------------------------------------ */

static const uint8_t dev_desc[18] = {
    18, 1, 0x00, 0x02, 0x02, 0x00, 0x00, 64,
    USB_VID & 0xFF, USB_VID >> 8, USB_PID & 0xFF, USB_PID >> 8,
    0x00, 0x01, 1, 2, 3, 1,
};

static const uint8_t cfg_desc[67] = {
    9, 2, 67, 0, 2, 1, 0, 0x80, 50,
    /* interface 0: CDC communication, ACM */
    9, 4, 0, 0, 1, 0x02, 0x02, 0x01, 0,
    5, 0x24, 0x00, 0x10, 0x01,          /* header, CDC 1.10 */
    5, 0x24, 0x01, 0x00, 0x01,          /* call management */
    4, 0x24, 0x02, 0x02,                /* ACM: line coding + control line state */
    5, 0x24, 0x06, 0x00, 0x01,          /* union: master 0, slave 1 */
    7, 5, 0x82, 0x03, 8, 0, 255,        /* notification EP */
    /* interface 1: CDC data */
    9, 4, 1, 0, 2, 0x0A, 0x00, 0x00, 0,
    7, 5, 0x01, 0x02, 64, 0, 0,
    7, 5, 0x81, 0x02, 64, 0, 0,
};

static const char str_manuf[] = "DMC-100 USB mod";
static const char str_prod[] = "FNIRSI DMC-100 Clamp Meter";

/* ---- helpers ---------------------------------------------------------------------------- */

static void grst(uint32_t v)
{
    GRSTCTL = v;
    for (uint32_t n = WAIT_N; n && (GRSTCTL & (AHBIDL | CSRST | RXFFLSH | TXFFLSH)) != AHBIDL; n--) {
    }
}

static void wait_bit(volatile uint32_t *r, uint32_t bit)
{
    for (uint32_t n = WAIT_N; n && !(*r & bit); n--) {
    }
}

static void fifo_put(uint32_t ep, const uint8_t *p, uint32_t n)
{
    for (uint32_t i = 0; i < n; i += 4) {
        uint32_t w = 0;
        for (uint32_t b = 0; b < 4 && i + b < n; b++)
            w |= (uint32_t)p[i + b] << (8 * b);
        FIFO(ep) = w;
    }
}

static void irq_off(void) { NVIC_ICER2 = IRQ_BIT; __asm volatile("dsb\n isb" ::: "memory"); }
static void irq_on(void) { NVIC_ISER2 = IRQ_BIT; }

/* stop an IN endpoint (NAK, disable) and flush its FIFO */
static void in_stop(uint32_t ep)
{
    if (DIEPCTL(ep) & EPENA) {
        DIEPCTL(ep) |= SNAK;
        wait_bit(&DIEPINT(ep), INEPNE);
        DIEPCTL(ep) |= EPDIS | SNAK;
        wait_bit(&DIEPINT(ep), EPDISD);
    }
    grst(TXFNUM(ep) | TXFFLSH);
    DIEPINT(ep) = 0xFFu;
}

/* ---- endpoint 0 ------------------------------------------------------------------------- */

static void ep0_out_arm(void)
{
    DOEPTSIZ(0) = EP0_OUT_SETUP;
    DOEPCTL(0) |= EPENA | CNAK;
}

static void ep0_tx_next(void)
{
    uint32_t n = u.ep0_left > 64 ? 64 : u.ep0_left;
    DIEPTSIZ(0) = PKTCNT(1) | n;
    DIEPCTL(0) |= EPENA | CNAK;
    fifo_put(0, u.ep0_ptr, n);
    u.ep0_ptr += n;
    u.ep0_left -= n;
}

/* IN data stage: len bytes of p, at most wLength */
static void ep0_send(const uint8_t *p, uint32_t len)
{
    uint32_t wlen = u.setup[6] | (uint32_t)u.setup[7] << 8;
    if (len > wlen)
        len = wlen;
    u.ep0_ptr = p;
    u.ep0_left = (uint16_t)len;
    u.ep0_zlp = len < wlen && len && !(len & 63u);
    u.ep0_in_stage = 1;
    ep0_tx_next();
}

/* status stage of a request without data or with an OUT data stage */
static void ep0_status(void)
{
    u.ep0_in_stage = 0;
    DIEPTSIZ(0) = PKTCNT(1);
    DIEPCTL(0) |= EPENA | CNAK;
}

static void ep0_stall(void)
{
    DIEPCTL(0) |= STALL;
    DOEPCTL(0) |= STALL;
}

static const uint8_t *str_desc(uint8_t idx)
{
    static const char hex[] = "0123456789ABCDEF";
    uint8_t *r = u.reply;
    uint32_t n = 0;
    if (idx == 0) {
        r[0] = 4; r[1] = 3; r[2] = 0x09; r[3] = 0x04;
        return r;
    }
    if (idx == 3) {  /* serial: 96-bit unique ID */
        const volatile uint8_t *id = (const volatile uint8_t *)0x1FFFF7E8u;
        for (uint32_t i = 0; i < 12; i++) {
            r[2 + 4 * i] = (uint8_t)hex[id[i] >> 4];
            r[3 + 4 * i] = 0;
            r[4 + 4 * i] = (uint8_t)hex[id[i] & 15];
            r[5 + 4 * i] = 0;
        }
        n = 24;
    } else {
        const char *s = idx == 1 ? str_manuf : idx == 2 ? str_prod : 0;
        if (!s)
            return 0;
        for (; s[n]; n++) {
            r[2 + 2 * n] = (uint8_t)s[n];
            r[3 + 2 * n] = 0;
        }
    }
    r[0] = (uint8_t)(2 + 2 * n);
    r[1] = 3;
    return r;
}

static void ep_activate(void)
{
    DIEPCTL(1) = USBAEP | EPTYP_BULK | (1u << 22) | SD0PID | SNAK | 64u;
    DIEPCTL(2) = USBAEP | EPTYP_INTR | (2u << 22) | SD0PID | SNAK | 8u;
    DOEPCTL(1) = USBAEP | EPTYP_BULK | SD0PID | SNAK | 64u;
    grst(TXFNUM(1) | TXFFLSH);
    grst(TXFNUM(2) | TXFFLSH);
    DIEPINT(1) = 0xFFu;
    DIEPINT(2) = 0xFFu;
    DOEPINT(1) = 0xFFu;
    DAINTMSK = 0x00030007u;  /* IN 0,1,2  OUT 0,1 */
}

static void rx_arm(void);
static void tx_kick(void);

static void ep_deactivate(void)
{
    u.configured = 0;
    u.dtr = 0;
    u.tx_busy = 0;
    u.tx_zlp = 0;
    u.rx_armed = 0;
    DAINTMSK = 0x00010001u;
    for (uint32_t n = 1; n <= 2; n++)
        if (DIEPCTL(n) & EPENA)
            in_stop(n);
    DIEPCTL(1) = SNAK;
    DIEPCTL(2) = SNAK;
    DOEPCTL(1) = SNAK;
}

static void setup(void)
{
    const uint8_t *s = u.setup;
    uint8_t type = s[0], req = s[1];
    uint16_t val = (uint16_t)(s[2] | s[3] << 8);
    const uint8_t *d = 0;
    uint32_t len = 0;

    if (DIEPCTL(0) & EPENA)  /* a reply the host gave up on */
        in_stop(0);
    u.ep0_in_stage = 0;
    u.ep0_rx_expect = 0;
    u.ep0_left = 0;

    switch (type << 8 | req) {
    case 0x8000: case 0x8100: case 0x8200:  /* GET_STATUS */
        u.reply[0] = 0; u.reply[1] = 0;
        ep0_send(u.reply, 2);
        return;
    case 0x0005:  /* SET_ADDRESS */
        DCFG = (DCFG & ~(0x7Fu << 4)) | (uint32_t)(val & 0x7F) << 4;
        ep0_status();
        return;
    case 0x8006:  /* GET_DESCRIPTOR */
        switch (val >> 8) {
        case 1: d = dev_desc; len = sizeof dev_desc; break;
        case 2: d = cfg_desc; len = sizeof cfg_desc; break;
        case 3: d = str_desc((uint8_t)val); len = d ? d[0] : 0; break;
        }
        if (d) ep0_send(d, len); else ep0_stall();
        return;
    case 0x8008:  /* GET_CONFIGURATION */
        u.reply[0] = u.configured;
        ep0_send(u.reply, 1);
        return;
    case 0x0009:  /* SET_CONFIGURATION */
        if (val == 1) {
            ep_activate();
            u.tx_busy = 0;
            u.tx_zlp = 0;
            u.rx_armed = 0;
            u.configured = 1;
            rx_arm();
        } else if (val == 0) {
            ep_deactivate();
        } else {
            ep0_stall();
            return;
        }
        ep0_status();
        return;
    case 0x810A:  /* GET_INTERFACE */
        u.reply[0] = 0;
        ep0_send(u.reply, 1);
        return;
    case 0x010B:  /* SET_INTERFACE (alt 0 only) */
        ep0_status();
        return;
    case 0x0201: case 0x0203: {  /* CLEAR_FEATURE / SET_FEATURE (ENDPOINT_HALT) */
        uint8_t ep = s[4];
        volatile uint32_t *c = (ep & 0x80) ? &DIEPCTL(ep & 3) : &DOEPCTL(ep & 3);
        if ((ep & 3) == 0) { ep0_status(); return; }
        if (req == 0x03) *c |= STALL;
        else *c = (*c & ~STALL) | SD0PID;
        ep0_status();
        return;
    }
    case 0x0001: case 0x0003:  /* device remote wakeup feature: accept, ignore */
        ep0_status();
        return;
    case 0x2120:  /* SET_LINE_CODING: OUT data stage */
        u.ep0_rx_expect = 1;
        ep0_out_arm();
        return;
    case 0xA121:  /* GET_LINE_CODING */
        ep0_send(u.line_coding, 7);
        return;
    case 0x2122:  /* SET_CONTROL_LINE_STATE */
        u.dtr = val & 1;
        ep0_status();
        return;
    case 0x2123:  /* SEND_BREAK */
        ep0_status();
        return;
    }
    ep0_stall();
}

/* ---- data endpoints ---------------------------------------------------------------------- */

static uint32_t rx_free(void) { return RXQ - 1u - (uint16_t)((u.rx_head - u.rx_tail) & (RXQ - 1u)); }

static void rx_arm(void)
{
    if (u.configured && !u.rx_armed && rx_free() >= 64) {
        u.rx_armed = 1;
        DOEPTSIZ(1) = PKTCNT(1) | 64u;
        DOEPCTL(1) |= EPENA | CNAK;
    }
}

static void tx_kick(void)
{
    if (!u.configured || u.tx_busy)
        return;
    uint32_t n = (uint16_t)(u.tx_head - u.tx_tail) & (TXQ - 1u);
    if (n == 0 && !u.tx_zlp)
        return;
    if (n > 64)
        n = 64;
    for (uint32_t i = 0; i < n; i++)
        u.txpkt[i] = u.txq[(u.tx_tail + i) & (TXQ - 1u)];
    u.tx_tail = (uint16_t)((u.tx_tail + n) & (TXQ - 1u));
    u.tx_zlp = n == 64;  /* a full packet ends a transfer only with a following short one */
    u.tx_busy = 1;
    DIEPTSIZ(1) = PKTCNT(1) | n;
    DIEPCTL(1) |= EPENA | CNAK;
    fifo_put(1, u.txpkt, n);
}

/* one receive FIFO entry */
static void rx_pop(void)
{
    uint32_t st = GRXSTSP;
    uint32_t ep = st & 15u, n = (st >> 4) & 0x7FFu, kind = (st >> 17) & 15u;
    for (uint32_t i = 0; i < n; i += 4) {
        uint32_t w = FIFO(0);
        for (uint32_t b = i; b < i + 4 && b < n; b++, w >>= 8) {
            uint8_t c = (uint8_t)w;
            if (kind == 6) {
                if (b < 8) u.setup[b] = c;
            } else if (kind == 2 && ep == 0) {
                if (b < sizeof u.ep0buf) u.ep0buf[b] = c;
            } else if (kind == 2 && ep == 1) {
                uint16_t h = u.rx_head, nh = (uint16_t)((h + 1u) & (RXQ - 1u));
                if (nh != u.rx_tail) {
                    u.rxq[h] = c;
                    u.rx_head = nh;
                }
            }
        }
    }
}

/* ---- interrupt ---------------------------------------------------------------------------- */

static void bus_reset(void)
{
    u.resets++;
    DCTL &= ~RWUSIG;
    ep_deactivate();
    grst(TXFNUM(0x10) | TXFFLSH);
    for (uint32_t n = 0; n < 3; n++) {
        DIEPINT(n) = 0xFFu;
        DOEPINT(n) = 0xFFu;
    }
    DCFG &= ~(0x7Fu << 4);
    DOEPTSIZ(0) = EP0_OUT_SETUP;
    u.ep0_in_stage = 0;
    u.ep0_rx_expect = 0;
    u.suspended = 0;
}

void usb_irq(void)
{
    uint32_t g = GINTSTS & GINTMSK;
    if (g & USBRST) {
        GINTSTS = USBRST;
        bus_reset();
    }
    if (g & ENUMDNE) {
        GINTSTS = ENUMDNE;
        DIEPCTL(0) &= ~3u;  /* 64 B packets */
        DCTL |= CGINAK;
    }
    if (g & USBSUSP) {
        GINTSTS = USBSUSP;
        u.suspended = 1;
    }
    if (g & WKUPINT) {
        GINTSTS = WKUPINT;
        u.suspended = 0;
    }
    while (GINTSTS & RXFLVL)
        rx_pop();
    if (g & OEPINT) {
        uint32_t a = DAINT;
        if (a & (1u << 16)) {
            uint32_t v = DOEPINT(0);
            DOEPINT(0) = v;
            if ((v & XFRC) && u.ep0_rx_expect) {
                u.ep0_rx_expect = 0;
                for (uint32_t i = 0; i < 7; i++)
                    u.line_coding[i] = u.ep0buf[i];
                ep0_status();
            }
            if (v & STUP) {
                u.suspended = 0;
                if (!(DOEPCTL(0) & EPENA))
                    DOEPTSIZ(0) = EP0_OUT_SETUP;
                setup();
            }
        }
        if (a & (1u << 17)) {
            uint32_t v = DOEPINT(1);
            DOEPINT(1) = v;
            if (v & XFRC) {
                u.rx_armed = 0;
                rx_arm();
            }
        }
    }
    if (g & IEPINT) {
        uint32_t a = DAINT;
        if (a & 1u) {
            uint32_t v = DIEPINT(0);
            DIEPINT(0) = v;
            if ((v & XFRC) && u.ep0_in_stage) {
                if (u.ep0_left) {
                    ep0_tx_next();
                } else if (u.ep0_zlp) {
                    u.ep0_zlp = 0;
                    DIEPTSIZ(0) = PKTCNT(1);
                    DIEPCTL(0) |= EPENA | CNAK;
                } else {
                    u.ep0_in_stage = 0;
                    ep0_out_arm();  /* OUT status stage */
                }
            }
        }
        if (a & 2u) {
            uint32_t v = DIEPINT(1);
            DIEPINT(1) = v;
            if (v & XFRC) {
                u.tx_busy = 0;
                tx_kick();
            }
        }
        if (a & 4u)
            DIEPINT(2) = 0xFFu;
    }
}

/* ---- init ---------------------------------------------------------------------------------- */

void usb_init(void)
{
    static const uint8_t lc[7] = {0x00, 0xC2, 0x01, 0x00, 0, 0, 8};  /* 115200 8N1 */
    for (uint32_t i = 0; i < 7; i++)
        u.line_coding[i] = lc[i];

    irq_off();
    CRM_CFG = (CRM_CFG & ~(1u << 27 | 3u << 22)) | 1u << 27 | 1u << 22;  /* 144 MHz / 3 */
    CRM_AHBEN |= 1u << 12;                                                /* OTGFS1 clock */
    (void)CRM_AHBEN;

    grst(0);
    grst(CSRST);
    GUSBCFG = (GUSBCFG & ~FHMOD) | FDMOD;
    fw_delay_ms(25);  /* forced mode takes effect after 25 ms */
    DCTL = SDIS;      /* stay off the bus while configuring (also drops a bootloader session) */
    PCGCCTL = 0;
    DCFG = (DCFG & ~0x7F3u) | 3u;  /* full speed, address 0 */

    GRXFSIZ = RX_WORDS;
    DIEPTXF0 = TX0_WORDS << 16 | RX_WORDS;
    DIEPTXF(1) = TX1_WORDS << 16 | (RX_WORDS + TX0_WORDS);
    DIEPTXF(2) = TX2_WORDS << 16 | (RX_WORDS + TX0_WORDS + TX1_WORDS);
    grst(TXFNUM(0x10) | TXFFLSH);
    grst(RXFFLSH);

    DIEPMSK = XFRC | EPDISD | TOC;
    DOEPMSK = XFRC | EPDISD | STUP;
    DAINTMSK = 0x00010001u;
    for (uint32_t n = 0; n < 3; n++) {
        DIEPINT(n) = 0xFFu;
        DOEPINT(n) = 0xFFu;
    }
    DOEPTSIZ(0) = EP0_OUT_SETUP;

    /* Session valid from the PA9 comparators, as the bootloader does it (see usb_session_hold). */
    GCCFG = PWRDWN | VBUSASEN | VBUSBSEN;
    GOTGINT = 0xFFFFFFFFu;

    GINTSTS = 0xFFFFFFFFu;
    GINTMSK = RXFLVL | USBSUSP | USBRST | ENUMDNE | IEPINT | OEPINT | WKUPINT;
    GAHBCFG = 1u;  /* global interrupt enable */

    NVIC_IPR67 = 0xF0;  /* lowest priority: TIM1 keys and USART1 (DMM frames) come first */
    irq_on();

    fw_delay_ms(5);
    DCTL &= ~SDIS;  /* connect: D+ pull-up on */
}

/* ---- main-loop API --------------------------------------------------------------------------- */

int usb_configured(void) { return u.configured; }
int usb_suspended(void) { return u.suspended; }
int usb_dtr(void) { return u.dtr; }
uint32_t usb_debug_gotgctl(void) { return GOTGCTL; }
uint32_t usb_debug_gccfg(void) { return GCCFG; }

/* Session-end events (B-session dropped), counted from GOTGINT. */
static uint32_t sedet_count;
uint32_t usb_debug_sedet(void)
{
    uint32_t v = GOTGINT;
    if (v & SEDET)
        sedet_count++;
    GOTGINT = v;
    return sedet_count;
}

/* PA9 is both the session (VBUS) sense input and USART1 TX to the DMM chip. A command to the
 * chip pulls it low bit by bit, which would end the session and drop the D+ pull-up (the host
 * sees a disconnect). VBUSIG set for the duration of the command keeps the session (tested;
 * VBUSIG alone at init does not give a session on this board, so it is only used here). */
static uint32_t saved_gccfg;
void usb_session_hold(int on)
{
    if (on) {
        saved_gccfg = GCCFG;
        GCCFG = saved_gccfg | VBUSIG;
    } else {
        GCCFG = saved_gccfg;
    }
}

uint32_t usb_debug_resets(void) { return u.resets; }

int usb_write(const char *p, uint32_t n)
{
    if (!u.configured)
        return 0;
    irq_off();
    uint32_t used = (uint16_t)(u.tx_head - u.tx_tail) & (TXQ - 1u);
    int ok = n <= TXQ - 1u - used;
    if (ok) {
        uint16_t h = u.tx_head;
        for (uint32_t i = 0; i < n; i++)
            u.txq[(h + i) & (TXQ - 1u)] = (uint8_t)p[i];
        u.tx_head = (uint16_t)((h + n) & (TXQ - 1u));
        tx_kick();
    }
    irq_on();
    return ok;
}

int usb_read_byte(void)
{
    int c = -1;
    irq_off();
    if (u.rx_tail != u.rx_head) {
        c = u.rxq[u.rx_tail];
        u.rx_tail = (uint16_t)((u.rx_tail + 1u) & (RXQ - 1u));
    }
    rx_arm();
    irq_on();
    return c;
}

void usb_tx_discard(void)
{
    irq_off();
    u.tx_tail = u.tx_head;
    irq_on();
}
