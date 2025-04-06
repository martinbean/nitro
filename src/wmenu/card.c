#include "common.h"

extern int TestEvent(int);

extern int D_801B1D08; // ev0
extern int D_801B1D0C; // ev1
extern int D_801B1D10; // ev2
extern int D_801B1D14; // ev3
extern int D_801B1D20; // ev10
extern int D_801B1D24; // ev11
extern int D_801B1D28; // ev12
extern int D_801B1D2C; // ev13

int _card_event()
{
	while (1) {
		// IOE
		if (TestEvent(D_801B1D08) == 1) {
			return 0;
		}
		// ERROR
		if (TestEvent(D_801B1D0C) == 1) {
			return 1;
		}
		// TIMEOUT
		if (TestEvent(D_801B1D10) == 1) {
			return 2;
		}
		// NEW CARD
		if (TestEvent(D_801B1D14) == 1) {
			return 3;
		}
	}
}

void _clear_event(void)
{
	TestEvent(D_801B1D08);
	TestEvent(D_801B1D0C);
	TestEvent(D_801B1D10);
	TestEvent(D_801B1D14);
}

int _card_event_x(void)
{
	while(1)
	{
		if (TestEvent(D_801B1D20) == 1)
		{
			return 0;
		}
		if (TestEvent(D_801B1D24) == 1)
		{
			return 1;
		}
		if (TestEvent(D_801B1D28) == 1)
		{
			return 2;
		}
		if (TestEvent(D_801B1D2C) == 1)
		{
			return 3;
		}
	}
}

void _clear_event_x(void)
{
	TestEvent(D_801B1D20);
	TestEvent(D_801B1D24);
	TestEvent(D_801B1D28);
	TestEvent(D_801B1D2C);
}

INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068470);
INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068554);
INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068B5C);
INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068D68);
INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068E5C);
