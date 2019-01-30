/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "matcher_parser_parse.y" /* yacc.c:339  */

/*
 * Sylpheed -- a GTK+ based, lightweight, and fast e-mail client
 * Copyright (c) 2001-2014 by Hiroyuki Yamamoto & The Claws Mail Team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "defs.h"

#include <glib.h>
#include <glib/gi18n.h>

#include "utils.h"
#include "filtering.h"
#include "matcher.h"
#include "matcher_parser.h"
#include "matcher_parser_lex.h"
#include "colorlabel.h"
#include "folder_item_prefs.h"

static gint error = 0;
static gint bool_op = 0;
static gint match_type = 0;
static gchar *header = NULL;

static MatcherProp *prop;

static GSList *matchers_list = NULL;

static gboolean enabled = TRUE;
static gchar *name = NULL;
static gint account_id = 0;
static MatcherList *cond;
static GSList *action_list = NULL;
static FilteringAction *action = NULL;
static gboolean matcher_is_fast = TRUE;
static gboolean disable_warnings = FALSE;

static FilteringProp *filtering;
static gboolean filtering_ptr_externally_managed = FALSE;

static GSList **prefs_filtering = NULL;
static int enable_compatibility = 0;

enum {
        MATCHER_PARSE_FILE,
        MATCHER_PARSE_NO_EOL,
	MATCHER_PARSE_ENABLED,
	MATCHER_PARSE_NAME,
	MATCHER_PARSE_ACCOUNT,
        MATCHER_PARSE_CONDITION,
        MATCHER_PARSE_FILTERING_ACTION,
};

static int matcher_parse_op = MATCHER_PARSE_FILE;


/* ******************************************************************** */
/* redeclarations to avoid warnings */
void matcher_parserrestart(FILE *input_file);
void matcher_parser_init(void);
void matcher_parser_switch_to_buffer(void * new_buffer);
void matcher_parser_delete_buffer(void * b);
void matcher_parserpop_buffer_state(void);
int matcher_parserlex(void);

void matcher_parser_disable_warnings(const gboolean disable)
{
	disable_warnings = disable;
}

void matcher_parser_start_parsing(FILE *f)
{
	matcher_parserlineno = 1;
	matcher_parserrestart(f);
	account_id = 0;
	matcher_parserparse();
}

 
void * matcher_parser_scan_string(const char * str);
 
FilteringProp *matcher_parser_get_filtering(gchar *str)
{
	void *bufstate;
	void *tmp_str = NULL;
	
	/* little hack to allow passing rules with no names */
	if (!strncmp(str, "rulename ", 9))
		tmp_str = g_strdup(str);
	else 
		tmp_str = g_strconcat("rulename \"\" ", str, NULL);

	/* bad coding to enable the sub-grammar matching
	   in yacc */
	matcher_parserlineno = 1;
	matcher_parse_op = MATCHER_PARSE_NO_EOL;
	matcher_parserrestart(NULL);
	matcher_parserpop_buffer_state();
        matcher_parser_init();
	bufstate = matcher_parser_scan_string((const char *) tmp_str);
        matcher_parser_switch_to_buffer(bufstate);
	/* Indicate that we will be using the global "filtering" pointer,
	 * so that yyparse does not free it in "filtering_action_list"
	 * section. */
	filtering_ptr_externally_managed = TRUE;
	if (matcher_parserparse() != 0)
		filtering = NULL;
	matcher_parse_op = MATCHER_PARSE_FILE;
	matcher_parser_delete_buffer(bufstate);
	g_free(tmp_str);
	filtering_ptr_externally_managed = FALSE; /* Return to normal. */
	return filtering;
}

static gboolean check_quote_symetry(gchar *str)
{
	const gchar *walk;
	int ret = 0;
	
	if (str == NULL)
		return TRUE; /* heh, that's symetric */
	if (*str == '\0')
		return TRUE;
	for (walk = str; *walk; walk++) {
		if (*walk == '\"') {
			if (walk == str 	/* first char */
			|| *(walk - 1) != '\\') /* not escaped */
				ret ++;
		}
	}
	return !(ret % 2);
}

MatcherList *matcher_parser_get_name(gchar *str)
{
	void *bufstate;

	if (!check_quote_symetry(str)) {
		cond = NULL;
		return cond;
	}
	
	/* bad coding to enable the sub-grammar matching
	   in yacc */
	matcher_parserlineno = 1;
	matcher_parse_op = MATCHER_PARSE_NAME;
	matcher_parserrestart(NULL);
	matcher_parserpop_buffer_state();
        matcher_parser_init();
	bufstate = matcher_parser_scan_string(str);
	matcher_parserparse();
	matcher_parse_op = MATCHER_PARSE_FILE;
	matcher_parser_delete_buffer(bufstate);
	return cond;
}

MatcherList *matcher_parser_get_enabled(gchar *str)
{
	void *bufstate;

	if (!check_quote_symetry(str)) {
		cond = NULL;
		return cond;
	}
	
	/* bad coding to enable the sub-grammar matching
	   in yacc */
	matcher_parserlineno = 1;
	matcher_parse_op = MATCHER_PARSE_ENABLED;
	matcher_parserrestart(NULL);
	matcher_parserpop_buffer_state();
	matcher_parser_init();
	bufstate = matcher_parser_scan_string(str);
	matcher_parserparse();
	matcher_parse_op = MATCHER_PARSE_FILE;
	matcher_parser_delete_buffer(bufstate);
	return cond;
}

MatcherList *matcher_parser_get_account(gchar *str)
{
	void *bufstate;

	if (!check_quote_symetry(str)) {
		cond = NULL;
		return cond;
	}
	
	/* bad coding to enable the sub-grammar matching
	   in yacc */
	matcher_parserlineno = 1;
	matcher_parse_op = MATCHER_PARSE_ACCOUNT;
	matcher_parserrestart(NULL);
	matcher_parserpop_buffer_state();
	matcher_parser_init();
	bufstate = matcher_parser_scan_string(str);
	matcher_parserparse();
	matcher_parse_op = MATCHER_PARSE_FILE;
	matcher_parser_delete_buffer(bufstate);
	return cond;
}

