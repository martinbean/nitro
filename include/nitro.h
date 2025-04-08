#ifndef NITRO_H
#define NITRO_H

#include "common.h"
#include "psyq/SYS/TYPES.H"
#include "psyq/LIBCD.H"
#include "types.h"

#define FILES_COUNT 254

typedef struct FileInfo {
	char *filename;
	char *cd_filename;
	void *addr;
	CdlFILE fp;
} FileInfo;

#endif /* NITRO_H */
