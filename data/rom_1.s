.section .rodata
.align 2

#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "constants/bg_music.h"
#include "gba/io_reg.h"
#include "gba/oam_types.h"
	.include "asm/macros.inc"

gAreaRouletteTable:: @ 0x0805CAC4
	.2byte AREA_FOREST_RUBY
	.2byte AREA_VOLCANO
	.2byte AREA_PLAINS_RUBY
	.2byte AREA_OCEAN_RUBY
	.2byte AREA_SAFARI_ZONE
	.2byte AREA_CAVE_RUBY
	.2byte AREA_RUIN_RUBY
	.2byte AREA_FOREST_SAPPHIRE
	.2byte AREA_LAKE
	.2byte AREA_PLAINS_SAPPHIRE
	.2byte AREA_WILDERNESS
	.2byte AREA_OCEAN_SAPPHIRE
	.2byte AREA_CAVE_SAPPHIRE
	.2byte AREA_RUIN_SAPPHIRE

.include "data/mon_locations.inc"

.include "data/sine_table.inc"

.include "data/graphics/empty_oam_data_block.inc"

gGbPlayerPalettes:: @ 0x0805F0A4
	@ This one is weird because some of the colors set the unused bit, so we can't do a matching conversion
	@ from a JASC palette format. Naming it with a ".bin" suffix to prevent `make clean` from deleting it.
	.incbin "graphics/gb_player/gb_player.gbapal.bin"

gGbPlayerGfx:: @ 0x0805F2A4
	.incbin "graphics/gb_player/gb_player.8bpp"

gGbPlayerTilemap:: @ 0x080632A4
	.incbin "graphics/gb_player/gb_player_tilemap.bin"

Sio32ConnectionData:: @ 0x080637A4
	.ascii "NINTENDO"

gBonusFieldSelectStateFuncs:: @ 0x080637AC
	.4byte LoadBonusFieldSelectGraphics
	.4byte BonusFieldSelect_Menu
	.4byte BonusFieldSelect_FadeToSelection

gEReaderStateFuncs:: @ 0x080637B8
	.4byte LoadEReaderGraphics
	.4byte Ereader_ShowInstructions
	.4byte Ereader_AnimateLinkCable
	.4byte Ereader_Communicating
	.4byte Ereader_ShowLinkTimeout
	.4byte Ereader_CloseSuccessfulTransmission
	.4byte Ereader_ShowSuccessPopup
	.4byte Ereader_ShowPrizeText
	.4byte Ereader_FadeScreenToMenu

gDexInfoWindowMiddleRowTiles:: @ 0x080637DC
	.2byte 0x00, 0x9A, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x9B, 0x00, 0x00, 0x00

gDexInfoWindowBottomRowTiles:: @ 0x0806381C
	.2byte 0x00, 0x5A, 0x5B, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x5C, 0x9C, 0x00, 0x00, 0x00

gDexInfoWindowEmptyRowTiles:: @ 0x0806385C
	.2byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.2byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.2byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.2byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

gDexInfoWindowEmptyTextRowTiles:: @ 0x0806389C
	.2byte 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
	.2byte 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
	.2byte 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
	.2byte 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F

gPokedexStateFuncs:: @ 0x080638DC
	.4byte LoadPokedexGraphics          @ POKEDEX_STATE_LOAD_GRAPHICS
	.4byte Pokedex_HandleListInput      @ POKEDEX_STATE_HANDLE_LIST_INPUT
	.4byte Pokedex_PostScrollRefresh          @ POKEDEX_STATE_2
	.4byte Pokedex_InfoWindowSlideIn          @ POKEDEX_STATE_3
	.4byte Pokedex_InfoWindowSlideOut          @ POKEDEX_STATE_4
	.4byte Pokedex_DetailViewInput          @ POKEDEX_STATE_5
	.4byte Pokedex_LinkSetup            @ POKEDEX_STATE_LINK_SETUP
	.4byte Pokedex_LinkTransferLoop          @ POKEDEX_STATE_7
	.4byte Pokedex_LinkErrorTimeout          @ POKEDEX_STATE_8
	.4byte Pokedex_LinkSuccessSequence          @ POKEDEX_STATE_9
	.4byte Pokedex_LinkRetryDelay         @ POKEDEX_STATE_10
	.4byte Pokedex_DeleteConfirmation         @ POKEDEX_STATE_DELETE_CONFIRMATION
	.4byte Pokedex_ReturnToTitle        @ POKEDEX_STATE_RETURN_TO_TITLE















































































































































































































gPokedexEntries:: @ 0x08063910
	.include "data/src/pokedex_entries.inc"
gLanguageSelectStateFuncs:: @ 0x080EC4CC
	.4byte LanguageSelect_LoadGraphics
	.4byte LanguageSelect_HandleInput
	.4byte LanguageSelect_BlinkSelection
	.4byte LanguageSelect_Exit
gFieldSelectStateFuncs:: @ 0x080EC4DC
	.4byte LoadFieldSelectGraphics
	.4byte FieldSelect_State1_8C7C
	.4byte FieldSelect_State2_8F64

gIntroStateFuncs:: @ 0x080EC4E8
	.4byte Intro_State0_929C
	.4byte Intro_State1_9348
	.4byte Intro_State2_9370
	.4byte Intro_State3_938C
	.4byte Intro_State4_93D0

gIntroSceneFuncs:: @ 0x080EC4FC
	.4byte IntroScene1_00_LoadTitleLettersAndTorchicScene
	.4byte IntroScene1TitleText_01_TitleLetterBounceReveal
	.4byte IntroScene1TitleText_02_TitleRecedeToBackground
	.4byte IntroScene1TitleText_03_1PxText
	.4byte IntroScene1Torchic_04_LargeSparkle
	.4byte IntroScene1Torchic_05_SpeedLineFadeIn
	.4byte IntroScene1Torchic_06_BrightenPokeballFlyTowardsScreen
	.4byte IntroScene1Torchic_07_TorchicRiseAndBGSplit
	.4byte nullsub_4
	.4byte IntroScene1Torchic_09_OrangeTextScrolls
	.4byte nullsub_5 @ 10
	.4byte nullsub_17
	.4byte IntroScene1Torchic_12_FlashWhite
	.4byte IntroScene1Torchic_13_ResetTilemap

	.4byte IntroScene2Pikas_14_LoadPinkYellowBackground
	.4byte nullsub_6
	.4byte IntroScene2Pikas_16_PikaPairRising
	.4byte nullsub_7
	.4byte IntroScene2Pikas_18_FlashWhite
	.4byte IntroScene2Pikas_19_ResetTilemap

	.4byte IntroScene3Treecko_20_LoadTreeckoFlipperBall @ 20
	.4byte IntroScene3Treecko_21_MoveTreeckoFlipperBallAndSplit
	.4byte IntroScene3Treecko_22_FlipperHitTextScroll
	.4byte nullsub_8
	.4byte IntroScene3Treecko_24_FlashWhite
	.4byte IntroScene3Treecko_25_ResetTilemap

	.4byte IntroScene4PlusleMinun_26_LoadTealWhiteBackground
	.4byte nullsub_9
	.4byte IntroScene4PlusleMinun_28_PlusleMinunTextScroll
	.4byte nullsub_10
	.4byte IntroScene4PlusleMinun_30_FlashWhite @ 30
	.4byte IntroScene4PlusleMinun_31_ResetTilemap

	.4byte IntroScene5Mudkip_32_LoadMudkipBallScene
	.4byte IntroScene5Mudkip_33_MoveMudkipBallSplit
	.4byte IntroScene5Mudkip_34_MoveMudkipBallTextScroll
	.4byte nullsub_11
	.4byte IntroScene5Mudkip_36_FlashWhite
	.4byte IntroScene5Mudkip_37_ResetTilemap

	.4byte IntroScene6Chinchou_38_LoadChinchou
	.4byte IntroScene6Chinchou_39_MoveChinchouBallAndStars
	.4byte IntroScene6Chinchou_40_MoveChinchouAndStars @ 40
	.4byte IntroScene6Chinchou_41_FlashWhiteClearSprites
	.4byte IntroScene6Chinchou_42_FrameAdvance

	.4byte IntroScene7Parade_43_LoadPinkYellowBackground
	.4byte IntroScene7Parade_44_MoveMakuhita
	.4byte IntroScene7Parade_45_MoveMakuhitaAndSpoink
	.4byte IntroScene7Parade_46_MoveMakuhitaPelipperAndSpoink
	.4byte IntroScene7Parade_47_MoveMakuhitaPelipperWailmerAndSpoink
	.4byte IntroScene7Parade_48_MoveWailmerShake
	.4byte IntroScene7Parade_49_FlashWhite
	.4byte IntroScene7Parade_50_ResetTilemap @ 50

	.4byte IntroScene8WailmerLaunch_51_LoadWailmerBlastBackground
	.4byte IntroScene8WailmerLaunch_52_BallAppearTimer
	.4byte IntroScene8WailmerLaunch_53_MoveBallStarsAndWailmer
	.4byte IntroScene8WailmerLaunch_54_MoveStarsAndWailmer
	.4byte nullsub_12
	.4byte nullsub_13
	.4byte IntroScene8WailmerLaunch_57_FlashWhiteClearSprites
	.4byte IntroScene8WailmerLaunch_58_ResetTilemap

	.4byte IntroScene9BallFlight_59_LoadSkySpeedOrbs
	.4byte IntroScene9BallFlight_60_MoveBallAndSky @ 60
	.4byte IntroScene9BallFlight_61_MoveSky
	.4byte IntroScene9BallFlight_62_MoveBallSkyFadeWhite
	.4byte nullsub_14
	.4byte IntroSceneX_64_HoldWhitescreen
	.4byte IntroSceneX_64_EndIntro

gHighScoresStateFuncs:: @ 0x080EC604
	.4byte LoadHighScoreGraphics
	.4byte HighScore_ShowCompletionBanner
	.4byte HighScore_FlashNewEntry
	.4byte HighScore_BrowseScores
	.4byte HighScore_NameEntry
	.4byte HighScore_InitLinkExchange
	.4byte HighScore_LinkExchangeLoop
	.4byte HighScore_LinkError
	.4byte HighScore_LinkSuccess
	.4byte HighScore_LinkRetryWait
	.4byte HighScore_ResetConfirmation
	.4byte HighScore_ExitToTitle
	.4byte HighScore_ReloadAfterLink
	.4byte HighScore_ShowMergedScores
	.4byte HighScore_ReturnToMain

gIdleHighScoresStateFuncs:: @ 0x080EC640
	.4byte IdleHighScore_LoadGraphics
	.4byte IdleHighScore_AutoScroll
	.4byte IdleHighScore_Exit

	@ 4 'name' blocks followed by 2 score high/low







gDefaultHighScores:: @ 0x080EC64C
	.include "data/src/high_score_tables.inc"
gHighScoreNameRowTilemapOffsets:: @ 0x080EC90C
	.4byte 0x02, 0x05, 0x07, 0x09, 0x0B, 0x0D, 0x0F, 0x11

gTitlescreenStateFuncs:: @ 0x080EC92C
	.4byte LoadTitlescreenGraphics                @ SUBSTATE_LOAD_GRAPHICS
	.4byte TitleScreen1_WaitForStartButton        @ SUBSTATE_WAIT_FOR_START_BUTTON
	.4byte TitleScreen2_AnimatePressStartSelected @ SUBSTATE_ANIM_PRESS_START_SELECTED
	.4byte TitleScreen3_AnimateMenuSlideIn        @ SUBSTATE_ANIM_MENU_SLIDE_IN
	.4byte TitleScreen4_MenuInputNoSavedGame      @ SUBSTATE_MENU_INPUT_NO_SAVED_GAME
	.4byte TitleScreen5_MenuInputSavedGame        @ SUBSTATE_MENU_INPUT_SAVED_GAME
	.4byte TitleScreen6_AnimCloseMenu             @ SUBSTATE_ANIM_CLOSE_MENU
	.4byte TitleScreen7_ProcessMenuItemSelected_NoSavedGame @ SUBSTATE_MENU_ITEM_SELECTED_NO_SAVED_GAME
	.4byte TitleScreen8_ProcessMenuItemSelected_SavedGame   @ SUBSTATE_MENU_ITEM_SELECTED_SAVED_GAME
	.4byte TitleScreen9_DeleteSaveConfirmation              @ SUBSTATE_DELETE_SAVE_GAME_CONFIRMATION
	.4byte TitleScreen10_ExecMenuSelection        @ SUBSTATE_EXEC_MENU_SELECTION
	.4byte TitleScreen11_FadeToAction             @ SUBSTATE_FADE_TO_MENU_ACTION

gIntroCopyright_Tilemap:: @ 0x080EC95C
	.incbin "graphics/intro/copyright_tilemap.bin"

gIntroCopyright_Gfx:: @ 0x080ED15C
    .incbin "graphics/intro/copyright.4bpp"
	.space 0x20

gIntroCopyright_Pal:: @ 0x080ED97C
    .incbin "graphics/intro/copyright.gbapal"

gBonusFieldSelectBg0_Tilemap:: @ 0x080EDB7C
	.incbin "graphics/field_select/bonus_field_select_bg0_tilemap.bin"


gBonusFieldSelectBg1_Tilemap_En:: @ 0x080EE37C
	.incbin "graphics/field_select/bonus_field_select_bg1_tilemap_en.bin"
gBonusFieldSelectBg1_Tilemap_FrDeItEs:: @ 0x080EEB7C
	.incbin "graphics/field_select/bonus_field_select_bg1_tilemap_frdeites.bin"
gBonusFieldSelectBg2_Tilemap:: @ 0x080EF37C
	.incbin "graphics/field_select/bonus_field_select_bg2_tilemap.bin"

gBonusFieldSelectStages_Pals:: @ 0x080EFB7C
	.incbin "graphics/field_select/bonus_field_select_stages.gbapal"

gBonusFieldSelectStages_Gfx:: @ 0x080EFD7C
	.incbin "graphics/field_select/bonus_field_select_stages.4bpp"
	.space 0x20


gEReaderText_Tilemap:: @ 0x080F159C
	.incbin "graphics/ereader/ereader_text_tilemap_eu.bin"
gEReaderOverlay_Tilemap:: @ 0x080F359C
	.incbin "graphics/ereader/ereader_overlay_tilemap.bin"


gEReaderBackground_Gfx:: @ 0x080F3D9C
	.incbin "graphics/ereader/background_eu.4bpp"
gEReaderBackgroundText_Gfx_Fr:: @ 0x080F559C
	.incbin "graphics/ereader/background_text_fr.4bpp"
gEReaderBackgroundText_Gfx_It:: @ 0x080F5D9C
	.incbin "graphics/ereader/background_text_it.4bpp"
gEReaderBackgroundText_Gfx_De:: @ 0x080F659C
	.incbin "graphics/ereader/background_text_de.4bpp"
gEReaderBackgroundText_Gfx_Es:: @ 0x080F6D9C
	.incbin "graphics/ereader/background_text_es.4bpp"
gEReaderBackground_Pals:: @ 0x080F75BC
	.incbin "graphics/ereader/background.gbapal"

gPokedexBg1_Tilemap_En:: @ 0x080F77BC
gPokedexBg1_Tilemap:: @ 0x080F77BC
	.incbin "graphics/pokedex/bg1_tilemap.bin"

gPokedexBgText_Gfx_En:: @ 0x080F7FBC
gPokedexBgText_Gfx:: @ 0x080F7FBC
	.incbin "graphics/pokedex/bg_text.4bpp"
	.space 0x20

@ 32x32 u16 tilemap (0x800 bytes) for the pokedex info window that slides
@ in over the dex entry view. Copied to BG1's screenblock 0 tilemap at
@ row 10 (VRAM 0x6000280) by Pokedex_InfoWindowSlideIn (src/pokedex.c).
@ Only the first 7 rows (2*0xE0 bytes) are DMA'd; rows 0-5 hold the
@ window content and the rest is 0x001F filler (tile 31, blank).
@ The window is a 26x6 chunk of tile indices 224..409, i.e. sheet rows
@ 7..12, cols 0..25 of the 32 wide gPokedexBgText_Gfx tileset
@ (graphics/pokedex/bg_text.png), with palette bank 1 (0x1000 attr bit).
@
@ Note: this area of the raw bg_text.png starts blank. The text from the dex
@ entry is drawn to it, in memory, (PrintDexDescription function) before
@ this tilemap definition draws that text to screen from the background tiles.

gPokedexBg1_Tilemap_De:: @ 0x080FC3DC
	.incbin "graphics/pokedex/bg1_tilemap_de.bin"
gPokedexBgText_Gfx_De:: @ 0x080FCBDC
	.incbin "graphics/pokedex/bg_text_de.4bpp"
	.space 0x20
gPokedexBg1_Tilemap_Fr:: @ 0x08100FFC
	.incbin "graphics/pokedex/bg1_tilemap_fr.bin"
gPokedexBgText_Gfx_Fr:: @ 0x081017FC
	.incbin "graphics/pokedex/bg_text_fr.4bpp"
	.space 0x20
gPokedexBg1_Tilemap_It:: @ 0x08105C1C
	.incbin "graphics/pokedex/bg1_tilemap_it.bin"
gPokedexBgText_Gfx_It:: @ 0x0810641C
	.incbin "graphics/pokedex/bg_text_it.4bpp"
	.space 0x20
gPokedexBg1_Tilemap_Es:: @ 0x0810A83C
	.incbin "graphics/pokedex/bg1_tilemap_es.bin"
gPokedexBgText_Gfx_Es:: @ 0x0810B03C
	.incbin "graphics/pokedex/bg_text_es.4bpp"
	.space 0x20
gPokedexInfoWindowTilemap:: @ 0x0810F45C
	.incbin "graphics/pokedex/info_window_tilemap_eu.bin"
gPokedexBg2_Tilemap:: @ 0x0810FC5C
	.incbin "graphics/pokedex/bg2_tilemap.bin"


gPokedexBg_Gfx_En:: @ 0x0811045C
	.incbin "graphics/pokedex/bg_en.4bpp"
	.space 0x20
gPokedexBg_Gfx_FrDeItEs:: @ 0x0811187C
	.incbin "graphics/pokedex/bg_frdeites.4bpp"
	.space 0x20
gPokedexBg3_Tilemap_En:: @ 0x08112C9C
gPokedexBg3_Tilemap:: @ 0x08112C9C
	.incbin "graphics/pokedex/bg3_tilemap.bin"

