# FNIRSI DMC-100 firmware V1.4: reverse engineering and USB mod

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

**USB connectivity mod and browser app: see [USB_MOD.md](USB_MOD.md).**
**Viewer online: <https://sl0perator.github.io/dmc100-USB-MOD/>** (Chrome/Edge, through a USB isolator).

**License:** the USB mod (`usbpatch/`, `web/`, `tools/`, the scripts in `analysis/` and the
mod's documentation) is MIT licensed, see [LICENSE](LICENSE). It does not cover the FNIRSI
firmware, the decompiled or disassembled firmware in this repository, or the files from the
upstream repository; those remain under their respective owners' rights.

| Path | Contents |
|------|----------|
| `USB_MOD.md` | the USB mod: building, flashing, protocol, how it works |
| `usbpatch/` | patch sources (CDC-ACM driver, glue, settings page) and `build.py` |
| `web/index.html` | browser viewer/logger/remote (WebSerial); `node web/test_protocol.js` tests it |
| `firmware/` | `APP_DMC-100_V1.4U_USB.bin`: the patched firmware to flash; `APP_DMC-100_V1.4_250524.bin`: stock V1.4 (to go back, and the build input) |
| `analysis/` | Ghidra decompile **at the correct base 0x08007000**, call graph, Ghidra scripts |
| `tools/rebuild_bin.py` | recreates the stock image from `dmc100_disasm.asm` (byte-identical) |
| `dmc100_decompiled*.c`, `dmc100_disasm.asm`, `dmc100_strings.txt`, `function_renames.txt` | the original analysis, see the warning below |

> **Warning about the original analysis files.** They were produced with the image loaded at
> 0x08000000, but the app is linked at **0x08007000** (a 28 KB bootloader sits below it; the
> vector table, the Keil scatter-load table and every literal pool agree). Code bytes are
> right, but every address in `dmc100_decompiled*.c`, `function_renames.txt` and
> `dmc100_strings.txt` is 0x7000 too low, pointers into flash resolve to the wrong place, and
> several names in `function_renames.txt` are wrong. Use `analysis/` instead. The guide below
> is kept for reference; its "recompile the decompiled C" route does not produce a working
> image, the USB mod patches the stock binary instead.

## Firmware details (corrected)

| Property | Value |
|----------|-------|
| MCU | Artery AT32F415 (Cortex-M4, Thumb-2, **no FPU**), 128 KB flash (1 KB pages), 32 KB RAM |
| Clock | 8 MHz crystal, PLL 144 MHz |
| App base | `0x08007000` (bootloader `0x08000000..0x08006FFF`) |
| App size | 95 984 bytes, ends `0x0801E6F0` |
| Settings page | `0x0801F400` (1 KB, written at power-off) |
| Initial stack pointer | `0x20007240` |
| Reset handler | `0x0800721C`, `main` at `0x080106E4` |
| Measuring chip | separate, USART1 115200 Bd, 13-byte frames `5A A5 ...` |

---

## Editing the C file

Open `dmc100_decompiled_clean.c` in any editor. A few things to know before you start:

**Function names** like `FUN_08007abc` are auto-generated — the original names were stripped.
Use `dmc100_strings.txt` to find functions by the strings they reference. For example:

```bash
# find which flash address is near the string "Temperature unit"
grep "Temperature unit" dmc100_strings.txt
# -> 0x005C0C   0x08005C0C   Temperature unit

# then find the function that starts just before that address
grep "@ 0x0800" dmc100_decompiled.c | awk -F'[@ x]' '{print $NF}' | \
  awk -v t="5c0c" '$1 <= t' | tail -1
```

**`DAT_08xxxxxx`** are read-only data values sitting in flash (constant tables, config values).
They are referenced by their absolute address — leave these as-is unless you also want to
change the data they point to.

**`uint8_t` / `uint16_t` / `uint32_t`** replaced Ghidra's `undefined` pseudo-types.
If a type looks wrong for what a variable is doing, cast it to whatever makes sense.

---

## Compiling back to a binary

### Requirements

```bash
# Arch / AUR
yay -S arm-none-eabi-gcc arm-none-eabi-binutils

# Or Debian/Ubuntu
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi
```

### Linker script

Save this as `dmc100.ld` in this folder:

```ld
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 96K
  RAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 29K
}

SECTIONS
{
  .text : {
    KEEP(*(.vectors))
    *(.text*)
    *(.rodata*)
  } > FLASH

  .data : {
    *(.data*)
  } > RAM AT > FLASH

  .bss : {
    *(.bss*)
    *(COMMON)
  } > RAM
}
```

### Compile

```bash
arm-none-eabi-gcc \
  -mcpu=cortex-m4 \
  -mthumb \
  -mfpu=fpv4-sp-d16 \
  -mfloat-abi=hard \
  -O2 \
  -ffunction-sections \
  -fdata-sections \
  -T dmc100.ld \
  -Wl,--gc-sections \
  -Wl,-Map=dmc100.map \
  -nostartfiles \
  -o dmc100.elf \
  dmc100_decompiled_clean.c
```

### Convert ELF → binary

```bash
arm-none-eabi-objcopy -O binary dmc100.elf APP_DMC-100_V1.4_patched.bin
```

### Verify size

```bash
ls -l APP_DMC-100_V1.4_patched.bin
# Must be exactly 95984 bytes — pad if needed:
truncate -s 95984 APP_DMC-100_V1.4_patched.bin
```

> **Note:** The decompiled C is pseudocode — it compiles cleanly (`gcc -fsyntax-only -std=c11`)
> but linking against real ARM hardware requires `arm-none-eabi-gcc` and resolving the many
> `extern` symbols (`DAT_08xxxxxx`, `s_StringName`, etc.) that refer to flash/RAM addresses.
> The clean file already has all declarations in the preamble; to fully link you would need
> to provide a linker script mapping those externs to their actual addresses.

---

## Smaller changes: patch without recompiling

For isolated changes (flip a flag, change a limit, skip a check) it is faster and safer to
edit the binary directly using the C as a reading reference:

1. Find the relevant function in `dmc100_decompiled.c`
2. Note its address from the `@ 0x08xxxxxxx` comment header
3. Look it up in `dmc100_disasm.asm` to get the exact bytes to change
4. Run `patch.py`:

```python
# patch.py
ORIGINAL = "../APP_DMC-100_V1.4_250524.bin"
OUTPUT   = "APP_DMC-100_V1.4_patched.bin"
BASE     = 0x08000000

patches = [
    # (flash_address, new_bytes)
    # NOP example:  (0x08007abc, bytes.fromhex("00BF")),
]

data = bytearray(open(ORIGINAL, "rb").read())
for addr, new_bytes in patches:
    offset = addr - BASE
    data[offset : offset + len(new_bytes)] = new_bytes
    print(f"  patched 0x{addr:08X} (file offset 0x{offset:06X}): {new_bytes.hex(' ')}")

open(OUTPUT, "wb").write(data)
print(f"Written: {OUTPUT}  ({len(data)} bytes)")
```

```bash
python3 patch.py
```

**Useful Thumb-2 snippets:**

| Effect | Bytes |
|--------|-------|
| NOP (2-byte) | `00 BF` |
| Return immediately (`BX LR`) | `70 47` |
| Force function to return 0 | `00 20 70 47` (`MOVS r0,#0` + `BX LR`) |
| Force function to return 1 | `01 20 70 47` (`MOVS r0,#1` + `BX LR`) |

---

## CRC / checksum note

If flashing fails after patching, the bootloader may validate a CRC32 at the end of flash:

```python
import zlib, struct

data = bytearray(open("APP_DMC-100_V1.4_patched.bin", "rb").read())
crc = zlib.crc32(data[:-4]) & 0xFFFFFFFF
struct.pack_into("<I", data, len(data) - 4, crc)
open("APP_DMC-100_V1.4_patched_crc.bin", "wb").write(data)
print(f"CRC32: 0x{crc:08X}")
```

