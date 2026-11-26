/*
 * Minimal USB CDC-ACM device for the AT32F415 OTGFS controller (Synopsys DWC2 derivative),
 * full speed, slave mode (no DMA), interrupt driven (IRQ 67).
 *
 * Hardware facts this relies on (several confirmed by the DMC100-Doom project, see README):
 *  - USB clock: 144 MHz PLL / 3 via CRM_CFG USBDIV = 101b (bit 27, bits 23:22 = 01).
 *  - PA11/PA12 are taken over by the PHY when the controller is clocked and powered.
 *  - VBUSIG does not give a valid session on this board: the session comparators on PA9 are
 *    used. In the stock firmware PA9 is USART1 TX (idles high) to the DMM chip.
 */
#pragma once
#include <stdint.h>

void usb_init(void);          /* clocks, core reset, device mode, IRQ, connect */
void usb_irq(void);           /* OTGFS1 interrupt handler (vector 67) */

int usb_configured(void);     /* host has set configuration 1 */
int usb_suspended(void);
int usb_dtr(void);            /* host opened the port (DTR from SET_CONTROL_LINE_STATE) */

/* Main-loop side (masks the USB interrupt briefly). */
int usb_write(const char *p, uint32_t n);   /* all or nothing; 0 if dropped */
int usb_read_byte(void);                     /* -1 if none */
void usb_tx_discard(void);
uint32_t usb_debug_gotgctl(void);
uint32_t usb_debug_resets(void);
uint32_t usb_debug_gccfg(void);
uint32_t usb_debug_sedet(void);
/* keep the USB session alive around a DMM command on PA9 (see usb_cdc.c) */
void usb_session_hold(int on);
