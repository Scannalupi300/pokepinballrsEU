@ Note: file has a shared 'bumper collision map' (gSharedBumperCollisionMap)
@ All other entries in this file are ruby board specific

gRubyBoardBG3Tilemap:: @ 0x08328D5C
	.incbin "graphics/stage/ruby/ruby_board_bg3_tilemap.bin"

gRubyBoardCollisionTileDataLayer0:: @ 0x08329D5C
    .incbin "data/board_data/collision/ruby/boardtop_launch_tiledata.bin"

gRubyBoardCollisionAngleDataLayer0:: @ 0x0832BD5C
    .incbin "data/board_data/collision/ruby/boardtop_launch_angledata.bin"

gRubyBoardCollisionTypeDataLayer0:: @ 0x083444DC
    .incbin "data/board_data/collision/ruby/boardtop_launch_typedata.bin"

gRubyBoardCollisionTileDataLayer0Alt:: @ 0x0835089C
    .incbin "data/board_data/collision/ruby/boardtop_normal_tiledata.bin"

gRubyBoardCollisionAngleDataLayer0Alt:: @ 0x0835289C
    .incbin "data/board_data/collision/ruby/boardtop_normal_angledata.bin"

gRubyBoardCollisionTypeDataLayer0Alt:: @ 0x0836AC1C
    .incbin "data/board_data/collision/ruby/boardtop_normal_typedata.bin"

gRubyBoardCollisionTileDataLayer1:: @ 0x08376DDC
    .incbin "data/board_data/collision/ruby/boardbottom_tiledata.bin"

gRubyBoardCollisionAngleDataLayer1:: @ 0x08378DDC
    .incbin "data/board_data/collision/ruby/boardbottom_angledata.bin"

gRubyBoardCollisionTypeDataLayer1:: @ 0x0838CA5C
    .incbin "data/board_data/collision/ruby/boardbottom_typedata.bin"

gRubyBoardBG2Tilemap:: @ 0x0839689C
	.incbin "graphics/stage/ruby/ruby_board_ramp_tilemap.bin"

gRubyBoardCollisionTileDataLayer2:: @ 0x0839789C
    .incbin "data/board_data/collision/ruby/topramps_tiledata.bin"

gRubyBoardCollisionAngleDataLayer2:: @ 0x0839989C
    .incbin "data/board_data/collision/ruby/topramps_angledata.bin"

gRubyBoardCollisionTypeDataLayer2:: @ 0x083AB71C
    .incbin "data/board_data/collision/ruby/topramps_typedata.bin"

gRubyBoardCompressedTiles1_En:: @ 0x083B465C
gRubyBoardCompressedTiles1:: @ 0x083B465C
	.incbin "graphics/stage/ruby/ruby_board_bgramp_tiles.4bpp.lz"

gRubyBoardCompressedTiles2_En:: @ 0x083B61D8
gRubyBoardCompressedTiles2:: @ 0x083B61D8
	.incbin "graphics/stage/ruby/ruby_board_bgtop_tiles.4bpp.lz"

gRubyBoardCompressedTiles2_Fr:: @ 0x083B8DAC
	.incbin "graphics/stage/ruby/ruby_board_bgtop_tiles_fr.4bpp.lz"
gRubyBoardCompressedTiles2_De:: @ 0x083BB964
	.incbin "graphics/stage/ruby/ruby_board_bgtop_tiles_de.4bpp.lz"
gRubyBoardCompressedTiles2_It:: @ 0x083BE4DC
	.incbin "graphics/stage/ruby/ruby_board_bgtop_tiles_it.4bpp.lz"
gRubyBoardCompressedTiles2_Es:: @ 0x083C108C
	.incbin "graphics/stage/ruby/ruby_board_bgtop_tiles_es.4bpp.lz"
gRubyBoardCompressedBGTileBuffer_En:: @ 0x083C3C44
gRubyBoardCompressedBGTileBuffer:: @ 0x083C3C44
	.incbin "graphics/stage/ruby/ruby_board_bgbottom_tiles.4bpp.lz"

gRubyBoardCompressedBGTileBuffer_Fr:: @ 0x083C5E20
	.incbin "graphics/stage/ruby/ruby_board_bgbottom_tiles_fr.4bpp.lz"
gRubyBoardCompressedBGTileBuffer_De:: @ 0x083C7FF8
	.incbin "graphics/stage/ruby/ruby_board_bgbottom_tiles_de.4bpp.lz"
gRubyBoardCompressedBGTileBuffer_It:: @ 0x083CA1E0
	.incbin "graphics/stage/ruby/ruby_board_bgbottom_tiles_it.4bpp.lz"
gRubyBoardCompressedBGTileBuffer_Es:: @ 0x083CC39C
	.incbin "graphics/stage/ruby/ruby_board_bgbottom_tiles_es.4bpp.lz"
gRubyBoardCompressedTiles1_Fr:: @ 0x083CE564
	.incbin "graphics/stage/ruby/ruby_board_bgramp_tiles_fr.4bpp.lz"
gRubyBoardCompressedTiles1_De:: @ 0x083D00B8
	.incbin "graphics/stage/ruby/ruby_board_bgramp_tiles_de.4bpp.lz"
gRubyBoardCompressedTiles1_It:: @ 0x083D1BF4
	.incbin "graphics/stage/ruby/ruby_board_bgramp_tiles_it.4bpp.lz"
gRubyBoardCompressedTiles1_Es:: @ 0x083D374C
	.incbin "graphics/stage/ruby/ruby_board_bgramp_tiles_es.4bpp.lz"
gSharedBumperCollisionMap:: @ 0x083D52A4
	.incbin "data/board_data/collision/ruby/shared_bumper_entity_collision_64x64.bin"

gRubyLinooneLeftCollisionMap:: @ 0x083D72A4
    .incbin "data/board_data/collision/ruby/linoone_left_collision_map_72x72.bin"

gRubyLinooneRightCollisionMap:: @ 0x083D9B24
    .incbin "data/board_data/collision/ruby/linoone_right_collision_map_72x72.bin"

gWhiscashCollisionMap:: @ 0x083DC3A4
	.incbin "data/board_data/collision/ruby/whiscash_entity_collision_80x88.bin"


@ Evo Arrows. Named this way for comprehension in folder.
@ E/V/O arrows. Second digit is '0 Top/1 Mid/2 Bottom',
@ First digit is 'variant'.
gRubyEvoArrow_E_0Lit_Top:: @ 0x083DFAA4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_0.4bpp"

gRubyEvoArrow_E_1Lit_Top:: @ 0x083DFB04
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_0.4bpp"

gRubyEvoArrow_E_2PlusLit_Top:: @ 0x083DFB64
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_0.4bpp"

gRubyEvoArrow_V_0Lit_Top:: @ 0x083DFBC4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_0.4bpp"

gRubyEvoArrow_V_1Lit_Top:: @ 0x083DFC24
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_0.4bpp"

gRubyEvoArrow_V_2Lit_Top:: @ 0x083DFC84
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_0.4bpp"

gRubyEvoArrow_V_3Lit_Top:: @ 0x083DFCE4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_0.4bpp"

gRubyEvoArrow_O_Under2Lit_Top:: @ 0x083DFD44
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_0.4bpp"

gRubyEvoArrow_O_2Lit_Top:: @ 0x083DFDA4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_0.4bpp"

gRubyEvoArrow_O_3Lit_Top:: @ 0x083DFE04
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_0.4bpp"
	.space 0x40

gRubyEvoArrow_E_0Lit_Mid:: @ 0x083DFEA4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_1.4bpp"

gRubyEvoArrow_E_1Lit_Mid:: @ 0x083DFF04
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_1.4bpp"

gRubyEvoArrow_E_2PlusLit_Mid:: @ 0x083DFF64
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_1.4bpp"

gRubyEvoArrow_V_0Lit_Mid:: @ 0x083DFFC4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_1.4bpp"

gRubyEvoArrow_V_1Lit_Mid:: @ 0x083E0024
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_1.4bpp"

gRubyEvoArrow_V_2Lit_Mid:: @ 0x083E0084
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_1.4bpp"

gRubyEvoArrow_V_3Lit_Mid:: @ 0x083E00E4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_1.4bpp"

gRubyEvoArrow_O_Under2Lit_Mid:: @ 0x083E0144
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_1.4bpp"

gRubyEvoArrow_O_2Lit_Mid:: @ 0x083E01A4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_1.4bpp"

gRubyEvoArrow_O_3Lit_Mid:: @ 0x083E0204
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_1.4bpp"
	.space 0x40

gRubyEvoArrow_E_0Lit_Bot:: @ 0x083E02A4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_2.4bpp"

gRubyEvoArrow_E_1Lit_Bot:: @ 0x083E0304
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_2.4bpp"

gRubyEvoArrow_E_2PlusLit_Bot:: @ 0x083E0364
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_2.4bpp"

gRubyEvoArrow_V_0Lit_Bot:: @ 0x083E03C4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_2.4bpp"

gRubyEvoArrow_V_1Lit_Bot:: @ 0x083E0424
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_2.4bpp"

gRubyEvoArrow_V_2Lit_Bot:: @ 0x083E0484
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_2.4bpp"

gRubyEvoArrow_V_3Lit_Bot:: @ 0x083E04E4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_2.4bpp"

gRubyEvoArrow_O_Under2Lit_Bot:: @ 0x083E0544
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_2.4bpp"

gRubyEvoArrow_O_2Lit_Bot:: @ 0x083E05A4
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_2.4bpp"

gRubyEvoArrow_O_3Lit_Bot:: @ 0x083E0604
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_2.4bpp"
	.space 0x40


@ Coin Arrows

gRubyCoinArrow_1_0Lit_Top:: @ 0x083E06A4
	@.incbin "graphics/stage/ruby/ruby_coin_arrows.4bpp"

    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p0.4bpp"

gRubyCoinArrow_1_1Lit_Top:: @ 0x083E0704
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p0.4bpp"

gRubyCoinArrow_1_2PlusLit_Top:: @ 0x083E0764
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p0.4bpp"

gRubyCoinArrow_5_0Lit_Top:: @ 0x083E07C4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p0.4bpp"

gRubyCoinArrow_5_1Lit_Top:: @ 0x083E0824
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p0.4bpp"

gRubyCoinArrow_5_2Lit_Top:: @ 0x083E0884
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p0.4bpp"

gRubyCoinArrow_5_3Lit_Top:: @ 0x083E08E4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p0.4bpp"

gRubyCoinArrow_10_Under2Lit_Top:: @ 0x083E0944
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p0.4bpp"

gRubyCoinArrow_10_2Lit_Top:: @ 0x083E09A4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p0.4bpp"

gRubyCoinArrow_10_3Lit_Top:: @ 0x083E0A04
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p0.4bpp"
    .space 0x40

gRubyCoinArrow_1_0Lit_Mid:: @ 0x083E0AA4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p1.4bpp"

gRubyCoinArrow_1_1Lit_Mid:: @ 0x083E0B04
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p1.4bpp"

gRubyCoinArrow_1_2PlusLit_Mid:: @ 0x083E0B64
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p1.4bpp"

gRubyCoinArrow_5_0Lit_Mid:: @ 0x083E0BC4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p1.4bpp"

gRubyCoinArrow_5_1Lit_Mid:: @ 0x083E0C24
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p1.4bpp"

gRubyCoinArrow_5_2Lit_Mid:: @ 0x083E0C84
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p1.4bpp"

gRubyCoinArrow_5_3Lit_Mid:: @ 0x083E0CE4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p1.4bpp"

gRubyCoinArrow_10_Under2Lit_Mid:: @ 0x083E0D44
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p1.4bpp"

gRubyCoinArrow_10_2Lit_Mid:: @ 0x083E0DA4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p1.4bpp"

gRubyCoinArrow_10_3Lit_Mid:: @ 0x083E0E04
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p1.4bpp"
    .space 0x40

gRubyCoinArrow_1_0Lit_Bot:: @ 0x083E0EA4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p2.4bpp"

gRubyCoinArrow_1_1Lit_Bot:: @ 0x083E0F04
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p2.4bpp"

gRubyCoinArrow_1_2PlusLit_Bot:: @ 0x083E0F64
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p2.4bpp"

gRubyCoinArrow_5_0Lit_Bot:: @ 0x083E0FC4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p2.4bpp"

gRubyCoinArrow_5_1Lit_Bot:: @ 0x083E1024
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p2.4bpp"

gRubyCoinArrow_5_2Lit_Bot:: @ 0x083E1084
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p2.4bpp"

gRubyCoinArrow_5_3Lit_Bot:: @ 0x083E10E4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p2.4bpp"

gRubyCoinArrow_10_Under2Lit_Bot:: @ 0x083E1144
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p2.4bpp"

gRubyCoinArrow_10_2Lit_Bot:: @ 0x083E11A4
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p2.4bpp"

gRubyCoinArrow_10_3Lit_Bot:: @ 0x083E1204
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p2.4bpp"
    .space 0x40


@ Get Arrows

gRubyGetArrow_G_0Lit_Top:: @ 0x083E12A4
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_0.4bpp"

gRubyGetArrow_G_1Lit_Top:: @ 0x083E1304
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_0.4bpp"

gRubyGetArrow_G_2PlusLit_Top:: @ 0x083E1364
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_0.4bpp"
    .space 0x20

gRubyGetArrow_E_0Lit_Top:: @ 0x083E13E4
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_0.4bpp"
    .space 0x20

gRubyGetArrow_E_1Lit_Top:: @ 0x083E1444
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_0.4bpp"
    .space 0x20

gRubyGetArrow_E_2Lit_Top:: @ 0x083E14A4
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_0.4bpp"
    .space 0x20

