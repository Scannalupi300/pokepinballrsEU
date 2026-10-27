#!/usr/bin/env python3
"""Check that the ROM has no hard-coded ROM addresses, so that code and data can move.

Relinks the built objects with `ld -q` (relocations kept) into build/pokepinballrs_eu/relocs.elf,
checks that its sections are the same as pokepinballrs_eu.elf, then looks for 32-bit words that
hold a ROM address without a relocation:
  - in the literal pools of the code (the $d regions of .text): any ROM address;
  - in the data: an address that is exactly the start of a symbol (other words in the ROM range
    are mostly pixels, samples or pairs of halfwords that only look like addresses). Words inside
    .incbin data (graphics, samples, tilemaps) and the value 0x08000000 (the ROM start, a common
    pixel pattern) are skipped.
The debug monitor at the end of the ROM (.rom_tail) runs elsewhere and is skipped.
usage: check_relocs.py   (after `make`; needs pyelftools and arm-none-eabi-ld on PATH)
Exit status 1 if something is found."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
import bisect, glob, re, subprocess, sys
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROM_LO, ROM_HI = 0x08000000, 0x0A000000
BUILD = _os.path.join(_R, 'build', 'pokepinballrs_eu')
ELF = _os.path.join(_R, 'pokepinballrs_eu.elf')
OUT = _os.path.join(BUILD, 'relocs.elf')


def relink():
    objs = [m.group(1) for m in re.finditer(r'^LOAD (\S+\.o)$', open(_os.path.join(_R, 'pokepinballrs_eu.map')).read(), re.M)]
    subprocess.run(['arm-none-eabi-ld', '-q', '-T', 'ld_script.ld', '-o', 'relocs.elf'] + objs +
                   ['-L', '../../tools/agbcc/lib', '-lgcc', '-lc'], cwd=BUILD, check=True)


def blob_labels():
    """Labels whose data is an .incbin (the next non-blank line)."""
    labels = set()
    paths = [p for pat in ('data/**/*.s', 'data/**/*.inc', 'sound/**/*.s', 'sound/**/*.inc')
             for p in glob.glob(_os.path.join(_R, pat), recursive=True)]
    for path in paths:
        lines = open(path, encoding='utf-8', errors='replace').read().split('\n')
        for i, l in enumerate(lines):
            m = re.match(r'^(\w+)::?', l)
            if m and '.incbin' in next((x for x in lines[i + 1:i + 4] if x.strip()), ''):
                labels.add(m.group(1))
    return labels


def main():
    relink()
    blobs = blob_labels()
    with open(OUT, 'rb') as f1, open(ELF, 'rb') as f2:
        e, ref = ELFFile(f1), ELFFile(f2)
        secs = [s for s in e.iter_sections() if s['sh_type'] == 'SHT_PROGBITS' and s['sh_size']
                and ROM_LO <= s['sh_addr'] < ROM_HI and s.name != '.rom_tail']
        for s in secs:
            r = ref.get_section_by_name(s.name)
            if r is None or r.data() != s.data():
                sys.exit('section %s differs from pokepinballrs_eu.elf: rebuild first' % s.name)
        syms, marks = {}, []
        for sym in e.get_section_by_name('.symtab').iter_symbols():
            v = sym['st_value']
            if not sym.name or sym['st_shndx'] == 'SHN_UNDEF' or not ROM_LO <= v < ROM_HI:
                continue
            if sym.name[0] == '$':
                marks.append((v, sym.name[:2]))
            elif sym['st_info']['type'] in ('STT_OBJECT', 'STT_FUNC', 'STT_NOTYPE'):
                syms.setdefault(v & ~1, sym.name)
        marks.sort()
        mark_addrs = [m[0] for m in marks]
        sym_addrs = sorted(syms)
        covered = set()
        for rs in e.iter_sections():
            if isinstance(rs, RelocationSection):
                base = e.get_section(rs['sh_info'])['sh_addr']
                for rel in rs.iter_relocations():
                    off = rel['r_offset']           # a virtual address in a linked file
                    covered.add(off if off >= base else base + off)

        def owner(a):
            i = bisect.bisect_right(sym_addrs, a) - 1
            return '%s+0x%X' % (syms[sym_addrs[i]], a - sym_addrs[i]) if i >= 0 else '?'

        def in_blob(a):
            i = bisect.bisect_right(sym_addrs, a) - 1
            return i >= 0 and syms[sym_addrs[i]] in blobs

        def in_pool(a):
            i = bisect.bisect_right(mark_addrs, a) - 1
            return i >= 0 and marks[i][1] == '$d'

        found = 0
        for s in secs:
            data, base, code = s.data(), s['sh_addr'], s.name.startswith('.text')
            for off in range(-base % 4, len(data) - 3, 4):
                a = base + off
                w = int.from_bytes(data[off:off + 4], 'little')
                if not ROM_LO <= w < ROM_HI or a in covered:
                    continue
                if code and not in_pool(a):
                    continue                        # pairs of Thumb instructions
                if not code and (w & ~1 not in syms or w & ~1 == ROM_LO or in_blob(a)):
                    continue
                found += 1
                print('0x%08X %-8s %-44s = 0x%08X (%s)' % (a, s.name, owner(a), w, owner(w)))
    print('%d relocations checked, %d hard-coded ROM addresses found' % (len(covered), found))
    sys.exit(1 if found else 0)


if __name__ == '__main__':
    main()
