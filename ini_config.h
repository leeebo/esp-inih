/*
 * SPDX-FileCopyrightText: 2022-2023 libo_go@163.com
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once
#include "sdkconfig.h"

/* Nonzero if ini_handler callback should accept lineno parameter. */
#define INI_HANDLER_LINENO CONFIG_INI_HANDLER_LINENO

/* Nonzero to allow multi-line value parsing, in the style of Python's
   configparser. If allowed, ini_parse() will call the handler with the same
   name for each subsequent line parsed. */
#define INI_ALLOW_MULTILINE CONFIG_INI_ALLOW_MULTILINE

/* Nonzero to allow a UTF-8 BOM sequence (0xEF 0xBB 0xBF) at the start of
   the file. See https://github.com/benhoyt/inih/issues/21 */
#define INI_ALLOW_BOM CONFIG_INI_ALLOW_BOM

/* Chars that begin a start-of-line comment. Per Python configparser, allow
   both ; and # comments at the start of a line by default. */
#define INI_START_COMMENT_PREFIXES CONFIG_INI_START_COMMENT_PREFIXES

/* Nonzero to allow inline comments (with valid inline comment characters
   specified by INI_INLINE_COMMENT_PREFIXES). Set to 0 to turn off and match
   Python 3.2+ configparser behaviour. */
#define INI_ALLOW_INLINE_COMMENTS CONFIG_INI_ALLOW_INLINE_COMMENTS
#define INI_INLINE_COMMENT_PREFIXES CONFIG_INI_INLINE_COMMENT_PREFIXES

/* Nonzero to use stack for line buffer, zero to use heap (malloc/free). */
#define INI_USE_STACK CONFIG_INI_USE_STACK

/* Maximum line length for any line in INI file (stack or heap). Note that
   this must be 3 more than the longest line (due to '\r', '\n', and '\0'). */
#define INI_MAX_LINE CONFIG_INI_MAX_LINE

/* Nonzero to allow heap line buffer to grow via realloc(), zero for a
   fixed-size buffer of INI_MAX_LINE bytes. Only applies if INI_USE_STACK is
   zero. */
#define INI_ALLOW_REALLOC CONFIG_INI_ALLOW_REALLOC

/* Initial size in bytes for heap line buffer. Only applies if INI_USE_STACK
   is zero. */
#define INI_INITIAL_ALLOC CONFIG_INI_INITIAL_ALLOC

/* Stop parsing on first error (default is to keep parsing). */
#define INI_STOP_ON_FIRST_ERROR CONFIG_INI_STOP_ON_FIRST_ERROR

/* Nonzero to call the handler at the start of each new section (with
   name and value NULL). Default is to only call the handler on
   each name=value pair. */
#define INI_CALL_HANDLER_ON_NEW_SECTION CONFIG_INI_CALL_HANDLER_ON_NEW_SECTION

/* Nonzero to allow a name without a value (no '=' or ':' on the line) and
   call the handler with value NULL in this case. Default is to treat
   no-value lines as an error. */
#define INI_ALLOW_NO_VALUE CONFIG_INI_ALLOW_NO_VALUE

/* Nonzero to use custom ini_malloc, ini_free, and ini_realloc memory
   allocation functions (INI_USE_STACK must also be 0). These functions must
   have the same signatures as malloc/free/realloc and behave in a similar
   way. ini_realloc is only needed if INI_ALLOW_REALLOC is set. */
#define INI_CUSTOM_ALLOCATOR CONFIG_INI_CUSTOM_ALLOCATOR