gPokedexBg3_Tilemap_FrDeItEs:: @ 0x0811349C
	.incbin "graphics/pokedex/bg3_tilemap_frdeites.bin"
gPokedexBackground_Pals:: @ 0x08113C9C
	.incbin "graphics/pokedex/bg.gbapal"

gPokedexSprites_Pals:: @ 0x08113E9C
	.incbin "graphics/pokedex/sprites.gbapal"

gPokedexSprites_Gfx_En:: @ 0x0811409C
gPokedexSprites_Gfx:: @ 0x0811409C
	.incbin "graphics/pokedex/sprites.4bpp"
	.space 0x20




gPokedexSprites_Gfx_De:: @ 0x0811ACBC
	.incbin "graphics/pokedex/sprites_de.4bpp"
	.space 0x20
gPokedexSprites_Gfx_Fr:: @ 0x08121CDC
	.incbin "graphics/pokedex/sprites_fr.4bpp"
	.space 0x20
gPokedexSprites_Gfx_It:: @ 0x081290FC
	.incbin "graphics/pokedex/sprites_it.4bpp"
	.space 0x20
gPokedexSprites_Gfx_Es:: @ 0x0812FD1C
	.incbin "graphics/pokedex/sprites_es.4bpp"
	.space 0x20
gPokedexTextGlyphs_Gfx:: @ 0x08136D3C
	.incbin "graphics/pokedex/text_glyphs_eu.4bpp"
gHighScoreScoreTable_Tilemap::
	.incbin "graphics/high_score/high_score_table_text_tilemap_eu.bin"
gHighScoreScoreTable_Tilemap_En:: @ 0x0813BD5C
	.incbin "graphics/high_score/high_score_table_text_tilemap_en.bin"
gHighScoreText_Gfx:: @ 0x0813CD5C
	.incbin "graphics/high_score/text_eu.4bpp"
	.space 0x20
gHighScoreScoreTable_Tilemap_De:: @ 0x0814457C
	.incbin "graphics/high_score/high_score_table_text_tilemap_de.bin"
gHighScoreScoreTable_Tilemap_Fr:: @ 0x0814557C
	.incbin "graphics/high_score/high_score_table_text_tilemap_fr.bin"
gHighScoreScoreTable_Tilemap_It:: @ 0x0814657C
	.incbin "graphics/high_score/high_score_table_text_tilemap_it.bin"
gHighScoreScoreTable_Tilemap_Es:: @ 0x0814757C
	.incbin "graphics/high_score/high_score_table_text_tilemap_es.bin"
gHighScoreBallWatermark_Tilemap:: @ 0x0814857C
	.incbin "graphics/high_score/high_score_ball_watermark_tilemap.bin"

gHighScoreBallWatermark_Gfx:: @ 0x0814957C
	.incbin "graphics/high_score/ball_watermark_tiles.4bpp"
	.space 0x20


gHighScoreBG_Pals:: @ 0x0814C19C
	.incbin "graphics/high_score/bg_eu.gbapal"
gHighScoreSprite_Pals:: @ 0x0814C39C
	.incbin "graphics/high_score/sprites.gbapal"

gHighScoreDialogs_Gfx_En:: @ 0x0814C59C
gHighScoreDialogs_Gfx:: @ 0x0814C59C
	@ sheet includes transmission windows, and the
	@ pokedex completion certificate, with latios/latias
	.incbin "graphics/high_score/dialogs.4bpp"
	.space 0x20

gHighScoreDialogs_Gfx_De:: @ 0x081509BC
	.incbin "graphics/high_score/dialogs_de.4bpp"
	.space 0x20
gHighScoreDialogs_Gfx_Fr:: @ 0x08154DDC
	.incbin "graphics/high_score/dialogs_fr.4bpp"
	.space 0x20
gHighScoreDialogs_Gfx_It:: @ 0x081591FC
	.incbin "graphics/high_score/dialogs_it.4bpp"
	.space 0x20
gHighScoreDialogs_Gfx_Es:: @ 0x0815D61C
	.incbin "graphics/high_score/dialogs_es.4bpp"
	.space 0x20
gHighScoreTitle_Gfx_Fr:: @ 0x08161A3C
	.incbin "graphics/high_score/rank_numbers_frdeites.4bpp"
	.global gHighScoreTitle_Gfx_It
	.set gHighScoreTitle_Gfx_It, gHighScoreTitle_Gfx_Fr + 0x160
	.global gHighScoreTitle_Gfx_De
	.set gHighScoreTitle_Gfx_De, gHighScoreTitle_Gfx_Fr + 0x1000
	.global gHighScoreTitle_Gfx_Es
	.set gHighScoreTitle_Gfx_Es, gHighScoreTitle_Gfx_Fr + 0x1160
gFieldSelectBG0Tilemap:: @ 0x08163A5C
	.incbin "graphics/field_select/field_select_bg_tilemap.bin"



.include "data/graphics/field_select.inc"
gEReaderText_Gfx:: @ 0x0818781C
	.incbin "graphics/ereader/text_eu.4bpp"
	.space 0x240
gIntroScene1TorchicSprites_Pals:: @ 0x0818F65C
	.incbin "graphics/intro/scene1torchic/sprites.gbapal"

gIntroScene1Torchic_BG3Tilemap:: @ 0x0818F85C
	.incbin "graphics/intro/scene1torchic/bg3_text_tilemap.bin"

gIntroScene1TorchicText_Gfx:: @ 0x0819005C
	.incbin "graphics/intro/scene1torchic/tiles.4bpp"
	.space 0x20

gIntroScene1Torchic_BG0Tilemap:: @ 0x0819587C
	.incbin "graphics/intro/scene1torchic/bg0_tilemap.bin"

gIntroScene1Torchic_BG2Tilemap:: @ 0x0819707C
	.incbin "graphics/intro/scene1torchic/bg2_dividers_tilemap.bin"

gIntroScene1Torchic_BG1Tilemap:: @ 0x0819807C
	.incbin "graphics/intro/scene1torchic/bg1_dividers_tilemap.bin"

gIntroScene1TorchicBall_Gfx:: @ 0x0819907C
	.incbin "graphics/intro/scene1torchic/ball.4bpp"
	.space 0x20

gIntroScene1TorchicSprites_Gfx:: @ 0x0819F89C
	.incbin "graphics/intro/scene1torchic/sprites.4bpp"

gIntroScene2Pikas_Pal:: @ 0x081A789C
	.incbin "graphics/intro/scene2pikas/scene.gbapal"

gIntroScene2Pikas_BG3Tilemap:: @ 0x081A7A9C
	.incbin "graphics/intro/scene2pikas/bg3_text_tilemap.bin"

gIntroScene2PikasSprites_Gfx:: @ 0x081A829C
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pichu/pikachu
	.incbin "graphics/intro/scene2pikas/tiles.4bpp"
	.space 0x20

gIntroScene2Pikas_BG0Tilemap:: @ 0x081AC2BC
	.incbin "graphics/intro/scene2pikas/bg0_pichu_tilemap.bin"

gIntroScene2Pikas_BG1Tilemap:: @ 0x081AE2BC
	.incbin "graphics/intro/scene2pikas/bg1_pikachu_tilemap.bin"

gIntroScene3Treecko_Pal:: @ 0x081B02BC
	.incbin "graphics/intro/scene3treecko/scene.gbapal"

gIntroScene3Treecko_BG2Tilemap:: @ 0x081B04BC
	.incbin "graphics/intro/scene3treecko/bg2_tilemap.bin"

gIntroScene3Treecko_BG3Tilemap:: @ 0x081B14BC
	.incbin "graphics/intro/scene3treecko/bg3_text_tilemap.bin"

gIntroScene3TreeckoBgTiles_Gfx:: @ 0x081B1CBC
	@ intro pane with treeko, pinball, flipper
	.incbin "graphics/intro/scene3treecko/tiles.4bpp"
	.space 0x20

gIntroScene3Treecko_BG1Tilemap:: @ 0x081B88DC
	.incbin "graphics/intro/scene3treecko/bg1_ball_tilemap.bin"

gIntroScene3Treecko_BG1TilemapA:: @ 0x081B90DC
	.incbin "graphics/intro/scene3treecko/bg1_ballandflipper_tilemap.bin"

gIntroScene3Treecko_BG1TilemapB:: @ 0x081B98DC
	.incbin "graphics/intro/scene3treecko/bg1_ballflipperhit_tilemap.bin"

gIntroScene3Treecko_BG0Tilemap:: @ 0x081BA0DC
	.incbin "graphics/intro/scene3treecko/bg0_treecko_tilemap.bin"

gIntroScene3TreeckoTreecko_Gfx:: @ 0x081BB0DC
	.incbin "graphics/intro/scene3treecko/treecko.4bpp"
	.space 0x20

gIntroScene4PlusleMinun_Pal:: @ 0x081BD0FC
	.incbin "graphics/intro/scene4plusleminun/scene.gbapal"

gIntroScene4PlusleMinun_BG3Tilemap:: @ 0x081BD2FC
	.incbin "graphics/intro/scene4plusleminun/bg3_text_tilemap.bin"

gIntroScene4PlusleMinunBgTiles_Gfx:: @ 0x081BDAFC
	.incbin "graphics/intro/scene4plusleminun/tiles.4bpp"

gIntroScene4PlusleMinun_BG0Tilemap:: @ 0x081C1B1C
	.incbin "graphics/intro/scene4plusleminun/bg0_minun_tilemap.bin"

gIntroScene4PlusleMinun_BG1Tilemap:: @ 0x081C3B1C
	.incbin "graphics/intro/scene4plusleminun/bg1_plusle_tilemap.bin"

gIntroScene5Mudkip_Pal:: @ 0x081C5B1C
	.incbin "graphics/intro/scene5mudkip/scene.gbapal"

gIntroScene5Mudkip_BG2Tilemap:: @ 0x081C5D1C
	.incbin "graphics/intro/scene5mudkip/bg2_2sections_tilemap.bin"

gIntroScene5Mudkip_BG1Tilemap:: @ 0x081C6D1C
	.incbin "graphics/intro/scene5mudkip/bg1_1sections_tilemap.bin"

gIntroScene5Mudkip_BG3Tilemap:: @ 0x081C7D1C
	.incbin "graphics/intro/scene5mudkip/bg3_text_tilemap.bin"

gIntroScene5MudkipBgTiles_Gfx:: @ 0x081C851C
	.incbin "graphics/intro/scene5mudkip/text_tiles.4bpp"
	.space 0x20

gIntroScene5Mudkip_BG0Tilemap:: @ 0x081CD53C
	.incbin "graphics/intro/scene5mudkip/bg0_tilemap.bin"

gIntroScene5MudkipSprites_Gfx:: @ 0x081CDD3C
	.incbin "graphics/intro/scene5mudkip/sprites.4bpp"
	.space 0x20

	.incbin "graphics/intro/scene5mudkip/unused_bg_tilemap.bin"

gIntroScene6Chinchou_Pal:: @ 0x081D1D5C
	.incbin "graphics/intro/scene6chinchou/scene.gbapal"

gIntroScene6Chinchou_BG3Tilemap:: @ 0x081D1F5C
	.incbin "graphics/intro/scene6chinchou/bg3_burst_tilemap.bin"

gIntroScene6ChinchouBgTiles_Gfx:: @ 0x081D275C
	.incbin "graphics/intro/scene6chinchou/tiles.4bpp"
	.space 0x20

gIntroScene6Chinchou_BG2Tilemap:: @ 0x081D8B7C
	.incbin "graphics/intro/scene6chinchou/bg2_chinchou_tilemap.bin"

gIntroScene6Chinchou_BG0Tilemap:: @ 0x081D937C
	.incbin "graphics/intro/scene6chinchou/bg0_chinchou_tilemap.bin"

gIntroScene6Chinchou_BG1Tilemap:: @ 0x081D9B7C
	.incbin "graphics/intro/scene6chinchou/bg1_ball_tilemap.bin"

gIntroScene6ChinchouStars_Gfx:: @ 0x081DBB7C
	.incbin "graphics/intro/scene6chinchou/stars.4bpp"
	.space 0x20

gIntroScene7Parade_Pal:: @ 0x081DCB9C
	.incbin "graphics/intro/scene7parade/scene.gbapal"

gIntroScene7Parade_BG3Tilemap:: @ 0x081DCD9C
	.incbin "graphics/intro/scene7parade/bg3_text_tilemap.bin"

gIntroScene7ParadeBgTiles_Gfx:: @ 0x081DD59C
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pelipper, makuhita, spoink

	.incbin "graphics/intro/scene7parade/tiles.4bpp"
	.space 0x20

gIntroScene7Parade_BG2Tilemap:: @ 0x081E25BC
	.incbin "graphics/intro/scene7parade/bg2_makuhita_tilemap.bin"

gIntroScene7Parade_BG0Tilemap:: @ 0x081E45BC
	.incbin "graphics/intro/scene7parade/bg0_pelipper_tilemap.bin"

gIntroScene7Parade_BG1Tilemap:: @ 0x081E65BC
	.incbin "graphics/intro/scene7parade/bg1_spoink_tilemap.bin"

gIntroScene7ParadeWailmer_Gfx:: @ 0x081E85BC
	.incbin "graphics/intro/scene7parade/wailmer.4bpp"
	.space 0x20

gIntroScene8WailmerLaunch_Pal:: @ 0x081EA5DC
	.incbin "graphics/intro/scene8wailmerlaunch/scene.gbapal"

gIntroScene8WailmerLaunch_BG2Tilemap:: @ 0x081EA7DC
	.incbin "graphics/intro/scene8wailmerlaunch/bg2_explosion_tilemap.bin"

gIntroScene8WailmerLaunchBgTiles_Gfx:: @ 0x081EAFDC
	.incbin "graphics/intro/scene8wailmerlaunch/explosion_tiles.4bpp"
	.space 0x20

gIntroScene8WailmerLaunch_Gfx:: @ 0x081EE3FC
	.incbin "graphics/intro/scene8wailmerlaunch/sprites.4bpp"
	.space 0x20

gIntroScene9BallFlight_Pal:: @ 0x081F141C
	.incbin "graphics/intro/scene9ballflight/scene.gbapal"

gIntroScene9BallFlight_BG3Tilemap:: @ 0x081F161C
	.incbin "graphics/intro/scene9ballflight/bg3_clouds_tilemap.bin"

gIntroScene9BallFlightClouds_Gfx:: @ 0x081F1E1C
	.incbin "graphics/intro/scene9ballflight/cloud_tiles.4bpp"
	.space 0x20

gIntroScene9BallFlightall_Gfx:: @ 0x081F423C
	.incbin "graphics/intro/scene9ballflight/ball.4bpp"

	.incbin "graphics/intro/wailmer_swallow.4bpp"

	.incbin "graphics/intro/scene9ballflight/ball_tail.4bpp"






gLanguageSelectBg0_Tilemap:: @ 0x081FC87C
	.incbin "graphics/language_select/bg0_tilemap.bin"
gLanguageSelectBg1_Tilemap:: @ 0x081FD07C
	.incbin "graphics/language_select/bg1_tilemap.bin"
gLanguageSelectSprite_Gfx:: @ 0x081FD87C
	.incbin "graphics/language_select/sprites.4bpp"
gLanguageSelectSprite_Pals:: @ 0x081FE89C
	.incbin "graphics/language_select/sprites.gbapal"
gLanguageSelect_Gfx:: @ 0x081FEA9C
	.incbin "graphics/language_select/bg.4bpp"
gLanguageSelectTitle_Gfx:: @ 0x08200A9C
	.incbin "graphics/language_select/titles.4bpp"
gLanguageSelectBg_Pals:: @ 0x08202ABC
	.incbin "graphics/language_select/bg.gbapal"
.include "data/graphics/titlescreen.inc"

gGravityDeltas_Strong:: @ 0x082539FC
	.2byte 1, 1, 1, 0

gGravityDeltas_Medium:: @ 0x08253A04
	.2byte 1, 0, 1, 0

gGravityDeltas_Light:: @ 0x08253A0C
	.2byte 1, 0, 0, 0

gIdlePinballGameStateFuncs:: @ 0x08253A14
	.4byte PinballGameIdle0_19048
	.4byte PinballGameIdle1_19190
	.4byte PinballGame_State2_4ABC8 @shared with main game mode
	.4byte PinballGameIdle3_19288

gAreaPortraitIndexes:: @ 0x08253A24
	.2byte 0, 1, 2, 3, 4
	.2byte 5, 6, 7, 8, 9
	.2byte 10, 11, 12, 12

gPondBumperRetractFrames:: @ 0x08253A40
	.2byte 10, 7,6,5,4,3,2,1,0,1,0,1,0,1,0,1,0,1

gPondBumperTransitionFrames:: @ 0x08253A64
	.2byte 0,2,3,4,5,6,7,10,10,10,7,6,5,4,3,2,1,0

gLotadBobOffsets:: @ 0x08253A88
	.2byte 0, 10, 20, 30, 20, 10

gChinchouBumper_Pals:: @ 0x08253A94
	.incbin "graphics/stage/main/chinchou_bumper.gbapal"

gLotadBumper_Pals:: @ 0x08253AB4
	.incbin "graphics/stage/main/lotad_bumper.gbapal"

gWhiscash_Pals:: @ 0x08253AD4
	.incbin "graphics/stage/main/whiscash.gbapal"

gBoardArrowAnimFrames:: @ 0x08253BB4
	.2byte 0,1,2,3,2,1,0,3,0,3

	@ Outside range used by the bumperAnimFrames.
	.2byte 0,0,0,0,0,0,0,0,0,0
	.2byte 0,0,0,0,0,0,0,0,0,0
	.2byte 0,0,0,1,0,0,0,1,0,0
	.2byte 0,1,0,1,0,1,0,1,0,1
	.2byte 0,1,1,1,0,1,1,1,0,1
	.2byte 1,1,1,1,1,1

gFieldVariant_Pals:: @ 0x08253C38
	.incbin "graphics/stage/main/field_variants.gbapal"

gPelipperFlyAnimTable:: @ 0x08253DB8
	@ frameId, yOffset
	.byte 9, -4
	.byte 9, -4
	.byte 9, -4
	.byte 9, -4
	.byte 10, -2
	.byte 10, -2
	.byte 11, 0
	.byte 11, 0
	.byte 11, 0
	.byte 12, -2
	.byte 12, -2
	.byte 12, -2
	.byte 12, -2

gBumperMosaicValues:: @ 0x08253DD2
	.2byte 0,4,2,0,4,2

