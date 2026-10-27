@ Note: ruby_board.inc has a shared 'bumper collision map' (gSharedBumperCollisionMap)

gSapphireBoardPalette:: @ 0x0840B284
	.incbin "graphics/stage/sapphire/sapphire_board.gbapal"

gSapphireBoardBG3Tilemap:: @ 0x0840B484
	.incbin "graphics/stage/sapphire/sapphire_board_bg3_tilemap.bin"

gSapphireBoardCollisionTileDataLayer0:: @ 0x0840C484
.incbin "data/board_data/collision/sapphire/boardtop_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer0:: @ 0x0840E484
.incbin "data/board_data/collision/sapphire/boardtop_angledata.bin"

gSapphireBoardCollisionTypeDataLayer0:: @ 0x08423084
.incbin "data/board_data/collision/sapphire/boardtop_typedata.bin"

gSapphireBoardCollisionTileDataLayer1:: @ 0x0842D684
.incbin "data/board_data/collision/sapphire/boardbottom_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer1:: @ 0x0842F684
.incbin "data/board_data/collision/sapphire/boardbottom_angledata.bin"

gSapphireBoardCollisionTypeDataLayer1:: @ 0x08441B04
.incbin "data/board_data/collision/sapphire/boardbottom_typedata.bin"

gSapphireBoardBG2Tilemap:: @ 0x0844AD44
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tilemap.bin"

gSapphireBoardCollisionTileDataLayer2:: @ 0x0844BD44
.incbin "data/board_data/collision/sapphire/topramp_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer2:: @ 0x0844DD44
.incbin "data/board_data/collision/sapphire/topramp_angledata.bin"

gSapphireBoardCollisionTypeDataLayer2:: @ 0x0845AE44
.incbin "data/board_data/collision/sapphire/topramp_typedata.bin"

gSapphireBoardCollisionTileDataLayer3:: @ 0x084616C4
.incbin "data/board_data/collision/sapphire/hatchexitramp_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer3:: @ 0x084636C4
.incbin "data/board_data/collision/sapphire/hatchexitramp_angledata.bin"

gSapphireBoardCollisionTypeDataLayer3:: @ 0x0846B9C4
.incbin "data/board_data/collision/sapphire/hatchexitramp_typedata.bin"

gSapphireBoardCompressedTiles1_En:: @ 0x0846FB44
gSapphireBoardCompressedTiles1:: @ 0x0846FB44
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tiles.4bpp.lz"

gSapphireBoardCompressedTiles2_En:: @ 0x084718B0
gSapphireBoardCompressedTiles2:: @ 0x084718B0
	.incbin "graphics/stage/sapphire/sapphire_board_bgtop_tiles.4bpp.lz"

gSapphireBoardCompressedTiles2_Fr:: @ 0x0847500C
	.incbin "graphics/stage/sapphire/sapphire_board_bgtop_tiles_fr.4bpp.lz"
gSapphireBoardCompressedTiles2_De:: @ 0x0847875C
	.incbin "graphics/stage/sapphire/sapphire_board_bgtop_tiles_de.4bpp.lz"
gSapphireBoardCompressedTiles2_It:: @ 0x0847BEB8
	.incbin "graphics/stage/sapphire/sapphire_board_bgtop_tiles_it.4bpp.lz"
gSapphireBoardCompressedTiles2_Es:: @ 0x0847F608
	.incbin "graphics/stage/sapphire/sapphire_board_bgtop_tiles_es.4bpp.lz"
gSapphireBoardCompressedBGTileBuffer_En:: @ 0x08482D44
gSapphireBoardCompressedBGTileBuffer:: @ 0x08482D44
	.incbin "graphics/stage/sapphire/sapphire_board_bgbottom_tiles.4bpp.lz"



@ Evo Arrows. Named this way for comprehension in folder.
@ E/V/O arrows. Second digit is '0 Top/1 Mid/2 Bottom',
@ First digit is 'variant'.
gSapphireBoardCompressedBGTileBuffer_Fr:: @ 0x08484D8C
	.incbin "graphics/stage/sapphire/sapphire_board_bgbottom_tiles_fr.4bpp.lz"
gSapphireBoardCompressedBGTileBuffer_De:: @ 0x08486DB4
	.incbin "graphics/stage/sapphire/sapphire_board_bgbottom_tiles_de.4bpp.lz"
gSapphireBoardCompressedBGTileBuffer_It:: @ 0x08488DC4
	.incbin "graphics/stage/sapphire/sapphire_board_bgbottom_tiles_it.4bpp.lz"
gSapphireBoardCompressedBGTileBuffer_Es:: @ 0x0848ADE0
	.incbin "graphics/stage/sapphire/sapphire_board_bgbottom_tiles_es.4bpp.lz"
gSapphireBoardCompressedTiles1_Fr:: @ 0x0848CE20
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tiles_fr.4bpp.lz"
gSapphireBoardCompressedTiles1_De:: @ 0x0848EB64
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tiles_de.4bpp.lz"
gSapphireBoardCompressedTiles1_It:: @ 0x08490890
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tiles_it.4bpp.lz"
gSapphireBoardCompressedTiles1_Es:: @ 0x084925D8
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tiles_es.4bpp.lz"
gSapphireEvoArrow_E_0Lit_Top:: @ 0x08494320
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_0.4bpp"

gSapphireEvoArrow_E_1Lit_Top:: @ 0x08494380
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_0.4bpp"

gSapphireEvoArrow_E_2Lit_Top:: @ 0x084943E0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_0.4bpp"

gSapphireEvoArrow_V_0Lit_Top:: @ 0x08494440
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_0.4bpp"

gSapphireEvoArrow_V_1Lit_Top:: @ 0x084944A0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_0.4bpp"

gSapphireEvoArrow_V_2Lit_Top:: @ 0x08494500
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_0.4bpp"

gSapphireEvoArrow_V_3Lit_Top:: @ 0x08494560
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_0.4bpp"

gSapphireEvoArrow_O_Under2Lit_Top:: @ 0x084945C0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_0.4bpp"

gSapphireEvoArrow_O_2Lit_Top:: @ 0x08494620
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_0.4bpp"

gSapphireEvoArrow_O_3Lit_Top:: @ 0x08494680
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_0.4bpp"
	.space 0x40

gSapphireEvoArrow_E_0Lit_Mid:: @ 0x08494720
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_1.4bpp"

gSapphireEvoArrow_E_1Lit_Mid:: @ 0x08494780
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_1.4bpp"

gSapphireEvoArrow_E_2Lit_Mid:: @ 0x084947E0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_1.4bpp"

gSapphireEvoArrow_V_0Lit_Mid:: @ 0x08494840
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_1.4bpp"

gSapphireEvoArrow_V_1Lit_Mid:: @ 0x084948A0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_1.4bpp"

gSapphireEvoArrow_V_2Lit_Mid:: @ 0x08494900
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_1.4bpp"

gSapphireEvoArrow_V_3Lit_Mid:: @ 0x08494960
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_1.4bpp"

gSapphireEvoArrow_O_Under2Lit_Mid:: @ 0x084949C0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_1.4bpp"

gSapphireEvoArrow_O_2Lit_Mid:: @ 0x08494A20
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_1.4bpp"

gSapphireEvoArrow_O_3Lit_Mid:: @ 0x08494A80
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_1.4bpp"
	.space 0x40

gSapphireEvoArrow_E_0Lit_Bot:: @ 0x08494B20
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_2.4bpp"

gSapphireEvoArrow_E_1Lit_Bot:: @ 0x08494B80
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_2.4bpp"

gSapphireEvoArrow_E_2Lit_Bot:: @ 0x08494BE0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_2.4bpp"

gSapphireEvoArrow_V_0Lit_Bot:: @ 0x08494C40
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_2.4bpp"

gSapphireEvoArrow_V_1Lit_Bot:: @ 0x08494CA0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_2.4bpp"

gSapphireEvoArrow_V_2Lit_Bot:: @ 0x08494D00
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_2.4bpp"

gSapphireEvoArrow_V_3Lit_Bot:: @ 0x08494D60
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_2.4bpp"
	.space 0x20

gSapphireEvoArrow_O_Under2Lit_Bot:: @ 0x08494DE0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_2.4bpp"
	.space 0x20

gSapphireEvoArrow_O_2Lit_Bot:: @ 0x08494E40
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_2.4bpp"
	.space 0x20

gSapphireEvoArrow_O_3Lit_Bot:: @ 0x08494EA0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_2.4bpp"
	.space 0x40


@ Coin Arrows


gSapphireCoinArrow_1_0Lit_Top:: @ 0x08494F20
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
    .space 0x20

gSapphireCoinArrow_1_1Lit_Top:: @ 0x08494F80
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p0.4bpp"
    .space 0x20

gSapphireCoinArrow_1_2PlusLit_Top:: @ 0x08494FE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0_filler.4bpp"

gSapphireCoinArrow_5_Under2Lit_Top:: @ 0x08495060
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0_filler.4bpp"

gSapphireCoinArrow_5_2Lit_Top:: @ 0x084950C0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0_filler.4bpp"

gSapphireCoinArrow_5_3Lit_Top:: @ 0x08495120
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p0.4bpp"

gSapphireCoinArrow_10_Under2Lit_Top:: @ 0x08495160
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireCoinArrow_10_2Lit_Top:: @ 0x084951C0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireCoinArrow_10_3Lit_Top:: @ 0x08495220
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
	.fill 0x20, 1, 0xDD
	.space 0xA0

gSapphireCoinArrow_1_0Lit_Mid:: @ 0x08495320
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p1.4bpp"

gSapphireCoinArrow_1_1Lit_Mid:: @ 0x08495380
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p1.4bpp"

gSapphireCoinArrow_1_2PlusLit_Mid:: @ 0x084953E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1_filler.4bpp"

gSapphireCoinArrow_5_Under2Lit_Mid:: @ 0x08495460
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1_filler.4bpp"

gSapphireCoinArrow_5_2Lit_Mid:: @ 0x084954C0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1_filler.4bpp"

gSapphireCoinArrow_5_3Lit_Mid:: @ 0x08495520
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p1.4bpp"

gSapphireCoinArrow_10_Under2Lit_Mid:: @ 0x08495560
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1_filler.4bpp"

gSapphireCoinArrow_10_2Lit_Mid:: @ 0x084955C0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1_filler.4bpp"

gSapphireCoinArrow_10_3Lit_Mid:: @ 0x08495620
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1_filler.4bpp"

gSapphireCoinArrow_1_0Lit_Bot:: @ 0x08495720
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p2.4bpp"

gSapphireCoinArrow_1_1Lit_Bot:: @ 0x08495780
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p2.4bpp"

gSapphireCoinArrow_1_2PlusLit_Bot:: @ 0x084957E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p2.4bpp"

gSapphireCoinArrow_5_Under2Lit_Bot:: @ 0x08495860
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p2.4bpp"

gSapphireCoinArrow_5_2Lit_Bot:: @ 0x084958C0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p2.4bpp"

gSapphireCoinArrow_5_3Lit_Bot:: @ 0x08495920
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p2.4bpp"

gSapphireCoinArrow_10_Under2Lit_Bot:: @ 0x08495960
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2_filler.4bpp"

gSapphireCoinArrow_10_2Lit_Bot:: @ 0x084959C0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2_filler.4bpp"

gSapphireCoinArrow_10_3Lit_Bot:: @ 0x08495A20
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2_filler.4bpp"


@ Get Arrows

gSapphireGetArrow_G_0Lit_Top:: @ 0x08495B20
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_0.4bpp"

gSapphireGetArrow_G_1Lit_Top:: @ 0x08495B80
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_0.4bpp"

gSapphireGetArrow_G_2PlusLit_Top:: @ 0x08495BE0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_0.4bpp"
    .space 0x20

gSapphireGetArrow_E_0Lit_Top:: @ 0x08495C60
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_0.4bpp"
    .space 0x20

gSapphireGetArrow_E_1Lit_Top:: @ 0x08495CC0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_0.4bpp"
    .space 0x20

gSapphireGetArrow_E_2Lit_Top:: @ 0x08495D20
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_0.4bpp"
    .space 0x20

gSapphireGetArrow_E_3Lit_Top:: @ 0x08495D80
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireGetArrow_T_Under2Lit_Top:: @ 0x08495DE0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireGetArrow_T_2Lit_Top:: @ 0x08495E40
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireGetArrow_T_3Lit_Top:: @ 0x08495EA0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_0.4bpp"
    .space 0x40

gSapphireGetArrow_G_0Lit_Mid:: @ 0x08495F20
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_1.4bpp"

gSapphireGetArrow_G_1Lit_Mid:: @ 0x08495F80
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_1.4bpp"

gSapphireGetArrow_G_2PlusLit_Mid:: @ 0x08495FE0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1.4bpp"
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_filler.4bpp"

gSapphireGetArrow_E_0Lit_Mid:: @ 0x08496060
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1.4bpp"
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_filler.4bpp"

gSapphireGetArrow_E_1Lit_Mid:: @ 0x084960C0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1.4bpp"
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_filler.4bpp"

gSapphireGetArrow_E_2Lit_Mid:: @ 0x08496120
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1.4bpp"
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_filler.4bpp"

gSapphireGetArrow_E_3Lit_Mid:: @ 0x08496180
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_1.4bpp"

gSapphireGetArrow_T_Under2Lit_Mid:: @ 0x084961C0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_1.4bpp"

gSapphireGetArrow_T_2Lit_Mid:: @ 0x08496220
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_1.4bpp"

gSapphireGetArrow_T_3Lit_Mid:: @ 0x08496280
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_1.4bpp"
    .space 0x40

gSapphireGetArrow_G_0Lit_Bot:: @ 0x08496320
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_2.4bpp"

gSapphireGetArrow_G_1Lit_Bot:: @ 0x08496380
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_2.4bpp"

gSapphireGetArrow_G_2PlusLit_Bot:: @ 0x084963E0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_2.4bpp"

gSapphireGetArrow_E_0Lit_Bot:: @ 0x08496440
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_2.4bpp"

gSapphireGetArrow_E_1Lit_Bot:: @ 0x084964A0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_2.4bpp"

gSapphireGetArrow_E_2Lit_Bot:: @ 0x08496500
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_2.4bpp"

gSapphireGetArrow_E_3Lit_Bot:: @ 0x08496560
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_2.4bpp"

gSapphireGetArrow_T_Under2Lit_Bot:: @ 0x084965C0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_2.4bpp"
    .space 0x20

gSapphireGetArrow_T_2Lit_Bot:: @ 0x08496620
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_2.4bpp"
    .space 0x20

gSapphireGetArrow_T_3Lit_Bot:: @ 0x08496680
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_2.4bpp"
    .space 0x80


@ Arrow for bonus multiplier left/right top/bottom digits

gSapphireProgressDigit0_TensTop:: @ 0x08496740
    .incbin "graphics/stage/sapphire/progress_digits/digit0_tens_top.4bpp"

gSapphireProgressDigit1_TensTop:: @ 0x08496760
    .incbin "graphics/stage/sapphire/progress_digits/digit1_tens_top.4bpp"

gSapphireProgressDigit2_TensTop:: @ 0x08496780
    .incbin "graphics/stage/sapphire/progress_digits/digit2_tens_top.4bpp"

gSapphireProgressDigit3_TensTop:: @ 0x084967A0
    .incbin "graphics/stage/sapphire/progress_digits/digit3_tens_top.4bpp"

gSapphireProgressDigit4_TensTop:: @ 0x084967C0
    .incbin "graphics/stage/sapphire/progress_digits/digit4_tens_top.4bpp"

gSapphireProgressDigit5_TensTop:: @ 0x084967E0
    .incbin "graphics/stage/sapphire/progress_digits/digit5_tens_top.4bpp"

gSapphireProgressDigit6_TensTop:: @ 0x08496800
    .incbin "graphics/stage/sapphire/progress_digits/digit6_tens_top.4bpp"

