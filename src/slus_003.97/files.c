#include "common.h"
#include "nitro.h"
#include "psyq/LIBCD.H"

INCLUDE_ASM("asm/slus_003.97/nonmatchings/files", cache_file_pos);

void seek_file(FileInfo *fileinfo)
{
	CdControl(CdlSetloc, &fileinfo->fp, 0);
}

INCLUDE_ASM("asm/slus_003.97/nonmatchings/files", quick_find_file);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/files", find_file);
INCLUDE_ASM("asm/slus_003.97/nonmatchings/files", read_file);
