.section .rodata

.include "asm/macros/m4a.inc"
.include "asm/macros/music_voice.inc"

@ Note, this appears identical to rs_drumset in pokeemerald
voice_group gUnknown_0852DBAC, 36
	voice_directsound_no_resample 60, 64, sc88pro_rnd_kick, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08535D10, 255, 0, 255, 242
	voice_directsound_no_resample 60, 64, gDirectSound_08536404, 255, 255, 255, 127
	voice_directsound_no_resample 60, 64, sc88pro_orchestra_snare, 255, 0, 255, 242
	voice_directsound 48, 44, sc55_tom, 255, 210, 77, 204
	voice_directsound_no_resample 60, 79, unknown_close_hihat, 255, 127, 0, 188
	voice_directsound 51, 49, sc55_tom, 255, 216, 77, 204
	voice_directsound_no_resample 60, 79, unknown_close_hihat, 255, 127, 0, 188
	voice_directsound 54, 59, sc55_tom, 255, 216, 77, 204
	voice_directsound_no_resample 60, 79, unknown_open_hihat, 255, 242, 141, 0
	voice_directsound 57, 69, sc55_tom, 255, 210, 77, 204
	voice_directsound 60, 79, sc55_tom, 255, 204, 77, 204
	voice_directsound_no_resample 30, 54, sc88pro_orchestra_cymbal_crash, 255, 246, 0, 216
	voice_directsound 62, 84, sc55_tom, 255, 204, 77, 204
	voice_directsound_no_resample 70, 49, unknown_bell, 255, 165, 103, 231
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 70, 49, unknown_bell, 255, 165, 103, 231
	voice_directsound_no_resample 32, 34, sc88pro_tambourine, 255, 127, 77, 204
	voice_directsound_no_resample 60, 14, trinity_cymbal_crash, 255, 235, 0, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, sc88pro_orchestra_cymbal_crash, 255, 246, 0, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, sc88pro_orchestra_cymbal_crash, 255, 246, 0, 216
	voice_directsound_no_resample 30, 54, sc88pro_orchestra_cymbal_crash, 8, 0, 255, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 104, sc88pro_mute_high_conga, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 94, sc88pro_open_low_conga, 255, 0, 255, 0

gUnknown_0852DD08:: @ 0x087BF6A8
	voice_directsound 60, 0, sc88pro_piano1_48, 255, 252, 0, 239
	voice_directsound 60, 0, sc88pro_piano1_60, 255, 250, 0, 221
	voice_directsound 60, 0, sc88pro_piano1_72, 255, 250, 0, 221
	voice_directsound 60, 0, sc88pro_piano1_84, 255, 247, 0, 221

gUnknown_0852DD38:: @ 0x087BF6D8
	voice_directsound 60, 0, sc88pro_string_ensemble_60, 255, 0, 255, 196
	voice_directsound 60, 0, sc88pro_string_ensemble_72, 255, 0, 255, 196
	voice_directsound 60, 0, sc88pro_string_ensemble_84, 255, 0, 255, 196

gUnknown_0852DD5C:: @ 0x087BF6FC
	voice_directsound 60, 0, sc88pro_trumpet_60, 255, 0, 193, 127
	voice_directsound 60, 0, sc88pro_trumpet_72, 255, 0, 193, 127
	voice_directsound 60, 0, sc88pro_trumpet_84, 255, 0, 193, 127

gUnknown_0852DD80:: @ 0x087BF720
	voice_directsound 60, 0, sc88pro_tuba_39, 255, 0, 255, 165
	voice_directsound 60, 0, sc88pro_tuba_51, 255, 0, 255, 165

gUnknown_0852DD98:: @ 0x087BF738
	voice_directsound 60, 0, sc88pro_french_horn_60, 255, 0, 224, 165
	voice_directsound 60, 0, sc88pro_french_horn_72, 255, 0, 218, 165

gUnknown_0852DDB0:: @ 0x087BF750
	voice_directsound 60, 0, sc88pro_piano1_48, 255, 252, 0, 252
	voice_directsound 60, 0, sc88pro_piano1_60, 255, 250, 0, 250
	voice_directsound 60, 0, sc88pro_piano1_72, 255, 250, 0, 250
	voice_directsound 60, 0, sc88pro_piano1_84, 255, 247, 0, 247

gVoiceGroup_Inst_0852DDE0:: @ 0x087BF780
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_directsound 60, 0, trinity_30303_mega_bass, 255, 178, 180, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_glockenspiel, 255, 165, 51, 235
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_xylophone, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_harp, 255, 242, 0, 204
	voice_directsound 60, 0, sc88pro_timpani, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_flute, 255, 127, 231, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 1, 7, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 7, 1
	voice_square_2_alt 60, 0, 3, 0, 1, 7, 1
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 7, 1
	voice_square_2_alt 60, 0, 2, 0, 1, 4, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 2
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 15, 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 29, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 22, 2, 0, 2, 0, 0
	voice_directsound_no_resample 60, 64, sc88pro_rnd_kick, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08535D10, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, sc88pro_orchestra_snare, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 32, 74, sc88pro_tambourine, 255, 127, 77, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 66, sc88pro_mute_high_conga, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 62, sc88pro_open_low_conga, 255, 0, 255, 0

gVoiceGroup_Evolution_0852E404:: @ 0x087BFDA4
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_timpani, 255, 246, 0, 226
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 1, 9, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 9, 0
	voice_square_2_alt 60, 0, 3, 0, 1, 7, 0
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, sc88pro_orchestra_snare, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 32, 49, sc88pro_tambourine, 255, 127, 77, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, sc88pro_orchestra_cymbal_crash, 8, 0, 255, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, sc88pro_orchestra_cymbal_crash, 255, 246, 0, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 79, sc88pro_mute_high_conga, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 74, sc88pro_open_low_conga, 255, 0, 255, 0

gVoiceGroup_HurryUp_0852E95C:: @ 0x087C02FC
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_flute, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gVoiceGroup_Pokedex_0852EF5C:: @ 0x087C08FC
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_tubular_bell, 255, 165, 90, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_organ2, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_nylon_str_guitar, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_fretless_bass, 255, 253, 0, 188
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_flute, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 2, 3, 1
	voice_square_2_alt 60, 0, 2, 0, 2, 3, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D44, 0, 7, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gVoiceGroup_Title_0852F55C:: @ 0x087C0EFC
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_nylon_str_guitar, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_fretless_bass, 255, 253, 0, 188
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_harp, 255, 242, 51, 242
	voice_directsound 60, 0, sc88pro_timpani, 255, 0, 180, 246
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 2, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D44, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 2, 4, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gVoiceGroup_Jirachi_0852FB5C:: @ 0x087C14FC
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_xylophone, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_nylon_str_guitar, 128, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_slap_bass, 255, 235, 128, 99
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_harp, 255, 242, 0, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_flute, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gVoiceGroup_EggModeStart_0853015C:: @ 0x087C1AFC
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_glockenspiel, 255, 165, 72, 249
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_xylophone, 255, 235, 0, 204
	voice_directsound 60, 0, sc88pro_tubular_bell, 255, 165, 90, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_organ2, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_accordion, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_nylon_str_guitar, 128, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_timpani, 255, 0, 180, 246
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_flute, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gVoiceGroup_EggMode_0853075C:: @ 0x087C20FC
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_organ2, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_nylon_str_guitar, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_flute, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 3
	voice_square_2_alt 60, 0, 3, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gVoiceGroup_EvoMode_08530D5C:: @ 0x087C26FC
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_xylophone, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_organ2, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_nylon_str_guitar, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534DB4, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_slap_bass, 255, 235, 128, 99
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_timpani, 255, 0, 180, 246
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_flute, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_1_alt 60, 0, 0, 2, 1, 1, 4, 1
	voice_square_2_alt 60, 0, 2, 1, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D34, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gVoiceGroup_UnkMus_0853135C:: @ 0x087C2CFC
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 2, 0, 2, 3, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_timpani, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 3, 0, 1, 7, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D54, 0, 7, 15, 2
	voice_square_1 60, 0, 0, 3, 0, 1, 7, 1
	voice_square_1 60, 0, 0, 3, 0, 0, 7, 1

gVoiceGroup_SFX_0853174C:: @ 0x087C30EC
	voice_directsound 60, 0, unknown_synth_snare, 255, 249, 103, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 2, 0, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 4, 0, 1
	voice_square_1_alt 60, 0, 44, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 38, 0, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 7, 0, 0
	voice_square_1_alt 60, 0, 0, 2, 2, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 2, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 1, 0, 1, 9, 0
	voice_directsound 60, 0, sc88pro_square_wave, 255, 0, 255, 165
	voice_directsound 60, 0, sc88pro_square_wave, 255, 226, 0, 165
	voice_square_1_alt 60, 0, 0, 2, 0, 6, 0, 1
	voice_square_1_alt 60, 0, 36, 0, 0, 2, 0, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_timpani, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 3, 0, 1, 0, 1
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 0, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 46, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 38, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 119, 2, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 106, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 23, 2, 0, 1, 9, 0
	voice_square_1_alt 60, 0, 21, 2, 0, 1, 9, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 47, 2, 0, 2, 6, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise 60, 0, 0, 0, 7, 15, 0
	voice_noise 60, 0, 0, 2, 7, 15, 0
	voice_noise_alt 60, 0, 0, 2, 0, 15, 0
	voice_noise_alt 60, 0, 1, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 2, 0, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 1

gVoiceGroup_SFX_08531D4C:: @ 0x087C36EC
	voice_directsound_no_resample 60, 0, bicycle_bell, 255, 249, 0, 165
	voice_directsound_alt 60, 0, bicycle_bell, 255, 0, 255, 165
	voice_directsound 60, 0, unknown_synth_snare, 255, 0, 255, 165
	voice_directsound 60, 0, sc88pro_glockenspiel, 255, 242, 0, 127
	voice_noise_alt 60, 0, 0, 0, 1, 0, 1
	voice_noise_alt 60, 0, 1, 0, 1, 0, 1
	voice_directsound 60, 0, sc88pro_timpani, 255, 0, 255, 165
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 1
	voice_directsound 60, 0, gDirectSound_08564D20, 255, 0, 255, 165
	voice_directsound 60, 0, sc88pro_pizzicato_strings, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08566920, 255, 0, 255, 127
	voice_noise_alt 60, 0, 1, 0, 2, 0, 0
	voice_square_1 60, 0, 103, 3, 2, 7, 0, 0
	voice_square_2 60, 0, 3, 2, 7, 0, 0
	voice_directsound 60, 0, sc88pro_square_wave, 255, 226, 0, 127
	voice_directsound 60, 0, gDirectSound_08568510, 255, 0, 255, 0
	voice_directsound 60, 0, sc88pro_square_wave, 255, 204, 0, 127
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 1
	voice_directsound 60, 0, gDirectSound_085698C4, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_square_wave, 255, 0, 255, 127
	voice_square_1 60, 0, 103, 0, 0, 7, 0, 0
	voice_directsound 60, 0, sc88pro_orchestra_snare, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_wind, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_bubbles, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08535D10, 255, 0, 255, 127
	voice_noise_alt 60, 0, 0, 0, 7, 15, 1
	voice_directsound 60, 0, gDirectSound_0856E19C, 255, 0, 255, 127
	voice_noise_alt 60, 0, 1, 0, 7, 15, 1
	voice_directsound 60, 0, sc88pro_glockenspiel, 255, 246, 0, 127
	voice_directsound 60, 0, gDirectSound_0856F4A4, 255, 0, 255, 127
	voice_square_1_alt 60, 0, 19, 2, 0, 2, 0, 0
	voice_directsound 60, 0, trinity_30303_mega_bass, 255, 0, 255, 127
	voice_square_1 60, 0, 103, 0, 0, 0, 15, 0
	voice_directsound_alt 60, 0, gDirectSound_0856F4A4, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_fretless_bass, 255, 255, 255, 127
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08574DCC, 255, 0, 255, 127
	voice_directsound 60, 0, trinity_30303_mega_bass, 255, 242, 0, 0
	voice_directsound 60, 0, gDirectSound_08576FDC, 255, 0, 255, 0
	voice_directsound 60, 0, sc88pro_tubular_bell, 255, 165, 90, 216
	voice_directsound 60, 0, unknown_close_hihat, 255, 127, 0, 188
	voice_directsound 60, 0, gDirectSound_08579118, 255, 249, 0, 165
	voice_square_1 60, 0, 0, 0, 4, 6, 0, 0
	voice_directsound 60, 0, sc88pro_glockenspiel, 13, 0, 255, 127
	voice_directsound 60, 0, sc88pro_tubular_bell, 13, 0, 255, 127
	voice_directsound 60, 0, trinity_big_boned, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_harp, 255, 252, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sc88pro_xylophone, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 0, 4, 0, 15, 0
	voice_directsound 60, 0, sc88pro_xylophone, 255, 188, 0, 0
	voice_directsound 60, 0, sc88pro_tubular_bell, 255, 226, 0, 127
	voice_directsound 60, 0, sc88pro_orchestra_cymbal_crash, 26, 0, 255, 127
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 0, 0
	voice_directsound 60, 0, sc88pro_glockenspiel, 255, 252, 0, 127
	voice_square_1_alt 60, 0, 0, 1, 0, 2, 0, 0
	voice_directsound 60, 0, sc88pro_pizzicato_strings, 255, 127, 0, 127
	voice_noise_alt 60, 0, 0, 1, 6, 0, 0
	voice_directsound 60, 0, sc88pro_slap_bass, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08536404, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08580744, 255, 255, 255, 127
	voice_directsound 60, 0, sc88pro_french_horn_72, 11, 242, 0, 127
	voice_square_1_alt 60, 0, 0, 2, 4, 6, 0, 0
	voice_directsound 60, 0, gDirectSound_08582284, 255, 255, 255, 127
	voice_directsound 60, 0, sc88pro_accordion, 255, 0, 255, 165
	voice_directsound 60, 0, sc55_tom, 255, 0, 255, 165
	voice_noise_alt 60, 0, 0, 5, 7, 15, 1
	voice_directsound 60, 0, sc88pro_square_wave, 128, 242, 0, 165
	voice_directsound 60, 0, sc88pro_string_ensemble_72, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 0, 1, 5, 0, 0
	voice_noise_alt 60, 0, 0, 6, 6, 0, 1
	voice_noise_alt 60, 0, 0, 3, 6, 0, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, trinity_30303_mega_bass, 15, 127, 231, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08583F1C, 255, 0, 255, 165

gVoiceGroup_SFX_08532310:: @ 0x087C3CB0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 1, 0, 15, 0
	voice_noise_alt 60, 0, 0, 1, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 31, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 31, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 55, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 21, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 0, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 63, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 103, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 1, 0, 15, 0
	voice_square_1_alt 60, 0, 103, 0, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08584B2C, 255, 0, 255, 0 @ 30
	voice_directsound 60, 0, gDirectSound_08588238, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_08588C10, 255, 0, 255, 0
	voice_directsound 60, 0, sc88pro_wind, 64, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_0858AA14, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_se_pikachu_kickback @ 101
	voice_directsound_compressed gDirectSound_se_pika_no_kickback
	voice_directsound_compressed gDirectSound_se_pichu_kickback_enabled
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_se_pichu_kickback

