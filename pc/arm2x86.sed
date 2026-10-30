# Turns the preprocessed ARM data assembly into input for the i686 assembler.
# The data files have no '@' inside strings, so '@' always starts a comment.
s/@.*//
# On i386 .word is 16 bits and .align counts bytes.
s/\.word\b/.4byte/g
s/\.hword\b/.2byte/g
s/\.align\b/.p2align/g
# ARM and ELF only.
/^[[:space:]]*\.syntax\b/d
/^[[:space:]]*\.thumb/d
/^[[:space:]]*\.arm\b/d
/^[[:space:]]*\.type\b/d
/^[[:space:]]*\.size\b/d
/^[[:space:]]*\.pool\b/d
