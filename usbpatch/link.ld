/*
 * Patch blob placement.
 *
 * DEAD:  0x08013860..0x0801456C, the stock firmware's OTG device driver. Nothing initialises
 *        USB in the stock app, the only way in was the IRQ 67 vector (and its stub at
 *        0x08008B78), both of which build.py redirects. Verified unreferenced from outside.
 *        (0x08013848..0x0801385F in front of it is the live "usbflash" FAT mount: untouched.)
 * PATCH: right after the stock image (ends 0x0801E6F0) up to the stock settings page at
 *        0x0801F400 (1 KB, written by the firmware at runtime).
 * PRAM:  above the stock stack top 0x20007240 (+16 B the bootloader pops) to the end of the
 *        32 KB SRAM. Zeroed by hook_init, no initialised data allowed.
 */
MEMORY
{
    DEAD  (rx)  : ORIGIN = 0x08013860, LENGTH = 0x0801456C - 0x08013860
    PATCH (rx)  : ORIGIN = 0x0801E6F0, LENGTH = 0x0801F400 - 0x0801E6F0
    PRAM  (rw)  : ORIGIN = 0x20007300, LENGTH = 0x20007FF0 - 0x20007300
    /* 0x20007FF0..0x20007FFF: not zeroed, survives until hook_init (beep flag) */
}

ENTRY(hook_init)

SECTIONS
{
    .text_dead : {
        *usb_cdc.o(.text* .rodata*)
        . = ALIGN(4);
    } > DEAD

    .text : {
        KEEP(*(.text.hook_init))
        KEEP(*(.text.hook_parse))
        KEEP(*(.text.hook_loop))
        KEEP(*(.text.usb_irq))
        KEEP(*(.text.hook_dmm_send))
        KEEP(*(.text.hook_beep))
        KEEP(*(.text.hook_beep3))
        KEEP(*(.text.hook_settings))
        KEEP(*(.text.hook_load))
        KEEP(*(.text.hook_save))
        KEEP(*(.text.hook_defaults))
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > PATCH

    .data : { *(.data*) } > PRAM AT > PATCH

    .bss (NOLOAD) : {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end = .;
    } > PRAM

    /DISCARD/ : { *(.ARM.exidx*) *(.ARM.attributes) *(.comment) }
}

ASSERT(SIZEOF(.data) == 0, "initialised data is not supported, use const or zeroed bss")