MatcherList *matcher_parser_get_cond(gchar *str, gboolean *is_fast)
{
	void *bufstate;

	if (!check_quote_symetry(str)) {
		cond = NULL;
		return cond;
	}
	
	matcher_is_fast = TRUE;
	/* bad coding to enable the sub-grammar matching
	   in yacc */
	matcher_parserlineno = 1;
	matcher_parse_op = MATCHER_PARSE_CONDITION;
	matcher_parserrestart(NULL);
	matcher_parserpop_buffer_state();
        matcher_parser_init();
	bufstate = matcher_parser_scan_string(str);
	matcher_parserparse();
	matcher_parse_op = MATCHER_PARSE_FILE;
	matcher_parser_delete_buffer(bufstate);
	if (is_fast)
		*is_fast = matcher_is_fast;
	return cond;
}

GSList *matcher_parser_get_action_list(gchar *str)
{
	void *bufstate;

	if (!check_quote_symetry(str)) {
		action_list = NULL;
		return action_list;
	}
	
	/* bad coding to enable the sub-grammar matching
	   in yacc */
	matcher_parserlineno = 1;
	matcher_parse_op = MATCHER_PARSE_FILTERING_ACTION;
	matcher_parserrestart(NULL);
	matcher_parserpop_buffer_state();
        matcher_parser_init();
	bufstate = matcher_parser_scan_string(str);
	matcher_parserparse();
	matcher_parse_op = MATCHER_PARSE_FILE;
	matcher_parser_delete_buffer(bufstate);
	return action_list;
}

MatcherProp *matcher_parser_get_prop(gchar *str)
{
	MatcherList *list;
	MatcherProp *prop;

	matcher_parserlineno = 1;
	list = matcher_parser_get_cond(str, NULL);
	if (list == NULL)
		return NULL;

	if (list->matchers == NULL)
		return NULL;

	if (list->matchers->next != NULL)
		return NULL;

	prop = list->matchers->data;

	g_slist_free(list->matchers);
	g_free(list);

	return prop;
}

void matcher_parsererror(char *str)
{
	GSList *l;

	if (matchers_list) {
		for (l = matchers_list; l != NULL; l = g_slist_next(l)) {
			matcherprop_free((MatcherProp *)
					 l->data);
			l->data = NULL;
		}
		g_slist_free(matchers_list);
		matchers_list = NULL;
	}
	cond = NULL;
	if (!disable_warnings)
		g_warning("filtering parsing: %i: %s",
		  	matcher_parserlineno, str);
	error = 1;
}

int matcher_parserwrap(void)
{
	return 1;
}

#line 381 "matcher_parser_parse.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_MATCHER_PARSER_PARSE_H_INCLUDED
# define YY_YY_MATCHER_PARSER_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MATCHER_ALL = 258,
    MATCHER_UNREAD = 259,
    MATCHER_NOT_UNREAD = 260,
    MATCHER_NEW = 261,
    MATCHER_NOT_NEW = 262,
    MATCHER_MARKED = 263,
    MATCHER_NOT_MARKED = 264,
    MATCHER_DELETED = 265,
    MATCHER_NOT_DELETED = 266,
    MATCHER_REPLIED = 267,
    MATCHER_NOT_REPLIED = 268,
    MATCHER_FORWARDED = 269,
    MATCHER_NOT_FORWARDED = 270,
    MATCHER_SUBJECT = 271,
    MATCHER_NOT_SUBJECT = 272,
    MATCHER_FROM = 273,
    MATCHER_NOT_FROM = 274,
    MATCHER_TO = 275,
    MATCHER_NOT_TO = 276,
    MATCHER_CC = 277,
    MATCHER_NOT_CC = 278,
    MATCHER_TO_OR_CC = 279,
    MATCHER_NOT_TO_AND_NOT_CC = 280,
    MATCHER_AGE_GREATER = 281,
    MATCHER_AGE_LOWER = 282,
    MATCHER_NEWSGROUPS = 283,
    MATCHER_AGE_GREATER_HOURS = 284,
    MATCHER_AGE_LOWER_HOURS = 285,
    MATCHER_NOT_NEWSGROUPS = 286,
    MATCHER_INREPLYTO = 287,
    MATCHER_NOT_INREPLYTO = 288,
    MATCHER_MESSAGEID = 289,
    MATCHER_NOT_MESSAGEID = 290,
    MATCHER_REFERENCES = 291,
    MATCHER_NOT_REFERENCES = 292,
    MATCHER_SCORE_GREATER = 293,
    MATCHER_SCORE_LOWER = 294,
    MATCHER_HEADER = 295,
    MATCHER_NOT_HEADER = 296,
    MATCHER_HEADERS_PART = 297,
    MATCHER_NOT_HEADERS_PART = 298,
    MATCHER_MESSAGE = 299,
    MATCHER_HEADERS_CONT = 300,
    MATCHER_NOT_HEADERS_CONT = 301,
    MATCHER_NOT_MESSAGE = 302,
    MATCHER_BODY_PART = 303,
    MATCHER_NOT_BODY_PART = 304,
    MATCHER_TEST = 305,
    MATCHER_NOT_TEST = 306,
    MATCHER_MATCHCASE = 307,
    MATCHER_MATCH = 308,
    MATCHER_REGEXPCASE = 309,
    MATCHER_REGEXP = 310,
    MATCHER_SCORE = 311,
    MATCHER_MOVE = 312,
    MATCHER_FOUND_IN_ADDRESSBOOK = 313,
    MATCHER_NOT_FOUND_IN_ADDRESSBOOK = 314,
    MATCHER_IN = 315,
    MATCHER_COPY = 316,
    MATCHER_DELETE = 317,
    MATCHER_MARK = 318,
    MATCHER_UNMARK = 319,
    MATCHER_LOCK = 320,
    MATCHER_UNLOCK = 321,
    MATCHER_EXECUTE = 322,
    MATCHER_MARK_AS_READ = 323,
    MATCHER_MARK_AS_UNREAD = 324,
    MATCHER_FORWARD = 325,
    MATCHER_MARK_AS_SPAM = 326,
    MATCHER_MARK_AS_HAM = 327,
    MATCHER_FORWARD_AS_ATTACHMENT = 328,
    MATCHER_EOL = 329,
    MATCHER_OR = 330,
    MATCHER_AND = 331,
    MATCHER_COLOR = 332,
    MATCHER_SCORE_EQUAL = 333,
    MATCHER_REDIRECT = 334,
    MATCHER_SIZE_GREATER = 335,
    MATCHER_SIZE_SMALLER = 336,
    MATCHER_SIZE_EQUAL = 337,
    MATCHER_LOCKED = 338,
    MATCHER_NOT_LOCKED = 339,
    MATCHER_PARTIAL = 340,
    MATCHER_NOT_PARTIAL = 341,
    MATCHER_COLORLABEL = 342,
    MATCHER_NOT_COLORLABEL = 343,
    MATCHER_IGNORE_THREAD = 344,
    MATCHER_NOT_IGNORE_THREAD = 345,
    MATCHER_WATCH_THREAD = 346,
    MATCHER_NOT_WATCH_THREAD = 347,
    MATCHER_CHANGE_SCORE = 348,
    MATCHER_SET_SCORE = 349,
    MATCHER_ADD_TO_ADDRESSBOOK = 350,
    MATCHER_STOP = 351,
    MATCHER_HIDE = 352,
    MATCHER_IGNORE = 353,
    MATCHER_WATCH = 354,
    MATCHER_SPAM = 355,
    MATCHER_NOT_SPAM = 356,
    MATCHER_HAS_ATTACHMENT = 357,
    MATCHER_HAS_NO_ATTACHMENT = 358,
    MATCHER_SIGNED = 359,
    MATCHER_NOT_SIGNED = 360,
    MATCHER_TAG = 361,
    MATCHER_NOT_TAG = 362,
    MATCHER_SET_TAG = 363,
    MATCHER_UNSET_TAG = 364,
    MATCHER_TAGGED = 365,
    MATCHER_NOT_TAGGED = 366,
    MATCHER_CLEAR_TAGS = 367,
    MATCHER_ENABLED = 368,
    MATCHER_DISABLED = 369,
    MATCHER_RULENAME = 370,
    MATCHER_ACCOUNT = 371,
    MATCHER_STRING = 372,
    MATCHER_SECTION = 373,
    MATCHER_INTEGER = 374
  };
