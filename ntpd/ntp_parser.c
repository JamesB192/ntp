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
#line 11 "../../ntpd/ntp_parser.y" /* yacc.c:339  */

  #ifdef HAVE_CONFIG_H
  # include <config.h>
  #endif

  #include "ntp.h"
  #include "ntpd.h"
  #include "ntp_machine.h"
  #include "ntp_stdlib.h"
  #include "ntp_filegen.h"
  #include "ntp_scanner.h"
  #include "ntp_config.h"
  #include "ntp_crypto.h"

  #include "ntpsim.h"		/* HMS: Do we really want this all the time? */
				/* SK: It might be a good idea to always
				   include the simulator code. That way
				   someone can use the same configuration file
				   for both the simulator and the daemon
				*/

  #define YYMALLOC	emalloc
  #define YYFREE	free
  #define YYERROR_VERBOSE
  #define YYMAXDEPTH	1000	/* stop the madness sooner */
  void yyerror(const char *msg);

  #ifdef SIM
  #  define ONLY_SIM(a)	(a)
  #else
  #  define ONLY_SIM(a)	NULL
  #endif

#line 100 "../../ntpd/ntp_parser.c" /* yacc.c:339  */

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_Abbrev = 258,
    T_Age = 259,
    T_All = 260,
    T_Allan = 261,
    T_Allpeers = 262,
    T_Auth = 263,
    T_Autokey = 264,
    T_Automax = 265,
    T_Average = 266,
    T_Basedate = 267,
    T_Bclient = 268,
    T_Bcpollbstep = 269,
    T_Beacon = 270,
    T_Broadcast = 271,
    T_Broadcastclient = 272,
    T_Broadcastdelay = 273,
    T_Burst = 274,
    T_Calibrate = 275,
    T_Ceiling = 276,
    T_Clockstats = 277,
    T_Cohort = 278,
    T_ControlKey = 279,
    T_Crypto = 280,
    T_Cryptostats = 281,
    T_Ctl = 282,
    T_Day = 283,
    T_Default = 284,
    T_Digest = 285,
    T_Disable = 286,
    T_Discard = 287,
    T_Dispersion = 288,
    T_Double = 289,
    T_Driftfile = 290,
    T_Drop = 291,
    T_Dscp = 292,
    T_Ellipsis = 293,
    T_Enable = 294,
    T_End = 295,
    T_False = 296,
    T_File = 297,
    T_Filegen = 298,
    T_Filenum = 299,
    T_Flag1 = 300,
    T_Flag2 = 301,
    T_Flag3 = 302,
    T_Flag4 = 303,
    T_Flake = 304,
    T_Floor = 305,
    T_Freq = 306,
    T_Fudge = 307,
    T_Host = 308,
    T_Huffpuff = 309,
    T_Iburst = 310,
    T_Ident = 311,
    T_Ignore = 312,
    T_Incalloc = 313,
    T_Incmem = 314,
    T_Initalloc = 315,
    T_Initmem = 316,
    T_Includefile = 317,
    T_Integer = 318,
    T_Interface = 319,
    T_Intrange = 320,
    T_Io = 321,
    T_Ipv4 = 322,
    T_Ipv4_flag = 323,
    T_Ipv6 = 324,
    T_Ipv6_flag = 325,
    T_Kernel = 326,
    T_Key = 327,
    T_Keys = 328,
    T_Keysdir = 329,
    T_Kod = 330,
    T_Mssntp = 331,
    T_Leapfile = 332,
    T_Leapsmearinterval = 333,
    T_Limited = 334,
    T_Link = 335,
    T_Listen = 336,
    T_Logconfig = 337,
    T_Logfile = 338,
    T_Loopstats = 339,
    T_Lowpriotrap = 340,
    T_Manycastclient = 341,
    T_Manycastserver = 342,
    T_Mask = 343,
    T_Maxage = 344,
    T_Maxclock = 345,
    T_Maxdepth = 346,
    T_Maxdist = 347,
    T_Maxmem = 348,
    T_Maxpoll = 349,
    T_Mdnstries = 350,
    T_Mem = 351,
    T_Memlock = 352,
    T_Minclock = 353,
    T_Mindepth = 354,
    T_Mindist = 355,
    T_Minimum = 356,
    T_Minpoll = 357,
    T_Minsane = 358,
    T_Mode = 359,
    T_Mode7 = 360,
    T_Monitor = 361,
    T_Month = 362,
    T_Mru = 363,
    T_Multicastclient = 364,
    T_Nic = 365,
    T_Nolink = 366,
    T_Nomodify = 367,
    T_Nomrulist = 368,
    T_None = 369,
    T_Nonvolatile = 370,
    T_Nopeer = 371,
    T_Noquery = 372,
    T_Noselect = 373,
    T_Noserve = 374,
    T_Notrap = 375,
    T_Notrust = 376,
    T_Ntp = 377,
    T_Ntpport = 378,
    T_NtpSignDsocket = 379,
    T_Orphan = 380,
    T_Orphanwait = 381,
    T_PCEdigest = 382,
    T_Panic = 383,
    T_Peer = 384,
    T_Peerstats = 385,
    T_Phone = 386,
    T_Pid = 387,
    T_Pidfile = 388,
    T_Pool = 389,
    T_Port = 390,
    T_Preempt = 391,
    T_Prefer = 392,
    T_Protostats = 393,
    T_Pw = 394,
    T_Randfile = 395,
    T_Rawstats = 396,
    T_Refid = 397,
    T_Requestkey = 398,
    T_Reset = 399,
    T_Restrict = 400,
    T_Revoke = 401,
    T_Rlimit = 402,
    T_Saveconfigdir = 403,
    T_Server = 404,
    T_Setvar = 405,
    T_Source = 406,
    T_Stacksize = 407,
    T_Statistics = 408,
    T_Stats = 409,
    T_Statsdir = 410,
    T_Step = 411,
    T_Stepback = 412,
    T_Stepfwd = 413,
    T_Stepout = 414,
    T_Stratum = 415,
    T_String = 416,
    T_Sys = 417,
    T_Sysstats = 418,
    T_Tick = 419,
    T_Time1 = 420,
    T_Time2 = 421,
    T_Timer = 422,
    T_Timingstats = 423,
    T_Tinker = 424,
    T_Tos = 425,
    T_Trap = 426,
    T_True = 427,
    T_Trustedkey = 428,
    T_Ttl = 429,
    T_Type = 430,
    T_U_int = 431,
    T_UEcrypto = 432,
    T_UEcryptonak = 433,
    T_UEdigest = 434,
    T_Unconfig = 435,
    T_Unpeer = 436,
    T_Version = 437,
    T_WanderThreshold = 438,
    T_Week = 439,
    T_Wildcard = 440,
    T_Xleave = 441,
    T_Year = 442,
    T_Flag = 443,
    T_EOC = 444,
    T_Simulate = 445,
    T_Beep_Delay = 446,
    T_Sim_Duration = 447,
    T_Server_Offset = 448,
    T_Duration = 449,
    T_Freq_Offset = 450,
    T_Wander = 451,
    T_Jitter = 452,
    T_Prop_Delay = 453,
    T_Proc_Delay = 454
  };
