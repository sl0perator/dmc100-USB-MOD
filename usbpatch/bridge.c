/*
 * Glue between the stock DMC-100 firmware and the USB CDC port.
 *
 * Hooks (patched into the stock image by build.py):
 *   hook_init    replaces main's call of fw_init_tail (0x0801076C)
 *   hook_parse   replaces main's call of fw_parse_frame (0x080107D0)
 *   hook_loop    replaces main's call of fw_charge_lockout (0x080107E6), which it drops
 *   hook_dmm_send replaces both fw_dmm_send calls (0x08012894, 0x08012992)
 *   usb_irq      vector 67 (OTGFS1)
 *
 * Text protocol, one line per message, fields separated by commas, lines end in "\n".
 * See PROTOCOL in ../USB_MOD.md.
 */
#include <stdint.h>
#include "fw.h"
#include "usb_cdc.h"

#define PROTO_VERSION 6
#define MAGIC 0x55534231u   /* hook_init ran (DMM commands are also sent before it) */

static struct {
    uint32_t magic;
    uint32_t dmm_cmds;
    uint32_t last_cyc, cyc_acc, ms;
    uint32_t last_status_ms;
    uint8_t keepawake, stream, last_dtr;
    uint8_t cmd_len;
    char cmd[24];
} b;

extern uint8_t __bss_start[], __bss_end[];
uint32_t beep_get(void);
void beep_set(uint32_t on);

/* ---- small formatting helpers (no libc) ------------------------------------------------------ */

static char *put_c(char *p, char c) { *p = c; return p + 1; }

static char *put_u(char *p, uint32_t v)
{
    char t[10];
    int n = 0;
    do {
        t[n++] = (char)('0' + v % 10u);
        v /= 10u;
    } while (v);
    while (n)
        *p++ = t[--n];
    return p;
}

static char *put_i(char *p, int32_t v)
{
    if (v < 0) {
        *p++ = '-';
        return put_u(p, (uint32_t)-v);
    }
    return put_u(p, (uint32_t)v);
}

static char *put_x(char *p, uint32_t v, int digits)
{
    static const char hex[] = "0123456789abcdef";
    for (int i = digits - 1; i >= 0; i--)
        *p++ = hex[(v >> (4 * i)) & 15u];
    return p;
}

static char *put_s(char *p, const char *s)
{
    while (*s)
        *p++ = *s++;
    return p;
}

static void send(const char *line, char *end)
{
    *end++ = '\n';
    usb_write(line, (uint32_t)(end - line));
}

/* ---- time ------------------------------------------------------------------------------------ */

static void tick(void)
{
    uint32_t c = DWT_CYCCNT;
    b.cyc_acc += c - b.last_cyc;
    b.last_cyc = c;
    uint32_t q = b.cyc_acc / (SYSCLK_HZ / 1000u);
    b.ms += q;
    b.cyc_acc -= q * (SYSCLK_HZ / 1000u);
}

static int charging_pins(void) { return (GPIOB_IDT & 3u) != 3u; }

static int host_active(void) { return usb_configured() && !usb_suspended(); }

/* bit 0 configured, bit 1 suspended, bit 3 DTR (port open) */
static uint8_t usb_state(void)
{
    return (uint8_t)(usb_configured() | usb_suspended() << 1 | usb_dtr() << 3);
}

/* ---- messages -------------------------------------------------------------------------------- */

/* R,ms,mode,unit,acdc,hold,numeric,value_bits,bar_bits,bar_flag,text,raw_frame,view,rel_bits
 * acdc: 2 DC, 1 AC (labels of the power view). In the power view (view 2) value/text is the
 * voltage, bar the clamp current (bar_flag 0 DC, 1 AC; DC current shown = bar + rel). */