gSapphireProgressDigit7_TensTop:: @ 0x08496820
    .incbin "graphics/stage/sapphire/progress_digits/digit7_tens_top.4bpp"

gSapphireProgressDigit8_TensTop:: @ 0x08496840
    .incbin "graphics/stage/sapphire/progress_digits/digit8_tens_top.4bpp"

gSapphireProgressDigit9_TensTop:: @ 0x08496860
    .incbin "graphics/stage/sapphire/progress_digits/digit9_tens_top.4bpp"

gSapphireProgressDigit0_OnesTop:: @ 0x08496880
    .incbin "graphics/stage/sapphire/progress_digits/digit0_ones_top.4bpp"

gSapphireProgressDigit1_OnesTop:: @ 0x084968A0
    .incbin "graphics/stage/sapphire/progress_digits/digit1_ones_top.4bpp"

gSapphireProgressDigit2_OnesTop:: @ 0x084968C0
    .incbin "graphics/stage/sapphire/progress_digits/digit2_ones_top.4bpp"

gSapphireProgressDigit3_OnesTop:: @ 0x084968E0
    .incbin "graphics/stage/sapphire/progress_digits/digit3_ones_top.4bpp"

gSapphireProgressDigit4_OnesTop:: @ 0x08496900
    .incbin "graphics/stage/sapphire/progress_digits/digit4_ones_top.4bpp"

gSapphireProgressDigit5_OnesTop:: @ 0x08496920
    .incbin "graphics/stage/sapphire/progress_digits/digit5_ones_top.4bpp"

gSapphireProgressDigit6_OnesTop:: @ 0x08496940
    .incbin "graphics/stage/sapphire/progress_digits/digit6_ones_top.4bpp"

gSapphireProgressDigit7_OnesTop:: @ 0x08496960
    .incbin "graphics/stage/sapphire/progress_digits/digit7_ones_top.4bpp"

gSapphireProgressDigit8_OnesTop:: @ 0x08496980
    .incbin "graphics/stage/sapphire/progress_digits/digit8_ones_top.4bpp"

gSapphireProgressDigit9_OnesTop:: @ 0x084969A0
    .incbin "graphics/stage/sapphire/progress_digits/digit9_ones_top.4bpp"
    .space 0x180

gSapphireProgressDigit0_TensBot:: @ 0x08496B40
    .incbin "graphics/stage/sapphire/progress_digits/digit0_tens_bot.4bpp"

gSapphireProgressDigit1_TensBot:: @ 0x08496B60
    .incbin "graphics/stage/sapphire/progress_digits/digit1_tens_bot.4bpp"

gSapphireProgressDigit2_TensBot:: @ 0x08496B80
    .incbin "graphics/stage/sapphire/progress_digits/digit2_tens_bot.4bpp"

gSapphireProgressDigit3_TensBot:: @ 0x08496BA0
    .incbin "graphics/stage/sapphire/progress_digits/digit3_tens_bot.4bpp"

gSapphireProgressDigit4_TensBot:: @ 0x08496BC0
    .incbin "graphics/stage/sapphire/progress_digits/digit4_tens_bot.4bpp"

gSapphireProgressDigit5_TensBot:: @ 0x08496BE0
    .incbin "graphics/stage/sapphire/progress_digits/digit5_tens_bot.4bpp"

gSapphireProgressDigit6_TensBot:: @ 0x08496C00
    .incbin "graphics/stage/sapphire/progress_digits/digit6_tens_bot.4bpp"

gSapphireProgressDigit7_TensBot:: @ 0x08496C20
    .incbin "graphics/stage/sapphire/progress_digits/digit7_tens_bot.4bpp"

gSapphireProgressDigit8_TensBot:: @ 0x08496C40
    .incbin "graphics/stage/sapphire/progress_digits/digit8_tens_bot.4bpp"

gSapphireProgressDigit9_TensBot:: @ 0x08496C60
    .incbin "graphics/stage/sapphire/progress_digits/digit9_tens_bot.4bpp"

gSapphireProgressDigit0_OnesBot:: @ 0x08496C80
    .incbin "graphics/stage/sapphire/progress_digits/digit0_ones_bot.4bpp"

gSapphireProgressDigit1_OnesBot:: @ 0x08496CA0
    .incbin "graphics/stage/sapphire/progress_digits/digit1_ones_bot.4bpp"

gSapphireProgressDigit2_OnesBot:: @ 0x08496CC0
    .incbin "graphics/stage/sapphire/progress_digits/digit2_ones_bot.4bpp"

gSapphireProgressDigit3_OnesBot:: @ 0x08496CE0
    .incbin "graphics/stage/sapphire/progress_digits/digit3_ones_bot.4bpp"

gSapphireProgressDigit4_OnesBot:: @ 0x08496D00
    .incbin "graphics/stage/sapphire/progress_digits/digit4_ones_bot.4bpp"

gSapphireProgressDigit5_OnesBot:: @ 0x08496D20
    .incbin "graphics/stage/sapphire/progress_digits/digit5_ones_bot.4bpp"

gSapphireProgressDigit6_OnesBot:: @ 0x08496D40
    .incbin "graphics/stage/sapphire/progress_digits/digit6_ones_bot.4bpp"

gSapphireProgressDigit7_OnesBot:: @ 0x08496D60
    .incbin "graphics/stage/sapphire/progress_digits/digit7_ones_bot.4bpp"

gSapphireProgressDigit8_OnesBot:: @ 0x08496D80
    .incbin "graphics/stage/sapphire/progress_digits/digit8_ones_bot.4bpp"

gSapphireProgressDigit9_OnesBot:: @ 0x08496DA0
    .incbin "graphics/stage/sapphire/progress_digits/digit9_ones_bot.4bpp"
    .space 0x1A0


@ Ball power up lights

gSapphireEvoArrow_E_0Lit_Top_Fr:: @ 0x08496F60
	@ copy of the English data, not used by the code
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_0.4bpp"
gSapphireEvoArrow_E_1Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_0.4bpp"
gSapphireEvoArrow_E_2Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_0.4bpp"
gSapphireEvoArrow_V_0Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_0.4bpp"
gSapphireEvoArrow_V_1Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_0.4bpp"
gSapphireEvoArrow_V_2Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_0.4bpp"
gSapphireEvoArrow_V_3Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_0.4bpp"
gSapphireEvoArrow_O_Under2Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_0.4bpp"
gSapphireEvoArrow_O_2Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_0.4bpp"
gSapphireEvoArrow_O_3Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_0.4bpp"
	.space 0x40
gSapphireEvoArrow_E_0Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_1.4bpp"
gSapphireEvoArrow_E_1Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_1.4bpp"
gSapphireEvoArrow_E_2Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_1.4bpp"
gSapphireEvoArrow_V_0Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_1.4bpp"
gSapphireEvoArrow_V_1Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_1.4bpp"
gSapphireEvoArrow_V_2Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_1.4bpp"
gSapphireEvoArrow_V_3Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_1.4bpp"
gSapphireEvoArrow_O_Under2Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_1.4bpp"
gSapphireEvoArrow_O_2Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_1.4bpp"
gSapphireEvoArrow_O_3Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_1.4bpp"
	.space 0x40
gSapphireEvoArrow_E_0Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_2.4bpp"
gSapphireEvoArrow_E_1Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_2.4bpp"
gSapphireEvoArrow_E_2Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_2.4bpp"
gSapphireEvoArrow_V_0Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_2.4bpp"
gSapphireEvoArrow_V_1Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_2.4bpp"
gSapphireEvoArrow_V_2Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_2.4bpp"
gSapphireEvoArrow_V_3Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_Under2Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_2Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_3Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_2.4bpp"
	.space 0x40
gSapphireCoinArrow_1_0Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
	.space 0x20
gSapphireCoinArrow_1_1Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p0.4bpp"
	.space 0x20
gSapphireCoinArrow_1_2PlusLit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0_filler.4bpp"
gSapphireCoinArrow_5_Under2Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0_filler.4bpp"
gSapphireCoinArrow_5_2Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0_filler.4bpp"
gSapphireCoinArrow_5_3Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p0.4bpp"
gSapphireCoinArrow_10_Under2Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCoinArrow_10_2Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p0.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCoinArrow_10_3Lit_Top_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
	.fill 0x20, 1, 0xDD
	.space 0xA0
gSapphireCoinArrow_1_0Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p1.4bpp"
gSapphireCoinArrow_1_1Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p1.4bpp"
gSapphireCoinArrow_1_2PlusLit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1_filler.4bpp"
gSapphireCoinArrow_5_Under2Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1_filler.4bpp"
gSapphireCoinArrow_5_2Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1_filler.4bpp"
gSapphireCoinArrow_5_3Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p1.4bpp"
gSapphireCoinArrow_10_Under2Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1_filler.4bpp"
gSapphireCoinArrow_10_2Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1_filler.4bpp"
gSapphireCoinArrow_10_3Lit_Mid_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1_filler.4bpp"
gSapphireCoinArrow_1_0Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p2.4bpp"
gSapphireCoinArrow_1_1Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p2.4bpp"
gSapphireCoinArrow_1_2PlusLit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p2.4bpp"
gSapphireCoinArrow_5_Under2Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p2.4bpp"
gSapphireCoinArrow_5_2Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p2.4bpp"
gSapphireCoinArrow_5_3Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p2.4bpp"
gSapphireCoinArrow_10_Under2Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2_filler.4bpp"
gSapphireCoinArrow_10_2Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2_filler.4bpp"
gSapphireCoinArrow_10_3Lit_Bot_Fr::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2_filler.4bpp"
gSapphireGetArrow_G_0Lit_Top_Fr:: @ 0x08498760
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_0_fr.4bpp"
gSapphireGetArrow_G_1Lit_Top_Fr:: @ 0x084987C0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_0_fr.4bpp"
gSapphireGetArrow_G_2PlusLit_Top_Fr:: @ 0x08498820
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_0_fr.4bpp"
	.space 0x20
gSapphireGetArrow_E_0Lit_Top_Fr:: @ 0x084988A0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_0_fr.4bpp"
	.space 0x20
gSapphireGetArrow_E_1Lit_Top_Fr:: @ 0x08498900
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_0_fr.4bpp"
	.space 0x20
gSapphireGetArrow_E_2Lit_Top_Fr:: @ 0x08498960
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_0_fr.4bpp"
	.space 0x20
gSapphireGetArrow_E_3Lit_Top_Fr:: @ 0x084989C0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_0_fr.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_Under2Lit_Top_Fr:: @ 0x08498A20
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_0_fr.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_2Lit_Top_Fr:: @ 0x08498A80
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_0_fr.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_3Lit_Top_Fr:: @ 0x08498AE0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_0_fr.4bpp"
	.space 0x40
gSapphireGetArrow_G_0Lit_Mid_Fr:: @ 0x08498B60
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_1_fr.4bpp"
gSapphireGetArrow_G_1Lit_Mid_Fr:: @ 0x08498BC0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_1_fr.4bpp"
gSapphireGetArrow_G_2PlusLit_Mid_Fr:: @ 0x08498C20
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_fr.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_filler_fr.4bpp"
gSapphireGetArrow_E_0Lit_Mid_Fr:: @ 0x08498CA0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_fr.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_filler_fr.4bpp"
gSapphireGetArrow_E_1Lit_Mid_Fr:: @ 0x08498D00
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_fr.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_filler_fr.4bpp"
gSapphireGetArrow_E_2Lit_Mid_Fr:: @ 0x08498D60
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_fr.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_filler_fr.4bpp"
gSapphireGetArrow_E_3Lit_Mid_Fr:: @ 0x08498DC0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_1_fr.4bpp"
gSapphireGetArrow_T_Under2Lit_Mid_Fr:: @ 0x08498E00
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_1_fr.4bpp"
gSapphireGetArrow_T_2Lit_Mid_Fr:: @ 0x08498E60
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_1_fr.4bpp"
gSapphireGetArrow_T_3Lit_Mid_Fr:: @ 0x08498EC0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_1_fr.4bpp"
	.space 0x40
gSapphireGetArrow_G_0Lit_Bot_Fr:: @ 0x08498F60
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_2_fr.4bpp"
gSapphireGetArrow_G_1Lit_Bot_Fr:: @ 0x08498FC0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_2_fr.4bpp"
gSapphireGetArrow_G_2PlusLit_Bot_Fr:: @ 0x08499020
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_2_fr.4bpp"
gSapphireGetArrow_E_0Lit_Bot_Fr:: @ 0x08499080
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_2_fr.4bpp"
gSapphireGetArrow_E_1Lit_Bot_Fr:: @ 0x084990E0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_2_fr.4bpp"
gSapphireGetArrow_E_2Lit_Bot_Fr:: @ 0x08499140
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_2_fr.4bpp"
gSapphireGetArrow_E_3Lit_Bot_Fr:: @ 0x084991A0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_2_fr.4bpp"
gSapphireGetArrow_T_Under2Lit_Bot_Fr:: @ 0x08499200
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_2_fr.4bpp"
	.space 0x20
gSapphireGetArrow_T_2Lit_Bot_Fr:: @ 0x08499260
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_2_fr.4bpp"
	.space 0x20
gSapphireGetArrow_T_3Lit_Bot_Fr:: @ 0x084992C0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_2_fr.4bpp"
	.space 0x80
gSapphireEvoArrow_E_0Lit_Top_De:: @ 0x08499380
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_0_de.4bpp"
gSapphireEvoArrow_E_1Lit_Top_De:: @ 0x084993E0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_0_de.4bpp"
gSapphireEvoArrow_E_2Lit_Top_De:: @ 0x08499440
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_0_de.4bpp"
gSapphireEvoArrow_V_0Lit_Top_De:: @ 0x084994A0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_0_de.4bpp"
gSapphireEvoArrow_V_1Lit_Top_De:: @ 0x08499500
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_0_de.4bpp"
gSapphireEvoArrow_V_2Lit_Top_De:: @ 0x08499560
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_0_de.4bpp"
gSapphireEvoArrow_V_3Lit_Top_De:: @ 0x084995C0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_0_de.4bpp"
gSapphireEvoArrow_O_Under2Lit_Top_De:: @ 0x08499620
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_0_de.4bpp"
gSapphireEvoArrow_O_2Lit_Top_De:: @ 0x08499680
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_0_de.4bpp"
gSapphireEvoArrow_O_3Lit_Top_De:: @ 0x084996E0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_0_de.4bpp"
	.space 0x40
gSapphireEvoArrow_E_0Lit_Mid_De:: @ 0x08499780
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_1_de.4bpp"
gSapphireEvoArrow_E_1Lit_Mid_De:: @ 0x084997E0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_1_de.4bpp"
gSapphireEvoArrow_E_2Lit_Mid_De:: @ 0x08499840
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_1_de.4bpp"
gSapphireEvoArrow_V_0Lit_Mid_De:: @ 0x084998A0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_1_de.4bpp"
gSapphireEvoArrow_V_1Lit_Mid_De:: @ 0x08499900
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_1_de.4bpp"
gSapphireEvoArrow_V_2Lit_Mid_De:: @ 0x08499960
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_1_de.4bpp"
gSapphireEvoArrow_V_3Lit_Mid_De:: @ 0x084999C0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_1_de.4bpp"
gSapphireEvoArrow_O_Under2Lit_Mid_De:: @ 0x08499A20
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_1_de.4bpp"
gSapphireEvoArrow_O_2Lit_Mid_De:: @ 0x08499A80
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_1_de.4bpp"
gSapphireEvoArrow_O_3Lit_Mid_De:: @ 0x08499AE0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_1_de.4bpp"
	.space 0x40
gSapphireEvoArrow_E_0Lit_Bot_De:: @ 0x08499B80
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_2_de.4bpp"
gSapphireEvoArrow_E_1Lit_Bot_De:: @ 0x08499BE0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_2_de.4bpp"
gSapphireEvoArrow_E_2Lit_Bot_De:: @ 0x08499C40
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_2_de.4bpp"
gSapphireEvoArrow_V_0Lit_Bot_De:: @ 0x08499CA0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_2_de.4bpp"
gSapphireEvoArrow_V_1Lit_Bot_De:: @ 0x08499D00
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_2_de.4bpp"
gSapphireEvoArrow_V_2Lit_Bot_De:: @ 0x08499D60
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_2_de.4bpp"
gSapphireEvoArrow_V_3Lit_Bot_De:: @ 0x08499DC0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_2_de.4bpp"
	.space 0x20