gRubyGetArrow_E_3Lit_Top:: @ 0x083E1504
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_0.4bpp"
    .space 0x20

gRubyGetArrow_T_Under2Lit_Top:: @ 0x083E1564
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_0.4bpp"
    .space 0x20

gRubyGetArrow_T_2Lit_Top:: @ 0x083E15C4
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_0.4bpp"
    .space 0x20

gRubyGetArrow_T_3Lit_Top:: @ 0x083E1624
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_0.4bpp"
    .space 0x40

gRubyGetArrow_G_0Lit_Mid:: @ 0x083E16A4
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_1.4bpp"

gRubyGetArrow_G_1Lit_Mid:: @ 0x083E1704
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_1.4bpp"

gRubyGetArrow_G_2PlusLit_Mid:: @ 0x083E1764
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_1.4bpp"
    .space 0x20

gRubyGetArrow_E_0Lit_Mid:: @ 0x083E17E4
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_1.4bpp"
    .space 0x20

gRubyGetArrow_E_1Lit_Mid:: @ 0x083E1844
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_1.4bpp"
    .space 0x20

gRubyGetArrow_E_2Lit_Mid:: @ 0x083E18A4
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_1.4bpp"
    .space 0x20

gRubyGetArrow_E_3Lit_Mid:: @ 0x083E1904
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_1.4bpp"

gRubyGetArrow_T_Under2Lit_Mid:: @ 0x083E1944
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_1.4bpp"

gRubyGetArrow_T_2Lit_Mid:: @ 0x083E19A4
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_1.4bpp"

gRubyGetArrow_T_3Lit_Mid:: @ 0x083E1A04
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_1.4bpp"
    .space 0x40

gRubyGetArrow_G_0Lit_Bot:: @ 0x083E1AA4
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_2.4bpp"

gRubyGetArrow_G_1Lit_Bot:: @ 0x083E1B04
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_2.4bpp"

gRubyGetArrow_G_2PlusLit_Bot:: @ 0x083E1B64
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_2.4bpp"

gRubyGetArrow_E_0Lit_Bot:: @ 0x083E1BC4
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_2.4bpp"

gRubyGetArrow_E_1Lit_Bot:: @ 0x083E1C24
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_2.4bpp"

gRubyGetArrow_E_2Lit_Bot:: @ 0x083E1C84
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_2.4bpp"

gRubyGetArrow_E_3Lit_Bot:: @ 0x083E1CE4
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_2.4bpp"

gRubyGetArrow_T_Under2Lit_Bot:: @ 0x083E1D44
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_2.4bpp"

gRubyGetArrow_T_2Lit_Bot:: @ 0x083E1DA4
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_2.4bpp"

gRubyGetArrow_T_3Lit_Bot:: @ 0x083E1E04
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_2.4bpp"
	.space 0x40
	.fill 0x20, 1, 0x22


@ Ball power up lights

gRubyEvoArrow_E_0Lit_Top_Fr:: @ 0x083E1EC4
	@ copy of the English data, not used by the code
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_0.4bpp"
gRubyEvoArrow_E_1Lit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_0.4bpp"
gRubyEvoArrow_E_2PlusLit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_0.4bpp"
gRubyEvoArrow_V_0Lit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_0.4bpp"
gRubyEvoArrow_V_1Lit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_0.4bpp"
gRubyEvoArrow_V_2Lit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_0.4bpp"
gRubyEvoArrow_V_3Lit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_0.4bpp"
gRubyEvoArrow_O_Under2Lit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_0.4bpp"
gRubyEvoArrow_O_2Lit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_0.4bpp"
gRubyEvoArrow_O_3Lit_Top_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_0.4bpp"
	.space 0x40
gRubyEvoArrow_E_0Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_1.4bpp"
gRubyEvoArrow_E_1Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_1.4bpp"
gRubyEvoArrow_E_2PlusLit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_1.4bpp"
gRubyEvoArrow_V_0Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_1.4bpp"
gRubyEvoArrow_V_1Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_1.4bpp"
gRubyEvoArrow_V_2Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_1.4bpp"
gRubyEvoArrow_V_3Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_1.4bpp"
gRubyEvoArrow_O_Under2Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_1.4bpp"
gRubyEvoArrow_O_2Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_1.4bpp"
gRubyEvoArrow_O_3Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_1.4bpp"
	.space 0x40
gRubyEvoArrow_E_0Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_2.4bpp"
gRubyEvoArrow_E_1Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_2.4bpp"
gRubyEvoArrow_E_2PlusLit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_2.4bpp"
gRubyEvoArrow_V_0Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_2.4bpp"
gRubyEvoArrow_V_1Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_2.4bpp"
gRubyEvoArrow_V_2Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_2.4bpp"
gRubyEvoArrow_V_3Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_2.4bpp"
gRubyEvoArrow_O_Under2Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_2.4bpp"
gRubyEvoArrow_O_2Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_2.4bpp"
gRubyEvoArrow_O_3Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_2.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
gRubyCoinArrow_1_1Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
gRubyCoinArrow_1_2PlusLit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p0.4bpp"
gRubyCoinArrow_5_0Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
gRubyCoinArrow_5_1Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
gRubyCoinArrow_5_2Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p0.4bpp"
gRubyCoinArrow_5_3Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p0.4bpp"
gRubyCoinArrow_10_Under2Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
gRubyCoinArrow_10_2Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
gRubyCoinArrow_10_3Lit_Top_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p0.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p1.4bpp"
gRubyCoinArrow_1_1Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
gRubyCoinArrow_1_2PlusLit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p1.4bpp"
gRubyCoinArrow_5_0Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
gRubyCoinArrow_5_1Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
gRubyCoinArrow_5_2Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p1.4bpp"
gRubyCoinArrow_5_3Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p1.4bpp"
gRubyCoinArrow_10_Under2Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
gRubyCoinArrow_10_2Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
gRubyCoinArrow_10_3Lit_Mid_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p1.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p2.4bpp"
gRubyCoinArrow_1_1Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p2.4bpp"
gRubyCoinArrow_1_2PlusLit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p2.4bpp"
gRubyCoinArrow_5_0Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p2.4bpp"
gRubyCoinArrow_5_1Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p2.4bpp"
gRubyCoinArrow_5_2Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p2.4bpp"
gRubyCoinArrow_5_3Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p2.4bpp"
gRubyCoinArrow_10_Under2Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
gRubyCoinArrow_10_2Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
gRubyCoinArrow_10_3Lit_Bot_Fr::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p2.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Top_Fr:: @ 0x083E36C4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_0_fr.4bpp"
gRubyGetArrow_G_1Lit_Top_Fr:: @ 0x083E3724
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_0_fr.4bpp"
gRubyGetArrow_G_2PlusLit_Top_Fr:: @ 0x083E3784
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_0_fr.4bpp"
	.space 0x20
gRubyGetArrow_E_0Lit_Top_Fr:: @ 0x083E3804
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_0_fr.4bpp"
	.space 0x20
gRubyGetArrow_E_1Lit_Top_Fr:: @ 0x083E3864
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_0_fr.4bpp"
	.space 0x20
gRubyGetArrow_E_2Lit_Top_Fr:: @ 0x083E38C4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_0_fr.4bpp"
	.space 0x20
gRubyGetArrow_E_3Lit_Top_Fr:: @ 0x083E3924
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_0_fr.4bpp"
	.space 0x20
gRubyGetArrow_T_Under2Lit_Top_Fr:: @ 0x083E3984
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_0_fr.4bpp"
	.space 0x20
gRubyGetArrow_T_2Lit_Top_Fr:: @ 0x083E39E4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_0_fr.4bpp"
	.space 0x20
gRubyGetArrow_T_3Lit_Top_Fr:: @ 0x083E3A44
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_0_fr.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Mid_Fr:: @ 0x083E3AC4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_1_fr.4bpp"
gRubyGetArrow_G_1Lit_Mid_Fr:: @ 0x083E3B24
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_1_fr.4bpp"
gRubyGetArrow_G_2PlusLit_Mid_Fr:: @ 0x083E3B84
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_1_fr.4bpp"
	.space 0x20
gRubyGetArrow_E_0Lit_Mid_Fr:: @ 0x083E3C04
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_1_fr.4bpp"
	.space 0x20
gRubyGetArrow_E_1Lit_Mid_Fr:: @ 0x083E3C64
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_1_fr.4bpp"
	.space 0x20
gRubyGetArrow_E_2Lit_Mid_Fr:: @ 0x083E3CC4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_1_fr.4bpp"
	.space 0x20
gRubyGetArrow_E_3Lit_Mid_Fr:: @ 0x083E3D24
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_1_fr.4bpp"
gRubyGetArrow_T_Under2Lit_Mid_Fr:: @ 0x083E3D64
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_1_fr.4bpp"
gRubyGetArrow_T_2Lit_Mid_Fr:: @ 0x083E3DC4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_1_fr.4bpp"
gRubyGetArrow_T_3Lit_Mid_Fr:: @ 0x083E3E24
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_1_fr.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Bot_Fr:: @ 0x083E3EC4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_2_fr.4bpp"
gRubyGetArrow_G_1Lit_Bot_Fr:: @ 0x083E3F24
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_2_fr.4bpp"
gRubyGetArrow_G_2PlusLit_Bot_Fr:: @ 0x083E3F84
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_2_fr.4bpp"
gRubyGetArrow_E_0Lit_Bot_Fr:: @ 0x083E3FE4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_2_fr.4bpp"
gRubyGetArrow_E_1Lit_Bot_Fr:: @ 0x083E4044
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_2_fr.4bpp"
gRubyGetArrow_E_2Lit_Bot_Fr:: @ 0x083E40A4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_2_fr.4bpp"
gRubyGetArrow_E_3Lit_Bot_Fr:: @ 0x083E4104
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_2_fr.4bpp"
gRubyGetArrow_T_Under2Lit_Bot_Fr:: @ 0x083E4164
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_2_fr.4bpp"
gRubyGetArrow_T_2Lit_Bot_Fr:: @ 0x083E41C4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_2_fr.4bpp"
gRubyGetArrow_T_3Lit_Bot_Fr:: @ 0x083E4224
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_2_fr.4bpp"
	.space 0x40
	.fill 0x20, 1, 0x22
gRubyEvoArrow_E_0Lit_Top_De:: @ 0x083E42E4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_0_de.4bpp"
gRubyEvoArrow_E_1Lit_Top_De:: @ 0x083E4344
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_0_de.4bpp"
gRubyEvoArrow_E_2PlusLit_Top_De:: @ 0x083E43A4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_0_de.4bpp"
gRubyEvoArrow_V_0Lit_Top_De:: @ 0x083E4404
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_0_de.4bpp"
gRubyEvoArrow_V_1Lit_Top_De:: @ 0x083E4464
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_0_de.4bpp"
gRubyEvoArrow_V_2Lit_Top_De:: @ 0x083E44C4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_0_de.4bpp"
gRubyEvoArrow_V_3Lit_Top_De:: @ 0x083E4524
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_0_de.4bpp"
gRubyEvoArrow_O_Under2Lit_Top_De:: @ 0x083E4584
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_0_de.4bpp"
gRubyEvoArrow_O_2Lit_Top_De:: @ 0x083E45E4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_0_de.4bpp"
gRubyEvoArrow_O_3Lit_Top_De:: @ 0x083E4644
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_0_de.4bpp"
	.space 0x40
gRubyEvoArrow_E_0Lit_Mid_De:: @ 0x083E46E4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_1_de.4bpp"
gRubyEvoArrow_E_1Lit_Mid_De:: @ 0x083E4744
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_1_de.4bpp"
gRubyEvoArrow_E_2PlusLit_Mid_De:: @ 0x083E47A4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_1_de.4bpp"
gRubyEvoArrow_V_0Lit_Mid_De:: @ 0x083E4804
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_1_de.4bpp"
gRubyEvoArrow_V_1Lit_Mid_De:: @ 0x083E4864
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_1_de.4bpp"
gRubyEvoArrow_V_2Lit_Mid_De:: @ 0x083E48C4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_1_de.4bpp"
gRubyEvoArrow_V_3Lit_Mid_De:: @ 0x083E4924
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_1_de.4bpp"
gRubyEvoArrow_O_Under2Lit_Mid_De:: @ 0x083E4984
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_1_de.4bpp"
gRubyEvoArrow_O_2Lit_Mid_De:: @ 0x083E49E4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_1_de.4bpp"
gRubyEvoArrow_O_3Lit_Mid_De:: @ 0x083E4A44
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_1_de.4bpp"
	.space 0x40
