/*
**	$Filename: Base/Base.h
**	$Release:
**	$Revision:
**	$Date:
**
**
**
**	(C) 1993, 1994 ...and avoid panic by, H. Gaberschek
**	    All Rights Reserved
*/
/****************************************************************************
  Portions copyright (c) 2005 Vasco Alexandre da Silva Costa

  Please read the license terms contained in the LICENSE and
  publiclicensecontract.doc files which should be contained with this
  distribution.
 ****************************************************************************/

#ifndef MODULE_BASE
#define MODULE_BASE

#ifndef __STDIO_H
#include <stdio.h>
#endif

#ifndef __STDARG_H
#include <stdarg.h>
#endif

#ifndef __STDLIB_H
#include <stdlib.h>
#endif

#ifndef __FCNTL_H
#include <fcntl.h>
#endif

#include "theclou.h"

#ifndef MODULE_ERROR
#include "error/error.h"
#endif

#ifndef MODULE_LIST
#include "list/list.h"
#endif

#ifndef MODULE_MEMORY
#include "memory/memory.h"
#endif

#ifndef MODULE_DISK
#include "disk/disk.h"
#endif

#ifndef MODULE_INPHDL
#include "inphdl/inphdl.h"
#endif

#include "gfx/gfx.h"
#include "text/text.h"
#include "anim/sysanim.h"
#include "present/interac.h"
#include "data/relation.h"


#ifndef MODULE_DATABASE
#include "data/database.h"
#endif

#ifndef MODULE_GAMEPLAY
#include "gameplay/gp.h"
#endif

#ifndef MODULE_SOUND
#include "sound/newsound.h"
#endif

#ifndef MODULE_FX
#include "sound/fx.h"
#endif

#include "cdrom/cdrom.h"

/*
 *
 *
 */
struct Setup {
    bool FullScreen;
    bool Profidisk;
    bool CDRom;
    S32 SfxVolume;
    S32 MusicVolume;
    unsigned Debug;
    bool CDAudio;
    unsigned Scale;
    unsigned ScaleMode;		/* GFX_SCALE_... */
    const char *SaveDir;	/* -p: NULL = per-version folder in the
				   user's data folder, "" = DATADISK */
};

/* How the 320x200 picture is scaled up to the window (-q option) */
#define GFX_SCALE_SMOOTH	0	/* linear filtering: smooth, a bit blurry */
#define GFX_SCALE_NEAREST	1	/* sharp, but pixels differ in size */
#define GFX_SCALE_INTEGER	2	/* sharp, whole multiples only, borders */
#define GFX_SCALE_SHARP		3	/* whole multiple with nearest, then linear to fit */
#define GFX_SCALE_LAST		GFX_SCALE_SHARP

extern struct Setup setup;


/*
 * Verwendungszweck:
 * StdBuffer0: geladenes Bild
 *
 * StdBuffer1: entpacktes Bild
 */

#define STD_BUFFER0_SIZE  (320 * 140)
#define STD_BUFFER1_SIZE  (61 * 1024)	/* weniger geht nicht! (Bild + CMAP) */

extern char prgname[255];

extern void *StdBuffer0, *StdBuffer1;

extern void tcClearStdBuffer(void *p_Buffer);

extern void tcSetPermanentColors(void);
void tcDone(void);

U32 tcGetProcessorType(void);

#define PROC_80286		1L
#define PROC_80386		2L
#define PROC_80486		3L

#endif
