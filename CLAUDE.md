# Pokémon Pinball R/S — versione europea (BPPP)

Decompilazione della ROM europea multilingua (inglese, francese, tedesco, italiano, spagnolo) di
Pokémon Pinball: Ruby & Sapphire. Progetto indipendente: è partito dalla decompilazione
pret/pokepinballrs della versione USA (crediti nel README), ma contiene e costruisce solo la
versione europea. Non c'è più nessuna build USA né codice `#ifdef EUROPE`.

## Stato

- `make compare` ricostruisce la ROM EU **identica byte per byte**
  (SHA1 `b8b7881eaa9856b5ada99078ad1053d31cb79827`).
- Codice: 848/848 funzioni corrispondenti, tutte in C (nessuna usa l'assembly originale).
  Le ultime risolte: `EndOfBallBonusSummary` (indice lingua, glifi, tabelle),
  `Draw{Ruby,Sapphire}ModeTimerDisplay` (dimensione per lingua del 3° blocco di tile "saver"),
  `UpdateSapphireHatchMachine` (il setup del banner è in un `do { } while (0)`, che chiude il
  blocco CSE: macro `BANNER_SETUP_BEGIN/END`), `LoadTitlescreenGraphics` (le copie DMA comuni
  sono ripetute in entrambi i rami del test sul salvataggio e il compilatore le fonde: la
  ripetizione cambia l'allocazione dei registri), `RestoreMainFieldDynamicGraphics` (indice
  dell'uovo in `var0` prima della DMA; in fondo al caso ROULETTE_WHEEL un ciclo vuoto
  `do { } while (0)`, forse una macro vuota: per la sua nota di ciclo jump.c copia lì `i++` e il
  test del ciclo esterno, reload dà un registro alla copia prima che il cross-jump la tolga, e la
  rotazione dei registri di reload, `last_spill_reg` in reload1.c, arriva giusta al caso dopo).
  Le ultime due trovate con decomp-permuter (vedi sotto).
- Dati: tutti in forma sorgente, e si modificano a mano (non sono più generati: gli strumenti
  che li ricavavano dai sorgenti USA sono stati tolti con la build USA).
  - `data/rom_1.s`, `sound_data.s`, `sound_data_2.s`, `rom_2.s`, `rom_tail.s`: i dati in ordine
    di ROM. Includono `data/board_data/*.inc` (board; quelle di Ruby e Sapphire con le varianti
    per lingua), `data/graphics/*.inc` (liste di grafica di sprite e ritratti), `data/*.inc`
    (tabelle) e un file per canzone in `sound/songs/`.
  - nomi: i dati raggiunti dal codice hanno nomi veri; le 586 `gUnknown_<indirizzo EU>` rimaste
    sono dati che il codice non raggiunge (copie inutilizzate di dati sprite, un gruppo sprite
    inutilizzato delle board) e 4 segnaposto in RAM. I campi `unusedXX` delle strutture non sono
    mai letti dal codice.
  - `data/src/pokedex_entries.inc`: Pokédex (205 voci, 5 lingue) con `.dexLang`;
  - `data/src/bonus_summary_templates.inc`: testi del riepilogo bonus FR/IT/DE/ES;
  - `data/src/{high_score_tables,pause_menu_sprite_offsets,idle_press_start_tiles}.inc`:
    tabelle (scritte da `dump_tables_eu.py`);
  - `data/src/ereader_text*.inc`: testi dell'e-Reader in 5 lingue (`dump_ereader_eu.py`);
  - `data/src/orphaned_se_tracks.inc`: altre tracce orfane dopo `broken_se_6A36D4`;
  - le righe `@ eu_range INIZIO FINE` in testa ai `.inc` sono solo l'intervallo di ROM coperto.
  - grafica per lingua in `graphics/**/<file>_<lingua>.png/.pal/.bin` (suffisso minuscolo del
    gruppo di lingue, `_eu` se il simbolo non ha suffisso), più la grafica che esiste solo in EU
    (`graphics/language_select/`, testi intro, ordinali dei record, testi e-Reader, etichette del
    cartello del negozio Ruby, la lettera "!" dell'alfabeto del tabellone); regole speciali in
    `graphics_rules.mk`, `graphics_rules_eu.mk` e nei JSON gfx-config (i fogli sprite del
    Pokédex FR/DE/ES hanno segmenti propri in `graphics/pokedex/pokedex_gfx_eu.json`). Dopo una
    modifica alle regole cancellare i `.4bpp` generati: make non li ricostruisce se cambiano solo
    le opzioni.
  - copie non usate dal codice dei dati inglesi (frecce EVO/monete FR/IT/ES di Ruby e Sapphire)
    scritte con i file inglesi;
  - sprite set scritti con `packed_sprite_oam(l)`; tabelle con il tipo degli elementi della
    dichiarazione C (`.byte`/`.2byte`/`.4byte`). Nessun blob binario né righe `.byte` anonime.
  - le copie per lingua dei dati sprite non usati (mai referenziate dal codice) sono sprite set
    seguiti da animazioni: contatore e coppie (fotogramma, durata).
  - puntatori simbolici; le etichette senza nome noto sono `gUnknown_<indirizzo>` o
    `<nome>_<Lingua>`.
  La coda della ROM (0x08FE0000, 16 KB, mai referenziata) è disassemblata in `data/rom_tail.s`
  da `disasm_rom_tail.py`: un debug monitor per l'hardware di sviluppo, collegato per girare
  dalla memoria di una DACS da 1 Mbit (0x09FE0000). 0x09FE2000 è il gestore di debug del BIOS
  (FIQ e istruzione non definita, se i bit 2 e 7 del byte 0x9C dell'header sono attivi); il
  monitor salva lo stato del gioco ed esegue i comandi che l'host scrive in `MonCommandBlock`
  (memoria, passo singolo con un breakpoint fatto di un'istruzione non definita, ripresa, reset,
  flash, riempimento, chiamate al gioco). Parte residente (primi 4 KB) a 0x09FE2000 e tre overlay
  (le pagine da 4 KB successive) tutti a 0x09FE3000, scelti dal registro di controllo a
  0x09FE2FFE; ognuno inizia con una tabella di punti d'ingresso e i suoi puntatori 0x09FE3xxx
  puntano all'overlay stesso.

## Build

Toolchain come da INSTALL.md (agbcc in `tools/agbcc`, binutils arm-none-eabi, `jq`).

    make compare -j8

La build non richiede la ROM originale. Gli strumenti di analisi sì: copiare la ROM EU in
`baserom_eu.gba` nella radice del repo (ignorata da git) o impostare `BASEROM_EU`.
Su Windows (MSYS2) usare il `jq` di msys, non quello mingw (scrive CRLF e rompe
`graphics_rules_generated.mk`), e Python in modalità UTF-8 (`python -X utf8`).

## Build nativa Windows (`pc/`, `make pc`)

`pokepinballrs_pc.exe`: il codice C e i dati del gioco compilati per Win32 a 32 bit (toolchain
MSYS2 `mingw-w64-i686-gcc`, in `/mingw32/bin`), senza emulatore. Dettagli nel README
("Native Windows build"). Punti da sapere:

- 32 bit perché i puntatori siano da 4 byte: i `.s` dei dati (passati da `pc/arm2x86.sed`:
  `.word` → `.4byte`, `.align` → `.p2align`, commenti `@`) hanno la disposizione delle struct C.
  `data/rom_tail.s` è escluso. Lato gioco `-fno-leading-underscore` (stessi nomi dell'assembly);
  `pc/win32.c` è compilato normalmente e i simboli di confine hanno etichette asm (`HOST_SYM`).
- agbcc arrotonda **ogni struct/union** a multipli di 4 con allineamento 4: `pc/struct_align.pl`
  aggiunge `aligned(4)` dopo il preprocessore (senza, 61 differenze, es. `struct Main` 19164 contro
  14564). Verificato confrontando sizeof/alignof/offsetof di tutte le struct degli header.
- Memoria GBA agli indirizzi GBA: prima sezione dell'immagine `.gbamem` (0x01FF1000-0x0E010000,
  script `build/pc/pc.ld` derivato da quello di default di ld; le sezioni PE non possono avere
  buchi, e `VirtualAlloc` a 0x02000000 fallisce perché user32/gdi32 mappano lì). Indirizzi delle
  variabili RAM presi dall'ELF GBA (`build/pc/ram_syms.ld`), quindi `make pc` costruisce prima la ROM.
- Divisione per zero: gestore di eccezioni che dà 0 come `__divsi3` (succede in `SetMatrixScale`).
- `#ifdef PLATFORM_PC` nel codice del gioco: `DmaSet` (macro.h), `EWRAM_DATA`/`IWRAM_DATA`,
  `SetSramFastFunc`, `swi 0x2A` e attese su `REG_VCOUNT` in m4a.c. La ROM resta identica.
- Test automatici: variabili `PINBALL_INPUT` (es. `320:A,325:,700:START`), `PINBALL_CMD` (es.
  `30:train-0-255,600:save,900:vk-27`), `PINBALL_DUMP`, `PINBALL_DUMP_FRAMES`, `PINBALL_SET`,
  `PINBALL_DIR` (per non toccare il salvataggio vero), `PINBALL_HIDDEN`, `PINBALL_SYNC`,
  `PINBALL_TRACE`, `PINBALL_VERIFY`, `PINBALL_EXIT_FRAME`, `PINBALL_TURBO`, `PINBALL_NOAUDIO`,
  `PINBALL_WAV` e altre (elenco in cima a `pc/win32.c`). Il crash handler dà l'indirizzo:
  `addr2line -e pokepinballrs_pc.exe` (con `/mingw32/bin` nel PATH).
- Non supportati: cavo link, e-Reader.
- Thread: gioco (`AgbMain`), display (`pc/video.c`, D3D11 con GDI di riserva, più worker per il
  renderer), finestra. `pc/ppu.c` disegna da una copia del frame (`struct PpuFrame`, `pc/frame.h`:
  VRAM, palette, OAM, registri per linea), quindi può ridisegnarlo. A scala 1 e senza
  interpolazione l'immagine è identica a quella di prima (confronto frame per frame).
- Lato gioco delle aggiunte: `pc/hooks.c`, chiamato dal codice del gioco sotto `#ifdef PLATFORM_PC`
  (ciclo principale, `ReadKeys`, telecamera, `PlayRumble`, ball save, palline, Pokédex, i fix).
  Lato Windows: `input.c`, `settings.c`, `state.c`, `replay.c`, `stats.c`, `online.c`, `ui.c`,
  `ui_art.c`.
- Partenza canonica: quando una partita sta per iniziare, `PcHook_LoopTop` prende `struct RunHeader`
  e il programma riparte come da accensione entrando direttamente nella partita. Replay =
  intestazione + tasti di ogni `ReadKeys`; a fine partita si confronta un hash. Determinismo provato
  con tavolo intero, interpolazione e latenza ridotta accesi e spenti.
- Tavolo intero: `RunCameraPasses` salva lo stato, riesegue il frame con la telecamera forzata
  (`PcHook_CameraPass`) e tiene solo l'immagine. Sapphire ha il limite della telecamera a Y = -4 e
  `bgOffsets` è senza segno: la tavola parte da 0.
- Stati salvati: solo in cima al ciclo principale (lo stack è vuoto); valgono solo per la build che
  li ha fatti perché contengono puntatori. Pokédex e record non tornano indietro al caricamento.
- Dipendenze: `make` vede ora anche `pc/*.h` dai sorgenti del gioco (scaninc con `-I pc`); prima
  una modifica a `host.h` non ricompilava `src/`, e i flag dei fix restavano vecchi.
- Menu e pannelli sono disegnati con la grafica del gioco (cornice e sprite delle Opzioni, font del
  Pokédex) su una tela da 240x160: `PINBALL_UI_CHECK=1` segnala i testi che non ci stanno. Il font
  non ha `%`, `+`, `>`, `Ù`.
- I glifi accentati del font del Pokédex stanno oltre la fine di `text_glyphs_eu.4bpp`, nei dati
  che seguono (`gHighScoreScoreTable_Tilemap`): si leggono dalla ROM, non dal file.

## Convenzioni nel codice

- Lingua corrente: `gMain_saveData.language` (gMain+0x141). EN 0, FR 1, DE 2, IT 3, ES 4, 99 = non impostata.
- Macro in `include/global.h`: `LANG5_SWITCH`, `DMA_LANG5`, `DMA_LANG5_AT`, `EXTERN_LANG5`,
  `DMA_LANG4_ENFR`, `LANG4_SWITCH_ENDE`, ecc. Simboli per lingua con suffissi
  `_En/_Fr/_De/_It/_Es` o gruppi (`_EnFr`, `_EnDe`, `_EnDeItEs`, …).
- I raggruppamenti di lingue cambiano da asset ad asset: copiare quello della ROM.
- Alcune tabelle sono indicizzate in un altro ordine (es. testi del riepilogo bonus: En, Fr, It, De, Es).
- `struct PokemonSpecies.name` è `[3][10]` (EN, FR, DE), vedi `src/data/species.h` (`SPECIES_NAME`).
- RAM: `sym_ewram.txt`, `sym_bss.txt`, `sym_common.txt`.

## Testi del Pokédex (tools/preproc)

- `.dexLang EN|FR|DE|IT|ES` sceglie la codifica europea dei glifi (US = quella originale, default);
  le tabelle sono in `ApplyEuropeanDexEncoding` (asm_file.cpp): glifi accentati, ß, „ « », `œ`
  (2 glifi), larghezze diverse di k, z, 1, `, é, “ a seconda della lingua.
- `{XXXX}` nelle stringhe dex scrive un codice glifo grezzo (8 casi in tutto il Pokédex).
- `.dexCategoryLeftAligned`: categoria allineata a sinistra (FR/DE/IT/ES; in EN è a destra).
- Testi e-Reader: con una lingua `.dexLang` attiva `.ereaderText` scrive righe di 25 celle
  (`EREADER_LINE_LENGTH`; 24 senza lingua) con larghezze fisse e i glifi europei;
  `.ereaderDexText` usa le larghezze del Pokédex della lingua. Le righe usano l'una o l'altra
  (il gioco ignora la larghezza); 8 caratteri sono `{XXXX}`.

## Strumenti (`tools/eu_port/`, Python 3 + pyelftools + capstone)

- `check.sh [oggetto]`: compila gli oggetti, confronta con la ROM per funzione, poi `make compare`.
- `cmp_eu.py`: confronto per funzione degli oggetti con la ROM (usa `data/obj_starts.json`,
  scrive `data/cmp_report.json`).
- `fdiff.py src/X.o Funzione 0xADDR [SIZE]`: diff istruzione per istruzione di una funzione.
- `nonmatching.sh FILE.c`: compila con `-DNONMATCHING` in `build/nm/src/FILE.o`
  (poi `fdiff.py ../nm/src/FILE.o Funzione 0xADDR SIZE`).
- `lcm_sim.py`: simula la PRE/LCM di agbcc su un dump `-dG` per capire perché un'espressione
  (es. l'indirizzo di un globale) viene ricaricata o riusata.
- `eudis.py ADDR SIZE`, `langsw.py ADDR SIZE`, `xref.py ADDR`: disassembly, tabelle switch per
  lingua, riferimenti (usano `data/eu_names.json`, `data/eu_entries.json`).
- `romdiff.py`, `worddiff.py`: dove differisce la ROM costruita e di quanto sono spostati i puntatori.
- `check_relocs.py` (dopo `make`): ricollega gli oggetti con `ld -q` e cerca indirizzi ROM fissi
  senza rilocazione: nei literal pool del codice (zone `$d`) qualsiasi indirizzo ROM, nei dati
  solo valori che sono l'inizio di un simbolo, saltando i dati `.incbin`, il valore 0x08000000 e
  la coda della ROM. Oggi: 0 trovati su 53.117 rilocazioni.
- `dump_dex_eu.py`, `dump_ereader_eu.py`, `dump_tables_eu.py`: riscrivono dalla ROM il Pokédex,
  i testi e-Reader e le tabelle in `data/src/`.
- `disasm_rom_tail.py`: riscrive `data/rom_tail.s` (discesa ricorsiva ARM/Thumb con capstone;
  nomi e commenti da `NAMES` e `COMMENTS`, riferimenti dentro i dati di `DATA_REGIONS` come
  `nome + offset`, le altre etichette col nome dell'indirizzo di esecuzione; indirizzi come
  `label - RES/OV1/OV2/OV3`) e lo verifica riassemblandolo come il Makefile (preproc, cpp, as);
  un'istruzione che as codifica diversamente diventerebbe `.inst` (oggi nessuna). Il codice non
  raggiunto è in `EXTRA_CODE`; `-l INIZIO FINE` stampa la classificazione. Richiede binutils e
  cpp arm-none-eabi nel PATH.

## Prossimi passi possibili

1. Sostituire i trucchi di matching rimasti (elenco nel README, "Remaining work"): `+= 0` in
   `DuskullPhase_ProcessEntityLogic`, `UpdateGroudonFieldEntities`, `UpdateSphealResultsScreen`;
   i punti marcati in `LoadPortraitGraphics`, `InitFrameProcess0_DefaultSpriteState_RubyBoard`,
   `UpdateOptionsSpritePositions`, `CheckGameBoyPlayer`, `DisableGbPlayerRumble`; il ciclo vuoto
   di `RestoreMainFieldDynamicGraphics`. Tolti, tutti cambiano il codice (misurato). Con il
   permuter (25 minuti, `-j10`): `LoadPortraitGraphics` resta a 20 (la forma `ptr[...]` al posto
   di `ptr2 = ptr`; `*(ptr2 += ...)` lascia 2 righe diverse), il caso di Ruby scende da 1020 a 390.
   Risolti così `CheckCatchTargetCollision` e `RenderTitlePressStartSprites` (vedi README).
   decomp-permuter (github.com/simonlindholm/decomp-permuter): una cartella per funzione con
   `base.c` e `target.o` che contengono **solo** quella funzione (il permuter confronta l'intero
   oggetto: usare `strip_other_fns.py` del permuter su tutti e due; `target.o` si ottiene
   compilando il sorgente attuale, che corrisponde alla ROM), sorgente preprocessato con
   `cpp -P` (senza direttive di riga), `compile.sh` con i flag di agbcc della build, `-j` e
   `PERM_RANDOMIZE` solo sulla zona interessata (su tutta la funzione non trovava niente, sul
   solo ciclo dei ritratti ha trovato il ciclo vuoto). I suoi match vanno riletti per trovare il
   costrutto naturale equivalente.