gVoiceGroup_Inst_08532808:: @ 0x087C41A8
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_keysplit gUnknown_0852DDB0, keysplit_gUnknown_08534BC0
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_directsound 60, 0, gDirectSound_085A37F4, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 210
	voice_directsound 60, 0, sc88pro_glockenspiel, 255, 165, 51, 235
	voice_directsound 60, 0, sc88pro_glockenspiel, 255, 165, 51, 235
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_directsound 60, 0, gDirectSound_085A4FE4, 255, 241, 0, 210
	voice_directsound 60, 0, sc88pro_xylophone, 255, 235, 0, 204
	voice_directsound 60, 0, sc88pro_tubular_bell, 255, 216, 90, 242
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_organ2, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_accordion, 255, 0, 255, 165
	voice_directsound 60, 0, sc88pro_accordion, 255, 0, 255, 165
	voice_directsound 60, 0, sc88pro_accordion, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_directsound 60, 0, sc88pro_nylon_str_guitar, 255, 249, 25, 149
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 248, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 210, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, sc88pro_fretless_bass, 255, 253, 0, 149
	voice_directsound 60, 0, sc88pro_fingered_bass, 255, 253, 0, 149
	voice_directsound 60, 0, gDirectSound_085A7D6C, 255, 253, 0, 127
	voice_directsound 60, 0, gDirectSound_085A7D6C, 255, 253, 0, 127
	voice_directsound 60, 0, sc88pro_slap_bass, 255, 235, 128, 115
	voice_directsound 60, 0, trinity_30303_mega_bass, 255, 178, 180, 165
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_directsound 60, 0, sc88pro_synth_bass, 255, 252, 0, 115
	voice_directsound 60, 0, gDirectSound_085A7EDC, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A7EDC, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8470, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8470, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_directsound 60, 0, sc88pro_pizzicato_strings, 255, 216, 0, 165
	voice_directsound 60, 0, sc88pro_harp, 255, 242, 0, 204
	voice_directsound 60, 0, sc88pro_timpani, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_directsound 60, 0, gDirectSound_085A9EA4, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_directsound 60, 0, gDirectSound_085A9EA4, 255, 210, 0, 127
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA274, 128, 0, 255, 127
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_flute, 255, 127, 231, 127
	voice_directsound 60, 0, sc88pro_flute, 255, 127, 231, 127
	voice_directsound 60, 0, sc88pro_flute, 255, 127, 231, 127
	voice_directsound 60, 0, sc88pro_flute, 255, 127, 231, 127
	voice_directsound 60, 0, sc88pro_flute, 255, 127, 231, 127
	voice_directsound 60, 0, sc88pro_flute, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_085ABE38, 255, 0, 255, 127
	voice_directsound 60, 0, sc88pro_flute, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_085AA274, 128, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 0, sc88pro_orchestra_cymbal_crash, 255, 249, 0, 249
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 0, unknown_close_hihat, 255, 89, 0, 89

gPokemonCryToneBank0:: @ 0x087C470C
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry025_Pikachu
	voice_directsound_compressed gDirectSound_Cry026_Raichu
	voice_directsound_compressed gDirectSound_Cry027_Sandshrew
	voice_directsound_compressed gDirectSound_Cry028_Sandslash
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry037_Vulpix
	voice_directsound_compressed gDirectSound_Cry038_Ninetales
	voice_directsound_compressed gDirectSound_Cry039_Jigglypuff
	voice_directsound_compressed gDirectSound_Cry040_Wigglytuff
	voice_directsound_compressed gDirectSound_Cry041_Zubat
	voice_directsound_compressed gDirectSound_Cry042_Golbat
	voice_directsound_compressed gDirectSound_Cry043_Oddish
	voice_directsound_compressed gDirectSound_Cry044_Gloom
	voice_directsound_compressed gDirectSound_Cry045_Vileplume
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry054_Psyduck
	voice_directsound_compressed gDirectSound_Cry055_Golduck
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry063_Abra
	voice_directsound_compressed gDirectSound_Cry064_Kadabra
	voice_directsound_compressed gDirectSound_Cry065_Alakazam
	voice_directsound_compressed gDirectSound_Cry066_Machop
	voice_directsound_compressed gDirectSound_Cry067_Machoke
	voice_directsound_compressed gDirectSound_Cry068_Machamp
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry072_Tentacool
	voice_directsound_compressed gDirectSound_Cry073_Tentacruel
	voice_directsound_compressed gDirectSound_Cry074_Geodude
	voice_directsound_compressed gDirectSound_Cry075_Graveler
	voice_directsound_compressed gDirectSound_Cry076_Golem
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry081_Magnemite
	voice_directsound_compressed gDirectSound_Cry082_Magneton
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry084_Doduo
	voice_directsound_compressed gDirectSound_Cry085_Dodrio
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry088_Grimer
	voice_directsound_compressed gDirectSound_Cry089_Muk
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry100_Voltorb
	voice_directsound_compressed gDirectSound_Cry101_Electrode
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry109_Koffing
	voice_directsound_compressed gDirectSound_Cry110_Weezing
	voice_directsound_compressed gDirectSound_Cry111_Rhyhorn
	voice_directsound_compressed gDirectSound_Cry112_Rhydon
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry116_Horsea
	voice_directsound_compressed gDirectSound_Cry117_Seadra
	voice_directsound_compressed gDirectSound_Cry118_Goldeen
	voice_directsound_compressed gDirectSound_Cry119_Seaking
	voice_directsound_compressed gDirectSound_Cry120_Staryu
	voice_directsound_compressed gDirectSound_Cry121_Starmie
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry127_Pinsir
	@ note: array stops 1 early; should have a row for Tauros here

gPokemonCryToneBank1:: @ 0x087C4D00
	voice_directsound_compressed gDirectSound_Cry129_Magikarp
	voice_directsound_compressed gDirectSound_Cry130_Gyarados
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry142_Aerodactyl
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry152_Chikorita
	voice_directsound_compressed gDirectSound_Cry153_Bayleef
	voice_directsound_compressed gDirectSound_Cry154_Meganium
	voice_directsound_compressed gDirectSound_Cry155_Cyndaquil
	voice_directsound_compressed gDirectSound_Cry156_Quilava
	voice_directsound_compressed gDirectSound_Cry157_Typhlosion
	voice_directsound_compressed gDirectSound_Cry158_Totodile
	voice_directsound_compressed gDirectSound_Cry159_Croconaw
	voice_directsound_compressed gDirectSound_Cry160_Feraligatr
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry169_Crobat
	voice_directsound_compressed gDirectSound_Cry170_Chinchou
	voice_directsound_compressed gDirectSound_Cry171_Lanturn
	voice_directsound_compressed gDirectSound_Cry172_Pichu
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry174_Igglybuff
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry177_Natu
	voice_directsound_compressed gDirectSound_Cry178_Xatu
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry182_Bellossom
	voice_directsound_compressed gDirectSound_Cry183_Marill
	voice_directsound_compressed gDirectSound_Cry184_Azumarill
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry202_Wobbuffet
	voice_directsound_compressed gDirectSound_Cry203_Girafarig
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry214_Heracross
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry218_Slugma
	voice_directsound_compressed gDirectSound_Cry219_Magcargo
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry222_Corsola
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry227_Skarmory
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry230_Kingdra
	voice_directsound_compressed gDirectSound_Cry231_Phanpy
	voice_directsound_compressed gDirectSound_Cry232_Donphan
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_Cry251_Celebi @Celebi
	voice_directsound_compressed gDirectSound_Cry252_Kecleon @KECLEON
	voice_directsound_compressed gDirectSound_Cry253_Roselia
	voice_directsound_compressed gDirectSound_Cry254_Torkoal
	voice_directsound_compressed gDirectSound_Cry255_Electrike
	voice_directsound_compressed gDirectSound_Cry256_Manectric

gPokemonCryToneBank2:: @ 0x087C5300
	voice_directsound_compressed gDirectSound_Cry257_Duskull
	voice_directsound_compressed gDirectSound_Cry258_Latias
	voice_directsound_compressed gDirectSound_Cry259_Wynaut
	voice_directsound_compressed gDirectSound_Cry260_Seviper
	voice_directsound_compressed gDirectSound_Cry261_Sharpedo
	voice_directsound_compressed gDirectSound_Cry262_Zangoose
	voice_directsound_compressed gDirectSound_Cry263_Azurill
	voice_directsound_compressed gDirectSound_Cry264_Swablu
	voice_directsound_compressed gDirectSound_Cry265_Altaria
	voice_directsound_compressed gDirectSound_Cry266_Unused
	voice_directsound_compressed gDirectSound_Cry267_Taillow
	voice_directsound_compressed gDirectSound_Cry268_Swellow
	voice_directsound_compressed gDirectSound_Cry269_Unused
	voice_directsound_compressed gDirectSound_Cry270_Spinda
	voice_directsound_compressed gDirectSound_Cry271_Torchic
	voice_directsound_compressed gDirectSound_Cry272_Combusken
	voice_directsound_compressed gDirectSound_Cry273_Blaziken
	voice_directsound_compressed gDirectSound_Cry274_Treecko @TREECKO
	voice_directsound_compressed gDirectSound_Cry275_Grovyle
	voice_directsound_compressed gDirectSound_Cry276_Sceptile
	voice_directsound_compressed gDirectSound_Cry277_Mudkip
	voice_directsound_compressed gDirectSound_Cry278_Marshtomp
	voice_directsound_compressed gDirectSound_Cry279_Swampert
	voice_directsound_compressed gDirectSound_Cry280_Pelipper
	voice_directsound_compressed gDirectSound_Cry281_Wingull
	voice_directsound_compressed gDirectSound_Cry282_Banette
	voice_directsound_compressed gDirectSound_Cry283_Shuppet
	voice_directsound_compressed gDirectSound_Cry284_Lotad
	voice_directsound_compressed gDirectSound_Cry285_Lombre
	voice_directsound_compressed gDirectSound_Cry286_Ludicolo
	voice_directsound_compressed gDirectSound_Cry287_Seedot
	voice_directsound_compressed gDirectSound_Cry288_Nuzleaf
	voice_directsound_compressed gDirectSound_Cry289_Shiftry
	voice_directsound_compressed gDirectSound_Cry290_Carvanha
	voice_directsound_compressed gDirectSound_Cry291_Wurmple
	voice_directsound_compressed gDirectSound_Cry292_Silcoon
	voice_directsound_compressed gDirectSound_Cry293_Beautifly
	voice_directsound_compressed gDirectSound_Cry294_Cascoon
	voice_directsound_compressed gDirectSound_Cry295_Dustox
	voice_directsound_compressed gDirectSound_Cry296_Ralts
	voice_directsound_compressed gDirectSound_Cry297_Kirlia
	voice_directsound_compressed gDirectSound_Cry298_Gardevoir
	voice_directsound_compressed gDirectSound_Cry299_Slakoth
	voice_directsound_compressed gDirectSound_Cry300_Vigoroth
	voice_directsound_compressed gDirectSound_Cry301_Slaking
	voice_directsound_compressed gDirectSound_Cry302_Nincada
	voice_directsound_compressed gDirectSound_Cry303_Ninjask
	voice_directsound_compressed gDirectSound_Cry304_Shedinja
	voice_directsound_compressed gDirectSound_Cry305_Makuhita
	voice_directsound_compressed gDirectSound_Cry306_Hariyama
	voice_directsound_compressed gDirectSound_Cry307_Nosepass
	voice_directsound_compressed gDirectSound_Cry308_Glalie
	voice_directsound_compressed gDirectSound_Cry309_Plusle
	voice_directsound_compressed gDirectSound_Cry310_Minun
	voice_directsound_compressed gDirectSound_Cry311_Surskit
	voice_directsound_compressed gDirectSound_Cry312_Masquerain
	voice_directsound_compressed gDirectSound_Cry313_Skitty
	voice_directsound_compressed gDirectSound_Cry314_Delcatty
	voice_directsound_compressed gDirectSound_Cry315_Gulpin
	voice_directsound_compressed gDirectSound_Cry316_Swalot
	voice_directsound_compressed gDirectSound_Cry317_Numel
	voice_directsound_compressed gDirectSound_Cry318_Camerupt
	voice_directsound_compressed gDirectSound_Cry319_Barboach
	voice_directsound_compressed gDirectSound_Cry320_Whiscash
	voice_directsound_compressed gDirectSound_Cry321_Corphish
	voice_directsound_compressed gDirectSound_Cry322_Crawdaunt
	voice_directsound_compressed gDirectSound_Cry323_Spoink
	voice_directsound_compressed gDirectSound_Cry324_Grumpig
	voice_directsound_compressed gDirectSound_Cry325_Trapinch
	voice_directsound_compressed gDirectSound_Cry326_Vibrava
	voice_directsound_compressed gDirectSound_Cry327_Flygon
	voice_directsound_compressed gDirectSound_Cry328_Cacnea
	voice_directsound_compressed gDirectSound_Cry329_Cacturne
	voice_directsound_compressed gDirectSound_Cry330_Baltoy
	voice_directsound_compressed gDirectSound_Cry331_Claydol
	voice_directsound_compressed gDirectSound_Cry332_Lunatone
	voice_directsound_compressed gDirectSound_Cry333_Solrock
	voice_directsound_compressed gDirectSound_Cry334_Feebas
	voice_directsound_compressed gDirectSound_Cry335_Milotic
	voice_directsound_compressed gDirectSound_Cry336_Absol
	voice_directsound_compressed gDirectSound_Cry337_Meditite
	voice_directsound_compressed gDirectSound_Cry338_Medicham
	voice_directsound_compressed gDirectSound_Cry339_Spheal
	voice_directsound_compressed gDirectSound_Cry340_Sealeo
	voice_directsound_compressed gDirectSound_Cry341_Walrein
	voice_directsound_compressed gDirectSound_Cry342_Clamperl
	voice_directsound_compressed gDirectSound_Cry343_Huntail
	voice_directsound_compressed gDirectSound_Cry344_Gorebyss
	voice_directsound_compressed gDirectSound_Cry345_Lileep
	voice_directsound_compressed gDirectSound_Cry346_Cradily
	voice_directsound_compressed gDirectSound_Cry347_Anorith
	voice_directsound_compressed gDirectSound_Cry348_Armaldo
	voice_directsound_compressed gDirectSound_Cry349_Beldum
	voice_directsound_compressed gDirectSound_Cry350_Metang
	voice_directsound_compressed gDirectSound_Cry351_Metagross
	voice_directsound_compressed gDirectSound_Cry352_Bagon
	voice_directsound_compressed gDirectSound_Cry353_Shelgon
	voice_directsound_compressed gDirectSound_Cry354_Regirock
	voice_directsound_compressed gDirectSound_Cry355_Regice
	voice_directsound_compressed gDirectSound_Cry356_Registeel
	voice_directsound_compressed gDirectSound_Cry357_Castform
	voice_directsound_compressed gDirectSound_Cry358_Volbeat
	voice_directsound_compressed gDirectSound_Cry359_Illumise
	voice_directsound_compressed gDirectSound_Cry360_Poochyena
	voice_directsound_compressed gDirectSound_Cry361_Mightyena
	voice_directsound_compressed gDirectSound_Cry362_Dusclops
	voice_directsound_compressed gDirectSound_Cry363_Sableye
	voice_directsound_compressed gDirectSound_Cry364_Mawile
	voice_directsound_compressed gDirectSound_Cry365_Aron
	voice_directsound_compressed gDirectSound_Cry366_Lairon
	voice_directsound_compressed gDirectSound_Cry367_Aggron
	voice_directsound_compressed gDirectSound_Cry368_Relicanth
	voice_directsound_compressed gDirectSound_Cry369_Luvdisc
	voice_directsound_compressed gDirectSound_Cry370_Groudon
	voice_directsound_compressed gDirectSound_Cry371_Kyogre
	voice_directsound_compressed gDirectSound_Cry372_Rayquaza
	voice_directsound_compressed gDirectSound_Cry373_Salamence
	voice_directsound_compressed gDirectSound_Cry374_Breloom
	voice_directsound_compressed gDirectSound_Cry375_Shroomish
	voice_directsound_compressed gDirectSound_Cry376_Linoone
	voice_directsound_compressed gDirectSound_Cry377_Tropius
	voice_directsound_compressed gDirectSound_Cry378_Wailmer
	voice_directsound_compressed gDirectSound_Cry379_Zigzagoon
	voice_directsound_compressed gDirectSound_Cry380_Exploud
	voice_directsound_compressed gDirectSound_Cry381_Loured
	voice_directsound_compressed gDirectSound_Cry382_Wailord
	voice_directsound_compressed gDirectSound_Cry383_Whismur
	voice_directsound_compressed gDirectSound_Cry384_Snorunt