static void send_reading(void)
{
    char line[128], *p = line;
    p = put_s(p, "R,");
    p = put_u(p, b.ms);
    p = put_c(p, ',');
    p = put_u(p, FW_MODE);
    p = put_c(p, ',');
    p = put_u(p, FW_RD_UNIT);
    p = put_c(p, ',');
    p = put_i(p, (int8_t)FW_RD_ACDC);
    p = put_c(p, ',');
    p = put_u(p, FW_RD_HOLD);
    p = put_c(p, ',');
    p = put_u(p, FW_RD_NUMERIC);
    p = put_c(p, ',');
    p = put_x(p, FW_RD_VALUE_BITS, 8);
    p = put_c(p, ',');
    p = put_x(p, FW_RD_BAR_BITS, 8);
    p = put_c(p, ',');
    p = put_u(p, FW_RD_BAR_FLAG);
    p = put_c(p, ',');
    const char *t = FW_RD_TEXT;
    if ((uint32_t)t >= 0x20000000u && (uint32_t)t < 0x20007200u) {
        for (int i = 0; i < 12 && t[i]; i++) {
            char c = t[i];
            p = put_c(p, (c > ' ' && c < 0x7F && c != ',') ? c : '_');
        }
    }
    p = put_c(p, ',');
    for (int i = 0; i < 13; i++)
        p = put_x(p, FW_RAW_FRAME[i], 2);
    p = put_c(p, ',');
    p = put_u(p, FW_VIEW);
    p = put_c(p, ',');
    p = put_x(p, FW_REL_OFFSET_BITS, 8);
    send(line, p);
}

/* S,ms,mode,view,menu,charge_boot,charging,flashlight,battery,language,temp_unit,
 *   autooff,brightness,theme,hold,keepawake,stream,beep,usb_state */
static void send_status(void)
{
    char line[96], *p = line;
    const uint8_t v[] = {
        FW_MODE, FW_VIEW, FW_IN_MENU, FW_CHARGE_BOOT, (uint8_t)charging_pins(), FW_FLASHLIGHT,
        FW_BATTERY, FW_LANGUAGE, FW_TEMP_UNIT, FW_AUTOOFF_SETTING, FW_BRIGHTNESS, FW_THEME,
        FW_RD_HOLD, b.keepawake, b.stream, (uint8_t)beep_get(), usb_state(),
    };
    p = put_s(p, "S,");
    p = put_u(p, b.ms);
    for (uint32_t i = 0; i < sizeof v; i++) {
        p = put_c(p, ',');
        p = put_u(p, v[i]);
    }
    send(line, p);
    b.last_status_ms = b.ms;
}

/* I,DMC100-USB,proto,stock_fw,gotgctl,usb_resets,gccfg,session_ends,dmm_cmds */
static void send_info(void)
{
    char line[96], *p = line;
    p = put_s(p, "I,DMC100-USB,");
    p = put_u(p, PROTO_VERSION);
    p = put_s(p, ",V1.4,");
    p = put_x(p, usb_debug_gotgctl(), 8);
    p = put_c(p, ',');
    p = put_u(p, usb_debug_resets());
    p = put_c(p, ',');
    p = put_x(p, usb_debug_gccfg(), 8);
    p = put_c(p, ',');
    p = put_u(p, usb_debug_sedet());
    p = put_c(p, ',');
    p = put_u(p, b.dmm_cmds);
    send(line, p);
}

static void reply(int ok, char c)
{
    char line[8], *p = line;
    p = put_s(p, ok ? "OK," : "ER,");
    p = put_c(p, c);
    send(line, p);
}

/* ---- commands -------------------------------------------------------------------------------- */

static int parse_num(const char *s, uint32_t *out)
{
    uint32_t v = 0;
    if (*s < '0' || *s > '9')
        return 0;
    for (; *s >= '0' && *s <= '9'; s++)
        v = v * 10u + (uint32_t)(*s - '0');
    *out = v;
    return *s == 0;
}