gSapphireEvoArrow_O_Under2Lit_Bot_De:: @ 0x08499E40
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_2_de.4bpp"
	.space 0x20
gSapphireEvoArrow_O_2Lit_Bot_De:: @ 0x08499EA0
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_2_de.4bpp"
	.space 0x20
gSapphireEvoArrow_O_3Lit_Bot_De:: @ 0x08499F00
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_2_de.4bpp"
	.space 0x40
gSapphireCoinArrow_1_0Lit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p0_de.4bpp"
	.space 0x20
gSapphireCoinArrow_1_1Lit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p0_de.4bpp"
	.space 0x20
gSapphireCoinArrow_1_2PlusLit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0_filler_de.4bpp"
gSapphireCoinArrow_5_Under2Lit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0_filler_de.4bpp"
gSapphireCoinArrow_5_2Lit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0_filler_de.4bpp"
gSapphireCoinArrow_5_3Lit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p0_de.4bpp"
gSapphireCoinArrow_10_Under2Lit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p0_de.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCoinArrow_10_2Lit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p0_de.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCoinArrow_10_3Lit_Top_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p0_de.4bpp"
	.fill 0x20, 1, 0xDD
	.space 0xA0
gSapphireCoinArrow_1_0Lit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p1_de.4bpp"
gSapphireCoinArrow_1_1Lit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p1_de.4bpp"
gSapphireCoinArrow_1_2PlusLit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1_filler_de.4bpp"
gSapphireCoinArrow_5_Under2Lit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1_filler_de.4bpp"
gSapphireCoinArrow_5_2Lit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1_filler_de.4bpp"
gSapphireCoinArrow_5_3Lit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p1_de.4bpp"
gSapphireCoinArrow_10_Under2Lit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1_filler_de.4bpp"
gSapphireCoinArrow_10_2Lit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1_filler_de.4bpp"
gSapphireCoinArrow_10_3Lit_Mid_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1_filler_de.4bpp"
gSapphireCoinArrow_1_0Lit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p2_de.4bpp"
gSapphireCoinArrow_1_1Lit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p2_de.4bpp"
gSapphireCoinArrow_1_2PlusLit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p2_de.4bpp"
gSapphireCoinArrow_5_Under2Lit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p2_de.4bpp"
gSapphireCoinArrow_5_2Lit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p2_de.4bpp"
gSapphireCoinArrow_5_3Lit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p2_de.4bpp"
gSapphireCoinArrow_10_Under2Lit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2_filler_de.4bpp"
gSapphireCoinArrow_10_2Lit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2_filler_de.4bpp"
gSapphireCoinArrow_10_3Lit_Bot_De::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2_de.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2_filler_de.4bpp"
gSapphireGetArrow_G_0Lit_Top_De:: @ 0x0849AB80
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_0_de.4bpp"
gSapphireGetArrow_G_1Lit_Top_De:: @ 0x0849ABE0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_0_de.4bpp"
gSapphireGetArrow_G_2PlusLit_Top_De:: @ 0x0849AC40
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_0_de.4bpp"
	.space 0x20
gSapphireGetArrow_E_0Lit_Top_De:: @ 0x0849ACC0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_0_de.4bpp"
	.space 0x20
gSapphireGetArrow_E_1Lit_Top_De:: @ 0x0849AD20
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_0_de.4bpp"
	.space 0x20
gSapphireGetArrow_E_2Lit_Top_De:: @ 0x0849AD80
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_0_de.4bpp"
	.space 0x20
gSapphireGetArrow_E_3Lit_Top_De:: @ 0x0849ADE0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_0_de.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_Under2Lit_Top_De:: @ 0x0849AE40
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_0_de.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_2Lit_Top_De:: @ 0x0849AEA0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_0_de.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_3Lit_Top_De:: @ 0x0849AF00
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_0_de.4bpp"
	.space 0x40
gSapphireGetArrow_G_0Lit_Mid_De:: @ 0x0849AF80
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_1_de.4bpp"
gSapphireGetArrow_G_1Lit_Mid_De:: @ 0x0849AFE0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_1_de.4bpp"
gSapphireGetArrow_G_2PlusLit_Mid_De:: @ 0x0849B040
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_de.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_filler_de.4bpp"
gSapphireGetArrow_E_0Lit_Mid_De:: @ 0x0849B0C0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_de.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_filler_de.4bpp"
gSapphireGetArrow_E_1Lit_Mid_De:: @ 0x0849B120
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_de.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_filler_de.4bpp"
gSapphireGetArrow_E_2Lit_Mid_De:: @ 0x0849B180
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_de.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_filler_de.4bpp"
gSapphireGetArrow_E_3Lit_Mid_De:: @ 0x0849B1E0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_1_de.4bpp"
gSapphireGetArrow_T_Under2Lit_Mid_De:: @ 0x0849B220
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_1_de.4bpp"
gSapphireGetArrow_T_2Lit_Mid_De:: @ 0x0849B280
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_1_de.4bpp"
gSapphireGetArrow_T_3Lit_Mid_De:: @ 0x0849B2E0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_1_de.4bpp"
	.space 0x40
gSapphireGetArrow_G_0Lit_Bot_De:: @ 0x0849B380
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_2_de.4bpp"
gSapphireGetArrow_G_1Lit_Bot_De:: @ 0x0849B3E0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_2_de.4bpp"
gSapphireGetArrow_G_2PlusLit_Bot_De:: @ 0x0849B440
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_2_de.4bpp"
gSapphireGetArrow_E_0Lit_Bot_De:: @ 0x0849B4A0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_2_de.4bpp"
gSapphireGetArrow_E_1Lit_Bot_De:: @ 0x0849B500
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_2_de.4bpp"
gSapphireGetArrow_E_2Lit_Bot_De:: @ 0x0849B560
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_2_de.4bpp"
gSapphireGetArrow_E_3Lit_Bot_De:: @ 0x0849B5C0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_2_de.4bpp"
gSapphireGetArrow_T_Under2Lit_Bot_De:: @ 0x0849B620
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_2_de.4bpp"
	.space 0x20
gSapphireGetArrow_T_2Lit_Bot_De:: @ 0x0849B680
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_2_de.4bpp"
	.space 0x20
gSapphireGetArrow_T_3Lit_Bot_De:: @ 0x0849B6E0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_2_de.4bpp"
	.space 0x80
gSapphireEvoArrow_E_0Lit_Top_It:: @ 0x0849B7A0
	@ copy of the English data, not used by the code
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_0.4bpp"
gSapphireEvoArrow_E_1Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_0.4bpp"
gSapphireEvoArrow_E_2Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_0.4bpp"
gSapphireEvoArrow_V_0Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_0.4bpp"
gSapphireEvoArrow_V_1Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_0.4bpp"
gSapphireEvoArrow_V_2Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_0.4bpp"
gSapphireEvoArrow_V_3Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_0.4bpp"
gSapphireEvoArrow_O_Under2Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_0.4bpp"
gSapphireEvoArrow_O_2Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_0.4bpp"
gSapphireEvoArrow_O_3Lit_Top_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_0.4bpp"
	.space 0x40
gSapphireEvoArrow_E_0Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_1.4bpp"
gSapphireEvoArrow_E_1Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_1.4bpp"
gSapphireEvoArrow_E_2Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_1.4bpp"
gSapphireEvoArrow_V_0Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_1.4bpp"
gSapphireEvoArrow_V_1Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_1.4bpp"
gSapphireEvoArrow_V_2Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_1.4bpp"
gSapphireEvoArrow_V_3Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_1.4bpp"
gSapphireEvoArrow_O_Under2Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_1.4bpp"
gSapphireEvoArrow_O_2Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_1.4bpp"
gSapphireEvoArrow_O_3Lit_Mid_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_1.4bpp"
	.space 0x40
gSapphireEvoArrow_E_0Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_2.4bpp"
gSapphireEvoArrow_E_1Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_2.4bpp"
gSapphireEvoArrow_E_2Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_2.4bpp"
gSapphireEvoArrow_V_0Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_2.4bpp"
gSapphireEvoArrow_V_1Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_2.4bpp"
gSapphireEvoArrow_V_2Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_2.4bpp"
gSapphireEvoArrow_V_3Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_Under2Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_2Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_3Lit_Bot_It::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_2.4bpp"
	.space 0x40
gSapphireCoinArrow_1_0Lit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
	.space 0x20
gSapphireCoinArrow_1_1Lit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p0.4bpp"
	.space 0x20
gSapphireCoinArrow_1_2PlusLit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0_filler.4bpp"
gSapphireCoinArrow_5_Under2Lit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0_filler.4bpp"
gSapphireCoinArrow_5_2Lit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0_filler.4bpp"
gSapphireCoinArrow_5_3Lit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p0.4bpp"
gSapphireCoinArrow_10_Under2Lit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCoinArrow_10_2Lit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p0.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCoinArrow_10_3Lit_Top_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
	.fill 0x20, 1, 0xDD
	.space 0xA0
gSapphireCoinArrow_1_0Lit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p1.4bpp"
gSapphireCoinArrow_1_1Lit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p1.4bpp"
gSapphireCoinArrow_1_2PlusLit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1_filler.4bpp"
gSapphireCoinArrow_5_Under2Lit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1_filler.4bpp"
gSapphireCoinArrow_5_2Lit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1_filler.4bpp"
gSapphireCoinArrow_5_3Lit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p1.4bpp"
gSapphireCoinArrow_10_Under2Lit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1_filler.4bpp"
gSapphireCoinArrow_10_2Lit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1_filler.4bpp"
gSapphireCoinArrow_10_3Lit_Mid_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1_filler.4bpp"
gSapphireCoinArrow_1_0Lit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p2.4bpp"
gSapphireCoinArrow_1_1Lit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p2.4bpp"
gSapphireCoinArrow_1_2PlusLit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p2.4bpp"
gSapphireCoinArrow_5_Under2Lit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p2.4bpp"
gSapphireCoinArrow_5_2Lit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p2.4bpp"
gSapphireCoinArrow_5_3Lit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p2.4bpp"
gSapphireCoinArrow_10_Under2Lit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2_filler.4bpp"
gSapphireCoinArrow_10_2Lit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2_filler.4bpp"
gSapphireCoinArrow_10_3Lit_Bot_It::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2_filler.4bpp"
gSapphireGetArrow_G_0Lit_Top_It:: @ 0x0849CFA0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_0_it.4bpp"
gSapphireGetArrow_G_1Lit_Top_It:: @ 0x0849D000
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_0_it.4bpp"
gSapphireGetArrow_G_2PlusLit_Top_It:: @ 0x0849D060
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_0_it.4bpp"
	.space 0x20
gSapphireGetArrow_E_0Lit_Top_It:: @ 0x0849D0E0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_0_it.4bpp"
	.space 0x20
gSapphireGetArrow_E_1Lit_Top_It:: @ 0x0849D140
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_0_it.4bpp"
	.space 0x20
gSapphireGetArrow_E_2Lit_Top_It:: @ 0x0849D1A0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_0_it.4bpp"
	.space 0x20
gSapphireGetArrow_E_3Lit_Top_It:: @ 0x0849D200
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_0_it.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_Under2Lit_Top_It:: @ 0x0849D260
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_0_it.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_2Lit_Top_It:: @ 0x0849D2C0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_0_it.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_3Lit_Top_It:: @ 0x0849D320
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_0_it.4bpp"
	.space 0x40
gSapphireGetArrow_G_0Lit_Mid_It:: @ 0x0849D3A0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_1_it.4bpp"
gSapphireGetArrow_G_1Lit_Mid_It:: @ 0x0849D400
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_1_it.4bpp"
gSapphireGetArrow_G_2PlusLit_Mid_It:: @ 0x0849D460
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_it.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_filler_it.4bpp"
gSapphireGetArrow_E_0Lit_Mid_It:: @ 0x0849D4E0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_it.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_filler_it.4bpp"
gSapphireGetArrow_E_1Lit_Mid_It:: @ 0x0849D540
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_it.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_filler_it.4bpp"
gSapphireGetArrow_E_2Lit_Mid_It:: @ 0x0849D5A0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_it.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_filler_it.4bpp"
gSapphireGetArrow_E_3Lit_Mid_It:: @ 0x0849D600
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_1_it.4bpp"
gSapphireGetArrow_T_Under2Lit_Mid_It:: @ 0x0849D640
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_1_it.4bpp"
gSapphireGetArrow_T_2Lit_Mid_It:: @ 0x0849D6A0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_1_it.4bpp"
gSapphireGetArrow_T_3Lit_Mid_It:: @ 0x0849D700
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_1_it.4bpp"
	.space 0x40
gSapphireGetArrow_G_0Lit_Bot_It:: @ 0x0849D7A0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_2_it.4bpp"
gSapphireGetArrow_G_1Lit_Bot_It:: @ 0x0849D800
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_2_it.4bpp"
gSapphireGetArrow_G_2PlusLit_Bot_It:: @ 0x0849D860
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_2_it.4bpp"
gSapphireGetArrow_E_0Lit_Bot_It:: @ 0x0849D8C0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_2_it.4bpp"
gSapphireGetArrow_E_1Lit_Bot_It:: @ 0x0849D920
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_2_it.4bpp"
gSapphireGetArrow_E_2Lit_Bot_It:: @ 0x0849D980
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_2_it.4bpp"
gSapphireGetArrow_E_3Lit_Bot_It:: @ 0x0849D9E0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_2_it.4bpp"
gSapphireGetArrow_T_Under2Lit_Bot_It:: @ 0x0849DA40
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_2_it.4bpp"
	.space 0x20
gSapphireGetArrow_T_2Lit_Bot_It:: @ 0x0849DAA0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_2_it.4bpp"
	.space 0x20
gSapphireGetArrow_T_3Lit_Bot_It:: @ 0x0849DB00
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_2_it.4bpp"
	.space 0x80
gSapphireEvoArrow_E_0Lit_Top_Es:: @ 0x0849DBC0
	@ copy of the English data, not used by the code
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_0.4bpp"
gSapphireEvoArrow_E_1Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_0.4bpp"
gSapphireEvoArrow_E_2Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_0.4bpp"
gSapphireEvoArrow_V_0Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_0.4bpp"
gSapphireEvoArrow_V_1Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_0.4bpp"
gSapphireEvoArrow_V_2Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_0.4bpp"
gSapphireEvoArrow_V_3Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_0.4bpp"
gSapphireEvoArrow_O_Under2Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_0.4bpp"
gSapphireEvoArrow_O_2Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_0.4bpp"
gSapphireEvoArrow_O_3Lit_Top_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_0.4bpp"
	.space 0x40
gSapphireEvoArrow_E_0Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_1.4bpp"
gSapphireEvoArrow_E_1Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_1.4bpp"
gSapphireEvoArrow_E_2Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_1.4bpp"
gSapphireEvoArrow_V_0Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_1.4bpp"
gSapphireEvoArrow_V_1Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_1.4bpp"
gSapphireEvoArrow_V_2Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_1.4bpp"
gSapphireEvoArrow_V_3Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_1.4bpp"
gSapphireEvoArrow_O_Under2Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_1.4bpp"
gSapphireEvoArrow_O_2Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_1.4bpp"
gSapphireEvoArrow_O_3Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_1.4bpp"
	.space 0x40
gSapphireEvoArrow_E_0Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_2.4bpp"
gSapphireEvoArrow_E_1Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_2.4bpp"
gSapphireEvoArrow_E_2Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_2.4bpp"
gSapphireEvoArrow_V_0Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_2.4bpp"
gSapphireEvoArrow_V_1Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_2.4bpp"
gSapphireEvoArrow_V_2Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_2.4bpp"
gSapphireEvoArrow_V_3Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_Under2Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_2Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_2.4bpp"
	.space 0x20
gSapphireEvoArrow_O_3Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_2.4bpp"
	.space 0x40
gSapphireCoinArrow_1_0Lit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
	.space 0x20