gShopSignLoopFrames:: @ 0x08253DDE
	@2 sets of 5
	.2byte 0,1,2,2,1
	.2byte 7,8,9,8,0

gShopSignIntroFrames:: @ 0x08253DF2
	@2 sets of 4
	.2byte 3,0,3,0
	.2byte 6,7,6,7

gShopSignTransitionFrames:: @ 0x08253E02
	@2 sets of 14
	.2byte 6,7,6,4,4,5,5,4,4,5,5,3,0,3
	.2byte 3,0,3,4,4,5,5,4,4,5,5,6,7,6
	.space 2, 0

gDusclopsBossGuardReadyTileOffsets:: @ 0x08253E3C
	.2byte 12,13,12,14

gLightningGrabAnimFrameIndices:: @ 0x08253E44
	.2byte 0,1,2,3,4,7,2,1,7,5,6,0

gSphealScoreDigitSpriteIndices:: @ 0x08253E5C
	.byte 0,2,2,2,2,2,0,0,0,0
	.byte 2,2,2,2,2,1,1,1,1,1
	.byte 1,1,0,0

	@ Vector16

gPauseMenuSpriteOffsets:: @ 0x08253E74
	.include "data/src/pause_menu_sprite_offsets.inc"
gPauseMenuTextAnimFrames:: @ 0x08253EA0
	.2byte 0,0,0,0,0,1,2,3,3,3,3,4,5

gDebugTextStrings:: @ 0x08253EBA
	.ascii " BALL-MV:"
	.byte 0,0,0,0,0
	.ascii " BALL-SPD:"
	.byte 0,0,0,0
	.ascii "  DEBUG1:"
	.byte 0,0,0,0,0

gDebugMenuValueTemplate:: @ 0x08253EE4
	.ascii "(000 000)"
	.byte 0,0,0
	.ascii "(000)    "
	.byte 0,0,0

gDebugMenuCursorText:: @ 0x08253EFC
	.ascii "*"
	.byte 0

	.align 2, 0
gPinballGameStateFuncs:: @ 0x08253F00
	.4byte PinballGame_State0_49ED4 @ called once upon loading the field
	.4byte PinballGame_State1_4AAD8 @ called once every frame while playing
	.4byte PinballGame_State2_4ABC8 @ called once on game over (losing all balls)
	.4byte PinballGame_State3_4B20C @ called once after game over?

gIdlePressStartTiles_Fr:: @ 0x08253F10
	.include "data/src/idle_press_start_tiles.inc"
gBall_Pals:: @ 0x08253F4C
	.incbin "graphics/stage/main/pokeball_regular.gbapal"
	.incbin "graphics/stage/main/pokeball_great.gbapal"
	.incbin "graphics/stage/main/pokeball_ultra.gbapal"
	.incbin "graphics/stage/main/pokeball_master.gbapal"
	.incbin "graphics/stage/main/pokeball_regular_flash.gbapal"
	.incbin "graphics/stage/main/pokeball_great_flash.gbapal"
	.incbin "graphics/stage/main/pokeball_ultra_flash.gbapal"
	.incbin "graphics/stage/main/pokeball_master_flash.gbapal"
	.incbin "graphics/stage/main/ball_full_white.gbapal"
	@ The following are actually unused; apparently, these were considered
	@ for the freeze trap at some point, but were switched to pure white instead.
	.incbin "graphics/stage/main/pokeball_regular_frozen.gbapal"
	.incbin "graphics/stage/main/pokeball_great_frozen.gbapal"
	.incbin "graphics/stage/main/pokeball_ultra_frozen.gbapal"
	.incbin "graphics/stage/main/pokeball_master_frozen.gbapal"

gCaptureBallTilesGfx:: @ 0x0825414C
	.incbin "graphics/stage/main/ball_open_to_catch.4bpp"
	.space 0x20

gDusclopsBonusClear_Gfx_En:: @ 0x0825496C
gDusclopsBonusClear_Gfx:: @ 0x0825496C
	.incbin "graphics/stage/dusclops/dusclops_bonus_clear.4bpp"
	.space 0x20

gDusclopsBonusClear_Gfx_Fr:: @ 0x0825698C
	.incbin "graphics/stage/dusclops/dusclops_bonus_clear_fr.4bpp"
	.space 0x20
gDusclopsBonusClear_Gfx_De:: @ 0x082589AC
	.incbin "graphics/stage/dusclops/dusclops_bonus_clear_de.4bpp"
	.space 0x20
gDusclopsBonusClear_Gfx_It:: @ 0x0825A9CC
	.incbin "graphics/stage/dusclops/dusclops_bonus_clear_it.4bpp"
	.space 0x20
gDusclopsBonusClear_Gfx_Es:: @ 0x0825C9EC
	.incbin "graphics/stage/dusclops/dusclops_bonus_clear_es.4bpp"
	.space 0x20
gKecleonBonusClear_Gfx_En:: @ 0x0825EA0C
gKecleonBonusClear_Gfx:: @ 0x0825EA0C
	.incbin "graphics/stage/kecleon/kecleon_bonus_clear.4bpp"
	.space 0x20

gKecleonBonusClear_Gfx_Fr:: @ 0x08260A2C
	.incbin "graphics/stage/kecleon/kecleon_bonus_clear_fr.4bpp"
	.space 0x20
gKecleonBonusClear_Gfx_De:: @ 0x08262A4C
	.incbin "graphics/stage/kecleon/kecleon_bonus_clear_de.4bpp"
	.space 0x20
gKecleonBonusClear_Gfx_It:: @ 0x08264A6C
	.incbin "graphics/stage/kecleon/kecleon_bonus_clear_it.4bpp"
	.space 0x20
gKecleonBonusClear_Gfx_Es:: @ 0x08266A8C
	.incbin "graphics/stage/kecleon/kecleon_bonus_clear_es.4bpp"
	.space 0x20
gKyogreBonusClear_Gfx_En:: @ 0x08268AAC
gKyogreBonusClear_Gfx:: @ 0x08268AAC
	.incbin "graphics/stage/kyogre/kyogre_bonus_clear.4bpp"
	.space 0x20

gKyogreBonusClear_Gfx_Fr:: @ 0x0826AACC
	.incbin "graphics/stage/kyogre/kyogre_bonus_clear_fr.4bpp"
	.space 0x20
gKyogreBonusClear_Gfx_De:: @ 0x0826CAEC
	.incbin "graphics/stage/kyogre/kyogre_bonus_clear_de.4bpp"
	.space 0x20
gKyogreBonusClear_Gfx_It:: @ 0x0826EB0C
	.incbin "graphics/stage/kyogre/kyogre_bonus_clear_it.4bpp"
	.space 0x20
gKyogreBonusClear_Gfx_Es:: @ 0x08270B2C
	.incbin "graphics/stage/kyogre/kyogre_bonus_clear_es.4bpp"
	.space 0x20
gGroudonBonusClear_Gfx_En:: @ 0x08272B4C
gGroudonBonusClear_Gfx:: @ 0x08272B4C
	.incbin "graphics/stage/groudon/groudon_bonus_clear.4bpp"
	.space 0x20

gGroudonBonusClear_Gfx_Fr:: @ 0x08274B6C
	.incbin "graphics/stage/groudon/groudon_bonus_clear_fr.4bpp"
	.space 0x20
gGroudonBonusClear_Gfx_De:: @ 0x08276B8C
	.incbin "graphics/stage/groudon/groudon_bonus_clear_de.4bpp"
	.space 0x20
gGroudonBonusClear_Gfx_It:: @ 0x08278BAC
	.incbin "graphics/stage/groudon/groudon_bonus_clear_it.4bpp"
	.space 0x20
gGroudonBonusClear_Gfx_Es:: @ 0x0827ABCC
	.incbin "graphics/stage/groudon/groudon_bonus_clear_es.4bpp"
	.space 0x20
gRayquazaBonusClear_Gfx_En:: @ 0x0827CBEC
gRayquazaBonusClear_Gfx:: @ 0x0827CBEC
	.incbin "graphics/stage/rayquaza/rayquaza_bonus_clear.4bpp"
	.space 0x20

gRayquazaBonusClear_Gfx_Fr:: @ 0x0827EC0C
	.incbin "graphics/stage/rayquaza/rayquaza_bonus_clear_fr.4bpp"
	.space 0x20
gRayquazaBonusClear_Gfx_De:: @ 0x08280C2C
	.incbin "graphics/stage/rayquaza/rayquaza_bonus_clear_de.4bpp"
	.space 0x20
gRayquazaBonusClear_Gfx_It:: @ 0x08282C4C
	.incbin "graphics/stage/rayquaza/rayquaza_bonus_clear_it.4bpp"
	.space 0x20
gRayquazaBonusClear_Gfx_Es:: @ 0x08284C6C
	.incbin "graphics/stage/rayquaza/rayquaza_bonus_clear_es.4bpp"
	.space 0x20
gCaptureScreenTilesGfx:: @ 0x08286C8C
	.incbin "graphics/stage/main/capture_screen.4bpp"

.include "data/graphics/mon_hatch_sprites_pals.inc"

@ Attract-mode demos. Each IdleBoardConfig entry has 4800 ReplayInputFrame entries
@ (3 bytes of button bits per game frame).
@ Eeach GameState is one PinballGame snapshot the demo starts from.
gIdleBoardConfig0:: @ 0x082894AC
	.incbin "data/idle_board/replay_input_0.bin"

gIdleBoardConfig2:: @ 0x0828CCEC
	.incbin "data/idle_board/replay_input_2.bin"

gIdleBoardConfig3:: @ 0x0829052C
	.incbin "data/idle_board/replay_input_3.bin"

gIdleBoardConfig1:: @ 0x08293D6C
	.incbin "data/idle_board/replay_input_1.bin"

gIdleBoardGameState0:: @ 0x082975AC
	.incbin "data/idle_board/game_state_0.bin"

gIdleBoardGameState2:: @ 0x082989D0
	.incbin "data/idle_board/game_state_2.bin"

gIdleBoardGameState3:: @ 0x08299DF4
	.incbin "data/idle_board/game_state_3.bin"

gIdleBoardGameState1:: @ 0x0829B218
	.incbin "data/idle_board/game_state_1.bin"

gEvolutionCutsceneTilesGfx_EnFr:: @ 0x0829C63C
gEvolutionCutsceneTilesGfx:: @ 0x0829C63C
	.incbin "graphics/stage/main/board_action.4bpp"
	.space 0x3E0

gEvolutionCutsceneTilesGfx_De:: @ 0x0829EA5C
	.incbin "graphics/stage/main/board_action_de.4bpp"
	.space 0x3E0
gEvolutionCutsceneTilesGfx_It:: @ 0x082A0E7C
	.incbin "graphics/stage/main/board_action_it.4bpp"
	.space 0x3E0
gEvolutionCutsceneTilesGfx_Es:: @ 0x082A329C
	.incbin "graphics/stage/main/board_action_es.4bpp"
	.space 0x3E0
gBoardActionObj_Pals:: @ 0x082A56BC
	.incbin "graphics/stage/main/board_action_obj.gbapal"

gEvoExAppear_Gfx:: @ 0x082A58BC
	.incbin "graphics/board_pickups/evo_item_ex.4bpp";

gEvoExAppear_Gfx_De:: @ 0x082A74DC
	.incbin "graphics/board_pickups/evo_item_ex_de.4bpp"
gEvoExAppear_Gfx_It:: @ 0x082A90FC
	.incbin "graphics/board_pickups/evo_item_ex_it.4bpp"
gEvoExAppear_Gfx_Es:: @ 0x082AAD1C
	.incbin "graphics/board_pickups/evo_item_ex_es.4bpp"
gEvoItem_Pals:: @ 0x082AC93C
	.incbin "graphics/board_pickups/icon1_xp.gbapal";
	.incbin "graphics/board_pickups/icon2_leaf.gbapal";
	.incbin "graphics/board_pickups/icon3_fire.gbapal";
	.incbin "graphics/board_pickups/icon4_link.gbapal";
	.incbin "graphics/board_pickups/icon5_moon.gbapal";
	.incbin "graphics/board_pickups/icon6_water.gbapal";
	.incbin "graphics/board_pickups/icon7_bolt.gbapal";
	.incbin "graphics/board_pickups/icon8_sun.gbapal";
	.incbin "graphics/board_pickups/icon9_heart.gbapal";
	.incbin "graphics/board_pickups/icon10_pokeblock.gbapal";
	@ Six blank palettes, filling out the block. Solely containing a near-flat grey.
	.incbin "graphics/board_pickups/evo_item_unused.gbapal.bin"

gEvoLeafAppear_Gfx:: @ 0x082ACB3C
	.incbin "graphics/board_pickups/evo_item_leaf.4bpp";

gEvoFireAppear_Gfx:: @ 0x082AE75C
	.incbin "graphics/board_pickups/evo_item_fire.4bpp";

gEvoHeartAppear_Gfx:: @ 0x082B037C
	.incbin "graphics/board_pickups/evo_item_heart.4bpp";

gEvoLinkAppear_Gfx:: @ 0x082B1F9C
	.incbin "graphics/board_pickups/evo_item_link.4bpp";

gEvoMoonAppear_Gfx:: @ 0x082B3BBC
	.incbin "graphics/board_pickups/evo_item_moon.4bpp";

gEvoWaterAppear_Gfx:: @ 0x082B57DC
	.incbin "graphics/board_pickups/evo_item_water.4bpp";

gEvoBoxAppear_Gfx:: @ 0x082B73FC
	.incbin "graphics/board_pickups/evo_item_box.4bpp";

gEvoSunAppear_Gfx:: @ 0x082B901C
	.incbin "graphics/board_pickups/evo_item_sun.4bpp";

gEvoBoltAppear_Gfx:: @ 0x082BAC3C
	.incbin "graphics/board_pickups/evo_item_bolt.4bpp";

gFlipperCollisionData:: @ 0x082BC85C
@ Flipper data has 13 sets of 96*96 u16 data (2 unused at the end)
	.incbin "data/board_data/collision/flipper_collision_all_96x96.bin"

@ 8x8 font, one tile per character.

.include "data/graphics/mon_catch_sprites_pals.inc"

gKyogreWaterAnimFrame_Pals:: @ 0x082F925C
	.incbin "graphics/stage/kyogre/water_anim_frames.gbapal"

gPokeballCaptureOamFrames:: @ 0x082F945C
	@ frame 0
	packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1

	@ frame 1
	packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2CC, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2D4, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2D8, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2DC, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2CC, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2D4, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2D8, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2DC, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2CC, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2D4, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2D8, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2DC, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2CC, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2D4, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2D8, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2DC, paletteNum=0x1

	@ frame 2
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2DE, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2E6, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2EA, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2EE, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2DE, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2E6, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2EA, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2EE, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2DE, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2E6, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2EA, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2EE, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2DE, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2E6, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2EA, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2EE, paletteNum=0x1

	@ frame 3
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2F0, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2F8, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2FC, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x300, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2F0, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2F8, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2FC, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x300, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2F0, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2F8, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2FC, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x300, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2F0, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2F8, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2FC, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x300, paletteNum=0x1

	@ frame 4
    packed_sprite_oam x=-0xB, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x302, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x30A, paletteNum=0x1
    packed_sprite_oam x=0x15, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0x6, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x302, paletteNum=0x1
    packed_sprite_oam x=-0x6, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x30A, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x302, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x30A, paletteNum=0x1
    packed_sprite_oam x=0x15, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0x6, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x302, paletteNum=0x1
    packed_sprite_oam x=-0x6, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x30A, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1

	@ frame 5
    packed_sprite_oam x=-0xA, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=0x16, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0x7, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=-0xF, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=0x16, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0x7, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=-0xF, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=0x16, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0x7, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=-0xF, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=0x16, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0x7, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=-0xF, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1

	@ frame 6
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1

	@ frame 7
    packed_sprite_oam x=0x0, y=-0x2, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x2, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=-0x12, y=0x9, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x32E, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x9, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x336, paletteNum=0x1
    packed_sprite_oam x=-0x3, y=0x21, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x338, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x29, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x33A, paletteNum=0x1
    packed_sprite_oam x=0x0, y=-0x2, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x2, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=-0x12, y=0x9, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x32E, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x9, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x336, paletteNum=0x1
    packed_sprite_oam x=-0x3, y=0x21, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x338, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x29, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x33A, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x29, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x33A, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x29, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x33A, paletteNum=0x1

	@ frame 8
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=-0xD, y=0x1A, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x343, paletteNum=0x1
    packed_sprite_oam x=-0x5, y=0xA, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x34B, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x34D, paletteNum=0x1
    packed_sprite_oam x=0xF, y=0x3E, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x35D, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x6, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x35F, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x16, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x361, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=-0xD, y=0x1A, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x343, paletteNum=0x1
    packed_sprite_oam x=-0x5, y=0xA, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x34B, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x34D, paletteNum=0x1
    packed_sprite_oam x=0xF, y=0x3E, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x35D, paletteNum=0x1

	@ frame 9
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x27, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x362, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x17, priority=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x372, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xF, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37A, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=0x7, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x37B, paletteNum=0x1
    packed_sprite_oam x=0x1F, y=0x37, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=0x27, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x380, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x17, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x388, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x38A, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1

	@ frame 10
    packed_sprite_oam x=0x6, y=0x26, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x362, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x16, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x372, paletteNum=0x1
    packed_sprite_oam x=-0x12, y=0x36, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x26, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x380, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x16, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x388, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x46, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x38A, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x46, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x6, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x38F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x391, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1

	@ frame 11
	packed_sprite_oam x=0xA, y=0x18, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x396, paletteNum=0x1
    packed_sprite_oam x=0xA, y=0x38, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x39E, paletteNum=0x1
    packed_sprite_oam x=-0x5, y=0x20, hFlip=0x1, vFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x396, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x18, hFlip=0x1, vFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x39E, paletteNum=0x1
    packed_sprite_oam x=0x6, y=0x26, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x362, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x16, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x372, paletteNum=0x1
    packed_sprite_oam x=-0x12, y=0x36, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x26, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x380, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x16, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x388, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x46, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x38A, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x46, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x6, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x38F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x391, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1

	@ frame 12
	packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x21, vFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x396, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x19, vFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x39E, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x27, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x362, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x17, priority=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x372, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xF, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37A, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=0x7, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x37B, paletteNum=0x1
    packed_sprite_oam x=0x1F, y=0x37, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=0x27, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x380, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x17, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x388, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x38A, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1

	@ frame 13
    packed_sprite_oam x=-0x2, y=0x6, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x38F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x391, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x5, y=0x26, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x35D, paletteNum=0x1
    packed_sprite_oam x=0x1, y=0x16, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x356, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x16, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x358, paletteNum=0x1
    packed_sprite_oam x=0x1, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x35A, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1

	@ frame 14
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1