gRubyEvoArrow_E_0Lit_Bot_De:: @ 0x083E4AE4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_2_de.4bpp"
gRubyEvoArrow_E_1Lit_Bot_De:: @ 0x083E4B44
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_2_de.4bpp"
gRubyEvoArrow_E_2PlusLit_Bot_De:: @ 0x083E4BA4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_2_de.4bpp"
gRubyEvoArrow_V_0Lit_Bot_De:: @ 0x083E4C04
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_2_de.4bpp"
gRubyEvoArrow_V_1Lit_Bot_De:: @ 0x083E4C64
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_2_de.4bpp"
gRubyEvoArrow_V_2Lit_Bot_De:: @ 0x083E4CC4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_2_de.4bpp"
gRubyEvoArrow_V_3Lit_Bot_De:: @ 0x083E4D24
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_2_de.4bpp"
gRubyEvoArrow_O_Under2Lit_Bot_De:: @ 0x083E4D84
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_2_de.4bpp"
gRubyEvoArrow_O_2Lit_Bot_De:: @ 0x083E4DE4
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_2_de.4bpp"
gRubyEvoArrow_O_3Lit_Bot_De:: @ 0x083E4E44
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_2_de.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p0_de.4bpp"
gRubyCoinArrow_1_1Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p0_de.4bpp"
gRubyCoinArrow_1_2PlusLit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p0_de.4bpp"
gRubyCoinArrow_5_0Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p0_de.4bpp"
gRubyCoinArrow_5_1Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p0_de.4bpp"
gRubyCoinArrow_5_2Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p0_de.4bpp"
gRubyCoinArrow_5_3Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p0_de.4bpp"
gRubyCoinArrow_10_Under2Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p0_de.4bpp"
gRubyCoinArrow_10_2Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p0_de.4bpp"
gRubyCoinArrow_10_3Lit_Top_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p0_de.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p1_de.4bpp"
gRubyCoinArrow_1_1Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p1_de.4bpp"
gRubyCoinArrow_1_2PlusLit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p1_de.4bpp"
gRubyCoinArrow_5_0Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p1_de.4bpp"
gRubyCoinArrow_5_1Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p1_de.4bpp"
gRubyCoinArrow_5_2Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p1_de.4bpp"
gRubyCoinArrow_5_3Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p1_de.4bpp"
gRubyCoinArrow_10_Under2Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p1_de.4bpp"
gRubyCoinArrow_10_2Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p1_de.4bpp"
gRubyCoinArrow_10_3Lit_Mid_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p1_de.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p2_de.4bpp"
gRubyCoinArrow_1_1Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p2_de.4bpp"
gRubyCoinArrow_1_2PlusLit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p2_de.4bpp"
gRubyCoinArrow_5_0Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p2_de.4bpp"
gRubyCoinArrow_5_1Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p2_de.4bpp"
gRubyCoinArrow_5_2Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p2_de.4bpp"
gRubyCoinArrow_5_3Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p2_de.4bpp"
gRubyCoinArrow_10_Under2Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p2_de.4bpp"
gRubyCoinArrow_10_2Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p2_de.4bpp"
gRubyCoinArrow_10_3Lit_Bot_De::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p2_de.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Top_De:: @ 0x083E5AE4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_0_de.4bpp"
gRubyGetArrow_G_1Lit_Top_De:: @ 0x083E5B44
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_0_de.4bpp"
gRubyGetArrow_G_2PlusLit_Top_De:: @ 0x083E5BA4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_0_de.4bpp"
	.space 0x20
gRubyGetArrow_E_0Lit_Top_De:: @ 0x083E5C24
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_0_de.4bpp"
	.space 0x20
gRubyGetArrow_E_1Lit_Top_De:: @ 0x083E5C84
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_0_de.4bpp"
	.space 0x20
gRubyGetArrow_E_2Lit_Top_De:: @ 0x083E5CE4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_0_de.4bpp"
	.space 0x20
gRubyGetArrow_E_3Lit_Top_De:: @ 0x083E5D44
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_0_de.4bpp"
	.space 0x20
gRubyGetArrow_T_Under2Lit_Top_De:: @ 0x083E5DA4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_0_de.4bpp"
	.space 0x20
gRubyGetArrow_T_2Lit_Top_De:: @ 0x083E5E04
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_0_de.4bpp"
	.space 0x20
gRubyGetArrow_T_3Lit_Top_De:: @ 0x083E5E64
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_0_de.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Mid_De:: @ 0x083E5EE4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_1_de.4bpp"
gRubyGetArrow_G_1Lit_Mid_De:: @ 0x083E5F44
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_1_de.4bpp"
gRubyGetArrow_G_2PlusLit_Mid_De:: @ 0x083E5FA4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_1_de.4bpp"
	.space 0x20
gRubyGetArrow_E_0Lit_Mid_De:: @ 0x083E6024
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_1_de.4bpp"
	.space 0x20
gRubyGetArrow_E_1Lit_Mid_De:: @ 0x083E6084
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_1_de.4bpp"
	.space 0x20
gRubyGetArrow_E_2Lit_Mid_De:: @ 0x083E60E4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_1_de.4bpp"
	.space 0x20
gRubyGetArrow_E_3Lit_Mid_De:: @ 0x083E6144
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_1_de.4bpp"
gRubyGetArrow_T_Under2Lit_Mid_De:: @ 0x083E6184
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_1_de.4bpp"
gRubyGetArrow_T_2Lit_Mid_De:: @ 0x083E61E4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_1_de.4bpp"
gRubyGetArrow_T_3Lit_Mid_De:: @ 0x083E6244
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_1_de.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Bot_De:: @ 0x083E62E4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_2_de.4bpp"
gRubyGetArrow_G_1Lit_Bot_De:: @ 0x083E6344
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_2_de.4bpp"
gRubyGetArrow_G_2PlusLit_Bot_De:: @ 0x083E63A4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_2_de.4bpp"
gRubyGetArrow_E_0Lit_Bot_De:: @ 0x083E6404
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_2_de.4bpp"
gRubyGetArrow_E_1Lit_Bot_De:: @ 0x083E6464
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_2_de.4bpp"
gRubyGetArrow_E_2Lit_Bot_De:: @ 0x083E64C4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_2_de.4bpp"
gRubyGetArrow_E_3Lit_Bot_De:: @ 0x083E6524
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_2_de.4bpp"
gRubyGetArrow_T_Under2Lit_Bot_De:: @ 0x083E6584
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_2_de.4bpp"
gRubyGetArrow_T_2Lit_Bot_De:: @ 0x083E65E4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_2_de.4bpp"
gRubyGetArrow_T_3Lit_Bot_De:: @ 0x083E6644
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_2_de.4bpp"
	.space 0x40
	.fill 0x20, 1, 0x22
gRubyEvoArrow_E_0Lit_Top_It:: @ 0x083E6704
	@ copy of the English data, not used by the code
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_0.4bpp"
gRubyEvoArrow_E_1Lit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_0.4bpp"
gRubyEvoArrow_E_2PlusLit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_0.4bpp"
gRubyEvoArrow_V_0Lit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_0.4bpp"
gRubyEvoArrow_V_1Lit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_0.4bpp"
gRubyEvoArrow_V_2Lit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_0.4bpp"
gRubyEvoArrow_V_3Lit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_0.4bpp"
gRubyEvoArrow_O_Under2Lit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_0.4bpp"
gRubyEvoArrow_O_2Lit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_0.4bpp"
gRubyEvoArrow_O_3Lit_Top_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_0.4bpp"
	.space 0x40
gRubyEvoArrow_E_0Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_1.4bpp"
gRubyEvoArrow_E_1Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_1.4bpp"
gRubyEvoArrow_E_2PlusLit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_1.4bpp"
gRubyEvoArrow_V_0Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_1.4bpp"
gRubyEvoArrow_V_1Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_1.4bpp"
gRubyEvoArrow_V_2Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_1.4bpp"
gRubyEvoArrow_V_3Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_1.4bpp"
gRubyEvoArrow_O_Under2Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_1.4bpp"
gRubyEvoArrow_O_2Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_1.4bpp"
gRubyEvoArrow_O_3Lit_Mid_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_1.4bpp"
	.space 0x40
gRubyEvoArrow_E_0Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_2.4bpp"
gRubyEvoArrow_E_1Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_2.4bpp"
gRubyEvoArrow_E_2PlusLit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_2.4bpp"
gRubyEvoArrow_V_0Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_2.4bpp"
gRubyEvoArrow_V_1Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_2.4bpp"
gRubyEvoArrow_V_2Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_2.4bpp"
gRubyEvoArrow_V_3Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_2.4bpp"
gRubyEvoArrow_O_Under2Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_2.4bpp"
gRubyEvoArrow_O_2Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_2.4bpp"
gRubyEvoArrow_O_3Lit_Bot_It::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_2.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
gRubyCoinArrow_1_1Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
gRubyCoinArrow_1_2PlusLit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p0.4bpp"
gRubyCoinArrow_5_0Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
gRubyCoinArrow_5_1Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
gRubyCoinArrow_5_2Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p0.4bpp"
gRubyCoinArrow_5_3Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p0.4bpp"
gRubyCoinArrow_10_Under2Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
gRubyCoinArrow_10_2Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
gRubyCoinArrow_10_3Lit_Top_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p0.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p1.4bpp"
gRubyCoinArrow_1_1Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
gRubyCoinArrow_1_2PlusLit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p1.4bpp"
gRubyCoinArrow_5_0Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
gRubyCoinArrow_5_1Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
gRubyCoinArrow_5_2Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p1.4bpp"
gRubyCoinArrow_5_3Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p1.4bpp"
gRubyCoinArrow_10_Under2Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
gRubyCoinArrow_10_2Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
gRubyCoinArrow_10_3Lit_Mid_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p1.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p2.4bpp"
gRubyCoinArrow_1_1Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p2.4bpp"
gRubyCoinArrow_1_2PlusLit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p2.4bpp"
gRubyCoinArrow_5_0Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p2.4bpp"
gRubyCoinArrow_5_1Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p2.4bpp"
gRubyCoinArrow_5_2Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p2.4bpp"
gRubyCoinArrow_5_3Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p2.4bpp"
gRubyCoinArrow_10_Under2Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
gRubyCoinArrow_10_2Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
gRubyCoinArrow_10_3Lit_Bot_It::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p2.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Top_It:: @ 0x083E7F04
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_0_it.4bpp"
gRubyGetArrow_G_1Lit_Top_It:: @ 0x083E7F64
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_0_it.4bpp"
gRubyGetArrow_G_2PlusLit_Top_It:: @ 0x083E7FC4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_0_it.4bpp"
	.space 0x20
gRubyGetArrow_E_0Lit_Top_It:: @ 0x083E8044
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_0_it.4bpp"
	.space 0x20
gRubyGetArrow_E_1Lit_Top_It:: @ 0x083E80A4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_0_it.4bpp"
	.space 0x20
gRubyGetArrow_E_2Lit_Top_It:: @ 0x083E8104
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_0_it.4bpp"
	.space 0x20
gRubyGetArrow_E_3Lit_Top_It:: @ 0x083E8164
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_0_it.4bpp"
	.space 0x20
gRubyGetArrow_T_Under2Lit_Top_It:: @ 0x083E81C4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_0_it.4bpp"
	.space 0x20
gRubyGetArrow_T_2Lit_Top_It:: @ 0x083E8224
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_0_it.4bpp"
	.space 0x20
gRubyGetArrow_T_3Lit_Top_It:: @ 0x083E8284
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_0_it.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Mid_It:: @ 0x083E8304
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_1_it.4bpp"
gRubyGetArrow_G_1Lit_Mid_It:: @ 0x083E8364
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_1_it.4bpp"
gRubyGetArrow_G_2PlusLit_Mid_It:: @ 0x083E83C4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_1_it.4bpp"
	.space 0x20
gRubyGetArrow_E_0Lit_Mid_It:: @ 0x083E8444
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_1_it.4bpp"
	.space 0x20
gRubyGetArrow_E_1Lit_Mid_It:: @ 0x083E84A4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_1_it.4bpp"
	.space 0x20
gRubyGetArrow_E_2Lit_Mid_It:: @ 0x083E8504
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_1_it.4bpp"
	.space 0x20
gRubyGetArrow_E_3Lit_Mid_It:: @ 0x083E8564
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_1_it.4bpp"
gRubyGetArrow_T_Under2Lit_Mid_It:: @ 0x083E85A4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_1_it.4bpp"
gRubyGetArrow_T_2Lit_Mid_It:: @ 0x083E8604
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_1_it.4bpp"
gRubyGetArrow_T_3Lit_Mid_It:: @ 0x083E8664
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_1_it.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Bot_It:: @ 0x083E8704
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_2_it.4bpp"
gRubyGetArrow_G_1Lit_Bot_It:: @ 0x083E8764
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_2_it.4bpp"
gRubyGetArrow_G_2PlusLit_Bot_It:: @ 0x083E87C4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_2_it.4bpp"
gRubyGetArrow_E_0Lit_Bot_It:: @ 0x083E8824
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_2_it.4bpp"
gRubyGetArrow_E_1Lit_Bot_It:: @ 0x083E8884
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_2_it.4bpp"
gRubyGetArrow_E_2Lit_Bot_It:: @ 0x083E88E4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_2_it.4bpp"
gRubyGetArrow_E_3Lit_Bot_It:: @ 0x083E8944
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_2_it.4bpp"
gRubyGetArrow_T_Under2Lit_Bot_It:: @ 0x083E89A4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_2_it.4bpp"
gRubyGetArrow_T_2Lit_Bot_It:: @ 0x083E8A04
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_2_it.4bpp"
gRubyGetArrow_T_3Lit_Bot_It:: @ 0x083E8A64
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_2_it.4bpp"
	.space 0x40
	.fill 0x20, 1, 0x22
gRubyEvoArrow_E_0Lit_Top_Es:: @ 0x083E8B24
	@ copy of the English data, not used by the code
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_0.4bpp"
gRubyEvoArrow_E_1Lit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_0.4bpp"
gRubyEvoArrow_E_2PlusLit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_0.4bpp"
gRubyEvoArrow_V_0Lit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_0.4bpp"
gRubyEvoArrow_V_1Lit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_0.4bpp"
gRubyEvoArrow_V_2Lit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_0.4bpp"
gRubyEvoArrow_V_3Lit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_0.4bpp"
gRubyEvoArrow_O_Under2Lit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_0.4bpp"
gRubyEvoArrow_O_2Lit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_0.4bpp"
gRubyEvoArrow_O_3Lit_Top_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_0.4bpp"
	.space 0x40
gRubyEvoArrow_E_0Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_1.4bpp"
gRubyEvoArrow_E_1Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_1.4bpp"
gRubyEvoArrow_E_2PlusLit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_1.4bpp"
gRubyEvoArrow_V_0Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_1.4bpp"
gRubyEvoArrow_V_1Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_1.4bpp"
gRubyEvoArrow_V_2Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_1.4bpp"
gRubyEvoArrow_V_3Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_1.4bpp"
gRubyEvoArrow_O_Under2Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_1.4bpp"
gRubyEvoArrow_O_2Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_1.4bpp"
gRubyEvoArrow_O_3Lit_Mid_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_1.4bpp"
	.space 0x40
