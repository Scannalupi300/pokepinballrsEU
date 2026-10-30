# Native Windows build: `make pc` builds pokepinballrs_pc.exe, a 32-bit Win32
# program made of the game's C code and data (no emulator).
#
# It is 32-bit so that pointers are 4 bytes like on the GBA: the data assembly
# and the C structures then have the same layout. The GBA memory is at its GBA
# addresses (a section of the image, see pc.ld below) and every RAM variable
# gets its address from the GBA ELF, so the ROM build comes first.
#
# Needs the MSYS2 i686 toolchain: pacman -S mingw-w64-i686-gcc

PC_BIN ?= /mingw32/bin
PC_RUN := PATH="$(PC_BIN):$$PATH"
PC_CC := $(PC_RUN) $(PC_BIN)/gcc
PC_AS := $(PC_RUN) $(PC_BIN)/as

PC_DIR := build/pc
PC_EXE := pokepinballrs_pc.exe

# PC_CONSOLE=1 keeps a console window with the log.
PC_CONSOLE ?= 0
ifeq ($(PC_CONSOLE),1)
PC_SUBSYSTEM := -mconsole
else
PC_SUBSYSTEM := -mwindows
endif

# Game side: no leading underscore in symbol names, like the data assembly.
# char is unsigned on the GBA, and the code relies on wrapping arithmetic. Some
# loops write past the end of RAM arrays, which on the GBA (and here, with the
# same RAM layout) lands in the next variable: GCC must not assume they don't.
PC_GAME_CFLAGS := -O2 -g -funsigned-char -fwrapv -fno-strict-aliasing -fno-leading-underscore \
                  -fcommon -fno-aggressive-loop-optimizations -fno-delete-null-pointer-checks \
                  -mno-ms-bitfields -mno-stack-arg-probe -DPLATFORM_PC -iquote include -iquote pc -w
PC_HOST_CFLAGS := -O2 -g -Wall -msse2 -mfpmath=sse -iquote pc

PC_GAME_C_SRCS := $(C_SRCS) pc/gba_bios.c pc/m4a_host.c pc/audio.c pc/hooks.c
PC_HOST_C_SRCS := pc/win32.c pc/video.c pc/ppu.c pc/input.c pc/settings.c pc/ui.c pc/ui_art.c pc/state.c pc/replay.c pc/stats.c pc/online.c
PC_DATA_SRCS := $(filter-out data/rom_tail.s,$(DATA_ASM_SRCS))

PC_OBJS := $(patsubst %.c,$(PC_DIR)/%.o,$(PC_GAME_C_SRCS)) \
           $(patsubst %.s,$(PC_DIR)/%.o,$(PC_DATA_SRCS)) \
           $(patsubst %.c,$(PC_DIR)/%.o,$(PC_HOST_C_SRCS)) \
           $(PC_DIR)/pc/libc.o

.PHONY: pc

pc: $(PC_EXE)

ifeq ($(NODEP),)
$(PC_DIR)/src/%.o: pc_c_dep = $(shell $(SCANINC) -I include -I pc $(C_SUBDIR)/$*.c)
$(PC_DIR)/pc/%.o: pc_c_dep = $(shell $(SCANINC) -I include -I pc pc/$*.c)
$(PC_DIR)/src/%.o: PC_GAME_CFLAGS += -iquote pc
$(PC_DIR)/data/%.o: pc_data_dep = $(shell $(SCANINC) $(DATA_ASM_SUBDIR)/$*.s)
else
$(PC_DIR)/src/%.o: pc_c_dep :=
$(PC_DIR)/pc/%.o: pc_c_dep :=
$(PC_DIR)/data/%.o: pc_data_dep :=
endif

# The game side goes through pc/struct_align.pl: agbcc's struct layout.
$(PC_DIR)/src/%.o: src/%.c $$(pc_c_dep) pc/struct_align.pl
	@mkdir -p $(@D)
	$(PC_CC) $(PC_GAME_CFLAGS) -E $< -o $(PC_DIR)/src/$*.i
	$(PREPROC) $(PC_DIR)/src/$*.i charmap.txt | perl pc/struct_align.pl > $(PC_DIR)/src/$*.pp.c
	$(PC_CC) $(PC_GAME_CFLAGS) -c $(PC_DIR)/src/$*.pp.c -o $@

$(PC_DIR)/pc/%.o: pc/%.c $$(pc_c_dep) pc/struct_align.pl
	@mkdir -p $(@D)
	$(PC_CC) $(PC_GAME_CFLAGS) -E $< | perl pc/struct_align.pl > $(PC_DIR)/pc/$*.pp.c
	$(PC_CC) $(PC_GAME_CFLAGS) -c $(PC_DIR)/pc/$*.pp.c -o $@

$(PC_DIR)/pc/libc.o: pc/libc.c
	@mkdir -p $(@D)
	$(PC_CC) $(PC_GAME_CFLAGS) -fno-builtin -fno-tree-loop-distribute-patterns -c $< -o $@

$(patsubst %.c,$(PC_DIR)/%.o,$(PC_HOST_C_SRCS)): $(PC_DIR)/pc/%.o: pc/%.c pc/host.h pc/frame.h pc/pc.h
	@mkdir -p $(@D)
	$(PC_CC) $(PC_HOST_CFLAGS) -c $< -o $@

$(PC_DIR)/pc/ppu.o: PC_HOST_CFLAGS += -O3

$(PC_DIR)/data/%.o: data/%.s $$(pc_data_dep) pc/arm2x86.sed
	@mkdir -p $(@D)
	$(PREPROC) $< charmap.txt | $(CPP) -I include | sed -f pc/arm2x86.sed | $(PC_AS) --32 -o $@

# The RAM variables at their GBA addresses, and the constants that
# ld_script.txt defines (gNumMusicPlayers, gMaxLines).
$(PC_DIR)/ram_syms.ld: $(ELF) pc/pc.mk
	@mkdir -p $(@D)
	$(PREFIX)nm $< | awk '($$2 == "B" && $$1 >= "02000000" && $$1 < "04000000" && $$3 != "SoundMainRAM_Buffer") || $$2 == "A" { printf "%s = 0x%s;\n", $$3, $$1 }' > $@

# The default PE link script with the GBA memory (0x02000000-0x0E00FFFF) as
# the first section of the image, plus the RAM symbols. Windows maps the image
# before anything else, so these addresses are always ours. Sections can't
# have gaps between them, so the code and data come after it.
$(PC_DIR)/pc.ld: $(PC_DIR)/ram_syms.ld pc/pc.mk
	@mkdir -p $(@D)
	$(PC_RUN) $(PC_BIN)/ld --verbose -m i386pe | sed -n '/^======/,/^======/p' | sed '1d;$$d' \
		| sed 's|^  \.text  __image_base__ + ( __section_alignment__ < 0x1000 ? \. : __section_alignment__ ) :|  .gbamem __image_base__ + __section_alignment__ :\n  {\n    . = 0x0E010000 - (__image_base__ + __section_alignment__);\n  }\n  .text BLOCK(__section_alignment__) :|' > $@
	grep -q '^  \.gbamem' $@
	cat $(PC_DIR)/ram_syms.ld >> $@

$(PC_EXE): $(PC_OBJS) $(PC_DIR)/pc.ld
	$(PC_CC) $(PC_SUBSYSTEM) -static -o $@ $(PC_OBJS) -Wl,-T,$(PC_DIR)/pc.ld \
		-Wl,--image-base,0x01FF0000 -Wl,--disable-dynamicbase -Wl,--disable-reloc-section -lwinmm -lgdi32 -lwinhttp