gPokemonCryToneBank3:: @ 0x087C5900
	voice_directsound_compressed gDirectSound_Cry385_Latios
	voice_directsound_compressed gDirectSound_Cry386_Jirachi
	voice_directsound_compressed gDirectSound_Cry387_Deoxys
	voice_directsound_compressed gDirectSound_Cry388_Chimecho
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_Cry142_Aerodactyl
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_Cry152_Chikorita
	voice_directsound_compressed_reverse gDirectSound_Cry153_Bayleef
	voice_directsound_compressed_reverse gDirectSound_Cry154_Meganium
	voice_directsound_compressed_reverse gDirectSound_Cry155_Cyndaquil
	voice_directsound_compressed_reverse gDirectSound_Cry156_Quilava
	voice_directsound_compressed_reverse gDirectSound_Cry157_Typhlosion
	voice_directsound_compressed_reverse gDirectSound_Cry158_Totodile
	voice_directsound_compressed_reverse gDirectSound_Cry159_Croconaw
	voice_directsound_compressed_reverse gDirectSound_Cry160_Feraligatr
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_Cry251_Celebi
	voice_directsound_compressed_reverse gDirectSound_Cry252_Kecleon
	voice_directsound_compressed_reverse gDirectSound_Cry253_Roselia
	voice_directsound_compressed_reverse gDirectSound_Cry254_Torkoal
	voice_directsound_compressed_reverse gDirectSound_Cry255_Electrike
	voice_directsound_compressed_reverse gDirectSound_Cry256_Manectric
	voice_directsound_compressed_reverse gDirectSound_Cry257_Duskull
	voice_directsound_compressed_reverse gDirectSound_Cry258_Latias
	voice_directsound_compressed_reverse gDirectSound_Cry259_Wynaut
	voice_directsound_compressed_reverse gDirectSound_Cry260_Seviper
	voice_directsound_compressed_reverse gDirectSound_Cry261_Sharpedo
	voice_directsound_compressed_reverse gDirectSound_Cry262_Zangoose
	voice_directsound_compressed_reverse gDirectSound_Cry263_Azurill
	voice_directsound_compressed_reverse gDirectSound_Cry264_Swablu
	voice_directsound_compressed_reverse gDirectSound_Cry265_Altaria
	voice_directsound_compressed_reverse gDirectSound_Cry266_Unused
	voice_directsound_compressed_reverse gDirectSound_Cry267_Taillow
	voice_directsound_compressed_reverse gDirectSound_Cry268_Swellow
	voice_directsound_compressed_reverse gDirectSound_Cry269_Unused
	voice_directsound_compressed_reverse gDirectSound_Cry270_Spinda
	voice_directsound_compressed_reverse gDirectSound_Cry271_Torchic
	voice_directsound_compressed_reverse gDirectSound_Cry272_Combusken
	voice_directsound_compressed_reverse gDirectSound_Cry273_Blaziken
	voice_directsound_compressed_reverse gDirectSound_Cry274_Treecko
	voice_directsound_compressed_reverse gDirectSound_Cry275_Grovyle
	voice_directsound_compressed_reverse gDirectSound_Cry276_Sceptile
	voice_directsound_compressed_reverse gDirectSound_Cry277_Mudkip
	voice_directsound_compressed_reverse gDirectSound_Cry278_Marshtomp
	voice_directsound_compressed_reverse gDirectSound_Cry279_Swampert
	voice_directsound_compressed_reverse gDirectSound_Cry280_Pelipper
	voice_directsound_compressed_reverse gDirectSound_Cry281_Wingull
	voice_directsound_compressed_reverse gDirectSound_Cry282_Banette
	voice_directsound_compressed_reverse gDirectSound_Cry283_Shuppet
	voice_directsound_compressed_reverse gDirectSound_Cry284_Lotad
	voice_directsound_compressed_reverse gDirectSound_Cry285_Lombre
	voice_directsound_compressed_reverse gDirectSound_Cry286_Ludicolo
	voice_directsound_compressed_reverse gDirectSound_Cry287_Seedot
	voice_directsound_compressed_reverse gDirectSound_Cry288_Nuzleaf
	voice_directsound_compressed_reverse gDirectSound_Cry289_Shiftry
	voice_directsound_compressed_reverse gDirectSound_Cry290_Carvanha
	voice_directsound_compressed_reverse gDirectSound_Cry291_Wurmple
	voice_directsound_compressed_reverse gDirectSound_Cry292_Silcoon
	voice_directsound_compressed_reverse gDirectSound_Cry293_Beautifly
	voice_directsound_compressed_reverse gDirectSound_Cry294_Cascoon
	voice_directsound_compressed_reverse gDirectSound_Cry295_Dustox
	voice_directsound_compressed_reverse gDirectSound_Cry296_Ralts
	voice_directsound_compressed_reverse gDirectSound_Cry297_Kirlia
	voice_directsound_compressed_reverse gDirectSound_Cry298_Gardevoir
	voice_directsound_compressed_reverse gDirectSound_Cry299_Slakoth
	voice_directsound_compressed_reverse gDirectSound_Cry300_Vigoroth
	voice_directsound_compressed_reverse gDirectSound_Cry301_Slaking
	voice_directsound_compressed_reverse gDirectSound_Cry302_Nincada
	voice_directsound_compressed_reverse gDirectSound_Cry303_Ninjask
	voice_directsound_compressed_reverse gDirectSound_Cry304_Shedinja
	voice_directsound_compressed_reverse gDirectSound_Cry305_Makuhita
	voice_directsound_compressed_reverse gDirectSound_Cry306_Hariyama
	voice_directsound_compressed_reverse gDirectSound_Cry307_Nosepass
	voice_directsound_compressed_reverse gDirectSound_Cry308_Glalie
	voice_directsound_compressed_reverse gDirectSound_Cry309_Plusle
	voice_directsound_compressed_reverse gDirectSound_Cry310_Minun
	voice_directsound_compressed_reverse gDirectSound_Cry311_Surskit
	voice_directsound_compressed_reverse gDirectSound_Cry312_Masquerain
	voice_directsound_compressed_reverse gDirectSound_Cry313_Skitty
	voice_directsound_compressed_reverse gDirectSound_Cry314_Delcatty
	voice_directsound_compressed_reverse gDirectSound_Cry315_Gulpin
	voice_directsound_compressed_reverse gDirectSound_Cry316_Swalot
	voice_directsound_compressed_reverse gDirectSound_Cry317_Numel
	voice_directsound_compressed_reverse gDirectSound_Cry318_Camerupt
	voice_directsound_compressed_reverse gDirectSound_Cry319_Barboach
	voice_directsound_compressed_reverse gDirectSound_Cry320_Whiscash
	voice_directsound_compressed_reverse gDirectSound_Cry321_Corphish
	voice_directsound_compressed_reverse gDirectSound_Cry322_Crawdaunt
	voice_directsound_compressed_reverse gDirectSound_Cry323_Spoink
	voice_directsound_compressed_reverse gDirectSound_Cry324_Grumpig
	voice_directsound_compressed_reverse gDirectSound_Cry325_Trapinch
	voice_directsound_compressed_reverse gDirectSound_Cry326_Vibrava
	voice_directsound_compressed_reverse gDirectSound_Cry327_Flygon
	voice_directsound_compressed_reverse gDirectSound_Cry328_Cacnea
	voice_directsound_compressed_reverse gDirectSound_Cry329_Cacturne
	voice_directsound_compressed_reverse gDirectSound_Cry330_Baltoy
	voice_directsound_compressed_reverse gDirectSound_Cry331_Claydol
	voice_directsound_compressed_reverse gDirectSound_Cry332_Lunatone
	voice_directsound_compressed_reverse gDirectSound_Cry333_Solrock
	voice_directsound_compressed_reverse gDirectSound_Cry334_Feebas
	voice_directsound_compressed_reverse gDirectSound_Cry335_Milotic
	voice_directsound_compressed_reverse gDirectSound_Cry336_Absol
	voice_directsound_compressed_reverse gDirectSound_Cry337_Meditite
	voice_directsound_compressed_reverse gDirectSound_Cry338_Medicham
	voice_directsound_compressed_reverse gDirectSound_Cry339_Spheal
	voice_directsound_compressed_reverse gDirectSound_Cry340_Sealeo
	voice_directsound_compressed_reverse gDirectSound_Cry341_Walrein
	voice_directsound_compressed_reverse gDirectSound_Cry342_Clamperl
	voice_directsound_compressed_reverse gDirectSound_Cry343_Huntail
	voice_directsound_compressed_reverse gDirectSound_Cry344_Gorebyss
	voice_directsound_compressed_reverse gDirectSound_Cry345_Lileep
	voice_directsound_compressed_reverse gDirectSound_Cry346_Cradily
	voice_directsound_compressed_reverse gDirectSound_Cry347_Anorith
	voice_directsound_compressed_reverse gDirectSound_Cry348_Armaldo
	voice_directsound_compressed_reverse gDirectSound_Cry349_Beldum
	voice_directsound_compressed_reverse gDirectSound_Cry350_Metang
	voice_directsound_compressed_reverse gDirectSound_Cry351_Metagross
	voice_directsound_compressed_reverse gDirectSound_Cry352_Bagon
	voice_directsound_compressed_reverse gDirectSound_Cry353_Shelgon
	voice_directsound_compressed_reverse gDirectSound_Cry354_Regirock
	voice_directsound_compressed_reverse gDirectSound_Cry355_Regice
	voice_directsound_compressed_reverse gDirectSound_Cry356_Registeel
	voice_directsound_compressed_reverse gDirectSound_Cry357_Castform
	voice_directsound_compressed_reverse gDirectSound_Cry358_Volbeat
	voice_directsound_compressed_reverse gDirectSound_Cry359_Illumise
	voice_directsound_compressed_reverse gDirectSound_Cry360_Poochyena
	voice_directsound_compressed_reverse gDirectSound_Cry361_Mightyena
	voice_directsound_compressed_reverse gDirectSound_Cry362_Dusclops
	voice_directsound_compressed_reverse gDirectSound_Cry363_Sableye
	voice_directsound_compressed_reverse gDirectSound_Cry364_Mawile
	voice_directsound_compressed_reverse gDirectSound_Cry365_Aron
	voice_directsound_compressed_reverse gDirectSound_Cry366_Lairon
	voice_directsound_compressed_reverse gDirectSound_Cry367_Aggron
	voice_directsound_compressed_reverse gDirectSound_Cry368_Relicanth
	voice_directsound_compressed_reverse gDirectSound_Cry369_Luvdisc
	voice_directsound_compressed_reverse gDirectSound_Cry370_Groudon
	voice_directsound_compressed_reverse gDirectSound_Cry371_Kyogre
	voice_directsound_compressed_reverse gDirectSound_Cry372_Rayquaza
	voice_directsound_compressed_reverse gDirectSound_Cry373_Salamence
	voice_directsound_compressed_reverse gDirectSound_Cry374_Breloom
	voice_directsound_compressed_reverse gDirectSound_Cry375_Shroomish
	voice_directsound_compressed_reverse gDirectSound_Cry376_Linoone
	voice_directsound_compressed_reverse gDirectSound_Cry377_Tropius
	voice_directsound_compressed_reverse gDirectSound_Cry378_Wailmer
	voice_directsound_compressed_reverse gDirectSound_Cry379_Zigzagoon
	voice_directsound_compressed_reverse gDirectSound_Cry380_Exploud
	voice_directsound_compressed_reverse gDirectSound_Cry381_Loured
	voice_directsound_compressed_reverse gDirectSound_Cry382_Wailord
	voice_directsound_compressed_reverse gDirectSound_Cry383_Whismur
	voice_directsound_compressed_reverse gDirectSound_Cry384_Snorunt
	voice_directsound_compressed_reverse gDirectSound_Cry385_Latios
	voice_directsound_compressed_reverse gDirectSound_Cry386_Jirachi
	voice_directsound_compressed_reverse gDirectSound_Cry387_Deoxys
	voice_directsound_compressed_reverse gDirectSound_Cry388_Chimecho