static void command(char *s)
{
    char c = *s;
    uint32_t n = 0;
    int has = parse_num(s + 1, &n);
    if (c >= 'a' && c <= 'z')
        c = (char)(c - 32);
    switch (c) {
    case 'K':  /* K<code>: inject a key event, as if the button was pressed */
        if (has && n >= 1 && n <= FW_KEY_MAX) {
            FW_KEY_PENDING = (uint8_t)n;
            reply(1, c);
            return;
        }
        break;
    case 'M':  /* M<n>: select function 0..11 (the path the firmware uses after the menu) */
        if (has && n < FW_MODE_COUNT && !FW_IN_MENU && !FW_CHARGE_BOOT) {
            if (FW_VIEW <= 2)
                FW_SAVED_VIEW = FW_VIEW;
            FW_SAVED_MODE = (uint8_t)n;
            FW_SCREEN_INIT = 0;
            FW_RELOAD_MODE = 1;
            reply(1, c);
            return;
        }
        break;
    case 'A':  /* A0/A1: keep the meter awake while the host is connected */
        if (has && n <= 1) { b.keepawake = (uint8_t)n; reply(1, c); send_status(); return; }
        break;
    case 'P':  /* P0/P1: reading stream off/on */
        if (has && n <= 1) { b.stream = (uint8_t)n; reply(1, c); send_status(); return; }
        break;
    case 'B':  /* B0/B1: beeper off/on (saved with the settings at power-off) */
        if (has && n <= 1) { beep_set(n); reply(1, c); send_status(); return; }
        break;
    case 'S':
        send_status();
        return;
    case 'I':
        send_info();
        return;
    case 0:
        return;
    }
    reply(0, c);
}

static void poll_commands(void)
{
    for (int k = 0; k < 64; k++) {
        int ch = usb_read_byte();
        if (ch < 0)
            return;
        if (ch == '\n' || ch == '\r') {
            b.cmd[b.cmd_len] = 0;
            command(b.cmd);
            b.cmd_len = 0;
        } else if (b.cmd_len < sizeof b.cmd - 1) {
            b.cmd[b.cmd_len++] = (char)ch;
        }
    }
}

/* ---- hooks ----------------------------------------------------------------------------------- */

void hook_init(void)
{
    fw_init_tail();
    for (uint8_t *p = __bss_start; p < __bss_end; p++)
        *p = 0;
    DEMCR |= 1u << 24;   /* TRCENA */
    DWT_CYCCNT = 0;
    DWT_CTRL |= 1u;      /* CYCCNTENA */
    b.keepawake = 1;
    b.stream = 1;
    usb_init();
    b.magic = MAGIC;
}

uint32_t hook_parse(void)
{
    uint8_t pending = FW_FRAME_READY;
    uint32_t r = fw_parse_frame();
    if (pending == 1 && FW_FRAME_READY == 0) {
        tick();
        if (b.stream && usb_configured() && !usb_suspended())
            send_reading();
    }
    return r;
}

void hook_loop(void)
{
    tick();
    if (usb_configured()) {
        uint8_t dtr = (uint8_t)usb_dtr();
        if (dtr && !b.last_dtr) {  /* port opened: drop stale output, say hello */
            usb_tx_discard();
            send_info();
            send_status();
        }
        b.last_dtr = dtr;
        poll_commands();
        if (b.ms - b.last_status_ms >= 1000u)
            send_status();
        /* keep the auto power-off from firing while a host is attached (0x1771 = beep) */
        if (b.keepawake && host_active() && FW_AUTOOFF_SETTING && FW_AUTOOFF_COUNT < 0x2000u)
            FW_AUTOOFF_COUNT = 0x2000u;
    } else {
        b.last_dtr = 0;
    }
    /* The stock loop ended with fw_charge_lockout(): "Do not use while charging" until
     * unplugged. Dropped: the meter measures while on USB power (use a USB isolator). */
}

/* Commands to the DMM chip go out on PA9, which is also the USB session sense pin. */
void hook_dmm_send(const uint8_t *cmd)
{
    if (b.magic != MAGIC) {  /* before hook_init: USB is not running */
        fw_dmm_send(cmd);
        return;
    }
    b.dmm_cmds++;
    usb_session_hold(1);
    fw_dmm_send(cmd);
    uint32_t t0 = DWT_CYCCNT;  /* until the last byte has left (about 87 us), at most 2 ms */
    while (!(USART1_STS & (1u << 6)) && DWT_CYCCNT - t0 < SYSCLK_HZ / 500u) {
    }
    usb_session_hold(0);
}
