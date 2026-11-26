/*
 * Beep on/off: gate in the stock beep functions, a fourth settings page, persistence.
 *
 * Hooks (patched by build.py):
 *   hook_beep      entry of the stock short beep 0x08009450 (B.W)
 *   hook_beep3     entry of the stock triple beep 0x08009420 (auto power-off warning, B.W)
 *   hook_settings  replaces the menu's call of the settings controller (0x0800C754)
 *   hook_load      replaces main's call of the settings loader (0x080106FC)
 *   hook_save      replaces the power-off call of the settings writer (0x08012AD4)
 *   hook_defaults  replaces "reset all settings" -> defaults (0x0800F190)
 * Plus: page dots drawn for 4 pages (0x0800E306, 0x0800E310).
 *
 * The flag lives at a fixed RAM address outside the zeroed .bss, because beeps and power-off
 * can happen before hook_init (boot charging screen). Default: off.
 */
#include <stdint.h>
#include "fw.h"

#define BEEP_ON (*(volatile uint8_t *)0x20007FF0u)  /* reserved in link.ld */

#define POS_FIRST 10   /* OFF */
#define POS_LAST  11   /* ON */
#define HILITE    0x1C9Fu
#define PANEL     0x3186u
#define TEXT_BG   0xF79Eu

uint32_t beep_get(void) { return BEEP_ON; }
void beep_set(uint32_t on) { BEEP_ON = on ? 1u : 0u; }

/* ---- the gate ---------------------------------------------------------------------------- */

void hook_beep(void)
{
    if (!BEEP_ON)
        return;
    FW_BEEP_ACTIVE = 1;
    fw_periph_clock(FW_CLK_TMR4, 1);
}

void hook_beep3(void)
{
    if (!BEEP_ON)
        return;
    for (int i = 0; i < 3; i++) {
        fw_periph_clock(FW_CLK_TMR4, 1);
        fw_delay_ms(150);
        fw_periph_clock(FW_CLK_TMR4, 0);
        fw_delay_ms(150);
    }
}

/* ---- persistence ------------------------------------------------------------------------- */

void hook_load(void)
{
    fw_settings_load();
    BEEP_ON = FW_SAVED_BEEP & 1u;   /* 0 after factory defaults and with stock-saved settings */
}

void hook_save(void)
{
    FW_SAVED_BEEP = BEEP_ON;        /* power-off just rewrote halfword [7] from the theme */
    fw_settings_save();
}

void hook_defaults(void)
{
    fw_settings_defaults();
    BEEP_ON = 0;
}

/* ---- settings page 4 --------------------------------------------------------------------- */

static uint32_t row_y(uint32_t pos) { return (pos - POS_FIRST) * 31u; }

static void draw_option(uint32_t pos, int selected)
{
    uint32_t y = row_y(pos);
    const char *label = pos == POS_LAST ? "ON" : "OFF";
    if (selected) {
        fw_fill_rect(0x3B, 0xA6 + y, 0x4F, 0xB9 + y, HILITE);
        fw_text(0x5C, 0xA8 + y, label, HILITE, HILITE, 0x10, 1);
    } else {
        fw_fill_rect(0x3B, 0xA6 + y, 0x4F, 0xB9 + y, FW_BG_COLOR);
        fw_rect(0x3B, 0xA6 + y, 0x4F, 0xB9 + y, FW_FG_COLOR);
        fw_text(0x5C, 0xA8 + y, label, FW_FG_COLOR, TEXT_BG, 0x10, 1);
    }
}

static void draw_cursor(uint32_t pos, int on)
{
    uint32_t y = row_y(pos);
    fw_rrect(0x35, 0xA2 + y, 0xBA, 0xBC + y, 3, on ? HILITE : FW_BG_COLOR);
}

static void draw_page(void)
{
    fw_fill_rect(0x0D, 0x68, 0xDF, 0x134, FW_BG_COLOR);
    fw_page_dots(3);
    fw_text(0x68, 0x78, "Beep", FW_FG_COLOR, TEXT_BG, 0x10, 1);
    fw_rrect(0x20, 0x98, 0xCF, 0xE6, 5, PANEL);
    draw_option(POS_FIRST, !BEEP_ON);
    draw_option(POS_LAST, BEEP_ON);
}

void hook_settings(void)
{
    uint8_t key = FW_KEY_CURRENT;
    uint8_t pos = FW_MENU_SET_POS;

    if (!FW_MENU_SET_INIT) {         /* first entry: stock sets the cursor to 1 */
        fw_settings_menu();
        return;
    }
    if (pos < POS_FIRST) {
        if (pos == 9 && key == 9 && !FW_MENU_SET_SLIDER && FW_MENU_IN_SUB) {
            fw_settings_mark(0, 9, 0, 0);   /* V/A past the last auto-off entry: our page */
            FW_MENU_SET_POS = POS_FIRST;
            draw_page();
            draw_cursor(POS_FIRST, 1);
            return;
        }
        fw_settings_menu();
        return;
    }

    if (FW_REDRAW == 1) {            /* full-screen redraw (stock does this per page) */
        draw_page();
        if (FW_MENU_IN_SUB)
            draw_cursor(pos, 1);
        FW_REDRAW = 0;
    }
    if (!FW_MENU_SET_DRAWN) {        /* re-entered the submenu on this page */
        draw_cursor(pos, 1);
        FW_MENU_SET_DRAWN = 1;
    }
    switch (key) {
    case 9:   /* V/A: down */
        if (pos < POS_LAST) {
            draw_cursor(pos, 0);
            FW_MENU_SET_POS = (uint8_t)(pos + 1);
            draw_cursor(pos + 1u, 1);
        }
        break;
    case 1:   /* HOLD: up */
        if (pos > POS_FIRST) {
            draw_cursor(pos, 0);
            FW_MENU_SET_POS = (uint8_t)(pos - 1);
            draw_cursor(pos - 1u, 1);
        } else {
            FW_MENU_SET_POS = 9;   /* back to the auto-off page, last entry */
            fw_page_autooff();
            fw_settings_mark(9, 0, 0, 0);
        }
        break;
    case 5:   /* MODE: select */
        if ((pos == POS_LAST) != (BEEP_ON != 0)) {
            draw_option(BEEP_ON ? POS_LAST : POS_FIRST, 0);
            BEEP_ON = pos == POS_LAST;
            draw_option(pos, 1);
            hook_beep();           /* audible confirmation when switched on */
        }
        break;
    case 13:  /* SAVE: leave the submenu (the menu code does the rest) */
        draw_cursor(pos, 0);
        break;
    }
}