gRubyBoardPaletteSet1:: @ 0x082F99FC
    .incbin "graphics/stage/ruby/ruby_board_palset_1.gbapal"

gSapphireBoardPaletteSet1:: @ 0x082F9BFC
    .incbin "graphics/stage/sapphire/sapphire_board_palset_1.gbapal"

gDusclopsBoardPaletteSet1:: @ 0x082F9DFC
    .incbin "graphics/stage/dusclops/dusclops_board_palset_1.gbapal"

gKecleonBoardPaletteSet1:: @ 0x082F9FFC
    .incbin "graphics/stage/kecleon/kecleon_board_palset_1.gbapal"

gKyogreBoardPaletteSet1:: @ 0x082FA1FC
    .incbin "graphics/stage/kyogre/kyogre_board_palset_1.gbapal"

gGroudonBoardPaletteSet1:: @ 0x082FA3FC
    .incbin "graphics/stage/groudon/groudon_board_palset_1.gbapal"

gRayquazaBoardPaletteSet1:: @ 0x082FA5FC
    .incbin "graphics/stage/rayquaza/rayquaza_board_palset_1.gbapal"

gSphealBoardPaletteSet1:: @ 0x082FA7FC
    .incbin "graphics/stage/spheal/spheal_board_palset_1.gbapal"

gRubyBoardPaletteSet2:: @ 0x082FA9FC
    .incbin "graphics/stage/ruby/ruby_board_palset_2.gbapal"

gSapphireBoardPaletteSet2:: @ 0x082FABFC
    .incbin "graphics/stage/sapphire/sapphire_board_palset_2.gbapal"

gDusclopsBoardPaletteSet2:: @ 0x082FADFC
    .incbin "graphics/stage/dusclops/dusclops_board_palset_2.gbapal"

gKecleonBoardPaletteSet2:: @ 0x082FAFFC
    .incbin "graphics/stage/kecleon/kecleon_board_palset_2.gbapal"

gKyogreBoardPaletteSet2:: @ 0x082FB1FC
    .incbin "graphics/stage/kyogre/kyogre_board_palset_2.gbapal"

gGroudonBoardPaletteSet2:: @ 0x082FB3FC
    .incbin "graphics/stage/groudon/groudon_board_palset_2.gbapal"

gRayquazaBoardPaletteSet2:: @ 0x082FB5FC
    .incbin "graphics/stage/rayquaza/rayquaza_board_palset_2.gbapal"

gSphealBoardPaletteSet2:: @ 0x082FB7FC
    .incbin "graphics/stage/spheal/spheal_board_palset_2.gbapal"

gRubyBoardPaletteSet0:: @ 0x082FB9FC
    .incbin "graphics/stage/ruby/ruby_board_palset_0.gbapal"

gBonusStageObjPal:: @ 0x082FBB1C
	.incbin "graphics/stage/main/bonus_stage_obj.gbapal"

gSapphireBoardPaletteSet0:: @ 0x082FBBFC
    .incbin "graphics/stage/sapphire/sapphire_board_palset_0.gbapal"

gDusclopsBoardPaletteSet0:: @ 0x082FBDFC
	.incbin "graphics/stage/dusclops/dusclops_board_palset_0.gbapal"

gKecleonBoardPaletteSet0:: @ 0x082FBFFC
    .incbin "graphics/stage/kecleon/kecleon_board_palset_0.gbapal"

gKyogreBoardPaletteSet0:: @ 0x082FC1FC
    .incbin "graphics/stage/kyogre/kyogre_board_palset_0.gbapal"

gGroudonBoardPaletteSet0:: @ 0x082FC3FC
    .incbin "graphics/stage/groudon/groudon_board_palset_0.gbapal"

gRayquazaBoardPaletteSet0:: @ 0x082FC5FC
    .incbin "graphics/stage/rayquaza/rayquaza_board_palset_0.gbapal"

gSphealBoardPaletteSet0:: @ 0x082FC7FC
    .incbin "graphics/stage/spheal/spheal_board_palset_0.gbapal"

gEvoNameDisplay_Pals:: @ 0x082FC9FC
	.incbin "graphics/stage/main/evo_name_display.gbapal"

gShopNameDisplay_Pals:: @ 0x082FCA1C
	.incbin "graphics/stage/main/shop_name_display.gbapal"
	.space 0x1C0

@ Evolution selection background loop
gEvoModeBG0_0_Tilemap_En:: @ 0x082FCBFC
gEvoModeBG0_0_Tilemap:: @ 0x082FCBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame0_tilemap.bin"

gEvoModeBG0_0_Tilemap_Fr:: @ 0x082FDBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame0_tilemap_fr.bin"
gEvoModeBG0_0_Tilemap_De:: @ 0x082FEBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame0_tilemap_de.bin"
gEvoModeBG0_0_Tilemap_It:: @ 0x082FFBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame0_tilemap_it.bin"
gEvoModeBG0_0_Tilemap_Es:: @ 0x08300BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame0_tilemap_es.bin"
gEvoModeBG0_1_Tilemap:: @ 0x08301BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame1_tilemap.bin"

gEvoModeBG0_1_Tilemap_Fr:: @ 0x08302BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame1_tilemap_fr.bin"
gEvoModeBG0_1_Tilemap_De:: @ 0x08303BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame1_tilemap_de.bin"
gEvoModeBG0_1_Tilemap_It:: @ 0x08304BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame1_tilemap_it.bin"
gEvoModeBG0_1_Tilemap_Es:: @ 0x08305BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame1_tilemap_es.bin"
gEvoModeBG0_2_Tilemap:: @ 0x08306BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame2_tilemap.bin"

gEvoModeBG0_2_Tilemap_Fr:: @ 0x08307BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame2_tilemap_fr.bin"
gEvoModeBG0_2_Tilemap_De:: @ 0x08308BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame2_tilemap_de.bin"
gEvoModeBG0_2_Tilemap_It:: @ 0x08309BFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame2_tilemap_it.bin"
gEvoModeBG0_2_Tilemap_Es:: @ 0x0830ABFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame2_tilemap_es.bin"
gEvoModeBG0_3_Tilemap:: @ 0x0830BBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame3_tilemap.bin"

gEvoModeBG0_3_Tilemap_Fr:: @ 0x0830CBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame3_tilemap_fr.bin"
gEvoModeBG0_3_Tilemap_De:: @ 0x0830DBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame3_tilemap_de.bin"
gEvoModeBG0_3_Tilemap_It:: @ 0x0830EBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame3_tilemap_it.bin"
gEvoModeBG0_3_Tilemap_Es:: @ 0x0830FBFC
	.incbin "graphics/stage/main/evo_mode_bg0_frame3_tilemap_es.bin"
gShopEvoUI_Pals:: @ 0x08310BFC
	.incbin "graphics/stage/main/shop_evo_ui.gbapal"

@ Shop mode background loop
gShopModeBG0_0_Tilemap_En:: @ 0x08310DFC
gShopModeBG0_0_Tilemap:: @ 0x08310DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame0_tilemap.bin"

gShopModeBG0_0_Tilemap_Fr:: @ 0x08311DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame0_tilemap_fr.bin"
gShopModeBG0_0_Tilemap_De:: @ 0x08312DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame0_tilemap_de.bin"
gShopModeBG0_0_Tilemap_It:: @ 0x08313DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame0_tilemap_it.bin"
gShopModeBG0_0_Tilemap_Es:: @ 0x08314DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame0_tilemap_es.bin"
gShopModeBG0_1_Tilemap:: @ 0x08315DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame1_tilemap.bin"

gShopModeBG0_1_Tilemap_Fr:: @ 0x08316DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame1_tilemap_fr.bin"
gShopModeBG0_1_Tilemap_De:: @ 0x08317DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame1_tilemap_de.bin"
gShopModeBG0_1_Tilemap_It:: @ 0x08318DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame1_tilemap_it.bin"
gShopModeBG0_1_Tilemap_Es:: @ 0x08319DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame1_tilemap_es.bin"
gShopModeBG0_2_Tilemap:: @ 0x0831ADFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame2_tilemap.bin"

gShopModeBG0_2_Tilemap_Fr:: @ 0x0831BDFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame2_tilemap_fr.bin"
gShopModeBG0_2_Tilemap_De:: @ 0x0831CDFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame2_tilemap_de.bin"
gShopModeBG0_2_Tilemap_It:: @ 0x0831DDFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame2_tilemap_it.bin"
gShopModeBG0_2_Tilemap_Es:: @ 0x0831EDFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame2_tilemap_es.bin"
gShopModeBG0_3_Tilemap:: @ 0x0831FDFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame3_tilemap.bin"

gShopModeBG0_3_Tilemap_Fr:: @ 0x08320DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame3_tilemap_fr.bin"
gShopModeBG0_3_Tilemap_De:: @ 0x08321DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame3_tilemap_de.bin"
gShopModeBG0_3_Tilemap_It:: @ 0x08322DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame3_tilemap_it.bin"
gShopModeBG0_3_Tilemap_Es:: @ 0x08323DFC
	.incbin "graphics/stage/main/shop_mode_bg0_frame3_tilemap_es.bin"
gSapphireShopSign_Pals:: @ 0x08324DFC
	.incbin "graphics/stage/sapphire/shop_sign.gbapal"

gRubyTravelPaint_Gfx:: @ 0x08324F1C
	.incbin "graphics/stage/ruby/travel_paint.4bpp"
	.space 0x120

gRubyPainter_Pals:: @ 0x0832673C
	.incbin "graphics/stage/ruby/painter.gbapal"

gSapphireTravelPaint_Gfx:: @ 0x0832693C
	.incbin "graphics/stage/sapphire/travel_paint.4bpp"
	.space 0x120

gSapphirePainter_Pals:: @ 0x0832815C
	.incbin "graphics/stage/sapphire/painter.gbapal"

gRubyBoard_Pals:: @ 0x0832835C
	.incbin "graphics/stage/ruby/ruby_board.gbapal"

gTimer_Default_Pal:: @ 0x083284DC
	.incbin "graphics/stage/main/default_timer.gbapal"

gLocation_Pals:: @ 0x0832855C
	.incbin "graphics/area_portraits/loc00_ruby_forest.gbapal"
	.incbin "graphics/area_portraits/loc01_sapphire_forest.gbapal"
	.incbin "graphics/area_portraits/loc02_ruby_plains.gbapal"
	.incbin "graphics/area_portraits/loc03_sapphire_plains.gbapal"
	.incbin "graphics/area_portraits/loc04_ruby_harbor.gbapal"
	.incbin "graphics/area_portraits/loc05_sapphire_beach.gbapal"
	.incbin "graphics/area_portraits/loc06_ruby_cave.gbapal"
	.incbin "graphics/area_portraits/loc07_sapphire_cave.gbapal"
	.incbin "graphics/area_portraits/loc08_ruby_safari_zone.gbapal"
	.incbin "graphics/area_portraits/loc09_ruby_volcano.gbapal"
	.incbin "graphics/area_portraits/loc10_sapphire_lake.gbapal"
	.incbin "graphics/area_portraits/loc11_sapphire_desert.gbapal"
	.incbin "graphics/area_portraits/loc12_ruins.gbapal"

	@ 3 unused palettes: one with color data, two blank
	.incbin "graphics/area_portraits/loc_unused.gbapal.bin"

gPortraitAnim_Pals:: @ 0x0832875C
	.incbin "graphics/slot_options/slot_options_1.gbapal"
	.incbin "graphics/slot_options/slot_options_3.gbapal"
	.incbin "graphics/slot_options/slot_options_5.gbapal"
	.incbin "graphics/slot_options/slot_options_7.gbapal"
	.incbin "graphics/slot_options/slot_options_9.gbapal"
	.incbin "graphics/slot_options/slot_options_11.gbapal"
	.incbin "graphics/slot_options/slot_options_13.gbapal"
	.incbin "graphics/slot_options/slot_options_15.gbapal"
	.incbin "graphics/slot_options/slot_options_17.gbapal"
	.incbin "graphics/slot_options/slot_options_19.gbapal"
	.incbin "graphics/slot_options/slot_options_21.gbapal"
	.incbin "graphics/slot_options/slot_options_23.gbapal"
	.incbin "graphics/slot_options/slot_options_25.gbapal"
	.incbin "graphics/slot_options/slot_options_27.gbapal"
	.incbin "graphics/slot_options/slot_options_29.gbapal"
	.incbin "graphics/slot_options/slot_options_31.gbapal"
	.incbin "graphics/slot_options/slot_options_33.gbapal"
	.incbin "graphics/slot_options/slot_options_35.gbapal"
	.incbin "graphics/slot_options/slot_options_37.gbapal"
	.incbin "graphics/slot_options/slot_options_39.gbapal"
	.incbin "graphics/slot_options/slot_options_41.gbapal"
	.incbin "graphics/slot_options/slot_options_43.gbapal"
	.incbin "graphics/slot_options/slot_options_45.gbapal"
	.incbin "graphics/slot_options/slot_options_47.gbapal"
	.incbin "graphics/slot_options/slot_options_49.gbapal"
	.incbin "graphics/slot_options/slot_options_51.gbapal"
	.incbin "graphics/slot_options/slot_options_53.gbapal"
	.incbin "graphics/slot_options/slot_options_55.gbapal"
	.incbin "graphics/slot_options/slot_options_57.gbapal"
	.incbin "graphics/slot_options/slot_options_59.gbapal"
	.incbin "graphics/slot_options/slot_options_61.gbapal"
	.incbin "graphics/slot_options/slot_options_63.gbapal"
	.incbin "graphics/slot_options/slot_options_65.gbapal"
	.incbin "graphics/slot_options/slot_options_67.gbapal"
	.incbin "graphics/slot_options/slot_options_69.gbapal"
	.incbin "graphics/slot_options/slot_options_71.gbapal"
	.incbin "graphics/slot_options/slot_options_73.gbapal"
	.incbin "graphics/slot_options/slot_options_75.gbapal"
	.incbin "graphics/slot_options/slot_options_77.gbapal"
	.incbin "graphics/slot_options/slot_options_79.gbapal"
	.incbin "graphics/slot_options/slot_options_81.gbapal"
	.incbin "graphics/slot_options/slot_options_83.gbapal"
	.incbin "graphics/slot_options/slot_options_85.gbapal"
	.incbin "graphics/slot_options/slot_options_87.gbapal"
	.incbin "graphics/slot_options/slot_options_89.gbapal"
	.incbin "graphics/slot_options/slot_options_91.gbapal"
	.incbin "graphics/slot_options/slot_options_93.gbapal"
	.incbin "graphics/slot_options/slot_options_95.gbapal"

.include "data/board_data/ruby_board.inc"

.include "data/board_data/sapphire_board.inc"

.include "data/board_data/dusclops_board.inc"

.include "data/board_data/kecleon_board.inc"

.include "data/board_data/kyogre_board.inc"

.include "data/board_data/groudon_board.inc"


.include "data/board_data/rayquaza_board.inc"


.include "data/board_data/spheal_board.inc"

gPichuKickbackFx_Gfx:: @ 0x0856C5EC
	.incbin "graphics/stage/main/pichu_saver_kickback.4bpp"
	.space 0x20

gPikachuKickbackFx_Gfx:: @ 0x0856EA0C
	.incbin "graphics/stage/main/pikachu_saver_kickback.4bpp"
	.space 0x20

gCatchTargetCollisionBitmap:: @ 0x08570E2C
	.incbin "data/board_data/collision/catch_target_collision_48x48_typeless.bin"

.include "data/graphics/mon_portraits_pals.inc"

@ The puff that reveals the catch mon.
gCatchMonAppearFx_Gfx:: @ 0x0857332C
	.incbin "graphics/stage/main/catch_mon_appear_fx.4bpp"
	.space 0x20

gCatchMonAppearFx_Pal:: @ 0x0857474C
	.incbin "graphics/stage/main/catch_mon_appear_fx.gbapal"

gCatchTile_RevealTilesGfx:: @ 0x0857494C
	.incbin "graphics/stage/main/catch_tile_reveal.4bpp"
	.space 0xA00

gCatchTile_Reveal_Pal:: @ 0x0857716C
	.incbin "graphics/stage/main/catch_tile_reveal.gbapal"

@ Lightning strike
gCatchTile_BurstStart_Gfx:: @ 0x0857736C
	.incbin "graphics/stage/main/catch_tile_burst_start.4bpp"
	.space 0x20


@ Tile Grid
gCatchTile_BurstStart_Pal:: @ 0x0857938C
	.incbin "graphics/stage/main/catch_tile_burst_start_eu.gbapal"
gCatchTile_BurstStage2_Gfx:: @ 0x085793AC
	.incbin "graphics/stage/main/catch_tile_burst_stage2.4bpp"
	.space 0x20


gCatchTile_BurstStage2_Pal:: @ 0x08579BCC
	.incbin "graphics/stage/main/catch_tile_burst_stage2_eu.gbapal"
gCatchTile_BurstStage3_Gfx:: @ 0x08579BEC
	.incbin "graphics/stage/main/catch_tile_burst_stage3.4bpp"
	.space 0x20


gCatchTile_BurstStage3_Pal:: @ 0x0857BC0C
	.incbin "graphics/stage/main/catch_tile_burst_stage3_eu.gbapal"
gCatchTile_BurstStage4_Gfx:: @ 0x0857BC2C
	.incbin "graphics/stage/main/catch_tile_burst_stage4.4bpp"
	.space 0x20


gCatchTile_BurstStage4_Pal:: @ 0x0857D44C
	.incbin "graphics/stage/main/catch_tile_burst_stage4_eu.gbapal"
gAerodactlyFlight_Gfx:: @ 0x0857D46C
	.incbin "graphics/stage/ruby/aerodactyl_flight.4bpp"
	.space 0x500
	.incbin "graphics/stage/ruby/aerodactyl_flight_cap.4bpp"

gAerodactlyFlight_Pal:: @ 0x0857E48C
	.incbin "graphics/stage/ruby/aerodactyl_flight.gbapal"

gTotodile_Pal:: @ 0x0857E4AC
	.incbin "graphics/stage/ruby/totodile.gbapal"

