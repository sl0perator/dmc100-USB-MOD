/*
 * Interface to the stock FNIRSI DMC-100 V1.4 application (APP_DMC-100_V1.4_250524.bin,
 * SHA-256 f8eab197553e117a374dc9926989b8ec2105baa8120682bd5c864bda30e8364d).
 *
 * The app is linked at 0x08007000 (a 28 KB bootloader sits below it). Every address here is
 * a real runtime address. Function names are ours; the comments say how each was identified.
 * MCU: Artery AT32F415 (Cortex-M4, no FPU), 128 KB flash (1 KB pages), 32 KB RAM, 144 MHz.
 */
#pragma once
#include <stdint.h>

#define FW_FN(addr, type) ((type)((uint32_t)(addr) | 1u))

/* ---- stock functions --------------------------------------------------------------------- */

/* Busy-wait delay in ms using SysTick in polled mode (SysTick is not used otherwise). */
#define fw_delay_ms        FW_FN(0x08009D18, void (*)(uint32_t))
/* Last init call before main's loop; we chain our init after it. */
#define fw_init_tail       FW_FN(0x0800C200, void (*)(void))
/* Decodes a 13-byte frame from the DMM chip (0x2000026A) into FW_READING when
 * FW_G[9] == 1; clears FW_G[9] and sets FW_G[0x0A] when it did. Always returns 0. */
#define fw_parse_frame     FW_FN(0x080125D4, uint32_t (*)(void))
/* "Do not use while charging" lockout: while the charger reports charging it draws a
 * charging screen and loops until unplugged (POWER switches off). No longer called. */
#define fw_charge_lockout  FW_FN(0x080121B8, void (*)(void))
/* Sends a 10-byte command (AA 55 ...) to the DMM chip on USART1 TX = PA9, byte by byte,
 * without waiting for the last byte to leave the shift register. */
#define fw_dmm_send        FW_FN(0x08012A74, void (*)(const uint8_t *))
/* Settings: load from flash (main), save to flash (power-off), factory defaults */
#define fw_settings_load   FW_FN(0x0801456C, void (*)(void))
#define fw_settings_save   FW_FN(0x08014678, void (*)(void))
#define fw_settings_defaults FW_FN(0x0800F100, void (*)(void))
/* Settings menu controller, called every loop while the settings submenu is active */
#define fw_settings_menu   FW_FN(0x08012F70, void (*)(void))
/* Settings page 3 (auto shutdown) and the cursor/selection helper:
 * (cursor_pos, erase_cursor_pos, select_pos, deselect_pos), 0 = none */
#define fw_page_autooff    FW_FN(0x0800C7B0, void (*)(void))
#define fw_settings_mark   FW_FN(0x0800CC34, void (*)(uint32_t, uint32_t, uint32_t, uint32_t))
#define fw_page_dots       FW_FN(0x0800E2E0, void (*)(uint32_t))
/* Drawing (RGB565): fill, rounded outline, outline, text (size 0x10 = 8x16, mode 1) */
#define fw_fill_rect       FW_FN(0x08007F24, void (*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))
#define fw_rrect           FW_FN(0x08007E88, void (*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))
#define fw_rect            FW_FN(0x08007E44, void (*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))
#define fw_text            FW_FN(0x080082F2, void (*)(uint32_t, uint32_t, const char *, uint32_t, uint32_t, uint32_t, uint32_t))
/* CRM peripheral clock on/off; the buzzer is TMR4 CH3 (PB8) at 4 kHz, sounding while its
 * clock (id 0x1C0002) is on */
#define fw_periph_clock    FW_FN(0x08009BA4, void (*)(uint32_t, uint32_t))
#define FW_CLK_TMR4        0x001C0002u
/* 1 when PB0 or PB1 (charger IC status pins) are low, read twice 10 ms apart. */
#define fw_is_charging     FW_FN(0x08012178, uint32_t (*)(void))

/* ---- stock RAM ------------------------------------------------------------------------------ */

#define FW_U8(a)  (*(volatile uint8_t *)(a))
#define FW_U32(a) (*(volatile uint32_t *)(a))

/* System state block (literal 0x200001B8 in main, key ISR, menus) */
#define FW_G               0x200001B8u
#define FW_KEY_PENDING     FW_U8(FW_G + 0x01)  /* written by the TIM1 key ISR, consumed by main */
#define FW_KEY_CURRENT     FW_U8(FW_G + 0x02)  /* key code handled in this loop iteration */
#define FW_FLASHLIGHT      FW_U8(FW_G + 0x03)  /* LED torch on PB9 (LIGHT long press) */
#define FW_BATTERY         FW_U8(FW_G + 0x04)  /* battery icon level */
#define FW_REDRAW          FW_U8(FW_G + 0x05)  /* 1: clear and redraw the measurement screen */
#define FW_FRAME_READY     FW_U8(FW_G + 0x09)  /* set by the USART1 idle ISR */
#define FW_NEW_DATA        FW_U8(FW_G + 0x0A)  /* set by fw_parse_frame, cleared by the screen */
#define FW_AUTOOFF_COUNT   FW_U32(FW_G + 0x10) /* counts down in the TIM1 ISR; 0x1771 beeps,
                                                  1 powers off; reloaded on key presses */