gRubyEvoArrow_E_0Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_2.4bpp"
gRubyEvoArrow_E_1Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_2.4bpp"
gRubyEvoArrow_E_2PlusLit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_2.4bpp"
gRubyEvoArrow_V_0Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_2.4bpp"
gRubyEvoArrow_V_1Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_2.4bpp"
gRubyEvoArrow_V_2Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_2.4bpp"
gRubyEvoArrow_V_3Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_2.4bpp"
gRubyEvoArrow_O_Under2Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_2.4bpp"
gRubyEvoArrow_O_2Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_2.4bpp"
gRubyEvoArrow_O_3Lit_Bot_Es::
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_2.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
gRubyCoinArrow_1_1Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
gRubyCoinArrow_1_2PlusLit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p0.4bpp"
gRubyCoinArrow_5_0Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
gRubyCoinArrow_5_1Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
gRubyCoinArrow_5_2Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p0.4bpp"
gRubyCoinArrow_5_3Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p0.4bpp"
gRubyCoinArrow_10_Under2Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
gRubyCoinArrow_10_2Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
gRubyCoinArrow_10_3Lit_Top_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p0.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p1.4bpp"
gRubyCoinArrow_1_1Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
gRubyCoinArrow_1_2PlusLit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p1.4bpp"
gRubyCoinArrow_5_0Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
gRubyCoinArrow_5_1Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
gRubyCoinArrow_5_2Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p1.4bpp"
gRubyCoinArrow_5_3Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p1.4bpp"
gRubyCoinArrow_10_Under2Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
gRubyCoinArrow_10_2Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
gRubyCoinArrow_10_3Lit_Mid_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p1.4bpp"
	.space 0x40
gRubyCoinArrow_1_0Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p2.4bpp"
gRubyCoinArrow_1_1Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p2.4bpp"
gRubyCoinArrow_1_2PlusLit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p2.4bpp"
gRubyCoinArrow_5_0Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p2.4bpp"
gRubyCoinArrow_5_1Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p2.4bpp"
gRubyCoinArrow_5_2Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p2.4bpp"
gRubyCoinArrow_5_3Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p2.4bpp"
gRubyCoinArrow_10_Under2Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
gRubyCoinArrow_10_2Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
gRubyCoinArrow_10_3Lit_Bot_Es::
	.incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p2.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Top_Es:: @ 0x083EA324
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_0_es.4bpp"
gRubyGetArrow_G_1Lit_Top_Es:: @ 0x083EA384
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_0_es.4bpp"
gRubyGetArrow_G_2PlusLit_Top_Es:: @ 0x083EA3E4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_0_es.4bpp"
	.space 0x20
gRubyGetArrow_E_0Lit_Top_Es:: @ 0x083EA464
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_0_es.4bpp"
	.space 0x20
gRubyGetArrow_E_1Lit_Top_Es:: @ 0x083EA4C4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_0_es.4bpp"
	.space 0x20
gRubyGetArrow_E_2Lit_Top_Es:: @ 0x083EA524
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_0_es.4bpp"
	.space 0x20
gRubyGetArrow_E_3Lit_Top_Es:: @ 0x083EA584
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_0_es.4bpp"
	.space 0x20
gRubyGetArrow_T_Under2Lit_Top_Es:: @ 0x083EA5E4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_0_es.4bpp"
	.space 0x20
gRubyGetArrow_T_2Lit_Top_Es:: @ 0x083EA644
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_0_es.4bpp"
	.space 0x20
gRubyGetArrow_T_3Lit_Top_Es:: @ 0x083EA6A4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_0_es.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Mid_Es:: @ 0x083EA724
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_1_es.4bpp"
gRubyGetArrow_G_1Lit_Mid_Es:: @ 0x083EA784
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_1_es.4bpp"
gRubyGetArrow_G_2PlusLit_Mid_Es:: @ 0x083EA7E4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_1_es.4bpp"
	.space 0x20
gRubyGetArrow_E_0Lit_Mid_Es:: @ 0x083EA864
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_1_es.4bpp"
	.space 0x20
gRubyGetArrow_E_1Lit_Mid_Es:: @ 0x083EA8C4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_1_es.4bpp"
	.space 0x20
gRubyGetArrow_E_2Lit_Mid_Es:: @ 0x083EA924
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_1_es.4bpp"
	.space 0x20
gRubyGetArrow_E_3Lit_Mid_Es:: @ 0x083EA984
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_1_es.4bpp"
gRubyGetArrow_T_Under2Lit_Mid_Es:: @ 0x083EA9C4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_1_es.4bpp"
gRubyGetArrow_T_2Lit_Mid_Es:: @ 0x083EAA24
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_1_es.4bpp"
gRubyGetArrow_T_3Lit_Mid_Es:: @ 0x083EAA84
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_1_es.4bpp"
	.space 0x40
gRubyGetArrow_G_0Lit_Bot_Es:: @ 0x083EAB24
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_2_es.4bpp"
gRubyGetArrow_G_1Lit_Bot_Es:: @ 0x083EAB84
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_2_es.4bpp"
gRubyGetArrow_G_2PlusLit_Bot_Es:: @ 0x083EABE4
	.incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_2_es.4bpp"
gRubyGetArrow_E_0Lit_Bot_Es:: @ 0x083EAC44
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_2_es.4bpp"
gRubyGetArrow_E_1Lit_Bot_Es:: @ 0x083EACA4
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_2_es.4bpp"
gRubyGetArrow_E_2Lit_Bot_Es:: @ 0x083EAD04
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_2_es.4bpp"
gRubyGetArrow_E_3Lit_Bot_Es:: @ 0x083EAD64
	.incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_2_es.4bpp"
gRubyGetArrow_T_Under2Lit_Bot_Es:: @ 0x083EADC4
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_2_es.4bpp"
gRubyGetArrow_T_2Lit_Bot_Es:: @ 0x083EAE24
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_2_es.4bpp"
gRubyGetArrow_T_3Lit_Bot_Es:: @ 0x083EAE84
	.incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_2_es.4bpp"
	.space 0x40
	.fill 0x20, 1, 0x22
gRubyBallPowerUpLight0off:: @ 0x083EAF44
	.incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_0_off.4bpp"

gRubyBallPowerUpLight0on:: @ 0x083EAF84
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_0_on.4bpp"

gRubyBallPowerUpLight1off:: @ 0x083EAFC4
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_1_off.4bpp"

gRubyBallPowerUpLight1on:: @ 0x083EB004
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_1_on.4bpp"

gRubyBallPowerUpLight2off:: @ 0x083EB044
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_2_off.4bpp"

gRubyBallPowerUpLight2on:: @ 0x083EB084
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_2_on.4bpp"


@ 'H' 'o' 'l' 'e' Lights

gRubyHoleLightH_Off:: @ 0x083EB0C4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_off.4bpp"

gRubyHoleLightH_On:: @ 0x083EB104
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_on.4bpp"

gRubyHoleLightO_Off:: @ 0x083EB144
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_off.4bpp"

gRubyHoleLightO_On:: @ 0x083EB184
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_on.4bpp"

gRubyHoleLightL_Off:: @ 0x083EB1C4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_off.4bpp"

gRubyHoleLightL_On:: @ 0x083EB204
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_on.4bpp"

gRubyHoleLightE_Off:: @ 0x083EB244
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_off.4bpp"

gRubyHoleLightE_On:: @ 0x083EB284
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_on.4bpp"



@ Catch light arrows : 3 balls / CATCH! / EVO

gRubyCatchLightState0Top:: @ 0x083EB2C4
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state0_top.4bpp"

gRubyCatchLightState1Top:: @ 0x083EB304
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state1_top.4bpp"
    .space 0x380

gRubyCatchLightState0Bot:: @ 0x083EB6C4
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state0_bot.4bpp"

gRubyCatchLightState1Bot:: @ 0x083EB704
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state1_bot.4bpp"

gRubyTrapIndicatorState0Top:: @ 0x083EB744
    .incbin "graphics/stage/ruby/trap_indicator/trap_state0_top.4bpp"

gRubyTrapIndicatorState1Top:: @ 0x083EB784
    .incbin "graphics/stage/ruby/trap_indicator/trap_state1_top.4bpp"

gRubyTrapIndicatorState2Top:: @ 0x083EB7C4
    .incbin "graphics/stage/ruby/trap_indicator/trap_state2_top.4bpp"



gRubyCatchLightSlot0State2Top:: @ 0x083EB804
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_top_eu.4bpp"
gRubyCatchLightSlot0State3Top:: @ 0x083EB844
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_top_eu.4bpp"
gRubyCatchLightSlot1State2Top:: @ 0x083EB884
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_top.4bpp"

gRubyCatchLightSlot1State3Top:: @ 0x083EB8C4
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_top.4bpp"

gRubyCatchLightSlot2State2Top:: @ 0x083EB904
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_top.4bpp"

gRubyCatchLightSlot2State3Top:: @ 0x083EB944
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_top.4bpp"

gRubyCatchLightSlot0State4Top:: @ 0x083EB984
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_top.4bpp"

gRubyCatchLightSlot0State5Top:: @ 0x083EB9C4
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_top.4bpp"

gRubyCatchLightSlot1State4Top:: @ 0x083EBA04
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_top.4bpp"

gRubyCatchLightSlot1State5Top:: @ 0x083EBA44
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_top.4bpp"

gRubyCatchLightSlot2State4Top:: @ 0x083EBA84
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_top.4bpp"

gRubyCatchLightSlot2State5Top:: @ 0x083EBAC4
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_top.4bpp"
	.space 0x40

gRubyTrapIndicatorState0Bot:: @ 0x083EBB44
    .incbin "graphics/stage/ruby/trap_indicator/trap_state0_bot.4bpp"

gRubyTrapIndicatorState1Bot:: @ 0x083EBB84
    .incbin "graphics/stage/ruby/trap_indicator/trap_state1_bot.4bpp"

gRubyTrapIndicatorState2Bot:: @ 0x083EBBC4
    .incbin "graphics/stage/ruby/trap_indicator/trap_state2_bot.4bpp"



gRubyCatchLightSlot0State2Bot:: @ 0x083EBC04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_bot_eu.4bpp"
gRubyCatchLightSlot0State3Bot:: @ 0x083EBC44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_bot_eu.4bpp"
gRubyCatchLightSlot1State2Bot:: @ 0x083EBC84
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_bot.4bpp"

gRubyCatchLightSlot1State3Bot:: @ 0x083EBCC4
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_bot.4bpp"

gRubyCatchLightSlot2State2Bot:: @ 0x083EBD04
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_bot.4bpp"

gRubyCatchLightSlot2State3Bot:: @ 0x083EBD44
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_bot.4bpp"

gRubyCatchLightSlot0State4Bot:: @ 0x083EBD84
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_bot.4bpp"

gRubyCatchLightSlot0State5Bot:: @ 0x083EBDC4
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_bot.4bpp"

gRubyCatchLightSlot1State4Bot:: @ 0x083EBE04
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_bot.4bpp"

gRubyCatchLightSlot1State5Bot:: @ 0x083EBE44
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_bot.4bpp"

gRubyCatchLightSlot2State4Bot:: @ 0x083EBE84
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_bot.4bpp"



@ Ruby Saver indicator

gRubyCatchLightSlot2State5Bot:: @ 0x083EBEC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_eu.4bpp"
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_filler_eu.4bpp"
gRubyHoleLightH_Off_Fr:: @ 0x083EC0E4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_off_fr.4bpp"
gRubyHoleLightH_On_Fr:: @ 0x083EC124
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_on_fr.4bpp"
gRubyHoleLightO_Off_Fr:: @ 0x083EC164
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_off_fr.4bpp"
gRubyHoleLightO_On_Fr:: @ 0x083EC1A4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_on_fr.4bpp"
gRubyHoleLightL_Off_Fr:: @ 0x083EC1E4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_off_fr.4bpp"
gRubyHoleLightL_On_Fr:: @ 0x083EC224
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_on_fr.4bpp"
gRubyHoleLightE_Off_Fr:: @ 0x083EC264
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_off_fr.4bpp"
gRubyHoleLightE_On_Fr:: @ 0x083EC2A4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_on_fr.4bpp"
gRubyCatchLightState0Top_Fr:: @ 0x083EC2E4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state0_top_fr.4bpp"
gRubyCatchLightState1Top_Fr:: @ 0x083EC324
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state1_top_fr.4bpp"
	.space 0x380
gRubyCatchLightState0Bot_Fr:: @ 0x083EC6E4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state0_bot_fr.4bpp"
gRubyCatchLightState1Bot_Fr:: @ 0x083EC724
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state1_bot_fr.4bpp"
gRubyTrapIndicatorState0Top_Fr::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state0_top_fr.4bpp"
gRubyTrapIndicatorState1Top_Fr::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state1_top_fr.4bpp"
gRubyTrapIndicatorState2Top_Fr::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state2_top_fr.4bpp"
gRubyCatchLightSlot0State2Top_Fr:: @ 0x083EC824
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_top_fr.4bpp"
gRubyCatchLightSlot0State3Top_Fr:: @ 0x083EC864
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_top_fr.4bpp"
gRubyCatchLightSlot1State2Top_Fr:: @ 0x083EC8A4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_top_fr.4bpp"
gRubyCatchLightSlot1State3Top_Fr:: @ 0x083EC8E4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_top_fr.4bpp"
gRubyCatchLightSlot2State2Top_Fr:: @ 0x083EC924
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_top_fr.4bpp"
gRubyCatchLightSlot2State3Top_Fr:: @ 0x083EC964
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_top_fr.4bpp"
gRubyCatchLightSlot0State4Top_Fr:: @ 0x083EC9A4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_top_fr.4bpp"
gRubyCatchLightSlot0State5Top_Fr:: @ 0x083EC9E4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_top_fr.4bpp"
gRubyCatchLightSlot1State4Top_Fr:: @ 0x083ECA24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_top_fr.4bpp"
gRubyCatchLightSlot1State5Top_Fr:: @ 0x083ECA64
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_top_fr.4bpp"
gRubyCatchLightSlot2State4Top_Fr:: @ 0x083ECAA4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_top_fr.4bpp"
gRubyCatchLightSlot2State5Top_Fr:: @ 0x083ECAE4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_top_fr.4bpp"
	.space 0x40
