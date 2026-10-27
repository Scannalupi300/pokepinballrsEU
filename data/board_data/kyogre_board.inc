@ note: base collision data for kyogre/groudon boards are shared.
@ that is in this file (gKyrGrouBoardCollision{Tile,Angle,Type}DataAllLayers)
@ other data is kyogre specific

gKyogreBoardPalette:: @ 0x085099A4
	.incbin "graphics/stage/kyogre/kyogre_board.gbapal"

gKyogreWaterBackgroundTilemap:: @ 0x08509BA4
	.incbin "graphics/stage/kyogre/kyogre_board_bg3_tilemap.bin"

gKyrGrouBoardCollisionTileDataAllLayers:: @ 0x0850A3A4
	.incbin "data/board_data/collision/kyogre/board_tiledata.bin"

gKyrGrouBoardCollisionAngleDataAllLayers:: @ 0x0850C3A4
	.incbin "data/board_data/collision/kyogre/board_angledata.bin"

gKyrGrouBoardCollisionTypeDataAllLayers:: @ 0x08511924
	.incbin "data/board_data/collision/kyogre/board_typedata.bin"

gKyogreBoardBG2Tilemap:: @ 0x085143E4
	.incbin "graphics/stage/kyogre/kyogre_board_bg2_tilemap.bin"

gKyogreBoardCompressedBGTiles:: @ 0x08514BE4
	.incbin "graphics/stage/kyogre/kyogre_board_bg_tiles.4bpp.lz"

gKyogreIntroShorePalette:: @ 0x08516AF8
	.incbin "graphics/stage/kyogre/intro_shore.gbapal"

gKyogreFadeInPaletteStep4:: @ 0x08516CF8
    .incbin "graphics/stage/kyogre/fade_in_step4.gbapal"

gKyogreFadeInPaletteStep3:: @ 0x08516EF8
    .incbin "graphics/stage/kyogre/fade_in_step3.gbapal"

gKyogreFadeInPaletteStep2:: @ 0x085170F8
    .incbin "graphics/stage/kyogre/fade_in_step2.gbapal"

gKyogreFadeInPaletteStep1:: @ 0x085172F8
    .incbin "graphics/stage/kyogre/fade_in_step1.gbapal"

gKyogreFadeInPaletteStep0:: @ 0x085174F8
    .incbin "graphics/stage/kyogre/fade_in_step0.gbapal"

gKyogreForm1CollisionMap:: @ 0x085176F8
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_1_collision_120x152.bin"

gKyogreForm2CollisionMap:: @ 0x08520578
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_2_collision_96x88.bin"

gKyogreForm3CollisionMap:: @ 0x08524778
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_3_collision_96x104.bin"

gKyogreIntroIcePalette:: @ 0x08529578
	.incbin "graphics/stage/kyogre/intro_ice.gbapal"
