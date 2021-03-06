
//**************************************************************************
//**
//** error.h
//**
//**************************************************************************

#ifndef __ERROR_H__
#define __ERROR_H__

// HEADER FILES ------------------------------------------------------------

#include <stdarg.h>
#include "common.h"

// MACROS ------------------------------------------------------------------

// TYPES -------------------------------------------------------------------

typedef enum
{
	ERR_NONE = 0,
	ERR_NO_SYMBOL_MEM = 10,
	ERR_IDENTIFIER_TOO_LONG,
	ERR_STRING_TOO_LONG,
	ERR_FILE_NAME_TOO_LONG,
	ERR_MISSING_LPAREN,
	ERR_MISSING_RPAREN,
	ERR_MISSING_SEMICOLON,
	ERR_MISSING_SCRIPT_NUMBER,
	ERR_ALLOC_PCODE_BUFFER,
	ERR_PCODE_BUFFER_OVERFLOW,
	ERR_TOO_MANY_SCRIPTS,
	ERR_TOO_MANY_FUNCTIONS,
	ERR_SAVE_OBJECT_FAILED,
	ERR_MISSING_LPAREN_SCR,
	ERR_INVALID_IDENTIFIER,
	ERR_REDEFINED_IDENTIFIER,
	ERR_MISSING_COMMA,
	ERR_BAD_VAR_TYPE,
	ERR_BAD_RETURN_TYPE,
	ERR_TOO_MANY_SCRIPT_ARGS,
	ERR_MISSING_LBRACE_SCR,
	ERR_MISSING_RBRACE_SCR,
	ERR_TOO_MANY_MAP_VARS,
	ERR_MISSING_WVAR_INDEX,
	ERR_MISSING_GVAR_INDEX,
	ERR_BAD_WVAR_INDEX,
	ERR_MISSING_WVAR_COLON,
	ERR_MISSING_GVAR_COLON,
	ERR_MISSING_SPEC_VAL,
	ERR_MISSING_SPEC_COLON,
	ERR_MISSING_SPEC_ARGC,
	ERR_CANT_READ_FILE,
	ERR_CANT_OPEN_FILE,
	ERR_CANT_OPEN_DBGFILE,
	ERR_INVALID_DIRECTIVE,
	ERR_BAD_DEFINE,
	ERR_INCL_NESTING_TOO_DEEP,
	ERR_STRING_LIT_NOT_FOUND,
	ERR_TOO_MANY_SCRIPT_VARS,
	ERR_TOO_MANY_FUNCTION_VARS,
	ERR_INVALID_DECLARATOR,
	ERR_BAD_LSPEC_ARG_COUNT,
	ERR_BAD_ARG_COUNT,
	ERR_UNKNOWN_IDENTIFIER,
	ERR_MISSING_COLON,
	ERR_BAD_EXPR,
	ERR_BAD_CONST_EXPR,
	ERR_NO_DIRECT_VER,
	ERR_ILLEGAL_EXPR_IDENT,
	ERR_EXPR_FUNC_NO_RET_VAL,
	ERR_MISSING_ASSIGN_OP,
	ERR_INCDEC_OP_ON_NON_VAR,
	ERR_MISSING_RBRACE,
	ERR_INVALID_STATEMENT,
	ERR_BAD_DO_STATEMENT,
	ERR_BAD_SCRIPT_DECL,
	ERR_CASE_OVERFLOW,
	ERR_BREAK_OVERFLOW,
	ERR_CONTINUE_OVERFLOW,
	ERR_STATEMENT_OVERFLOW,
	ERR_MISPLACED_BREAK,
	ERR_MISPLACED_CONTINUE,
	ERR_CASE_NOT_IN_SWITCH,
	ERR_DEFAULT_NOT_IN_SWITCH,
	ERR_MULTIPLE_DEFAULT,
	ERR_EXPR_STACK_OVERFLOW,
	ERR_EXPR_STACK_EMPTY,
	ERR_UNKNOWN_CONST_EXPR_PCD,
	ERR_BAD_RADIX_CONSTANT,
	ERR_BAD_ASSIGNMENT,
	ERR_OUT_OF_MEMORY,
	ERR_TOO_MANY_STRINGS,
	ERR_UNKNOWN_PRTYPE,
	ERR_BAD_CHARACTER,
	ERR_SCRIPT_OUT_OF_RANGE,
	ERR_MISSING_PARAM,
	ERR_SCRIPT_ALREADY_DEFINED,
	ERR_FUNCTION_ALREADY_DEFINED,
	ERR_PARM_MUST_BE_VAR,
	ERR_LANGCODE_SIZE,
	ERR_MISSING_LBRACE_LOC,
	ERR_MISSING_RBRACE_LOC,
	ERR_MISSING_LOCALIZED,
	ERR_BAD_LANGCODE,
	ERR_MISSING_LANGCODE,
	ERR_MISSING_FONT_NAME,
	ERR_MISSING_LBRACE_FONTS,
	ERR_MISSING_RBRACE_FONTS,
	ERR_NOCOMPACT_NOT_HERE,
	ERR_MISSING_ASSIGN,
	ERR_MUST_RETURN_A_VALUE,
	ERR_MUST_NOT_RETURN_A_VALUE,
	ERR_SUSPEND_IN_FUNCTION,
	ERR_TERMINATE_IN_FUNCTION,
	ERR_RESTART_IN_FUNCTION,
	ERR_RETURN_OUTSIDE_FUNCTION,
	ERR_PREVIOUS_NOT_VOID,
	ERR_MISSING_LBRACE,
	ERR_FUNC_ARGUMENT_COUNT,
	ERR_UNDEFINED_FUNC,
	ERR_TOO_MANY_ARRAY_DIMS,
	ERR_MISSING_LBRACKET,
	ERR_MISSING_RBRACKET,
	ERR_ZERO_DIMENSION,
	ERR_TOO_MANY_DIM_USED,
	ERR_TOO_FEW_DIM_USED,
	ERR_TOO_MANY_ARRAY_INIT,
	ERR_EOF,
	ERR_ARRAY_MAPVAR_ONLY,
	ERR_NOT_AN_ARRAY,
	ERR_MISSING_LBRACE_ARR,
	ERR_MISSING_RBRACE_ARR,
	ERR_LATENT_IN_FUNC,
	ERR_LOCAL_VAR_SHADOWED,
	ERR_BAD_CHARACTER_CONSTANT,
	ERR_MULTIPLE_IMPORTS,
	ERR_IMPORT_IN_EXPORT,
	ERR_EXPORTER_NOT_FLAGGED,
	ERR_TOO_MANY_IMPORTS,
	ERR_NO_NEED_ARRAY_SIZE,
	ERR_NO_MULTIDIMENSIONS,
	ERR_NEED_ARRAY_SIZE,
	ERR_DISCONNECT_NEEDS_1_ARG,
	ERR_UNCLOSED_WITH_ARGS,
	ERR_NOT_A_CHAR_ARRAY,
	ERR_CANT_FIND_INCLUDE,
	ERR_SCRIPT_NAMED_NONE,
	ERR_HEXEN_COMPAT,
	ERR_NOT_HEXEN,
	ERR_SPECIAL_RANGE,
} error_t;

// PUBLIC FUNCTION PROTOTYPES ----------------------------------------------

void ERR_ErrorAt(char *sourceName, int sourceLine);
void ERR_Error(error_t error, boolean info, ...);
void ERR_ErrorV(error_t error, boolean info, va_list args);
void ERR_Finish(void);
void ERR_Exit(error_t error, boolean info, ...);
void ERR_RemoveErrorFile(void);

// PUBLIC DATA DECLARATIONS ------------------------------------------------

#endif