gRubyTrapIndicatorState0Bot_Fr::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state0_bot_fr.4bpp"
gRubyTrapIndicatorState1Bot_Fr::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state1_bot_fr.4bpp"
gRubyTrapIndicatorState2Bot_Fr::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state2_bot_fr.4bpp"
gRubyCatchLightSlot0State2Bot_Fr:: @ 0x083ECC24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_bot_fr.4bpp"
gRubyCatchLightSlot0State3Bot_Fr:: @ 0x083ECC64
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_bot_fr.4bpp"
gRubyCatchLightSlot1State2Bot_Fr:: @ 0x083ECCA4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_bot_fr.4bpp"
gRubyCatchLightSlot1State3Bot_Fr:: @ 0x083ECCE4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_bot_fr.4bpp"
gRubyCatchLightSlot2State2Bot_Fr:: @ 0x083ECD24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_bot_fr.4bpp"
gRubyCatchLightSlot2State3Bot_Fr:: @ 0x083ECD64
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_bot_fr.4bpp"
gRubyCatchLightSlot0State4Bot_Fr:: @ 0x083ECDA4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_bot_fr.4bpp"
gRubyCatchLightSlot0State5Bot_Fr:: @ 0x083ECDE4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_bot_fr.4bpp"
gRubyCatchLightSlot1State4Bot_Fr:: @ 0x083ECE24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_bot_fr.4bpp"
gRubyCatchLightSlot1State5Bot_Fr:: @ 0x083ECE64
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_bot_fr.4bpp"
gRubyCatchLightSlot2State4Bot_Fr:: @ 0x083ECEA4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_bot_fr.4bpp"
gRubyCatchLightSlot2State5Bot_Fr:: @ 0x083ECEE4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_fr.4bpp"
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_filler_fr.4bpp"
gRubyHoleLightH_Off_De:: @ 0x083ED104
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_off_de.4bpp"
gRubyHoleLightH_On_De:: @ 0x083ED144
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_on_de.4bpp"
gRubyHoleLightO_Off_De:: @ 0x083ED184
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_off_de.4bpp"
gRubyHoleLightO_On_De:: @ 0x083ED1C4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_on_de.4bpp"
gRubyHoleLightL_Off_De:: @ 0x083ED204
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_off_de.4bpp"
gRubyHoleLightL_On_De:: @ 0x083ED244
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_on_de.4bpp"
gRubyHoleLightE_Off_De:: @ 0x083ED284
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_off_de.4bpp"
gRubyHoleLightE_On_De:: @ 0x083ED2C4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_on_de.4bpp"
gRubyCatchLightState0Top_De:: @ 0x083ED304
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state0_top_de.4bpp"
gRubyCatchLightState1Top_De:: @ 0x083ED344
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state1_top_de.4bpp"
	.space 0x380
gRubyCatchLightState0Bot_De:: @ 0x083ED704
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state0_bot_de.4bpp"
gRubyCatchLightState1Bot_De:: @ 0x083ED744
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state1_bot_de.4bpp"
gRubyTrapIndicatorState0Top_De::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state0_top_de.4bpp"
gRubyTrapIndicatorState1Top_De::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state1_top_de.4bpp"
gRubyTrapIndicatorState2Top_De::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state2_top_de.4bpp"
gRubyCatchLightSlot0State2Top_De:: @ 0x083ED844
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_top_de.4bpp"
gRubyCatchLightSlot0State3Top_De:: @ 0x083ED884
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_top_de.4bpp"
gRubyCatchLightSlot1State2Top_De:: @ 0x083ED8C4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_top_de.4bpp"
gRubyCatchLightSlot1State3Top_De:: @ 0x083ED904
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_top_de.4bpp"
gRubyCatchLightSlot2State2Top_De:: @ 0x083ED944
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_top_de.4bpp"
gRubyCatchLightSlot2State3Top_De:: @ 0x083ED984
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_top_de.4bpp"
gRubyCatchLightSlot0State4Top_De:: @ 0x083ED9C4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_top_de.4bpp"
gRubyCatchLightSlot0State5Top_De:: @ 0x083EDA04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_top_de.4bpp"
gRubyCatchLightSlot1State4Top_De:: @ 0x083EDA44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_top_de.4bpp"
gRubyCatchLightSlot1State5Top_De:: @ 0x083EDA84
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_top_de.4bpp"
gRubyCatchLightSlot2State4Top_De:: @ 0x083EDAC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_top_de.4bpp"
gRubyCatchLightSlot2State5Top_De:: @ 0x083EDB04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_top_de.4bpp"
	.space 0x40
gRubyTrapIndicatorState0Bot_De::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state0_bot_de.4bpp"
gRubyTrapIndicatorState1Bot_De::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state1_bot_de.4bpp"
gRubyTrapIndicatorState2Bot_De::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state2_bot_de.4bpp"
gRubyCatchLightSlot0State2Bot_De:: @ 0x083EDC44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_bot_de.4bpp"
gRubyCatchLightSlot0State3Bot_De:: @ 0x083EDC84
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_bot_de.4bpp"
gRubyCatchLightSlot1State2Bot_De:: @ 0x083EDCC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_bot_de.4bpp"
gRubyCatchLightSlot1State3Bot_De:: @ 0x083EDD04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_bot_de.4bpp"
gRubyCatchLightSlot2State2Bot_De:: @ 0x083EDD44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_bot_de.4bpp"
gRubyCatchLightSlot2State3Bot_De:: @ 0x083EDD84
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_bot_de.4bpp"
gRubyCatchLightSlot0State4Bot_De:: @ 0x083EDDC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_bot_de.4bpp"
gRubyCatchLightSlot0State5Bot_De:: @ 0x083EDE04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_bot_de.4bpp"
gRubyCatchLightSlot1State4Bot_De:: @ 0x083EDE44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_bot_de.4bpp"
gRubyCatchLightSlot1State5Bot_De:: @ 0x083EDE84
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_bot_de.4bpp"
gRubyCatchLightSlot2State4Bot_De:: @ 0x083EDEC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_bot_de.4bpp"
gRubyCatchLightSlot2State5Bot_De:: @ 0x083EDF04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_de.4bpp"
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_filler_de.4bpp"
gRubyHoleLightH_Off_It:: @ 0x083EE124
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_off_it.4bpp"
gRubyHoleLightH_On_It:: @ 0x083EE164
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_on_it.4bpp"
gRubyHoleLightO_Off_It:: @ 0x083EE1A4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_off_it.4bpp"
gRubyHoleLightO_On_It:: @ 0x083EE1E4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_on_it.4bpp"
gRubyHoleLightL_Off_It:: @ 0x083EE224
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_off_it.4bpp"
gRubyHoleLightL_On_It:: @ 0x083EE264
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_on_it.4bpp"
gRubyHoleLightE_Off_It:: @ 0x083EE2A4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_off_it.4bpp"
gRubyHoleLightE_On_It:: @ 0x083EE2E4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_on_it.4bpp"
gRubyCatchLightState0Top_It:: @ 0x083EE324
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state0_top_it.4bpp"
gRubyCatchLightState1Top_It:: @ 0x083EE364
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state1_top_it.4bpp"
	.space 0x380
gRubyCatchLightState0Bot_It:: @ 0x083EE724
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state0_bot_it.4bpp"
gRubyCatchLightState1Bot_It:: @ 0x083EE764
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state1_bot_it.4bpp"
gRubyTrapIndicatorState0Top_It::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state0_top_it.4bpp"
gRubyTrapIndicatorState1Top_It::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state1_top_it.4bpp"
gRubyTrapIndicatorState2Top_It::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state2_top_it.4bpp"
gRubyCatchLightSlot0State2Top_It:: @ 0x083EE864
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_top_it.4bpp"
gRubyCatchLightSlot0State3Top_It:: @ 0x083EE8A4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_top_it.4bpp"
gRubyCatchLightSlot1State2Top_It:: @ 0x083EE8E4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_top_it.4bpp"
gRubyCatchLightSlot1State3Top_It:: @ 0x083EE924
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_top_it.4bpp"
gRubyCatchLightSlot2State2Top_It:: @ 0x083EE964
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_top_it.4bpp"
gRubyCatchLightSlot2State3Top_It:: @ 0x083EE9A4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_top_it.4bpp"
gRubyCatchLightSlot0State4Top_It:: @ 0x083EE9E4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_top_it.4bpp"
gRubyCatchLightSlot0State5Top_It:: @ 0x083EEA24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_top_it.4bpp"
gRubyCatchLightSlot1State4Top_It:: @ 0x083EEA64
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_top_it.4bpp"
gRubyCatchLightSlot1State5Top_It:: @ 0x083EEAA4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_top_it.4bpp"
gRubyCatchLightSlot2State4Top_It:: @ 0x083EEAE4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_top_it.4bpp"
gRubyCatchLightSlot2State5Top_It:: @ 0x083EEB24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_top_it.4bpp"
	.space 0x40
gRubyTrapIndicatorState0Bot_It::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state0_bot_it.4bpp"
gRubyTrapIndicatorState1Bot_It::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state1_bot_it.4bpp"
gRubyTrapIndicatorState2Bot_It::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state2_bot_it.4bpp"
gRubyCatchLightSlot0State2Bot_It:: @ 0x083EEC64
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_bot_it.4bpp"
gRubyCatchLightSlot0State3Bot_It:: @ 0x083EECA4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_bot_it.4bpp"
gRubyCatchLightSlot1State2Bot_It:: @ 0x083EECE4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_bot_it.4bpp"
gRubyCatchLightSlot1State3Bot_It:: @ 0x083EED24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_bot_it.4bpp"
gRubyCatchLightSlot2State2Bot_It:: @ 0x083EED64
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_bot_it.4bpp"
gRubyCatchLightSlot2State3Bot_It:: @ 0x083EEDA4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_bot_it.4bpp"
gRubyCatchLightSlot0State4Bot_It:: @ 0x083EEDE4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_bot_it.4bpp"
gRubyCatchLightSlot0State5Bot_It:: @ 0x083EEE24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_bot_it.4bpp"
gRubyCatchLightSlot1State4Bot_It:: @ 0x083EEE64
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_bot_it.4bpp"
gRubyCatchLightSlot1State5Bot_It:: @ 0x083EEEA4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_bot_it.4bpp"
gRubyCatchLightSlot2State4Bot_It:: @ 0x083EEEE4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_bot_it.4bpp"
gRubyCatchLightSlot2State5Bot_It:: @ 0x083EEF24
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_it.4bpp"
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_filler_it.4bpp"
gRubyHoleLightH_Off_Es:: @ 0x083EF144
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_off_es.4bpp"
gRubyHoleLightH_On_Es:: @ 0x083EF184
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_on_es.4bpp"
gRubyHoleLightO_Off_Es:: @ 0x083EF1C4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_off_es.4bpp"
gRubyHoleLightO_On_Es:: @ 0x083EF204
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_on_es.4bpp"
gRubyHoleLightL_Off_Es:: @ 0x083EF244
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_off_es.4bpp"
gRubyHoleLightL_On_Es:: @ 0x083EF284
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_on_es.4bpp"
gRubyHoleLightE_Off_Es:: @ 0x083EF2C4
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_off_es.4bpp"
gRubyHoleLightE_On_Es:: @ 0x083EF304
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_on_es.4bpp"
gRubyCatchLightState0Top_Es:: @ 0x083EF344
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state0_top_es.4bpp"
gRubyCatchLightState1Top_Es:: @ 0x083EF384
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state1_top_es.4bpp"
	.space 0x380
gRubyCatchLightState0Bot_Es:: @ 0x083EF744
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state0_bot_es.4bpp"
gRubyCatchLightState1Bot_Es:: @ 0x083EF784
	.incbin "graphics/stage/ruby/catch_lights/catch_light_state1_bot_es.4bpp"
gRubyTrapIndicatorState0Top_Es::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state0_top_es.4bpp"
gRubyTrapIndicatorState1Top_Es::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state1_top_es.4bpp"
gRubyTrapIndicatorState2Top_Es::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state2_top_es.4bpp"
gRubyCatchLightSlot0State2Top_Es:: @ 0x083EF884
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_top_es.4bpp"
gRubyCatchLightSlot0State3Top_Es:: @ 0x083EF8C4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_top_es.4bpp"
gRubyCatchLightSlot1State2Top_Es:: @ 0x083EF904
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_top_es.4bpp"
gRubyCatchLightSlot1State3Top_Es:: @ 0x083EF944
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_top_es.4bpp"
gRubyCatchLightSlot2State2Top_Es:: @ 0x083EF984
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_top_es.4bpp"
gRubyCatchLightSlot2State3Top_Es:: @ 0x083EF9C4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_top_es.4bpp"
gRubyCatchLightSlot0State4Top_Es:: @ 0x083EFA04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_top_es.4bpp"
gRubyCatchLightSlot0State5Top_Es:: @ 0x083EFA44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_top_es.4bpp"
gRubyCatchLightSlot1State4Top_Es:: @ 0x083EFA84
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_top_es.4bpp"
gRubyCatchLightSlot1State5Top_Es:: @ 0x083EFAC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_top_es.4bpp"
gRubyCatchLightSlot2State4Top_Es:: @ 0x083EFB04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_top_es.4bpp"
gRubyCatchLightSlot2State5Top_Es:: @ 0x083EFB44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_top_es.4bpp"
	.space 0x40
