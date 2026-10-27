# Pokémon Pinball: Ruby & Sapphire (Europe)

This is a decompilation of the European release of Pokémon Pinball: Ruby & Sapphire (game code
BPPP), the multi-language version in English, French, German, Italian and Spanish.

It builds the following ROM:

* pokepinballrs_eu.gba `sha1: b8b7881eaa9856b5ada99078ad1053d31cb79827`

To set up the repository, see [INSTALL.md](INSTALL.md). To debug the game with mGBA and GDB, see
[DEBUG.md](DEBUG.md).

## Status

- **The ROM is rebuilt byte for byte** (`make compare`).
- **Code: all 848 functions are C.** None of them falls back to the original assembly.
- **Data: everything is in source form.** Graphics are PNG/palette files, texts and tables are
  assembler source, and pointers are symbolic. No binary blob and no anonymous `.byte` line is
  left. The 16 KB block at `0x08FE0000` that the game never references, a debug monitor, is
  disassembled to ARM/Thumb assembly (see *The block at the end of the ROM*).

## Building

Set up the toolchain as described in [INSTALL.md](INSTALL.md), then:

    make compare

The build does not need the original ROM. The analysis tools in `tools/eu_port` do: copy the
European ROM to `baserom_eu.gba` at the root of the repository (it is ignored by git), or set
`BASEROM_EU`.

On Windows (MSYS2), use the msys `jq`, because the mingw one writes CRLF line endings. Also run
Python in UTF-8 mode (`python -X utf8`).

## The European release

- **Language selection.** A language selection screen appears at the first boot. The language
  is stored in the save data: `gMain_saveData.language`, with EN 0, FR 1, DE 2, IT 3, ES 4, and
  99 for not set yet.
- **Per-language assets almost everywhere.** This covers the board graphics and HUD, mode
  banners, catch/evolution/shop texts, bonus field results, high score screen, title screen
  menus, options, pause menu, Pokédex, e-Reader screens and intro texts. The languages are
  grouped differently from asset to asset. For example, one table may be shared by
  English/French while German, Italian and Spanish each have their own; the code follows the
  grouping of the ROM.
- **Pokémon names in three versions:** English (also used in Italian and Spanish), French and
  German.
- **The Pokédex** has its 205 entries (categories and descriptions) in five languages, with
  accented letters, ß, „ “ « », œ and per-language character widths.
- **The ROM is 16 MiB.**

## Layout of the source

### Code

- Per-language symbols use suffixes such as `_En`, `_Fr`, `_De`, `_It`, `_Es`, or a language
  group (`_EnFr`, `_EnDe`, `_EnDeItEs`, …).
- Macros in `include/global.h` (`LANG5_SWITCH`, `DMA_LANG5`, `EXTERN_LANG5`, `DMA_LANG4_ENFR`,
  `LANG4_SWITCH_ENDE`, `DMA_PORTRAIT_ANIM_FRAME`, …) express the usual "pick the asset of the
  current language" patterns, so that they compile like the original code.
- RAM layout: `sym_ewram.txt`, `sym_bss.txt` and `sym_common.txt`.

### Data

- **`data/*.s`** hold the ROM data in ROM order: `rom_1.s`, `sound_data.s`, `sound_data_2.s`,
  `rom_2.s` and `rom_tail.s`. Pointer tables are symbolic, sprite sets use the
  `packed_sprite_oam(l)` macros, tables are written with the element type of their C
  declaration, and VRAM destinations with expressions such as `BG_ADDR_FOR_BOARD_WRAP(y, x)`.
- **`data/src/*.inc`** hold the larger hand-written or dumped sources:
  - the Pokédex entries in five languages;
  - the bonus summary texts;
  - the e-Reader texts (15 pages × 3 lines × 5 languages) and their page tables;
  - the default high scores, pause menu sprite offsets and "press start" tiles;
  - a few orphaned sound effect tracks.
- **Graphics** are in `graphics/`. Per-language copies are named
  `<file>_<language group>.png/.pal/.bin` (`_eu` when the symbol has no language suffix). Each
  one converts back to the exact bytes of the ROM. Special build rules are in
  `graphics_rules.mk`, `graphics_rules_eu.mk` and in gfx-config JSON files (for example, the
  French, German and Spanish Pokédex sprite sheets have their own segments in
  `graphics/pokedex/pokedex_gfx_eu.json`).
- Copies of English data that the code never uses (EVO/coin arrows for French, Italian and
  Spanish) are built from the English files, and labelled as unused.

### The block at the end of the ROM

After the game data, the ROM has a 16 KB block at `0x08FE0000` that the game never references,
then `0xFF` padding and 2 KB of zeros. The block is a debug monitor for the development
hardware. It was linked to run from the memory of a 1 Mbit DACS at `0x09FE0000`, not from where
it sits in this ROM:

- `0x09FE2000` is the debugging handler of the BIOS. When bits 2 and 7 of the header byte at
  `0x0800009C` are set, the BIOS forwards the FIQ and undefined instruction exceptions there.
  The monitor sets that byte to `0xA5` when it resumes the game, and restores the original byte
  at the next exception;
