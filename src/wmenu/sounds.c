#include "common.h"
#include "nitro.h"

extern int32_t VSync(int32_t); // libetc.h

extern void play_prog_and_note_on_random_voice(short, int32_t);

void play_unlock_sound_1(void)
{
	int32_t note;
	int32_t i;

	for (note = 0; note < 127; note = note + 8)
	{
		play_prog_and_note_on_random_voice(1, note);

		for (i = 0; i < 2; i++)
		{
			VSync(0);
		}
	}
}

INCLUDE_ASM("asm/wmenu/nonmatchings/sounds", play_unlock_sound_2);

void play_unlock_sound_3(void)
{
	int32_t note;
	int32_t i;

	for (note = 64; note >= 33; note = note - 1)
	{
		play_prog_and_note_on_random_voice(0, note);

		for (i = 0; i < 1; i++)
		{
			VSync(0);
		}
	}
}

void play_unlock_sound_4(void)
{
	int32_t note;
	int32_t i;

	for (note = 64; note < 127; note = note + 4)
	{
		play_prog_and_note_on_random_voice(3, note);

		for (i = 0; i < 4; i++)
		{
			VSync(0);
		}
	}
}

void func_80066BF4(int32_t arg0)
{
	// Empty function. Answers on a postcard, please.
}
