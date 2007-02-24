
//**************************************************************************
//**
//** pcode.h
//**
//**************************************************************************

#ifndef __PCODE_H__
#define __PCODE_H__

// HEADER FILES ------------------------------------------------------------

#include <stddef.h>
#include "common.h"

// MACROS ------------------------------------------------------------------

// Values added to script number to indicate its type
enum
{
	OPEN_SCRIPTS_BASE			= 1000,
	RESPAWN_SCRIPTS_BASE		= 2000,	// [BC]
	DEATH_SCRIPTS_BASE			= 3000,	// [BC]
	ENTER_SCRIPTS_BASE			= 4000,	// [BC]
	PICKUP_SCRIPTS_BASE			= 5000,	// [BC]
	BLUE_RETURN_SCRIPTS_BASE	= 6000,	// [BC]
	RED_RETURN_SCRIPTS_BASE		= 7000,	// [BC]
	WHITE_RETURN_SCRIPTS_BASE	= 8000,	// [BC]
	LIGHTNING_SCRIPTS_BASE		= 12000,
	UNLOADING_SCRIPTS_BASE		= 13000,
	DISCONNECT_SCRIPTS_BASE		= 14000
};

// Values added to script number to indicate flags (requires new-style .o)
enum
{
	NET_SCRIPT_FLAG			= 0x00010000
};

// Or'ed with variable index when passing variables of type "out"
// An idea that was never realized.
enum
{
	OUTVAR_SCRIPT_SPEC		= 0x40000000,
	OUTVAR_MAP_SPEC			= 0x80000000,
	OUTVAR_WORLD_SPEC		= 0xc0000000,
	OUTVAR_GLOBAL_SPEC		= 0x00000000
};

// TYPES -------------------------------------------------------------------

struct symbolNode_s;	// Defined in symbol.h
	