#endif
/* Tokens.  */
#define MATCHER_ALL 258
#define MATCHER_UNREAD 259
#define MATCHER_NOT_UNREAD 260
#define MATCHER_NEW 261
#define MATCHER_NOT_NEW 262
#define MATCHER_MARKED 263
#define MATCHER_NOT_MARKED 264
#define MATCHER_DELETED 265
#define MATCHER_NOT_DELETED 266
#define MATCHER_REPLIED 267
#define MATCHER_NOT_REPLIED 268
#define MATCHER_FORWARDED 269
#define MATCHER_NOT_FORWARDED 270
#define MATCHER_SUBJECT 271
#define MATCHER_NOT_SUBJECT 272
#define MATCHER_FROM 273
#define MATCHER_NOT_FROM 274
#define MATCHER_TO 275
#define MATCHER_NOT_TO 276
#define MATCHER_CC 277
#define MATCHER_NOT_CC 278
#define MATCHER_TO_OR_CC 279
#define MATCHER_NOT_TO_AND_NOT_CC 280
#define MATCHER_AGE_GREATER 281
#define MATCHER_AGE_LOWER 282
#define MATCHER_NEWSGROUPS 283
#define MATCHER_AGE_GREATER_HOURS 284
#define MATCHER_AGE_LOWER_HOURS 285
#define MATCHER_NOT_NEWSGROUPS 286
#define MATCHER_INREPLYTO 287
#define MATCHER_NOT_INREPLYTO 288
#define MATCHER_MESSAGEID 289
#define MATCHER_NOT_MESSAGEID 290
#define MATCHER_REFERENCES 291
#define MATCHER_NOT_REFERENCES 292
#define MATCHER_SCORE_GREATER 293
#define MATCHER_SCORE_LOWER 294
#define MATCHER_HEADER 295
#define MATCHER_NOT_HEADER 296
#define MATCHER_HEADERS_PART 297
#define MATCHER_NOT_HEADERS_PART 298
#define MATCHER_MESSAGE 299
#define MATCHER_HEADERS_CONT 300
#define MATCHER_NOT_HEADERS_CONT 301
#define MATCHER_NOT_MESSAGE 302
#define MATCHER_BODY_PART 303
#define MATCHER_NOT_BODY_PART 304
#define MATCHER_TEST 305
#define MATCHER_NOT_TEST 306
#define MATCHER_MATCHCASE 307
#define MATCHER_MATCH 308
#define MATCHER_REGEXPCASE 309
#define MATCHER_REGEXP 310
#define MATCHER_SCORE 311
#define MATCHER_MOVE 312
#define MATCHER_FOUND_IN_ADDRESSBOOK 313
#define MATCHER_NOT_FOUND_IN_ADDRESSBOOK 314
#define MATCHER_IN 315
#define MATCHER_COPY 316
#define MATCHER_DELETE 317
#define MATCHER_MARK 318
#define MATCHER_UNMARK 319
#define MATCHER_LOCK 320
#define MATCHER_UNLOCK 321
#define MATCHER_EXECUTE 322
#define MATCHER_MARK_AS_READ 323
#define MATCHER_MARK_AS_UNREAD 324
#define MATCHER_FORWARD 325
#define MATCHER_MARK_AS_SPAM 326
#define MATCHER_MARK_AS_HAM 327
#define MATCHER_FORWARD_AS_ATTACHMENT 328
#define MATCHER_EOL 329
#define MATCHER_OR 330
#define MATCHER_AND 331
#define MATCHER_COLOR 332
#define MATCHER_SCORE_EQUAL 333
#define MATCHER_REDIRECT 334
#define MATCHER_SIZE_GREATER 335
#define MATCHER_SIZE_SMALLER 336
#define MATCHER_SIZE_EQUAL 337
#define MATCHER_LOCKED 338
#define MATCHER_NOT_LOCKED 339
#define MATCHER_PARTIAL 340
#define MATCHER_NOT_PARTIAL 341
#define MATCHER_COLORLABEL 342
#define MATCHER_NOT_COLORLABEL 343
#define MATCHER_IGNORE_THREAD 344
#define MATCHER_NOT_IGNORE_THREAD 345
#define MATCHER_WATCH_THREAD 346
#define MATCHER_NOT_WATCH_THREAD 347
#define MATCHER_CHANGE_SCORE 348
#define MATCHER_SET_SCORE 349
#define MATCHER_ADD_TO_ADDRESSBOOK 350
#define MATCHER_STOP 351
#define MATCHER_HIDE 352
#define MATCHER_IGNORE 353
#define MATCHER_WATCH 354
#define MATCHER_SPAM 355
#define MATCHER_NOT_SPAM 356
#define MATCHER_HAS_ATTACHMENT 357
#define MATCHER_HAS_NO_ATTACHMENT 358
#define MATCHER_SIGNED 359
#define MATCHER_NOT_SIGNED 360
#define MATCHER_TAG 361
#define MATCHER_NOT_TAG 362
#define MATCHER_SET_TAG 363
#define MATCHER_UNSET_TAG 364
#define MATCHER_TAGGED 365
#define MATCHER_NOT_TAGGED 366
#define MATCHER_CLEAR_TAGS 367
#define MATCHER_ENABLED 368
#define MATCHER_DISABLED 369
#define MATCHER_RULENAME 370
#define MATCHER_ACCOUNT 371
#define MATCHER_STRING 372
#define MATCHER_SECTION 373
#define MATCHER_INTEGER 374

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 316 "matcher_parser_parse.y" /* yacc.c:355  */

	char *str;
	int value;

