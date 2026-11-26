#!/usr/bin/env python3
"""Build the USB-enabled DMC-100 firmware from the stock V1.4 image.

    python3 build.py [--stock ../firmware/APP_DMC-100_V1.4_250524.bin] [--out ../firmware/...]

Steps: verify the stock image hash, compile and link the patch blob (arm-none-eabi-gcc),
check every patch site still holds the expected original instruction, write the BLs and the
vector, append the blob, and verify the result (sizes, region limits, BL targets decode back).
"""
import argparse
import hashlib
import os
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
BASE = 0x08007000
STOCK_SHA256 = "f8eab197553e117a374dc9926989b8ec2105baa8120682bd5c864bda30e8364d"
STOCK_END = 0x0801E6F0
LIMIT = 0x0801F400          # stock settings page
DEAD = (0x08013860, 0x0801456C)   # stock OTG driver, unreachable once vector 67 is redirected
OLD_IRQ_STUB = 0x08008B7A   # "b.w 0x080141A4" of the old IRQ 67 handler
VECTOR_OTGFS = 16 + 67      # vector index of IRQ 67

# (site, original target, hook symbol)
BL_PATCHES = [
    (0x0801076C, 0x0800C200, "hook_init"),     # main: last init call before the loop
    (0x080107D0, 0x080125D4, "hook_parse"),    # main loop: DMM frame decoder
    (0x080107E6, 0x080121B8, "hook_loop"),     # main loop: charging lockout
    (0x08012894, 0x08012A74, "hook_dmm_send"), # DMM command: first send
    (0x08012992, 0x08012A74, "hook_dmm_send"), # DMM command: resend every 200 ms until acked
    (0x0800C754, 0x08012F70, "hook_settings"), # menu: settings controller
    (0x080106FC, 0x0801456C, "hook_load"),     # main: settings load
    (0x08012AD4, 0x08014678, "hook_save"),     # power-off: settings save
    (0x0800F190, 0x0800F100, "hook_defaults"), # reset all settings: defaults
]
# function entries replaced by a B.W to our code: (address, expected first 4 bytes, symbol)
BW_PATCHES = [
    (0x08009450, "03490120", "hook_beep"),     # short beep
    (0x08009420, "70b50a4d", "hook_beep3"),    # triple beep (auto power-off warning)
]
# raw instruction patches: (address, old, new)
RAW_PATCHES = [
    (0x0800E306, "7330", "6f30"),   # page dots: x = 0x6F + 9 i (centred for 4)
    (0x0800E310, "032c", "042c"),   # page dots: 4 instead of 3
]
VERSION_OLD = b"DMC-100  V1.4"
VERSION_NEW = b"DMC-100 V1.4U"

CFLAGS = [
    "-mcpu=cortex-m4", "-mthumb", "-mfloat-abi=soft", "-Os", "-std=c11",
    "-ffreestanding", "-fno-builtin", "-nostdlib", "-fno-common",
    "-ffunction-sections", "-fdata-sections", "-Wall", "-Wextra", "-Werror",
]


def bl_encode(site, target):
    off = target - (site + 4)
    if not -(1 << 24) <= off < (1 << 24) or off & 1:
        raise ValueError(f"BL out of range {site:#x} -> {target:#x}")
    s = (off >> 24) & 1
    i1 = (off >> 23) & 1
    i2 = (off >> 22) & 1
    imm10 = (off >> 12) & 0x3FF
    imm11 = (off >> 1) & 0x7FF
    j1 = (~(i1 ^ s)) & 1
    j2 = (~(i2 ^ s)) & 1
    hw1 = 0xF000 | (s << 10) | imm10
    hw2 = 0xD000 | (j1 << 13) | (j2 << 11) | imm11
    return struct.pack("<HH", hw1, hw2)


def bw_encode(site, target):
    """Thumb-2 B.W (T4): like BL but bit 14 of the second halfword clear."""
    raw = bytearray(bl_encode(site, target))
    hw2 = struct.unpack_from("<H", raw, 2)[0] & ~0x4000
    struct.pack_into("<H", raw, 2, hw2)
    return bytes(raw)


def bl_decode(site, raw):
    hw1, hw2 = struct.unpack("<HH", raw)
    if hw1 & 0xF800 != 0xF000 or hw2 & 0xD000 != 0xD000:
        return None
    s = (hw1 >> 10) & 1
    imm10 = hw1 & 0x3FF
    j1 = (hw2 >> 13) & 1
    j2 = (hw2 >> 11) & 1
    imm11 = hw2 & 0x7FF
    i1 = (~(j1 ^ s)) & 1
    i2 = (~(j2 ^ s)) & 1
    off = (s << 24) | (i1 << 23) | (i2 << 22) | (imm10 << 12) | (imm11 << 1)
    if s:
        off -= 1 << 25
    return site + 4 + off


