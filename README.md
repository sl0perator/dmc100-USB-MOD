# DMC-100 Firmware V1.4 — Modification Guide

## Files

| File | Description |
|------|-------------|
| `dmc100_decompiled_clean.c` | **Main working file** — 364 functions, compiles with 0 errors |
| `dmc100_decompiled.c` | Raw Ghidra output — source for regenerating the clean file, do not edit |
| `dmc100_strings.txt` | 523 extracted strings with flash addresses — useful for finding functions |
| `dmc100_disasm.asm` | Raw disassembly — reference when you need exact byte positions |
| `../APP_DMC-100_V1.4_250524.bin` | Original firmware — **keep this untouched as your baseline** |

---

## Firmware details

| Property | Value |
|----------|-------|
| Architecture | ARM Cortex-M4F (Thumb-2, little-endian, hardware FPU) |
| Flash base | `0x08000000` |
| Flash size | 95 984 bytes (93 KB) |
| RAM base | `0x20000000` |
| Initial stack pointer | `0x20007240` |
| Reset handler | `0x0800721C` |

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