typedef enum
{
	PCD_NOP,
	PCD_TERMINATE,
	PCD_SUSPEND,
	PCD_PUSHNUMBER,
	PCD_LSPEC1,
	PCD_LSPEC2,
	PCD_LSPEC3,
	PCD_LSPEC4,
	PCD_LSPEC5,
	PCD_LSPEC1DIRECT,
	PCD_LSPEC2DIRECT,
	PCD_LSPEC3DIRECT,
	PCD_LSPEC4DIRECT,
	PCD_LSPEC5DIRECT,
	PCD_ADD,
	PCD_SUBTRACT,
	PCD_MULTIPLY,
	PCD_DIVIDE,
	PCD_MODULUS,
	PCD_EQ,
	PCD_NE,
	PCD_LT,
	PCD_GT,
	PCD_LE,
	PCD_GE,
	PCD_ASSIGNSCRIPTVAR,
	PCD_ASSIGNMAPVAR,
	PCD_ASSIGNWORLDVAR,
	PCD_PUSHSCRIPTVAR,
	PCD_PUSHMAPVAR,
	PCD_PUSHWORLDVAR,
	PCD_ADDSCRIPTVAR,
	PCD_ADDMAPVAR,
	PCD_ADDWORLDVAR,
	PCD_SUBSCRIPTVAR,
	PCD_SUBMAPVAR,
	PCD_SUBWORLDVAR,
	PCD_MULSCRIPTVAR,
	PCD_MULMAPVAR,
	PCD_MULWORLDVAR,
	PCD_DIVSCRIPTVAR,
	PCD_DIVMAPVAR,
	PCD_DIVWORLDVAR,
	PCD_MODSCRIPTVAR,
	PCD_MODMAPVAR,
	PCD_MODWORLDVAR,
	PCD_INCSCRIPTVAR,
	PCD_INCMAPVAR,
	PCD_INCWORLDVAR,
	PCD_DECSCRIPTVAR,
	PCD_DECMAPVAR,
	PCD_DECWORLDVAR,
	PCD_GOTO,
	PCD_IFGOTO,
	PCD_DROP,
	PCD_DELAY,
	PCD_DELAYDIRECT,
	PCD_RANDOM,
	PCD_RANDOMDIRECT,
	PCD_THINGCOUNT,
	PCD_THINGCOUNTDIRECT,
	PCD_TAGWAIT,
	PCD_TAGWAITDIRECT,
	PCD_POLYWAIT,
	PCD_POLYWAITDIRECT,
	PCD_CHANGEFLOOR,
	PCD_CHANGEFLOORDIRECT,
	PCD_CHANGECEILING,
	PCD_CHANGECEILINGDIRECT,
	PCD_RESTART,
	PCD_ANDLOGICAL,
	PCD_ORLOGICAL,
	PCD_ANDBITWISE,
	PCD_ORBITWISE,
	PCD_EORBITWISE,
	PCD_NEGATELOGICAL,
	PCD_LSHIFT,
	PCD_RSHIFT,
	PCD_UNARYMINUS,
	PCD_IFNOTGOTO,
	PCD_LINESIDE,
	PCD_SCRIPTWAIT,
	PCD_SCRIPTWAITDIRECT,
	PCD_CLEARLINESPECIAL,
	PCD_CASEGOTO,
	PCD_BEGINPRINT,
	PCD_ENDPRINT,
	PCD_PRINTSTRING,
	PCD_PRINTNUMBER,
	PCD_PRINTCHARACTER,
	PCD_PLAYERCOUNT,
	PCD_GAMETYPE,
	PCD_GAMESKILL,
	PCD_TIMER,
	PCD_SECTORSOUND,
	PCD_AMBIENTSOUND,
	PCD_SOUNDSEQUENCE,
	PCD_SETLINETEXTURE,
	PCD_SETLINEBLOCKING,
	PCD_SETLINESPECIAL,
	PCD_THINGSOUND,
	PCD_ENDPRINTBOLD,
// [RH] End of Hexen p-codes
	PCD_ACTIVATORSOUND,
	PCD_LOCALAMBIENTSOUND,
	PCD_SETLINEMONSTERBLOCKING,
// [BC] Start of new pcodes
	PCD_PLAYERBLUESKULL,
	PCD_PLAYERREDSKULL,
	PCD_PLAYERYELLOWSKULL,
	PCD_PLAYERMASTERSKULL,
	PCD_PLAYERBLUECARD,
	PCD_PLAYERREDCARD,
	PCD_PLAYERYELLOWCARD,
	PCD_PLAYERMASTERCARD,
	PCD_PLAYERBLACKSKULL,
	PCD_PLAYERSILVERSKULL,
	PCD_PLAYERGOLDSKULL,
	PCD_PLAYERBLACKCARD,
	PCD_PLAYERSILVERCARD,
	PCD_PLAYERONTEAM,
	PCD_PLAYERTEAM,
	PCD_PLAYERHEALTH,
	PCD_PLAYERARMORPOINTS,
	PCD_PLAYERFRAGS,
	PCD_PLAYEREXPERT,
	PCD_BLUETEAMCOUNT,
	PCD_REDTEAMCOUNT,
	PCD_BLUETEAMSCORE,
	PCD_REDTEAMSCORE,
	PCD_ISONEFLAGCTF,
	PCD_LSPEC6,				// [RH] LSPEC6 is never actually used.
	PCD_LSPEC6DIRECT,		// Should these be removed?
	PCD_PRINTNAME,
	PCD_MUSICCHANGE,
	PCD_CONSOLECOMMANDDIRECT,
	PCD_CONSOLECOMMAND,
	PCD_SINGLEPLAYER,
// [RH] End of Skull Tag p-codes
	PCD_FIXEDMUL,
	PCD_FIXEDDIV,
	PCD_SETGRAVITY,
	PCD_SETGRAVITYDIRECT,
	PCD_SETAIRCONTROL,
	PCD_SETAIRCONTROLDIRECT,
	PCD_CLEARINVENTORY,
	PCD_GIVEINVENTORY,
	PCD_GIVEINVENTORYDIRECT,
	PCD_TAKEINVENTORY,
	PCD_TAKEINVENTORYDIRECT,
	PCD_CHECKINVENTORY,
	PCD_CHECKINVENTORYDIRECT,
	PCD_SPAWN,
	PCD_SPAWNDIRECT,
	PCD_SPAWNSPOT,
	PCD_SPAWNSPOTDIRECT,
	PCD_SETMUSIC,
	PCD_SETMUSICDIRECT,
	PCD_LOCALSETMUSIC,
	PCD_LOCALSETMUSICDIRECT,
	PCD_PRINTFIXED,
	PCD_PRINTLOCALIZED,
	PCD_MOREHUDMESSAGE,
	PCD_OPTHUDMESSAGE,
	PCD_ENDHUDMESSAGE,
	PCD_ENDHUDMESSAGEBOLD,
	PCD_SETSTYLE,
	PCD_SETSTYLEDIRECT,
	PCD_SETFONT,
	PCD_SETFONTDIRECT,
	PCD_PUSHBYTE,		// Valid in compact-script mode only
	PCD_LSPEC1DIRECTB,	// "
	PCD_LSPEC2DIRECTB,	// "
	PCD_LSPEC3DIRECTB,	// "
	PCD_LSPEC4DIRECTB,	// "
	PCD_LSPEC5DIRECTB,	// "
	PCD_DELAYDIRECTB,	// "
	PCD_RANDOMDIRECTB,	// "
	PCD_PUSHBYTES,		// "
	PCD_PUSH2BYTES,		// "
	PCD_PUSH3BYTES,		// "
	PCD_PUSH4BYTES,		// "
	PCD_PUSH5BYTES,		// "
	PCD_SETTHINGSPECIAL,
	PCD_ASSIGNGLOBALVAR,
	PCD_PUSHGLOBALVAR,
	PCD_ADDGLOBALVAR,
	PCD_SUBGLOBALVAR,
	PCD_MULGLOBALVAR,
	PCD_DIVGLOBALVAR,
	PCD_MODGLOBALVAR,
	PCD_INCGLOBALVAR,
	PCD_DECGLOBALVAR,
	PCD_FADETO,
	PCD_FADERANGE,
	PCD_CANCELFADE,
	PCD_PLAYMOVIE,
	PCD_SETFLOORTRIGGER,
	PCD_SETCEILINGTRIGGER,
	PCD_GETACTORX,
	PCD_GETACTORY,
	PCD_GETACTORZ,
	PCD_STARTTRANSLATION,
	PCD_TRANSLATIONRANGE1,
	PCD_TRANSLATIONRANGE2,
	PCD_ENDTRANSLATION,
	PCD_CALL,
	PCD_CALLDISCARD,
	PCD_RETURNVOID,
	PCD_RETURNVAL,
	PCD_PUSHMAPARRAY,
	PCD_ASSIGNMAPARRAY,
	PCD_ADDMAPARRAY,
	PCD_SUBMAPARRAY,
	PCD_MULMAPARRAY,
	PCD_DIVMAPARRAY,
	PCD_MODMAPARRAY,
	PCD_INCMAPARRAY,
	PCD_DECMAPARRAY,
	PCD_DUP,
	PCD_SWAP,
	PCD_WRITETOINI,
	PCD_GETFROMINI,
	PCD_SIN,
	PCD_COS,
	PCD_VECTORANGLE,
	PCD_CHECKWEAPON,
	PCD_SETWEAPON,
	PCD_TAGSTRING,
	PCD_PUSHWORLDARRAY,
	PCD_ASSIGNWORLDARRAY,
	PCD_ADDWORLDARRAY,
	PCD_SUBWORLDARRAY,
	PCD_MULWORLDARRAY,
	PCD_DIVWORLDARRAY,
	PCD_MODWORLDARRAY,
	PCD_INCWORLDARRAY,
	PCD_DECWORLDARRAY,
	PCD_PUSHGLOBALARRAY,
	PCD_ASSIGNGLOBALARRAY,
	PCD_ADDGLOBALARRAY,
	PCD_SUBGLOBALARRAY,
	PCD_MULGLOBALARRAY,
	PCD_DIVGLOBALARRAY,
	PCD_MODGLOBALARRAY,
	PCD_INCGLOBALARRAY,
	PCD_DECGLOBALARRAY,
	PCD_SETMARINEWEAPON,
	PCD_SETACTORPROPERTY,
	PCD_GETACTORPROPERTY,
	PCD_PLAYERNUMBER,
	PCD_ACTIVATORTID,
	PCD_SETMARINESPRITE,
	PCD_GETSCREENWIDTH,
	PCD_GETSCREENHEIGHT,
	PCD_THING_PROJECTILE2,
	PCD_STRLEN,
	PCD_SETHUDSIZE,
	PCD_GETCVAR,
	PCD_CASEGOTOSORTED,
	PCD_SETRESULTVALUE,
	PCD_GETLINEROWOFFSET,
	PCD_GETACTORFLOORZ,
	PCD_GETACTORANGLE,
	PCD_GETSECTORFLOORZ,
	PCD_GETSECTORCEILINGZ,
	PCD_LSPEC5RESULT,
	PCD_GETSIGILPIECES,
	PCD_GETLEVELINFO,
	PCD_CHANGESKY,
	PCD_PLAYERINGAME,
	PCD_PLAYERISBOT,
	PCD_SETCAMERATOTEXTURE,
	PCD_ENDLOG,
	PCD_GETAMMOCAPACITY,
	PCD_SETAMMOCAPACITY,
// [JB] start of new pcodes
	PCD_PRINTMAPCHARARRAY,
	PCD_PRINTWORLDCHARARRAY,
	PCD_PRINTGLOBALCHARARRAY,
// [JB] end of new pcodes
	PCD_SETACTORANGLE,
	PCD_GRABINPUT,
	PCD_SETMOUSEPOINTER,
	PCD_MOVEMOUSEPOINTER,
	PCD_SPAWNPROJECTILE,
	PCD_GETSECTORLIGHTLEVEL,
	PCD_GETACTORCEILINGZ,
	PCD_SETACTORPOSITION,
	PCD_CLEARACTORINVENTORY,
	PCD_GIVEACTORINVENTORY,
	PCD_TAKEACTORINVENTORY,
	PCD_CHECKACTORINVENTORY,
	PCD_THINGCOUNTNAME,
	PCD_SPAWNSPOTFACING,
	PCD_PLAYERCLASS,
	//[MW] start my p-codes
	PCD_ANDSCRIPTVAR,
	PCD_ANDMAPVAR, 
	PCD_ANDWORLDVAR, 
	PCD_ANDGLOBALVAR, 
	PCD_ANDMAPARRAY, 
	PCD_ANDWORLDARRAY, 
	PCD_ANDGLOBALARRAY,
	PCD_EORSCRIPTVAR, 
	PCD_EORMAPVAR, 
	PCD_EORWORLDVAR, 
	PCD_EORGLOBALVAR, 
	PCD_EORMAPARRAY, 
	PCD_EORWORLDARRAY, 
	PCD_EORGLOBALARRAY,
	PCD_ORSCRIPTVAR, 
	PCD_ORMAPVAR, 
	PCD_ORWORLDVAR, 
	PCD_ORGLOBALVAR, 
	PCD_ORMAPARRAY, 
	PCD_ORWORLDARRAY, 
	PCD_ORGLOBALARRAY,
	PCD_LSSCRIPTVAR, 
	PCD_LSMAPVAR, 
	PCD_LSWORLDVAR, 
	PCD_LSGLOBALVAR, 
	PCD_LSMAPARRAY, 
	PCD_LSWORLDARRAY, 
	PCD_LSGLOBALARRAY,
	PCD_RSSCRIPTVAR, 
	PCD_RSMAPVAR, 
	PCD_RSWORLDVAR, 
	PCD_RSGLOBALVAR, 
	PCD_RSMAPARRAY, 
	PCD_RSWORLDARRAY, 
	PCD_RSGLOBALARRAY, 
	//[MW] end my p-codes
	PCD_GETPLAYERINFO,
	PCD_CHANGELEVEL,
	PCD_SECTORDAMAGE,
	PCD_REPLACETEXTURES,
	PCD_NEGATEBINARY,
	PCD_GETACTORPITCH,
	PCD_SETACTORPITCH,
	PCD_PRINTBIND,

	PCODE_COMMAND_COUNT
} pcd_t;