gRubyTrapIndicatorState0Bot_Es::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state0_bot_es.4bpp"
gRubyTrapIndicatorState1Bot_Es::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state1_bot_es.4bpp"
gRubyTrapIndicatorState2Bot_Es::
	.incbin "graphics/stage/ruby/trap_indicator/trap_state2_bot_es.4bpp"
gRubyCatchLightSlot0State2Bot_Es:: @ 0x083EFC84
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state2_bot_es.4bpp"
gRubyCatchLightSlot0State3Bot_Es:: @ 0x083EFCC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state3_bot_es.4bpp"
gRubyCatchLightSlot1State2Bot_Es:: @ 0x083EFD04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_bot_es.4bpp"
gRubyCatchLightSlot1State3Bot_Es:: @ 0x083EFD44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_bot_es.4bpp"
gRubyCatchLightSlot2State2Bot_Es:: @ 0x083EFD84
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_bot_es.4bpp"
gRubyCatchLightSlot2State3Bot_Es:: @ 0x083EFDC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_bot_es.4bpp"
gRubyCatchLightSlot0State4Bot_Es:: @ 0x083EFE04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_bot_es.4bpp"
gRubyCatchLightSlot0State5Bot_Es:: @ 0x083EFE44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_bot_es.4bpp"
gRubyCatchLightSlot1State4Bot_Es:: @ 0x083EFE84
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_bot_es.4bpp"
gRubyCatchLightSlot1State5Bot_Es:: @ 0x083EFEC4
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_bot_es.4bpp"
gRubyCatchLightSlot2State4Bot_Es:: @ 0x083EFF04
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_bot_es.4bpp"
gRubyCatchLightSlot2State5Bot_Es:: @ 0x083EFF44
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_es.4bpp"
	.incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_bot_filler_es.4bpp"
gRubySaverRow0Tile_Off:: @ 0x083F0004
    .incbin "graphics/stage/ruby/saver/saver_off_row0.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row0_filler.4bpp"

gRubySaverRow0Tile_On:: @ 0x083F0104
    .incbin "graphics/stage/ruby/saver/saver_on_row0.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_on_row0_filler.4bpp"

gRubySaverRow1Tile_Off:: @ 0x083F0404
    .incbin "graphics/stage/ruby/saver/saver_off_row1.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row1_filler.4bpp"

gRubySaverRow1Tile_On:: @ 0x083F0504
    .incbin "graphics/stage/ruby/saver/saver_on_row1.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_on_row1_filler.4bpp"

gRubySaverRow2Tile_Off:: @ 0x083F0824
    .incbin "graphics/stage/ruby/saver/saver_off_row2.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row2_filler.4bpp"

gRubySaverRow2Tile_On:: @ 0x083F0924
    .incbin "graphics/stage/ruby/saver/saver_on_row2.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x200
	.fill 0xA0, 1, 0x11

gRubySaverRow3Tile_Off:: @ 0x083F0C84
    .incbin "graphics/stage/ruby/saver/saver_off_row3.4bpp"
	.fill 0xC0, 1, 0x11


gRubySaverRow3Tile_On:: @ 0x083F0D84
	.incbin "graphics/stage/ruby/saver/saver_on_row3_eu.4bpp"
gRubySaverRow0Tile_Off_Fr:: @ 0x083F1024
	.incbin "graphics/stage/ruby/saver/saver_off_row0_fr.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row0_filler_fr.4bpp"
gRubySaverRow0Tile_On_Fr:: @ 0x083F1124
	.incbin "graphics/stage/ruby/saver/saver_on_row0_fr.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_on_row0_filler_fr.4bpp"
gRubySaverRow1Tile_Off_Fr:: @ 0x083F1424
	.incbin "graphics/stage/ruby/saver/saver_off_row1_fr.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row1_filler_fr.4bpp"
gRubySaverRow1Tile_On_Fr:: @ 0x083F1524
	.incbin "graphics/stage/ruby/saver/saver_on_row1_fr.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_on_row1_filler_fr.4bpp"
gRubySaverRow2Tile_Off_Fr:: @ 0x083F1824
	.incbin "graphics/stage/ruby/saver/saver_off_row2_fr.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row2_filler_fr.4bpp"
gRubySaverRow2Tile_On_Fr:: @ 0x083F1924
	.incbin "graphics/stage/ruby/saver/saver_on_row2_fr.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x200
	.fill 0xA0, 1, 0x11
gRubySaverRow3Tile_Off_Fr:: @ 0x083F1CA4
	.incbin "graphics/stage/ruby/saver/saver_off_row3_fr.4bpp"
	.fill 0xC0, 1, 0x11
gRubySaverRow3Tile_On_Fr:: @ 0x083F1DA4
	.incbin "graphics/stage/ruby/saver/saver_on_row3_fr.4bpp"
gRubySaverRow0Tile_Off_It:: @ 0x083F2044
	.incbin "graphics/stage/ruby/saver/saver_off_row0_it.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row0_filler_it.4bpp"
gRubySaverRow0Tile_On_It:: @ 0x083F2144
	.incbin "graphics/stage/ruby/saver/saver_on_row0_it.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_on_row0_filler_it.4bpp"
gRubySaverRow1Tile_Off_It:: @ 0x083F2444
	.incbin "graphics/stage/ruby/saver/saver_off_row1_it.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row1_filler_it.4bpp"
gRubySaverRow1Tile_On_It:: @ 0x083F2544
	.incbin "graphics/stage/ruby/saver/saver_on_row1_it.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_on_row1_filler_it.4bpp"
gRubySaverRow2Tile_Off_It:: @ 0x083F2844
	.incbin "graphics/stage/ruby/saver/saver_off_row2_it.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row2_filler_it.4bpp"
gRubySaverRow2Tile_On_It:: @ 0x083F2944
	.incbin "graphics/stage/ruby/saver/saver_on_row2_it.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x200
	.fill 0xA0, 1, 0x11
gRubySaverRow3Tile_Off_It:: @ 0x083F2CC4
	.incbin "graphics/stage/ruby/saver/saver_off_row3_it.4bpp"
	.fill 0xC0, 1, 0x11
gRubySaverRow3Tile_On_It:: @ 0x083F2DC4
	.incbin "graphics/stage/ruby/saver/saver_on_row3_it.4bpp"
gRubySaverRow0Tile_Off_Es:: @ 0x083F3064
	.incbin "graphics/stage/ruby/saver/saver_off_row0_es.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row0_filler_es.4bpp"
gRubySaverRow0Tile_On_Es:: @ 0x083F3164
	.incbin "graphics/stage/ruby/saver/saver_on_row0_es.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_on_row0_filler_es.4bpp"
gRubySaverRow1Tile_Off_Es:: @ 0x083F3464
	.incbin "graphics/stage/ruby/saver/saver_off_row1_es.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row1_filler_es.4bpp"
gRubySaverRow1Tile_On_Es:: @ 0x083F3564
	.incbin "graphics/stage/ruby/saver/saver_on_row1_es.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_on_row1_filler_es.4bpp"
gRubySaverRow2Tile_Off_Es:: @ 0x083F3864
	.incbin "graphics/stage/ruby/saver/saver_off_row2_es.4bpp"
	.incbin "graphics/stage/ruby/saver/saver_off_row2_filler_es.4bpp"
gRubySaverRow2Tile_On_Es:: @ 0x083F3964
	.incbin "graphics/stage/ruby/saver/saver_on_row2_es.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x200
	.fill 0xA0, 1, 0x11
gRubySaverRow3Tile_Off_Es:: @ 0x083F3CE4
	.incbin "graphics/stage/ruby/saver/saver_off_row3_es.4bpp"
	.fill 0xC0, 1, 0x11
gRubySaverRow3Tile_On_Es:: @ 0x083F3DE4
	.incbin "graphics/stage/ruby/saver/saver_on_row3_es.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x220
gRubyHatchArrowRow0Tile_Off:: @ 0x083F4064
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row0.4bpp"

gRubyHatchArrowRow0Tile_On:: @ 0x083F40E4
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0.4bpp"
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_filler.4bpp"

gRubyCatchArrowRow0Tile_Off:: @ 0x083F41A4
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0.4bpp"
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_filler.4bpp"

gRubyCatchArrowRow0Tile_On:: @ 0x083F4224
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0.4bpp"
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_filler.4bpp"

gRubyBumperArrowRow0Tile_Off:: @ 0x083F42A4
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_filler.4bpp"

gRubyBumperArrowRow0Tile_On:: @ 0x083F4324
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row0.4bpp"
    .space 0x100

gRubyHatchArrowRow1Tile_Off:: @ 0x083F4464
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row1.4bpp"

gRubyHatchArrowRow1Tile_On:: @ 0x083F44E4
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row1.4bpp"

gRubyCatchArrowRow1Tile_Off:: @ 0x083F4564
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row1.4bpp"

gRubyCatchArrowRow1Tile_On:: @ 0x083F45E4
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row1.4bpp"

gRubyBumperArrowRow1Tile_Off:: @ 0x083F4664
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row1.4bpp"

gRubyBumperArrowRow1Tile_On:: @ 0x083F46E4
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row1.4bpp"
    .space 0x100

gRubyHatchArrowRow2Tile_Off:: @ 0x083F4864
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row2.4bpp"

gRubyHatchArrowRow2Tile_On:: @ 0x083F48E4
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row2.4bpp"

gRubyCatchArrowRow2Tile_Off:: @ 0x083F4964
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row2.4bpp"

gRubyCatchArrowRow2Tile_On:: @ 0x083F49E4
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row2.4bpp"

gRubyBumperArrowRow2Tile_Off:: @ 0x083F4A64
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row2.4bpp"

gRubyBumperArrowRow2Tile_On:: @ 0x083F4AE4
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row2.4bpp"
    .space 0x100

gRubyHatchArrowRow3Tile_Off:: @ 0x083F4C64
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row3.4bpp"

gRubyHatchArrowRow3Tile_On:: @ 0x083F4CE4
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row3.4bpp"

gRubyCatchArrowRow3Tile_Off:: @ 0x083F4D64
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row3.4bpp"

gRubyCatchArrowRow3Tile_On:: @ 0x083F4DE4
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row3.4bpp"

gRubyBumperArrowRow3Tile_Off:: @ 0x083F4E64
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_filler.4bpp"

gRubyBumperArrowRow3Tile_On:: @ 0x083F4EE4
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_filler.4bpp"


@ Sign for bonus multiplier left/right digits

gRubyHatchArrowRow0Tile_Off_Fr:: @ 0x083F5084
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row0_fr.4bpp"
gRubyHatchArrowRow0Tile_On_Fr:: @ 0x083F5104
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_fr.4bpp"
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_filler_fr.4bpp"
gRubyCatchArrowRow0Tile_Off_Fr:: @ 0x083F51C4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_fr.4bpp"
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_filler_fr.4bpp"
gRubyCatchArrowRow0Tile_On_Fr:: @ 0x083F5244
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_fr.4bpp"
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_filler_fr.4bpp"
gRubyBumperArrowRow0Tile_Off_Fr:: @ 0x083F52C4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_fr.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_filler_fr.4bpp"
gRubyBumperArrowRow0Tile_On_Fr:: @ 0x083F5344
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row0_fr.4bpp"
	.space 0x100
gRubyHatchArrowRow1Tile_Off_Fr:: @ 0x083F5484
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row1_fr.4bpp"
gRubyHatchArrowRow1Tile_On_Fr:: @ 0x083F5504
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row1_fr.4bpp"
gRubyCatchArrowRow1Tile_Off_Fr:: @ 0x083F5584
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row1_fr.4bpp"
gRubyCatchArrowRow1Tile_On_Fr:: @ 0x083F5604
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row1_fr.4bpp"
gRubyBumperArrowRow1Tile_Off_Fr:: @ 0x083F5684
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row1_fr.4bpp"
gRubyBumperArrowRow1Tile_On_Fr:: @ 0x083F5704
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row1_fr.4bpp"
	.space 0x100
gRubyHatchArrowRow2Tile_Off_Fr:: @ 0x083F5884
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row2_fr.4bpp"
gRubyHatchArrowRow2Tile_On_Fr:: @ 0x083F5904
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row2_fr.4bpp"
gRubyCatchArrowRow2Tile_Off_Fr:: @ 0x083F5984
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row2_fr.4bpp"
gRubyCatchArrowRow2Tile_On_Fr:: @ 0x083F5A04
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row2_fr.4bpp"
gRubyBumperArrowRow2Tile_Off_Fr:: @ 0x083F5A84
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row2_fr.4bpp"
gRubyBumperArrowRow2Tile_On_Fr:: @ 0x083F5B04
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row2_fr.4bpp"
	.space 0x100
gRubyHatchArrowRow3Tile_Off_Fr:: @ 0x083F5C84
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row3_fr.4bpp"
gRubyHatchArrowRow3Tile_On_Fr:: @ 0x083F5D04
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row3_fr.4bpp"
gRubyCatchArrowRow3Tile_Off_Fr:: @ 0x083F5D84
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row3_fr.4bpp"
gRubyCatchArrowRow3Tile_On_Fr:: @ 0x083F5E04
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row3_fr.4bpp"
gRubyBumperArrowRow3Tile_Off_Fr:: @ 0x083F5E84
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_fr.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_filler_fr.4bpp"
gRubyBumperArrowRow3Tile_On_Fr:: @ 0x083F5F04
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_fr.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_filler_fr.4bpp"
gRubyHatchArrowRow0Tile_Off_De:: @ 0x083F60A4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row0_de.4bpp"
gRubyHatchArrowRow0Tile_On_De:: @ 0x083F6124
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_de.4bpp"
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_filler_de.4bpp"
gRubyCatchArrowRow0Tile_Off_De:: @ 0x083F61E4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_de.4bpp"
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_filler_de.4bpp"
gRubyCatchArrowRow0Tile_On_De:: @ 0x083F6264
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_de.4bpp"
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_filler_de.4bpp"
gRubyBumperArrowRow0Tile_Off_De:: @ 0x083F62E4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_de.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_filler_de.4bpp"
gRubyBumperArrowRow0Tile_On_De:: @ 0x083F6364
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row0_de.4bpp"
	.space 0x100