#line 664 "matcher_parser_parse.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MATCHER_PARSER_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 681 "matcher_parser_parse.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   737

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  120
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   374

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   374,   374,   374,   382,   384,   388,   390,   390,   392,
     398,   431,   432,   433,   434,   435,   436,   445,   454,   463,
     472,   481,   490,   494,   498,   505,   512,   519,   560,   561,
     565,   573,   577,   581,   585,   592,   600,   604,   612,   616,
     623,   630,   637,   644,   651,   658,   665,   672,   679,   686,
     693,   700,   707,   714,   721,   728,   735,   742,   749,   756,
     763,   770,   777,   784,   795,   806,   813,   820,   827,   834,
     843,   852,   861,   870,   879,   888,   897,   906,   915,   924,
     933,   942,   949,   956,   965,   974,   983,   992,  1001,  1010,
    1019,  1028,  1037,  1046,  1055,  1064,  1073,  1082,  1091,  1099,
    1107,  1116,  1115,  1129,  1128,  1141,  1150,  1159,  1168,  1178,
    1177,  1191,  1190,  1203,  1212,  1221,  1230,  1239,  1248,  1260,
    1269,  1278,  1287,  1296,  1303,  1312,  1319,  1326,  1333,  1340,
    1347,  1354,  1361,  1368,  1375,  1387,  1399,  1411,  1420,  1429,
    1437,  1445,  1449,  1453,  1458,  1457,  1470
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MATCHER_ALL", "MATCHER_UNREAD",
  "MATCHER_NOT_UNREAD", "MATCHER_NEW", "MATCHER_NOT_NEW", "MATCHER_MARKED",
  "MATCHER_NOT_MARKED", "MATCHER_DELETED", "MATCHER_NOT_DELETED",
  "MATCHER_REPLIED", "MATCHER_NOT_REPLIED", "MATCHER_FORWARDED",
  "MATCHER_NOT_FORWARDED", "MATCHER_SUBJECT", "MATCHER_NOT_SUBJECT",
  "MATCHER_FROM", "MATCHER_NOT_FROM", "MATCHER_TO", "MATCHER_NOT_TO",
  "MATCHER_CC", "MATCHER_NOT_CC", "MATCHER_TO_OR_CC",
  "MATCHER_NOT_TO_AND_NOT_CC", "MATCHER_AGE_GREATER", "MATCHER_AGE_LOWER",
  "MATCHER_NEWSGROUPS", "MATCHER_AGE_GREATER_HOURS",
  "MATCHER_AGE_LOWER_HOURS", "MATCHER_NOT_NEWSGROUPS", "MATCHER_INREPLYTO",
  "MATCHER_NOT_INREPLYTO", "MATCHER_MESSAGEID", "MATCHER_NOT_MESSAGEID",
  "MATCHER_REFERENCES", "MATCHER_NOT_REFERENCES", "MATCHER_SCORE_GREATER",
  "MATCHER_SCORE_LOWER", "MATCHER_HEADER", "MATCHER_NOT_HEADER",
  "MATCHER_HEADERS_PART", "MATCHER_NOT_HEADERS_PART", "MATCHER_MESSAGE",
  "MATCHER_HEADERS_CONT", "MATCHER_NOT_HEADERS_CONT",
  "MATCHER_NOT_MESSAGE", "MATCHER_BODY_PART", "MATCHER_NOT_BODY_PART",
  "MATCHER_TEST", "MATCHER_NOT_TEST", "MATCHER_MATCHCASE", "MATCHER_MATCH",
  "MATCHER_REGEXPCASE", "MATCHER_REGEXP", "MATCHER_SCORE", "MATCHER_MOVE",
  "MATCHER_FOUND_IN_ADDRESSBOOK", "MATCHER_NOT_FOUND_IN_ADDRESSBOOK",
  "MATCHER_IN", "MATCHER_COPY", "MATCHER_DELETE", "MATCHER_MARK",
  "MATCHER_UNMARK", "MATCHER_LOCK", "MATCHER_UNLOCK", "MATCHER_EXECUTE",
  "MATCHER_MARK_AS_READ", "MATCHER_MARK_AS_UNREAD", "MATCHER_FORWARD",
  "MATCHER_MARK_AS_SPAM", "MATCHER_MARK_AS_HAM",
  "MATCHER_FORWARD_AS_ATTACHMENT", "MATCHER_EOL", "MATCHER_OR",
  "MATCHER_AND", "MATCHER_COLOR", "MATCHER_SCORE_EQUAL",
  "MATCHER_REDIRECT", "MATCHER_SIZE_GREATER", "MATCHER_SIZE_SMALLER",
  "MATCHER_SIZE_EQUAL", "MATCHER_LOCKED", "MATCHER_NOT_LOCKED",
  "MATCHER_PARTIAL", "MATCHER_NOT_PARTIAL", "MATCHER_COLORLABEL",
  "MATCHER_NOT_COLORLABEL", "MATCHER_IGNORE_THREAD",
  "MATCHER_NOT_IGNORE_THREAD", "MATCHER_WATCH_THREAD",
  "MATCHER_NOT_WATCH_THREAD", "MATCHER_CHANGE_SCORE", "MATCHER_SET_SCORE",
  "MATCHER_ADD_TO_ADDRESSBOOK", "MATCHER_STOP", "MATCHER_HIDE",
  "MATCHER_IGNORE", "MATCHER_WATCH", "MATCHER_SPAM", "MATCHER_NOT_SPAM",
  "MATCHER_HAS_ATTACHMENT", "MATCHER_HAS_NO_ATTACHMENT", "MATCHER_SIGNED",
  "MATCHER_NOT_SIGNED", "MATCHER_TAG", "MATCHER_NOT_TAG",
  "MATCHER_SET_TAG", "MATCHER_UNSET_TAG", "MATCHER_TAGGED",
  "MATCHER_NOT_TAGGED", "MATCHER_CLEAR_TAGS", "MATCHER_ENABLED",
  "MATCHER_DISABLED", "MATCHER_RULENAME", "MATCHER_ACCOUNT",
  "MATCHER_STRING", "MATCHER_SECTION", "MATCHER_INTEGER", "$accept",
  "file", "$@1", "file_line_list", "file_line", "$@2",
  "section_notification", "instruction", "enabled", "name", "account",
  "filtering", "filtering_action_list", "filtering_action_b", "match_type",
  "condition", "condition_list", "bool_op", "one_condition", "$@3", "$@4",
  "$@5", "$@6", "filtering_action", "$@7", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374
};
# endif