@ Due to the way mks4agb (Nintendo's tool) works, key split table labels can
@ appear before the actual start of the key split table data. If you look at
@ the first keysplit table (keysplit_piano), you'll notice it's offset backwards
@ by 36 bytes. This is because the key split tables don't map instruments
@ for the entire note range (0-127)--they only map subsets, and the upper
@ and lower ranges aren't necessarily 0 or 127.
@
@ For example if a key split table maps an note range of 10-20, then the key
@ split table label will be offset 10 bytes before the actual key split data
@ begins. Therefore, the notes naturally map to the key split table without
@ any extra offset calculation.

keysplit gUnknown_08534BC0, 36
	split 0, 55
	split 1, 70
	split 2, 91
	split 3, 108

keysplit gUnknown_08534C08, 36
	split 0, 69
	split 1, 81
	split 2, 108

keysplit gUnknown_08534C50, 36
	split 0, 66
	split 1, 84
	split 2, 108

keysplit gUnknown_08534C98, 24
	split 0, 42
	split 1, 108

keysplit gUnknown_08534CEC, 36
	split 0, 66
	split 1, 108

gUnknown_08534D34:: @ 0x087C66D4
	.incbin "sound/programmable_wave_samples/gUnknown_08534D34.pcm"

gUnknown_08534D44:: @ 0x087C66E4
	.incbin "sound/programmable_wave_samples/gUnknown_08534D44.pcm"

gUnknown_08534D54:: @ 0x087C66F4
	.incbin "sound/programmable_wave_samples/gUnknown_08534D54.pcm"

gUnknown_08534D64:: @ 0x087C6704
	.incbin "sound/programmable_wave_samples/gUnknown_08534D64.pcm"

gUnknown_08534D74:: @ 0x087C6714
	.incbin "sound/programmable_wave_samples/gUnknown_08534D74.pcm"

gUnknown_08534D84:: @ 0x087C6724
	.incbin "sound/programmable_wave_samples/gUnknown_08534D84.pcm"

gUnknown_08534D94:: @ 0x087C6734
	.incbin "sound/programmable_wave_samples/gUnknown_08534D94.pcm"

gUnknown_08534DA4:: @ 0x087C6744
	.incbin "sound/programmable_wave_samples/gUnknown_08534DA4.pcm"

gUnknown_08534DB4:: @ 0x087C6754
	.incbin "sound/programmable_wave_samples/gUnknown_08534DB4.pcm"

gUnknown_08534DC4:: @ 0x087C6764
	.incbin "sound/programmable_wave_samples/gUnknown_08534DC4.pcm"


	.equiv NUM_TRACKS_BGM, 10
	.equiv NUM_TRACKS_SE1, 3
	.equiv NUM_TRACKS_SE2, 3
	.equiv NUM_TRACKS_SE3, 2

	.align 2
gMPlayTable:: @ 0x087C6774
	music_player gMPlayInfo_BGM, gMPlayTrack_BGM, NUM_TRACKS_BGM, 0
	music_player gMPlayInfo_SE1, gMPlayTrack_SE1, NUM_TRACKS_SE1, 0
	music_player gMPlayInfo_SE2, gMPlayTrack_SE2, NUM_TRACKS_SE2, 0
	music_player gMPlayInfo_SE3, gMPlayTrack_SE3, NUM_TRACKS_SE3, 0

.include "sound/MPlayDef.s"

.equiv MUSIC_PLAYER_BGM, 0
.equiv MUSIC_PLAYER_SE1, 1
.equiv MUSIC_PLAYER_SE2, 2
.equiv MUSIC_PLAYER_SE3, 3

	.align 2
gSongTable:: @ 0x087C67A4
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_title, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_table_select, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_ereader, MUSIC_PLAYER_BGM, 0
	song mus_unk_6, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_opening, MUSIC_PLAYER_BGM, 0
	song mus_high_score, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_shop, MUSIC_PLAYER_BGM, 0
	song mus_slots_prize, MUSIC_PLAYER_BGM, 0
	song mus_end_of_ball, MUSIC_PLAYER_BGM, 0
	song mus_bonus_chance, MUSIC_PLAYER_BGM, 0
	song mus_bonus_chance_legendary, MUSIC_PLAYER_BGM, 0
	song mus_travel_mode_start, MUSIC_PLAYER_BGM, 0
	song mus_success, MUSIC_PLAYER_BGM, 0
	song mus_success2, MUSIC_PLAYER_BGM, 0
	song mus_end_of_ball2, MUSIC_PLAYER_BGM, 0
	song mus_prize_awarded, MUSIC_PLAYER_BGM, 0
	song mus_egg_mode, MUSIC_PLAYER_BGM, 0
	song mus_egg_mode_start, MUSIC_PLAYER_BGM, 0
	song mus_travel_mode, MUSIC_PLAYER_BGM, 0
	song mus_unk_18, MUSIC_PLAYER_BGM, 0
	song mus_hurry_up, MUSIC_PLAYER_BGM, 0
	song mus_evolution, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_field_ruby, MUSIC_PLAYER_BGM, 0
	song mus_catch_em_mode, MUSIC_PLAYER_BGM, 0
	song mus_evo_mode, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_field_sapphire, MUSIC_PLAYER_BGM, 0
	song mus_catch_em_mode2, MUSIC_PLAYER_BGM, 0
	song mus_evo_mode2, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_bonus_field_kecleon, MUSIC_PLAYER_BGM, 0
	song mus_bonus_field_duskull, MUSIC_PLAYER_BGM, 0
	song mus_bonus_field_dusclops, MUSIC_PLAYER_BGM, 0
	song mus_bonus_field_spheal, MUSIC_PLAYER_BGM, 0
	song mus_bonus_field_groudon, MUSIC_PLAYER_BGM, 0
	song mus_bonus_field_kyogre, MUSIC_PLAYER_BGM, 0
	song mus_bonus_field_rayquaza, MUSIC_PLAYER_BGM, 0
	song mus_success3, MUSIC_PLAYER_BGM, 0
	song mus_end_of_ball3, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_pokedex, MUSIC_PLAYER_BGM, 0
	song mus_jirachi, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_field_ruby2, MUSIC_PLAYER_BGM, 0
	song mus_field_sapphire2, MUSIC_PLAYER_BGM, 0
	song mus_unk_5d, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_menu_select, MUSIC_PLAYER_SE2, 2
	song se_menu_cancel, MUSIC_PLAYER_SE2, 2
	song se_menu_move, MUSIC_PLAYER_SE2, 2
	song se_menu_popup_open, MUSIC_PLAYER_SE2, 2
	song se_menu_popup_close, MUSIC_PLAYER_SE2, 2
	song se_score_entry_a_b_move, MUSIC_PLAYER_SE2, 2
	song se_score_entry_letter_change, MUSIC_PLAYER_SE2, 2
	song se_unused_0x6c, MUSIC_PLAYER_SE2, 2
	song se_dex_info_field_select_move, MUSIC_PLAYER_SE2, 2
	song se_unused_0x6e, MUSIC_PLAYER_SE2, 2
	song se_unused_0x6f, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_unk_71, MUSIC_PLAYER_SE2, 2
	song se_flipper_pressed, MUSIC_PLAYER_SE3, 3
	song se_slingshot_hit, MUSIC_PLAYER_SE2, 2
	song se_pokemon_catch_hit, MUSIC_PLAYER_SE2, 2
	song se_pichu_in_position_chirp, MUSIC_PLAYER_SE2, 2
	song se_trigger_button_hit, MUSIC_PLAYER_SE2, 2
	song se_wall_hit, MUSIC_PLAYER_SE3, 3
	song se_tilt_triggered, MUSIC_PLAYER_SE3, 3
	song se_pika_spinner_clack, MUSIC_PLAYER_SE2, 2
	song se_pika_full_charge_1_up, MUSIC_PLAYER_SE2, 2
	song se_unk_7b, MUSIC_PLAYER_SE2, 2
	song se_kickback_thunderwave, MUSIC_PLAYER_SE2, 2
	song se_unused_0x7d, MUSIC_PLAYER_SE2, 2
	song se_coin_collected, MUSIC_PLAYER_SE2, 2
	song se_unused_0x7f, MUSIC_PLAYER_SE2, 2
	song se_center_hole_eject, MUSIC_PLAYER_SE2, 2
	song se_roulette_tick, MUSIC_PLAYER_SE2, 2
	song se_evo_selection_move, MUSIC_PLAYER_SE2, 2
	song se_evo_selection_confirm, MUSIC_PLAYER_SE2, 2
	song se_evo_item_appear, MUSIC_PLAYER_SE2, 2
	song se_evo_item_finish_appear, MUSIC_PLAYER_SE2, 2
	song se_evo_item_collected, MUSIC_PLAYER_SE2, 2
	song se_ball_upgrade, MUSIC_PLAYER_SE2, 2
	song se_unused_0x88, MUSIC_PLAYER_SE2, 2
	song se_unused_0x89, MUSIC_PLAYER_SE2, 2
	song se_failure, MUSIC_PLAYER_SE2, 2
	song se_catch_evo_banner, MUSIC_PLAYER_SE2, 2
	song se_catch_tile_reveal, MUSIC_PLAYER_SE2, 2
	song se_catch_all_reveal_lightning, MUSIC_PLAYER_SE2, 2
	song se_catch_all_reveal_shatter, MUSIC_PLAYER_SE2, 2
	song se_shop_list_reveal, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_bonus_score_tallied, MUSIC_PLAYER_SE2, 2
	song se_hatch_flourish, MUSIC_PLAYER_SE2, 2
	song se_area_roulette_selected, MUSIC_PLAYER_SE2, 2
	song se_ball_saved, MUSIC_PLAYER_SE2, 2
	song se_lati_delivery, MUSIC_PLAYER_SE2, 2
	song se_saver_plunger_drop, MUSIC_PLAYER_SE2, 2
	song se_travel_painter_flight, MUSIC_PLAYER_SE2, 2
	song se_travel_painter_paints, MUSIC_PLAYER_SE2, 2
	song se_evo_get_arrow_earned, MUSIC_PLAYER_SE2, 2
	song se_mon_catch_ball_woosh, MUSIC_PLAYER_SE2, 2
	song se_mon_catch_energy_beam, MUSIC_PLAYER_SE2, 2
	song se_mon_catch_ball_close, MUSIC_PLAYER_SE2, 2
	song se_mon_catch_ball_hit_ground, MUSIC_PLAYER_SE2, 2
	song se_mon_catch_ball_shake, MUSIC_PLAYER_SE2, 2
	song se_warp, MUSIC_PLAYER_SE2, 2
	song se_unused_0xa0, MUSIC_PLAYER_SE2, 2
	song se_ball_summary_text_progress, MUSIC_PLAYER_SE2, 2
	song se_ball_summary_page_swipe, MUSIC_PLAYER_SE2, 2
	song se_pause_cursor_move, MUSIC_PLAYER_SE2, 2
	song se_bonus_panel_slide, MUSIC_PLAYER_SE2, 2
	song se_pausing, MUSIC_PLAYER_SE2, 2
	song se_unpausing, MUSIC_PLAYER_SE2, 2
	song se_catch_mon_entity_appears, MUSIC_PLAYER_SE2, 2
	song se_pika_charge_do, MUSIC_PLAYER_SE2, 2
	song se_pika_charge_re, MUSIC_PLAYER_SE2, 2
	song se_pika_charge_mi, MUSIC_PLAYER_SE2, 2
	song se_pika_charge_fa, MUSIC_PLAYER_SE2, 2
	song se_pika_charge_so, MUSIC_PLAYER_SE2, 2
	song se_pika_charge_la, MUSIC_PLAYER_SE2, 2
	song se_pika_charge_ti, MUSIC_PLAYER_SE2, 2
	song se_pika_charge_high_do, MUSIC_PLAYER_SE2, 2
	song se_evo_cutscene_mon_portrait_change, MUSIC_PLAYER_SE2, 2
	song se_pikachu_kickback, MUSIC_PLAYER_SE2, 2
	song se_pichu_kickback_enabled, MUSIC_PLAYER_SE2, 2
	song se_pichu_kickback, MUSIC_PLAYER_SE2, 2
	song se_unused_0xb4, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_bumper_hit, MUSIC_PLAYER_SE2, 2
	song se_cyndaquil_egg_guard_hit, MUSIC_PLAYER_SE2, 2
	song se_aerodactyl_egg_flight, MUSIC_PLAYER_SE2, 2
	song se_cyndaquil_ball_eject_after_egg_arrival, MUSIC_PLAYER_SE2, 2
	song se_unused_0xba, MUSIC_PLAYER_SE2, 2
	song se_unused_0xbb, MUSIC_PLAYER_SE2, 2
	song se_unused_0xbc, MUSIC_PLAYER_SE2, 2
	song se_ruby_mart_gate_open, MUSIC_PLAYER_SE2, 2
	song se_unused_0xbe, MUSIC_PLAYER_SE2, 2
	song se_unused_0xbf, MUSIC_PLAYER_SE2, 2
	song se_unused_0xc0, MUSIC_PLAYER_SE2, 2
	song se_unused_0xc1, MUSIC_PLAYER_SE2, 2
	song se_sharpedo_ball_eject, MUSIC_PLAYER_SE2, 2
	song se_shop_eject, MUSIC_PLAYER_SE2, 2
	song se_unused_0xc4, MUSIC_PLAYER_SE2, 2
	song se_makuhita_punch, MUSIC_PLAYER_SE2, 2
	song se_chikorita_leaf_blade, MUSIC_PLAYER_SE2, 2
	song se_zigzagoon_emerge, MUSIC_PLAYER_SE2, 2
	song se_ruby_bumper_emerges, MUSIC_PLAYER_SE2, 2
	song se_ruby_bumper_leaves, MUSIC_PLAYER_SE2, 2
	song se_ruby_mart_sign_changed, MUSIC_PLAYER_SE2, 2
	song se_unused_0xcb, MUSIC_PLAYER_SE2, 2
	song se_spoink_launcher_charged, MUSIC_PLAYER_SE2, 2
	song se_spoink_launcher_fired, MUSIC_PLAYER_SE2, 2
	song se_sharpedo_bite, MUSIC_PLAYER_SE2, 2
	song se_nuzleaf_hit, MUSIC_PLAYER_SE2, 2
	song se_nuzleaf_teetering, MUSIC_PLAYER_SE2, 2
	song se_nuzleaf_forms_bridge, MUSIC_PLAYER_SE2, 2
	song se_gulpin_lands_or_leaves, MUSIC_PLAYER_SE2, 2
	song se_whiscash_emerge_splash, MUSIC_PLAYER_SE2, 2
	song se_whiscash_leave_burble, MUSIC_PLAYER_SE2, 2
	song se_whiscash_catch_ball, MUSIC_PLAYER_SE2, 2
	song se_whiscash_spit_ball, MUSIC_PLAYER_SE2, 2
	song se_whiscash_splashdown, MUSIC_PLAYER_SE2, 2
	song se_ramp_prize_collected, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_hatch_machine_spinner_trigger, MUSIC_PLAYER_SE2, 2
	song se_mon_lands_on_hatch_machine_top, MUSIC_PLAYER_SE2, 2
	song se_hatch_machine_stage_advance, MUSIC_PLAYER_SE2, 2
	song se_hatch_machine_egg_hatch, MUSIC_PLAYER_SE2, 2
	song se_hatch_machine_elevator, MUSIC_PLAYER_SE2, 2
	song se_hatch_machine_elevator_top, MUSIC_PLAYER_SE2, 2
	song se_pelipper_ball_grab, MUSIC_PLAYER_SE2, 2
	song se_pelipper_wing_flap, MUSIC_PLAYER_SE2, 2
	song se_pelipper_swoosh, MUSIC_PLAYER_SE2, 2
	song se_pelipper_ball_drop_lands, MUSIC_PLAYER_SE2, 2
	song se_sapphire_mart_gate_trigger, MUSIC_PLAYER_SE2, 2
	song se_sapphire_mart_gate_replaced, MUSIC_PLAYER_SE2, 2
	song se_sapphire_mart_gate_hit, MUSIC_PLAYER_SE2, 2
	song se_seedot_falling, MUSIC_PLAYER_SE2, 2
	song se_seedot_lands, MUSIC_PLAYER_SE2, 2
	song se_seedot_leaves, MUSIC_PLAYER_SE2, 2
	song se_zigzagoon_roulette_stop, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_duskull_appear, MUSIC_PLAYER_SE2, 2
	song se_duskull_death_cry, MUSIC_PLAYER_SE2, 2
	song se_dusclops_depart_incomplete, MUSIC_PLAYER_SE2, 2
	song se_dusclops_move, MUSIC_PLAYER_SE2, 2
	song se_dusclops_appear, MUSIC_PLAYER_SE2, 2
	song se_dusclops_hit, MUSIC_PLAYER_SE2, 2
	song se_dusclops_ball_absorb, MUSIC_PLAYER_SE2, 2
	song se_dusclops_ball_launch, MUSIC_PLAYER_SE2, 2
	song se_bonus_board_ball_spawn, MUSIC_PLAYER_SE2, 2
	song se_unused_0xfa, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_kecleon_side_look, MUSIC_PLAYER_SE2, 2
	song se_kecleon_vanish, MUSIC_PLAYER_SE2, 2
	song se_kecleon_startled, MUSIC_PLAYER_SE2, 2
	song se_kecleon_running, MUSIC_PLAYER_SE2, 2
	song se_kecleon_knocked_over, MUSIC_PLAYER_SE2, 2
	song se_kecleon_hit_damaged, MUSIC_PLAYER_SE2, 2
	song se_kecleon_hits_ground_defeated, MUSIC_PLAYER_SE2, 2
	song se_kecleon_seeing_stars, MUSIC_PLAYER_SE2, 2
	song se_kecleon_tree_hit, MUSIC_PLAYER_SE2, 2
	song se_kecleon_scope_fall, MUSIC_PLAYER_SE2, 2
	song se_kecleon_scope_activated, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_kyogre_hit, MUSIC_PLAYER_SE2, 2
	song se_kyogre_breach_surface, MUSIC_PLAYER_SE2, 2
	song se_kyogre_dive, MUSIC_PLAYER_SE2, 2
	song se_kyogre_spawn_whirlpool, MUSIC_PLAYER_SE2, 2
	song se_kyogre_freeze_ring, MUSIC_PLAYER_SE2, 2
	song se_kyogre_departs, MUSIC_PLAYER_SE2, 2
	song se_kyogre_freeze_hits_ball, MUSIC_PLAYER_SE2, 2
	song se_kyogre_freeze_crack, MUSIC_PLAYER_SE2, 2
	song se_kyogre_freeze_escaped, MUSIC_PLAYER_SE2, 2
	song se_kyogre_whirlpool_grabs_ball, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_groudon_hit, MUSIC_PLAYER_SE2, 2
	song se_groudon_step, MUSIC_PLAYER_SE2, 2
	song se_groudon_intro_leap, MUSIC_PLAYER_SE2, 2
	song se_groudon_lands, MUSIC_PLAYER_SE2, 2
	song se_groudon_spits_fire, MUSIC_PLAYER_SE2, 2
	song se_groudon_fire_ring, MUSIC_PLAYER_SE2, 2
	song se_groudon_fire_grab_resist, MUSIC_PLAYER_SE2, 2
	song se_groudon_fire_grab, MUSIC_PLAYER_SE2, 2
	song se_groudon_fireball_connects, MUSIC_PLAYER_SE2, 2
	song se_groudon_boulder_land, MUSIC_PLAYER_SE2, 2
	song se_groudon_dustorm_lift, MUSIC_PLAYER_SE2, 2
	song se_groudon_ball_hit_fire, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_rayquaza_hit, MUSIC_PLAYER_SE2, 2
	song se_rayquaza_wind, MUSIC_PLAYER_SE2, 2
	song se_rayquaza_lightning_charge, MUSIC_PLAYER_SE2, 2
	song se_rayquaza_flyby, MUSIC_PLAYER_SE2, 2
	song se_rayquaza_lightning_trap, MUSIC_PLAYER_SE2, 2
	song se_rayquaza_whirlwind_ball_launch, MUSIC_PLAYER_SE2, 2
	song se_rayquaza_whirlwind_ball_land, MUSIC_PLAYER_SE2, 2
	song se_rayquaza_sonic_boom, MUSIC_PLAYER_SE2, 2
	song se_rayquaza_stage_wind, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_spheal_surfacing, MUSIC_PLAYER_SE2, 2
	song se_spheal_submerging, MUSIC_PLAYER_SE2, 2
	song se_spheal_submerging_after_scoring, MUSIC_PLAYER_SE2, 2
	song se_spheal_hit, MUSIC_PLAYER_SE2, 2
	song se_spheal_net_swoosh, MUSIC_PLAYER_SE2, 2
	song se_spheal_crowd_cheer, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_spheal_end_whistle, MUSIC_PLAYER_SE2, 2
	song se_sealeo_hit_thud, MUSIC_PLAYER_SE2, 2
	song se_sealeo_nose_bounce, MUSIC_PLAYER_SE2, 2
	song se_spheal_land_under_net, MUSIC_PLAYER_SE2, 2
	song se_unused_0x13f, MUSIC_PLAYER_SE2, 2
	song se_spheal_surface_at_ramp, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_pika_no_kickback, MUSIC_PLAYER_SE2, 2
	song mus_dummy, MUSIC_PLAYER_BGM, 0
	song se_jirachi_move, MUSIC_PLAYER_SE2, 2
	song se_jirachi_hit, MUSIC_PLAYER_SE2, 2
	song se_totodile_lowers_rope, MUSIC_PLAYER_SE2, 2
	song se_totodile_slides_down, MUSIC_PLAYER_SE2, 2
	song se_totodile_places_egg, MUSIC_PLAYER_SE2, 2
	song se_totodile_climbs_rope, MUSIC_PLAYER_SE2, 2
	song se_highest_score_earned, MUSIC_PLAYER_SE2, 2
	song se_high_score_earned, MUSIC_PLAYER_SE2, 2
	song se_whiscash_earthquake, MUSIC_PLAYER_SE2, 2

.include "sound/songs/mus_dummy.s"

	.align 2
sc88pro_rnd_kick:: @ 0x087C7210
	.incbin "sound/direct_sound_samples/sc88pro_rnd_kick.bin"

	.align 2
gDirectSound_08535D10:: @ 0x087C76B0
	.incbin "sound/direct_sound_samples/gDirectSound_08535D10.bin"

	.align 2
gDirectSound_08536404:: @ 0x087C7DA4
	.incbin "sound/direct_sound_samples/gDirectSound_08536404.bin"

	.align 2
sc88pro_orchestra_snare:: @ 0x087C8634
	.incbin "sound/direct_sound_samples/sc88pro_orchestra_snare.bin"

	.align 2
sc55_tom:: @ 0x087C8EAC
	.incbin "sound/direct_sound_samples/sc55_tom.bin"

	.align 2
unknown_close_hihat:: @ 0x087C9EEC
	.incbin "sound/direct_sound_samples/unknown_close_hihat.bin"

	.align 2
unknown_open_hihat:: @ 0x087CA300
	.incbin "sound/direct_sound_samples/unknown_open_hihat.bin"

	.align 2
sc88pro_orchestra_cymbal_crash:: @ 0x087CB130
	.incbin "sound/direct_sound_samples/sc88pro_orchestra_cymbal_crash.bin"

	.align 2
unknown_bell:: @ 0x087CC05C
	.incbin "sound/direct_sound_samples/unknown_bell.bin"

	.align 2
sc88pro_tambourine:: @ 0x087CCFF0
	.incbin "sound/direct_sound_samples/sc88pro_tambourine.bin"

	.align 2
trinity_cymbal_crash:: @ 0x087CD8A4
	.incbin "sound/direct_sound_samples/trinity_cymbal_crash.bin"

	.align 2
sc88pro_mute_high_conga:: @ 0x087CE188
	.incbin "sound/direct_sound_samples/sc88pro_mute_high_conga.bin"

	.align 2
sc88pro_open_low_conga:: @ 0x087CE6A0
	.incbin "sound/direct_sound_samples/sc88pro_open_low_conga.bin"

	.align 2
sc88pro_piano1_48:: @ 0x087CEC68
	.incbin "sound/direct_sound_samples/sc88pro_piano1_48.bin"

	.align 2
sc88pro_piano1_60:: @ 0x087CFBC8
	.incbin "sound/direct_sound_samples/sc88pro_piano1_60.bin"

	.align 2
sc88pro_piano1_72:: @ 0x087D1228
	.incbin "sound/direct_sound_samples/sc88pro_piano1_72.bin"

	.align 2
sc88pro_piano1_84:: @ 0x087D2784
	.incbin "sound/direct_sound_samples/sc88pro_piano1_84.bin"

	.align 2
sc88pro_string_ensemble_60:: @ 0x087D3310
	.incbin "sound/direct_sound_samples/sc88pro_string_ensemble_60.bin"

	.align 2
sc88pro_string_ensemble_72:: @ 0x087D68B4
	.incbin "sound/direct_sound_samples/sc88pro_string_ensemble_72.bin"

	.align 2
sc88pro_string_ensemble_84:: @ 0x087D8BD0
	.incbin "sound/direct_sound_samples/sc88pro_string_ensemble_84.bin"

	.align 2
sc88pro_trumpet_60:: @ 0x087DC29C
	.incbin "sound/direct_sound_samples/sc88pro_trumpet_60.bin"

	.align 2
sc88pro_trumpet_72:: @ 0x087DD5EC
	.incbin "sound/direct_sound_samples/sc88pro_trumpet_72.bin"

	.align 2
sc88pro_trumpet_84:: @ 0x087DEAFC
	.incbin "sound/direct_sound_samples/sc88pro_trumpet_84.bin"

	.align 2
sc88pro_tuba_39:: @ 0x087DFF1C
	.incbin "sound/direct_sound_samples/sc88pro_tuba_39.bin"

	.align 2
sc88pro_tuba_51:: @ 0x087E0FB8
	.incbin "sound/direct_sound_samples/sc88pro_tuba_51.bin"

	.align 2
sc88pro_french_horn_60:: @ 0x087E2014
	.incbin "sound/direct_sound_samples/sc88pro_french_horn_60.bin"

	.align 2
sc88pro_french_horn_72:: @ 0x087E8FA8
	.incbin "sound/direct_sound_samples/sc88pro_french_horn_72.bin"

	.align 2
sc88pro_flute:: @ 0x087ED52C
	.incbin "sound/direct_sound_samples/sc88pro_flute.bin"

	.align 2
sc88pro_organ2:: @ 0x087EDC90
	.incbin "sound/direct_sound_samples/sc88pro_organ2.bin"

	.align 2
sc88pro_nylon_str_guitar:: @ 0x087EE488
	.incbin "sound/direct_sound_samples/sc88pro_nylon_str_guitar.bin"

	.align 2
gDirectSound_0855EA58:: @ 0x087F03F8
	.incbin "sound/direct_sound_samples/gDirectSound_0855EA58.bin"

	.align 2
unknown_synth_snare:: @ 0x087F0BCC
	.incbin "sound/direct_sound_samples/unknown_synth_snare.bin"

	.align 2
sc88pro_square_wave:: @ 0x087F15D8
	.incbin "sound/direct_sound_samples/sc88pro_square_wave.bin"

	.align 2
sc88pro_timpani:: @ 0x087F31EC
	.incbin "sound/direct_sound_samples/sc88pro_timpani.bin"

	.align 2
bicycle_bell:: @ 0x087F46BC
	.incbin "sound/direct_sound_samples/bicycle_bell.bin"

	.align 2
sc88pro_glockenspiel:: @ 0x087F601C
	.incbin "sound/direct_sound_samples/sc88pro_glockenspiel.bin"

	.align 2
gDirectSound_08564D20:: @ 0x087F66C0
	.incbin "sound/direct_sound_samples/gDirectSound_08564D20.bin"

	.align 2
sc88pro_pizzicato_strings:: @ 0x087F7B84
	.incbin "sound/direct_sound_samples/sc88pro_pizzicato_strings.bin"

	.align 2
gDirectSound_08566920:: @ 0x087F82C0
	.incbin "sound/direct_sound_samples/gDirectSound_08566920.bin"

	.align 2
gDirectSound_08568510:: @ 0x087F9EB0
	.incbin "sound/direct_sound_samples/gDirectSound_08568510.bin"

	.align 2
gDirectSound_085698C4:: @ 0x087FB264
	.incbin "sound/direct_sound_samples/gDirectSound_085698C4.bin"

	.align 2
sc88pro_wind:: @ 0x087FD8E8
	.incbin "sound/direct_sound_samples/sc88pro_wind.bin"

	.align 2
sc88pro_bubbles:: @ 0x087FEB2C
	.incbin "sound/direct_sound_samples/sc88pro_bubbles.bin"

	.align 2
gDirectSound_0856E19C:: @ 0x087FFB3C
	.incbin "sound/direct_sound_samples/gDirectSound_0856E19C.bin"

	.align 2
gDirectSound_0856F4A4:: @ 0x08800E44
	.incbin "sound/direct_sound_samples/gDirectSound_0856F4A4.bin"

	.align 2
trinity_30303_mega_bass:: @ 0x08802F50
	.incbin "sound/direct_sound_samples/trinity_30303_mega_bass.bin"

	.align 2
sc88pro_fretless_bass:: @ 0x08804F2C
	.incbin "sound/direct_sound_samples/sc88pro_fretless_bass.bin"

	.align 2
sc88pro_synth_bass:: @ 0x08805AF8
	.incbin "sound/direct_sound_samples/sc88pro_synth_bass.bin"

	.align 2
gDirectSound_08574DCC:: @ 0x0880676C
	.incbin "sound/direct_sound_samples/gDirectSound_08574DCC.bin"

	.align 2
gDirectSound_08576FDC:: @ 0x0880897C
	.incbin "sound/direct_sound_samples/gDirectSound_08576FDC.bin"

	.align 2
sc88pro_tubular_bell:: @ 0x08809148
	.incbin "sound/direct_sound_samples/sc88pro_tubular_bell.bin"

	.align 2
gDirectSound_08579118:: @ 0x0880AAB8
	.incbin "sound/direct_sound_samples/gDirectSound_08579118.bin"

	.align 2
trinity_big_boned:: @ 0x0880CA68
	.incbin "sound/direct_sound_samples/trinity_big_boned.bin"

	.align 2
sc88pro_harp:: @ 0x0880FD48
	.incbin "sound/direct_sound_samples/sc88pro_harp.bin"

	.align 2
sc88pro_xylophone:: @ 0x08810778
	.incbin "sound/direct_sound_samples/sc88pro_xylophone.bin"

	.align 2
sc88pro_slap_bass:: @ 0x088111AC
	.incbin "sound/direct_sound_samples/sc88pro_slap_bass.bin"

	.align 2
gDirectSound_08580744:: @ 0x088120E4
	.incbin "sound/direct_sound_samples/gDirectSound_08580744.bin"

	.align 2
gDirectSound_08582284:: @ 0x08813C24
	.incbin "sound/direct_sound_samples/gDirectSound_08582284.bin"

	.align 2
sc88pro_accordion:: @ 0x088144EC
	.incbin "sound/direct_sound_samples/sc88pro_accordion.bin"

	.align 2
gDirectSound_08583F1C:: @ 0x088158BC
	.incbin "sound/direct_sound_samples/gDirectSound_08583F1C.bin"

	.align 2
gDirectSound_08584B2C:: @ 0x088164CC
	.incbin "sound/direct_sound_samples/gDirectSound_08584B2C.bin"

	.align 2
gDirectSound_08588238:: @ 0x08819BD8
	.incbin "sound/direct_sound_samples/gDirectSound_08588238.bin"

	.align 2
gDirectSound_08588C10:: @ 0x0881A5B0
	.incbin "sound/direct_sound_samples/gDirectSound_08588C10.bin"

	.align 2
gDirectSound_0858AA14:: @ 0x0881C3B4
	.incbin "sound/direct_sound_samples/gDirectSound_0858AA14.bin"

	.align 2
gDirectSound_se_pikachu_kickback:: @ 0x0881FA18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_se_pikachu_kickback.bin"

	.align 2
gDirectSound_se_pika_no_kickback:: @ 0x0882761C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_se_pika_no_kickback.bin"

	.align 2
gDirectSound_se_pichu_kickback_enabled:: @ 0x08828B10
	.incbin "sound/direct_sound_samples/cries/gDirectSound_se_pichu_kickback_enabled.bin"

	.align 2
gDirectSound_se_pichu_kickback:: @ 0x0882D6F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_se_pichu_kickback.bin"

	.align 2
gDirectSound_085A37F4:: @ 0x08835194
	.incbin "sound/direct_sound_samples/gDirectSound_085A37F4.bin"

	.align 2
gDirectSound_085A3DF4:: @ 0x08835794
	.incbin "sound/direct_sound_samples/gDirectSound_085A3DF4.bin"

	.align 2
gDirectSound_085A45E0:: @ 0x08835F80
	.incbin "sound/direct_sound_samples/gDirectSound_085A45E0.bin"

	.align 2
gDirectSound_085A4FE4:: @ 0x08836984
	.incbin "sound/direct_sound_samples/gDirectSound_085A4FE4.bin"

	.align 2
gDirectSound_085A5934:: @ 0x088372D4
	.incbin "sound/direct_sound_samples/gDirectSound_085A5934.bin"

	.align 2
gDirectSound_085A5A74:: @ 0x08837414
	.incbin "sound/direct_sound_samples/gDirectSound_085A5A74.bin"

	.align 2
sc88pro_fingered_bass:: @ 0x08837ABC
	.incbin "sound/direct_sound_samples/sc88pro_fingered_bass.bin"

	.align 2
gDirectSound_085A7D6C:: @ 0x0883970C
	.incbin "sound/direct_sound_samples/gDirectSound_085A7D6C.bin"

	.align 2
gDirectSound_085A7EDC:: @ 0x0883987C
	.incbin "sound/direct_sound_samples/gDirectSound_085A7EDC.bin"

	.align 2
gDirectSound_085A8470:: @ 0x08839E10
	.incbin "sound/direct_sound_samples/gDirectSound_085A8470.bin"

	.align 2
gDirectSound_085A8788:: @ 0x0883A128
	.incbin "sound/direct_sound_samples/gDirectSound_085A8788.bin"

	.align 2
gDirectSound_085A9C78:: @ 0x0883B618
	.incbin "sound/direct_sound_samples/gDirectSound_085A9C78.bin"

	.align 2
gDirectSound_085A9EA4:: @ 0x0883B844
	.incbin "sound/direct_sound_samples/gDirectSound_085A9EA4.bin"

	.align 2

gDirectSound_085AA074:: @ 0x0883BA14
	.incbin "sound/direct_sound_samples/gDirectSound_085AA074.bin"

	.align 2
gDirectSound_085AA274:: @ 0x0883BC14
	.incbin "sound/direct_sound_samples/gDirectSound_085AA274.bin"

	.align 2
gDirectSound_085ABE38:: @ 0x0883D7D8
	.incbin "sound/direct_sound_samples/gDirectSound_085ABE38.bin"

	.align 2
gDirectSound_Cry025_Pikachu:: @ 0x0883D8DC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry025_Pikachu.bin"

	.align 2
gDirectSound_Cry026_Raichu:: @ 0x0883E984
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry026_Raichu.bin"

	.align 2
gDirectSound_Cry027_Sandshrew:: @ 0x08840144
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry027_Sandshrew.bin"

	.align 2
gDirectSound_Cry028_Sandslash:: @ 0x08840A98
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry028_Sandslash.bin"

	.align 2
gDirectSound_Cry037_Vulpix:: @ 0x08841828
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry037_Vulpix.bin"

	.align 2
gDirectSound_Cry038_Ninetales:: @ 0x08842FF8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry038_Ninetales.bin"

	.align 2
gDirectSound_Cry039_Jigglypuff:: @ 0x08844864
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry039_Jigglypuff.bin"

	.align 2
gDirectSound_Cry040_Wigglytuff:: @ 0x08844DC8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry040_Wigglytuff.bin"

	.align 2
gDirectSound_Cry041_Zubat:: @ 0x08845490
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry041_Zubat.bin"

	.align 2
gDirectSound_Cry042_Golbat:: @ 0x088467FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry042_Golbat.bin"

	.align 2
gDirectSound_Cry043_Oddish:: @ 0x08847B60
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry043_Oddish.bin"

	.align 2
gDirectSound_Cry044_Gloom:: @ 0x088489FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry044_Gloom.bin"

	.align 2
gDirectSound_Cry045_Vileplume:: @ 0x08849678
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry045_Vileplume.bin"

	.align 2
gDirectSound_Cry054_Psyduck:: @ 0x0884B014
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry054_Psyduck.bin"

	.align 2
gDirectSound_Cry055_Golduck:: @ 0x0884BD3C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry055_Golduck.bin"

	.align 2
gDirectSound_Cry063_Abra:: @ 0x0884C884
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry063_Abra.bin"

	.align 2
gDirectSound_Cry064_Kadabra:: @ 0x0884DFE8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry064_Kadabra.bin"

	.align 2
gDirectSound_Cry065_Alakazam:: @ 0x0884FAD0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry065_Alakazam.bin"

	.align 2
gDirectSound_Cry066_Machop:: @ 0x08851A6C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry066_Machop.bin"

	.align 2
gDirectSound_Cry067_Machoke:: @ 0x088527D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry067_Machoke.bin"

	.align 2
gDirectSound_Cry068_Machamp:: @ 0x08853560
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry068_Machamp.bin"

	.align 2
gDirectSound_Cry072_Tentacool:: @ 0x088545E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry072_Tentacool.bin"

	.align 2
gDirectSound_Cry073_Tentacruel:: @ 0x088555D8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry073_Tentacruel.bin"

	.align 2
gDirectSound_Cry074_Geodude:: @ 0x08856CD4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry074_Geodude.bin"

	.align 2
gDirectSound_Cry075_Graveler:: @ 0x08858488
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry075_Graveler.bin"

	.align 2
gDirectSound_Cry076_Golem:: @ 0x0885A070
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry076_Golem.bin"

	.align 2
gDirectSound_Cry081_Magnemite:: @ 0x0885AE9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry081_Magnemite.bin"

	.align 2
gDirectSound_Cry082_Magneton:: @ 0x0885C1E0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry082_Magneton.bin"

	.align 2
gDirectSound_Cry084_Doduo:: @ 0x0885D9C8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry084_Doduo.bin"

	.align 2
gDirectSound_Cry085_Dodrio:: @ 0x0885ED0C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry085_Dodrio.bin"

	.align 2
gDirectSound_Cry088_Grimer:: @ 0x08860084
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry088_Grimer.bin"

	.align 2
gDirectSound_Cry089_Muk:: @ 0x08860B0C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry089_Muk.bin"

	.align 2
gDirectSound_Cry100_Voltorb:: @ 0x088619CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry100_Voltorb.bin"

	.align 2
gDirectSound_Cry101_Electrode:: @ 0x08863290
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry101_Electrode.bin"

	.align 2
gDirectSound_Cry109_Koffing:: @ 0x08864BC8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry109_Koffing.bin"

	.align 2
gDirectSound_Cry110_Weezing:: @ 0x08866024
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry110_Weezing.bin"

	.align 2
gDirectSound_Cry111_Rhyhorn:: @ 0x088675D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry111_Rhyhorn.bin"

	.align 2
gDirectSound_Cry112_Rhydon:: @ 0x0886893C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry112_Rhydon.bin"

	.align 2
gDirectSound_Cry116_Horsea:: @ 0x08869DA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry116_Horsea.bin"

	.align 2
gDirectSound_Cry117_Seadra:: @ 0x0886A724
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry117_Seadra.bin"

	.align 2
gDirectSound_Cry118_Goldeen:: @ 0x0886AF90
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry118_Goldeen.bin"

	.align 2
gDirectSound_Cry119_Seaking:: @ 0x0886B968
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry119_Seaking.bin"

	.align 2
gDirectSound_Cry120_Staryu:: @ 0x0886CCC0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry120_Staryu.bin"

	.align 2
gDirectSound_Cry121_Starmie:: @ 0x0886E0A8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry121_Starmie.bin"

	.align 2
gDirectSound_Cry127_Pinsir:: @ 0x0886F584
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry127_Pinsir.bin"

	.align 2
gDirectSound_Cry129_Magikarp:: @ 0x088701E0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry129_Magikarp.bin"

	.align 2
gDirectSound_Cry130_Gyarados:: @ 0x088714E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry130_Gyarados.bin"

	.align 2
gDirectSound_Cry142_Aerodactyl:: @ 0x0887291C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry142_Aerodactyl.bin"

	.align 2
gDirectSound_Cry152_Chikorita:: @ 0x08874178
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry152_Chikorita.bin"

	.align 2
gDirectSound_Cry153_Bayleef:: @ 0x088746B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry153_Bayleef.bin"

	.align 2
gDirectSound_Cry154_Meganium:: @ 0x08874F84
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry154_Meganium.bin"

	.align 2
gDirectSound_Cry155_Cyndaquil:: @ 0x08875FBC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry155_Cyndaquil.bin"

	.align 2
gDirectSound_Cry156_Quilava:: @ 0x088766C0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry156_Quilava.bin"

	.align 2
gDirectSound_Cry157_Typhlosion:: @ 0x088772A8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry157_Typhlosion.bin"

	.align 2
gDirectSound_Cry158_Totodile:: @ 0x088798B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry158_Totodile.bin"

	.align 2
gDirectSound_Cry159_Croconaw:: @ 0x0887AB10
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry159_Croconaw.bin"

	.align 2
gDirectSound_Cry160_Feraligatr:: @ 0x0887BF4C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry160_Feraligatr.bin"

	.align 2
gDirectSound_Cry169_Crobat:: @ 0x0887D8D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry169_Crobat.bin"

	.align 2
gDirectSound_Cry170_Chinchou:: @ 0x0887F000
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry170_Chinchou.bin"

	.align 2
gDirectSound_Cry171_Lanturn:: @ 0x0887FCB0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry171_Lanturn.bin"

	.align 2
gDirectSound_Cry172_Pichu:: @ 0x0888073C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry172_Pichu.bin"

	.align 2
gDirectSound_Cry174_Igglybuff:: @ 0x08880E90
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry174_Igglybuff.bin"

	.align 2
gDirectSound_Cry177_Natu:: @ 0x0888158C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry177_Natu.bin"

	.align 2
gDirectSound_Cry178_Xatu:: @ 0x0888201C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry178_Xatu.bin"

	.align 2
gDirectSound_Cry182_Bellossom:: @ 0x08882EE8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry182_Bellossom.bin"

	.align 2
gDirectSound_Cry183_Marill:: @ 0x08883D00
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry183_Marill.bin"

	.align 2
gDirectSound_Cry184_Azumarill:: @ 0x08884A14
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry184_Azumarill.bin"

	.align 2
gDirectSound_Cry202_Wobbuffet:: @ 0x08885B00
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry202_Wobbuffet.bin"

	.align 2
gDirectSound_Cry203_Girafarig:: @ 0x08886F9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry203_Girafarig.bin"

	.align 2
gDirectSound_Cry214_Heracross:: @ 0x08887E50
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry214_Heracross.bin"

	.align 2
gDirectSound_Cry218_Slugma:: @ 0x088890A4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry218_Slugma.bin"

	.align 2
gDirectSound_Cry219_Magcargo:: @ 0x0888A1BC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry219_Magcargo.bin"

	.align 2
gDirectSound_Cry222_Corsola:: @ 0x0888B6C4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry222_Corsola.bin"

	.align 2
gDirectSound_Cry227_Skarmory:: @ 0x0888C3A4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry227_Skarmory.bin"

	.align 2
gDirectSound_Cry230_Kingdra:: @ 0x0888DBAC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry230_Kingdra.bin"

	.align 2
gDirectSound_Cry231_Phanpy:: @ 0x0888E984
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry231_Phanpy.bin"

	.align 2
gDirectSound_Cry232_Donphan:: @ 0x0888F4D4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry232_Donphan.bin"

	.align 2
gDirectSound_Cry251_Celebi:: @ 0x088905F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry251_Celebi.bin"

	.align 2
gDirectSound_Cry252_Kecleon:: @ 0x08891470
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry252_Kecleon.bin"

	.align 2
gDirectSound_Cry253_Roselia:: @ 0x08891CD0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry253_Roselia.bin"

	.align 2
gDirectSound_Cry254_Torkoal:: @ 0x08892790
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry254_Torkoal.bin"

	.align 2
gDirectSound_Cry255_Electrike:: @ 0x088930DC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry255_Electrike.bin"

	.align 2
gDirectSound_Cry256_Manectric:: @ 0x08893D38
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry256_Manectric.bin"

	.align 2
gDirectSound_Cry257_Duskull:: @ 0x08895240
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry257_Duskull.bin"

	.align 2
gDirectSound_Cry258_Latias:: @ 0x08895CD8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry258_Latias.bin"

	.align 2
gDirectSound_Cry259_Wynaut:: @ 0x08896908
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry259_Wynaut.bin"

	.align 2
gDirectSound_Cry260_Seviper:: @ 0x088976E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry260_Seviper.bin"

	.align 2
gDirectSound_Cry261_Sharpedo:: @ 0x08898288
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry261_Sharpedo.bin"

	.align 2
gDirectSound_Cry262_Zangoose:: @ 0x08899994
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry262_Zangoose.bin"

	.align 2
gDirectSound_Cry263_Azurill:: @ 0x0889A324
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry263_Azurill.bin"

	.align 2
gDirectSound_Cry264_Swablu:: @ 0x0889AD8C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry264_Swablu.bin"

	.align 2
gDirectSound_Cry265_Altaria:: @ 0x0889B324
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry265_Altaria.bin"

	.align 2
gDirectSound_Cry266_Unused:: @ 0x0889BE40
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry266_Unused.bin"

	.align 2
gDirectSound_Cry267_Taillow:: @ 0x0889C794
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry267_Taillow.bin"

	.align 2
gDirectSound_Cry268_Swellow:: @ 0x0889CD94
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry268_Swellow.bin"

	.align 2
gDirectSound_Cry269_Unused:: @ 0x0889D698
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry269_Unused.bin"

	.align 2
gDirectSound_Cry270_Spinda:: @ 0x0889E848
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry270_Spinda.bin"

	.align 2
gDirectSound_Cry271_Torchic:: @ 0x0889F4B4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry271_Torchic.bin"

	.align 2
gDirectSound_Cry272_Combusken:: @ 0x0889FE5C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry272_Combusken.bin"

	.align 2
gDirectSound_Cry273_Blaziken:: @ 0x088A1B30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry273_Blaziken.bin"

	.align 2
gDirectSound_Cry274_Treecko:: @ 0x088A3AB0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry274_Treecko.bin"

	.align 2
gDirectSound_Cry275_Grovyle:: @ 0x088A4658
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry275_Grovyle.bin"

	.align 2
gDirectSound_Cry276_Sceptile:: @ 0x088A5ACC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry276_Sceptile.bin"

	.align 2
gDirectSound_Cry277_Mudkip:: @ 0x088A74E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry277_Mudkip.bin"

	.align 2
gDirectSound_Cry278_Marshtomp:: @ 0x088A7C6C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry278_Marshtomp.bin"

	.align 2
gDirectSound_Cry279_Swampert:: @ 0x088A8D70
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry279_Swampert.bin"

	.align 2
gDirectSound_Cry280_Pelipper:: @ 0x088AA3F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry280_Pelipper.bin"

	.align 2
gDirectSound_Cry281_Wingull:: @ 0x088AAFB8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry281_Wingull.bin"

	.align 2
gDirectSound_Cry282_Banette:: @ 0x088ABBF8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry282_Banette.bin"

	.align 2
gDirectSound_Cry283_Shuppet:: @ 0x088AC8A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry283_Shuppet.bin"

	.align 2
gDirectSound_Cry284_Lotad:: @ 0x088AD0E0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry284_Lotad.bin"

	.align 2
gDirectSound_Cry285_Lombre:: @ 0x088AD548
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry285_Lombre.bin"

	.align 2
gDirectSound_Cry286_Ludicolo:: @ 0x088AE3DC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry286_Ludicolo.bin"

	.align 2
gDirectSound_Cry287_Seedot:: @ 0x088AF4AC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry287_Seedot.bin"

	.align 2
gDirectSound_Cry288_Nuzleaf:: @ 0x088AFCD8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry288_Nuzleaf.bin"

	.align 2
gDirectSound_Cry289_Shiftry:: @ 0x088B0840
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry289_Shiftry.bin"

	.align 2
gDirectSound_Cry290_Carvanha:: @ 0x088B1C04
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry290_Carvanha.bin"

	.align 2
gDirectSound_Cry291_Wurmple:: @ 0x088B2618
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry291_Wurmple.bin"

	.align 2
gDirectSound_Cry292_Silcoon:: @ 0x088B2EE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry292_Silcoon.bin"

	.align 2
gDirectSound_Cry293_Beautifly:: @ 0x088B3F10
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry293_Beautifly.bin"

	.align 2
gDirectSound_Cry294_Cascoon:: @ 0x088B4748
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry294_Cascoon.bin"

	.align 2
gDirectSound_Cry295_Dustox:: @ 0x088B578C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry295_Dustox.bin"

	.align 2
gDirectSound_Cry296_Ralts:: @ 0x088B6438
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry296_Ralts.bin"

	.align 2
gDirectSound_Cry297_Kirlia:: @ 0x088B6E54
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry297_Kirlia.bin"

	.align 2
gDirectSound_Cry298_Gardevoir:: @ 0x088B7A84
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry298_Gardevoir.bin"

	.align 2
gDirectSound_Cry299_Slakoth:: @ 0x088B92E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry299_Slakoth.bin"

	.align 2
gDirectSound_Cry300_Vigoroth:: @ 0x088B9B6C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry300_Vigoroth.bin"

	.align 2
gDirectSound_Cry301_Slaking:: @ 0x088BA9C4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry301_Slaking.bin"

	.align 2
gDirectSound_Cry302_Nincada:: @ 0x088BB3B0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry302_Nincada.bin"

	.align 2
gDirectSound_Cry303_Ninjask:: @ 0x088BBA20
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry303_Ninjask.bin"

	.align 2
gDirectSound_Cry304_Shedinja:: @ 0x088BC648
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry304_Shedinja.bin"

	.align 2
gDirectSound_Cry305_Makuhita:: @ 0x088BCE00
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry305_Makuhita.bin"

	.align 2
gDirectSound_Cry306_Hariyama:: @ 0x088BD55C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry306_Hariyama.bin"

	.align 2
gDirectSound_Cry307_Nosepass:: @ 0x088BE614
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry307_Nosepass.bin"

	.align 2
gDirectSound_Cry308_Glalie:: @ 0x088BF378
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry308_Glalie.bin"

	.align 2
gDirectSound_Cry309_Plusle:: @ 0x088C085C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry309_Plusle.bin"

	.align 2
gDirectSound_Cry310_Minun:: @ 0x088C1158
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry310_Minun.bin"

	.align 2
gDirectSound_Cry311_Surskit:: @ 0x088C2160
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry311_Surskit.bin"

	.align 2
gDirectSound_Cry312_Masquerain:: @ 0x088C2BE0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry312_Masquerain.bin"

	.align 2
gDirectSound_Cry313_Skitty:: @ 0x088C3F94
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry313_Skitty.bin"

	.align 2
gDirectSound_Cry314_Delcatty:: @ 0x088C46A8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry314_Delcatty.bin"

	.align 2
gDirectSound_Cry315_Gulpin:: @ 0x088C5BC0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry315_Gulpin.bin"

	.align 2
gDirectSound_Cry316_Swalot:: @ 0x088C63C4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry316_Swalot.bin"

	.align 2
gDirectSound_Cry317_Numel:: @ 0x088C7524
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry317_Numel.bin"

	.align 2
gDirectSound_Cry318_Camerupt:: @ 0x088C7E70
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry318_Camerupt.bin"

	.align 2
gDirectSound_Cry319_Barboach:: @ 0x088C9590
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry319_Barboach.bin"

	.align 2
gDirectSound_Cry320_Whiscash:: @ 0x088C9ECC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry320_Whiscash.bin"

	.align 2
gDirectSound_Cry321_Corphish:: @ 0x088CAFC8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry321_Corphish.bin"

	.align 2
gDirectSound_Cry322_Crawdaunt:: @ 0x088CBBCC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry322_Crawdaunt.bin"

	.align 2
gDirectSound_Cry323_Spoink:: @ 0x088CD484
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry323_Spoink.bin"

	.align 2
gDirectSound_Cry324_Grumpig:: @ 0x088CDBC4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry324_Grumpig.bin"

	.align 2
gDirectSound_Cry325_Trapinch:: @ 0x088CE864
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry325_Trapinch.bin"

	.align 2
gDirectSound_Cry326_Vibrava:: @ 0x088CF288
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry326_Vibrava.bin"

	.align 2
gDirectSound_Cry327_Flygon:: @ 0x088D008C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry327_Flygon.bin"

	.align 2
gDirectSound_Cry328_Cacnea:: @ 0x088D1A94
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry328_Cacnea.bin"

	.align 2
gDirectSound_Cry329_Cacturne:: @ 0x088D2384
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry329_Cacturne.bin"

	.align 2
gDirectSound_Cry330_Baltoy:: @ 0x088D3A34
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry330_Baltoy.bin"

	.align 2
gDirectSound_Cry331_Claydol:: @ 0x088D46B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry331_Claydol.bin"

	.align 2
gDirectSound_Cry332_Lunatone:: @ 0x088D5A18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry332_Lunatone.bin"

	.align 2
gDirectSound_Cry333_Solrock:: @ 0x088D7214
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry333_Solrock.bin"

	.align 2
gDirectSound_Cry334_Feebas:: @ 0x088D8240
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry334_Feebas.bin"

	.align 2
gDirectSound_Cry335_Milotic:: @ 0x088D8A14
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry335_Milotic.bin"

	.align 2
gDirectSound_Cry336_Absol:: @ 0x088DB158
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry336_Absol.bin"

	.align 2
gDirectSound_Cry337_Meditite:: @ 0x088DBBD4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry337_Meditite.bin"

	.align 2
gDirectSound_Cry338_Medicham:: @ 0x088DC3F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry338_Medicham.bin"

	.align 2
gDirectSound_Cry339_Spheal:: @ 0x088DD478
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry339_Spheal.bin"

	.align 2
gDirectSound_Cry340_Sealeo:: @ 0x088DDA2C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry340_Sealeo.bin"

	.align 2
gDirectSound_Cry341_Walrein:: @ 0x088DE604
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry341_Walrein.bin"

	.align 2
gDirectSound_Cry342_Clamperl:: @ 0x088E0A50
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry342_Clamperl.bin"

	.align 2
gDirectSound_Cry343_Huntail:: @ 0x088E1CA0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry343_Huntail.bin"

	.align 2
gDirectSound_Cry344_Gorebyss:: @ 0x088E2C88
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry344_Gorebyss.bin"

	.align 2
gDirectSound_Cry345_Lileep:: @ 0x088E42F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry345_Lileep.bin"

	.align 2
gDirectSound_Cry346_Cradily:: @ 0x088E4C9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry346_Cradily.bin"

	.align 2
gDirectSound_Cry347_Anorith:: @ 0x088E69CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry347_Anorith.bin"

	.align 2
gDirectSound_Cry348_Armaldo:: @ 0x088E7584
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry348_Armaldo.bin"

	.align 2
gDirectSound_Cry349_Beldum:: @ 0x088E8C58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry349_Beldum.bin"

	.align 2
gDirectSound_Cry350_Metang:: @ 0x088E95F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry350_Metang.bin"

	.align 2
gDirectSound_Cry351_Metagross:: @ 0x088EA8CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry351_Metagross.bin"

	.align 2
gDirectSound_Cry352_Bagon:: @ 0x088ED044
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry352_Bagon.bin"

	.align 2
gDirectSound_Cry353_Shelgon:: @ 0x088ED818
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry353_Shelgon.bin"

	.align 2
gDirectSound_Cry354_Regirock:: @ 0x088EEC20
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry354_Regirock.bin"

	.align 2
gDirectSound_Cry355_Regice:: @ 0x088F0BFC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry355_Regice.bin"

	.align 2
gDirectSound_Cry356_Registeel:: @ 0x088F2BFC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry356_Registeel.bin"

	.align 2
gDirectSound_Cry357_Castform:: @ 0x088F4300
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry357_Castform.bin"

	.align 2
gDirectSound_Cry358_Volbeat:: @ 0x088F4F98
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry358_Volbeat.bin"

	.align 2
gDirectSound_Cry359_Illumise:: @ 0x088F5B20
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry359_Illumise.bin"

	.align 2
gDirectSound_Cry360_Poochyena:: @ 0x088F6C38
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry360_Poochyena.bin"

	.align 2
gDirectSound_Cry361_Mightyena:: @ 0x088F7580
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry361_Mightyena.bin"

	.align 2
gDirectSound_Cry362_Dusclops:: @ 0x088F890C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry362_Dusclops.bin"

	.align 2
gDirectSound_Cry363_Sableye:: @ 0x088F96C4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry363_Sableye.bin"

	.align 2
gDirectSound_Cry364_Mawile:: @ 0x088FA268
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry364_Mawile.bin"

	.align 2
gDirectSound_Cry365_Aron:: @ 0x088FADE8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry365_Aron.bin"

	.align 2
gDirectSound_Cry366_Lairon:: @ 0x088FB714
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry366_Lairon.bin"

	.align 2
gDirectSound_Cry367_Aggron:: @ 0x088FCBEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry367_Aggron.bin"

	.align 2
gDirectSound_Cry368_Relicanth:: @ 0x088FE590
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry368_Relicanth.bin"

	.align 2
gDirectSound_Cry369_Luvdisc:: @ 0x088FF9C0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry369_Luvdisc.bin"

	.align 2
gDirectSound_Cry370_Groudon:: @ 0x088FFE9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry370_Groudon.bin"

	.align 2
gDirectSound_Cry371_Kyogre:: @ 0x089023A8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry371_Kyogre.bin"

	.align 2
gDirectSound_Cry372_Rayquaza:: @ 0x08904760
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry372_Rayquaza.bin"

	.align 2
gDirectSound_Cry373_Salamence:: @ 0x0890648C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry373_Salamence.bin"

	.align 2
gDirectSound_Cry374_Breloom:: @ 0x08907DA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry374_Breloom.bin"

	.align 2
gDirectSound_Cry375_Shroomish:: @ 0x08908A68
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry375_Shroomish.bin"

	.align 2
gDirectSound_Cry376_Linoone:: @ 0x08909340
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry376_Linoone.bin"

	.align 2
gDirectSound_Cry377_Tropius:: @ 0x0890B1DC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry377_Tropius.bin"

	.align 2
gDirectSound_Cry378_Wailmer:: @ 0x0890D2A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry378_Wailmer.bin"

	.align 2
gDirectSound_Cry379_Zigzagoon:: @ 0x0890EF00
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry379_Zigzagoon.bin"

	.align 2
gDirectSound_Cry380_Exploud:: @ 0x0890FA90
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry380_Exploud.bin"

	.align 2
gDirectSound_Cry381_Loured:: @ 0x089116D8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry381_Loured.bin"

	.align 2
gDirectSound_Cry382_Wailord:: @ 0x08912400
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry382_Wailord.bin"

	.align 2
gDirectSound_Cry383_Whismur:: @ 0x08914E10
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry383_Whismur.bin"

	.align 2
gDirectSound_Cry384_Snorunt:: @ 0x08915634
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry384_Snorunt.bin"

	.align 2
gDirectSound_Cry385_Latios:: @ 0x0891673C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry385_Latios.bin"

	.align 2
gDirectSound_Cry386_Jirachi:: @ 0x08917D34
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry386_Jirachi.bin"

	.align 2
gDirectSound_Cry387_Deoxys:: @ 0x08918AB8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry387_Deoxys.bin"

	.align 2
gDirectSound_Cry388_Chimecho:: @ 0x08919F8C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_Cry388_Chimecho.bin"

.include "sound/songs/mus_title.s"
.include "sound/songs/mus_table_select.s"
.include "sound/songs/mus_ereader.s"
.include "sound/songs/mus_unk_6.s"
.include "sound/songs/mus_opening.s"
.include "sound/songs/mus_high_score.s"
.include "sound/songs/mus_shop.s"
.include "sound/songs/mus_slots_prize.s"
.include "sound/songs/mus_end_of_ball.s"
.include "sound/songs/mus_bonus_chance.s"
.include "sound/songs/mus_bonus_chance_legendary.s"
.include "sound/songs/mus_travel_mode_start.s"
.include "sound/songs/mus_success.s"
.include "sound/songs/mus_success2.s"
.include "sound/songs/mus_end_of_ball2.s"
.include "sound/songs/mus_prize_awarded.s"
.include "sound/songs/mus_egg_mode.s"
.include "sound/songs/mus_egg_mode_start.s"
.include "sound/songs/mus_travel_mode.s"
.include "sound/songs/mus_unk_18.s"
.include "sound/songs/mus_hurry_up.s"
.include "sound/songs/mus_evolution.s"
.include "sound/songs/mus_field_ruby.s"
.include "sound/songs/mus_catch_em_mode.s"
.include "sound/songs/mus_evo_mode.s"
.include "sound/songs/mus_field_sapphire.s"
.include "sound/songs/mus_catch_em_mode2.s"
.include "sound/songs/mus_evo_mode2.s"
.include "sound/songs/mus_bonus_field_kecleon.s"
.include "sound/songs/mus_bonus_field_duskull.s"
.include "sound/songs/mus_bonus_field_dusclops.s"
.include "sound/songs/mus_bonus_field_spheal.s"
.include "sound/songs/mus_bonus_field_groudon.s"
.include "sound/songs/mus_bonus_field_kyogre.s"
.include "sound/songs/mus_bonus_field_rayquaza.s"
.include "sound/songs/mus_success3.s"
.include "sound/songs/mus_end_of_ball3.s"
.include "sound/songs/mus_pokedex.s"
.include "sound/songs/mus_jirachi.s"
.include "sound/songs/mus_field_ruby2.s"
.include "sound/songs/mus_field_sapphire2.s"
.include "sound/songs/mus_unk_5d.s"
.include "sound/songs/se_menu_select.s"
.include "sound/songs/se_menu_cancel.s"
.include "sound/songs/se_menu_move.s"
.include "sound/songs/se_menu_popup_open.s"
.include "sound/songs/se_menu_popup_close.s"
.include "sound/songs/se_score_entry_a_b_move.s"
.include "sound/songs/se_score_entry_letter_change.s"
.include "sound/songs/se_unused_0x6c.s"
.include "sound/songs/se_dex_info_field_select_move.s"
.include "sound/songs/se_unused_0x6e.s"
.include "sound/songs/se_unused_0x6f.s"
.include "sound/songs/se_unk_71.s"
.include "sound/songs/se_flipper_pressed.s"
.include "sound/songs/se_slingshot_hit.s"
.include "sound/songs/se_pokemon_catch_hit.s"
.include "sound/songs/se_pichu_in_position_chirp.s"
.include "sound/songs/se_trigger_button_hit.s"
.include "sound/songs/se_wall_hit.s"
.include "sound/songs/se_tilt_triggered.s"
.include "sound/songs/se_pika_spinner_clack.s"
.include "sound/songs/se_pika_full_charge_1_up.s"
.include "sound/songs/se_unk_7b.s"
.include "sound/songs/se_kickback_thunderwave.s"
.include "sound/songs/se_unused_0x7d.s"
.include "sound/songs/se_coin_collected.s"
.include "sound/songs/se_unused_0x7f.s"
.include "sound/songs/se_center_hole_eject.s"
.include "sound/songs/se_roulette_tick.s"
.include "sound/songs/se_evo_selection_move.s"
.include "sound/songs/se_evo_selection_confirm.s"
.include "sound/songs/se_evo_item_appear.s"
.include "sound/songs/se_evo_item_finish_appear.s"
.include "sound/songs/se_evo_item_collected.s"
.include "sound/songs/se_ball_upgrade.s"
.include "sound/songs/se_unused_0x88.s"
.include "sound/songs/se_unused_0x89.s"
.include "sound/songs/se_failure.s"
.include "sound/songs/se_catch_evo_banner.s"
.include "sound/songs/se_catch_tile_reveal.s"
.include "sound/songs/se_catch_all_reveal_lightning.s"
.include "sound/songs/se_catch_all_reveal_shatter.s"
.include "sound/songs/se_shop_list_reveal.s"
.include "sound/songs/se_bonus_score_tallied.s"
.include "sound/songs/se_hatch_flourish.s"
.include "sound/songs/se_area_roulette_selected.s"
.include "sound/songs/se_ball_saved.s"
.include "sound/songs/se_lati_delivery.s"
.include "sound/songs/se_saver_plunger_drop.s"
.include "sound/songs/se_travel_painter_flight.s"
.include "sound/songs/se_travel_painter_paints.s"
.include "sound/songs/se_evo_get_arrow_earned.s"
.include "sound/songs/se_mon_catch_ball_woosh.s"
.include "sound/songs/se_mon_catch_energy_beam.s"
.include "sound/songs/se_mon_catch_ball_close.s"
.include "sound/songs/se_mon_catch_ball_hit_ground.s"
.include "sound/songs/se_mon_catch_ball_shake.s"
.include "sound/songs/se_warp.s"
.include "sound/songs/se_unused_0xa0.s"
.include "sound/songs/se_ball_summary_text_progress.s"
.include "sound/songs/se_ball_summary_page_swipe.s"
.include "sound/songs/se_pause_cursor_move.s"
.include "sound/songs/se_bonus_panel_slide.s"
.include "sound/songs/se_pausing.s"
.include "sound/songs/se_unpausing.s"
.include "sound/songs/se_catch_mon_entity_appears.s"
.include "sound/songs/se_pika_charge_do.s"
.include "sound/songs/se_pika_charge_re.s"
.include "sound/songs/se_pika_charge_mi.s"
.include "sound/songs/se_pika_charge_fa.s"
.include "sound/songs/se_pika_charge_so.s"
.include "sound/songs/se_pika_charge_la.s"
.include "sound/songs/se_pika_charge_ti.s"
.include "sound/songs/se_pika_charge_high_do.s"
.include "sound/songs/se_evo_cutscene_mon_portrait_change.s"
.include "sound/songs/se_pikachu_kickback.s"
.include "sound/songs/se_pichu_kickback_enabled.s"
.include "sound/songs/se_pichu_kickback.s"
.include "sound/songs/se_unused_0xb4.s"
.include "sound/songs/se_bumper_hit.s"
.include "sound/songs/se_cyndaquil_egg_guard_hit.s"
.include "sound/songs/se_aerodactyl_egg_flight.s"
.include "sound/songs/se_cyndaquil_ball_eject_after_egg_arrival.s"
.include "sound/songs/se_unused_0xba.s"
.include "sound/songs/se_unused_0xbb.s"
.include "sound/songs/se_unused_0xbc.s"
.include "sound/songs/se_ruby_mart_gate_open.s"
.include "sound/songs/se_unused_0xbe.s"
.include "sound/songs/se_unused_0xbf.s"
.include "sound/songs/se_unused_0xc0.s"
.include "sound/songs/se_unused_0xc1.s"
.include "sound/songs/se_sharpedo_ball_eject.s"
.include "sound/songs/se_shop_eject.s"
.include "sound/songs/se_unused_0xc4.s"
.include "sound/songs/se_makuhita_punch.s"
.include "sound/songs/se_chikorita_leaf_blade.s"
.include "sound/songs/se_zigzagoon_emerge.s"
.include "sound/songs/se_ruby_bumper_emerges.s"
.include "sound/songs/se_ruby_bumper_leaves.s"
.include "sound/songs/se_ruby_mart_sign_changed.s"
.include "sound/songs/se_unused_0xcb.s"
.include "sound/songs/se_spoink_launcher_charged.s"
.include "sound/songs/se_spoink_launcher_fired.s"
.include "sound/songs/se_sharpedo_bite.s"
.include "sound/songs/se_nuzleaf_hit.s"
.include "sound/songs/se_nuzleaf_teetering.s"
.include "sound/songs/se_nuzleaf_forms_bridge.s"
.include "sound/songs/se_gulpin_lands_or_leaves.s"
.include "sound/songs/se_whiscash_emerge_splash.s"
.include "sound/songs/se_whiscash_leave_burble.s"
.include "sound/songs/se_whiscash_catch_ball.s"
.include "sound/songs/se_whiscash_spit_ball.s"
.include "sound/songs/se_whiscash_splashdown.s"
.include "sound/songs/se_ramp_prize_collected.s"
.include "sound/songs/se_hatch_machine_spinner_trigger.s"
.include "sound/songs/se_mon_lands_on_hatch_machine_top.s"
.include "sound/songs/se_hatch_machine_stage_advance.s"
.include "sound/songs/se_hatch_machine_egg_hatch.s"
.include "sound/songs/se_hatch_machine_elevator.s"
.include "sound/songs/se_hatch_machine_elevator_top.s"
.include "sound/songs/se_pelipper_ball_grab.s"
.include "sound/songs/se_pelipper_wing_flap.s"
.include "sound/songs/se_pelipper_swoosh.s"
.include "sound/songs/se_pelipper_ball_drop_lands.s"
.include "sound/songs/se_sapphire_mart_gate_trigger.s"
.include "sound/songs/se_sapphire_mart_gate_replaced.s"
.include "sound/songs/se_sapphire_mart_gate_hit.s"
.include "sound/songs/se_seedot_falling.s"
.include "sound/songs/se_seedot_lands.s"
.include "sound/songs/se_seedot_leaves.s"
.include "sound/songs/se_zigzagoon_roulette_stop.s"
.include "sound/songs/se_duskull_appear.s"
.include "sound/songs/se_duskull_death_cry.s"
.include "sound/songs/se_dusclops_depart_incomplete.s"
.include "sound/songs/se_dusclops_move.s"
.include "sound/songs/se_dusclops_appear.s"
.include "sound/songs/se_dusclops_hit.s"
.include "sound/songs/se_dusclops_ball_absorb.s"
.include "sound/songs/se_dusclops_ball_launch.s"
.include "sound/songs/se_bonus_board_ball_spawn.s"
.include "sound/songs/se_unused_0xfa.s"
.include "sound/songs/se_kecleon_side_look.s"
.include "sound/songs/se_kecleon_vanish.s"
.include "sound/songs/se_kecleon_startled.s"
.include "sound/songs/se_kecleon_running.s"
.include "sound/songs/se_kecleon_knocked_over.s"
.include "sound/songs/se_kecleon_hit_damaged.s"
.include "sound/songs/se_kecleon_hits_ground_defeated.s"
.include "sound/songs/se_kecleon_seeing_stars.s"
.include "sound/songs/se_kecleon_tree_hit.s"
.include "sound/songs/se_kecleon_scope_fall.s"
.include "sound/songs/se_kecleon_scope_activated.s"
.include "sound/songs/se_kyogre_hit.s"
.include "sound/songs/se_kyogre_breach_surface.s"
.include "sound/songs/se_kyogre_dive.s"
.include "sound/songs/se_kyogre_spawn_whirlpool.s"
.include "sound/songs/se_kyogre_freeze_ring.s"
.include "sound/songs/se_kyogre_departs.s"
.include "sound/songs/se_kyogre_freeze_hits_ball.s"
.include "sound/songs/se_kyogre_freeze_crack.s"
.include "sound/songs/se_kyogre_freeze_escaped.s"
.include "sound/songs/se_kyogre_whirlpool_grabs_ball.s"
.include "sound/songs/se_groudon_hit.s"
.include "sound/songs/se_groudon_step.s"
.include "sound/songs/se_groudon_intro_leap.s"
.include "sound/songs/se_groudon_lands.s"
.include "sound/songs/se_groudon_spits_fire.s"
.include "sound/songs/se_groudon_fire_ring.s"
.include "sound/songs/se_groudon_fire_grab_resist.s"
.include "sound/songs/se_groudon_fire_grab.s"
.include "sound/songs/se_groudon_fireball_connects.s"
.include "sound/songs/se_groudon_boulder_land.s"
.include "sound/songs/se_groudon_dustorm_lift.s"
.include "sound/songs/se_groudon_ball_hit_fire.s"
.include "sound/songs/se_rayquaza_hit.s"
.include "sound/songs/se_rayquaza_wind.s"
.include "sound/songs/se_rayquaza_lightning_charge.s"
.include "sound/songs/se_rayquaza_flyby.s"
.include "sound/songs/se_rayquaza_lightning_trap.s"
.include "sound/songs/se_rayquaza_whirlwind_ball_launch.s"
.include "sound/songs/se_rayquaza_whirlwind_ball_land.s"
.include "sound/songs/se_rayquaza_sonic_boom.s"
.include "sound/songs/se_rayquaza_stage_wind.s"
.include "sound/songs/se_spheal_surfacing.s"
.include "sound/songs/se_spheal_submerging.s"
.include "sound/songs/se_spheal_submerging_after_scoring.s"
.include "sound/songs/se_spheal_hit.s"
.include "sound/songs/se_spheal_net_swoosh.s"
.include "sound/songs/se_spheal_crowd_cheer.s"
.include "sound/songs/se_spheal_end_whistle.s"
.include "sound/songs/se_sealeo_hit_thud.s"
.include "sound/songs/se_sealeo_nose_bounce.s"
.include "sound/songs/se_spheal_land_under_net.s"
.include "sound/songs/se_unused_0x13f.s"
.include "sound/songs/se_spheal_surface_at_ramp.s"
.include "sound/songs/se_pika_no_kickback.s"
.include "sound/songs/se_jirachi_move.s"
.include "sound/songs/se_jirachi_hit.s"
.include "sound/songs/se_totodile_lowers_rope.s"
.include "sound/songs/se_totodile_slides_down.s"
.include "sound/songs/se_totodile_places_egg.s"
.include "sound/songs/se_totodile_climbs_rope.s"
.include "sound/songs/se_highest_score_earned.s"
.include "sound/songs/se_high_score_earned.s"
.include "sound/songs/se_whiscash_earthquake.s"