// PUBLIC FUNCTION PROTOTYPES ----------------------------------------------

void PC_OpenObject(char *name, size_t size, int flags);
void PC_CloseObject(void);
void PC_Append(void *buffer, size_t size);
void PC_AppendByte(U_BYTE val);
void PC_AppendWord(U_WORD val);
void PC_AppendLong(U_LONG val);
void PC_AppendString(char *string);
void PC_AppendCmd(pcd_t command);
void PC_AppendPushVal(U_LONG val);
void PC_AppendShrink(U_BYTE val);
void PC_Write(void *buffer, size_t size, int address);
void PC_WriteByte(U_BYTE val, int address);
//void PC_WriteWord(U_WORD val, int address);
void PC_WriteLong(U_LONG val, int address);
void PC_WriteString(char *string, int address);
void PC_WriteCmd(pcd_t command, int address);
void PC_Skip(size_t size);
//void PC_SkipByte(void);
//void PC_SkipWord(void);
void PC_SkipLong(void);
void PC_AddScript(int number, int argCount);
void PC_SetScriptVarCount(int number, int varCount);
void PC_AddFunction(struct symbolNode_s *sym);
void PC_PutMapVariable(int index, int value);
void PC_NameMapVariable(int index, struct symbolNode_s *sym);
void PC_AddArray(int index, int size);
void PC_InitArray(int index, int *entries, boolean hasStrings);
int PC_AddImport(char *name);

// PUBLIC DATA DECLARATIONS ------------------------------------------------

extern int pc_Address;
extern byte *pc_Buffer;
extern byte *pc_BufferPtr;
extern int pc_ScriptCount;
extern int pc_FunctionCount;
extern boolean pc_NoShrink;
extern boolean pc_HexenCase;
extern boolean pc_WadAuthor;
extern boolean pc_EncryptStrings;
extern int pc_LastAppendedCommand;

#endif