gRubyHatchArrowRow1Tile_Off_De:: @ 0x083F64A4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row1_de.4bpp"
gRubyHatchArrowRow1Tile_On_De:: @ 0x083F6524
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row1_de.4bpp"
gRubyCatchArrowRow1Tile_Off_De:: @ 0x083F65A4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row1_de.4bpp"
gRubyCatchArrowRow1Tile_On_De:: @ 0x083F6624
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row1_de.4bpp"
gRubyBumperArrowRow1Tile_Off_De:: @ 0x083F66A4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row1_de.4bpp"
gRubyBumperArrowRow1Tile_On_De:: @ 0x083F6724
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row1_de.4bpp"
	.space 0x100
gRubyHatchArrowRow2Tile_Off_De:: @ 0x083F68A4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row2_de.4bpp"
gRubyHatchArrowRow2Tile_On_De:: @ 0x083F6924
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row2_de.4bpp"
gRubyCatchArrowRow2Tile_Off_De:: @ 0x083F69A4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row2_de.4bpp"
gRubyCatchArrowRow2Tile_On_De:: @ 0x083F6A24
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row2_de.4bpp"
gRubyBumperArrowRow2Tile_Off_De:: @ 0x083F6AA4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row2_de.4bpp"
gRubyBumperArrowRow2Tile_On_De:: @ 0x083F6B24
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row2_de.4bpp"
	.space 0x100
gRubyHatchArrowRow3Tile_Off_De:: @ 0x083F6CA4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row3_de.4bpp"
gRubyHatchArrowRow3Tile_On_De:: @ 0x083F6D24
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row3_de.4bpp"
gRubyCatchArrowRow3Tile_Off_De:: @ 0x083F6DA4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row3_de.4bpp"
gRubyCatchArrowRow3Tile_On_De:: @ 0x083F6E24
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row3_de.4bpp"
gRubyBumperArrowRow3Tile_Off_De:: @ 0x083F6EA4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_de.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_filler_de.4bpp"
gRubyBumperArrowRow3Tile_On_De:: @ 0x083F6F24
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_de.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_filler_de.4bpp"
gRubyHatchArrowRow0Tile_Off_It:: @ 0x083F70C4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row0_it.4bpp"
gRubyHatchArrowRow0Tile_On_It:: @ 0x083F7144
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_it.4bpp"
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_filler_it.4bpp"
gRubyCatchArrowRow0Tile_Off_It:: @ 0x083F7204
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_it.4bpp"
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_filler_it.4bpp"
gRubyCatchArrowRow0Tile_On_It:: @ 0x083F7284
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_it.4bpp"
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_filler_it.4bpp"
gRubyBumperArrowRow0Tile_Off_It:: @ 0x083F7304
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_it.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_filler_it.4bpp"
gRubyBumperArrowRow0Tile_On_It:: @ 0x083F7384
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row0_it.4bpp"
	.space 0x100
gRubyHatchArrowRow1Tile_Off_It:: @ 0x083F74C4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row1_it.4bpp"
gRubyHatchArrowRow1Tile_On_It:: @ 0x083F7544
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row1_it.4bpp"
gRubyCatchArrowRow1Tile_Off_It:: @ 0x083F75C4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row1_it.4bpp"
gRubyCatchArrowRow1Tile_On_It:: @ 0x083F7644
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row1_it.4bpp"
gRubyBumperArrowRow1Tile_Off_It:: @ 0x083F76C4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row1_it.4bpp"
gRubyBumperArrowRow1Tile_On_It:: @ 0x083F7744
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row1_it.4bpp"
	.space 0x100
gRubyHatchArrowRow2Tile_Off_It:: @ 0x083F78C4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row2_it.4bpp"
gRubyHatchArrowRow2Tile_On_It:: @ 0x083F7944
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row2_it.4bpp"
gRubyCatchArrowRow2Tile_Off_It:: @ 0x083F79C4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row2_it.4bpp"
gRubyCatchArrowRow2Tile_On_It:: @ 0x083F7A44
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row2_it.4bpp"
gRubyBumperArrowRow2Tile_Off_It:: @ 0x083F7AC4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row2_it.4bpp"
gRubyBumperArrowRow2Tile_On_It:: @ 0x083F7B44
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row2_it.4bpp"
	.space 0x100
gRubyHatchArrowRow3Tile_Off_It:: @ 0x083F7CC4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row3_it.4bpp"
gRubyHatchArrowRow3Tile_On_It:: @ 0x083F7D44
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row3_it.4bpp"
gRubyCatchArrowRow3Tile_Off_It:: @ 0x083F7DC4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row3_it.4bpp"
gRubyCatchArrowRow3Tile_On_It:: @ 0x083F7E44
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row3_it.4bpp"
gRubyBumperArrowRow3Tile_Off_It:: @ 0x083F7EC4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_it.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_filler_it.4bpp"
gRubyBumperArrowRow3Tile_On_It:: @ 0x083F7F44
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_it.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_filler_it.4bpp"
gRubyHatchArrowRow0Tile_Off_Es:: @ 0x083F80E4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row0_es.4bpp"
gRubyHatchArrowRow0Tile_On_Es:: @ 0x083F8164
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_es.4bpp"
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_filler_es.4bpp"
gRubyCatchArrowRow0Tile_Off_Es:: @ 0x083F8224
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_es.4bpp"
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_filler_es.4bpp"
gRubyCatchArrowRow0Tile_On_Es:: @ 0x083F82A4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_es.4bpp"
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_filler_es.4bpp"
gRubyBumperArrowRow0Tile_Off_Es:: @ 0x083F8324
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_es.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_filler_es.4bpp"
gRubyBumperArrowRow0Tile_On_Es:: @ 0x083F83A4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row0_es.4bpp"
	.space 0x100
gRubyHatchArrowRow1Tile_Off_Es:: @ 0x083F84E4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row1_es.4bpp"
gRubyHatchArrowRow1Tile_On_Es:: @ 0x083F8564
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row1_es.4bpp"
gRubyCatchArrowRow1Tile_Off_Es:: @ 0x083F85E4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row1_es.4bpp"
gRubyCatchArrowRow1Tile_On_Es:: @ 0x083F8664
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row1_es.4bpp"
gRubyBumperArrowRow1Tile_Off_Es:: @ 0x083F86E4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row1_es.4bpp"
gRubyBumperArrowRow1Tile_On_Es:: @ 0x083F8764
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row1_es.4bpp"
	.space 0x100
gRubyHatchArrowRow2Tile_Off_Es:: @ 0x083F88E4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row2_es.4bpp"
gRubyHatchArrowRow2Tile_On_Es:: @ 0x083F8964
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row2_es.4bpp"
gRubyCatchArrowRow2Tile_Off_Es:: @ 0x083F89E4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row2_es.4bpp"
gRubyCatchArrowRow2Tile_On_Es:: @ 0x083F8A64
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row2_es.4bpp"
gRubyBumperArrowRow2Tile_Off_Es:: @ 0x083F8AE4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row2_es.4bpp"
gRubyBumperArrowRow2Tile_On_Es:: @ 0x083F8B64
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row2_es.4bpp"
	.space 0x100
gRubyHatchArrowRow3Tile_Off_Es:: @ 0x083F8CE4
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row3_es.4bpp"
gRubyHatchArrowRow3Tile_On_Es:: @ 0x083F8D64
	.incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row3_es.4bpp"
gRubyCatchArrowRow3Tile_Off_Es:: @ 0x083F8DE4
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row3_es.4bpp"
gRubyCatchArrowRow3Tile_On_Es:: @ 0x083F8E64
	.incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row3_es.4bpp"
gRubyBumperArrowRow3Tile_Off_Es:: @ 0x083F8EE4
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_es.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_filler_es.4bpp"
gRubyBumperArrowRow3Tile_On_Es:: @ 0x083F8F64
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_es.4bpp"
	.incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_filler_es.4bpp"
gRubyProgressDigit0_Tens:: @ 0x083F9104
    .incbin "graphics/stage/ruby/progress_digits/digit0_tens.4bpp"

gRubyProgressDigit1_Tens:: @ 0x083F9124
    .incbin "graphics/stage/ruby/progress_digits/digit1_tens.4bpp"

gRubyProgressDigit2_Tens:: @ 0x083F9144
    .incbin "graphics/stage/ruby/progress_digits/digit2_tens.4bpp"

gRubyProgressDigit3_Tens:: @ 0x083F9164
    .incbin "graphics/stage/ruby/progress_digits/digit3_tens.4bpp"

gRubyProgressDigit4_Tens:: @ 0x083F9184
    .incbin "graphics/stage/ruby/progress_digits/digit4_tens.4bpp"

gRubyProgressDigit5_Tens:: @ 0x083F91A4
    .incbin "graphics/stage/ruby/progress_digits/digit5_tens.4bpp"

gRubyProgressDigit6_Tens:: @ 0x083F91C4
    .incbin "graphics/stage/ruby/progress_digits/digit6_tens.4bpp"

gRubyProgressDigit7_Tens:: @ 0x083F91E4
    .incbin "graphics/stage/ruby/progress_digits/digit7_tens.4bpp"

gRubyProgressDigit8_Tens:: @ 0x083F9204
    .incbin "graphics/stage/ruby/progress_digits/digit8_tens.4bpp"

gRubyProgressDigit9_Tens:: @ 0x083F9224
    .incbin "graphics/stage/ruby/progress_digits/digit9_tens.4bpp"

gRubyProgressDigit0_Ones:: @ 0x083F9244
    .incbin "graphics/stage/ruby/progress_digits/digit0_ones.4bpp"

gRubyProgressDigit1_Ones:: @ 0x083F9264
    .incbin "graphics/stage/ruby/progress_digits/digit1_ones.4bpp"

gRubyProgressDigit2_Ones:: @ 0x083F9284
    .incbin "graphics/stage/ruby/progress_digits/digit2_ones.4bpp"

gRubyProgressDigit3_Ones:: @ 0x083F92A4
    .incbin "graphics/stage/ruby/progress_digits/digit3_ones.4bpp"

gRubyProgressDigit4_Ones:: @ 0x083F92C4
    .incbin "graphics/stage/ruby/progress_digits/digit4_ones.4bpp"

gRubyProgressDigit5_Ones:: @ 0x083F92E4
    .incbin "graphics/stage/ruby/progress_digits/digit5_ones.4bpp"

gRubyProgressDigit6_Ones:: @ 0x083F9304
    .incbin "graphics/stage/ruby/progress_digits/digit6_ones.4bpp"

gRubyProgressDigit7_Ones:: @ 0x083F9324
    .incbin "graphics/stage/ruby/progress_digits/digit7_ones.4bpp"

gRubyProgressDigit8_Ones:: @ 0x083F9344
    .incbin "graphics/stage/ruby/progress_digits/digit8_ones.4bpp"

gRubyProgressDigit9_Ones:: @ 0x083F9364
    .incbin "graphics/stage/ruby/progress_digits/digit9_ones.4bpp"

.space 0x1A0


@ Text for sign over Ruby shop entrance

gRubyShopSignMartLabel_En:: @ 0x083F9524
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_label_en.4bpp"
gRubyShopSignMartPiece0:: @ 0x083F95E4
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece0.4bpp"








@ arrow for ramp leading to shop: mart/evo

gRubyShopSignMartPiece1:: @ 0x083F96A4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece1_eu.4bpp"
gRubyShopSignMartPiece2_En:: @ 0x083F97A4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece2_en.4bpp"
	.space 0xA0
gRubyShopSignEvoLabel_En:: @ 0x083F9924
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_evo_label_en.4bpp"
gRubyShopSignCenterPiece0_En:: @ 0x083F99E4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece0_en.4bpp"
gRubyShopSignCenterPiece1_En:: @ 0x083F9AA4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece1_en.4bpp"
gRubyShopSignCenterPiece2_En:: @ 0x083F9BA4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece2_en.4bpp"
gRubyShopSignMartLabel_Fr:: @ 0x083F9D44
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_label_fr.4bpp"
gRubyShopSignMartPiece0_Fr:: @ 0x083F9E04
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece0_fr.4bpp"
gRubyShopSignMartPiece1_Fr:: @ 0x083F9EC4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece1_fr.4bpp"
gRubyShopSignMartPiece2_Fr:: @ 0x083F9FC4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece2_fr.4bpp"
	.space 0xA0
gRubyShopSignEvoLabel_Fr:: @ 0x083FA144
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_evo_label_fr.4bpp"
gRubyShopSignCenterPiece0_Fr:: @ 0x083FA204
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece0_fr.4bpp"
gRubyShopSignCenterPiece1_Fr:: @ 0x083FA2C4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece1_fr.4bpp"
gRubyShopSignCenterPiece2_Fr:: @ 0x083FA3C4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece2_fr.4bpp"
gRubyShopSignMartLabel_De:: @ 0x083FA564
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_label_de.4bpp"
gRubyShopSignMartPiece0_De:: @ 0x083FA624
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece0_de.4bpp"
gRubyShopSignMartPiece1_De:: @ 0x083FA6E4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece1_de.4bpp"
gRubyShopSignMartPiece2_De:: @ 0x083FA7E4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece2_de.4bpp"
	.space 0xA0