#endif
/* Tokens.  */
#define T_Abbrev 258
#define T_Age 259
#define T_All 260
#define T_Allan 261
#define T_Allpeers 262
#define T_Auth 263
#define T_Autokey 264
#define T_Automax 265
#define T_Average 266
#define T_Basedate 267
#define T_Bclient 268
#define T_Bcpollbstep 269
#define T_Beacon 270
#define T_Broadcast 271
#define T_Broadcastclient 272
#define T_Broadcastdelay 273
#define T_Burst 274
#define T_Calibrate 275
#define T_Ceiling 276
#define T_Clockstats 277
#define T_Cohort 278
#define T_ControlKey 279
#define T_Crypto 280
#define T_Cryptostats 281
#define T_Ctl 282
#define T_Day 283
#define T_Default 284
#define T_Digest 285
#define T_Disable 286
#define T_Discard 287
#define T_Dispersion 288
#define T_Double 289
#define T_Driftfile 290
#define T_Drop 291
#define T_Dscp 292
#define T_Ellipsis 293
#define T_Enable 294
#define T_End 295
#define T_False 296
#define T_File 297
#define T_Filegen 298
#define T_Filenum 299
#define T_Flag1 300
#define T_Flag2 301
#define T_Flag3 302
#define T_Flag4 303
#define T_Flake 304
#define T_Floor 305
#define T_Freq 306
#define T_Fudge 307
#define T_Host 308
#define T_Huffpuff 309
#define T_Iburst 310
#define T_Ident 311
#define T_Ignore 312
#define T_Incalloc 313
#define T_Incmem 314
#define T_Initalloc 315
#define T_Initmem 316
#define T_Includefile 317
#define T_Integer 318
#define T_Interface 319
#define T_Intrange 320
#define T_Io 321
#define T_Ipv4 322
#define T_Ipv4_flag 323
#define T_Ipv6 324
#define T_Ipv6_flag 325
#define T_Kernel 326
#define T_Key 327
#define T_Keys 328
#define T_Keysdir 329
#define T_Kod 330
#define T_Mssntp 331
#define T_Leapfile 332
#define T_Leapsmearinterval 333
#define T_Limited 334
#define T_Link 335
#define T_Listen 336
#define T_Logconfig 337
#define T_Logfile 338
#define T_Loopstats 339
#define T_Lowpriotrap 340
#define T_Manycastclient 341
#define T_Manycastserver 342
#define T_Mask 343
#define T_Maxage 344
#define T_Maxclock 345
#define T_Maxdepth 346
#define T_Maxdist 347
#define T_Maxmem 348
#define T_Maxpoll 349
#define T_Mdnstries 350
#define T_Mem 351
#define T_Memlock 352
#define T_Minclock 353
#define T_Mindepth 354
#define T_Mindist 355
#define T_Minimum 356
#define T_Minpoll 357
#define T_Minsane 358
#define T_Mode 359
#define T_Mode7 360
#define T_Monitor 361
#define T_Month 362
#define T_Mru 363
#define T_Multicastclient 364
#define T_Nic 365
#define T_Nolink 366
#define T_Nomodify 367
#define T_Nomrulist 368
#define T_None 369
#define T_Nonvolatile 370
#define T_Nopeer 371
#define T_Noquery 372
#define T_Noselect 373
#define T_Noserve 374
#define T_Notrap 375
#define T_Notrust 376
#define T_Ntp 377
#define T_Ntpport 378
#define T_NtpSignDsocket 379
#define T_Orphan 380
#define T_Orphanwait 381
#define T_PCEdigest 382
#define T_Panic 383
#define T_Peer 384
#define T_Peerstats 385
#define T_Phone 386
#define T_Pid 387
#define T_Pidfile 388
#define T_Pool 389
#define T_Port 390
#define T_Preempt 391
#define T_Prefer 392
#define T_Protostats 393
#define T_Pw 394
#define T_Randfile 395
#define T_Rawstats 396
#define T_Refid 397
#define T_Requestkey 398
#define T_Reset 399
#define T_Restrict 400
#define T_Revoke 401
#define T_Rlimit 402
#define T_Saveconfigdir 403
#define T_Server 404
#define T_Setvar 405
#define T_Source 406
#define T_Stacksize 407
#define T_Statistics 408
#define T_Stats 409
#define T_Statsdir 410
#define T_Step 411
#define T_Stepback 412
#define T_Stepfwd 413
#define T_Stepout 414
#define T_Stratum 415
#define T_String 416
#define T_Sys 417
#define T_Sysstats 418
#define T_Tick 419
#define T_Time1 420
#define T_Time2 421
#define T_Timer 422
#define T_Timingstats 423
#define T_Tinker 424
#define T_Tos 425
#define T_Trap 426
#define T_True 427
#define T_Trustedkey 428
#define T_Ttl 429
#define T_Type 430
#define T_U_int 431
#define T_UEcrypto 432
#define T_UEcryptonak 433
#define T_UEdigest 434
#define T_Unconfig 435
#define T_Unpeer 436
#define T_Version 437
#define T_WanderThreshold 438
#define T_Week 439
#define T_Wildcard 440
#define T_Xleave 441
#define T_Year 442
#define T_Flag 443
#define T_EOC 444
#define T_Simulate 445
#define T_Beep_Delay 446
#define T_Sim_Duration 447
#define T_Server_Offset 448
#define T_Duration 449
#define T_Freq_Offset 450
#define T_Wander 451
#define T_Jitter 452
#define T_Prop_Delay 453
#define T_Proc_Delay 454

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "../../ntpd/ntp_parser.y" /* yacc.c:355  */

	char *			String;
	double			Double;
	int			Integer;
	unsigned		U_int;
	gen_fifo *		Generic_fifo;
	attr_val *		Attr_val;
	attr_val_fifo *		Attr_val_fifo;
	int_fifo *		Int_fifo;
	string_fifo *		String_fifo;
	address_node *		Address_node;
	address_fifo *		Address_fifo;
	setvar_node *		Set_var;
	server_info *		Sim_server;
	server_info_fifo *	Sim_server_fifo;
	script_info *		Sim_script;
	script_info_fifo *	Sim_script_fifo;

