#!/usr/bin/perl
# agbcc, like ARM compilers of its time, gives every struct and union a size
# that is a multiple of 4 and 4-byte alignment (STRUCTURE_SIZE_BOUNDARY 32).
# The data assembly and the GBA RAM addresses follow that layout, so the
# native build asks GCC for the same: this adds __attribute__((aligned(4))) to
# every struct and union definition of the preprocessed source.
undef $/;
$_ = <>;
s/\b(struct|union)(\s+[A-Za-z_]\w*)?(\s*)\{/$1 __attribute__((aligned(4)))$2$3\{/g;
print;