- it saves the state of the game (the registers of every CPU mode, DMA, WAITCNT, IME), then
  runs the commands that a host writes to a shared block (`MonCommandBlock`). The 11 commands
  are: read or write memory through a buffer, single step, resume, reset the game, identify,
  erase and program the flash memory, fill memory, and call functions of the game. A single
  step replaces the next instruction with an undefined one; the monitor computes the address
  of that instruction by decoding ARM and Thumb branches and conditions;
- a resident part (the first 4 KB) runs at `0x09FE2000`. Three overlays (the following 4 KB
  pages) all run at `0x09FE3000`: a control register at `0x09FE2FFE` selects the page shown
  there. Each overlay starts with a table of entry points, and its pointers into `0x09FE3xxx`
  refer to itself.

`tools/eu_port/disasm_rom_tail.py` disassembles it to `data/rom_tail.s` with capstone, following
branches, code pointers, literal pools, gcc switch tables and function prologues. Functions and
data have names and short comments based on what the code does (`MonException`,
`MonCommandLoop`, `MonCmd2_TransferMemory`, `MonOv1_NextArmPc`, …). The other labels are named
after their run address, and the run-time addresses stored in the block are written as
`label - RES` (or `OV1`, `OV2`, `OV3`). The script checks the file by assembling it the way the
Makefile does: all 2,460 instructions assemble back to the original bytes, so none of them
needs `.inst`.

### Text encoding (`tools/preproc`)

- `.dexLang EN|FR|DE|IT|ES` selects the European glyph encoding of the Pokédex font for the
  strings that follow; `.dexLang US`, the default, selects the original encoding.
- `{XXXX}` writes a raw glyph code, for the few characters drawn with an unusual width.
- `.dexCategoryLeftAligned` writes a left-aligned Pokédex category. This is used in French,
  German, Italian and Spanish; English keeps the right alignment.
- With a `.dexLang` language set, `.ereaderText` writes the 25-cell lines of the e-Reader
  screens, and `.ereaderDexText` writes a line with the character widths of the Pokédex font of
  that language; the lines use one or the other.

### Tools (`tools/eu_port`, Python 3 + pyelftools + capstone)

- `dump_dex_eu.py`, `dump_ereader_eu.py` and `dump_tables_eu.py` write the files of `data/src`
  from the ROM.
- `disasm_rom_tail.py` writes `data/rom_tail.s` from the ROM and checks it.
- `check.sh`, `cmp_eu.py`, `fdiff.py`, `nonmatching.sh`, `eudis.py`, `xref.py`, `langsw.py`,
  `romdiff.py` and `worddiff.py` compare functions and data with the ROM.
- `check_relocs.py` relinks the ROM keeping its relocations and checks that no ROM address is
  hard-coded in the code or in the data, so that code and data can move when the game is
  modified.
- `lcm_sim.py` simulates agbcc's partial redundancy elimination, to understand why a value is
  reloaded or reused.
- `CLAUDE.md` holds the detailed working notes, in Italian.

## Matching notes

Some functions needed more than translating the logic. The causes are useful for other agbcc
projects:

- **`UpdateSapphireHatchMachine`.** The banner setup sits inside a `do { } while (0)`. The loop
  end note closes the CSE extended block, which changes the code after it (macros
  `BANNER_SETUP_BEGIN/END`).
- **`LoadTitlescreenGraphics`.** The palette, button icon and options sprite copies are repeated
  at the end of both branches of the saved-game test. The compiler merges the identical tails
  (cross jumping), and the duplication changes the register allocation of the code after them.
  decomp-permuter found an equivalent fake match (an if/else with two identical branches),
  which pointed to this structure.
- **`RestoreMainFieldDynamicGraphics`.** The egg frame index is read into a variable before its
  DMA copy, like the other copies of the function. The ROULETTE_WHEEL case ends with an empty
  `do { } while (0)`, probably a macro that expands to nothing. Its loop note makes jump.c copy
  the `i++` and the exit test of the outer loop there; reload gives the copy a register before
  cross jumping removes it, and reload picks registers in rotation, so the next case gets the
  original ones. It was found with
  [decomp-permuter](https://github.com/simonlindholm/decomp-permuter).
- **`EndOfBallBonusSummary`** handles the language index, glyphs and tables of each language.
  **`Draw{Ruby,Sapphire}ModeTimerDisplay`** use a per-language size for one block of "saver"
  tiles.

## Remaining work

- Find what the empty loop in `RestoreMainFieldDynamicGraphics` was in the original source.
- Split the music of `data/sound_data.s` into one file per song, and the board data of
  `data/rom_1.s` into separate include files.

## Credits

The decompilation of the game started from the [pret/pokepinballrs](https://github.com/pret/pokepinballrs)
disassembly of the US release, and the build uses pret's
[agbcc](https://github.com/pret/agbcc) compiler. This repository adapts that work to the
European ROM and is developed independently.