#line 557 "../../ntpd/ntp_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 574 "../../ntpd/ntp_parser.c" /* yacc.c:358  */

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
#define YYFINAL  216
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   675

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  205
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  106
/* YYNRULES -- Number of rules.  */
#define YYNRULES  320
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  426

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   454

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
     201,   202,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   200,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   203,     2,   204,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   373,   373,   377,   378,   379,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     415,   425,   426,   427,   428,   429,   433,   434,   439,   444,
     446,   452,   453,   461,   462,   463,   467,   472,   473,   474,
     475,   476,   477,   478,   479,   483,   485,   490,   491,   492,
     493,   494,   495,   499,   504,   513,   523,   524,   534,   536,
     538,   540,   551,   558,   560,   565,   567,   569,   571,   573,
     583,   589,   590,   598,   600,   612,   613,   614,   615,   616,
     625,   630,   635,   643,   645,   647,   649,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   666,   667,   676,   678,
     687,   697,   702,   710,   711,   712,   713,   714,   715,   716,
     717,   722,   723,   731,   741,   750,   765,   770,   771,   775,
     776,   780,   781,   782,   783,   784,   785,   786,   795,   799,
     803,   811,   819,   827,   842,   857,   870,   871,   879,   880,
     881,   882,   883,   884,   885,   886,   887,   888,   889,   890,
     891,   892,   893,   897,   902,   910,   915,   916,   917,   921,
     926,   934,   939,   940,   941,   942,   943,   944,   945,   946,
     954,   964,   969,   977,   979,   981,   990,   992,   997,   998,
    1002,  1003,  1004,  1005,  1013,  1018,  1023,  1031,  1036,  1037,
    1038,  1047,  1049,  1054,  1059,  1067,  1069,  1086,  1087,  1088,
    1089,  1090,  1091,  1095,  1096,  1097,  1098,  1099,  1100,  1108,
    1113,  1118,  1126,  1131,  1132,  1133,  1134,  1135,  1136,  1137,
    1138,  1139,  1140,  1149,  1150,  1151,  1158,  1165,  1172,  1188,
    1207,  1209,  1211,  1213,  1215,  1217,  1224,  1229,  1230,  1231,
    1235,  1239,  1248,  1249,  1253,  1254,  1255,  1259,  1270,  1284,
    1296,  1301,  1303,  1308,  1309,  1317,  1319,  1327,  1332,  1340,
    1365,  1372,  1382,  1383,  1387,  1388,  1389,  1390,  1394,  1395,
    1396,  1400,  1405,  1410,  1418,  1419,  1420,  1421,  1422,  1423,
    1424,  1434,  1439,  1447,  1452,  1460,  1462,  1466,  1471,  1476,
    1484,  1489,  1497,  1506,  1507,  1511,  1512,  1516,  1524,  1542,
    1546,  1551,  1559,  1564,  1565,  1569,  1574,  1582,  1587,  1592,
    1597,  1602,  1610,  1615,  1620,  1628,  1633,  1634,  1635,  1636,
    1637
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Abbrev", "T_Age", "T_All", "T_Allan",
  "T_Allpeers", "T_Auth", "T_Autokey", "T_Automax", "T_Average",
  "T_Basedate", "T_Bclient", "T_Bcpollbstep", "T_Beacon", "T_Broadcast",
  "T_Broadcastclient", "T_Broadcastdelay", "T_Burst", "T_Calibrate",
  "T_Ceiling", "T_Clockstats", "T_Cohort", "T_ControlKey", "T_Crypto",
  "T_Cryptostats", "T_Ctl", "T_Day", "T_Default", "T_Digest", "T_Disable",
  "T_Discard", "T_Dispersion", "T_Double", "T_Driftfile", "T_Drop",
  "T_Dscp", "T_Ellipsis", "T_Enable", "T_End", "T_False", "T_File",
  "T_Filegen", "T_Filenum", "T_Flag1", "T_Flag2", "T_Flag3", "T_Flag4",
  "T_Flake", "T_Floor", "T_Freq", "T_Fudge", "T_Host", "T_Huffpuff",
  "T_Iburst", "T_Ident", "T_Ignore", "T_Incalloc", "T_Incmem",
  "T_Initalloc", "T_Initmem", "T_Includefile", "T_Integer", "T_Interface",
  "T_Intrange", "T_Io", "T_Ipv4", "T_Ipv4_flag", "T_Ipv6", "T_Ipv6_flag",
  "T_Kernel", "T_Key", "T_Keys", "T_Keysdir", "T_Kod", "T_Mssntp",
  "T_Leapfile", "T_Leapsmearinterval", "T_Limited", "T_Link", "T_Listen",
  "T_Logconfig", "T_Logfile", "T_Loopstats", "T_Lowpriotrap",
  "T_Manycastclient", "T_Manycastserver", "T_Mask", "T_Maxage",
  "T_Maxclock", "T_Maxdepth", "T_Maxdist", "T_Maxmem", "T_Maxpoll",
  "T_Mdnstries", "T_Mem", "T_Memlock", "T_Minclock", "T_Mindepth",
  "T_Mindist", "T_Minimum", "T_Minpoll", "T_Minsane", "T_Mode", "T_Mode7",
  "T_Monitor", "T_Month", "T_Mru", "T_Multicastclient", "T_Nic",
  "T_Nolink", "T_Nomodify", "T_Nomrulist", "T_None", "T_Nonvolatile",
  "T_Nopeer", "T_Noquery", "T_Noselect", "T_Noserve", "T_Notrap",
  "T_Notrust", "T_Ntp", "T_Ntpport", "T_NtpSignDsocket", "T_Orphan",
  "T_Orphanwait", "T_PCEdigest", "T_Panic", "T_Peer", "T_Peerstats",
  "T_Phone", "T_Pid", "T_Pidfile", "T_Pool", "T_Port", "T_Preempt",
  "T_Prefer", "T_Protostats", "T_Pw", "T_Randfile", "T_Rawstats",
  "T_Refid", "T_Requestkey", "T_Reset", "T_Restrict", "T_Revoke",
  "T_Rlimit", "T_Saveconfigdir", "T_Server", "T_Setvar", "T_Source",
  "T_Stacksize", "T_Statistics", "T_Stats", "T_Statsdir", "T_Step",
  "T_Stepback", "T_Stepfwd", "T_Stepout", "T_Stratum", "T_String", "T_Sys",
  "T_Sysstats", "T_Tick", "T_Time1", "T_Time2", "T_Timer", "T_Timingstats",
  "T_Tinker", "T_Tos", "T_Trap", "T_True", "T_Trustedkey", "T_Ttl",
  "T_Type", "T_U_int", "T_UEcrypto", "T_UEcryptonak", "T_UEdigest",
  "T_Unconfig", "T_Unpeer", "T_Version", "T_WanderThreshold", "T_Week",
  "T_Wildcard", "T_Xleave", "T_Year", "T_Flag", "T_EOC", "T_Simulate",
  "T_Beep_Delay", "T_Sim_Duration", "T_Server_Offset", "T_Duration",
  "T_Freq_Offset", "T_Wander", "T_Jitter", "T_Prop_Delay", "T_Proc_Delay",
  "'='", "'('", "')'", "'{'", "'}'", "$accept", "configuration",
  "command_list", "command", "server_command", "client_type", "address",
  "ip_address", "address_fam", "option_list", "option", "option_flag",
  "option_flag_keyword", "option_int", "option_int_keyword", "option_str",
  "option_str_keyword", "unpeer_command", "unpeer_keyword",
  "other_mode_command", "authentication_command", "crypto_command_list",
  "crypto_command", "crypto_str_keyword", "orphan_mode_command",
  "tos_option_list", "tos_option", "tos_option_int_keyword",
  "tos_option_dbl_keyword", "monitoring_command", "stats_list", "stat",
  "filegen_option_list", "filegen_option", "link_nolink", "enable_disable",
  "filegen_type", "access_control_command", "ac_flag_list",
  "access_control_flag", "discard_option_list", "discard_option",
  "discard_option_keyword", "mru_option_list", "mru_option",
  "mru_option_keyword", "fudge_command", "fudge_factor_list",
  "fudge_factor", "fudge_factor_dbl_keyword", "fudge_factor_bool_keyword",
  "rlimit_command", "rlimit_option_list", "rlimit_option",
  "rlimit_option_keyword", "system_option_command", "system_option_list",
  "system_option", "system_option_flag_keyword",
  "system_option_local_flag_keyword", "tinker_command",
  "tinker_option_list", "tinker_option", "tinker_option_keyword",
  "miscellaneous_command", "misc_cmd_dbl_keyword", "misc_cmd_int_keyword",
  "misc_cmd_str_keyword", "misc_cmd_str_lcl_keyword", "drift_parm",
  "variable_assign", "t_default_or_zero", "trap_option_list",
  "trap_option", "log_config_list", "log_config_command",
  "interface_command", "interface_nic", "nic_rule_class",
  "nic_rule_action", "reset_command", "counter_set_list",
  "counter_set_keyword", "integer_list", "integer_list_range",
  "integer_list_range_elt", "integer_range", "string_list", "address_list",
  "boolean", "number", "basedate", "simulate_command", "sim_conf_start",
  "sim_init_statement_list", "sim_init_statement", "sim_init_keyword",
  "sim_server_list", "sim_server", "sim_server_offset", "sim_server_name",
  "sim_act_list", "sim_act", "sim_act_stmt_list", "sim_act_stmt",
  "sim_act_keyword", YY_NULLPTR
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
      61,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF -188

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-188)))

