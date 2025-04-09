#include "common.h"
#include "nitro.h"
#include "psyq/libsnd.h"

extern uint32_t sfx_volume;
extern uint32_t music_volume;

INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", init_bg_music);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", init_vab);

void close_vab(int16_t vab_id)
{
	mute_all_voices();
	SsVabClose(vab_id);
}

void stop_all_sound(void)
{
	mute_all_voices();
	stop_cd_sound();
	SsVabClose(0);
	SsEnd();
}

INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", play_prog_on_random_voice);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", play_prog_and_note_on_random_voice);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", play_soundbite_using_sfx_volume);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", play_soundbite_using_music_volume);

void set_voice_volume_sfx(int16_t voice, int32_t volume)
{
	volume = volume * sfx_volume;
	volume = (volume << 7);
	volume = volume >> 0x10;

	SsUtSetVVol(voice, volume, volume);
}

void set_voice_volume_music(int16_t voice, int32_t volume)
{
	volume = volume * music_volume;
	volume = (volume << 7);
	volume = volume >> 0x10;

	SsUtSetVVol(voice, volume, volume);
}

void mute_all_voices(void)
{
	int32_t voice;

	for (voice = 0; voice < 24; voice++)
	{
		SsUtSetVVol(voice, 0, 0);
		SsUtKeyOffV(voice);
	}
}

INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", play_cd_track);

void stop_cd_sound(void)
{
	CdSyncCallback(0);
	CdReadyCallback(0);
	CdControlB(CdlStop, 0, 0);
	SsSetSerialAttr(SS_SERIAL_A, SS_MIX, SS_SOFF);
	SsSetSerialVol(SS_SERIAL_A, 0, 0);
}

INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", cbcomplete);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", cbdataready);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", func_800185A0);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", set_cd_volume);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", set_main_volume);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/audio", func_80018778);
