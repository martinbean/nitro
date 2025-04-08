#include "common.h"
#include "nitro.h"
#include "psyq/LIBCD.H"

extern FileInfo fileinfo[FILES_COUNT];

void cache_file_pos(void)
{
	int i;

	for (i = 0; i < sizeof(fileinfo) / sizeof(fileinfo[0]); i++)
	{
		find_file(&fileinfo[i], 1);
	}
}

void seek_file(FileInfo *fileinfo)
{
	CdControl(CdlSetloc, &fileinfo->fp, 0);
}

INCLUDE_ASM("asm/slus_003.97/nonmatchings/files", quick_find_file);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/files", find_file);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/files", read_file);