#define YYTABLE_NINF -7

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,  -168,   -38,  -188,  -188,  -188,   -36,  -188,   162,     2,
    -113,  -188,   162,  -188,   -19,   -40,  -188,  -108,  -188,  -104,
    -101,  -188,  -188,   -94,  -188,  -188,   -40,   -17,   366,   -40,
    -188,  -188,   -91,  -188,   -83,  -188,  -188,    16,    34,    20,
      17,   -11,  -188,  -188,   -74,   -19,   -72,  -188,   397,   537,
     -70,   -55,    35,  -188,  -188,  -188,    94,   200,   -90,  -188,
     -40,  -188,   -40,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,    21,    41,   -54,   -48,  -188,   -18,  -188,
    -188,   -88,  -188,  -188,  -188,   105,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,   162,  -188,
    -188,  -188,  -188,  -188,  -188,     2,  -188,    49,    82,  -188,
     162,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,   251,  -188,   -29,   367,  -188,  -188,  -188,
     -94,  -188,  -188,   -40,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,   366,  -188,    57,   -40,  -188,  -188,   -28,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,    34,  -188,
    -188,    97,   107,  -188,    50,  -188,  -188,  -188,  -188,   -11,
    -188,    60,   -63,  -188,   -19,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,   397,  -188,    21,
     -14,  -188,  -188,  -188,   -32,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,   537,  -188,    88,    21,  -188,  -188,  -188,
      91,   -55,  -188,  -188,  -188,    92,  -188,   -44,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
      -1,  -118,  -188,  -188,  -188,  -188,  -188,    93,  -188,    -4,
    -188,  -188,  -188,  -188,   -16,    12,  -188,  -188,  -188,  -188,
      15,   114,  -188,  -188,   251,  -188,    21,   -32,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   493,  -188,  -188,   493,
     -70,   493,  -188,  -188,    18,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   -53,   140,  -188,  -188,
    -188,   186,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -115,    -3,   -13,  -188,  -188,  -188,  -188,    30,  -188,  -188,
      10,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   493,   493,  -188,   169,
     -70,   139,  -188,   141,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,   -51,  -188,    42,     6,    22,  -132,  -188,
       4,  -188,    21,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,   493,  -188,  -188,  -188,  -188,    11,  -188,  -188,
    -188,   -40,  -188,  -188,  -188,    27,  -188,  -188,  -188,    23,
      28,    21,    38,  -172,  -188,    26,    21,  -188,  -188,  -188,
       9,    31,  -188,  -188,  -188,  -188,  -188,    51,    45,    53,
    -188,    68,  -188,    21,  -188,  -188
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,    24,    58,   237,     0,    71,     0,     0,
     249,   240,     0,   230,     0,     0,   242,     0,   262,     0,
       0,   243,   241,     0,   244,    25,     0,     0,     0,     0,
     263,   238,     0,    23,     0,   245,    22,     0,     0,     0,
       0,     0,   246,    21,     0,     0,     0,   239,     0,     0,
       0,     0,     0,    56,    57,   299,     0,     2,     0,     7,
       0,     8,     0,     9,    10,    13,    11,    12,    14,    15,
      16,    17,    18,     0,     0,     0,     0,   223,     0,   224,
      19,     0,     5,    62,    63,    64,   197,   198,   199,   200,
     203,   201,   202,   204,   205,   206,   207,   208,   192,   194,
     195,   196,   156,   157,   158,   128,   154,     0,   247,   231,
     191,   103,   104,   105,   106,   110,   107,   108,   109,   111,
      29,    30,    28,     0,    26,     0,     6,    65,    66,   259,
     232,   258,   291,    59,    61,   162,   163,   164,   165,   166,
     167,   168,   169,   129,   160,     0,    60,    70,   289,   233,
      67,   274,   275,   276,   277,   278,   279,   280,   271,   273,
     136,    29,    30,   136,   136,    68,   190,   188,   189,   184,
     186,     0,     0,   234,    98,   102,    99,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   209,   211,     0,
       0,    87,    88,    89,     0,    90,    91,    97,    92,    96,
      93,    94,    95,    80,    82,     0,     0,    86,   253,   285,
       0,    69,   284,   286,   282,   236,     1,     0,     4,    31,
      55,   296,   295,   225,   226,   227,   228,   270,   269,   268,
       0,     0,    79,    75,    76,    77,    78,     0,    72,     0,
     193,   153,   155,   248,   100,     0,   180,   181,   182,   183,
       0,     0,   178,   179,   170,   172,     0,     0,    27,   229,
     257,   290,   159,   161,   288,   272,   132,   136,   136,   135,
       0,   130,   185,   187,     0,   101,   210,   212,   297,   294,
     292,   293,    85,    81,    83,    84,   235,     0,   283,   281,
       3,    20,   264,   265,   266,   261,   267,   260,   303,   304,
       0,     0,     0,    74,    73,   120,   119,     0,   117,   118,
       0,   112,   115,   116,   176,   177,   175,   171,   173,   174,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   137,   133,   134,   136,   252,
       0,     0,   254,     0,    37,    38,    39,    54,    47,    49,
      48,    51,    40,    41,    42,    43,    50,    52,    44,    32,
      33,    36,    34,     0,    35,     0,     0,     0,     0,   306,
       0,   301,     0,   113,   127,   123,   125,   121,   122,   124,
     126,   114,   131,   251,   250,   256,   255,     0,    45,    46,
      53,     0,   300,   298,   305,     0,   302,   287,   309,     0,
       0,     0,     0,     0,   311,     0,     0,   307,   310,   308,
       0,     0,   316,   317,   318,   319,   320,     0,     0,     0,
     312,     0,   314,     0,   313,   315
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,  -188,   -41,  -188,  -188,   -15,   -49,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,    56,  -188,  -188,  -188,
    -188,   -35,  -188,  -188,  -188,  -188,  -188,  -188,  -158,  -188,
    -188,   155,  -188,  -188,   118,  -188,  -188,  -188,    25,  -188,
    -188,  -188,  -188,    96,  -188,  -188,   254,   -58,  -188,  -188,
    -188,  -188,    76,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,   142,  -188,  -188,  -188,  -188,
    -188,  -188,   111,  -188,  -188,    59,  -188,  -188,   242,    24,
    -187,  -188,  -188,  -188,  -188,   -25,  -188,  -188,   -92,  -188,
    -188,  -188,  -111,  -188,  -124,  -188
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    56,    57,    58,    59,    60,   132,   124,   125,   291,
     359,   360,   361,   362,   363,   364,   365,    61,    62,    63,
      64,    85,   238,   239,    65,   203,   204,   205,   206,    66,
     174,   119,   244,   311,   312,   313,   381,    67,   266,   335,
     105,   106,   107,   143,   144,   145,    68,   254,   255,   256,
     257,    69,   169,   170,   171,    70,    98,    99,   100,   101,
      71,   187,   188,   189,    72,    73,    74,    75,    76,   109,
     173,   384,   286,   342,   130,   131,    77,    78,   297,   230,
      79,   158,   159,   215,   211,   212,   213,   149,   133,   282,
     223,   207,    80,    81,   300,   301,   302,   368,   369,   400,
     370,   403,   404,   417,   418,   419
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   208,   277,   111,   292,   269,   271,   112,   209,   279,
     175,   340,   388,   102,   374,   305,   217,   366,   227,   285,
       1,    82,   402,   306,   164,    83,   307,    84,   120,     2,
     121,   280,   407,   166,   366,     3,     4,     5,   375,   228,
     240,   151,   152,     6,     7,   219,   134,   220,   108,   160,
       8,     9,   240,   126,    10,   221,    11,   127,    12,    13,
     128,   153,    14,   229,   308,   113,   293,   129,   294,   318,
     147,    15,   393,   298,   299,    16,   298,   299,   148,   150,
     165,    17,   341,    18,   222,   259,   167,   172,   161,   176,
     162,   122,    19,    20,   216,   309,    21,    22,   214,   218,
     154,    23,    24,   103,   224,    25,    26,   225,   104,   336,
     337,   114,   242,   226,    27,   231,   243,   376,   261,   115,
     263,   122,   116,   273,   377,   389,   267,    28,    29,    30,
     155,   261,   258,   264,    31,   232,   268,   274,   270,   275,
     281,   168,   378,    32,   117,   290,   210,   278,    33,   118,
      34,   284,    35,    36,   287,   289,   303,   304,   233,   310,
     295,   234,    37,    38,    39,    40,    41,    42,    43,    44,
      86,   163,    45,   314,    46,    87,   315,   316,   343,   339,
     382,   122,    88,    47,   296,   396,   371,   372,    48,    49,
      50,   373,    51,    52,   379,   344,   156,   380,   383,    53,
      54,   157,   386,   390,   387,   345,   391,   395,    -6,    55,
       2,   392,   411,   397,   405,   409,     3,     4,     5,   410,
     399,   338,   402,   401,     6,     7,   412,   413,   414,   415,
     416,     8,     9,    89,   422,    10,   425,    11,   406,    12,
      13,   346,   347,    14,   235,   236,   412,   413,   414,   415,
     416,   237,    15,   423,   245,   420,    16,   424,   348,   283,
     241,   262,    17,   276,    18,   272,   110,    90,    91,   265,
     288,   146,   260,    19,    20,   367,   394,    21,    22,   317,
     349,   319,    23,    24,    92,     0,    25,    26,   350,    93,
     351,   385,   408,   421,     0,    27,   246,   247,   248,   249,
       0,     0,     0,     0,   352,     0,     0,     0,    28,    29,
      30,     0,     0,     0,     0,    31,    94,     0,     0,     0,
       0,     0,   353,   354,    32,     0,     0,     0,     0,    33,
       0,    34,     0,    35,    36,     0,     0,     0,     0,    95,
      96,    97,     0,    37,    38,    39,    40,    41,    42,    43,
      44,     0,     0,    45,     0,    46,     0,     0,   355,     0,
     356,     0,     0,     0,    47,     0,     0,     0,   357,    48,
      49,    50,   358,    51,    52,     0,   398,     2,     0,     0,
      53,    54,     0,     3,     4,     5,     0,     0,     0,    -6,
      55,     6,     7,   250,     0,     0,     0,     0,     8,     9,
       0,     0,    10,   177,    11,     0,    12,    13,     0,     0,
      14,   251,     0,     0,     0,     0,   252,   253,     0,    15,
       0,     0,     0,    16,   135,   136,   137,   138,     0,    17,
     178,    18,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,    21,    22,     0,     0,   179,    23,
      24,   180,     0,    25,    26,   139,     0,   140,     0,   141,
       0,     0,    27,     0,     0,   142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,    33,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    38,    39,    40,    41,    42,    43,    44,     0,     0,
      45,     0,    46,     0,     0,   181,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,    48,    49,    50,     0,
      51,    52,   320,     0,     0,     0,     0,    53,    54,   190,
     321,   191,   192,   182,   183,   184,   185,    55,   193,     0,
     194,   186,     0,     0,     0,     0,     0,     0,   322,   323,
       0,     0,   324,     0,     0,     0,     0,     0,   325,     0,
       0,     0,     0,     0,     0,     0,     0,   195,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326,   327,     0,     0,   328,
     329,     0,   330,   331,   332,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,   197,
       0,     0,     0,     0,     0,   198,     0,   199,     0,     0,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   202,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   334
};

