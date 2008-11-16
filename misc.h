
//**************************************************************************
//**
//** misc.h
//**
//**************************************************************************

#ifndef __MISC_H__
#define __MISC_H__

// HEADER FILES ------------------------------------------------------------

#include <stddef.h>
#include "error.h"

// MACROS ------------------------------------------------------------------

#define ASCII_SLASH 47
#define ASCII_BACKSLASH 92

// TYPES -------------------------------------------------------------------

typedef enum
{
	MSG_NORMAL,
	MSG_VERBOSE,
	MSG_DEBUG
} msg_t;

// PUBLIC FUNCTION PROTOTYPES ----------------------------------------------

void *MS_Alloc(size_t size, error_t error);
void *MS_Realloc(void *base, size_t size, error_t error);
U_WORD MS_LittleUWORD(U_WORD val);
// U_LONG MS_LittleULONG(U_LONG val);
U_INT MS_LittleUINT(U_INT val);
int MS_LoadFile(char *name, char **buffer);
boolean MS_FileExists(char *name);
boolean MS_SaveFile(char *name, void *buffer, int length);
int MS_StrCmp(char *s1, char *s2);
char *MS_StrLwr(char *string);
char *MS_StrUpr(char *string);
void MS_SuggestFileExt(char *base, char *extension);
void MS_StripFileExt(char *name);
boolean MS_StripFilename(char *path);
void MS_Message(msg_t type, char *text, ...);

// PUBLIC DATA DECLARATIONS ------------------------------------------------

#endif