gSapphireCoinArrow_1_1Lit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p0.4bpp"
	.space 0x20
gSapphireCoinArrow_1_2PlusLit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0_filler.4bpp"
gSapphireCoinArrow_5_Under2Lit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0_filler.4bpp"
gSapphireCoinArrow_5_2Lit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0_filler.4bpp"
gSapphireCoinArrow_5_3Lit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p0.4bpp"
gSapphireCoinArrow_10_Under2Lit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCoinArrow_10_2Lit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p0.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCoinArrow_10_3Lit_Top_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
	.fill 0x20, 1, 0xDD
	.space 0xA0
gSapphireCoinArrow_1_0Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p1.4bpp"
gSapphireCoinArrow_1_1Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p1.4bpp"
gSapphireCoinArrow_1_2PlusLit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1_filler.4bpp"
gSapphireCoinArrow_5_Under2Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1_filler.4bpp"
gSapphireCoinArrow_5_2Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1_filler.4bpp"
gSapphireCoinArrow_5_3Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p1.4bpp"
gSapphireCoinArrow_10_Under2Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1_filler.4bpp"
gSapphireCoinArrow_10_2Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1_filler.4bpp"
gSapphireCoinArrow_10_3Lit_Mid_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1_filler.4bpp"
gSapphireCoinArrow_1_0Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p2.4bpp"
gSapphireCoinArrow_1_1Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p2.4bpp"
gSapphireCoinArrow_1_2PlusLit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p2.4bpp"
gSapphireCoinArrow_5_Under2Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p2.4bpp"
gSapphireCoinArrow_5_2Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p2.4bpp"
gSapphireCoinArrow_5_3Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p2.4bpp"
gSapphireCoinArrow_10_Under2Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2_filler.4bpp"
gSapphireCoinArrow_10_2Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2_filler.4bpp"
gSapphireCoinArrow_10_3Lit_Bot_Es::
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
	.incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2_filler.4bpp"
gSapphireGetArrow_G_0Lit_Top_Es:: @ 0x0849F3C0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_0_es.4bpp"
gSapphireGetArrow_G_1Lit_Top_Es:: @ 0x0849F420
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_0_es.4bpp"
gSapphireGetArrow_G_2PlusLit_Top_Es:: @ 0x0849F480
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_0_es.4bpp"
	.space 0x20
gSapphireGetArrow_E_0Lit_Top_Es:: @ 0x0849F500
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_0_es.4bpp"
	.space 0x20
gSapphireGetArrow_E_1Lit_Top_Es:: @ 0x0849F560
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_0_es.4bpp"
	.space 0x20
gSapphireGetArrow_E_2Lit_Top_Es:: @ 0x0849F5C0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_0_es.4bpp"
	.space 0x20
gSapphireGetArrow_E_3Lit_Top_Es:: @ 0x0849F620
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_0_es.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_Under2Lit_Top_Es:: @ 0x0849F680
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_0_es.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_2Lit_Top_Es:: @ 0x0849F6E0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_0_es.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireGetArrow_T_3Lit_Top_Es:: @ 0x0849F740
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_0_es.4bpp"
	.space 0x40
gSapphireGetArrow_G_0Lit_Mid_Es:: @ 0x0849F7C0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_1_es.4bpp"
gSapphireGetArrow_G_1Lit_Mid_Es:: @ 0x0849F820
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_1_es.4bpp"
gSapphireGetArrow_G_2PlusLit_Mid_Es:: @ 0x0849F880
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_es.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_filler_es.4bpp"
gSapphireGetArrow_E_0Lit_Mid_Es:: @ 0x0849F900
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_es.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_filler_es.4bpp"
gSapphireGetArrow_E_1Lit_Mid_Es:: @ 0x0849F960
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_es.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_filler_es.4bpp"
gSapphireGetArrow_E_2Lit_Mid_Es:: @ 0x0849F9C0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_es.4bpp"
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_filler_es.4bpp"
gSapphireGetArrow_E_3Lit_Mid_Es:: @ 0x0849FA20
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_1_es.4bpp"
gSapphireGetArrow_T_Under2Lit_Mid_Es:: @ 0x0849FA60
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_1_es.4bpp"
gSapphireGetArrow_T_2Lit_Mid_Es:: @ 0x0849FAC0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_1_es.4bpp"
gSapphireGetArrow_T_3Lit_Mid_Es:: @ 0x0849FB20
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_1_es.4bpp"
	.space 0x40
gSapphireGetArrow_G_0Lit_Bot_Es:: @ 0x0849FBC0
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_2_es.4bpp"
gSapphireGetArrow_G_1Lit_Bot_Es:: @ 0x0849FC20
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_2_es.4bpp"
gSapphireGetArrow_G_2PlusLit_Bot_Es:: @ 0x0849FC80
	.incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_2_es.4bpp"
gSapphireGetArrow_E_0Lit_Bot_Es:: @ 0x0849FCE0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_2_es.4bpp"
gSapphireGetArrow_E_1Lit_Bot_Es:: @ 0x0849FD40
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_2_es.4bpp"
gSapphireGetArrow_E_2Lit_Bot_Es:: @ 0x0849FDA0
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_2_es.4bpp"
gSapphireGetArrow_E_3Lit_Bot_Es:: @ 0x0849FE00
	.incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_2_es.4bpp"
gSapphireGetArrow_T_Under2Lit_Bot_Es:: @ 0x0849FE60
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_2_es.4bpp"
	.space 0x20
gSapphireGetArrow_T_2Lit_Bot_Es:: @ 0x0849FEC0
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_2_es.4bpp"
	.space 0x20
gSapphireGetArrow_T_3Lit_Bot_Es:: @ 0x0849FF20
	.incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_2_es.4bpp"
	.space 0x80
gSapphireBallPowerUpLight0off:: @ 0x0849FFE0
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_0_off.4bpp"

gSapphireBallPowerUpLight0on:: @ 0x084A0020
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_0_on.4bpp"

gSapphireBallPowerUpLight1off:: @ 0x084A0060
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_1_off.4bpp"

gSapphireBallPowerUpLight1on:: @ 0x084A00A0
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_1_on.4bpp"

gSapphireBallPowerUpLight2off:: @ 0x084A00E0
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_2_off.4bpp"

gSapphireBallPowerUpLight2on:: @ 0x084A0120
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_2_on.4bpp"


@ 'H' 'o' 'l' 'e' Lights

gSapphireHoleLightH_Off:: @ 0x084A0160
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_off.4bpp"

gSapphireHoleLightH_On:: @ 0x084A01A0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_on.4bpp"

gSapphireHoleLightO_Off:: @ 0x084A01E0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_off.4bpp"

gSapphireHoleLightO_On:: @ 0x084A0220
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_on.4bpp"

gSapphireHoleLightL_Off:: @ 0x084A0260
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_off.4bpp"

gSapphireHoleLightL_On:: @ 0x084A02A0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_on.4bpp"

gSapphireHoleLightE_Off:: @ 0x084A02E0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_off.4bpp"

gSapphireHoleLightE_On:: @ 0x084A0320
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_on.4bpp"



@ Catch light arrows / Center trap / hatch machine / P square indicator
@ Data is mostly separate... but cuts across rows into an otherwise blank



gSapphireCatchLightState0Top:: @ 0x084A0360
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_top.4bpp"

gSapphireCatchLightState1Top:: @ 0x084A03A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_top.4bpp"
	.space 0x380

gSapphireCatchLightState0Bot:: @ 0x084A0760
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_bot.4bpp"

gSapphireCatchLightState1Bot:: @ 0x084A07A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_bot.4bpp"

gSapphireTrapIndicatorState0Top:: @ 0x084A07E0
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state0_top.4bpp"

gSapphireTrapIndicatorState1Top:: @ 0x084A0820
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state1_top.4bpp"

gSapphireTrapIndicatorState2Top:: @ 0x084A0860
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state2_top.4bpp"

gSapphireCatchLightSlot0State2Top:: @ 0x084A08A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_top.4bpp"

gSapphireCatchLightSlot0State3Top:: @ 0x084A08E0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_top.4bpp"

gSapphireCatchLightSlot1State2Top:: @ 0x084A0920
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_top.4bpp"

gSapphireCatchLightSlot1State3Top:: @ 0x084A0960
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_top.4bpp"

gSapphireCatchLightSlot2State2Top:: @ 0x084A09A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_top.4bpp"

gSapphireCatchLightSlot2State3Top:: @ 0x084A09E0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_top.4bpp"

gSapphireCatchLightSlot0State4Top:: @ 0x084A0A20
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_top.4bpp"

gSapphireCatchLightSlot0State5Top:: @ 0x084A0A60
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_top.4bpp"

gSapphireCatchLightSlot1State4Top:: @ 0x084A0AA0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_top.4bpp"

gSapphireCatchLightSlot1State5Top:: @ 0x084A0AE0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_top.4bpp"

gSapphireCatchLightSlot2State4Top:: @ 0x084A0B20
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_top.4bpp"

gSapphireCatchLightSlot2State5Top:: @ 0x084A0B60
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_top.4bpp"

gHatchMachineSeg0IdleA:: @ 0x084A0BA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_a.4bpp"

gSapphireTrapIndicatorState0Bot:: @ 0x084A0BE0
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state0_bot.4bpp"

gSapphireTrapIndicatorState1Bot:: @ 0x084A0C20
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state1_bot.4bpp"

gSapphireTrapIndicatorState2Bot:: @ 0x084A0C60
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state2_bot.4bpp"

gSapphireCatchLightSlot0State2Bot:: @ 0x084A0CA0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_bot.4bpp"

gSapphireCatchLightSlot0State3Bot:: @ 0x084A0CE0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_bot.4bpp"

gSapphireCatchLightSlot1State2Bot:: @ 0x084A0D20
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_bot.4bpp"

gSapphireCatchLightSlot1State3Bot:: @ 0x084A0D60
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_bot.4bpp"

gSapphireCatchLightSlot2State2Bot:: @ 0x084A0DA0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_bot.4bpp"

gSapphireCatchLightSlot2State3Bot:: @ 0x084A0DE0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_bot.4bpp"

gSapphireCatchLightSlot0State4Bot:: @ 0x084A0E20
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_bot.4bpp"

gSapphireCatchLightSlot0State5Bot:: @ 0x084A0E60
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_bot.4bpp"

gSapphireCatchLightSlot1State4Bot:: @ 0x084A0EA0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_bot.4bpp"

gSapphireCatchLightSlot1State5Bot:: @ 0x084A0EE0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_bot.4bpp"

gSapphireCatchLightSlot2State4Bot:: @ 0x084A0F20
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_bot.4bpp"

gSapphireCatchLightSlot2State5Bot:: @ 0x084A0F60
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_bot.4bpp"




gHatchMachineSeg0IdleB:: @ 0x084A0FA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_b.4bpp"

gHatchMachineSeg0HitA:: @ 0x084A0FE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_a.4bpp"

gHatchMachineSeg1IdleA:: @ 0x084A1020
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_a.4bpp"

gHatchMachineSeg1HitA:: @ 0x084A1060
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_a.4bpp"

gHatchMachineSeg2IdleA:: @ 0x084A10A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_a.4bpp"

gHatchMachineSeg2HitA:: @ 0x084A10E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_a.4bpp"
    .space 0x80

gHatchMachineSeg4IdleA:: @ 0x084A11A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_a.4bpp"

gHatchMachineSeg4HitA:: @ 0x084A11E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_a.4bpp"

gHatchMachineSeg5IdleA:: @ 0x084A1220
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_a.4bpp"

gHatchMachineSeg5HitA:: @ 0x084A1260
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_a.4bpp"

gHatchMachineSeg6IdleA:: @ 0x084A12A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_a.4bpp"

gHatchMachineSeg6HitA:: @ 0x084A12E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_a.4bpp"

gHatchMachineSeg7IdleA:: @ 0x084A1320
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_a.4bpp"

gHatchMachineSeg7HitA:: @ 0x084A1360
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_a.4bpp"

gHatchMachineSeg8IdleA:: @ 0x084A13A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_a.4bpp"

gHatchMachineSeg0HitB:: @ 0x084A13E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_b.4bpp"

gHatchMachineSeg1IdleB:: @ 0x084A1420
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_b.4bpp"

gHatchMachineSeg1HitB:: @ 0x084A1460
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_b.4bpp"

gHatchMachineSeg2IdleB:: @ 0x084A14A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_b.4bpp"

gHatchMachineSeg2HitB:: @ 0x084A14E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_b.4bpp"

gHatchMachineSeg3Idle:: @ 0x084A1520
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_idle.4bpp"

gHatchMachineSeg3Hit:: @ 0x084A1560
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_hit.4bpp"

gHatchMachineSeg4IdleB:: @ 0x084A15A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_b.4bpp"

gHatchMachineSeg4HitB:: @ 0x084A15E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_b.4bpp"

gHatchMachineSeg5IdleB:: @ 0x084A1620
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_b.4bpp"

gHatchMachineSeg5HitB:: @ 0x084A1660
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_b.4bpp"

gHatchMachineSeg6IdleB:: @ 0x084A16A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_b.4bpp"

gHatchMachineSeg6HitB:: @ 0x084A16E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_b.4bpp"

gHatchMachineSeg7IdleB:: @ 0x084A1720
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_b.4bpp"

gHatchMachineSeg7HitB:: @ 0x084A1760
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_b.4bpp"

gHatchMachineSeg8IdleB:: @ 0x084A17A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_b.4bpp"

gHatchMachineSeg8HitA:: @ 0x084A17E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_a.4bpp"

gHatchMachineSeg9IdleA:: @ 0x084A1820
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_a.4bpp"

gHatchMachineSeg9HitA:: @ 0x084A1860
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_a.4bpp"



gSapphirePSquareFrame0Top:: @ 0x084A18A0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame0_top.4bpp"

gSapphirePSquareFrame1Top:: @ 0x084A18E0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame1_top.4bpp"

gSapphirePSquareFrame2Top:: @ 0x084A1920
    .incbin "graphics/stage/sapphire/p_square/p_square_frame2_top.4bpp"

gSapphirePSquareFrame3Top:: @ 0x084A1960
    .incbin "graphics/stage/sapphire/p_square/p_square_frame3_top.4bpp"

gSapphirePSquareFrame4Top:: @ 0x084A19A0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame4_top.4bpp"
    .space 0x200

gHatchMachineSeg8HitB:: @ 0x084A1BE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_b.4bpp"

gHatchMachineSeg9IdleB:: @ 0x084A1C20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_b.4bpp"

gHatchMachineSeg9HitB:: @ 0x084A1C60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_b.4bpp"



gSapphirePSquareFrame0Bot:: @ 0x084A1CA0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame0_bot.4bpp"

gSapphirePSquareFrame1Bot:: @ 0x084A1CE0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame1_bot.4bpp"

gSapphirePSquareFrame2Bot:: @ 0x084A1D20
    .incbin "graphics/stage/sapphire/p_square/p_square_frame2_bot.4bpp"

gSapphirePSquareFrame3Bot:: @ 0x084A1D60
    .incbin "graphics/stage/sapphire/p_square/p_square_frame3_bot.4bpp"




@ Saver light space. Area has more tiles than are actually used.
@ Actual usage is 2 rows of 7 tiles, one row of 6 tiles, one row 2 tiles
@ Data in memory has those as rectangles, and a different offset.
@ Leaving as is, without carving out the 'space' and separate carved zones for the junk data.

gSapphirePSquareFrame4Bot:: @ 0x084A1DA0
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_eu.4bpp"
	.space 0x220
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_filler_eu.4bpp"
gSapphireHoleLightH_Off_Fr:: @ 0x084A2180
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_off_fr.4bpp"
gSapphireHoleLightH_On_Fr:: @ 0x084A21C0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_on_fr.4bpp"
gSapphireHoleLightO_Off_Fr:: @ 0x084A2200
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_off_fr.4bpp"
gSapphireHoleLightO_On_Fr:: @ 0x084A2240
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_on_fr.4bpp"
gSapphireHoleLightL_Off_Fr:: @ 0x084A2280
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_off_fr.4bpp"
gSapphireHoleLightL_On_Fr:: @ 0x084A22C0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_on_fr.4bpp"
gSapphireHoleLightE_Off_Fr:: @ 0x084A2300
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_off_fr.4bpp"
gSapphireHoleLightE_On_Fr:: @ 0x084A2340
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_on_fr.4bpp"
gSapphireCatchLightState0Top_Fr:: @ 0x084A2380
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_top_fr.4bpp"
gSapphireCatchLightState1Top_Fr:: @ 0x084A23C0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_top_fr.4bpp"
	.space 0x380