static const yytype_int16 yycheck[] =
{
      15,    50,   189,    22,     5,   163,   164,    26,    63,    41,
      45,    64,    63,    11,     4,    31,    57,   149,    36,   206,
       1,   189,   194,    39,    39,    63,    42,    63,    68,    10,
      70,    63,   204,    44,   149,    16,    17,    18,    28,    57,
      98,     7,     8,    24,    25,    60,    63,    62,   161,    29,
      31,    32,   110,   161,    35,    34,    37,   161,    39,    40,
     161,    27,    43,    81,    80,    84,    67,   161,    69,   256,
     161,    52,   204,   191,   192,    56,   191,   192,   161,    63,
      63,    62,   135,    64,    63,   126,    97,   161,    68,   161,
      70,   161,    73,    74,     0,   111,    77,    78,    63,   189,
      66,    82,    83,   101,    63,    86,    87,   161,   106,   267,
     268,   130,    63,   161,    95,   203,    34,   107,   133,   138,
      63,   161,   141,    63,   114,   176,    29,   108,   109,   110,
      96,   146,   161,   161,   115,    30,    29,   200,    88,   174,
     172,   152,   132,   124,   163,   189,   201,   161,   129,   168,
     131,    63,   133,   134,    63,    63,    63,   161,    53,   175,
     161,    56,   143,   144,   145,   146,   147,   148,   149,   150,
       8,   151,   153,   161,   155,    13,   161,    63,    38,   161,
     338,   161,    20,   164,   185,   372,   189,   200,   169,   170,
     171,   161,   173,   174,   184,     9,   162,   187,    29,   180,
     181,   167,    63,   161,    63,    19,   200,   203,   189,   190,
      10,   189,   203,   202,   401,   189,    16,    17,    18,   406,
     193,   270,   194,   200,    24,    25,   195,   196,   197,   198,
     199,    31,    32,    71,   189,    35,   423,    37,   200,    39,
      40,    55,    56,    43,   139,   140,   195,   196,   197,   198,
     199,   146,    52,   200,     3,   204,    56,   189,    72,   203,
     105,   143,    62,   187,    64,   169,    12,   105,   106,   158,
     211,    29,   130,    73,    74,   300,   368,    77,    78,   254,
      94,   257,    82,    83,   122,    -1,    86,    87,   102,   127,
     104,   340,   403,   417,    -1,    95,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,   115,   154,    -1,    -1,    -1,
      -1,    -1,   136,   137,   124,    -1,    -1,    -1,    -1,   129,
      -1,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,   177,
     178,   179,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,    -1,   153,    -1,   155,    -1,    -1,   172,    -1,
     174,    -1,    -1,    -1,   164,    -1,    -1,    -1,   182,   169,
     170,   171,   186,   173,   174,    -1,   391,    10,    -1,    -1,
     180,   181,    -1,    16,    17,    18,    -1,    -1,    -1,   189,
     190,    24,    25,   142,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,     6,    37,    -1,    39,    40,    -1,    -1,
      43,   160,    -1,    -1,    -1,    -1,   165,   166,    -1,    52,
      -1,    -1,    -1,    56,    58,    59,    60,    61,    -1,    62,
      33,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    77,    78,    -1,    -1,    51,    82,
      83,    54,    -1,    86,    87,    89,    -1,    91,    -1,    93,
      -1,    -1,    95,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    -1,    -1,    -1,    -1,   129,    -1,   131,    -1,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
     153,    -1,   155,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   169,   170,   171,    -1,
     173,   174,    49,    -1,    -1,    -1,    -1,   180,   181,    12,
      57,    14,    15,   156,   157,   158,   159,   190,    21,    -1,
      23,   164,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,   116,
     117,    -1,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    10,    16,    17,    18,    24,    25,    31,    32,
      35,    37,    39,    40,    43,    52,    56,    62,    64,    73,
      74,    77,    78,    82,    83,    86,    87,    95,   108,   109,
     110,   115,   124,   129,   131,   133,   134,   143,   144,   145,
     146,   147,   148,   149,   150,   153,   155,   164,   169,   170,
     171,   173,   174,   180,   181,   190,   206,   207,   208,   209,
     210,   222,   223,   224,   225,   229,   234,   242,   251,   256,
     260,   265,   269,   270,   271,   272,   273,   281,   282,   285,
     297,   298,   189,    63,    63,   226,     8,    13,    20,    71,
     105,   106,   122,   127,   154,   177,   178,   179,   261,   262,
     263,   264,    11,   101,   106,   245,   246,   247,   161,   274,
     261,    22,    26,    84,   130,   138,   141,   163,   168,   236,
      68,    70,   161,   211,   212,   213,   161,   161,   161,   161,
     279,   280,   211,   293,    63,    58,    59,    60,    61,    89,
      91,    93,    99,   248,   249,   250,   293,   161,   161,   292,
      63,     7,     8,    27,    66,    96,   162,   167,   286,   287,
      29,    68,    70,   151,   211,    63,    44,    97,   152,   257,
     258,   259,   161,   275,   235,   236,   161,     6,    33,    51,
      54,   128,   156,   157,   158,   159,   164,   266,   267,   268,
      12,    14,    15,    21,    23,    50,    90,    92,    98,   100,
     103,   125,   126,   230,   231,   232,   233,   296,   212,    63,
     201,   289,   290,   291,    63,   288,     0,   208,   189,   211,
     211,    34,    63,   295,    63,   161,   161,    36,    57,    81,
     284,   203,    30,    53,    56,   139,   140,   146,   227,   228,
     262,   246,    63,    34,   237,     3,    45,    46,    47,    48,
     142,   160,   165,   166,   252,   253,   254,   255,   161,   208,
     280,   211,   249,    63,   161,   287,   243,    29,    29,   243,
      88,   243,   258,    63,   200,   236,   267,   295,   161,    41,
      63,   172,   294,   231,    63,   295,   277,    63,   290,    63,
     189,   214,     5,    67,    69,   161,   185,   283,   191,   192,
     299,   300,   301,    63,   161,    31,    39,    42,    80,   111,
     175,   238,   239,   240,   161,   161,    63,   253,   295,   294,
      49,    57,    75,    76,    79,    85,   112,   113,   116,   117,
     119,   120,   121,   123,   182,   244,   243,   243,   212,   161,
      64,   135,   278,    38,     9,    19,    55,    56,    72,    94,
     102,   104,   118,   136,   137,   172,   174,   182,   186,   215,
     216,   217,   218,   219,   220,   221,   149,   300,   302,   303,
     305,   189,   200,   161,     4,    28,   107,   114,   132,   184,
     187,   241,   243,    29,   276,   212,    63,    63,    63,   176,
     161,   200,   189,   204,   303,   203,   295,   202,   211,   193,
     304,   200,   194,   306,   307,   295,   200,   204,   307,   189,
     295,   203,   195,   196,   197,   198,   199,   308,   309,   310,
     204,   309,   189,   200,   189,   295
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   205,   206,   207,   207,   207,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     209,   210,   210,   210,   210,   210,   211,   211,   212,   213,
     213,   214,   214,   215,   215,   215,   216,   217,   217,   217,
     217,   217,   217,   217,   217,   218,   218,   219,   219,   219,
     219,   219,   219,   220,   221,   222,   223,   223,   224,   224,
     224,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   226,   226,   227,   227,   228,   228,   228,   228,   228,
     229,   230,   230,   231,   231,   231,   231,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   233,   234,   234,
     234,   235,   235,   236,   236,   236,   236,   236,   236,   236,
     236,   237,   237,   238,   238,   238,   238,   239,   239,   240,
     240,   241,   241,   241,   241,   241,   241,   241,   242,   242,
     242,   242,   242,   242,   242,   242,   243,   243,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   245,   245,   246,   247,   247,   247,   248,
     248,   249,   250,   250,   250,   250,   250,   250,   250,   250,
     251,   252,   252,   253,   253,   253,   253,   253,   254,   254,
     255,   255,   255,   255,   256,   257,   257,   258,   259,   259,
     259,   260,   260,   261,   261,   262,   262,   263,   263,   263,
     263,   263,   263,   264,   264,   264,   264,   264,   264,   265,
     266,   266,   267,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   270,   270,   270,
     271,   271,   272,   272,   273,   273,   273,   274,   274,   274,
     275,   276,   276,   277,   277,   278,   278,   279,   279,   280,
     281,   281,   282,   282,   283,   283,   283,   283,   284,   284,
     284,   285,   286,   286,   287,   287,   287,   287,   287,   287,
     287,   288,   288,   289,   289,   290,   290,   291,   292,   292,
     293,   293,   294,   294,   294,   295,   295,   296,   297,   298,
     299,   299,   300,   301,   301,   302,   302,   303,   304,   305,
     306,   306,   307,   308,   308,   309,   310,   310,   310,   310,
     310
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     5,     3,     4,     4,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     2,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     3,
       1,     2,     2,     2,     2,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       4,     1,     0,     0,     2,     2,     2,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     5,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     5,     1,
       3,     2,     3,     1,     1,     2,     1,     5,     4,     3,
       2,     1,     6,     3,     2,     3,     1,     1,     1,     1,
       1
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
        case 5:
#line 380 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			/* I will need to incorporate much more fine grained
			 * error messages. The following should suffice for
			 * the time being.
			 */
			struct FILE_INFO * ip_ctx = lex_current();
			msyslog(LOG_ERR,
				"syntax error in %s line %d, column %d",
				ip_ctx->fname,
				ip_ctx->errpos.nline,
				ip_ctx->errpos.ncol);
		}
