gSphealBoardPalette:: @ 0x08550E88
	.incbin "graphics/stage/spheal/spheal_board.gbapal"

gSphealWaterBackgroundTilemap:: @ 0x08551088
	.incbin "graphics/stage/spheal/spheal_board_bgwater_tilemap.bin"

gSphealBoardCollisionTileDataAllLayers:: @ 0x08551888
	.incbin "data/board_data/collision/spheal/board_tiledata.bin"

gSphealBoardCollisionAngleDataAllLayers:: @ 0x08553888
	.incbin "data/board_data/collision/spheal/board_angledata.bin"

gSphealBoardCollisionTypeDataAllLayers:: @ 0x0855F008
	.incbin "data/board_data/collision/spheal/board_typedata.bin"

gSphealBoardBG2Tilemap:: @ 0x08564BC8
	.incbin "graphics/stage/spheal/spheal_board_bg_tilemap.bin"

gSphealBoardCompressedBGTiles:: @ 0x085653C8
	.incbin "graphics/stage/spheal/spheal_board_bg_tiles.4bpp.lz"

gSphealRampCollisionMap:: @ 0x085685EC
	.incbin "data/board_data/collision/spheal/spheal_ramp_entity_collision_64x64.bin"

gSphealFrozenIceCollisionMap:: @ 0x0856A5EC
	.incbin "data/board_data/collision/spheal/spheal_ice_water_entity_collision_64x64.bin"