gBoardHudTiles_B:: @ 0x0857E68C
	.incbin "graphics/stage/main/board_hud_tiles_b.4bpp"
	.space 0x20

gRubyShopSign_Pal:: @ 0x0857EEAC
	.incbin "graphics/stage/ruby/shopsign.gbapal"

gTravelPortrait_Pal:: @ 0x0857EECC
	.incbin "graphics/stage/main/travel_portrait.gbapal"

gBoardHudTiles_A_En:: @ 0x0857EEEC
gBoardHudTiles_A:: @ 0x0857EEEC
	.incbin "graphics/stage/main/board_hud_tiles_a.4bpp"
	.space 0x20


gBoardHudTiles_A_Fr:: @ 0x0857F30C
	.incbin "graphics/stage/main/board_hud_tiles_a_fr.4bpp"
	.space 0x20
gBoardHudTiles_A_De:: @ 0x0857F72C
	.incbin "graphics/stage/main/board_hud_tiles_a_de.4bpp"
	.space 0x20
gBoardHudTiles_A_It:: @ 0x0857FB4C
	.incbin "graphics/stage/main/board_hud_tiles_a_it.4bpp"
	.space 0x20
gBoardHudTiles_A_Es:: @ 0x0857FF6C
	.incbin "graphics/stage/main/board_hud_tiles_a_es.4bpp"
	.space 0x20
gPortraitAnimFrameGraphics_En:: @ 0x0858038C
	.incbin "graphics/slot_options/slot_options_1_en.4bpp"
	.incbin "graphics/slot_options/slot_options_2_en.4bpp"
	.incbin "graphics/slot_options/slot_options_3_en.4bpp"
	.incbin "graphics/slot_options/slot_options_4_en.4bpp"
	.incbin "graphics/slot_options/slot_options_5_en.4bpp"
	.incbin "graphics/slot_options/slot_options_6_en.4bpp"
	.incbin "graphics/slot_options/slot_options_7_en.4bpp"
	.incbin "graphics/slot_options/slot_options_8_en.4bpp"
	.incbin "graphics/slot_options/slot_options_9_en.4bpp"
	.incbin "graphics/slot_options/slot_options_10_en.4bpp"
	.incbin "graphics/slot_options/slot_options_11_en.4bpp"
	.incbin "graphics/slot_options/slot_options_12_en.4bpp"
	.incbin "graphics/slot_options/slot_options_13_en.4bpp"
	.incbin "graphics/slot_options/slot_options_14_en.4bpp"
	.incbin "graphics/slot_options/slot_options_15_en.4bpp"
	.incbin "graphics/slot_options/slot_options_16_en.4bpp"
	.incbin "graphics/slot_options/slot_options_17_en.4bpp"
	.incbin "graphics/slot_options/slot_options_18_en.4bpp"
	.incbin "graphics/slot_options/slot_options_19_en.4bpp"
	.incbin "graphics/slot_options/slot_options_20_en.4bpp"
	.incbin "graphics/slot_options/slot_options_21_en.4bpp"
	.incbin "graphics/slot_options/slot_options_22_en.4bpp"
	.incbin "graphics/slot_options/slot_options_23_en.4bpp"
	.incbin "graphics/slot_options/slot_options_24_en.4bpp"
	.incbin "graphics/slot_options/slot_options_25_en.4bpp"
	.incbin "graphics/slot_options/slot_options_26_en.4bpp"
	.incbin "graphics/slot_options/slot_options_27_en.4bpp"
	.incbin "graphics/slot_options/slot_options_28_en.4bpp"
	.incbin "graphics/slot_options/slot_options_29_en.4bpp"
	.incbin "graphics/slot_options/slot_options_30_en.4bpp"
	.incbin "graphics/slot_options/slot_options_31_en.4bpp"
	.incbin "graphics/slot_options/slot_options_32_en.4bpp"
	.incbin "graphics/slot_options/slot_options_33_en.4bpp"
	.incbin "graphics/slot_options/slot_options_34_en.4bpp"
	.incbin "graphics/slot_options/slot_options_35_en.4bpp"
	.incbin "graphics/slot_options/slot_options_36_en.4bpp"
	.incbin "graphics/slot_options/slot_options_37_en.4bpp"
	.incbin "graphics/slot_options/slot_options_38_en.4bpp"
	.incbin "graphics/slot_options/slot_options_39_en.4bpp"
	.incbin "graphics/slot_options/slot_options_40_en.4bpp"
	.incbin "graphics/slot_options/slot_options_41_en.4bpp"
	.incbin "graphics/slot_options/slot_options_42_en.4bpp"
	.incbin "graphics/slot_options/slot_options_43_en.4bpp"
	.incbin "graphics/slot_options/slot_options_44_en.4bpp"
	.incbin "graphics/slot_options/slot_options_45_en.4bpp"
	.incbin "graphics/slot_options/slot_options_46_en.4bpp"
	.incbin "graphics/slot_options/slot_options_47_en.4bpp"
	.incbin "graphics/slot_options/slot_options_48_en.4bpp"
	.incbin "graphics/slot_options/slot_options_49_en.4bpp"
	.incbin "graphics/slot_options/slot_options_50_en.4bpp"
	.incbin "graphics/slot_options/slot_options_51_en.4bpp"
	.incbin "graphics/slot_options/slot_options_52_en.4bpp"
	.incbin "graphics/slot_options/slot_options_53_en.4bpp"
	.incbin "graphics/slot_options/slot_options_54_en.4bpp"
	.incbin "graphics/slot_options/slot_options_55_en.4bpp"
	.incbin "graphics/slot_options/slot_options_56_en.4bpp"
	.incbin "graphics/slot_options/slot_options_57_en.4bpp"
	.incbin "graphics/slot_options/slot_options_58_en.4bpp"
	.incbin "graphics/slot_options/slot_options_59_en.4bpp"
	.incbin "graphics/slot_options/slot_options_60_en.4bpp"
	.incbin "graphics/slot_options/slot_options_61_en.4bpp"
	.incbin "graphics/slot_options/slot_options_62_en.4bpp"
	.incbin "graphics/slot_options/slot_options_63_en.4bpp"
	.incbin "graphics/slot_options/slot_options_64_en.4bpp"
	.incbin "graphics/slot_options/slot_options_65_en.4bpp"
	.incbin "graphics/slot_options/slot_options_66_en.4bpp"
	.incbin "graphics/slot_options/slot_options_67_en.4bpp"
	.incbin "graphics/slot_options/slot_options_68_en.4bpp"
	.incbin "graphics/slot_options/slot_options_69_en.4bpp"
	.incbin "graphics/slot_options/slot_options_70_en.4bpp"
	.incbin "graphics/slot_options/slot_options_71_en.4bpp"
	.incbin "graphics/slot_options/slot_options_72_en.4bpp"
	.incbin "graphics/slot_options/slot_options_73_en.4bpp"
	.incbin "graphics/slot_options/slot_options_74_en.4bpp"
	.incbin "graphics/slot_options/slot_options_75_en.4bpp"
	.incbin "graphics/slot_options/slot_options_76_en.4bpp"
	.incbin "graphics/slot_options/slot_options_77_en.4bpp"
	.incbin "graphics/slot_options/slot_options_78_en.4bpp"
	.incbin "graphics/slot_options/slot_options_79_en.4bpp"
	.incbin "graphics/slot_options/slot_options_80_en.4bpp"
	.incbin "graphics/slot_options/slot_options_81_en.4bpp"
	.incbin "graphics/slot_options/slot_options_82_en.4bpp"
	.incbin "graphics/slot_options/slot_options_83_en.4bpp"
	.incbin "graphics/slot_options/slot_options_84_en.4bpp"
	.incbin "graphics/slot_options/slot_options_85_en.4bpp"
	.incbin "graphics/slot_options/slot_options_86_en.4bpp"
	.incbin "graphics/slot_options/slot_options_87_en.4bpp"
	.incbin "graphics/slot_options/slot_options_88_en.4bpp"
	.incbin "graphics/slot_options/slot_options_89_en.4bpp"
	.incbin "graphics/slot_options/slot_options_90_en.4bpp"
	.incbin "graphics/slot_options/slot_options_91_en.4bpp"
	.incbin "graphics/slot_options/slot_options_92_en.4bpp"
	.incbin "graphics/slot_options/slot_options_93_en.4bpp"
	.incbin "graphics/slot_options/slot_options_94_en.4bpp"
	.incbin "graphics/slot_options/slot_options_95_en.4bpp"
	.incbin "graphics/slot_options/slot_options_96_en.4bpp"
gPortraitAnimFrameGraphics_Fr:: @ 0x0859238C
	.incbin "graphics/slot_options/slot_options_1_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_2_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_3_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_4_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_5_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_6_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_7_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_8_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_9_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_10_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_11_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_12_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_13_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_14_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_15_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_16_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_17_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_18_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_19_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_20_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_21_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_22_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_23_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_24_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_25_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_26_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_27_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_28_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_29_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_30_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_31_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_32_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_33_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_34_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_35_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_36_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_37_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_38_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_39_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_40_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_41_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_42_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_43_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_44_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_45_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_46_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_47_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_48_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_49_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_50_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_51_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_52_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_53_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_54_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_55_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_56_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_57_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_58_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_59_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_60_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_61_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_62_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_63_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_64_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_65_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_66_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_67_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_68_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_69_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_70_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_71_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_72_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_73_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_74_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_75_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_76_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_77_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_78_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_79_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_80_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_81_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_82_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_83_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_84_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_85_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_86_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_87_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_88_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_89_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_90_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_91_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_92_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_93_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_94_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_95_fr.4bpp"
	.incbin "graphics/slot_options/slot_options_96_fr.4bpp"
gPortraitAnimFrameGraphics_De:: @ 0x085A438C
	.incbin "graphics/slot_options/slot_options_1_de.4bpp"
	.incbin "graphics/slot_options/slot_options_2_de.4bpp"
	.incbin "graphics/slot_options/slot_options_3_de.4bpp"
	.incbin "graphics/slot_options/slot_options_4_de.4bpp"
	.incbin "graphics/slot_options/slot_options_5_de.4bpp"
	.incbin "graphics/slot_options/slot_options_6_de.4bpp"
	.incbin "graphics/slot_options/slot_options_7_de.4bpp"
	.incbin "graphics/slot_options/slot_options_8_de.4bpp"
	.incbin "graphics/slot_options/slot_options_9_de.4bpp"
	.incbin "graphics/slot_options/slot_options_10_de.4bpp"
	.incbin "graphics/slot_options/slot_options_11_de.4bpp"
	.incbin "graphics/slot_options/slot_options_12_de.4bpp"
	.incbin "graphics/slot_options/slot_options_13_de.4bpp"
	.incbin "graphics/slot_options/slot_options_14_de.4bpp"
	.incbin "graphics/slot_options/slot_options_15_de.4bpp"
	.incbin "graphics/slot_options/slot_options_16_de.4bpp"
	.incbin "graphics/slot_options/slot_options_17_de.4bpp"
	.incbin "graphics/slot_options/slot_options_18_de.4bpp"
	.incbin "graphics/slot_options/slot_options_19_de.4bpp"
	.incbin "graphics/slot_options/slot_options_20_de.4bpp"
	.incbin "graphics/slot_options/slot_options_21_de.4bpp"
	.incbin "graphics/slot_options/slot_options_22_de.4bpp"
	.incbin "graphics/slot_options/slot_options_23_de.4bpp"
	.incbin "graphics/slot_options/slot_options_24_de.4bpp"
	.incbin "graphics/slot_options/slot_options_25_de.4bpp"
	.incbin "graphics/slot_options/slot_options_26_de.4bpp"
	.incbin "graphics/slot_options/slot_options_27_de.4bpp"
	.incbin "graphics/slot_options/slot_options_28_de.4bpp"
	.incbin "graphics/slot_options/slot_options_29_de.4bpp"
	.incbin "graphics/slot_options/slot_options_30_de.4bpp"
	.incbin "graphics/slot_options/slot_options_31_de.4bpp"
	.incbin "graphics/slot_options/slot_options_32_de.4bpp"
	.incbin "graphics/slot_options/slot_options_33_de.4bpp"
	.incbin "graphics/slot_options/slot_options_34_de.4bpp"
	.incbin "graphics/slot_options/slot_options_35_de.4bpp"
	.incbin "graphics/slot_options/slot_options_36_de.4bpp"
	.incbin "graphics/slot_options/slot_options_37_de.4bpp"
	.incbin "graphics/slot_options/slot_options_38_de.4bpp"
	.incbin "graphics/slot_options/slot_options_39_de.4bpp"
	.incbin "graphics/slot_options/slot_options_40_de.4bpp"
	.incbin "graphics/slot_options/slot_options_41_de.4bpp"
	.incbin "graphics/slot_options/slot_options_42_de.4bpp"
	.incbin "graphics/slot_options/slot_options_43_de.4bpp"
	.incbin "graphics/slot_options/slot_options_44_de.4bpp"
	.incbin "graphics/slot_options/slot_options_45_de.4bpp"
	.incbin "graphics/slot_options/slot_options_46_de.4bpp"
	.incbin "graphics/slot_options/slot_options_47_de.4bpp"
	.incbin "graphics/slot_options/slot_options_48_de.4bpp"
	.incbin "graphics/slot_options/slot_options_49_de.4bpp"
	.incbin "graphics/slot_options/slot_options_50_de.4bpp"
	.incbin "graphics/slot_options/slot_options_51_de.4bpp"
	.incbin "graphics/slot_options/slot_options_52_de.4bpp"
	.incbin "graphics/slot_options/slot_options_53_de.4bpp"
	.incbin "graphics/slot_options/slot_options_54_de.4bpp"
	.incbin "graphics/slot_options/slot_options_55_de.4bpp"
	.incbin "graphics/slot_options/slot_options_56_de.4bpp"
	.incbin "graphics/slot_options/slot_options_57_de.4bpp"
	.incbin "graphics/slot_options/slot_options_58_de.4bpp"
	.incbin "graphics/slot_options/slot_options_59_de.4bpp"
	.incbin "graphics/slot_options/slot_options_60_de.4bpp"
	.incbin "graphics/slot_options/slot_options_61_de.4bpp"
	.incbin "graphics/slot_options/slot_options_62_de.4bpp"
	.incbin "graphics/slot_options/slot_options_63_de.4bpp"
	.incbin "graphics/slot_options/slot_options_64_de.4bpp"
	.incbin "graphics/slot_options/slot_options_65_de.4bpp"
	.incbin "graphics/slot_options/slot_options_66_de.4bpp"
	.incbin "graphics/slot_options/slot_options_67_de.4bpp"
	.incbin "graphics/slot_options/slot_options_68_de.4bpp"
	.incbin "graphics/slot_options/slot_options_69_de.4bpp"
	.incbin "graphics/slot_options/slot_options_70_de.4bpp"
	.incbin "graphics/slot_options/slot_options_71_de.4bpp"
	.incbin "graphics/slot_options/slot_options_72_de.4bpp"
	.incbin "graphics/slot_options/slot_options_73_de.4bpp"
	.incbin "graphics/slot_options/slot_options_74_de.4bpp"
	.incbin "graphics/slot_options/slot_options_75_de.4bpp"
	.incbin "graphics/slot_options/slot_options_76_de.4bpp"
	.incbin "graphics/slot_options/slot_options_77_de.4bpp"
	.incbin "graphics/slot_options/slot_options_78_de.4bpp"
	.incbin "graphics/slot_options/slot_options_79_de.4bpp"
	.incbin "graphics/slot_options/slot_options_80_de.4bpp"
	.incbin "graphics/slot_options/slot_options_81_de.4bpp"
	.incbin "graphics/slot_options/slot_options_82_de.4bpp"
	.incbin "graphics/slot_options/slot_options_83_de.4bpp"
	.incbin "graphics/slot_options/slot_options_84_de.4bpp"
	.incbin "graphics/slot_options/slot_options_85_de.4bpp"
	.incbin "graphics/slot_options/slot_options_86_de.4bpp"
	.incbin "graphics/slot_options/slot_options_87_de.4bpp"
	.incbin "graphics/slot_options/slot_options_88_de.4bpp"
	.incbin "graphics/slot_options/slot_options_89_de.4bpp"
	.incbin "graphics/slot_options/slot_options_90_de.4bpp"
	.incbin "graphics/slot_options/slot_options_91_de.4bpp"
	.incbin "graphics/slot_options/slot_options_92_de.4bpp"
	.incbin "graphics/slot_options/slot_options_93_de.4bpp"
	.incbin "graphics/slot_options/slot_options_94_de.4bpp"
	.incbin "graphics/slot_options/slot_options_95_de.4bpp"
	.incbin "graphics/slot_options/slot_options_96_de.4bpp"