#define YYPACT_NINF -227

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-227)))

#define YYTABLE_NINF -8

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -227,    13,   233,  -227,   -52,   -51,  -227,   117,   398,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,   -95,   -84,     5,   -83,
     -82,     5,     5,     5,     5,     5,     5,     5,   -68,   -64,
     -56,   -55,     5,     5,     5,     5,     5,     5,     5,     5,
     -54,   -53,   -50,   -49,   -40,   -39,   -38,  -227,  -227,  -227,
    -227,  -227,   -37,  -227,  -227,   -35,  -227,  -227,   -32,  -227,
     -31,   -29,   -28,   -26,   -25,   -24,  -227,  -227,  -227,  -227,
     -22,   -21,  -227,  -227,  -227,  -227,   -20,   -19,   -36,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,     5,
       5,   -16,   -15,  -227,  -227,  -227,  -227,  -227,   -14,   -13,
    -227,   -62,   626,  -227,  -227,   -23,  -227,   -66,  -227,  -227,
    -227,  -227,  -227,  -227,   -12,   -10,    -9,    -8,    -7,    -6,
      -5,    -4,    -3,    -2,  -227,  -227,    -1,  -227,  -227,     2,
      53,    54,    55,    60,   169,   170,  -227,  -227,  -227,  -227,
     171,   176,   191,   192,   235,   236,   237,   238,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,   239,   240,  -227,  -227,
     242,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,   243,
     244,  -227,  -227,  -227,  -227,   512,   -23,  -227,  -227,  -227,
     626,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,     5,
       5,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,     6,
       7,  -227,  -227,  -227,   245,  -227,  -227,   626,   -23,    18,
    -227,  -227,   246,   247,   248,   249,  -227,   -23,    22,  -227,
    -227,  -227,  -227,  -227,    30,  -227,  -227
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     0,     0,     6,
       9,    10,     4,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   126,   127,
     128,   129,     0,   130,   131,     0,   132,   133,     0,    22,
       0,     0,     0,     0,     0,     0,    53,    54,    61,    62,
       0,     0,    65,    66,    67,    68,     0,     0,     0,   146,
     141,   142,   143,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,    81,    82,   123,    23,    24,     0,     0,
       8,    17,    19,    18,    21,    29,    20,    35,    37,    30,
      31,    32,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,    95,    96,   101,   103,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   118,
     139,   120,   109,   111,   124,   119,     0,     0,   137,    97,
       0,    98,    99,   100,    63,    64,   138,   140,   144,     0,
       0,   121,   122,    25,    26,     0,     0,    28,    39,    38,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    87,    88,    91,    92,    89,    90,    93,    94,     0,
       0,   105,   106,   113,   107,   108,   114,   115,   116,     0,
       0,   134,   135,   136,     0,    79,    80,     0,     0,    16,
      27,    36,     0,     0,     0,     0,   145,     0,    14,    15,
     102,   104,   110,   112,    12,    13,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,  -227,    58,  -227,  -227,  -227,  -227,  -227,   229,
     172,  -226,    44,  -227,   -27,   163,  -227,  -227,   168,  -227,
    -227,  -227,  -227,  -227,  -227
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,   120,   121,   122,
     123,   239,   240,   125,   134,   126,   127,   200,   128,   219,
     220,   229,   230,   129,   234
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     135,   136,   137,   138,   139,   140,   141,   142,   143,   198,
     199,   146,   248,     3,   149,   150,   151,   152,   153,   154,
     155,   254,    10,    11,   144,   160,   161,   162,   163,   164,
     165,   166,   167,    62,    63,   145,   147,   148,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   156,   124,   118,    80,   157,    82,   130,   131,   132,
     133,   158,   159,   168,   169,    12,   244,   245,   171,   170,
      96,    97,    98,    99,   100,   101,   102,   172,   173,   174,
     175,   188,   189,   190,   176,   111,   112,   177,   178,   115,
     179,   180,   249,   181,   182,   183,   255,   184,   185,   186,
     187,   191,   192,   193,   256,   201,   194,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -5,     4,   212,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,   197,
     213,   214,   215,    -7,    -7,    -7,    -7,   216,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,   242,   243,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,     4,     5,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,   196,   217,   218,   221,    -7,
      -7,    -7,    -7,   222,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,   223,   224,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
     195,     5,   225,   226,   227,   228,   231,   232,   238,   233,
     235,   236,   246,   250,   251,   252,   253,   237,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,     0,     0,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     0,     0,     0,     0,     0,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
       0,     0,   113,   114,     0,     0,     0,     0,   119,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,     0,     0,     0,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,     0,     0,   113,   114
};

