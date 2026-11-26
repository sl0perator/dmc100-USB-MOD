#!/usr/bin/env python3
"""Rebuild the original firmware image from dmc100_disasm.asm.

Code lines carry their bytes; data gaps are listed as '; ---- data/gap A .. B (n bytes)'
followed by a '; xx xx ...' line. One gap (0x0800EE7A, TJpgDec Clip8 table's 0xFF run)
is truncated with '...' - it is filled with the repeating byte shown.
"""
import re, sys
src, out = sys.argv[1], sys.argv[2]
BASE = 0x08000000
img = bytearray(); expected = BASE
pat_code = re.compile(r'^\s*0x([0-9A-Fa-f]{8}):\s+((?:[0-9a-f]{2} )+)')
pat_word = re.compile(r'^\s*0x([0-9A-Fa-f]{8}):\s+\.word\s+0x([0-9A-Fa-f]{8})')
pat_addr = re.compile(r'^\s*0x([0-9A-Fa-f]{8}):')
pat_gap = re.compile(r'^; ---- data/gap\s+0x([0-9A-Fa-f]{8}) \.\. 0x([0-9A-Fa-f]{8})\s+\((\d+) bytes\)')
lines = open(src).read().splitlines()
i = 0
while i < len(lines):
    ln = lines[i]; i += 1
    g = pat_gap.match(ln)
    if g:
        a, n = int(g[1], 16), int(g[3])
        data = lines[i].strip().lstrip(';').strip(); i += 1
        trunc = data.endswith('...')
        b = bytes.fromhex(data.rstrip('.').strip())
        if trunc:
            assert len(set(b)) == 1, "truncated gap with non-uniform fill"
            b = bytes([b[0]]) * n
        assert len(b) == n, f"gap len mismatch at {a:08x}"
    else:
        m = pat_word.match(ln)
        if m:
            a = int(m[1], 16); b = int(m[2], 16).to_bytes(4, 'little')
        else:
            m = pat_code.match(ln)
            if not m:
                if pat_addr.match(ln): sys.exit("UNPARSED: " + ln)
                continue
            a = int(m[1], 16); b = bytes.fromhex(m[2])
    if a < expected:  # disassembler resynced mid-instruction: overlap must agree
        ov = expected - a
        if img[a - BASE:a - BASE + ov] != b[:ov]: sys.exit(f"inconsistent overlap at {a:08x}")
        b = b[ov:]; a = expected
    if a != expected: sys.exit(f"gap at {a:08x}, expected {expected:08x}")
    img += b; expected += len(b)
open(out, 'wb').write(img)
print(len(img), "bytes")
