# DMC-100 USB mod

USB connectivity for the FNIRSI DMC-100 clamp meter: a patched V1.4 firmware that turns the
USB-C port into a USB serial port (CDC-ACM) while the meter keeps working as before, plus a
browser app to view, chart, log and control it.

> [!CAUTION]
> **A USB isolator between the meter and the computer is required. Do not connect the meter
> to a computer without one.**
>
> The meter's measurement inputs (the COM and V/Ω jacks) are not isolated from the USB
> port. Without isolation, a USB cable connects whatever you are measuring to your
> computer's ground. If you measure mains voltage, or anything not referenced to the same
> earth as the PC, that can **destroy the computer and the meter, start a fire, or give you a
> lethal electric shock** through the computer chassis, the cable shield or anything else
> connected to the PC.
>
> - Use a USB isolator rated for the voltages involved (for example an ADuM3160 / ADuM4160
>   based "USB isolator", full speed, 1.5 kV or more). Plug it in between the PC and the
>   meter, every time.
> - A battery-powered laptop **is not** a substitute: its chassis, other cables and you
>   are still part of the circuit.
> - The stock firmware refuses to measure while the meter is on USB power ("Do not use while
>   charging") for exactly this reason. **This mod removes that protection.** The meter now
>   measures while connected to any USB port or charger.
> - Measuring current with the clamp jaws alone is isolated by the clamp itself, but the test
>   leads are not. Unplug the test leads if you are not using the isolator.
>
> You use this mod at your own risk.

## What you get

- Live readings over USB: display text, value, unit, function, AC/DC, HOLD, the raw frame of
  the measuring chip.
- Power view (long V/A): voltage, clamp current and power at the same time.
- Control: every button (short/long press), function select, keep-awake, stream on/off,
  beeper on/off.
- A fourth settings page **Beep** (OFF/ON, default OFF), saved with the other settings.
- `web/index.html`: one offline HTML file (Chrome/Edge, WebSerial) with readout, chart, stats,
  CSV/JSON recording, buttons, status and a console.
- The boot screen says `DMC-100 V1.4U`.

Not possible in firmware: the beeps on function changes come from the separate measuring
chip, which sounds the buzzer itself when it receives a command. Only the main firmware's beeps
(HOLD release, power-off, auto power-off warning) follow the Beep setting.

## Download

Ready-made firmware: [`firmware/APP_DMC-100_V1.4U_USB.bin`](firmware/APP_DMC-100_V1.4U_USB.bin).
The stock V1.4 image, for going back, is next to it:
[`firmware/APP_DMC-100_V1.4_250524.bin`](firmware/APP_DMC-100_V1.4_250524.bin).

Where the stock image comes from: FNIRSI's online manual pages don't make the V1.4 firmware
easy to find, but it is on their Shopify CDN:
<https://cdn.shopify.com/s/files/1/0694/8310/2426/files/APP_DMC-100_V1.4_250524.bin>
(95,984 bytes, SHA-256 `f8eab197553e117a374dc9926989b8ec2105baa8120682bd5c864bda30e8364d`,
identical to the copy in `firmware/`).

## Building

Needs `arm-none-eabi-gcc` and Python 3:

```sh
python3 usbpatch/build.py
# -> firmware/APP_DMC-100_V1.4U_USB.bin (overwrites the committed one)
```

The script patches the stock V1.4 image `firmware/APP_DMC-100_V1.4_250524.bin` (SHA-256
`f8eab197…8e364d`, checked). If that file is missing, it recreates it byte for byte from
`dmc100_disasm.asm` with `tools/rebuild_bin.py`, so a fresh clone builds as is.

## Flashing

As with FNIRSI updates: meter off and unplugged, hold **HOLD + SAVE** and press **POWER**,
plug in USB, copy the `.bin` to the drive that appears (it must be the only `.bin` there),
press **SAVE**. The bootloader is never touched, so the stock file can always be flashed back
the same way.

## Using it

Linux: the meter appears as `2e3c:5740` "FNIRSI DMC-100 Clamp Meter", `/dev/ttyACM0`.
Open `web/index.html` in Chrome or Edge and click **Connect**, or use any terminal
(`picocom /dev/ttyACM0`). The baud rate is ignored.

## Custom boot logo (stock feature)

The stock firmware already supports a custom boot logo. At boot it briefly mounts the
**firmware drive** (the drive the bootloader shows in update mode, NOR offset 0) and draws
`LOGO.jpg` from it at (0, 0); without the file it shows its built-in picture
(`0x0800DF38`). "Reset all settings" deletes `LOGO.jpg` from that drive again (`0x0800F1BC`).

1. Make a 240 × 320 (portrait) **baseline** JPEG; the decoder (TJpgDec) does not do
   progressive JPEGs. For example with ImageMagick:
   `magick in.png -resize 240x320^ -gravity center -extent 240x320 -strip -interlace none -sampling-factor 4:2:0 -quality 90 LOGO.jpg`
2. Enter update mode (HOLD + SAVE + POWER), plug in, copy `LOGO.jpg` to the drive, eject.
3. Switch the meter off and on (or copy it together with a firmware `.bin` and press SAVE).

## Protocol

Text lines, comma separated, `\n` terminated. Commands are a letter and a number, then `\n`.

### Meter → PC

`R` (one per measurement frame):

| # | field | meaning |
|---|---|---|
| 1 | ms | meter uptime in ms |
| 2 | mode | function 0..11: DC V, AC V, Ω, continuity, diode, capacitance, frequency, temperature, live/neutral, NCV, DC A, AC A |
| 3 | unit | 1 none, 2 mV, 3 V, 4 µA, 5 mA, 6 A, 7 Ω, 8 kΩ, 9 MΩ, 10 nF, 11 µF, 12 mF, 13 Hz, 14 kHz, 15 MHz, 16 °C/°F (see temp_unit) |
| 4 | acdc | 2 DC, 1 AC, -1 neither |
| 5 | hold | 1 while HOLD |
| 6 | numeric | 0 when the display shows OL / dashes |
| 7 | value | IEEE-754 float, hex, in the displayed unit |
| 8 | bar | float, hex: 22-bit frame value / 100 (power view: clamp current in A) |
| 9 | bar_flag | power view: 0 DC current, 1 AC current |
| 10 | text | display string |
| 11 | raw | 13-byte frame of the measuring chip, hex (`5aa5…`) |
| 12 | view | screen layout; 2 = power view |
| 13 | rel | float, hex: zero offset the meter adds to DC clamp current |

Power view: V = value, A = bar (+ rel when bar_flag = 0), W = |V × A|.

`S` (every second and after commands):
`S,ms,mode,view,menu,charge_boot,charging,flashlight,battery,language,temp_unit,autooff,brightness,theme,hold,keepawake,stream,beep,usb_state`
(usb_state bits: 0 configured, 1 suspended, 3 port open)

`I` (on connect and on request):
`I,DMC100-USB,proto,V1.4,gotgctl,usb_resets,gccfg,session_ends,dmm_commands`

`OK,<cmd>` / `ER,<cmd>` acknowledge commands.

### PC → meter

| command | effect |
|---|---|
| `K<n>` | key press: HOLD 1/2, MODE 5/6, V/A 9/10, SAVE 13/14, POWER 17/18, LIGHT 21/22 (short/long). `K10` toggles the power view, `K22` the flashlight, `K18` switches off. |
| `M<n>` | select function 0..11 (measurement screen only) |
| `B0` / `B1` | beeper off / on (saved at power-off) |
| `A0` / `A1` | keep awake while a PC is connected (default on) |
| `P0` / `P1` | reading stream off / on |
| `S`, `I` | status / info line |

## How it works

Reverse engineering notes are in `analysis/` (`dmc100_app_0x08007000_decompiled.c` is a fresh
Ghidra decompile at the correct base) and in `usbpatch/fw.h`, which documents every stock
address used.

- **MCU**: Artery AT32F415 (Cortex-M4, no FPU), 128 KB flash in 1 KB pages, 32 KB RAM, 8 MHz
  crystal, PLL at 144 MHz. The app is linked at **0x08007000**, above a 28 KB bootloader.
- **Measuring chip**: separate chip on USART1 (PA9 TX / PA10 RX, 115200 Bd). It streams 13-byte
  frames (`5A A5 …`, LCD-segment style digits and flags plus a 22-bit value). The MCU selects
  functions with 10-byte commands `AA 55 05 <cmd> 00 00 00 00 00 <5+cmd>` and waits for an
  `FD` acknowledge frame.
- **USB**: the stock app links Artery's OTG device driver and the IRQ 67 handler but never
  initialises USB (the bootloader uses it for updates). The mod brings its own CDC-ACM driver.
  The stock OTG driver at 0x08013860..0x0801456C is unreachable once the vector is redirected,
  and holds part of the patch.
- **Patch layout**: driver in the reclaimed 0x08013860 region; glue code after the stock image
  (0x0801E6F0 up to the settings page at 0x0801F400); RAM above the stock stack (0x20007300..).
  `build.py` checks every patched instruction before it changes it.
- **Hooks**: init, frame decoder and loop tail of `main` (the loop tail used to call the
  charging lockout, which is dropped);
  both sends to the measuring chip; the two beep routines; the settings menu controller,
  loader, power-off writer and defaults; the IRQ 67 vector.
- **NOR flash**: W25Q32 (4 MB) on SPI1 with two FAT12 volumes, 4 KB sectors: the firmware
  drive at 0 (1 MB, shown by the bootloader, holds `LOGO.jpg`) and the data drive at
  0x100000 (3 MB, the `UI` pictures). The app mounts both as `2:`, switching the base at
  0x20000060.
- **Settings**: 140 bytes at 0x200000A0 ↔ flash 0x0801F400, written at power-off. The beep flag
  sits in the unused high byte of the theme halfword, so stock firmware ignores it.

## Known issues / open questions

- **PA9 is shared** between USART1 TX (commands to the measuring chip) and the OTG session
  sense input. Without a workaround every command would end the USB session and the PC would
  see a disconnect. The firmware sets VBUSIG in GCCFG for the duration of each command (the
  last byte is awaited), which keeps the session. VBUSIG alone at init does not give a session
  on this board (as DMC100-Doom found), so the PA9 comparators stay in use otherwise.
  `I` reports session drops and the number of commands sent.
- AC/DC mapping was taken from the power view's labels; unit code 1 has no label in the stock
  firmware.

## Credits

[DMC100-Doom](https://github.com/ArturBieniek4/DMC100-Doom) by Artur Bieniek documented
several hardware facts this mod relies on (USB divider, PA9 session sensing, button pins,
flash layout, update procedure). No code was copied from it.