static const yytype_int16 yycheck[] =
{
      27,    28,    29,    30,    31,    32,    33,    34,    35,    75,
      76,    38,   238,     0,    41,    42,    43,    44,    45,    46,
      47,   247,    74,    74,   119,    52,    53,    54,    55,    56,
      57,    58,    59,    56,    57,   119,   119,   119,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   119,     8,   115,    77,   119,    79,    52,    53,    54,
      55,   117,   117,   117,   117,     7,    60,    60,   117,   119,
      93,    94,    95,    96,    97,    98,    99,   117,   117,   117,
     117,   117,   109,   110,   119,   108,   109,   119,   119,   112,
     119,   119,    74,   119,   119,   119,    74,   119,   119,   119,
     119,   117,   117,   117,    74,   117,   119,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,     0,     1,   117,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   125,
     117,   117,   117,    56,    57,    58,    59,   117,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   219,   220,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     1,   118,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,   122,   117,   117,   117,    56,
      57,    58,    59,   117,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   117,   117,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     121,   118,   117,   117,   117,   117,   117,   117,   195,   117,
     117,   117,   117,   117,   117,   117,   117,   195,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,    -1,   110,   111,    -1,    -1,    -1,    -1,   116,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,    -1,   110,   111
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   121,   122,     0,     1,   118,   123,   124,   125,   126,
      74,    74,   123,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    56,    57,    58,    59,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     127,   128,   129,   130,   132,   133,   135,   136,   138,   143,
      52,    53,    54,    55,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   119,   119,   134,   119,   119,   134,
     134,   134,   134,   134,   134,   134,   119,   119,   117,   117,
     134,   134,   134,   134,   134,   134,   134,   134,   117,   117,
     119,   117,   117,   117,   117,   117,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   117,   134,
     134,   117,   117,   117,   119,   129,   135,   132,    75,    76,
     137,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   139,
     140,   117,   117,   117,   117,   117,   117,   117,   117,   141,
     142,   117,   117,   117,   144,   117,   117,   130,   135,   131,
     132,   138,   134,   134,    60,    60,   117,   135,   131,    74,
     117,   117,   117,   117,   131,    74,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   120,   122,   121,   123,   123,   124,   125,   124,   124,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   129,   130,   131,   132,   132,
     133,   134,   134,   134,   134,   135,   136,   136,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   139,   138,   140,   138,   138,   138,   138,   138,   141,
     138,   142,   138,   138,   138,   138,   138,   138,   138,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   143,   143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     0,     2,     2,
       2,     6,     5,     5,     4,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     0,     5,     0,     5,     3,     3,     3,     3,     0,
       5,     0,     5,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     2,     2,     2,
       2,     1,     1,     1,     0,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 374 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	if (matcher_parse_op == MATCHER_PARSE_FILE) {
		prefs_filtering = &pre_global_processing;
	}
}
#line 2082 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 7:
#line 390 "matcher_parser_parse.y" /* yacc.c:1646  */
    { action_list = NULL; }
