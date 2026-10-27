#!/bin/bash
T="$(cd "$(dirname "$0")" && pwd)"; R="$(cd "$T/../.." && pwd)"
# Rebuild the objects, compare the given ones with the ROM (verbose), and verify the ROM still matches.
$T/build_eu_objs.sh > /dev/null
python3 -I $T/cmp_eu.py "$@" -v | grep -v anchor | grep -v " ok "
cd $R && make compare 2>&1 | tail -1
