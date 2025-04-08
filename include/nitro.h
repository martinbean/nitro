#ifndef NITRO_H
#define NITRO_H

#include "common.h"
#include "psyq/SYS/TYPES.H"
#include "psyq/LIBCD.H"
#include "types.h"

typedef struct FileInfo {
	char *filename;
	char *cd_filename;
	void *addr;
	CdlFILE *fp;
} FileInfo;

#endif /* NITRO_H */