#line 2088 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 393 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	yyerrok;
}
#line 2096 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 10:
#line 399 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *folder = (yyvsp[-1].str);
	FolderItem *item = NULL;

	if (matcher_parse_op == MATCHER_PARSE_FILE) {
                enable_compatibility = 0;
		if (!strcmp(folder, "global")) {
                        /* backward compatibility */
                        enable_compatibility = 1;
                }
		else if (!strcmp(folder, "preglobal")) {
			prefs_filtering = &pre_global_processing;
                }
		else if (!strcmp(folder, "postglobal")) {
			prefs_filtering = &post_global_processing;
                }
		else if (!strcmp(folder, "filtering")) {
                        prefs_filtering = &filtering_rules;
		}
                else {
			item = folder_find_item_from_identifier(folder);
			if (item != NULL) {
				prefs_filtering = &item->prefs->processing;
			} else {
				prefs_filtering = NULL;
			}
		}
	}
}
#line 2130 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 16:
#line 437 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	if (matcher_parse_op == MATCHER_PARSE_NO_EOL)
		YYACCEPT;
	else {
		matcher_parsererror("parse error [no eol]");
		YYERROR;
	}
}
#line 2143 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 17:
#line 446 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	if (matcher_parse_op == MATCHER_PARSE_ENABLED)
		YYACCEPT;
	else {
		matcher_parsererror("parse error [enabled]");
		YYERROR;
	}
}
#line 2156 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 18:
#line 455 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	if (matcher_parse_op == MATCHER_PARSE_ACCOUNT)
		YYACCEPT;
	else {
		matcher_parsererror("parse error [account]");
		YYERROR;
	}
}
#line 2169 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 19:
#line 464 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	if (matcher_parse_op == MATCHER_PARSE_NAME)
		YYACCEPT;
	else {
		matcher_parsererror("parse error [name]");
		YYERROR;
	}
}
#line 2182 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 20:
#line 473 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	if (matcher_parse_op == MATCHER_PARSE_CONDITION)
		YYACCEPT;
	else {
		matcher_parsererror("parse error [condition]");
		YYERROR;
	}
}
#line 2195 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 21:
#line 482 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	if (matcher_parse_op == MATCHER_PARSE_FILTERING_ACTION)
		YYACCEPT;
	else {
		matcher_parsererror("parse error [filtering action]");
		YYERROR;
	}
}
#line 2208 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 23:
#line 495 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	enabled = TRUE;
}
#line 2216 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 24:
#line 499 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	enabled = FALSE;
}
#line 2224 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 506 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	name = g_strdup((yyvsp[0].str));
}
#line 2232 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 513 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	account_id = strtol((yyvsp[0].str), NULL, 10);
}
#line 2240 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 520 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	filtering = filteringprop_new(enabled, name, account_id, cond, action_list);
	enabled = TRUE;
	account_id = 0;
	g_free(name);
	name = NULL;
        if (enable_compatibility) {
                prefs_filtering = &filtering_rules;
                if (action_list != NULL) {
                        FilteringAction * first_action;
                        
                        first_action = action_list->data;
                        
                        if (first_action->type == MATCHACTION_CHANGE_SCORE)
                                prefs_filtering = &pre_global_processing;
                }
        }
        
	cond = NULL;
	action_list = NULL;
        
	if ((matcher_parse_op == MATCHER_PARSE_FILE) &&
            (prefs_filtering != NULL)) {
		*prefs_filtering = g_slist_append(*prefs_filtering,
						  filtering);
		filtering = NULL;
	} else if (!filtering_ptr_externally_managed) {
		/* If filtering_ptr_externally_managed was TRUE, it
		 * would mean that some function higher in the stack is
		 * interested in the data "filtering" is pointing at, so
		 * we would not free it. That function has to free it itself.
		 * At the time of writing this, the only function that
		 * does this is matcher_parser_get_filtering(). */
		filteringprop_free(filtering);
		filtering = NULL;
	}
}
#line 2282 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 566 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
        action_list = g_slist_append(action_list, action);
        action = NULL;
}
#line 2291 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 574 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	match_type = MATCHTYPE_MATCHCASE;
}
#line 2299 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 578 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	match_type = MATCHTYPE_MATCH;
}
#line 2307 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 582 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	match_type = MATCHTYPE_REGEXPCASE;
}
#line 2315 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 586 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	match_type = MATCHTYPE_REGEXP;
}
#line 2323 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 593 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	cond = matcherlist_new(matchers_list, (bool_op == MATCHERBOOL_AND));
	matchers_list = NULL;
}
#line 2332 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 601 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	matchers_list = g_slist_append(matchers_list, prop);
}
#line 2340 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 37:
#line 605 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	matchers_list = NULL;
	matchers_list = g_slist_append(matchers_list, prop);
}
#line 2349 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 38:
#line 613 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	bool_op = MATCHERBOOL_AND;
}
#line 2357 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 617 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	bool_op = MATCHERBOOL_OR;
}
#line 2365 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 624 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_ALL;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2376 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 631 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_UNREAD;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2387 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 638 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_UNREAD;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2398 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 645 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NEW;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2409 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 652 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_NEW;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2420 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 659 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_MARKED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2431 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 666 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_MARKED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2442 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 47:
#line 673 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_DELETED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2453 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 680 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_DELETED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2464 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 687 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_REPLIED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2475 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 50:
#line 694 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_REPLIED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2486 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 51:
#line 701 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_FORWARDED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2497 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 52:
#line 708 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_FORWARDED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2508 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 53:
#line 715 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_LOCKED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2519 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 54:
#line 722 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_LOCKED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2530 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 55:
#line 729 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_SPAM;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2541 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 56:
#line 736 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_SPAM;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2552 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 57:
#line 743 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_HAS_ATTACHMENT;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2563 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 58:
#line 750 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_HAS_NO_ATTACHMENT;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2574 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 59:
#line 757 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_SIGNED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2585 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 60:
#line 764 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_SIGNED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2596 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 61:
#line 771 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_PARTIAL;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2607 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 62:
#line 778 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_PARTIAL;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2618 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 63:
#line 785 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_COLORLABEL;
	value = strtol((yyvsp[0].str), NULL, 10);
	if (value < 0) value = 0;
	else if (value > COLORLABELS) value = COLORLABELS;
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 2633 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 64:
#line 796 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_NOT_COLORLABEL;
	value = strtol((yyvsp[0].str), NULL, 0);
	if (value < 0) value = 0;
	else if (value > COLORLABELS) value = COLORLABELS;
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 2648 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 65:
#line 807 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_IGNORE_THREAD;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2659 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 66:
#line 814 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_IGNORE_THREAD;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2670 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 67:
#line 821 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_WATCH_THREAD;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2681 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 68:
#line 828 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_WATCH_THREAD;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2692 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 69:
#line 835 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_SUBJECT;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2705 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 70:
#line 844 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_SUBJECT;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2718 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 71:
#line 853 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_FROM;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2731 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 72:
#line 862 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_FROM;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2744 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 73:
#line 871 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_TO;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2757 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 74:
#line 880 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_TO;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2770 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 75:
#line 889 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_CC;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2783 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 76:
#line 898 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_CC;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2796 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 77:
#line 907 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_TO_OR_CC;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2809 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 78:
#line 916 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_TO_AND_NOT_CC;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2822 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 79:
#line 925 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_TAG;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2835 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 80:
#line 934 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_TAG;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2848 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 81:
#line 943 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_TAGGED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2859 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 82:
#line 950 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;

	criteria = MATCHCRITERIA_NOT_TAGGED;
	prop = matcherprop_new(criteria, NULL, 0, NULL, 0);
}
#line 2870 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 83:
#line 957 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_AGE_GREATER;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 2883 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 84:
#line 966 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_AGE_LOWER;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 2896 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 85:
#line 975 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_AGE_GREATER_HOURS;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 2909 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 86:
#line 984 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_AGE_LOWER_HOURS;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 2922 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 87:
#line 993 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NEWSGROUPS;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2935 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1002 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_NEWSGROUPS;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2948 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1011 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_MESSAGEID;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2961 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1020 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_MESSAGEID;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2974 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1029 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_INREPLYTO;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 2987 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1038 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_INREPLYTO;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3000 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1047 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_REFERENCES;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3013 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1056 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_REFERENCES;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3026 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1065 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_SCORE_GREATER;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 3039 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1074 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_SCORE_LOWER;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 3052 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1083 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value = 0;

	criteria = MATCHCRITERIA_SCORE_EQUAL;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 3065 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1092 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value    = 0;
	criteria = MATCHCRITERIA_SIZE_GREATER;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 3077 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1100 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value    = 0;
	criteria = MATCHCRITERIA_SIZE_SMALLER;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 3089 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1108 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gint value    = 0;
	criteria = MATCHCRITERIA_SIZE_EQUAL;
	value = strtol((yyvsp[0].str), NULL, 0);
	prop = matcherprop_new(criteria, NULL, 0, NULL, value);
}
#line 3101 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1116 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	header = g_strdup((yyvsp[0].str));
}
#line 3109 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1119 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_HEADER;
	expr = (yyvsp[-3].str);
	prop = matcherprop_new(criteria, header, match_type, expr, 0);
	g_free(header);
}
#line 3123 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1129 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	header = g_strdup((yyvsp[0].str));
}
#line 3131 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1132 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_NOT_HEADER;
	expr = (yyvsp[-3].str);
	prop = matcherprop_new(criteria, header, match_type, expr, 0);
	g_free(header);
}
#line 3145 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1142 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_HEADERS_PART;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3158 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1151 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_NOT_HEADERS_PART;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3171 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1160 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_HEADERS_CONT;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3184 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1169 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_NOT_HEADERS_CONT;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3197 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1178 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	header = g_strdup((yyvsp[0].str));
}
#line 3205 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1181 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_FOUND_IN_ADDRESSBOOK;
	expr = (yyvsp[-3].str);
	prop = matcherprop_new(criteria, header, match_type, expr, 0);
	g_free(header);
}
#line 3219 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1191 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	header = g_strdup((yyvsp[0].str));
}
#line 3227 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1194 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;

	criteria = MATCHCRITERIA_NOT_FOUND_IN_ADDRESSBOOK;
	expr = (yyvsp[-3].str);
	prop = matcherprop_new(criteria, header, match_type, expr, 0);
	g_free(header);
}
#line 3241 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1204 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_MESSAGE;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3254 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1213 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_NOT_MESSAGE;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3267 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1222 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_BODY_PART;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3280 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1231 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_NOT_BODY_PART;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, match_type, expr, 0);
}
#line 3293 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1240 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_TEST;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, MATCHTYPE_MATCH, expr, 0);
}
#line 3306 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1249 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint criteria = 0;
	gchar *expr = NULL;
	matcher_is_fast = FALSE;
	criteria = MATCHCRITERIA_NOT_TEST;
	expr = (yyvsp[0].str);
	prop = matcherprop_new(criteria, NULL, MATCHTYPE_MATCH, expr, 0);
}
#line 3319 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1261 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *cmd = NULL;
	gint action_type = 0;

	action_type = MATCHACTION_EXECUTE;
	cmd = (yyvsp[0].str);
	action = filteringaction_new(action_type, 0, cmd, 0, 0, NULL);
}
#line 3332 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1270 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *destination = NULL;
	gint action_type = 0;

	action_type = MATCHACTION_MOVE;
	destination = (yyvsp[0].str);
	action = filteringaction_new(action_type, 0, destination, 0, 0, NULL);
}
#line 3345 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1279 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *destination = NULL;
	gint action_type = 0;

	action_type = MATCHACTION_SET_TAG;
	destination = (yyvsp[0].str);
	action = filteringaction_new(action_type, 0, destination, 0, 0, NULL);
}
#line 3358 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1288 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *destination = NULL;
	gint action_type = 0;

	action_type = MATCHACTION_UNSET_TAG;
	destination = (yyvsp[0].str);
	action = filteringaction_new(action_type, 0, destination, 0, 0, NULL);
}
#line 3371 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1297 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_CLEAR_TAGS;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3382 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1304 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *destination = NULL;
	gint action_type = 0;

	action_type = MATCHACTION_COPY;
	destination = (yyvsp[0].str);
	action = filteringaction_new(action_type, 0, destination, 0, 0, NULL);
}
#line 3395 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1313 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_DELETE;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3406 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1320 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_MARK;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3417 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1327 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_UNMARK;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3428 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1334 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_LOCK;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3439 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1341 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_UNLOCK;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3450 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1348 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_MARK_AS_READ;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3461 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1355 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_MARK_AS_UNREAD;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3472 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1362 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_MARK_AS_SPAM;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3483 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1369 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;

	action_type = MATCHACTION_MARK_AS_HAM;
	action = filteringaction_new(action_type, 0, NULL, 0, 0, NULL);
}
#line 3494 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1376 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *destination = NULL;
	gint action_type = 0;
	gint account_id = 0;

	action_type = MATCHACTION_FORWARD;
	account_id = strtol((yyvsp[-1].str), NULL, 10);
	destination = (yyvsp[0].str);
	action = filteringaction_new(action_type,
            account_id, destination, 0, 0, NULL);
}
#line 3510 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1388 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *destination = NULL;
	gint action_type = 0;
	gint account_id = 0;

	action_type = MATCHACTION_FORWARD_AS_ATTACHMENT;
	account_id = strtol((yyvsp[-1].str), NULL, 10);
	destination = (yyvsp[0].str);
	action = filteringaction_new(action_type,
            account_id, destination, 0, 0, NULL);
}
#line 3526 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1400 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *destination = NULL;
	gint action_type = 0;
	gint account_id = 0;

	action_type = MATCHACTION_REDIRECT;
	account_id = strtol((yyvsp[-1].str), NULL, 10);
	destination = (yyvsp[0].str);
	action = filteringaction_new(action_type,
            account_id, destination, 0, 0, NULL);
}
#line 3542 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1412 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gint action_type = 0;
	gint color = 0;

	action_type = MATCHACTION_COLOR;
	color = strtol((yyvsp[0].str), NULL, 10);
	action = filteringaction_new(action_type, 0, NULL, color, 0, NULL);
}
#line 3555 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1421 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
        gint score = 0;
        
        score = strtol((yyvsp[0].str), NULL, 10);
	action = filteringaction_new(MATCHACTION_CHANGE_SCORE, 0,
				     NULL, 0, score, NULL);
}
#line 3567 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1430 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
        gint score = 0;
        
        score = strtol((yyvsp[0].str), NULL, 10);
	action = filteringaction_new(MATCHACTION_CHANGE_SCORE, 0,
				     NULL, 0, score, NULL);
}
#line 3579 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1438 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
        gint score = 0;
        
        score = strtol((yyvsp[0].str), NULL, 10);
	action = filteringaction_new(MATCHACTION_SET_SCORE, 0,
				     NULL, 0, score, NULL);
}
#line 3591 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1446 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	action = filteringaction_new(MATCHACTION_HIDE, 0, NULL, 0, 0, NULL);
}
#line 3599 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1450 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	action = filteringaction_new(MATCHACTION_IGNORE, 0, NULL, 0, 0, NULL);
}
#line 3607 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1454 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	action = filteringaction_new(MATCHACTION_WATCH, 0, NULL, 0, 0, NULL);
}
#line 3615 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1458 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	header = g_strdup((yyvsp[0].str));
}
#line 3623 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1461 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	gchar *addressbook = NULL;
	gint action_type = 0;

	action_type = MATCHACTION_ADD_TO_ADDRESSBOOK;
	addressbook = (yyvsp[-2].str);
	action = filteringaction_new(action_type, 0, addressbook, 0, 0, header);
	g_free(header);
}
#line 3637 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1471 "matcher_parser_parse.y" /* yacc.c:1646  */
    {
	action = filteringaction_new(MATCHACTION_STOP, 0, NULL, 0, 0, NULL);
}
#line 3645 "matcher_parser_parse.c" /* yacc.c:1646  */
    break;


#line 3649 "matcher_parser_parse.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
