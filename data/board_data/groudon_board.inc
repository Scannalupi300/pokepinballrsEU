@ note: base collision data for kyogre/groudon boards are shared.
@ that is in the kyogre_board.inc file (gKyrGrouBoardCollision{Tile,Angle,Type}DataAllLayers)

gGroudonLavaPaletteCycleData:: @ 0x08529778
	.incbin "graphics/stage/groudon/groudon_lava.gbapal"

gGroudonBoardBG3Tilemap:: @ 0x08529978
	.incbin "graphics/stage/groudon/groudon_board_bg3_tilemap.bin"

gGroudonBoardBG2Tilemap:: @ 0x0852A178
	.incbin "graphics/stage/groudon/groudon_board_bg2_tilemap.bin"

gGroudonBoardCompressedBGTiles:: @ 0x0852A978
    .incbin "graphics/stage/groudon/groudon_board_bg_tiles.4bpp.lz"

gGroudonBodyCollisionMap:: @ 0x0852E568
	.incbin "data/board_data/collision/groudon/groudon_entity_collision_112x128.bin"

gGroudonProjectileCollisionMap:: @ 0x08535568
	.incbin "data/board_data/collision/groudon/groudon_projectile_collision_80x80.bin"
	.incbin "data/board_data/collision/groudon/groudon_projectile_collision2_80x56.bin"