gPortraitAnimFrameGraphics_It:: @ 0x085B638C
	.incbin "graphics/slot_options/slot_options_1_it.4bpp"
	.incbin "graphics/slot_options/slot_options_2_it.4bpp"
	.incbin "graphics/slot_options/slot_options_3_it.4bpp"
	.incbin "graphics/slot_options/slot_options_4_it.4bpp"
	.incbin "graphics/slot_options/slot_options_5_it.4bpp"
	.incbin "graphics/slot_options/slot_options_6_it.4bpp"
	.incbin "graphics/slot_options/slot_options_7_it.4bpp"
	.incbin "graphics/slot_options/slot_options_8_it.4bpp"
	.incbin "graphics/slot_options/slot_options_9_it.4bpp"
	.incbin "graphics/slot_options/slot_options_10_it.4bpp"
	.incbin "graphics/slot_options/slot_options_11_it.4bpp"
	.incbin "graphics/slot_options/slot_options_12_it.4bpp"
	.incbin "graphics/slot_options/slot_options_13_it.4bpp"
	.incbin "graphics/slot_options/slot_options_14_it.4bpp"
	.incbin "graphics/slot_options/slot_options_15_it.4bpp"
	.incbin "graphics/slot_options/slot_options_16_it.4bpp"
	.incbin "graphics/slot_options/slot_options_17_it.4bpp"
	.incbin "graphics/slot_options/slot_options_18_it.4bpp"
	.incbin "graphics/slot_options/slot_options_19_it.4bpp"
	.incbin "graphics/slot_options/slot_options_20_it.4bpp"
	.incbin "graphics/slot_options/slot_options_21_it.4bpp"
	.incbin "graphics/slot_options/slot_options_22_it.4bpp"
	.incbin "graphics/slot_options/slot_options_23_it.4bpp"
	.incbin "graphics/slot_options/slot_options_24_it.4bpp"
	.incbin "graphics/slot_options/slot_options_25_it.4bpp"
	.incbin "graphics/slot_options/slot_options_26_it.4bpp"
	.incbin "graphics/slot_options/slot_options_27_it.4bpp"
	.incbin "graphics/slot_options/slot_options_28_it.4bpp"
	.incbin "graphics/slot_options/slot_options_29_it.4bpp"
	.incbin "graphics/slot_options/slot_options_30_it.4bpp"
	.incbin "graphics/slot_options/slot_options_31_it.4bpp"
	.incbin "graphics/slot_options/slot_options_32_it.4bpp"
	.incbin "graphics/slot_options/slot_options_33_it.4bpp"
	.incbin "graphics/slot_options/slot_options_34_it.4bpp"
	.incbin "graphics/slot_options/slot_options_35_it.4bpp"
	.incbin "graphics/slot_options/slot_options_36_it.4bpp"
	.incbin "graphics/slot_options/slot_options_37_it.4bpp"
	.incbin "graphics/slot_options/slot_options_38_it.4bpp"
	.incbin "graphics/slot_options/slot_options_39_it.4bpp"
	.incbin "graphics/slot_options/slot_options_40_it.4bpp"
	.incbin "graphics/slot_options/slot_options_41_it.4bpp"
	.incbin "graphics/slot_options/slot_options_42_it.4bpp"
	.incbin "graphics/slot_options/slot_options_43_it.4bpp"
	.incbin "graphics/slot_options/slot_options_44_it.4bpp"
	.incbin "graphics/slot_options/slot_options_45_it.4bpp"
	.incbin "graphics/slot_options/slot_options_46_it.4bpp"
	.incbin "graphics/slot_options/slot_options_47_it.4bpp"
	.incbin "graphics/slot_options/slot_options_48_it.4bpp"
	.incbin "graphics/slot_options/slot_options_49_it.4bpp"
	.incbin "graphics/slot_options/slot_options_50_it.4bpp"
	.incbin "graphics/slot_options/slot_options_51_it.4bpp"
	.incbin "graphics/slot_options/slot_options_52_it.4bpp"
	.incbin "graphics/slot_options/slot_options_53_it.4bpp"
	.incbin "graphics/slot_options/slot_options_54_it.4bpp"
	.incbin "graphics/slot_options/slot_options_55_it.4bpp"
	.incbin "graphics/slot_options/slot_options_56_it.4bpp"
	.incbin "graphics/slot_options/slot_options_57_it.4bpp"
	.incbin "graphics/slot_options/slot_options_58_it.4bpp"
	.incbin "graphics/slot_options/slot_options_59_it.4bpp"
	.incbin "graphics/slot_options/slot_options_60_it.4bpp"
	.incbin "graphics/slot_options/slot_options_61_it.4bpp"
	.incbin "graphics/slot_options/slot_options_62_it.4bpp"
	.incbin "graphics/slot_options/slot_options_63_it.4bpp"
	.incbin "graphics/slot_options/slot_options_64_it.4bpp"
	.incbin "graphics/slot_options/slot_options_65_it.4bpp"
	.incbin "graphics/slot_options/slot_options_66_it.4bpp"
	.incbin "graphics/slot_options/slot_options_67_it.4bpp"
	.incbin "graphics/slot_options/slot_options_68_it.4bpp"
	.incbin "graphics/slot_options/slot_options_69_it.4bpp"
	.incbin "graphics/slot_options/slot_options_70_it.4bpp"
	.incbin "graphics/slot_options/slot_options_71_it.4bpp"
	.incbin "graphics/slot_options/slot_options_72_it.4bpp"
	.incbin "graphics/slot_options/slot_options_73_it.4bpp"
	.incbin "graphics/slot_options/slot_options_74_it.4bpp"
	.incbin "graphics/slot_options/slot_options_75_it.4bpp"
	.incbin "graphics/slot_options/slot_options_76_it.4bpp"
	.incbin "graphics/slot_options/slot_options_77_it.4bpp"
	.incbin "graphics/slot_options/slot_options_78_it.4bpp"
	.incbin "graphics/slot_options/slot_options_79_it.4bpp"
	.incbin "graphics/slot_options/slot_options_80_it.4bpp"
	.incbin "graphics/slot_options/slot_options_81_it.4bpp"
	.incbin "graphics/slot_options/slot_options_82_it.4bpp"
	.incbin "graphics/slot_options/slot_options_83_it.4bpp"
	.incbin "graphics/slot_options/slot_options_84_it.4bpp"
	.incbin "graphics/slot_options/slot_options_85_it.4bpp"
	.incbin "graphics/slot_options/slot_options_86_it.4bpp"
	.incbin "graphics/slot_options/slot_options_87_it.4bpp"
	.incbin "graphics/slot_options/slot_options_88_it.4bpp"
	.incbin "graphics/slot_options/slot_options_89_it.4bpp"
	.incbin "graphics/slot_options/slot_options_90_it.4bpp"
	.incbin "graphics/slot_options/slot_options_91_it.4bpp"
	.incbin "graphics/slot_options/slot_options_92_it.4bpp"
	.incbin "graphics/slot_options/slot_options_93_it.4bpp"
	.incbin "graphics/slot_options/slot_options_94_it.4bpp"
	.incbin "graphics/slot_options/slot_options_95_it.4bpp"
	.incbin "graphics/slot_options/slot_options_96_it.4bpp"
gPortraitAnimFrameGraphics_Es:: @ 0x085C838C
	.incbin "graphics/slot_options/slot_options_1_es.4bpp"
	.incbin "graphics/slot_options/slot_options_2_es.4bpp"
	.incbin "graphics/slot_options/slot_options_3_es.4bpp"
	.incbin "graphics/slot_options/slot_options_4_es.4bpp"
	.incbin "graphics/slot_options/slot_options_5_es.4bpp"
	.incbin "graphics/slot_options/slot_options_6_es.4bpp"
	.incbin "graphics/slot_options/slot_options_7_es.4bpp"
	.incbin "graphics/slot_options/slot_options_8_es.4bpp"
	.incbin "graphics/slot_options/slot_options_9_es.4bpp"
	.incbin "graphics/slot_options/slot_options_10_es.4bpp"
	.incbin "graphics/slot_options/slot_options_11_es.4bpp"
	.incbin "graphics/slot_options/slot_options_12_es.4bpp"
	.incbin "graphics/slot_options/slot_options_13_es.4bpp"
	.incbin "graphics/slot_options/slot_options_14_es.4bpp"
	.incbin "graphics/slot_options/slot_options_15_es.4bpp"
	.incbin "graphics/slot_options/slot_options_16_es.4bpp"
	.incbin "graphics/slot_options/slot_options_17_es.4bpp"
	.incbin "graphics/slot_options/slot_options_18_es.4bpp"
	.incbin "graphics/slot_options/slot_options_19_es.4bpp"
	.incbin "graphics/slot_options/slot_options_20_es.4bpp"
	.incbin "graphics/slot_options/slot_options_21_es.4bpp"
	.incbin "graphics/slot_options/slot_options_22_es.4bpp"
	.incbin "graphics/slot_options/slot_options_23_es.4bpp"
	.incbin "graphics/slot_options/slot_options_24_es.4bpp"
	.incbin "graphics/slot_options/slot_options_25_es.4bpp"
	.incbin "graphics/slot_options/slot_options_26_es.4bpp"
	.incbin "graphics/slot_options/slot_options_27_es.4bpp"
	.incbin "graphics/slot_options/slot_options_28_es.4bpp"
	.incbin "graphics/slot_options/slot_options_29_es.4bpp"
	.incbin "graphics/slot_options/slot_options_30_es.4bpp"
	.incbin "graphics/slot_options/slot_options_31_es.4bpp"
	.incbin "graphics/slot_options/slot_options_32_es.4bpp"
	.incbin "graphics/slot_options/slot_options_33_es.4bpp"
	.incbin "graphics/slot_options/slot_options_34_es.4bpp"
	.incbin "graphics/slot_options/slot_options_35_es.4bpp"
	.incbin "graphics/slot_options/slot_options_36_es.4bpp"
	.incbin "graphics/slot_options/slot_options_37_es.4bpp"
	.incbin "graphics/slot_options/slot_options_38_es.4bpp"
	.incbin "graphics/slot_options/slot_options_39_es.4bpp"
	.incbin "graphics/slot_options/slot_options_40_es.4bpp"
	.incbin "graphics/slot_options/slot_options_41_es.4bpp"
	.incbin "graphics/slot_options/slot_options_42_es.4bpp"
	.incbin "graphics/slot_options/slot_options_43_es.4bpp"
	.incbin "graphics/slot_options/slot_options_44_es.4bpp"
	.incbin "graphics/slot_options/slot_options_45_es.4bpp"
	.incbin "graphics/slot_options/slot_options_46_es.4bpp"
	.incbin "graphics/slot_options/slot_options_47_es.4bpp"
	.incbin "graphics/slot_options/slot_options_48_es.4bpp"
	.incbin "graphics/slot_options/slot_options_49_es.4bpp"
	.incbin "graphics/slot_options/slot_options_50_es.4bpp"
	.incbin "graphics/slot_options/slot_options_51_es.4bpp"
	.incbin "graphics/slot_options/slot_options_52_es.4bpp"
	.incbin "graphics/slot_options/slot_options_53_es.4bpp"
	.incbin "graphics/slot_options/slot_options_54_es.4bpp"
	.incbin "graphics/slot_options/slot_options_55_es.4bpp"
	.incbin "graphics/slot_options/slot_options_56_es.4bpp"
	.incbin "graphics/slot_options/slot_options_57_es.4bpp"
	.incbin "graphics/slot_options/slot_options_58_es.4bpp"
	.incbin "graphics/slot_options/slot_options_59_es.4bpp"
	.incbin "graphics/slot_options/slot_options_60_es.4bpp"
	.incbin "graphics/slot_options/slot_options_61_es.4bpp"
	.incbin "graphics/slot_options/slot_options_62_es.4bpp"
	.incbin "graphics/slot_options/slot_options_63_es.4bpp"
	.incbin "graphics/slot_options/slot_options_64_es.4bpp"
	.incbin "graphics/slot_options/slot_options_65_es.4bpp"
	.incbin "graphics/slot_options/slot_options_66_es.4bpp"
	.incbin "graphics/slot_options/slot_options_67_es.4bpp"
	.incbin "graphics/slot_options/slot_options_68_es.4bpp"
	.incbin "graphics/slot_options/slot_options_69_es.4bpp"
	.incbin "graphics/slot_options/slot_options_70_es.4bpp"
	.incbin "graphics/slot_options/slot_options_71_es.4bpp"
	.incbin "graphics/slot_options/slot_options_72_es.4bpp"
	.incbin "graphics/slot_options/slot_options_73_es.4bpp"
	.incbin "graphics/slot_options/slot_options_74_es.4bpp"
	.incbin "graphics/slot_options/slot_options_75_es.4bpp"
	.incbin "graphics/slot_options/slot_options_76_es.4bpp"
	.incbin "graphics/slot_options/slot_options_77_es.4bpp"
	.incbin "graphics/slot_options/slot_options_78_es.4bpp"
	.incbin "graphics/slot_options/slot_options_79_es.4bpp"
	.incbin "graphics/slot_options/slot_options_80_es.4bpp"
	.incbin "graphics/slot_options/slot_options_81_es.4bpp"
	.incbin "graphics/slot_options/slot_options_82_es.4bpp"
	.incbin "graphics/slot_options/slot_options_83_es.4bpp"
	.incbin "graphics/slot_options/slot_options_84_es.4bpp"
	.incbin "graphics/slot_options/slot_options_85_es.4bpp"
	.incbin "graphics/slot_options/slot_options_86_es.4bpp"
	.incbin "graphics/slot_options/slot_options_87_es.4bpp"
	.incbin "graphics/slot_options/slot_options_88_es.4bpp"
	.incbin "graphics/slot_options/slot_options_89_es.4bpp"
	.incbin "graphics/slot_options/slot_options_90_es.4bpp"
	.incbin "graphics/slot_options/slot_options_91_es.4bpp"
	.incbin "graphics/slot_options/slot_options_92_es.4bpp"
	.incbin "graphics/slot_options/slot_options_93_es.4bpp"
	.incbin "graphics/slot_options/slot_options_94_es.4bpp"
	.incbin "graphics/slot_options/slot_options_95_es.4bpp"
	.incbin "graphics/slot_options/slot_options_96_es.4bpp"
gBallRotationTileGraphics:: @ 0x085DA38C
	.incbin "graphics/stage/main/pokeball_regular.4bpp"
	.incbin "graphics/stage/main/pokeball_great.4bpp"
	.incbin "graphics/stage/main/pokeball_ultra.4bpp"
	.incbin "graphics/stage/main/pokeball_master.4bpp"

gBallUpgradeFx_Gfx:: @ 0x085DC58C
	.incbin "graphics/stage/main/ball_upgrade_fx_frames.4bpp"

gBallSpawnGlowTiles_Type2:: @ 0x085DD18C
	.incbin "graphics/stage/main/ball_spawn_glow_type2.4bpp"

gBallSpawnGlowTiles_Type1:: @ 0x085DE38C
	.incbin "graphics/stage/main/ball_spawn_glow_type1.4bpp"

gSpoinkEntity_Gfx:: @ 0x085DF98C
	.incbin "graphics/stage/main/spoink_launcher.4bpp"

gKyogreSurfacingFx_Gfx:: @ 0x085E05CC
	.incbin "graphics/stage/kyogre/surfacing_fx_frames.4bpp"

gKyogreFreeze_Gfx:: @ 0x085E0C8C
	.incbin "graphics/stage/kyogre/freeze_trap_frames.4bpp"

gRubyChikoritaEntity:: @ 0x085E2E4C
	.incbin "graphics/stage/ruby/chikorita_frames.4bpp"

gChikoritaProjectileTiles:: @ 0x085E464C
	.incbin "graphics/stage/ruby/chikorita_projectile.4bpp"

@ Used when the leaf blade hits one of the linoone
gChikoritaExplosionTiles:: @ 0x085E484C
	.incbin "graphics/stage/ruby/chikorita_projectile_fx.4bpp"

@ Clouds from the intro sequence
gRayquazaSkyBackgroundGfx:: @ 0x085E4C4C
	.incbin "graphics/stage/rayquaza/sky_background.4bpp"

gChinchouBumper_Gfx:: @ 0x085E728C
	.incbin "graphics/stage/main/chinchou_bumper.4bpp"

.include "data/graphics/mon_hatch_sprites.inc"

gPickupIcon1_Gfx:: @ 0x0860AA6C
	.incbin "graphics/board_pickups/icon1_xp.4bpp"
gPickupIcon1_Gfx_De:: @ 0x0860C86C
	.incbin "graphics/board_pickups/icon1_xp_de.4bpp"
gPickupIcon1_Gfx_It:: @ 0x0860E66C
	.incbin "graphics/board_pickups/icon1_xp_it.4bpp"
gPickupIcon1_Gfx_Es:: @ 0x0861046C
	.incbin "graphics/board_pickups/icon1_xp_es.4bpp"
gPickupIcon2_Gfx:: @ 0x0861226C
	.incbin "graphics/board_pickups/icon2_leaf.4bpp"
gPickupIcon3_Gfx:: @ 0x0861406C
	.incbin "graphics/board_pickups/icon3_fire.4bpp"
gPickupIcon9_Gfx:: @ 0x08615E6C
	.incbin "graphics/board_pickups/icon9_heart.4bpp"
gPickupIcon4_Gfx:: @ 0x08617C6C
	.incbin "graphics/board_pickups/icon4_link.4bpp"
gPickupIcon5_Gfx:: @ 0x08619A6C
	.incbin "graphics/board_pickups/icon5_moon.4bpp"
gPickupIcon6_Gfx:: @ 0x0861B86C
	.incbin "graphics/board_pickups/icon6_water.4bpp"
gPickupIcon10_Gfx:: @ 0x0861D66C
	.incbin "graphics/board_pickups/icon10_pokeblock.4bpp"
gPickupIcon8_Gfx:: @ 0x0861F46C
	.incbin "graphics/board_pickups/icon8_sun.4bpp"
gPickupIcon7_Gfx:: @ 0x0862126C
	.incbin "graphics/board_pickups/icon7_bolt.4bpp"

gFlipper_Gfx:: @ 0x0862306C
	.incbin "graphics/stage/main/flipper_frames.4bpp"

gAlphabetTilesGfx:: @ 0x08623C6C
	.incbin "graphics/stage/main/alphabet.4bpp"

gAlphabetExclamationMark_Gfx:: @ 0x0862496C
	.incbin "graphics/stage/main/alphabet_exclamation_mark.4bpp"
gSpaceTileGfx:: @ 0x086249AC
	.space 0x40  @ Note: this 0x40 space is required, and is used as a tile pair.

gSapphireBoardWailmer_Gfx:: @ 0x086249EC
	.incbin "graphics/stage/sapphire/wailmer.4bpp";

.include "data/graphics/mon_catch_sprites.inc"

gRubyStageGulpin_Gfx:: @ 0x0866C6EC
	.incbin "graphics/stage/ruby/gulpin.4bpp"

gMainStageBonusTrap_Gfx:: @ 0x0866CFEC
	.incbin "graphics/stage/main/bonus_trap.4bpp"

gLotadBumper_Gfx:: @ 0x0866DEEC
	.incbin "graphics/stage/main/lotad_bumper.4bpp"

gRubyStageCyndaquil_Gfx:: @ 0x0866E9EC
	.incbin "graphics/stage/ruby/cyndaquil.4bpp"

gJirachiFx_Gfx:: @ 0x0866F66C
	.incbin "graphics/stage/main/jirachi_fx.4bpp"

gSapphireStageBasket_Gfx:: @ 0x08673E6C
	.incbin "graphics/stage/sapphire/seedot_basket.4bpp"

gKecleonStageKecleon_Gfx:: @ 0x086745EC
	.incbin "graphics/stage/kecleon/kecleon.4bpp"

gKecleonStageKecleonFx_Gfx:: @ 0x0867A4EC
	.incbin "graphics/stage/kecleon/kecleon_fx.4bpp"

gOneUpTreeckoSprite_Gfx:: @ 0x0867AAEC
	.incbin "graphics/stage/misc/treecko_1_up_deliverer.4bpp"

gLifeCountDigit_Gfx:: @ 0x0867B0EC
	.incbin "graphics/stage/misc/life_count_digit.4bpp"