#line 2135 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 416 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			peer_node *my_node;

			my_node = create_peer_node((yyvsp[-2].Integer), (yyvsp[-1].Address_node), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.peers, my_node);
		}
#line 2146 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 435 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Address_node) = create_address_node((yyvsp[0].String), (yyvsp[-1].Integer)); }
#line 2152 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 440 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Address_node) = create_address_node((yyvsp[0].String), AF_UNSPEC); }
#line 2158 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 445 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = AF_INET; }
#line 2164 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 447 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = AF_INET6; }
#line 2170 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 452 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 2176 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 454 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2185 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 468 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 2191 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 484 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2197 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 486 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_uval((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2203 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 500 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2209 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 514 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			unpeer_node *my_node;

			my_node = create_unpeer_node((yyvsp[0].Address_node));
			if (my_node)
				APPEND_G_FIFO(cfgt.unpeers, my_node);
		}
#line 2221 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 535 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.broadcastclient = 1; }
#line 2227 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 537 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.manycastserver, (yyvsp[0].Address_fifo)); }
#line 2233 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 539 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.multicastclient, (yyvsp[0].Address_fifo)); }
#line 2239 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 541 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.mdnstries = (yyvsp[0].Integer); }
#line 2245 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 552 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *atrv;

			atrv = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			APPEND_G_FIFO(cfgt.vars, atrv);
		}
#line 2256 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 559 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.control_key = (yyvsp[0].Integer); }
#line 2262 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 561 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			cfgt.auth.cryptosw++;
			CONCAT_G_FIFOS(cfgt.auth.crypto_cmd_list, (yyvsp[0].Attr_val_fifo));
		}
