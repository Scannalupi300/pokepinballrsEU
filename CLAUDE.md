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
    di ROM. Le canzoni e i dati delle board sono scritti per esteso dentro questi file.
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

1. Capire che cosa era nel sorgente originale il ciclo vuoto di `RestoreMainFieldDynamicGraphics`.
   decomp-permuter (github.com/simonlindholm/decomp-permuter) si usa con una cartella per
   funzione: `base.c` preprocessato (con `-DNONMATCHING` se serve), `target.o` assemblato dal
   codice originale della funzione (etichette locali `.L`, padding come `.align 2, 0`),
   `compile.sh` con i flag di agbcc della build. Conviene randomizzare solo la zona interessata
   (`PERM_RANDOMIZE`): su tutta la funzione non trovava niente, sul solo ciclo dei ritratti ha
   trovato il ciclo vuoto. I suoi match vanno poi riletti per trovare il costrutto naturale
   equivalente.
2. Dividere la musica di `data/sound_data.s` in un file per canzone e i dati delle board di
   `data/rom_1.s` in file da includere.