gShroomishBumperHit_Gfx:: @ 0x0867B56C
	.incbin "graphics/stage/sapphire/shroomish_bumper_hit.4bpp"

gRubyStageNuzleaf_Gfx:: @ 0x0867BD6C
	.incbin "graphics/stage/ruby/nuzleaf.4bpp"

gHatchMachineSparkleFx_Gfx:: @ 0x0867ECEC
	.incbin "graphics/stage/sapphire/hatch_machine_spark_fx.4bpp"

gRubyIntroSprites_Gfx:: @ 0x0867F0EC
	.incbin "graphics/stage/ruby/intro_sprite.4bpp"

gSapphireIntroSprites_Gfx:: @ 0x0868464C
	.incbin "graphics/stage/sapphire/intro_sprite.4bpp"

gDusclopsIntroSprite_Gfx:: @ 0x08689BAC
	.incbin "graphics/stage/dusclops/intro_sprite.4bpp";

gKecleonIntroSprite_Gfx:: @ 0x0868C24C
	.incbin "graphics/stage/kecleon/intro_sprite.4bpp";

gKyogreIntroSprite_Gfx:: @ 0x0868F06C
	.incbin "graphics/stage/kyogre/intro_sprite.4bpp"

gGroudonIntroSprite_Gfx:: @ 0x08691F0C
	.incbin "graphics/stage/groudon/intro_sprite.4bpp"

gRayquazaIntroSprite_Gfx:: @ 0x086976CC
	.incbin "graphics/stage/rayquaza/intro_sprite.4bpp"

gSphealIntroSprites_Gfx:: @ 0x0869C64C
	.incbin "graphics/stage/spheal/intro_sprite.4bpp"

gSapphireMinun_Gfx:: @ 0x0869F06C
	.incbin "graphics/stage/sapphire/bumper_minun.4bpp"

gSapphireMinunHeadElectricity_Gfx:: @ 0x086A1D6C
	.incbin "graphics/stage/sapphire/bumper_minun_fx.4bpp"

gRubyMakuhitaGfx:: @ 0x086A2B6C
	.incbin "graphics/stage/ruby/makuhita.4bpp"

gLinooneBumperGfx:: @ 0x086A496C
	.incbin "graphics/stage/ruby/linoone_side_bumper.4bpp"

@ Shop selection change sheen, and "SOLD OUT" banner.
gShopPortraitOverlayGfx_En:: @ 0x086A4B6C
gShopPortraitOverlayGfx:: @ 0x086A4B6C
	.incbin "graphics/stage/main/shop_portrait_overlay.4bpp"

gShopPortraitOverlayGfx_Fr:: @ 0x086A5A6C
	.incbin "graphics/stage/main/shop_portrait_overlay_fr.4bpp"
gShopPortraitOverlayGfx_De:: @ 0x086A696C
	.incbin "graphics/stage/main/shop_portrait_overlay_de.4bpp"
gShopPortraitOverlayGfx_It:: @ 0x086A786C
	.incbin "graphics/stage/main/shop_portrait_overlay_it.4bpp"
gShopPortraitOverlayGfx_Es:: @ 0x086A876C
	.incbin "graphics/stage/main/shop_portrait_overlay_es.4bpp"
gDecimalDigitTilesGfx:: @ 0x086A966C
	.incbin "graphics/stage/main/decimal_digits.4bpp"

gSapphireShopSignTileGfx_En:: @ 0x086A98EC
gSapphireShopSignTileGfx:: @ 0x086A98EC
	.incbin "graphics/stage/sapphire/shop_sign_tiles.4bpp"

gSapphireShopSignTileGfx_Fr:: @ 0x086AC5EC
	.incbin "graphics/stage/sapphire/shop_sign_tiles_fr.4bpp"
gSapphireShopSignTileGfx_De:: @ 0x086AF2EC
	.incbin "graphics/stage/sapphire/shop_sign_tiles_de.4bpp"
gSapphireShopSignTileGfx_It:: @ 0x086B1FEC
	.incbin "graphics/stage/sapphire/shop_sign_tiles_it.4bpp"
gSapphireShopSignTileGfx_Es:: @ 0x086B4CEC
	.incbin "graphics/stage/sapphire/shop_sign_tiles_es.4bpp"
gRubyTravelVolbeat_Gfx:: @ 0x086B79EC
	.incbin "graphics/stage/ruby/travel_volbeat.4bpp"

gSapphireTravelIllumise_Gfx:: @ 0x086BC66C
	.incbin "graphics/stage/sapphire/travel_illumise.4bpp"

gLocationPortraitGfx:: @ 0x086C12EC
	.incbin "graphics/area_portraits/loc00_ruby_forest.4bpp"
	.incbin "graphics/area_portraits/loc01_sapphire_forest.4bpp"
	.incbin "graphics/area_portraits/loc02_ruby_plains.4bpp"
	.incbin "graphics/area_portraits/loc03_sapphire_plains.4bpp"
	.incbin "graphics/area_portraits/loc04_ruby_harbor.4bpp"
	.incbin "graphics/area_portraits/loc05_sapphire_beach.4bpp"
	.incbin "graphics/area_portraits/loc06_ruby_cave.4bpp"
	.incbin "graphics/area_portraits/loc07_sapphire_cave.4bpp"
	.incbin "graphics/area_portraits/loc08_ruby_safari_zone.4bpp"
	.incbin "graphics/area_portraits/loc09_ruby_volcano.4bpp"
	.incbin "graphics/area_portraits/loc10_sapphire_lake.4bpp"
	.incbin "graphics/area_portraits/loc11_sapphire_desert.4bpp"
	.incbin "graphics/area_portraits/loc12_ruins.4bpp"

@ Includes the rope tiles, totodile, and egg
gTotodileEggDelivery_Gfx:: @ 0x086C39EC
	.incbin "graphics/stage/ruby/totodile.4bpp"

gHatchMachineElevator_Gfx:: @ 0x086C46AC
	.incbin "graphics/stage/sapphire/hatch_machine_elevator.4bpp"

gDusclopsBoardDusclopsAppearFx_Gfx:: @ 0x086C8AAC
	.incbin "graphics/stage/dusclops/dusclops_appear_fx.4bpp";

gKyogreTopPosition_Gfx:: @ 0x086CA2AC
	.incbin "graphics/stage/kyogre/kyogre_top.4bpp"

gKyogreBreach_Gfx:: @ 0x086CF52C
	.incbin "graphics/stage/kyogre/kyogre_breach.4bpp"

gGroudonAttackFx_Gfx:: @ 0x086D2E2C
	.incbin "graphics/stage/groudon/board_fx.4bpp"
	.space 0x20

gGroudonBoardBoulders_Gfx:: @ 0x086D4E4C
	.incbin "graphics/stage/groudon/boulders.4bpp";

gRayquazaTornadoGfx:: @ 0x086DAB4C
	.incbin "graphics/stage/rayquaza/tornado_frames.4bpp"

gRayquazaFlyby_Gfx:: @ 0x086DC1CC
	.incbin "graphics/stage/rayquaza/wind_board.4bpp"
	.space 0x20

gRayquazaSpriteSheet:: @ 0x086DDDEC
	.incbin "graphics/stage/rayquaza/entity_flying.4bpp"

gRayquazaBodyVariantTiles:: @ 0x086DE64C
	.incbin "graphics/stage/rayquaza/body_variants.4bpp"

gSphealNetGfx:: @ 0x086E364C
	.incbin "graphics/stage/spheal/spheal_net.4bpp"

gSphealNetFrontGfx:: @ 0x086E3C4C
	.incbin "graphics/stage/spheal/spheal_net_front.4bpp"

gSphealEntitySprites:: @ 0x086E40CC
	.incbin "graphics/stage/spheal/spheal.4bpp"

gSealeoEntitySprites:: @ 0x086E844C
	.incbin "graphics/stage/spheal/sealeo.4bpp"

gSphealResultsScreenGfx_EnFr:: @ 0x086EB44C
gSphealResultsScreenGfx:: @ 0x086EB44C
	.incbin "graphics/stage/spheal/spheal_results.4bpp"

gSphealResultsScreenGfx_De:: @ 0x086EBC4C
	.incbin "graphics/stage/spheal/spheal_results_de.4bpp"
gSphealResultsScreenGfx_It:: @ 0x086EC44C
	.incbin "graphics/stage/spheal/spheal_results_it.4bpp"
gSphealResultsScreenGfx_Es:: @ 0x086ECC4C
	.incbin "graphics/stage/spheal/spheal_results_es.4bpp"
gWhiscash_Gfx:: @ 0x086ED44C
	.incbin "graphics/stage/ruby/whiscash.4bpp"

gPelipper_Gfx:: @ 0x086F05CC
	.incbin "graphics/stage/sapphire/pelipper.4bpp"
	.incbin "graphics/stage/sapphire/charger.4bpp"

gChargeFillIndicator_Gfx:: @ 0x086F554C
	.incbin "graphics/stage/main/charge_fill_indicator.4bpp"

gPikachuSaverTilesGfx:: @ 0x086F5C4C
	.incbin "graphics/stage/main/pikachu_saver_tiles.4bpp"

gDxModePikachuObjTiles:: @ 0x086F60CC
	.incbin "graphics/stage/main/dx_mode_pikachu_obj_tiles.4bpp"

gPichuSaverTilesGfx:: @ 0x086F69CC
	.incbin "graphics/stage/main/pichu_saver_tiles.4bpp"

gSapphirePlusle_Gfx:: @ 0x086F72CC
	.incbin "graphics/stage/sapphire/bumper_plusle.4bpp"

gSapphirePlusleHeadElectricity_Gfx:: @ 0x086F9FCC
	.incbin "graphics/stage/sapphire/bumper_plusle_fx.4bpp"

.include "data/graphics/mon_portraits.inc"
gRubyBoardShopDoor_Gfx:: @ 0x087223CC
	.incbin "graphics/stage/ruby/shop_door.4bpp";


gZigzagoonShockWallIndicator_Gfx:: @ 0x087229CC
	.incbin "graphics/stage/sapphire/zigzagoon_press_button_indicator_eu.4bpp"
gDusclopsBoardDusclops_Gfx:: @ 0x087239CC
	.incbin "graphics/stage/dusclops/dusclops.4bpp";

gRubyBoardSharpedo_Gfx:: @ 0x0872B9CC
	.incbin "graphics/stage/ruby/sharpedo.4bpp";

gMartEvoForegroundMenuUx_Gfx:: @ 0x0872C0EC
	.incbin "graphics/stage/main/mart_evo_menu_foreground.4bpp";

gMartEvoForegroundMenuUx_Gfx_De:: @ 0x0872CA0C
	.incbin "graphics/stage/main/mart_evo_menu_foreground_de.4bpp"
gRubyBoardShop_Gfx_En:: @ 0x0872D32C
gRubyBoardShop_Gfx:: @ 0x0872D32C
	.incbin "graphics/stage/ruby/shop.4bpp";

gRubyBoardShop_Gfx_Fr:: @ 0x08730A2C
	.incbin "graphics/stage/ruby/shop_fr.4bpp"
gRubyBoardShop_Gfx_De:: @ 0x0873412C
	.incbin "graphics/stage/ruby/shop_de.4bpp"
gRubyBoardShop_Gfx_It:: @ 0x0873782C
	.incbin "graphics/stage/ruby/shop_it.4bpp"
gRubyBoardShop_Gfx_Es:: @ 0x0873AF2C
	.incbin "graphics/stage/ruby/shop_es.4bpp"
gAreaRouletteSelectedFx_Gfx:: @ 0x0873E62C
	.incbin "graphics/stage/main/area_roulette_selected_fx.4bpp";

gMainBoardPikaSpinner_Gfx:: @ 0x0873E8AC
	.incbin "graphics/stage/main/pika_spinner.4bpp";

gRubyBoardHatchCave_Gfx:: @ 0x0873FAAC
	.incbin "graphics/stage/ruby/hatch_cave.4bpp";

gEggFrameTilesGfx:: @ 0x087415AC
	.incbin "graphics/stage/main/egg.4bpp";

gSapphireBoardSeedot_Gfx:: @ 0x087423AC
	.incbin "graphics/stage/sapphire/seedot.4bpp";

gSapphireBoardShopShockWall_Gfx:: @ 0x08742E2C
	.incbin "graphics/stage/sapphire/shop_shock_wall.4bpp";

gRubyBoardRampPrize_Gfx_EnFr:: @ 0x0874332C
gRubyBoardRampPrize_Gfx:: @ 0x0874332C
	.incbin "graphics/stage/ruby/ramp_prize.4bpp";

gRubyBoardRampPrize_Gfx_DeItEs:: @ 0x0874372C
	.incbin "graphics/stage/ruby/ramp_prize_deites.4bpp"
gDusclopsBoardDusclopsBallGrabSwirl_Gfx:: @ 0x08743B2C
	.incbin "graphics/stage/dusclops/dusclops_ball_grab.4bpp";

gKyogreWhirlpoolTrap_Gfx:: @ 0x0874412C
	.incbin "graphics/stage/kyogre/whirlpool_trap.4bpp"

gMainBoardBallSave_Gfx_En:: @ 0x0874582C
gMainBoardBallSave_Gfx:: @ 0x0874582C
	.incbin "graphics/stage/main/ball_save.4bpp";

gMainBoardBallSave_Gfx_Fr:: @ 0x087470EC
	.incbin "graphics/stage/main/ball_save_fr.4bpp"
gMainBoardBallSave_Gfx_De:: @ 0x087489AC
	.incbin "graphics/stage/main/ball_save_de.4bpp"
gMainBoardBallSave_Gfx_It:: @ 0x0874A26C
	.incbin "graphics/stage/main/ball_save_it.4bpp"
gMainBoardBallSaveLatios_Gfx:: @ 0x0874BB2C
	.incbin "graphics/stage/main/latios.4bpp";

gMainBoardBallSaveLatiosArm_Gfx:: @ 0x0874CB2C
	.incbin "graphics/stage/main/latios_arm.4bpp";

gMainBoardBallSave_Gfx_Es:: @ 0x0874CBEC
	.incbin "graphics/stage/main/ball_save_es.4bpp"
gMainBoardEndOfBall_Gfx_En:: @ 0x0874E4AC
gMainBoardEndOfBall_Gfx:: @ 0x0874E4AC
	.incbin "graphics/stage/main/end_of_ball.4bpp";



gEobBonusSummaryCharTiles:: @ 0x087500AC
	.incbin "graphics/stage/misc/end_of_ball_summary_text_chars_eu.4bpp"
gMainBoardEndOfBall_Gfx_Fr:: @ 0x087507CC
	.incbin "graphics/stage/main/end_of_ball_fr.4bpp"
gMainBoardEndOfBall_Gfx_De:: @ 0x087523CC
	.incbin "graphics/stage/main/end_of_ball_de.4bpp"
gMainBoardEndOfBall_Gfx_It:: @ 0x08753FCC
	.incbin "graphics/stage/main/end_of_ball_it.4bpp"
gMainBoardEndOfBall_Gfx_Es:: @ 0x08755BCC
	.incbin "graphics/stage/main/end_of_ball_es.4bpp"
gMainBoardEvoBanner_Gfx:: @ 0x087577CC
	.incbin "graphics/stage/main/evo_banner.4bpp";

gMainBoardEvoBanner_Gfx_Fr:: @ 0x0875BB4C
	.incbin "graphics/stage/main/evo_banner_fr.4bpp"
gMainBoardEvoBanner_Gfx_De:: @ 0x0875FECC
	.incbin "graphics/stage/main/evo_banner_de.4bpp"
gMainBoardEvoBanner_Gfx_It:: @ 0x0876424C
	.incbin "graphics/stage/main/evo_banner_it.4bpp"
gMainBoardEvoBanner_Gfx_Es:: @ 0x087685CC
	.incbin "graphics/stage/main/evo_banner_es.4bpp"
gMainBoardGameOverText_Gfx_EnFrDeIt:: @ 0x0876C94C
gMainBoardGameOverText_Gfx:: @ 0x0876C94C
	.incbin "graphics/stage/main/game_over_text.4bpp";

gMainBoardGameOverText_Gfx_Es:: @ 0x0876CD4C
	.incbin "graphics/stage/main/game_over_text_es.4bpp"
gMainBoardJirachiBanner_Gfx:: @ 0x0876D14C
	.incbin "graphics/stage/main/jirachi_banner.4bpp";

gMainBoardTravel_Gfx:: @ 0x087714CC
	.incbin "graphics/stage/main/travel.4bpp";

gMainBoardTravel_Gfx_Fr:: @ 0x08773AAC
	.incbin "graphics/stage/main/travel_fr.4bpp"
gMainBoardTravel_Gfx_De:: @ 0x0877608C
	.incbin "graphics/stage/main/travel_de.4bpp"
gMainBoardTravel_Gfx_It:: @ 0x0877866C
	.incbin "graphics/stage/main/travel_it.4bpp"
gMainBoardTravel_Gfx_Es:: @ 0x0877AC4C
	.incbin "graphics/stage/main/travel_es.4bpp"
gPauseMenuText_Gfx:: @ 0x0877D22C
	.incbin "graphics/stage/main/pause_menu_text.4bpp";

gFieldIntroText_Gfx_En:: @ 0x0877D3CC
	.incbin "graphics/stage/misc/field_intro_text_en.4bpp"
gFieldIntroText_Gfx_Fr:: @ 0x0877D50C
	.incbin "graphics/stage/misc/field_intro_text_fr.4bpp"
gFieldIntroText_Gfx_De:: @ 0x0877D64C
	.incbin "graphics/stage/misc/field_intro_text_de.4bpp"
gFieldIntroText_Gfx_It:: @ 0x0877D78C
	.incbin "graphics/stage/misc/field_intro_text_it.4bpp"
gFieldIntroText_Gfx_Es:: @ 0x0877D8CC
	.incbin "graphics/stage/misc/field_intro_text_es.4bpp"
gDusclopsBoardDuskull_Gfx:: @ 0x0877DA0C
	.incbin "graphics/stage/dusclops/duskull.4bpp";

gSapphireBoardZigzagoon_Gfx:: @ 0x0877F80C
	.incbin "graphics/stage/sapphire/zigzagoon.4bpp";

gBallSaver_Ruby_Pal:: @ 0x08781B0C
	.incbin "graphics/stage/ruby/ball_saver.gbapal"

gBallSaver_Sapphire_Pal:: @ 0x08781B2C
	.incbin "graphics/stage/sapphire/ball_saver.gbapal"