gRubyShopSignEvoLabel_De:: @ 0x083FA964
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_evo_label_de.4bpp"
gRubyShopSignCenterPiece0_De:: @ 0x083FAA24
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece0_de.4bpp"
gRubyShopSignCenterPiece1_De:: @ 0x083FAAE4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece1_de.4bpp"
gRubyShopSignCenterPiece2_De:: @ 0x083FABE4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece2_de.4bpp"
gRubyShopSignMartLabel_It:: @ 0x083FAD84
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_label_it.4bpp"
gRubyShopSignMartPiece0_It:: @ 0x083FAE44
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece0_it.4bpp"
gRubyShopSignMartPiece1_It:: @ 0x083FAF04
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece1_it.4bpp"
gRubyShopSignMartPiece2_It:: @ 0x083FB004
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece2_it.4bpp"
	.space 0xA0
gRubyShopSignEvoLabel_It:: @ 0x083FB184
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_evo_label_it.4bpp"
gRubyShopSignCenterPiece0_It:: @ 0x083FB244
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece0_it.4bpp"
gRubyShopSignCenterPiece1_It:: @ 0x083FB304
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece1_it.4bpp"
gRubyShopSignCenterPiece2_It:: @ 0x083FB404
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece2_it.4bpp"
gRubyShopSignMartLabel_Es:: @ 0x083FB5A4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_label_es.4bpp"
gRubyShopSignMartPiece0_Es:: @ 0x083FB664
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece0_es.4bpp"
gRubyShopSignMartPiece1_Es:: @ 0x083FB724
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece1_es.4bpp"
gRubyShopSignMartPiece2_Es:: @ 0x083FB824
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece2_es.4bpp"
	.space 0xA0
gRubyShopSignEvoLabel_Es:: @ 0x083FB9A4
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_evo_label_es.4bpp"
gRubyShopSignCenterPiece0_Es:: @ 0x083FBA64
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece0_es.4bpp"
gRubyShopSignCenterPiece1_Es:: @ 0x083FBB24
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece1_es.4bpp"
gRubyShopSignCenterPiece2_Es:: @ 0x083FBC24
	.incbin "graphics/stage/ruby/shop_sign/shop_sign_center_piece2_es.4bpp"
gRubyEvoArrow_R0_Off:: @ 0x083FBDC4
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row0.4bpp"

gRubyEvoArrow_R0_On:: @ 0x083FBE64
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row0.4bpp"

gRubyMartArrow_R0_Off:: @ 0x083FBF04
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row0.4bpp"

gRubyMartArrow_R0_On:: @ 0x083FBFA4
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row0.4bpp"
	.space 0x180

gRubyEvoArrow_R1_Off:: @ 0x083FC1C4
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row1.4bpp"

gRubyEvoArrow_R1_On:: @ 0x083FC264
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row1.4bpp"

gRubyMartArrow_R1_Off:: @ 0x083FC304
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row1.4bpp"

gRubyMartArrow_R1_On:: @ 0x083FC3A4
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row1.4bpp"
	.space 0x180

gRubyEvoArrow_R2_Off:: @ 0x083FC5C4
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row2.4bpp"

gRubyEvoArrow_R2_On:: @ 0x083FC664
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row2.4bpp"

gRubyMartArrow_R2_Off:: @ 0x083FC704
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row2.4bpp"

gRubyMartArrow_R2_On:: @ 0x083FC7A4
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row2.4bpp"
	.space 0x180

gRubyEvoArrow_R3_Off:: @ 0x083FC9C4
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_filler.4bpp"

gRubyEvoArrow_R3_On:: @ 0x083FCA64
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_filler.4bpp"

gRubyMartArrow_R3_Off:: @ 0x083FCB04
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_filler.4bpp"

gRubyMartArrow_R3_On:: @ 0x083FCBA4
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_filler.4bpp"
	.space 0x1A0



@ Slingshot wedge lights

gRubyEvoArrow_R0_Off_Fr:: @ 0x083FCDE4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row0_fr.4bpp"
gRubyEvoArrow_R0_On_Fr:: @ 0x083FCE84
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row0_fr.4bpp"
gRubyMartArrow_R0_Off_Fr:: @ 0x083FCF24
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row0_fr.4bpp"
gRubyMartArrow_R0_On_Fr:: @ 0x083FCFC4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row0_fr.4bpp"
	.space 0x180
gRubyEvoArrow_R1_Off_Fr:: @ 0x083FD1E4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row1_fr.4bpp"
gRubyEvoArrow_R1_On_Fr:: @ 0x083FD284
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row1_fr.4bpp"
gRubyMartArrow_R1_Off_Fr:: @ 0x083FD324
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row1_fr.4bpp"
gRubyMartArrow_R1_On_Fr:: @ 0x083FD3C4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row1_fr.4bpp"
	.space 0x180
gRubyEvoArrow_R2_Off_Fr:: @ 0x083FD5E4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row2_fr.4bpp"
gRubyEvoArrow_R2_On_Fr:: @ 0x083FD684
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row2_fr.4bpp"
gRubyMartArrow_R2_Off_Fr:: @ 0x083FD724
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row2_fr.4bpp"
gRubyMartArrow_R2_On_Fr:: @ 0x083FD7C4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row2_fr.4bpp"
	.space 0x180
gRubyEvoArrow_R3_Off_Fr:: @ 0x083FD9E4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_fr.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_filler_fr.4bpp"
gRubyEvoArrow_R3_On_Fr:: @ 0x083FDA84
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_fr.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_filler_fr.4bpp"
gRubyMartArrow_R3_Off_Fr:: @ 0x083FDB24
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_fr.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_filler_fr.4bpp"
gRubyMartArrow_R3_On_Fr:: @ 0x083FDBC4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_fr.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_filler_fr.4bpp"
	.space 0x1A0
gRubyEvoArrow_R0_Off_De:: @ 0x083FDE04
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row0_de.4bpp"
gRubyEvoArrow_R0_On_De:: @ 0x083FDEA4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row0_de.4bpp"
gRubyMartArrow_R0_Off_De:: @ 0x083FDF44
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row0_de.4bpp"
gRubyMartArrow_R0_On_De:: @ 0x083FDFE4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row0_de.4bpp"
	.space 0x180
gRubyEvoArrow_R1_Off_De:: @ 0x083FE204
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row1_de.4bpp"
gRubyEvoArrow_R1_On_De:: @ 0x083FE2A4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row1_de.4bpp"
gRubyMartArrow_R1_Off_De:: @ 0x083FE344
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row1_de.4bpp"
gRubyMartArrow_R1_On_De:: @ 0x083FE3E4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row1_de.4bpp"
	.space 0x180
gRubyEvoArrow_R2_Off_De:: @ 0x083FE604
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row2_de.4bpp"
gRubyEvoArrow_R2_On_De:: @ 0x083FE6A4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row2_de.4bpp"
gRubyMartArrow_R2_Off_De:: @ 0x083FE744
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row2_de.4bpp"
gRubyMartArrow_R2_On_De:: @ 0x083FE7E4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row2_de.4bpp"
	.space 0x180
gRubyEvoArrow_R3_Off_De:: @ 0x083FEA04
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_de.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_filler_de.4bpp"
gRubyEvoArrow_R3_On_De:: @ 0x083FEAA4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_de.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_filler_de.4bpp"
gRubyMartArrow_R3_Off_De:: @ 0x083FEB44
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_de.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_filler_de.4bpp"
gRubyMartArrow_R3_On_De:: @ 0x083FEBE4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_de.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_filler_de.4bpp"
	.space 0x1A0
gRubyEvoArrow_R0_Off_It:: @ 0x083FEE24
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row0_it.4bpp"
gRubyEvoArrow_R0_On_It:: @ 0x083FEEC4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row0_it.4bpp"
gRubyMartArrow_R0_Off_It:: @ 0x083FEF64
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row0_it.4bpp"
gRubyMartArrow_R0_On_It:: @ 0x083FF004
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row0_it.4bpp"
	.space 0x180
gRubyEvoArrow_R1_Off_It:: @ 0x083FF224
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row1_it.4bpp"
gRubyEvoArrow_R1_On_It:: @ 0x083FF2C4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row1_it.4bpp"
gRubyMartArrow_R1_Off_It:: @ 0x083FF364
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row1_it.4bpp"
gRubyMartArrow_R1_On_It:: @ 0x083FF404
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row1_it.4bpp"
	.space 0x180
gRubyEvoArrow_R2_Off_It:: @ 0x083FF624
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row2_it.4bpp"
gRubyEvoArrow_R2_On_It:: @ 0x083FF6C4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row2_it.4bpp"
gRubyMartArrow_R2_Off_It:: @ 0x083FF764
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row2_it.4bpp"
gRubyMartArrow_R2_On_It:: @ 0x083FF804
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row2_it.4bpp"
	.space 0x180
gRubyEvoArrow_R3_Off_It:: @ 0x083FFA24
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_it.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_filler_it.4bpp"
gRubyEvoArrow_R3_On_It:: @ 0x083FFAC4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_it.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_filler_it.4bpp"
gRubyMartArrow_R3_Off_It:: @ 0x083FFB64
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_it.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_filler_it.4bpp"
gRubyMartArrow_R3_On_It:: @ 0x083FFC04
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_it.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_filler_it.4bpp"
	.space 0x1A0
gRubyEvoArrow_R0_Off_Es:: @ 0x083FFE44
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row0_es.4bpp"
gRubyEvoArrow_R0_On_Es:: @ 0x083FFEE4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row0_es.4bpp"
gRubyMartArrow_R0_Off_Es:: @ 0x083FFF84
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row0_es.4bpp"
gRubyMartArrow_R0_On_Es:: @ 0x08400024
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row0_es.4bpp"
	.space 0x180
gRubyEvoArrow_R1_Off_Es:: @ 0x08400244
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row1_es.4bpp"
gRubyEvoArrow_R1_On_Es:: @ 0x084002E4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row1_es.4bpp"
gRubyMartArrow_R1_Off_Es:: @ 0x08400384
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row1_es.4bpp"
gRubyMartArrow_R1_On_Es:: @ 0x08400424
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row1_es.4bpp"
	.space 0x180
gRubyEvoArrow_R2_Off_Es:: @ 0x08400644
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row2_es.4bpp"
gRubyEvoArrow_R2_On_Es:: @ 0x084006E4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row2_es.4bpp"
gRubyMartArrow_R2_Off_Es:: @ 0x08400784
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row2_es.4bpp"
gRubyMartArrow_R2_On_Es:: @ 0x08400824
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row2_es.4bpp"
	.space 0x180
gRubyEvoArrow_R3_Off_Es:: @ 0x08400A44
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_es.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_filler_es.4bpp"
gRubyEvoArrow_R3_On_Es:: @ 0x08400AE4
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_es.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_filler_es.4bpp"
gRubyMartArrow_R3_Off_Es:: @ 0x08400B84
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_es.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_filler_es.4bpp"
gRubyMartArrow_R3_On_Es:: @ 0x08400C24
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_es.4bpp"
	.incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_filler_es.4bpp"
	.space 0x1A0
gRuby_LSlingshot_Off_R0:: @ 0x08400E64
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row0.4bpp"
	.space 0x40

gRuby_LSlingshot_On_R0:: @ 0x08400EC4
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row0.4bpp"
	.space 0x80

gRuby_RSlingshot_Off_R0:: @ 0x08400F64
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row0.4bpp"
	.space 0x40

gRuby_RSlingshot_On_R0:: @ 0x08400FC4
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row0.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R1:: @ 0x08401264
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row1.4bpp"
	.space 0x20

gRuby_LSlingshot_On_R1:: @ 0x084012C4
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row1.4bpp"
	.space 0x40

gRuby_RSlingshot_Off_R1:: @ 0x08401344
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row1.4bpp"
	.space 0x20

gRuby_RSlingshot_On_R1:: @ 0x084013A4
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row1.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R2:: @ 0x08401664
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row2.4bpp"

gRuby_LSlingshot_On_R2:: @ 0x084016C4
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row2.4bpp"

gRuby_RSlingshot_Off_R2:: @ 0x08401724
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row2.4bpp"

gRuby_RSlingshot_On_R2:: @ 0x08401784
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row2.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R3:: @ 0x08401A64
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row3.4bpp"

gRuby_LSlingshot_On_R3:: @ 0x08401AC4
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row3.4bpp"

gRuby_RSlingshot_Off_R3:: @ 0x08401B24
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row3.4bpp"

gRuby_RSlingshot_On_R3:: @ 0x08401B84
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row3.4bpp"
	.space 0x2A0

gRuby_LSlingshot_Off_R4:: @ 0x08401E84
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row4.4bpp"
	.space 0x20

gRuby_LSlingshot_On_R4:: @ 0x08401EE4
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row4.4bpp"

gRuby_RSlingshot_Off_R4:: @ 0x08401F24
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row4.4bpp"
	.space 0x20

gRuby_RSlingshot_On_R4:: @ 0x08401F84
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row4.4bpp"
	.space 0x2C0



gRubyBoardBG1Tiles:: @ 0x08402284
	@ loaded to charblock 2; tiles 0-703 are blank because all_board_setup.c
	@ later overwrites that region with the decompressed bgtop tiles
	.incbin "graphics/stage/ruby/ruby_board_bg1_tiles.4bpp"

gRubyBoardBG1Tilemap:: @ 0x0840A284
	.incbin "graphics/stage/ruby/ruby_board_bg1_tilemap.bin"