#line 2271 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 566 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.keys = (yyvsp[0].String); }
#line 2277 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 568 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.keysdir = (yyvsp[0].String); }
#line 2283 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 570 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.request_key = (yyvsp[0].Integer); }
#line 2289 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 572 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.revoke = (yyvsp[0].Integer); }
#line 2295 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 574 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			/* [Bug 948] leaves it open if appending or
			 * replacing the trusted key list is the right
			 * way. In any case, either alternative should
			 * be coded correctly!
			 */
			DESTROY_G_FIFO(cfgt.auth.trusted_key_list, destroy_attr_val); /* remove for append */
			CONCAT_G_FIFOS(cfgt.auth.trusted_key_list, (yyvsp[0].Attr_val_fifo));
		}
#line 2309 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 584 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.ntp_signd_socket = (yyvsp[0].String); }
#line 2315 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 589 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 2321 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 591 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2330 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 599 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2336 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 601 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val) = NULL;
			cfgt.auth.revoke = (yyvsp[0].Integer);
			msyslog(LOG_WARNING,
				"'crypto revoke %d' is deprecated, "
				"please use 'revoke %d' instead.",
				cfgt.auth.revoke, cfgt.auth.revoke);
		}
#line 2349 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 626 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.orphan_cmds, (yyvsp[0].Attr_val_fifo)); }
#line 2355 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 631 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2364 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 636 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2373 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 644 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (double)(yyvsp[0].Integer)); }
#line 2379 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 646 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2385 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 648 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (double)(yyvsp[0].Integer)); }
#line 2391 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 650 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Basedate, (yyvsp[0].Integer)); }
#line 2397 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 677 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.stats_list, (yyvsp[0].Int_fifo)); }
#line 2403 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 679 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				cfgt.stats_dir = (yyvsp[0].String);
			} else {
				YYFREE((yyvsp[0].String));
				yyerror("statsdir remote configuration ignored");
			}
		}
#line 2416 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 688 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			filegen_node *fgn;

			fgn = create_filegen_node((yyvsp[-1].Integer), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.filegen_opts, fgn);
		}
#line 2427 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 698 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2436 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 703 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = NULL;
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2445 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 722 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 2451 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 724 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2460 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 732 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String));
			} else {
				(yyval.Attr_val) = NULL;
				YYFREE((yyvsp[0].String));
				yyerror("filegen file remote config ignored");
			}
		}
#line 2474 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 742 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				yyerror("filegen type remote config ignored");
			}
		}
#line 2487 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 751 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			const char *err;

			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				if (T_Link == (yyvsp[0].Integer))
					err = "filegen link remote config ignored";
				else
					err = "filegen nolink remote config ignored";
				yyerror(err);
			}
		}
#line 2506 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 766 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 2512 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 796 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			CONCAT_G_FIFOS(cfgt.discard_opts, (yyvsp[0].Attr_val_fifo));
		}
#line 2520 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 800 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			CONCAT_G_FIFOS(cfgt.mru_opts, (yyvsp[0].Attr_val_fifo));
		}
#line 2528 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 804 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node((yyvsp[-1].Address_node), NULL, (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2540 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 812 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node((yyvsp[-3].Address_node), (yyvsp[-1].Address_node), (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2552 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 820 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node(NULL, NULL, (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2564 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 828 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node(
				create_address_node(
					estrdup("0.0.0.0"),
					AF_INET),
				create_address_node(
					estrdup("0.0.0.0"),
					AF_INET),
				(yyvsp[0].Int_fifo),
				lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2583 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 843 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node(
				create_address_node(
					estrdup("::"),
					AF_INET6),
				create_address_node(
					estrdup("::"),
					AF_INET6),
				(yyvsp[0].Int_fifo),
				lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2602 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 858 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *	rn;

			APPEND_G_FIFO((yyvsp[0].Int_fifo), create_int_node((yyvsp[-1].Integer)));
			rn = create_restrict_node(
				NULL, NULL, (yyvsp[0].Int_fifo), lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2615 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 870 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Int_fifo) = NULL; }
#line 2621 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 872 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2630 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 898 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2639 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 903 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2648 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 911 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2654 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 922 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2663 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 927 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2672 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 935 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2678 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 955 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			addr_opts_node *aon;

			aon = create_addr_opts_node((yyvsp[-1].Address_node), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.fudge, aon);
		}
#line 2689 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 965 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2698 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 970 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2707 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 978 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2713 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 980 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2719 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 982 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].Integer) >= 0 && (yyvsp[0].Integer) <= 16) {
				(yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				yyerror("fudge factor: stratum value not in [0..16], ignored");
			}
		}
#line 2732 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 991 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2738 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 993 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2744 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1014 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.rlimit, (yyvsp[0].Attr_val_fifo)); }
#line 2750 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1019 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2759 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1024 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2768 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1032 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2774 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1048 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.enable_opts, (yyvsp[0].Attr_val_fifo)); }
#line 2780 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1050 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.disable_opts, (yyvsp[0].Attr_val_fifo)); }
#line 2786 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1055 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2795 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1060 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2804 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1068 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 2810 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1070 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer));
			} else {
				char err_str[128];

				(yyval.Attr_val) = NULL;
				snprintf(err_str, sizeof(err_str),
					 "enable/disable %s remote configuration ignored",
					 keyword((yyvsp[0].Integer)));
				yyerror(err_str);
			}
		}
#line 2828 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1109 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.tinker, (yyvsp[0].Attr_val_fifo)); }
#line 2834 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1114 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2843 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1119 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2852 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1127 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2858 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1152 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;

			av = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2869 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1159 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;

			av = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2880 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1166 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;

			av = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2891 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1173 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			char error_text[64];
			attr_val *av;

			if (lex_from_file()) {
				av = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String));
				APPEND_G_FIFO(cfgt.vars, av);
			} else {
				YYFREE((yyvsp[0].String));
				snprintf(error_text, sizeof(error_text),
					 "%s remote config ignored",
					 keyword((yyvsp[-1].Integer)));
				yyerror(error_text);
			}
		}
#line 2911 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1189 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (!lex_from_file()) {
				YYFREE((yyvsp[-1].String)); /* avoid leak */
				yyerror("remote includefile ignored");
				break;
			}
			if (lex_level() > MAXINCLUDELEVEL) {
				fprintf(stderr, "getconfig: Maximum include file level exceeded.\n");
				msyslog(LOG_ERR, "getconfig: Maximum include file level exceeded.");
			} else {
				const char * path = FindConfig((yyvsp[-1].String)); /* might return $2! */
				if (!lex_push_file(path, "r")) {
					fprintf(stderr, "getconfig: Couldn't open <%s>\n", path);
					msyslog(LOG_ERR, "getconfig: Couldn't open <%s>", path);
				}
			}
			YYFREE((yyvsp[-1].String)); /* avoid leak */
		}
#line 2934 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1208 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { lex_flush_stack(); }
#line 2940 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1210 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { /* see drift_parm below for actions */ }
#line 2946 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1212 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.logconfig, (yyvsp[0].Attr_val_fifo)); }
#line 2952 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1214 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.phone, (yyvsp[0].String_fifo)); }
#line 2958 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1216 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { APPEND_G_FIFO(cfgt.setvar, (yyvsp[0].Set_var)); }
#line 2964 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1218 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			addr_opts_node *aon;

			aon = create_addr_opts_node((yyvsp[-1].Address_node), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.trap, aon);
		}
#line 2975 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1225 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.ttl, (yyvsp[0].Attr_val_fifo)); }
#line 2981 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1240 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
#ifndef LEAP_SMEAR
			yyerror("Built without LEAP_SMEAR support.");
#endif
		}
#line 2991 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1260 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				attr_val *av;
				av = create_attr_sval(T_Driftfile, (yyvsp[0].String));
				APPEND_G_FIFO(cfgt.vars, av);
			} else {
				YYFREE((yyvsp[0].String));
				yyerror("driftfile remote configuration ignored");
			}
		}