gSapphireCatchLightState0Bot_Fr:: @ 0x084A2780
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_bot_fr.4bpp"
gSapphireCatchLightState1Bot_Fr:: @ 0x084A27C0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_bot_fr.4bpp"
gSapphireTrapIndicatorState0Top_Fr::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state0_top_fr.4bpp"
gSapphireTrapIndicatorState1Top_Fr::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state1_top_fr.4bpp"
gSapphireTrapIndicatorState2Top_Fr::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state2_top_fr.4bpp"
gSapphireCatchLightSlot0State2Top_Fr:: @ 0x084A28C0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_top_fr.4bpp"
gSapphireCatchLightSlot0State3Top_Fr:: @ 0x084A2900
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_top_fr.4bpp"
gSapphireCatchLightSlot1State2Top_Fr:: @ 0x084A2940
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_top_fr.4bpp"
gSapphireCatchLightSlot1State3Top_Fr:: @ 0x084A2980
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_top_fr.4bpp"
gSapphireCatchLightSlot2State2Top_Fr:: @ 0x084A29C0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_top_fr.4bpp"
gSapphireCatchLightSlot2State3Top_Fr:: @ 0x084A2A00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_top_fr.4bpp"
gSapphireCatchLightSlot0State4Top_Fr:: @ 0x084A2A40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_top_fr.4bpp"
gSapphireCatchLightSlot0State5Top_Fr:: @ 0x084A2A80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_top_fr.4bpp"
gSapphireCatchLightSlot1State4Top_Fr:: @ 0x084A2AC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_top_fr.4bpp"
gSapphireCatchLightSlot1State5Top_Fr:: @ 0x084A2B00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_top_fr.4bpp"
gSapphireCatchLightSlot2State4Top_Fr:: @ 0x084A2B40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_top_fr.4bpp"
gSapphireCatchLightSlot2State5Top_Fr:: @ 0x084A2B80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_top_fr.4bpp"
gHatchMachineSeg0IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_a_fr.4bpp"
gSapphireTrapIndicatorState0Bot_Fr::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state0_bot_fr.4bpp"
gSapphireTrapIndicatorState1Bot_Fr::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state1_bot_fr.4bpp"
gSapphireTrapIndicatorState2Bot_Fr::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state2_bot_fr.4bpp"
gSapphireCatchLightSlot0State2Bot_Fr:: @ 0x084A2CC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_bot_fr.4bpp"
gSapphireCatchLightSlot0State3Bot_Fr:: @ 0x084A2D00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_bot_fr.4bpp"
gSapphireCatchLightSlot1State2Bot_Fr:: @ 0x084A2D40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_bot_fr.4bpp"
gSapphireCatchLightSlot1State3Bot_Fr:: @ 0x084A2D80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_bot_fr.4bpp"
gSapphireCatchLightSlot2State2Bot_Fr:: @ 0x084A2DC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_bot_fr.4bpp"
gSapphireCatchLightSlot2State3Bot_Fr:: @ 0x084A2E00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_bot_fr.4bpp"
gSapphireCatchLightSlot0State4Bot_Fr:: @ 0x084A2E40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_bot_fr.4bpp"
gSapphireCatchLightSlot0State5Bot_Fr:: @ 0x084A2E80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_bot_fr.4bpp"
gSapphireCatchLightSlot1State4Bot_Fr:: @ 0x084A2EC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_bot_fr.4bpp"
gSapphireCatchLightSlot1State5Bot_Fr:: @ 0x084A2F00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_bot_fr.4bpp"
gSapphireCatchLightSlot2State4Bot_Fr:: @ 0x084A2F40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_bot_fr.4bpp"
gSapphireCatchLightSlot2State5Bot_Fr:: @ 0x084A2F80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_bot_fr.4bpp"
gHatchMachineSeg0IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_b_fr.4bpp"
gHatchMachineSeg0HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_a_fr.4bpp"
gHatchMachineSeg1IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_a_fr.4bpp"
gHatchMachineSeg1HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_a_fr.4bpp"
gHatchMachineSeg2IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_a_fr.4bpp"
gHatchMachineSeg2HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_a_fr.4bpp"
	.space 0x80
gHatchMachineSeg4IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_a_fr.4bpp"
gHatchMachineSeg4HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_a_fr.4bpp"
gHatchMachineSeg5IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_a_fr.4bpp"
gHatchMachineSeg5HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_a_fr.4bpp"
gHatchMachineSeg6IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_a_fr.4bpp"
gHatchMachineSeg6HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_a_fr.4bpp"
gHatchMachineSeg7IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_a_fr.4bpp"
gHatchMachineSeg7HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_a_fr.4bpp"
gHatchMachineSeg8IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_a_fr.4bpp"
gHatchMachineSeg0HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_b_fr.4bpp"
gHatchMachineSeg1IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_b_fr.4bpp"
gHatchMachineSeg1HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_b_fr.4bpp"
gHatchMachineSeg2IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_b_fr.4bpp"
gHatchMachineSeg2HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_b_fr.4bpp"
gHatchMachineSeg3Idle_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_idle_fr.4bpp"
gHatchMachineSeg3Hit_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_hit_fr.4bpp"
gHatchMachineSeg4IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_b_fr.4bpp"
gHatchMachineSeg4HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_b_fr.4bpp"
gHatchMachineSeg5IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_b_fr.4bpp"
gHatchMachineSeg5HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_b_fr.4bpp"
gHatchMachineSeg6IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_b_fr.4bpp"
gHatchMachineSeg6HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_b_fr.4bpp"
gHatchMachineSeg7IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_b_fr.4bpp"
gHatchMachineSeg7HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_b_fr.4bpp"
gHatchMachineSeg8IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_b_fr.4bpp"
gHatchMachineSeg8HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_a_fr.4bpp"
gHatchMachineSeg9IdleA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_a_fr.4bpp"
gHatchMachineSeg9HitA_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_a_fr.4bpp"
gSapphirePSquareFrame0Top_Fr:: @ 0x084A38C0
	.incbin "graphics/stage/sapphire/p_square/p_square_frame0_top_fr.4bpp"
gSapphirePSquareFrame1Top_Fr:: @ 0x084A3900
	.incbin "graphics/stage/sapphire/p_square/p_square_frame1_top_fr.4bpp"
gSapphirePSquareFrame2Top_Fr:: @ 0x084A3940
	.incbin "graphics/stage/sapphire/p_square/p_square_frame2_top_fr.4bpp"
gSapphirePSquareFrame3Top_Fr:: @ 0x084A3980
	.incbin "graphics/stage/sapphire/p_square/p_square_frame3_top_fr.4bpp"
gSapphirePSquareFrame4Top_Fr:: @ 0x084A39C0
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_top_fr.4bpp"
	.space 0x200
gHatchMachineSeg8HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_b_fr.4bpp"
gHatchMachineSeg9IdleB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_b_fr.4bpp"
gHatchMachineSeg9HitB_Fr::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_b_fr.4bpp"
gSapphirePSquareFrame0Bot_Fr:: @ 0x084A3CC0
	.incbin "graphics/stage/sapphire/p_square/p_square_frame0_bot_fr.4bpp"
gSapphirePSquareFrame1Bot_Fr:: @ 0x084A3D00
	.incbin "graphics/stage/sapphire/p_square/p_square_frame1_bot_fr.4bpp"
gSapphirePSquareFrame2Bot_Fr:: @ 0x084A3D40
	.incbin "graphics/stage/sapphire/p_square/p_square_frame2_bot_fr.4bpp"
gSapphirePSquareFrame3Bot_Fr:: @ 0x084A3D80
	.incbin "graphics/stage/sapphire/p_square/p_square_frame3_bot_fr.4bpp"
gSapphirePSquareFrame4Bot_Fr:: @ 0x084A3DC0
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_fr.4bpp"
	.space 0x220
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_filler_fr.4bpp"
gSapphireHoleLightH_Off_De:: @ 0x084A41A0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_off_de.4bpp"
gSapphireHoleLightH_On_De:: @ 0x084A41E0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_on_de.4bpp"
gSapphireHoleLightO_Off_De:: @ 0x084A4220
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_off_de.4bpp"
gSapphireHoleLightO_On_De:: @ 0x084A4260
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_on_de.4bpp"
gSapphireHoleLightL_Off_De:: @ 0x084A42A0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_off_de.4bpp"
gSapphireHoleLightL_On_De:: @ 0x084A42E0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_on_de.4bpp"
gSapphireHoleLightE_Off_De:: @ 0x084A4320
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_off_de.4bpp"
gSapphireHoleLightE_On_De:: @ 0x084A4360
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_on_de.4bpp"
gSapphireCatchLightState0Top_De:: @ 0x084A43A0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_top_de.4bpp"
gSapphireCatchLightState1Top_De:: @ 0x084A43E0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_top_de.4bpp"
	.space 0x380
gSapphireCatchLightState0Bot_De:: @ 0x084A47A0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_bot_de.4bpp"
gSapphireCatchLightState1Bot_De:: @ 0x084A47E0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_bot_de.4bpp"
gSapphireTrapIndicatorState0Top_De::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state0_top_de.4bpp"
gSapphireTrapIndicatorState1Top_De::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state1_top_de.4bpp"
gSapphireTrapIndicatorState2Top_De::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state2_top_de.4bpp"
gSapphireCatchLightSlot0State2Top_De:: @ 0x084A48E0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_top_de.4bpp"
gSapphireCatchLightSlot0State3Top_De:: @ 0x084A4920
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_top_de.4bpp"
gSapphireCatchLightSlot1State2Top_De:: @ 0x084A4960
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_top_de.4bpp"
gSapphireCatchLightSlot1State3Top_De:: @ 0x084A49A0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_top_de.4bpp"
gSapphireCatchLightSlot2State2Top_De:: @ 0x084A49E0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_top_de.4bpp"
gSapphireCatchLightSlot2State3Top_De:: @ 0x084A4A20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_top_de.4bpp"
gSapphireCatchLightSlot0State4Top_De:: @ 0x084A4A60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_top_de.4bpp"
gSapphireCatchLightSlot0State5Top_De:: @ 0x084A4AA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_top_de.4bpp"
gSapphireCatchLightSlot1State4Top_De:: @ 0x084A4AE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_top_de.4bpp"
gSapphireCatchLightSlot1State5Top_De:: @ 0x084A4B20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_top_de.4bpp"
gSapphireCatchLightSlot2State4Top_De:: @ 0x084A4B60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_top_de.4bpp"
gSapphireCatchLightSlot2State5Top_De:: @ 0x084A4BA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_top_de.4bpp"
gHatchMachineSeg0IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_a_de.4bpp"
gSapphireTrapIndicatorState0Bot_De::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state0_bot_de.4bpp"
gSapphireTrapIndicatorState1Bot_De::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state1_bot_de.4bpp"
gSapphireTrapIndicatorState2Bot_De::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state2_bot_de.4bpp"
gSapphireCatchLightSlot0State2Bot_De:: @ 0x084A4CE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_bot_de.4bpp"
gSapphireCatchLightSlot0State3Bot_De:: @ 0x084A4D20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_bot_de.4bpp"
gSapphireCatchLightSlot1State2Bot_De:: @ 0x084A4D60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_bot_de.4bpp"
gSapphireCatchLightSlot1State3Bot_De:: @ 0x084A4DA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_bot_de.4bpp"
gSapphireCatchLightSlot2State2Bot_De:: @ 0x084A4DE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_bot_de.4bpp"
gSapphireCatchLightSlot2State3Bot_De:: @ 0x084A4E20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_bot_de.4bpp"
gSapphireCatchLightSlot0State4Bot_De:: @ 0x084A4E60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_bot_de.4bpp"
gSapphireCatchLightSlot0State5Bot_De:: @ 0x084A4EA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_bot_de.4bpp"
gSapphireCatchLightSlot1State4Bot_De:: @ 0x084A4EE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_bot_de.4bpp"
gSapphireCatchLightSlot1State5Bot_De:: @ 0x084A4F20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_bot_de.4bpp"
gSapphireCatchLightSlot2State4Bot_De:: @ 0x084A4F60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_bot_de.4bpp"
gSapphireCatchLightSlot2State5Bot_De:: @ 0x084A4FA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_bot_de.4bpp"
gHatchMachineSeg0IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_b_de.4bpp"
gHatchMachineSeg0HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_a_de.4bpp"
gHatchMachineSeg1IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_a_de.4bpp"
gHatchMachineSeg1HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_a_de.4bpp"
gHatchMachineSeg2IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_a_de.4bpp"
gHatchMachineSeg2HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_a_de.4bpp"
	.space 0x80
gHatchMachineSeg4IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_a_de.4bpp"
gHatchMachineSeg4HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_a_de.4bpp"
gHatchMachineSeg5IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_a_de.4bpp"
gHatchMachineSeg5HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_a_de.4bpp"
gHatchMachineSeg6IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_a_de.4bpp"
gHatchMachineSeg6HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_a_de.4bpp"
gHatchMachineSeg7IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_a_de.4bpp"
gHatchMachineSeg7HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_a_de.4bpp"
gHatchMachineSeg8IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_a_de.4bpp"
gHatchMachineSeg0HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_b_de.4bpp"
gHatchMachineSeg1IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_b_de.4bpp"
gHatchMachineSeg1HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_b_de.4bpp"
gHatchMachineSeg2IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_b_de.4bpp"
gHatchMachineSeg2HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_b_de.4bpp"
gHatchMachineSeg3Idle_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_idle_de.4bpp"
gHatchMachineSeg3Hit_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_hit_de.4bpp"
gHatchMachineSeg4IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_b_de.4bpp"
gHatchMachineSeg4HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_b_de.4bpp"
gHatchMachineSeg5IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_b_de.4bpp"
gHatchMachineSeg5HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_b_de.4bpp"
gHatchMachineSeg6IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_b_de.4bpp"
gHatchMachineSeg6HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_b_de.4bpp"
gHatchMachineSeg7IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_b_de.4bpp"
gHatchMachineSeg7HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_b_de.4bpp"
gHatchMachineSeg8IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_b_de.4bpp"
gHatchMachineSeg8HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_a_de.4bpp"
gHatchMachineSeg9IdleA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_a_de.4bpp"
gHatchMachineSeg9HitA_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_a_de.4bpp"
gSapphirePSquareFrame0Top_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame0_top_de.4bpp"
gSapphirePSquareFrame1Top_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame1_top_de.4bpp"
gSapphirePSquareFrame2Top_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame2_top_de.4bpp"
gSapphirePSquareFrame3Top_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame3_top_de.4bpp"
gSapphirePSquareFrame4Top_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_top_de.4bpp"
	.space 0x200