#define FW_LANGUAGE        FW_U8(FW_G + 0x20)  /* 0 Chinese, 1 English */
#define FW_TEMP_UNIT       FW_U8(FW_G + 0x21)  /* 0 degC, 1 degF */
#define FW_AUTOOFF_SETTING FW_U8(FW_G + 0x22)  /* 0 off, 1..3 */
#define FW_BRIGHTNESS      FW_U8(FW_G + 0x23)  /* 0..9 */
#define FW_SAVED_MODE      FW_U8(FW_G + 0x24)  /* mode restored when FW_RELOAD_MODE is set */
#define FW_SAVED_VIEW      FW_U8(FW_G + 0x25)
#define FW_THEME           FW_U8(FW_G + 0x26)
#define FW_BEEP_ACTIVE     FW_U8(FW_G + 0x0F)  /* short beep running, TIM1 ISR stops it */
#define FW_BG_COLOR        (*(volatile uint16_t *)(FW_G + 0x1A))
#define FW_FG_COLOR        (*(volatile uint16_t *)(FW_G + 0x1C))
#define FW_REL_OFFSET_BITS FW_U32(FW_G + 0x14)  /* float added to the clamp current (DC A zero) */

/* Saved settings (140 bytes at 0x200000A0 <-> flash 0x0801F400), halfwords:
 * [0] 0 = valid, [1] language, [2] auto-off, [3] brightness, [4] temp unit, [5] mode, [6] view,
 * [7] theme, [8] history count, [9] history index, [10..69] 30 history records.
 * Settings are bytes stored in halfwords; the loader reads only the low byte. The high byte
 * of [7] holds our beep flag. */
#define FW_SAVED_BEEP      FW_U8(0x200000AFu)

/* Menu / settings UI state */
#define FW_MENU            0x20000090u
#define FW_MENU_SET_DRAWN  FW_U8(FW_MENU + 1)   /* cursor drawn since entering the submenu */
#define FW_MENU_SET_INIT   FW_U8(FW_MENU + 2)   /* cleared when the menu tab changes */
#define FW_MENU_IN_SUB     FW_U8(FW_MENU + 3)   /* 1: keys go to the settings controller */
#define FW_MENU_SET_POS    FW_U8(FW_MENU + 5)   /* 1-2 language, 3 brightness, 4-5 temp unit,
                                                   6-9 auto-off; ours: 10-11 beep */
#define FW_MENU_SET_SLIDER FW_U8(FW_MENU + 6)   /* brightness slider being edited */

#define FW_CHARGE_BOOT     FW_U8(0x20000000u)  /* 1: powered up by the charger (charge screen) */
#define FW_IN_MENU         FW_U8(0x2000006Cu)  /* 1: settings/history menus are shown */
#define FW_RELOAD_MODE     FW_U8(0x2000006Du)  /* 1: re-send FW_SAVED_MODE to the DMM chip */
#define FW_VIEW            FW_U8(0x20000072u)  /* screen layout 0..2 */
#define FW_MODE            FW_U8(0x20000073u)  /* current function 0..11, see below */
#define FW_SCREEN_INIT     FW_U8(0x20000075u)  /* 0: full redraw of the measurement screen */

#define FW_RAW_FRAME       ((const volatile uint8_t *)0x2000026Au) /* 13 bytes, 5A A5 ... */

/* Decoded reading (written by fw_parse_frame) */
#define FW_READING         0x20000288u
#define FW_RD_NUMERIC      FW_U8(FW_READING + 0x00)  /* display shows digits (not OL/----) */
#define FW_RD_TEXT         (*(char *volatile *)(FW_READING + 0x04)) /* display string */
#define FW_RD_VALUE_BITS   FW_U32(FW_READING + 0x08) /* float, in the displayed unit */
#define FW_RD_ACDC         FW_U8(FW_READING + 0x0C)  /* 1, 2 or 0xFF (frame byte 2 bits 0/1) */
#define FW_RD_UNIT         FW_U8(FW_READING + 0x0D)  /* unit code, see web UI */
#define FW_RD_HOLD         FW_U8(FW_READING + 0x0E)
#define FW_RD_BAR_BITS     FW_U32(FW_READING + 0x10) /* float: 22-bit frame value / 100 */
#define FW_RD_BAR_FLAG     FW_U8(FW_READING + 0x14)

/* Modes (FW_MODE), from the GBK labels at 0x0800AAE0..:
 * 0 DC V, 1 AC V, 2 resistance, 3 continuity, 4 diode, 5 capacitance, 6 frequency,
 * 7 temperature, 8 live/neutral, 9 NCV, 10 DC A, 11 AC A */
#define FW_MODE_COUNT 12

/* Key codes (key table at 0x20000018: pin mask, short code, long code):
 * HOLD PB4 1/2, MODE PB6 5/6, V/A PB7 9/10, SAVE PB5 13/14, POWER PF7 17/18, LIGHT PA15 21/22 */
#define FW_KEY_MAX 22

/* ---- hardware ---------------------------------------------------------------------------- */
#define GPIOB_IDT          FW_U32(0x40010C08u)
#define USART1_STS         FW_U32(0x40013800u)   /* bit 6 TDC: transmission complete */
#define DWT_CTRL           FW_U32(0xE0001000u)
#define DWT_CYCCNT         FW_U32(0xE0001004u)
#define DEMCR              FW_U32(0xE000EDFCu)
#define SYSCLK_HZ          144000000u
