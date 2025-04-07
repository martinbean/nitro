#include "common.h"
#include "nitro.h"

extern uint32_t TestEvent(uint32_t); // libapi

extern uint32_t ev0;
extern uint32_t ev1;
extern uint32_t ev2;
extern uint32_t ev3;
extern uint32_t ev10;
extern uint32_t ev11;
extern uint32_t ev12;
extern uint32_t ev13;

uint32_t _card_event()
{
	while (1)
	{
		// IOE
		if (TestEvent(ev0) == 1)
		{
			return 0;
		}
		// ERROR
		if (TestEvent(ev1) == 1)
		{
			return 1;
		}
		// TIMEOUT
		if (TestEvent(ev2) == 1)
		{
			return 2;
		}
		// NEW CARD
		if (TestEvent(ev3) == 1)
		{
			return 3;
		}
	}
}

void _clear_event(void)
{
	TestEvent(ev0);
	TestEvent(ev1);
	TestEvent(ev2);
	TestEvent(ev3);
}

uint32_t _card_event_x(void)
{
	while(1)
	{
		if (TestEvent(ev10) == 1)
		{
			return 0;
		}
		if (TestEvent(ev11) == 1)
		{
			return 1;
		}
		if (TestEvent(ev12) == 1)
		{
			return 2;
		}
		if (TestEvent(ev13) == 1)
		{
			return 3;
		}
	}
}

void _clear_event_x(void)
{
	TestEvent(ev10);
	TestEvent(ev11);
	TestEvent(ev12);
	TestEvent(ev13);
}

INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068470);
INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068554);
INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068B5C);
INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068D68);
INCLUDE_ASM("asm/wmenu/nonmatchings/card", func_80068E5C);