gHatchMachineSeg8HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_b_de.4bpp"
gHatchMachineSeg9IdleB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_b_de.4bpp"
gHatchMachineSeg9HitB_De::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_b_de.4bpp"
gSapphirePSquareFrame0Bot_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame0_bot_de.4bpp"
gSapphirePSquareFrame1Bot_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame1_bot_de.4bpp"
gSapphirePSquareFrame2Bot_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame2_bot_de.4bpp"
gSapphirePSquareFrame3Bot_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame3_bot_de.4bpp"
gSapphirePSquareFrame4Bot_De::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_de.4bpp"
	.space 0x220
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_filler_de.4bpp"
gSapphireHoleLightH_Off_It:: @ 0x084A61C0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_off_it.4bpp"
gSapphireHoleLightH_On_It:: @ 0x084A6200
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_on_it.4bpp"
gSapphireHoleLightO_Off_It:: @ 0x084A6240
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_off_it.4bpp"
gSapphireHoleLightO_On_It:: @ 0x084A6280
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_on_it.4bpp"
gSapphireHoleLightL_Off_It:: @ 0x084A62C0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_off_it.4bpp"
gSapphireHoleLightL_On_It:: @ 0x084A6300
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_on_it.4bpp"
gSapphireHoleLightE_Off_It:: @ 0x084A6340
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_off_it.4bpp"
gSapphireHoleLightE_On_It:: @ 0x084A6380
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_on_it.4bpp"
gSapphireCatchLightState0Top_It:: @ 0x084A63C0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_top_it.4bpp"
gSapphireCatchLightState1Top_It:: @ 0x084A6400
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_top_it.4bpp"
	.space 0x380
gSapphireCatchLightState0Bot_It:: @ 0x084A67C0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_bot_it.4bpp"
gSapphireCatchLightState1Bot_It:: @ 0x084A6800
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_bot_it.4bpp"
gSapphireTrapIndicatorState0Top_It::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state0_top_it.4bpp"
gSapphireTrapIndicatorState1Top_It::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state1_top_it.4bpp"
gSapphireTrapIndicatorState2Top_It::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state2_top_it.4bpp"
gSapphireCatchLightSlot0State2Top_It:: @ 0x084A6900
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_top_it.4bpp"
gSapphireCatchLightSlot0State3Top_It:: @ 0x084A6940
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_top_it.4bpp"
gSapphireCatchLightSlot1State2Top_It:: @ 0x084A6980
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_top_it.4bpp"
gSapphireCatchLightSlot1State3Top_It:: @ 0x084A69C0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_top_it.4bpp"
gSapphireCatchLightSlot2State2Top_It:: @ 0x084A6A00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_top_it.4bpp"
gSapphireCatchLightSlot2State3Top_It:: @ 0x084A6A40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_top_it.4bpp"
gSapphireCatchLightSlot0State4Top_It:: @ 0x084A6A80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_top_it.4bpp"
gSapphireCatchLightSlot0State5Top_It:: @ 0x084A6AC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_top_it.4bpp"
gSapphireCatchLightSlot1State4Top_It:: @ 0x084A6B00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_top_it.4bpp"
gSapphireCatchLightSlot1State5Top_It:: @ 0x084A6B40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_top_it.4bpp"
gSapphireCatchLightSlot2State4Top_It:: @ 0x084A6B80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_top_it.4bpp"
gSapphireCatchLightSlot2State5Top_It:: @ 0x084A6BC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_top_it.4bpp"
gHatchMachineSeg0IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_a_it.4bpp"
gSapphireTrapIndicatorState0Bot_It::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state0_bot_it.4bpp"
gSapphireTrapIndicatorState1Bot_It::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state1_bot_it.4bpp"
gSapphireTrapIndicatorState2Bot_It::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state2_bot_it.4bpp"
gSapphireCatchLightSlot0State2Bot_It:: @ 0x084A6D00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_bot_it.4bpp"
gSapphireCatchLightSlot0State3Bot_It:: @ 0x084A6D40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_bot_it.4bpp"
gSapphireCatchLightSlot1State2Bot_It:: @ 0x084A6D80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_bot_it.4bpp"
gSapphireCatchLightSlot1State3Bot_It:: @ 0x084A6DC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_bot_it.4bpp"
gSapphireCatchLightSlot2State2Bot_It:: @ 0x084A6E00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_bot_it.4bpp"
gSapphireCatchLightSlot2State3Bot_It:: @ 0x084A6E40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_bot_it.4bpp"
gSapphireCatchLightSlot0State4Bot_It:: @ 0x084A6E80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_bot_it.4bpp"
gSapphireCatchLightSlot0State5Bot_It:: @ 0x084A6EC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_bot_it.4bpp"
gSapphireCatchLightSlot1State4Bot_It:: @ 0x084A6F00
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_bot_it.4bpp"
gSapphireCatchLightSlot1State5Bot_It:: @ 0x084A6F40
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_bot_it.4bpp"
gSapphireCatchLightSlot2State4Bot_It:: @ 0x084A6F80
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_bot_it.4bpp"
gSapphireCatchLightSlot2State5Bot_It:: @ 0x084A6FC0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_bot_it.4bpp"
gHatchMachineSeg0IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_b_it.4bpp"
gHatchMachineSeg0HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_a_it.4bpp"
gHatchMachineSeg1IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_a_it.4bpp"
gHatchMachineSeg1HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_a_it.4bpp"
gHatchMachineSeg2IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_a_it.4bpp"
gHatchMachineSeg2HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_a_it.4bpp"
	.space 0x80
gHatchMachineSeg4IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_a_it.4bpp"
gHatchMachineSeg4HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_a_it.4bpp"
gHatchMachineSeg5IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_a_it.4bpp"
gHatchMachineSeg5HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_a_it.4bpp"
gHatchMachineSeg6IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_a_it.4bpp"
gHatchMachineSeg6HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_a_it.4bpp"
gHatchMachineSeg7IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_a_it.4bpp"
gHatchMachineSeg7HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_a_it.4bpp"
gHatchMachineSeg8IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_a_it.4bpp"
gHatchMachineSeg0HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_b_it.4bpp"
gHatchMachineSeg1IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_b_it.4bpp"
gHatchMachineSeg1HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_b_it.4bpp"
gHatchMachineSeg2IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_b_it.4bpp"
gHatchMachineSeg2HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_b_it.4bpp"
gHatchMachineSeg3Idle_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_idle_it.4bpp"
gHatchMachineSeg3Hit_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_hit_it.4bpp"
gHatchMachineSeg4IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_b_it.4bpp"
gHatchMachineSeg4HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_b_it.4bpp"
gHatchMachineSeg5IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_b_it.4bpp"
gHatchMachineSeg5HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_b_it.4bpp"
gHatchMachineSeg6IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_b_it.4bpp"
gHatchMachineSeg6HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_b_it.4bpp"
gHatchMachineSeg7IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_b_it.4bpp"
gHatchMachineSeg7HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_b_it.4bpp"
gHatchMachineSeg8IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_b_it.4bpp"
gHatchMachineSeg8HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_a_it.4bpp"
gHatchMachineSeg9IdleA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_a_it.4bpp"
gHatchMachineSeg9HitA_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_a_it.4bpp"
gSapphirePSquareFrame0Top_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame0_top_it.4bpp"
gSapphirePSquareFrame1Top_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame1_top_it.4bpp"
gSapphirePSquareFrame2Top_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame2_top_it.4bpp"
gSapphirePSquareFrame3Top_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame3_top_it.4bpp"
gSapphirePSquareFrame4Top_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_top_it.4bpp"
	.space 0x200
gHatchMachineSeg8HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_b_it.4bpp"
gHatchMachineSeg9IdleB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_b_it.4bpp"
gHatchMachineSeg9HitB_It::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_b_it.4bpp"
gSapphirePSquareFrame0Bot_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame0_bot_it.4bpp"
gSapphirePSquareFrame1Bot_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame1_bot_it.4bpp"
gSapphirePSquareFrame2Bot_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame2_bot_it.4bpp"
gSapphirePSquareFrame3Bot_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame3_bot_it.4bpp"
gSapphirePSquareFrame4Bot_It::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_it.4bpp"
	.space 0x220
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_filler_it.4bpp"
gSapphireHoleLightH_Off_Es:: @ 0x084A81E0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_off_es.4bpp"
gSapphireHoleLightH_On_Es:: @ 0x084A8220
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_on_es.4bpp"
gSapphireHoleLightO_Off_Es:: @ 0x084A8260
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_off_es.4bpp"
gSapphireHoleLightO_On_Es:: @ 0x084A82A0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_on_es.4bpp"
gSapphireHoleLightL_Off_Es:: @ 0x084A82E0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_off_es.4bpp"
gSapphireHoleLightL_On_Es:: @ 0x084A8320
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_on_es.4bpp"
gSapphireHoleLightE_Off_Es:: @ 0x084A8360
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_off_es.4bpp"
gSapphireHoleLightE_On_Es:: @ 0x084A83A0
	.incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_on_es.4bpp"
gSapphireCatchLightState0Top_Es:: @ 0x084A83E0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_top_es.4bpp"
gSapphireCatchLightState1Top_Es:: @ 0x084A8420
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_top_es.4bpp"
	.space 0x380
gSapphireCatchLightState0Bot_Es:: @ 0x084A87E0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_bot_es.4bpp"
gSapphireCatchLightState1Bot_Es:: @ 0x084A8820
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_bot_es.4bpp"
gSapphireTrapIndicatorState0Top_Es::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state0_top_es.4bpp"
gSapphireTrapIndicatorState1Top_Es::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state1_top_es.4bpp"
gSapphireTrapIndicatorState2Top_Es::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state2_top_es.4bpp"
gSapphireCatchLightSlot0State2Top_Es:: @ 0x084A8920
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_top_es.4bpp"
gSapphireCatchLightSlot0State3Top_Es:: @ 0x084A8960
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_top_es.4bpp"
gSapphireCatchLightSlot1State2Top_Es:: @ 0x084A89A0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_top_es.4bpp"
gSapphireCatchLightSlot1State3Top_Es:: @ 0x084A89E0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_top_es.4bpp"
gSapphireCatchLightSlot2State2Top_Es:: @ 0x084A8A20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_top_es.4bpp"
gSapphireCatchLightSlot2State3Top_Es:: @ 0x084A8A60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_top_es.4bpp"
gSapphireCatchLightSlot0State4Top_Es:: @ 0x084A8AA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_top_es.4bpp"
gSapphireCatchLightSlot0State5Top_Es:: @ 0x084A8AE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_top_es.4bpp"
gSapphireCatchLightSlot1State4Top_Es:: @ 0x084A8B20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_top_es.4bpp"
gSapphireCatchLightSlot1State5Top_Es:: @ 0x084A8B60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_top_es.4bpp"
gSapphireCatchLightSlot2State4Top_Es:: @ 0x084A8BA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_top_es.4bpp"
gSapphireCatchLightSlot2State5Top_Es:: @ 0x084A8BE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_top_es.4bpp"
gHatchMachineSeg0IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_a_es.4bpp"
gSapphireTrapIndicatorState0Bot_Es::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state0_bot_es.4bpp"
gSapphireTrapIndicatorState1Bot_Es::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state1_bot_es.4bpp"
gSapphireTrapIndicatorState2Bot_Es::
	.incbin "graphics/stage/sapphire/trap_indicator/trap_state2_bot_es.4bpp"
gSapphireCatchLightSlot0State2Bot_Es:: @ 0x084A8D20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_bot_es.4bpp"
gSapphireCatchLightSlot0State3Bot_Es:: @ 0x084A8D60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_bot_es.4bpp"
gSapphireCatchLightSlot1State2Bot_Es:: @ 0x084A8DA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_bot_es.4bpp"
gSapphireCatchLightSlot1State3Bot_Es:: @ 0x084A8DE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_bot_es.4bpp"
gSapphireCatchLightSlot2State2Bot_Es:: @ 0x084A8E20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_bot_es.4bpp"
gSapphireCatchLightSlot2State3Bot_Es:: @ 0x084A8E60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_bot_es.4bpp"
gSapphireCatchLightSlot0State4Bot_Es:: @ 0x084A8EA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_bot_es.4bpp"
gSapphireCatchLightSlot0State5Bot_Es:: @ 0x084A8EE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_bot_es.4bpp"
gSapphireCatchLightSlot1State4Bot_Es:: @ 0x084A8F20
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_bot_es.4bpp"
gSapphireCatchLightSlot1State5Bot_Es:: @ 0x084A8F60
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_bot_es.4bpp"
gSapphireCatchLightSlot2State4Bot_Es:: @ 0x084A8FA0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_bot_es.4bpp"
gSapphireCatchLightSlot2State5Bot_Es:: @ 0x084A8FE0
	.incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_bot_es.4bpp"
gHatchMachineSeg0IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_b_es.4bpp"
gHatchMachineSeg0HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_a_es.4bpp"
gHatchMachineSeg1IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_a_es.4bpp"
gHatchMachineSeg1HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_a_es.4bpp"
gHatchMachineSeg2IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_a_es.4bpp"
gHatchMachineSeg2HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_a_es.4bpp"
	.space 0x80
gHatchMachineSeg4IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_a_es.4bpp"
gHatchMachineSeg4HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_a_es.4bpp"
gHatchMachineSeg5IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_a_es.4bpp"
gHatchMachineSeg5HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_a_es.4bpp"
gHatchMachineSeg6IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_a_es.4bpp"
gHatchMachineSeg6HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_a_es.4bpp"
gHatchMachineSeg7IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_a_es.4bpp"
gHatchMachineSeg7HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_a_es.4bpp"
gHatchMachineSeg8IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_a_es.4bpp"
gHatchMachineSeg0HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_b_es.4bpp"
gHatchMachineSeg1IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_b_es.4bpp"
gHatchMachineSeg1HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_b_es.4bpp"
gHatchMachineSeg2IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_b_es.4bpp"
gHatchMachineSeg2HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_b_es.4bpp"
gHatchMachineSeg3Idle_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_idle_es.4bpp"
gHatchMachineSeg3Hit_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_hit_es.4bpp"
gHatchMachineSeg4IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_b_es.4bpp"
gHatchMachineSeg4HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_b_es.4bpp"
gHatchMachineSeg5IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_b_es.4bpp"
gHatchMachineSeg5HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_b_es.4bpp"
gHatchMachineSeg6IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_b_es.4bpp"
gHatchMachineSeg6HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_b_es.4bpp"
gHatchMachineSeg7IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_b_es.4bpp"
gHatchMachineSeg7HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_b_es.4bpp"
gHatchMachineSeg8IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_b_es.4bpp"
gHatchMachineSeg8HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_a_es.4bpp"
gHatchMachineSeg9IdleA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_a_es.4bpp"
gHatchMachineSeg9HitA_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_a_es.4bpp"
gSapphirePSquareFrame0Top_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame0_top_es.4bpp"
gSapphirePSquareFrame1Top_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame1_top_es.4bpp"
gSapphirePSquareFrame2Top_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame2_top_es.4bpp"
gSapphirePSquareFrame3Top_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame3_top_es.4bpp"
gSapphirePSquareFrame4Top_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_top_es.4bpp"
	.space 0x200
gHatchMachineSeg8HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_b_es.4bpp"
gHatchMachineSeg9IdleB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_b_es.4bpp"
gHatchMachineSeg9HitB_Es::
	.incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_b_es.4bpp"
gSapphirePSquareFrame0Bot_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame0_bot_es.4bpp"
gSapphirePSquareFrame1Bot_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame1_bot_es.4bpp"
gSapphirePSquareFrame2Bot_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame2_bot_es.4bpp"
gSapphirePSquareFrame3Bot_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame3_bot_es.4bpp"
gSapphirePSquareFrame4Bot_Es::
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_es.4bpp"
	.space 0x220
	.incbin "graphics/stage/sapphire/p_square/p_square_frame4_bot_filler_es.4bpp"
gSapphireSaverRow0Tile_Off:: @ 0x084AA0A0
    .incbin "graphics/stage/sapphire/saver/saver_off_row0.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_off_row0_filler.4bpp"

gSapphireSaverRow0Tile_On:: @ 0x084AA1A0
    .incbin "graphics/stage/sapphire/saver/saver_on_row0.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_on_row0_filler.4bpp"

gSapphireSaverRow1Tile_Off:: @ 0x084AA4A0
    .incbin "graphics/stage/sapphire/saver/saver_off_row1.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_off_row1_filler.4bpp"

gSapphireSaverRow1Tile_On:: @ 0x084AA5A0
    .incbin "graphics/stage/sapphire/saver/saver_on_row1.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_on_row1_filler.4bpp"