gRubyChinchouCatchBurstBanner_Gfx:: @ 0x08781D0C
	.incbin "graphics/stage/ruby/chinchou_catch_burst_banner.4bpp"
	.space 0xA0

gRubyChinchouCatchBurstBanner_Pal:: @ 0x0878612C
	.incbin "graphics/stage/ruby/chinchou_catch_burst_banner.gbapal"

gRubyLotadCatchBurstBanner_Pal:: @ 0x0878614C
	.incbin "graphics/stage/ruby/lotad_catch_burst_banner.gbapal"

gSapphireShroomishCatchBurstBanner_Pal:: @ 0x0878616C
	.incbin "graphics/stage/sapphire/shroomish_catch_burst_banner.gbapal"

gRubyLotadCatchBurstBanner_Gfx:: @ 0x0878632C
	.incbin "graphics/stage/ruby/lotad_catch_burst_banner.4bpp"
	.space 0xA0

gSapphireShroomishCatchBurstBanner_Gfx:: @ 0x0878A74C
	.incbin "graphics/stage/sapphire/shroomish_catch_burst_banner.4bpp"
	.space 0xA0

gEndOfBallBonus_Ruby_Pal:: @ 0x0878EB6C
	.incbin "graphics/stage/ruby/end_of_ball_bonus.gbapal"

gEndOfBallBonus_Sapphire_Pal:: @ 0x0878EB8C
	.incbin "graphics/stage/sapphire/end_of_ball_bonus.gbapal"

gMainBoardEvoBanner_Pal:: @ 0x0878ED6C
    .incbin "graphics/stage/main/evo_banner.gbapal"

gMainCatchModeBanner_Gfx:: @ 0x0878EF6C
	.incbin "graphics/stage/main/catch_mode_banner.4bpp"
	.space 0xA0

gMainCatchModeBanner_Gfx_Fr:: @ 0x0879338C
	.incbin "graphics/stage/main/catch_mode_banner_fr.4bpp"
	.space 0xA0
gMainCatchModeBanner_Gfx_De:: @ 0x087977AC
	.incbin "graphics/stage/main/catch_mode_banner_de.4bpp"
	.space 0xA0
gMainCatchModeBanner_Gfx_It:: @ 0x0879BBCC
	.incbin "graphics/stage/main/catch_mode_banner_it.4bpp"
	.space 0xA0
gMainCatchModeBanner_Gfx_Es:: @ 0x0879FFEC
	.incbin "graphics/stage/main/catch_mode_banner_es.4bpp"
	.space 0xA0
gMainCatchModeBanner_Pal:: @ 0x087A440C
    .incbin "graphics/stage/main/catch_mode_banner.gbapal"

gMainBoardJirachiBanner_Pal:: @ 0x087A460C
    .incbin "graphics/stage/main/jirachi_banner.gbapal"

gMainBoardTravel_Pal:: @ 0x087A480C
    .incbin "graphics/stage/main/travel.gbapal"

gSapphireBoardZigzagoonFx_Gfx:: @ 0x087A4A0C
	.incbin "graphics/stage/sapphire/zigzagoon_fx.4bpp";

@ Unreferenced blob, most likely a leftover tilemap. This has mostly ascending id values with runs of repeats.
gUnknown_085279CC:: @ 0x087A560C
	.incbin "graphics/stage/unknown_085279CC.bin"

gOptionsBGMList:: @ 0x087A5962
	.2byte MUS_TITLE, MUS_TABLE_SELECT, MUS_EREADER, MUS_OPENING, MUS_HIGH_SCORE
	.2byte MUS_POKEDEX, MUS_SHOP, MUS_SLOTS_PRIZE, MUS_END_OF_BALL, MUS_BONUS_CHANCE, MUS_BONUS_CHANCE_LEGENDARY
	.2byte MUS_TRAVEL_MODE_START, MUS_SUCCESS, MUS_PRIZE_AWARDED, MUS_EGG_MODE, MUS_EGG_MODE_START
	.2byte MUS_TRAVEL_MODE, MUS_HURRY_UP, MUS_EVOLUTION, MUS_FIELD_RUBY, MUS_CATCH_EM_MODE
	.2byte MUS_EVO_MODE, MUS_FIELD_RUBY2, MUS_FIELD_SAPPHIRE, MUS_CATCH_EM_MODE2, MUS_FIELD_SAPPHIRE2
	.2byte MUS_BONUS_FIELD_KECLEON, MUS_BONUS_FIELD_DUSKULL, MUS_BONUS_FIELD_DUSCLOPS, MUS_BONUS_FIELD_SPHEAL, MUS_BONUS_FIELD_GROUDON
	.2byte MUS_BONUS_FIELD_KYOGRE, MUS_BONUS_FIELD_RAYQUAZA, MUS_JIRACHI

gOptionsSEList:: @ 0x087A59A6
    .2byte SE_MENU_SELECT, SE_MENU_CANCEL, SE_MENU_MOVE, SE_MENU_POPUP_OPEN, SE_MENU_POPUP_CLOSE
    .2byte SE_SCORE_ENTRY_A_B_MOVE, SE_SCORE_ENTRY_LETTER_CHANGE, SE_DEX_INFO_FIELD_SELECT_MOVE, SE_FLIPPER_PRESSED, SE_SLINGSHOT_HIT
    .2byte SE_POKEMON_CATCH_HIT, SE_PICHU_IN_POSITION_CHIRP, SE_TRIGGER_BUTTON_HIT, SE_WALL_HIT, SE_TILT_TRIGGERED
    .2byte SE_PIKA_SPINNER_CLACK, SE_PIKA_FULL_CHARGE_1_UP, SE_UNKNOWN_0x7B, SE_KICKBACK_THUNDERWAVE, SE_COIN_COLLECTED
    .2byte SE_CENTER_HOLE_EJECT, SE_ROULETTE_TICK, SE_EVO_SELECTION_MOVE, SE_EVO_SELECTION_CONFIRM, SE_EVO_ITEM_APPEAR
    .2byte SE_EVO_ITEM_FINISH_APPEAR, SE_EVO_ITEM_COLLECTED, SE_BALL_UPGRADE, SE_FAILURE, SE_CATCH_EVO_BANNER
    .2byte SE_CATCH_TILE_REVEAL, SE_CATCH_ALL_REVEAL_LIGHTNING, SE_CATCH_ALL_REVEAL_SHATTER, SE_SHOP_LIST_REVEAL, SE_BONUS_SCORE_TALLIED
    .2byte SE_HATCH_FLOURISH, SE_AREA_ROULETTE_SELECTED, SE_BALL_SAVED, SE_LATI_DELIVERY, SE_SAVER_PLUNGER_DROP
    .2byte SE_TRAVEL_PAINTER_FLIGHT, SE_TRAVEL_PAINTER_PAINTS, SE_EVO_GET_ARROW_EARNED, SE_MON_CATCH_BALL_WOOSH, SE_MON_CATCH_ENERGY_BEAM
    .2byte SE_MON_CATCH_BALL_CLOSE, SE_MON_CATCH_BALL_HIT_GROUND, SE_MON_CATCH_BALL_SHAKE, SE_WARP, SE_BALL_SUMMARY_TEXT_PROGRESS

    .2byte SE_BALL_SUMMARY_PAGE_SWIPE, SE_PAUSE_CURSOR_MOVE, SE_BONUS_PANEL_SLIDE, SE_PAUSING, SE_UNPAUSING
    .2byte SE_CATCH_MON_ENTITY_APPEARS, SE_PIKA_CHARGE_DO, SE_PIKA_CHARGE_RE, SE_PIKA_CHARGE_MI, SE_PIKA_CHARGE_FA
    .2byte SE_PIKA_CHARGE_SO, SE_PIKA_CHARGE_LA, SE_PIKA_CHARGE_TI, SE_PIKA_CHARGE_HIGH_DO, SE_EVO_CUTSCENE_MON_PORTRAIT_CHANGE
    .2byte SE_BUMPER_HIT, SE_CYNDAQUIL_EGG_GUARD_HIT, SE_AERODACTYL_EGG_FLIGHT, SE_CYNDAQUIL_BALL_EJECT_AFTER_EGG_ARRIVAL, SE_RUBY_MART_GATE_OPEN
    .2byte SE_SHARPEDO_BALL_EJECT, SE_SHOP_EJECT, SE_MAKUHITA_PUNCH, SE_CHIKORITA_LEAF_BLADE, SE_ZIGZAGOON_EMERGE
    .2byte SE_RUBY_BUMPER_EMERGES, SE_RUBY_BUMPER_LEAVES, SE_RUBY_MART_SIGN_CHANGED, SE_SPOINK_LAUNCHER_CHARGED, SE_SPOINK_LAUNCHER_FIRED
    .2byte SE_SHARPEDO_BITE, SE_NUZLEAF_HIT, SE_NUZLEAF_TEETERING, SE_NUZLEAF_FORMS_BRIDGE, SE_GULPIN_LANDS_OR_LEAVES
    .2byte SE_WHISCASH_EMERGE_SPLASH, SE_WHISCASH_LEAVE_BURBLE, SE_WHISCASH_CATCH_BALL, SE_WHISCASH_SPIT_BALL, SE_WHISCASH_SPLASHDOWN
    .2byte SE_RAMP_PRIZE_COLLECTED, SE_HATCH_MACHINE_SPINNER_TRIGGER, SE_MON_LANDS_ON_HATCH_MACHINE_TOP, SE_HATCH_MACHINE_STAGE_ADVANCE, SE_HATCH_MACHINE_EGG_HATCH
    .2byte SE_HATCH_MACHINE_ELEVATOR, SE_HATCH_MACHINE_ELEVATOR_TOP, SE_PELIPPER_BALL_GRAB, SE_PELIPPER_WING_FLAP, SE_PELIPPER_SWOOSH

    .2byte SE_PELIPPER_BALL_DROP_LANDS, SE_SAPPHIRE_MART_GATE_TRIGGER, SE_SAPPHIRE_MART_GATE_REPLACED, SE_SAPPHIRE_MART_GATE_HIT, SE_SEEDOT_FALLING
    .2byte SE_SEEDOT_LANDS, SE_SEEDOT_LEAVES, SE_ZIGZAGOON_ROULETTE_STOP, SE_DUSKULL_APPEAR, SE_DUSKULL_DEATH_CRY
    .2byte SE_DUSCLOPS_DEPART_INCOMPLETE, SE_DUSCLOPS_MOVE, SE_DUSCLOPS_APPEAR, SE_DUSCLOPS_HIT, SE_DUSCLOPS_BALL_ABSORB
    .2byte SE_DUSCLOPS_BALL_LAUNCH, SE_BONUS_BOARD_BALL_SPAWN, SE_KECLEON_SIDE_LOOK, SE_KECLEON_VANISH, SE_KECLEON_STARTLED
    .2byte SE_KECLEON_RUNNING, SE_KECLEON_KNOCKED_OVER, SE_KECLEON_HIT_DAMAGED, SE_KECLEON_HITS_GROUND_DEFEATED, SE_KECLEON_SEEING_STARS
    .2byte SE_KECLEON_TREE_HIT, SE_KECLEON_SCOPE_FALL, SE_KECLEON_SCOPE_ACTIVATED, SE_KYOGRE_HIT, SE_KYOGRE_BREACH_SURFACE
    .2byte SE_KYOGRE_DIVE, SE_KYOGRE_SPAWN_WHIRLPOOL, SE_KYOGRE_FREEZE_RING, SE_KYOGRE_DEPARTS, SE_KYOGRE_FREEZE_HITS_BALL
    .2byte SE_KYOGRE_FREEZE_CRACK, SE_KYOGRE_FREEZE_ESCAPED, SE_KYOGRE_WHIRLPOOL_GRABS_BALL, SE_GROUDON_HIT, SE_GROUDON_STEP
    .2byte SE_GROUDON_INTRO_LEAP, SE_GROUDON_LANDS, SE_GROUDON_SPITS_FIRE, SE_GROUDON_FIRE_RING, SE_GROUDON_FIRE_GRAB_RESIST
    .2byte SE_GROUDON_FIRE_GRAB, SE_GROUDON_FIREBALL_CONNECTS, SE_GROUDON_BOULDER_LAND, SE_GROUDON_DUSTORM_LIFT, SE_GROUDON_BALL_HIT_FIRE

	.2byte SE_RAYQUAZA_HIT, SE_RAYQUAZA_WIND, SE_RAYQUAZA_LIGHTNING_CHARGE, SE_RAYQUAZA_FLYBY, SE_RAYQUAZA_LIGHTNING_TRAP
    .2byte SE_RAYQUAZA_WHIRLWIND_BALL_LAUNCH, SE_RAYQUAZA_WHIRLWIND_BALL_LAND, SE_RAYQUAZA_SONIC_BOOM, SE_RAYQUAZA_STAGE_WIND, SE_SPHEAL_SURFACING
    .2byte SE_SPHEAL_SUBMERGING, SE_SPHEAL_SUBMERGE_AFTER_SCORING, SE_SPHEAL_HIT, SE_SPHEAL_NET_SWOOSH, SE_SPHEAL_CROWD_CHEER
    .2byte SE_SPHEAL_END_WHISTLE, SE_SEALEO_HIT_THUD, SE_SEALEO_NOSE_BOUNCE, SE_SPHEAL_LAND_UNDER_NET, SE_SPHEAL_SURFACE_AT_RAMP
    .2byte SE_JIRACHI_MOVE, SE_JIRACHI_HIT, SE_TOTODILE_LOWERS_ROPE, SE_TOTODILE_SLIDES_DOWN, SE_TOTODILE_PLACES_EGG
    .2byte SE_TOTODILE_CLIMBS_ROPE, SE_WHISCASH_EARTHQUAKE, SE_HIGHEST_SCORE_EARNED, SE_HIGH_SCORE_EARNED, SE_UNKNOWN_0x71
    .2byte SE_PIKACHU_KICKBACK, SE_PICHU_KICKBACK_ENABLED, SE_PICHU_KICKBACK, SE_PIKA_NO_KICKBACK


gDefaultButtonConfigs:: @ 0x087A5B16
	@4 sets of 10
	.byte 0x05, 0x0A, 0x00, 0x0A, 0x09, 0x0A, 0x08, 0x0A, 0x09, 0x08;
	.byte 0x05, 0x0A, 0x00, 0x0A, 0x09, 0x0A, 0x08, 0x0A, 0x01, 0x0A;
	.byte 0x09, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 0x00, 0x0A, 0x05, 0x00;
	.byte 0x09, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 0x04, 0x0A, 0x06, 0x0A;

gDefaultCustomButtonConfigTileIds:: @ 0x087A5B3E
	.byte 1, 10, 0, 10, 5, 10, 4, 10, 6, 10

gOptionsStateFuncs:: @ 0x087A5B48
	.4byte Options_LoadGraphics
	.4byte Options_HandleInput
	.4byte Options_State2_51C3C
	.4byte Options_State3_51C60

.include "data/pokedex_entries/species_rs_to_cry_id.inc"

gOptionsText_Tilemap_En:: @ 0x087A5C68
gOptionsText_Tilemap:: @ 0x087A5C68
	.incbin "graphics/options/text.bin"

gOptionsText_Gfx_En:: @ 0x087A6468
gOptionsText_Gfx:: @ 0x087A6468
	.incbin "graphics/options/text.4bpp"
	.space 0x20

gOptionsText_Tilemap_De:: @ 0x087A7C88
	.incbin "graphics/options/text_de.bin"
gOptionsText_Gfx_De:: @ 0x087A8488
	.incbin "graphics/options/text_de.4bpp"
	.space 0x20
gOptionsText_Tilemap_Fr:: @ 0x087A9CA8
	.incbin "graphics/options/text_fr.bin"
gOptionsText_Gfx_Fr:: @ 0x087AA4A8
	.incbin "graphics/options/text_fr.4bpp"
	.space 0x20
gOptionsText_Tilemap_It:: @ 0x087ABCC8
	.incbin "graphics/options/text_it.bin"
gOptionsText_Gfx_It:: @ 0x087AC4C8
	.incbin "graphics/options/text_it.4bpp"
	.space 0x20
gOptionsText_Tilemap_Es:: @ 0x087ADCE8
	.incbin "graphics/options/text_es.bin"
gOptionsText_Gfx_Es:: @ 0x087AE4E8
	.incbin "graphics/options/text_es.4bpp"
	.space 0x20
gOptionsBackground_Tilemap_EnDe:: @ 0x087AFD08
gOptionsBackground_Tilemap:: @ 0x087AFD08
	.incbin "graphics/options/background.bin"

gOptionsBackground_Gfx_EnFr:: @ 0x087B0508
gOptionsBackground_Gfx:: @ 0x087B0508
	.incbin "graphics/options/background.4bpp"
	.space 0x20

gOptionsBackground_Gfx_De:: @ 0x087B1128
	.incbin "graphics/options/background_de.4bpp"
	.space 0x20
gOptionsBackground_Tilemap_Fr:: @ 0x087B1D48
	.incbin "graphics/options/background_fr.bin"
gOptionsBackground_Tilemap_It:: @ 0x087B2548
	.incbin "graphics/options/background_it.bin"
gOptionsBackground_Gfx_It:: @ 0x087B2D48
	.incbin "graphics/options/background_it.4bpp"
	.space 0x20
gOptionsBackground_Tilemap_Es:: @ 0x087B3968
	.incbin "graphics/options/background_es.bin"
gOptionsBackground_Gfx_Es:: @ 0x087B4168
	.incbin "graphics/options/background_es.4bpp"
	.space 0x20
gOptionsBackground_Pals:: @ 0x087B4D88
	.incbin "graphics/options/background.gbapal"

gGBAButtonIcons_Pals:: @ 0x087B4F88
	.incbin "graphics/gba_buttons.gbapal"

gOptionsSprites_Gfx_En:: @ 0x087B5188
gOptionsSprites_Gfx:: @ 0x087B5188
	.incbin "graphics/options/sprites.4bpp"

.align 2
gOptionsSprites_Gfx_De:: @ 0x087B71A8
	.incbin "graphics/options/sprites_de.4bpp"
gOptionsSprites_Gfx_Fr:: @ 0x087B91C8
	.incbin "graphics/options/sprites_fr.4bpp"
gOptionsSprites_Gfx_It:: @ 0x087BB1E8
	.incbin "graphics/options/sprites_it.4bpp"
gOptionsSprites_Gfx_Es:: @ 0x087BD208
	.incbin "graphics/options/sprites_es.4bpp"