#line 3006 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1271 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				attr_val *av;
				av = create_attr_sval(T_Driftfile, (yyvsp[-1].String));
				APPEND_G_FIFO(cfgt.vars, av);
				av = create_attr_dval(T_WanderThreshold, (yyvsp[0].Double));
				APPEND_G_FIFO(cfgt.vars, av);
			} else {
				YYFREE((yyvsp[-1].String));
				yyerror("driftfile remote configuration ignored");
			}
		}
#line 3023 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1284 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				attr_val *av;
				av = create_attr_sval(T_Driftfile, estrdup(""));
				APPEND_G_FIFO(cfgt.vars, av);
			} else {
				yyerror("driftfile remote configuration ignored");
			}
		}
#line 3037 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1297 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Set_var) = create_setvar_node((yyvsp[-3].String), (yyvsp[-1].String), (yyvsp[0].Integer)); }
#line 3043 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1303 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 0; }
#line 3049 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1308 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 3055 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1310 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3064 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1318 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 3070 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1320 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), estrdup((yyvsp[0].Address_node)->address));
			destroy_address_node((yyvsp[0].Address_node));
		}
#line 3079 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1328 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3088 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1333 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3097 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1341 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			char	prefix;
			char *	type;

			switch ((yyvsp[0].String)[0]) {

			case '+':
			case '-':
			case '=':
				prefix = (yyvsp[0].String)[0];
				type = (yyvsp[0].String) + 1;
				break;

			default:
				prefix = '=';
				type = (yyvsp[0].String);
			}

			(yyval.Attr_val) = create_attr_sval(prefix, estrdup(type));
			YYFREE((yyvsp[0].String));
		}
#line 3123 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1366 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			nic_rule_node *nrn;

			nrn = create_nic_rule_node((yyvsp[0].Integer), NULL, (yyvsp[-1].Integer));
			APPEND_G_FIFO(cfgt.nic_rules, nrn);
		}
#line 3134 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1373 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			nic_rule_node *nrn;

			nrn = create_nic_rule_node(0, (yyvsp[0].String), (yyvsp[-1].Integer));
			APPEND_G_FIFO(cfgt.nic_rules, nrn);
		}
#line 3145 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1401 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.reset_counters, (yyvsp[0].Int_fifo)); }
#line 3151 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1406 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 3160 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1411 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = NULL;
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 3169 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1435 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 3178 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1440 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 3187 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1448 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3196 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1453 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3205 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1461 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival('i', (yyvsp[0].Integer)); }
#line 3211 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1467 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_rangeval('-', (yyvsp[-3].Integer), (yyvsp[-1].Integer)); }
#line 3217 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1472 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.String_fifo) = (yyvsp[-1].String_fifo);
			APPEND_G_FIFO((yyval.String_fifo), create_string_node((yyvsp[0].String)));
		}
#line 3226 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1477 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.String_fifo) = NULL;
			APPEND_G_FIFO((yyval.String_fifo), create_string_node((yyvsp[0].String)));
		}
#line 3235 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1485 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Address_fifo) = (yyvsp[-1].Address_fifo);
			APPEND_G_FIFO((yyval.Address_fifo), (yyvsp[0].Address_node));
		}
#line 3244 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1490 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Address_fifo) = NULL;
			APPEND_G_FIFO((yyval.Address_fifo), (yyvsp[0].Address_node));
		}
#line 3253 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1498 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].Integer) != 0 && (yyvsp[0].Integer) != 1) {
				yyerror("Integer value is not boolean (0 or 1). Assuming 1");
				(yyval.Integer) = 1;
			} else {
				(yyval.Integer) = (yyvsp[0].Integer);
			}
		}
#line 3266 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1506 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 1; }
#line 3272 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1507 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 0; }
#line 3278 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1511 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Double) = (double)(yyvsp[0].Integer); }
#line 3284 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1517 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = basedate_eval_string((yyvsp[0].String)); YYFREE((yyvsp[0].String)); }
#line 3290 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1525 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			sim_node *sn;

			sn =  create_sim_node((yyvsp[-2].Attr_val_fifo), (yyvsp[-1].Sim_server_fifo));
			APPEND_G_FIFO(cfgt.sim_details, sn);

			/* Revert from ; to \n for end-of-command */
			old_config_style = 1;
		}
#line 3304 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1542 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { old_config_style = 0; }
#line 3310 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1547 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-2].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[-1].Attr_val));
		}
#line 3319 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1552 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[-1].Attr_val));
		}
#line 3328 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1560 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-2].Integer), (yyvsp[0].Double)); }
#line 3334 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1570 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Sim_server_fifo) = (yyvsp[-1].Sim_server_fifo);
			APPEND_G_FIFO((yyval.Sim_server_fifo), (yyvsp[0].Sim_server));
		}
#line 3343 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1575 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Sim_server_fifo) = NULL;
			APPEND_G_FIFO((yyval.Sim_server_fifo), (yyvsp[0].Sim_server));
		}
#line 3352 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1583 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Sim_server) = ONLY_SIM(create_sim_server((yyvsp[-4].Address_node), (yyvsp[-2].Double), (yyvsp[-1].Sim_script_fifo))); }
#line 3358 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1588 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-1].Double); }
#line 3364 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1593 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Address_node) = (yyvsp[0].Address_node); }
#line 3370 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1598 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Sim_script_fifo) = (yyvsp[-1].Sim_script_fifo);
			APPEND_G_FIFO((yyval.Sim_script_fifo), (yyvsp[0].Sim_script));
		}
#line 3379 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1603 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Sim_script_fifo) = NULL;
			APPEND_G_FIFO((yyval.Sim_script_fifo), (yyvsp[0].Sim_script));
		}
#line 3388 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1611 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Sim_script) = ONLY_SIM(create_sim_script_info((yyvsp[-3].Double), (yyvsp[-1].Attr_val_fifo))); }
#line 3394 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1616 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-2].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[-1].Attr_val));
		}
#line 3403 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1621 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[-1].Attr_val));
		}
#line 3412 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1629 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-2].Integer), (yyvsp[0].Double)); }
#line 3418 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
    break;


#line 3422 "../../ntpd/ntp_parser.c" /* yacc.c:1646  */
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
#line 1640 "../../ntpd/ntp_parser.y" /* yacc.c:1906  */


void
yyerror(
	const char *msg
	)
{
	int retval;
	struct FILE_INFO * ip_ctx;

	ip_ctx = lex_current();
	ip_ctx->errpos = ip_ctx->tokpos;

	msyslog(LOG_ERR, "line %d column %d %s",
		ip_ctx->errpos.nline, ip_ctx->errpos.ncol, msg);
	if (!lex_from_file()) {
		/* Save the error message in the correct buffer */
		retval = snprintf(remote_config.err_msg + remote_config.err_pos,
				  MAXLINE - remote_config.err_pos,
				  "column %d %s",
				  ip_ctx->errpos.ncol, msg);

		/* Increment the value of err_pos */
		if (retval > 0)
			remote_config.err_pos += retval;

		/* Increment the number of errors */
		++remote_config.no_errors;
	}
}


/*
 * token_name - convert T_ token integers to text
 *		example: token_name(T_Server) returns "T_Server"
 */
const char *
token_name(
	int token
	)
{
	return yytname[YYTRANSLATE(token)];
}


/* Initial Testing function -- ignore */
#if 0
int main(int argc, char *argv[])
{
	ip_file = FOPEN(argv[1], "r");
	if (!ip_file)
		fprintf(stderr, "ERROR!! Could not open file: %s\n", argv[1]);
	yyparse();
	return 0;
}
#endif