gSapphireSaverRow2Tile_Off:: @ 0x084AA8C0
    .incbin "graphics/stage/sapphire/saver/saver_off_row2.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_off_row2_filler.4bpp"

gSapphireSaverRow2Tile_On:: @ 0x084AA9C0
    .incbin "graphics/stage/sapphire/saver/saver_on_row2.4bpp"
	.space 0x200
	.fill 0xA0, 1, 0xCC

gSapphireSaverRow3Tile_Off:: @ 0x084AAD20
    .incbin "graphics/stage/sapphire/saver/saver_off_row3.4bpp"
	.fill 0xC0, 1, 0xCC



@ Hatch arrow, Catch arrow, Bumper arrow


gSapphireSaverRow3Tile_On:: @ 0x084AAE20
	.incbin "graphics/stage/sapphire/saver/saver_on_row3_eu.4bpp"
gSapphireSaverRow0Tile_Off_Fr:: @ 0x084AB0C0
	.incbin "graphics/stage/sapphire/saver/saver_off_row0_fr.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row0_filler_fr.4bpp"
gSapphireSaverRow0Tile_On_Fr:: @ 0x084AB1C0
	.incbin "graphics/stage/sapphire/saver/saver_on_row0_fr.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_on_row0_filler_fr.4bpp"
gSapphireSaverRow1Tile_Off_Fr:: @ 0x084AB4C0
	.incbin "graphics/stage/sapphire/saver/saver_off_row1_fr.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row1_filler_fr.4bpp"
gSapphireSaverRow1Tile_On_Fr:: @ 0x084AB5C0
	.incbin "graphics/stage/sapphire/saver/saver_on_row1_fr.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_on_row1_filler_fr.4bpp"
gSapphireSaverRow2Tile_Off_Fr:: @ 0x084AB8C0
	.incbin "graphics/stage/sapphire/saver/saver_off_row2_fr.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row2_filler_fr.4bpp"
gSapphireSaverRow2Tile_On_Fr:: @ 0x084AB9C0
	.incbin "graphics/stage/sapphire/saver/saver_on_row2_fr.4bpp"
	.space 0x200
	.fill 0xA0, 1, 0xCC
gSapphireSaverRow3Tile_Off_Fr:: @ 0x084ABD40
	.incbin "graphics/stage/sapphire/saver/saver_off_row3_fr.4bpp"
	.fill 0xC0, 1, 0xCC
gSapphireSaverRow3Tile_On_Fr:: @ 0x084ABE40
	.incbin "graphics/stage/sapphire/saver/saver_on_row3_fr.4bpp"
gSapphireSaverRow0Tile_Off_It:: @ 0x084AC0E0
	.incbin "graphics/stage/sapphire/saver/saver_off_row0_it.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row0_filler_it.4bpp"
gSapphireSaverRow0Tile_On_It:: @ 0x084AC1E0
	.incbin "graphics/stage/sapphire/saver/saver_on_row0_it.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_on_row0_filler_it.4bpp"
gSapphireSaverRow1Tile_Off_It:: @ 0x084AC4E0
	.incbin "graphics/stage/sapphire/saver/saver_off_row1_it.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row1_filler_it.4bpp"
gSapphireSaverRow1Tile_On_It:: @ 0x084AC5E0
	.incbin "graphics/stage/sapphire/saver/saver_on_row1_it.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_on_row1_filler_it.4bpp"
gSapphireSaverRow2Tile_Off_It:: @ 0x084AC8E0
	.incbin "graphics/stage/sapphire/saver/saver_off_row2_it.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row2_filler_it.4bpp"
gSapphireSaverRow2Tile_On_It:: @ 0x084AC9E0
	.incbin "graphics/stage/sapphire/saver/saver_on_row2_it.4bpp"
	.space 0x200
	.fill 0xA0, 1, 0xCC
gSapphireSaverRow3Tile_Off_It:: @ 0x084ACD60
	.incbin "graphics/stage/sapphire/saver/saver_off_row3_it.4bpp"
	.fill 0xC0, 1, 0xCC
gSapphireSaverRow3Tile_On_It:: @ 0x084ACE60
	.incbin "graphics/stage/sapphire/saver/saver_on_row3_it.4bpp"
gSapphireSaverRow0Tile_Off_Es:: @ 0x084AD100
	.incbin "graphics/stage/sapphire/saver/saver_off_row0_es.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row0_filler_es.4bpp"
gSapphireSaverRow0Tile_On_Es:: @ 0x084AD200
	.incbin "graphics/stage/sapphire/saver/saver_on_row0_es.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_on_row0_filler_es.4bpp"
gSapphireSaverRow1Tile_Off_Es:: @ 0x084AD500
	.incbin "graphics/stage/sapphire/saver/saver_off_row1_es.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row1_filler_es.4bpp"
gSapphireSaverRow1Tile_On_Es:: @ 0x084AD600
	.incbin "graphics/stage/sapphire/saver/saver_on_row1_es.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_on_row1_filler_es.4bpp"
gSapphireSaverRow2Tile_Off_Es:: @ 0x084AD920
	.incbin "graphics/stage/sapphire/saver/saver_off_row2_es.4bpp"
	.incbin "graphics/stage/sapphire/saver/saver_off_row2_filler_es.4bpp"
gSapphireSaverRow2Tile_On_Es:: @ 0x084ADA20
	.incbin "graphics/stage/sapphire/saver/saver_on_row2_es.4bpp"
	.space 0x200
	.fill 0xA0, 1, 0xCC
gSapphireSaverRow3Tile_Off_Es:: @ 0x084ADD80
	.incbin "graphics/stage/sapphire/saver/saver_off_row3_es.4bpp"
	.fill 0xC0, 1, 0xCC
gSapphireSaverRow3Tile_On_Es:: @ 0x084ADE80
	.incbin "graphics/stage/sapphire/saver/saver_on_row3_es.4bpp"
	.fill 0x20, 1, 0xCC
	.space 0x260
gSapphireHatchArrow_R0_Off:: @ 0x084AE140
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row0.4bpp"
    .space 0x40

gSapphireHatchArrow_R0_On:: @ 0x084AE1C0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireCatchArrow_R0_Off:: @ 0x084AE220
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireCatchArrow_R0_On:: @ 0x084AE2A0
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row0.4bpp"

gSapphireBumperArrow_R0_Off:: @ 0x084AE300
    .space 0x80 @ reference, not actually used
	@.incbin "baserom.gba", 0x2E0860, 0x80

gSapphireBumperArrow_R0_On:: @ 0x084AE380
	.space 0x80 @ reference, not actually used
	.space 0x100

gSapphireHatchArrow_R1_Off:: @ 0x084AE500
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row1.4bpp"

gSapphireHatchArrow_R1_On:: @ 0x084AE580
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row1.4bpp"

gSapphireCatchArrow_R1_Off:: @ 0x084AE600
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row1.4bpp"

gSapphireCatchArrow_R1_On:: @ 0x084AE680
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row1.4bpp"

gSapphireBumperArrow_R1_Off:: @ 0x084AE700
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row1.4bpp"

gSapphireBumperArrow_R1_On:: @ 0x084AE780
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row1.4bpp"
    .space 0x100

gSapphireHatchArrow_R2_Off:: @ 0x084AE900
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row2.4bpp"

gSapphireHatchArrow_R2_On:: @ 0x084AE980
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row2.4bpp"

gSapphireCatchArrow_R2_Off:: @ 0x084AEA00
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row2.4bpp"

gSapphireCatchArrow_R2_On:: @ 0x084AEA80
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row2.4bpp"

gSapphireBumperArrow_R2_Off:: @ 0x084AEB00
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row2.4bpp"

gSapphireBumperArrow_R2_On:: @ 0x084AEB80
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row2.4bpp"
    .space 0x100

gSapphireHatchArrow_R3_Off:: @ 0x084AED00
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row3.4bpp"

gSapphireHatchArrow_R3_On:: @ 0x084AED80
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row3.4bpp"

gSapphireCatchArrow_R3_Off:: @ 0x084AEE00
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row3.4bpp"
    .space 0x20

gSapphireCatchArrow_R3_On:: @ 0x084AEE80
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row3.4bpp"
    .space 0x20

gSapphireBumperArrow_R3_Off:: @ 0x084AEF00
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row3.4bpp"

gSapphireBumperArrow_R3_On:: @ 0x084AEF80
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row3.4bpp"
    .space 0x120



@ arrow for ramp leading to shop: mart/evo

	.space 0x40
gSapphireHatchArrow_R0_Off_Fr:: @ 0x084AF160
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row0_fr.4bpp"
	.space 0x40
gSapphireHatchArrow_R0_On_Fr:: @ 0x084AF1E0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row0_fr.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCatchArrow_R0_Off_Fr:: @ 0x084AF240
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row0_fr.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCatchArrow_R0_On_Fr:: @ 0x084AF2C0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row0_fr.4bpp"
gSapphireBumperArrow_R0_Off_Fr:: @ 0x084AF320
	.space 0x80
gSapphireBumperArrow_R0_On_Fr:: @ 0x084AF3A0
	.space 0x80
	.space 0x100
gSapphireHatchArrow_R1_Off_Fr:: @ 0x084AF520
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row1_fr.4bpp"
gSapphireHatchArrow_R1_On_Fr:: @ 0x084AF5A0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row1_fr.4bpp"
gSapphireCatchArrow_R1_Off_Fr:: @ 0x084AF620
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row1_fr.4bpp"
gSapphireCatchArrow_R1_On_Fr:: @ 0x084AF6A0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row1_fr.4bpp"
gSapphireBumperArrow_R1_Off_Fr:: @ 0x084AF720
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row1_fr.4bpp"
gSapphireBumperArrow_R1_On_Fr:: @ 0x084AF7A0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row1_fr.4bpp"
	.space 0x100
gSapphireHatchArrow_R2_Off_Fr:: @ 0x084AF920
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row2_fr.4bpp"
gSapphireHatchArrow_R2_On_Fr:: @ 0x084AF9A0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row2_fr.4bpp"
gSapphireCatchArrow_R2_Off_Fr:: @ 0x084AFA20
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row2_fr.4bpp"
gSapphireCatchArrow_R2_On_Fr:: @ 0x084AFAA0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row2_fr.4bpp"
gSapphireBumperArrow_R2_Off_Fr:: @ 0x084AFB20
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row2_fr.4bpp"
gSapphireBumperArrow_R2_On_Fr:: @ 0x084AFBA0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row2_fr.4bpp"
	.space 0x100
gSapphireHatchArrow_R3_Off_Fr:: @ 0x084AFD20
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row3_fr.4bpp"
gSapphireHatchArrow_R3_On_Fr:: @ 0x084AFDA0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row3_fr.4bpp"
gSapphireCatchArrow_R3_Off_Fr:: @ 0x084AFE20
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row3_fr.4bpp"
	.space 0x20
gSapphireCatchArrow_R3_On_Fr:: @ 0x084AFEA0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row3_fr.4bpp"
	.space 0x20
gSapphireBumperArrow_R3_Off_Fr:: @ 0x084AFF20
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row3_fr.4bpp"
gSapphireBumperArrow_R3_On_Fr:: @ 0x084AFFA0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row3_fr.4bpp"
	.space 0x120
gSapphireHatchArrow_R0_Off_De:: @ 0x084B0180
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row0_de.4bpp"
	.space 0x40
gSapphireHatchArrow_R0_On_De:: @ 0x084B0200
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row0_de.4bpp"
gSapphireCatchArrow_R0_Off_De:: @ 0x084B0260
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row0_de.4bpp"
gSapphireCatchArrow_R0_On_De:: @ 0x084B02E0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row0_de.4bpp"
gSapphireBumperArrow_R0_Off_De:: @ 0x084B0340
	.space 0x80
gSapphireBumperArrow_R0_On_De:: @ 0x084B03C0
	.space 0x80
	.space 0x100
gSapphireHatchArrow_R1_Off_De:: @ 0x084B0540
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row1_de.4bpp"
gSapphireHatchArrow_R1_On_De:: @ 0x084B05C0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row1_de.4bpp"
gSapphireCatchArrow_R1_Off_De:: @ 0x084B0640
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row1_de.4bpp"
gSapphireCatchArrow_R1_On_De:: @ 0x084B06C0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row1_de.4bpp"
gSapphireBumperArrow_R1_Off_De:: @ 0x084B0740
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row1_de.4bpp"
gSapphireBumperArrow_R1_On_De:: @ 0x084B07C0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row1_de.4bpp"
	.space 0x100
gSapphireHatchArrow_R2_Off_De:: @ 0x084B0940
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row2_de.4bpp"
gSapphireHatchArrow_R2_On_De:: @ 0x084B09C0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row2_de.4bpp"
gSapphireCatchArrow_R2_Off_De:: @ 0x084B0A40
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row2_de.4bpp"
gSapphireCatchArrow_R2_On_De:: @ 0x084B0AC0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row2_de.4bpp"
gSapphireBumperArrow_R2_Off_De:: @ 0x084B0B40
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row2_de.4bpp"
gSapphireBumperArrow_R2_On_De:: @ 0x084B0BC0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row2_de.4bpp"
	.space 0x100
gSapphireHatchArrow_R3_Off_De:: @ 0x084B0D40
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row3_de.4bpp"
gSapphireHatchArrow_R3_On_De:: @ 0x084B0DC0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row3_de.4bpp"
gSapphireCatchArrow_R3_Off_De:: @ 0x084B0E40
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row3_de.4bpp"
	.space 0x20
gSapphireCatchArrow_R3_On_De:: @ 0x084B0EC0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row3_de.4bpp"
	.space 0x20
gSapphireBumperArrow_R3_Off_De:: @ 0x084B0F40
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row3_de.4bpp"
gSapphireBumperArrow_R3_On_De:: @ 0x084B0FC0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row3_de.4bpp"
	.space 0x120
gSapphireHatchArrow_R0_Off_It:: @ 0x084B11A0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row0_it.4bpp"
	.space 0x40
gSapphireHatchArrow_R0_On_It:: @ 0x084B1220
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row0_it.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCatchArrow_R0_Off_It:: @ 0x084B1280
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row0_it.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCatchArrow_R0_On_It:: @ 0x084B1300
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row0_it.4bpp"
gSapphireBumperArrow_R0_Off_It:: @ 0x084B1360
	.space 0x80
gSapphireBumperArrow_R0_On_It:: @ 0x084B13E0
	.space 0x80
	.space 0x100
gSapphireHatchArrow_R1_Off_It:: @ 0x084B1560
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row1_it.4bpp"
gSapphireHatchArrow_R1_On_It:: @ 0x084B15E0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row1_it.4bpp"
gSapphireCatchArrow_R1_Off_It:: @ 0x084B1660
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row1_it.4bpp"
gSapphireCatchArrow_R1_On_It:: @ 0x084B16E0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row1_it.4bpp"
gSapphireBumperArrow_R1_Off_It:: @ 0x084B1760
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row1_it.4bpp"
gSapphireBumperArrow_R1_On_It:: @ 0x084B17E0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row1_it.4bpp"
	.space 0x100
gSapphireHatchArrow_R2_Off_It:: @ 0x084B1960
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row2_it.4bpp"
gSapphireHatchArrow_R2_On_It:: @ 0x084B19E0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row2_it.4bpp"
gSapphireCatchArrow_R2_Off_It:: @ 0x084B1A60
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row2_it.4bpp"
gSapphireCatchArrow_R2_On_It:: @ 0x084B1AE0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row2_it.4bpp"
gSapphireBumperArrow_R2_Off_It:: @ 0x084B1B60
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row2_it.4bpp"
gSapphireBumperArrow_R2_On_It:: @ 0x084B1BE0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row2_it.4bpp"
	.space 0x100
gSapphireHatchArrow_R3_Off_It:: @ 0x084B1D60
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row3_it.4bpp"
gSapphireHatchArrow_R3_On_It:: @ 0x084B1DE0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row3_it.4bpp"
gSapphireCatchArrow_R3_Off_It:: @ 0x084B1E60
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row3_it.4bpp"
	.space 0x20