def run(cmd):
    r = subprocess.run(cmd, cwd=HERE, capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"command failed: {' '.join(cmd)}\n{r.stdout}{r.stderr}")
    return r.stdout


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--stock", default=os.path.join(HERE, "..", "firmware", "APP_DMC-100_V1.4_250524.bin"))
    ap.add_argument("--out", default=os.path.join(HERE, "..", "firmware", "APP_DMC-100_V1.4U_USB.bin"))
    a = ap.parse_args()

    if not os.path.exists(a.stock):
        # no stock image: recreate it from the disassembly listing in this repo (byte-identical,
        # the hash check below verifies it)
        disasm = os.path.join(HERE, "..", "dmc100_disasm.asm")
        print(f"{os.path.relpath(a.stock)} not found, rebuilding it from dmc100_disasm.asm")
        os.makedirs(os.path.dirname(os.path.abspath(a.stock)), exist_ok=True)
        r = subprocess.run([sys.executable, "-I", os.path.join(HERE, "..", "tools", "rebuild_bin.py"),
                            disasm, a.stock], capture_output=True, text=True)
        if r.returncode:
            sys.exit(f"rebuilding the stock image failed:\n{r.stdout}{r.stderr}")
    img = bytearray(open(a.stock, "rb").read())
    if hashlib.sha256(img).hexdigest() != STOCK_SHA256:
        sys.exit("stock image does not match V1.4 (250524); refusing to patch")
    assert BASE + len(img) == STOCK_END

    build = os.path.join(HERE, "build")
    os.makedirs(build, exist_ok=True)
    elf = os.path.join(build, "patch.elf")
    objs = []
    for src in ("usb_cdc.c", "bridge.c", "settings_ui.c"):
        obj = os.path.join(build, src[:-2] + ".o")
        run(["arm-none-eabi-gcc", *CFLAGS, "-c", src, "-o", obj])
        objs.append(obj)
    run(["arm-none-eabi-gcc", *CFLAGS, "-T", "link.ld", "-Wl,--gc-sections",
         f"-Wl,-Map={os.path.join(build, 'patch.map')}", *objs, "-o", elf, "-lgcc"])
    blob_path = os.path.join(build, "patch.bin")
    dead_path = os.path.join(build, "patch_dead.bin")
    run(["arm-none-eabi-objcopy", "-O", "binary", "-j", ".text", elf, blob_path])
    run(["arm-none-eabi-objcopy", "-O", "binary", "-j", ".text_dead", elf, dead_path])
    blob = open(blob_path, "rb").read()
    dead = open(dead_path, "rb").read()

    syms = {}
    for line in run(["arm-none-eabi-nm", elf]).splitlines():
        parts = line.split()
        if len(parts) == 3:
            syms[parts[2]] = int(parts[0], 16)
    for need in ("hook_init", "hook_parse", "hook_loop", "usb_irq", "hook_dmm_send",
                 "hook_beep", "hook_beep3", "hook_settings", "hook_load", "hook_save", "hook_defaults",
                 "__bss_start", "__bss_end"):
        if need not in syms:
            sys.exit(f"missing symbol {need}")
    if syms["hook_init"] != STOCK_END:
        sys.exit("blob does not start at the stock image end")
    if len(dead) > DEAD[1] - DEAD[0]:
        sys.exit("dead-region part too large")
    end = STOCK_END + len(blob)
    if end > LIMIT:
        sys.exit(f"blob too large: ends {end:#x}, limit {LIMIT:#x}")
    ram = syms["__bss_end"] - syms["__bss_start"]

    # patch BLs (verify the original instruction first)
    for site, orig, sym in BL_PATCHES:
        o = site - BASE
        if bytes(img[o:o + 4]) != bl_encode(site, orig):
            sys.exit(f"unexpected instruction at {site:#x}")
        img[o:o + 4] = bl_encode(site, syms[sym])

    for site, old, sym in BW_PATCHES:
        o = site - BASE
        if bytes(img[o:o + 4]).hex() != old:
            sys.exit(f"unexpected entry at {site:#x}")
        img[o:o + 4] = bw_encode(site, syms[sym])
    for site, old, new in RAW_PATCHES:
        o = site - BASE
        if bytes(img[o:o + 2]).hex() != old:
            sys.exit(f"unexpected bytes at {site:#x}")
        img[o:o + 2] = bytes.fromhex(new)

    # OTGFS vector
    vo = VECTOR_OTGFS * 4
    old = struct.unpack_from("<I", img, vo)[0]
    if old != 0x08008B79:
        sys.exit(f"unexpected OTGFS vector {old:#x}")
    struct.pack_into("<I", img, vo, syms["usb_irq"] | 1)

    # old IRQ 67 stub -> "bx lr; nop", then blank the dead driver and put our part there
    o = OLD_IRQ_STUB - BASE
    if bytes(img[o:o + 4]) != bytes.fromhex("0bf013bb"):
        sys.exit("unexpected old IRQ stub")
    img[o:o + 4] = bytes.fromhex("704700bf")
    d0, d1 = DEAD[0] - BASE, DEAD[1] - BASE
    img[d0:d1] = b"\xff" * (d1 - d0)
    img[d0:d0 + len(dead)] = dead

    # version string on the boot screen
    i = img.find(VERSION_OLD)
    if i < 0 or img.count(VERSION_OLD) != 1:
        sys.exit("version string not found")
    img[i:i + len(VERSION_NEW)] = VERSION_NEW

    img += blob

    # verification
    for site, _, sym in BL_PATCHES:
        if bl_decode(site, img[site - BASE:site - BASE + 4]) != syms[sym]:
            sys.exit(f"BL verify failed at {site:#x}")
    assert struct.unpack_from("<I", img, vo)[0] == syms["usb_irq"] | 1
    assert img[:len(img) - len(blob)].count(VERSION_NEW) == 1

    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    open(a.out, "wb").write(img)
    print(f"blob    {len(blob)} B at {STOCK_END:#010x}..{end:#010x} "
          f"({LIMIT - end} B left before the settings page)")
    print(f"dead    {len(dead)} B at {DEAD[0]:#010x} ({DEAD[1] - DEAD[0] - len(dead)} B left)")
    print(f"ram     {ram} B at {syms['__bss_start']:#010x}")
    for k in ("hook_init", "hook_parse", "hook_loop", "usb_irq"):
        print(f"{k:12s}{syms[k]:#010x}")
    print(f"output  {os.path.relpath(a.out)}  {len(img)} B  sha256 {hashlib.sha256(img).hexdigest()}")


if __name__ == "__main__":
    main()