gSapphireCatchArrow_R3_On_It:: @ 0x084B1EE0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row3_it.4bpp"
	.space 0x20
gSapphireBumperArrow_R3_Off_It:: @ 0x084B1F60
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row3_it.4bpp"
gSapphireBumperArrow_R3_On_It:: @ 0x084B1FE0
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row3_it.4bpp"
	.space 0x120
gSapphireHatchArrow_R0_Off_Es:: @ 0x084B21C0
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row0_es.4bpp"
	.space 0x40
gSapphireHatchArrow_R0_On_Es:: @ 0x084B2240
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row0_es.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCatchArrow_R0_Off_Es:: @ 0x084B22A0
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row0_es.4bpp"
	.fill 0x20, 1, 0xDD
gSapphireCatchArrow_R0_On_Es:: @ 0x084B2320
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row0_es.4bpp"
gSapphireBumperArrow_R0_Off_Es:: @ 0x084B2380
	.space 0x80
gSapphireBumperArrow_R0_On_Es:: @ 0x084B2400
	.space 0x80
	.space 0x100
gSapphireHatchArrow_R1_Off_Es:: @ 0x084B2580
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row1_es.4bpp"
gSapphireHatchArrow_R1_On_Es:: @ 0x084B2600
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row1_es.4bpp"
gSapphireCatchArrow_R1_Off_Es:: @ 0x084B2680
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row1_es.4bpp"
gSapphireCatchArrow_R1_On_Es:: @ 0x084B2700
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row1_es.4bpp"
gSapphireBumperArrow_R1_Off_Es:: @ 0x084B2780
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row1_es.4bpp"
gSapphireBumperArrow_R1_On_Es:: @ 0x084B2800
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row1_es.4bpp"
	.space 0x100
gSapphireHatchArrow_R2_Off_Es:: @ 0x084B2980
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row2_es.4bpp"
gSapphireHatchArrow_R2_On_Es:: @ 0x084B2A00
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row2_es.4bpp"
gSapphireCatchArrow_R2_Off_Es:: @ 0x084B2A80
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row2_es.4bpp"
gSapphireCatchArrow_R2_On_Es:: @ 0x084B2B00
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row2_es.4bpp"
gSapphireBumperArrow_R2_Off_Es:: @ 0x084B2B80
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row2_es.4bpp"
gSapphireBumperArrow_R2_On_Es:: @ 0x084B2C00
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row2_es.4bpp"
	.space 0x100
gSapphireHatchArrow_R3_Off_Es:: @ 0x084B2D80
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row3_es.4bpp"
gSapphireHatchArrow_R3_On_Es:: @ 0x084B2E00
	.incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row3_es.4bpp"
gSapphireCatchArrow_R3_Off_Es:: @ 0x084B2E80
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row3_es.4bpp"
	.space 0x20
gSapphireCatchArrow_R3_On_Es:: @ 0x084B2F00
	.incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row3_es.4bpp"
	.space 0x20
gSapphireBumperArrow_R3_Off_Es:: @ 0x084B2F80
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row3_es.4bpp"
gSapphireBumperArrow_R3_On_Es:: @ 0x084B3000
	.incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row3_es.4bpp"
	.space 0x120
gSapphireMartArrow_R0_Off:: @ 0x084B31A0
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row0.4bpp"

gSapphireMartArrow_R0_On:: @ 0x084B3220
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row0.4bpp"

gSapphireEvoArrow_R0_Off:: @ 0x084B32A0
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row0.4bpp"

gSapphireEvoArrow_R0_On:: @ 0x084B3320
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row0.4bpp"
	.space 0x200

gSapphireMartArrow_R1_Off:: @ 0x084B35A0
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row1.4bpp"

gSapphireMartArrow_R1_On:: @ 0x084B3620
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row1.4bpp"

gSapphireEvoArrow_R1_Off:: @ 0x084B36A0
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row1.4bpp"

gSapphireEvoArrow_R1_On:: @ 0x084B3720
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row1.4bpp"
	.space 0x200

gSapphireMartArrow_R2_Off:: @ 0x084B39A0
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row2.4bpp"

gSapphireMartArrow_R2_On:: @ 0x084B3A20
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row2.4bpp"

gSapphireEvoArrow_R2_Off:: @ 0x084B3AA0
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row2.4bpp"

gSapphireEvoArrow_R2_On:: @ 0x084B3B20
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row2.4bpp"
	.space 0x200

gSapphireMartArrow_R3_Off:: @ 0x084B3DA0
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3.4bpp"
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_filler.4bpp"

gSapphireMartArrow_R3_On:: @ 0x084B3E20
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3.4bpp"
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_filler.4bpp"

gSapphireEvoArrow_R3_Off:: @ 0x084B3EA0
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3.4bpp"
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_filler.4bpp"

gSapphireEvoArrow_R3_On:: @ 0x084B3F20
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3.4bpp"
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_filler.4bpp"
	.space 0x620


@ Slingshot wedge lights

gSapphireMartArrow_R0_Off_Fr:: @ 0x084B45C0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row0_fr.4bpp"
gSapphireMartArrow_R0_On_Fr:: @ 0x084B4640
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row0_fr.4bpp"
gSapphireEvoArrow_R0_Off_Fr:: @ 0x084B46C0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row0_fr.4bpp"
gSapphireEvoArrow_R0_On_Fr:: @ 0x084B4740
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row0_fr.4bpp"
	.space 0x200
gSapphireMartArrow_R1_Off_Fr:: @ 0x084B49C0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row1_fr.4bpp"
gSapphireMartArrow_R1_On_Fr:: @ 0x084B4A40
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row1_fr.4bpp"
gSapphireEvoArrow_R1_Off_Fr:: @ 0x084B4AC0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row1_fr.4bpp"
gSapphireEvoArrow_R1_On_Fr:: @ 0x084B4B40
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row1_fr.4bpp"
	.space 0x200
gSapphireMartArrow_R2_Off_Fr:: @ 0x084B4DC0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row2_fr.4bpp"
gSapphireMartArrow_R2_On_Fr:: @ 0x084B4E40
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row2_fr.4bpp"
gSapphireEvoArrow_R2_Off_Fr:: @ 0x084B4EC0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row2_fr.4bpp"
gSapphireEvoArrow_R2_On_Fr:: @ 0x084B4F40
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row2_fr.4bpp"
	.space 0x200
gSapphireMartArrow_R3_Off_Fr:: @ 0x084B51C0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_fr.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_filler_fr.4bpp"
gSapphireMartArrow_R3_On_Fr:: @ 0x084B5240
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_fr.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_filler_fr.4bpp"
gSapphireEvoArrow_R3_Off_Fr:: @ 0x084B52C0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_fr.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_filler_fr.4bpp"
gSapphireEvoArrow_R3_On_Fr:: @ 0x084B5340
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_fr.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_filler_fr.4bpp"
	.space 0x620
gSapphireMartArrow_R0_Off_De:: @ 0x084B59E0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row0_de.4bpp"
gSapphireMartArrow_R0_On_De:: @ 0x084B5A60
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row0_de.4bpp"
gSapphireEvoArrow_R0_Off_De:: @ 0x084B5AE0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row0_de.4bpp"
gSapphireEvoArrow_R0_On_De:: @ 0x084B5B60
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row0_de.4bpp"
	.space 0x200
gSapphireMartArrow_R1_Off_De:: @ 0x084B5DE0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row1_de.4bpp"
gSapphireMartArrow_R1_On_De:: @ 0x084B5E60
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row1_de.4bpp"
gSapphireEvoArrow_R1_Off_De:: @ 0x084B5EE0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row1_de.4bpp"
gSapphireEvoArrow_R1_On_De:: @ 0x084B5F60
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row1_de.4bpp"
	.space 0x200
gSapphireMartArrow_R2_Off_De:: @ 0x084B61E0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row2_de.4bpp"
gSapphireMartArrow_R2_On_De:: @ 0x084B6260
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row2_de.4bpp"
gSapphireEvoArrow_R2_Off_De:: @ 0x084B62E0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row2_de.4bpp"
gSapphireEvoArrow_R2_On_De:: @ 0x084B6360
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row2_de.4bpp"
	.space 0x200
gSapphireMartArrow_R3_Off_De:: @ 0x084B65E0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_de.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_filler_de.4bpp"
gSapphireMartArrow_R3_On_De:: @ 0x084B6660
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_de.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_filler_de.4bpp"
gSapphireEvoArrow_R3_Off_De:: @ 0x084B66E0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_de.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_filler_de.4bpp"
gSapphireEvoArrow_R3_On_De:: @ 0x084B6760
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_de.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_filler_de.4bpp"
	.space 0x620
gSapphireMartArrow_R0_Off_It:: @ 0x084B6E00
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row0_it.4bpp"
gSapphireMartArrow_R0_On_It:: @ 0x084B6E80
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row0_it.4bpp"
gSapphireEvoArrow_R0_Off_It:: @ 0x084B6F00
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row0_it.4bpp"
gSapphireEvoArrow_R0_On_It:: @ 0x084B6F80
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row0_it.4bpp"
	.space 0x200
gSapphireMartArrow_R1_Off_It:: @ 0x084B7200
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row1_it.4bpp"
gSapphireMartArrow_R1_On_It:: @ 0x084B7280
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row1_it.4bpp"
gSapphireEvoArrow_R1_Off_It:: @ 0x084B7300
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row1_it.4bpp"
gSapphireEvoArrow_R1_On_It:: @ 0x084B7380
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row1_it.4bpp"
	.space 0x200
gSapphireMartArrow_R2_Off_It:: @ 0x084B7600
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row2_it.4bpp"
gSapphireMartArrow_R2_On_It:: @ 0x084B7680
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row2_it.4bpp"
gSapphireEvoArrow_R2_Off_It:: @ 0x084B7700
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row2_it.4bpp"
gSapphireEvoArrow_R2_On_It:: @ 0x084B7780
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row2_it.4bpp"
	.space 0x200
gSapphireMartArrow_R3_Off_It:: @ 0x084B7A00
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_it.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_filler_it.4bpp"
gSapphireMartArrow_R3_On_It:: @ 0x084B7A80
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_it.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_filler_it.4bpp"
gSapphireEvoArrow_R3_Off_It:: @ 0x084B7B00
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_it.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_filler_it.4bpp"
gSapphireEvoArrow_R3_On_It:: @ 0x084B7B80
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_it.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_filler_it.4bpp"
	.space 0x620
gSapphireMartArrow_R0_Off_Es:: @ 0x084B8220
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row0_es.4bpp"
gSapphireMartArrow_R0_On_Es:: @ 0x084B82A0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row0_es.4bpp"
gSapphireEvoArrow_R0_Off_Es:: @ 0x084B8320
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row0_es.4bpp"
gSapphireEvoArrow_R0_On_Es:: @ 0x084B83A0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row0_es.4bpp"
	.space 0x200
gSapphireMartArrow_R1_Off_Es:: @ 0x084B8620
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row1_es.4bpp"
gSapphireMartArrow_R1_On_Es:: @ 0x084B86A0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row1_es.4bpp"
gSapphireEvoArrow_R1_Off_Es:: @ 0x084B8720
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row1_es.4bpp"
gSapphireEvoArrow_R1_On_Es:: @ 0x084B87A0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row1_es.4bpp"
	.space 0x200
gSapphireMartArrow_R2_Off_Es:: @ 0x084B8A20
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row2_es.4bpp"
gSapphireMartArrow_R2_On_Es:: @ 0x084B8AA0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row2_es.4bpp"
gSapphireEvoArrow_R2_Off_Es:: @ 0x084B8B20
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row2_es.4bpp"
gSapphireEvoArrow_R2_On_Es:: @ 0x084B8BA0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row2_es.4bpp"
	.space 0x200
gSapphireMartArrow_R3_Off_Es:: @ 0x084B8E20
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_es.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_filler_es.4bpp"
gSapphireMartArrow_R3_On_Es:: @ 0x084B8EA0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_es.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_filler_es.4bpp"
gSapphireEvoArrow_R3_Off_Es:: @ 0x084B8F20
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_es.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_filler_es.4bpp"
gSapphireEvoArrow_R3_On_Es:: @ 0x084B8FA0
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_es.4bpp"
	.incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_filler_es.4bpp"
	.space 0x620
gSapphire_LSlingshot_Off_R0:: @ 0x084B9640
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row0.4bpp"
	.space 0x40

gSapphire_LSlingshot_On_R0:: @ 0x084B96A0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row0.4bpp"
	.space 0x80

gSapphire_RSlingshot_Off_R0:: @ 0x084B9740
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row0.4bpp"
	.space 0x40

gSapphire_RSlingshot_On_R0:: @ 0x084B97A0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row0.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R1:: @ 0x084B9A40
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row1.4bpp"
	.space 0x20

gSapphire_LSlingshot_On_R1:: @ 0x084B9AA0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row1.4bpp"
	.space 0x40

gSapphire_RSlingshot_Off_R1:: @ 0x084B9B20
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row1.4bpp"
	.space 0x20

gSapphire_RSlingshot_On_R1:: @ 0x084B9B80
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row1.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R2:: @ 0x084B9E40
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row2.4bpp"

gSapphire_LSlingshot_On_R2:: @ 0x084B9EA0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row2.4bpp"

gSapphire_RSlingshot_Off_R2:: @ 0x084B9F00
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row2.4bpp"

gSapphire_RSlingshot_On_R2:: @ 0x084B9F60
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row2.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R3:: @ 0x084BA240
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row3.4bpp"

gSapphire_LSlingshot_On_R3:: @ 0x084BA2A0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row3.4bpp"

gSapphire_RSlingshot_Off_R3:: @ 0x084BA300
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row3.4bpp"

gSapphire_RSlingshot_On_R3:: @ 0x084BA360
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row3.4bpp"
	.space 0x2A0

gSapphire_LSlingshot_Off_R4:: @ 0x084BA660
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row4.4bpp"
	.space 0x20

gSapphire_LSlingshot_On_R4:: @ 0x084BA6C0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row4.4bpp"

gSapphire_RSlingshot_Off_R4:: @ 0x084BA700
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row4.4bpp"
	.space 0x20

gSapphire_RSlingshot_On_R4:: @ 0x084BA760
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row4.4bpp"
	.space 0x2C0


gWailmerWaterFrame0Row0:: @ 0x084BAA60
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row0.4bpp"
	.space 0x40

gWailmerWaterFrame1Row0:: @ 0x084BAAE0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row0.4bpp"
	.space 0x40

gWailmerWaterFrame2Row0:: @ 0x084BAB60
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row0.4bpp"
	.space 0x2C0

gWailmerWaterFrame0Row1:: @ 0x084BAE60
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row1.4bpp"

gWailmerWaterFrame1Row1:: @ 0x084BAEE0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row1.4bpp"

gWailmerWaterFrame2Row1:: @ 0x084BAF60
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row1.4bpp"
	.space 0x280

gWailmerWaterFrame0Row2:: @ 0x084BB260
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row2.4bpp"
	.space 0x20

gWailmerWaterFrame1Row2:: @ 0x084BB2E0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row2.4bpp"
	.space 0x20

gWailmerWaterFrame2Row2:: @ 0x084BB360
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row2.4bpp"
	.space 0x2A0

gWailmerWaterFrame0Row3:: @ 0x084BB660
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row3.4bpp"
	.space 0x20

gWailmerWaterFrame1Row3:: @ 0x084BB6E0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row3.4bpp"
	.space 0x20

gWailmerWaterFrame2Row3:: @ 0x084BB760
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row3.4bpp"
	.space 0x2C0

gSapphireBoardBG1Tiles:: @ 0x084BBA80
	@ loaded to charblock 2; tiles 0-703 are overwritten by the scroll ring
	.incbin "graphics/stage/sapphire/sapphire_board_bg1_tiles.4bpp"

gSapphireBoardBG1Tilemap:: @ 0x084C3A80
	.incbin "graphics/stage/sapphire/sapphire_board_bg1_tilemap.bin"
