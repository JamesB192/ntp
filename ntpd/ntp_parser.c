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

#line 100 "ntp_parser.c" /* yacc.c:339  */

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
#ifndef YY_YY_NTP_PARSER_H_INCLUDED
# define YY_YY_NTP_PARSER_H_INCLUDED
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
    T_Epeer = 296,
    T_False = 297,
    T_File = 298,
    T_Filegen = 299,
    T_Filenum = 300,
    T_Flag1 = 301,
    T_Flag2 = 302,
    T_Flag3 = 303,
    T_Flag4 = 304,
    T_Flake = 305,
    T_Floor = 306,
    T_Freq = 307,
    T_Fudge = 308,
    T_Host = 309,
    T_Huffpuff = 310,
    T_Iburst = 311,
    T_Ident = 312,
    T_Ignore = 313,
    T_Incalloc = 314,
    T_Incmem = 315,
    T_Initalloc = 316,
    T_Initmem = 317,
    T_Includefile = 318,
    T_Integer = 319,
    T_Interface = 320,
    T_Intrange = 321,
    T_Io = 322,
    T_Ipv4 = 323,
    T_Ipv4_flag = 324,
    T_Ipv6 = 325,
    T_Ipv6_flag = 326,
    T_Kernel = 327,
    T_Key = 328,
    T_Keys = 329,
    T_Keysdir = 330,
    T_Kod = 331,
    T_Mssntp = 332,
    T_Leapfile = 333,
    T_Leapsmearinterval = 334,
    T_Limited = 335,
    T_Link = 336,
    T_Listen = 337,
    T_Logconfig = 338,
    T_Logfile = 339,
    T_Loopstats = 340,
    T_Lowpriotrap = 341,
    T_Manycastclient = 342,
    T_Manycastserver = 343,
    T_Mask = 344,
    T_Maxage = 345,
    T_Maxclock = 346,
    T_Maxdepth = 347,
    T_Maxdist = 348,
    T_Maxmem = 349,
    T_Maxpoll = 350,
    T_Mdnstries = 351,
    T_Mem = 352,
    T_Memlock = 353,
    T_Minclock = 354,
    T_Mindepth = 355,
    T_Mindist = 356,
    T_Minimum = 357,
    T_Minpoll = 358,
    T_Minsane = 359,
    T_Mode = 360,
    T_Mode7 = 361,
    T_Monitor = 362,
    T_Month = 363,
    T_Mru = 364,
    T_Multicastclient = 365,
    T_Nic = 366,
    T_Nolink = 367,
    T_Nomodify = 368,
    T_Nomrulist = 369,
    T_None = 370,
    T_Nonvolatile = 371,
    T_Noepeer = 372,
    T_Nopeer = 373,
    T_Noquery = 374,
    T_Noselect = 375,
    T_Noserve = 376,
    T_Notrap = 377,
    T_Notrust = 378,
    T_Ntp = 379,
    T_Ntpport = 380,
    T_NtpSignDsocket = 381,
    T_Orphan = 382,
    T_Orphanwait = 383,
    T_PCEdigest = 384,
    T_Panic = 385,
    T_Peer = 386,
    T_Peerstats = 387,
    T_Phone = 388,
    T_Pid = 389,
    T_Pidfile = 390,
    T_Pool = 391,
    T_Port = 392,
    T_Preempt = 393,
    T_Prefer = 394,
    T_Protostats = 395,
    T_Pw = 396,
    T_Randfile = 397,
    T_Rawstats = 398,
    T_Refid = 399,
    T_Requestkey = 400,
    T_Reset = 401,
    T_Restrict = 402,
    T_Revoke = 403,
    T_Rlimit = 404,
    T_Saveconfigdir = 405,
    T_Server = 406,
    T_Setvar = 407,
    T_Source = 408,
    T_Stacksize = 409,
    T_Statistics = 410,
    T_Stats = 411,
    T_Statsdir = 412,
    T_Step = 413,
    T_Stepback = 414,
    T_Stepfwd = 415,
    T_Stepout = 416,
    T_Stratum = 417,
    T_String = 418,
    T_Sys = 419,
    T_Sysstats = 420,
    T_Tick = 421,
    T_Time1 = 422,
    T_Time2 = 423,
    T_Timer = 424,
    T_Timingstats = 425,
    T_Tinker = 426,
    T_Tos = 427,
    T_Trap = 428,
    T_True = 429,
    T_Trustedkey = 430,
    T_Ttl = 431,
    T_Type = 432,
    T_U_int = 433,
    T_UEcrypto = 434,
    T_UEcryptonak = 435,
    T_UEdigest = 436,
    T_Unconfig = 437,
    T_Unpeer = 438,
    T_Version = 439,
    T_WanderThreshold = 440,
    T_Week = 441,
    T_Wildcard = 442,
    T_Xleave = 443,
    T_Year = 444,
    T_Flag = 445,
    T_EOC = 446,
    T_Simulate = 447,
    T_Beep_Delay = 448,
    T_Sim_Duration = 449,
    T_Server_Offset = 450,
    T_Duration = 451,
    T_Freq_Offset = 452,
    T_Wander = 453,
    T_Jitter = 454,
    T_Prop_Delay = 455,
    T_Proc_Delay = 456
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
#define T_Epeer 296
#define T_False 297
#define T_File 298
#define T_Filegen 299
#define T_Filenum 300
#define T_Flag1 301
#define T_Flag2 302
#define T_Flag3 303
#define T_Flag4 304
#define T_Flake 305
#define T_Floor 306
#define T_Freq 307
#define T_Fudge 308
#define T_Host 309
#define T_Huffpuff 310
#define T_Iburst 311
#define T_Ident 312
#define T_Ignore 313
#define T_Incalloc 314
#define T_Incmem 315
#define T_Initalloc 316
#define T_Initmem 317
#define T_Includefile 318
#define T_Integer 319
#define T_Interface 320
#define T_Intrange 321
#define T_Io 322
#define T_Ipv4 323
#define T_Ipv4_flag 324
#define T_Ipv6 325
#define T_Ipv6_flag 326
#define T_Kernel 327
#define T_Key 328
#define T_Keys 329
#define T_Keysdir 330
#define T_Kod 331
#define T_Mssntp 332
#define T_Leapfile 333
#define T_Leapsmearinterval 334
#define T_Limited 335
#define T_Link 336
#define T_Listen 337
#define T_Logconfig 338
#define T_Logfile 339
#define T_Loopstats 340
#define T_Lowpriotrap 341
#define T_Manycastclient 342
#define T_Manycastserver 343
#define T_Mask 344
#define T_Maxage 345
#define T_Maxclock 346
#define T_Maxdepth 347
#define T_Maxdist 348
#define T_Maxmem 349
#define T_Maxpoll 350
#define T_Mdnstries 351
#define T_Mem 352
#define T_Memlock 353
#define T_Minclock 354
#define T_Mindepth 355
#define T_Mindist 356
#define T_Minimum 357
#define T_Minpoll 358
#define T_Minsane 359
#define T_Mode 360
#define T_Mode7 361
#define T_Monitor 362
#define T_Month 363
#define T_Mru 364
#define T_Multicastclient 365
#define T_Nic 366
#define T_Nolink 367
#define T_Nomodify 368
#define T_Nomrulist 369
#define T_None 370
#define T_Nonvolatile 371
#define T_Noepeer 372
#define T_Nopeer 373
#define T_Noquery 374
#define T_Noselect 375
#define T_Noserve 376
#define T_Notrap 377
#define T_Notrust 378
#define T_Ntp 379
#define T_Ntpport 380
#define T_NtpSignDsocket 381
#define T_Orphan 382
#define T_Orphanwait 383
#define T_PCEdigest 384
#define T_Panic 385
#define T_Peer 386
#define T_Peerstats 387
#define T_Phone 388
#define T_Pid 389
#define T_Pidfile 390
#define T_Pool 391
#define T_Port 392
#define T_Preempt 393
#define T_Prefer 394
#define T_Protostats 395
#define T_Pw 396
#define T_Randfile 397
#define T_Rawstats 398
#define T_Refid 399
#define T_Requestkey 400
#define T_Reset 401
#define T_Restrict 402
#define T_Revoke 403
#define T_Rlimit 404
#define T_Saveconfigdir 405
#define T_Server 406
#define T_Setvar 407
#define T_Source 408
#define T_Stacksize 409
#define T_Statistics 410
#define T_Stats 411
#define T_Statsdir 412
#define T_Step 413
#define T_Stepback 414
#define T_Stepfwd 415
#define T_Stepout 416
#define T_Stratum 417
#define T_String 418
#define T_Sys 419
#define T_Sysstats 420
#define T_Tick 421
#define T_Time1 422
#define T_Time2 423
#define T_Timer 424
#define T_Timingstats 425
#define T_Tinker 426
#define T_Tos 427
#define T_Trap 428
#define T_True 429
#define T_Trustedkey 430
#define T_Ttl 431
#define T_Type 432
#define T_U_int 433
#define T_UEcrypto 434
#define T_UEcryptonak 435
#define T_UEdigest 436
#define T_Unconfig 437
#define T_Unpeer 438
#define T_Version 439
#define T_WanderThreshold 440
#define T_Week 441
#define T_Wildcard 442
#define T_Xleave 443
#define T_Year 444
#define T_Flag 445
#define T_EOC 446
#define T_Simulate 447
#define T_Beep_Delay 448
#define T_Sim_Duration 449
#define T_Server_Offset 450
#define T_Duration 451
#define T_Freq_Offset 452
#define T_Wander 453
#define T_Jitter 454
#define T_Prop_Delay 455
#define T_Proc_Delay 456

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

#line 561 "ntp_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NTP_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 578 "ntp_parser.c" /* yacc.c:358  */

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
#define YYLAST   656

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  106
/* YYNRULES -- Number of rules.  */
#define YYNRULES  322
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  428

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   456

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
     203,   204,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   202,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   205,     2,   206,     2,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   375,   375,   379,   380,   381,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     417,   427,   428,   429,   430,   431,   435,   436,   441,   446,
     448,   454,   455,   463,   464,   465,   469,   474,   475,   476,
     477,   478,   479,   480,   481,   485,   487,   492,   493,   494,
     495,   496,   497,   501,   506,   515,   525,   526,   536,   538,
     540,   542,   553,   560,   562,   567,   569,   571,   573,   575,
     585,   591,   592,   600,   602,   614,   615,   616,   617,   618,
     627,   632,   637,   645,   647,   649,   651,   656,   657,   658,
     659,   660,   661,   662,   663,   664,   668,   669,   678,   680,
     689,   699,   704,   712,   713,   714,   715,   716,   717,   718,
     719,   724,   725,   733,   743,   752,   767,   772,   773,   777,
     778,   782,   783,   784,   785,   786,   787,   788,   797,   801,
     805,   813,   821,   829,   844,   859,   872,   873,   881,   882,
     883,   884,   885,   886,   887,   888,   889,   890,   891,   892,
     893,   894,   895,   896,   897,   901,   906,   914,   919,   920,
     921,   925,   930,   938,   943,   944,   945,   946,   947,   948,
     949,   950,   958,   968,   973,   981,   983,   985,   994,   996,
    1001,  1002,  1006,  1007,  1008,  1009,  1017,  1022,  1027,  1035,
    1040,  1041,  1042,  1051,  1053,  1058,  1063,  1071,  1073,  1090,
    1091,  1092,  1093,  1094,  1095,  1099,  1100,  1101,  1102,  1103,
    1104,  1112,  1117,  1122,  1130,  1135,  1136,  1137,  1138,  1139,
    1140,  1141,  1142,  1143,  1144,  1153,  1154,  1155,  1162,  1169,
    1176,  1192,  1211,  1213,  1215,  1217,  1219,  1221,  1228,  1233,
    1234,  1235,  1239,  1243,  1252,  1253,  1257,  1258,  1259,  1263,
    1274,  1288,  1300,  1305,  1307,  1312,  1313,  1321,  1323,  1331,
    1336,  1344,  1369,  1376,  1386,  1387,  1391,  1392,  1393,  1394,
    1398,  1399,  1400,  1404,  1409,  1414,  1422,  1423,  1424,  1425,
    1426,  1427,  1428,  1438,  1443,  1451,  1456,  1464,  1466,  1470,
    1475,  1480,  1488,  1493,  1501,  1510,  1511,  1515,  1516,  1520,
    1528,  1546,  1550,  1555,  1563,  1568,  1569,  1573,  1578,  1586,
    1591,  1596,  1601,  1606,  1614,  1619,  1624,  1632,  1637,  1638,
    1639,  1640,  1641
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
  "T_Dscp", "T_Ellipsis", "T_Enable", "T_End", "T_Epeer", "T_False",
  "T_File", "T_Filegen", "T_Filenum", "T_Flag1", "T_Flag2", "T_Flag3",
  "T_Flag4", "T_Flake", "T_Floor", "T_Freq", "T_Fudge", "T_Host",
  "T_Huffpuff", "T_Iburst", "T_Ident", "T_Ignore", "T_Incalloc",
  "T_Incmem", "T_Initalloc", "T_Initmem", "T_Includefile", "T_Integer",
  "T_Interface", "T_Intrange", "T_Io", "T_Ipv4", "T_Ipv4_flag", "T_Ipv6",
  "T_Ipv6_flag", "T_Kernel", "T_Key", "T_Keys", "T_Keysdir", "T_Kod",
  "T_Mssntp", "T_Leapfile", "T_Leapsmearinterval", "T_Limited", "T_Link",
  "T_Listen", "T_Logconfig", "T_Logfile", "T_Loopstats", "T_Lowpriotrap",
  "T_Manycastclient", "T_Manycastserver", "T_Mask", "T_Maxage",
  "T_Maxclock", "T_Maxdepth", "T_Maxdist", "T_Maxmem", "T_Maxpoll",
  "T_Mdnstries", "T_Mem", "T_Memlock", "T_Minclock", "T_Mindepth",
  "T_Mindist", "T_Minimum", "T_Minpoll", "T_Minsane", "T_Mode", "T_Mode7",
  "T_Monitor", "T_Month", "T_Mru", "T_Multicastclient", "T_Nic",
  "T_Nolink", "T_Nomodify", "T_Nomrulist", "T_None", "T_Nonvolatile",
  "T_Noepeer", "T_Nopeer", "T_Noquery", "T_Noselect", "T_Noserve",
  "T_Notrap", "T_Notrust", "T_Ntp", "T_Ntpport", "T_NtpSignDsocket",
  "T_Orphan", "T_Orphanwait", "T_PCEdigest", "T_Panic", "T_Peer",
  "T_Peerstats", "T_Phone", "T_Pid", "T_Pidfile", "T_Pool", "T_Port",
  "T_Preempt", "T_Prefer", "T_Protostats", "T_Pw", "T_Randfile",
  "T_Rawstats", "T_Refid", "T_Requestkey", "T_Reset", "T_Restrict",
  "T_Revoke", "T_Rlimit", "T_Saveconfigdir", "T_Server", "T_Setvar",
  "T_Source", "T_Stacksize", "T_Statistics", "T_Stats", "T_Statsdir",
  "T_Step", "T_Stepback", "T_Stepfwd", "T_Stepout", "T_Stratum",
  "T_String", "T_Sys", "T_Sysstats", "T_Tick", "T_Time1", "T_Time2",
  "T_Timer", "T_Timingstats", "T_Tinker", "T_Tos", "T_Trap", "T_True",
  "T_Trustedkey", "T_Ttl", "T_Type", "T_U_int", "T_UEcrypto",
  "T_UEcryptonak", "T_UEdigest", "T_Unconfig", "T_Unpeer", "T_Version",
  "T_WanderThreshold", "T_Week", "T_Wildcard", "T_Xleave", "T_Year",
  "T_Flag", "T_EOC", "T_Simulate", "T_Beep_Delay", "T_Sim_Duration",
  "T_Server_Offset", "T_Duration", "T_Freq_Offset", "T_Wander", "T_Jitter",
  "T_Prop_Delay", "T_Proc_Delay", "'='", "'('", "')'", "'{'", "'}'",
  "$accept", "configuration", "command_list", "command", "server_command",
  "client_type", "address", "ip_address", "address_fam", "option_list",
  "option", "option_flag", "option_flag_keyword", "option_int",
  "option_int_keyword", "option_str", "option_str_keyword",
  "unpeer_command", "unpeer_keyword", "other_mode_command",
  "authentication_command", "crypto_command_list", "crypto_command",
  "crypto_str_keyword", "orphan_mode_command", "tos_option_list",
  "tos_option", "tos_option_int_keyword", "tos_option_dbl_keyword",
  "monitoring_command", "stats_list", "stat", "filegen_option_list",
  "filegen_option", "link_nolink", "enable_disable", "filegen_type",
  "access_control_command", "ac_flag_list", "access_control_flag",
  "discard_option_list", "discard_option", "discard_option_keyword",
  "mru_option_list", "mru_option", "mru_option_keyword", "fudge_command",
  "fudge_factor_list", "fudge_factor", "fudge_factor_dbl_keyword",
  "fudge_factor_bool_keyword", "rlimit_command", "rlimit_option_list",
  "rlimit_option", "rlimit_option_keyword", "system_option_command",
  "system_option_list", "system_option", "system_option_flag_keyword",
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
     455,   456,    61,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF -187

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-187)))

#define YYTABLE_NINF -7

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,  -174,   -42,  -187,  -187,  -187,   -31,  -187,   397,    12,
    -137,  -187,   397,  -187,    84,   -37,  -187,  -119,  -187,  -106,
    -104,  -187,  -187,   -98,  -187,  -187,   -37,     3,   331,   -37,
    -187,  -187,   -97,  -187,   -92,  -187,  -187,    13,   235,   -13,
      15,   -26,  -187,  -187,   -90,    84,   -88,  -187,    48,   528,
     -81,   -58,    24,  -187,  -187,  -187,    93,   194,   -95,  -187,
     -37,  -187,   -37,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,     5,    37,   -61,   -59,  -187,     2,  -187,
    -187,  -100,  -187,  -187,  -187,   241,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,   397,  -187,
    -187,  -187,  -187,  -187,  -187,    12,  -187,    47,    78,  -187,
     397,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,   267,  -187,   -50,   363,  -187,  -187,  -187,
     -98,  -187,  -187,   -37,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,   331,  -187,    51,   -37,  -187,  -187,   -47,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,   235,  -187,
    -187,    94,   100,  -187,    41,  -187,  -187,  -187,  -187,   -26,
    -187,    68,   -69,  -187,    84,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,    48,  -187,     5,
     -28,  -187,  -187,  -187,   -33,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,   528,  -187,    70,     5,  -187,  -187,  -187,
      74,   -58,  -187,  -187,  -187,    75,  -187,   -27,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
      10,  -132,  -187,  -187,  -187,  -187,  -187,    85,  -187,     4,
    -187,  -187,  -187,  -187,   -29,     7,  -187,  -187,  -187,  -187,
       8,   101,  -187,  -187,   267,  -187,     5,   -33,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,   447,  -187,  -187,   447,
     -81,   447,  -187,  -187,    16,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,   -40,   134,  -187,  -187,
    -187,   180,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -102,   -17,   -22,  -187,  -187,  -187,  -187,    22,  -187,  -187,
       9,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,   447,   447,
    -187,   146,   -81,   112,  -187,   126,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,   -53,  -187,    28,   -10,    14,
    -143,  -187,    -9,  -187,     5,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,   447,  -187,  -187,  -187,  -187,    -4,
    -187,  -187,  -187,   -37,  -187,  -187,  -187,     6,  -187,  -187,
    -187,    18,    17,     5,    21,  -166,  -187,    39,     5,  -187,
    -187,  -187,    23,   -46,  -187,  -187,  -187,  -187,  -187,   255,
      44,    30,  -187,    49,  -187,     5,  -187,  -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,    24,    58,   239,     0,    71,     0,     0,
     251,   242,     0,   232,     0,     0,   244,     0,   264,     0,
       0,   245,   243,     0,   246,    25,     0,     0,     0,     0,
     265,   240,     0,    23,     0,   247,    22,     0,     0,     0,
       0,     0,   248,    21,     0,     0,     0,   241,     0,     0,
       0,     0,     0,    56,    57,   301,     0,     2,     0,     7,
       0,     8,     0,     9,    10,    13,    11,    12,    14,    15,
      16,    17,    18,     0,     0,     0,     0,   225,     0,   226,
      19,     0,     5,    62,    63,    64,   199,   200,   201,   202,
     205,   203,   204,   206,   207,   208,   209,   210,   194,   196,
     197,   198,   158,   159,   160,   128,   156,     0,   249,   233,
     193,   103,   104,   105,   106,   110,   107,   108,   109,   111,
      29,    30,    28,     0,    26,     0,     6,    65,    66,   261,
     234,   260,   293,    59,    61,   164,   165,   166,   167,   168,
     169,   170,   171,   129,   162,     0,    60,    70,   291,   235,
      67,   276,   277,   278,   279,   280,   281,   282,   273,   275,
     136,    29,    30,   136,   136,    68,   192,   190,   191,   186,
     188,     0,     0,   236,    98,   102,    99,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   211,   213,     0,
       0,    87,    88,    89,     0,    90,    91,    97,    92,    96,
      93,    94,    95,    80,    82,     0,     0,    86,   255,   287,
       0,    69,   286,   288,   284,   238,     1,     0,     4,    31,
      55,   298,   297,   227,   228,   229,   230,   272,   271,   270,
       0,     0,    79,    75,    76,    77,    78,     0,    72,     0,
     195,   155,   157,   250,   100,     0,   182,   183,   184,   185,
       0,     0,   180,   181,   172,   174,     0,     0,    27,   231,
     259,   292,   161,   163,   290,   274,   132,   136,   136,   135,
       0,   130,   187,   189,     0,   101,   212,   214,   299,   296,
     294,   295,    85,    81,    83,    84,   237,     0,   285,   283,
       3,    20,   266,   267,   268,   263,   269,   262,   305,   306,
       0,     0,     0,    74,    73,   120,   119,     0,   117,   118,
       0,   112,   115,   116,   178,   179,   177,   173,   175,   176,
     138,   139,   140,   141,   142,   143,   144,   146,   147,   145,
     148,   149,   150,   151,   152,   153,   154,   137,   133,   134,
     136,   254,     0,     0,   256,     0,    37,    38,    39,    54,
      47,    49,    48,    51,    40,    41,    42,    43,    50,    52,
      44,    32,    33,    36,    34,     0,    35,     0,     0,     0,
       0,   308,     0,   303,     0,   113,   127,   123,   125,   121,
     122,   124,   126,   114,   131,   253,   252,   258,   257,     0,
      45,    46,    53,     0,   302,   300,   307,     0,   304,   289,
     311,     0,     0,     0,     0,     0,   313,     0,     0,   309,
     312,   310,     0,     0,   318,   319,   320,   321,   322,     0,
       0,     0,   314,     0,   316,     0,   315,   317
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,   -39,  -187,  -187,   -15,   -49,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,    38,  -187,  -187,  -187,
    -187,   -38,  -187,  -187,  -187,  -187,  -187,  -187,  -159,  -187,
    -187,   110,  -187,  -187,   102,  -187,  -187,  -187,    -8,  -187,
    -187,  -187,  -187,    79,  -187,  -187,   232,   -57,  -187,  -187,
    -187,  -187,    63,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,   122,  -187,  -187,  -187,  -187,
    -187,  -187,    97,  -187,  -187,    45,  -187,  -187,   229,    19,
    -186,  -187,  -187,  -187,  -187,   -36,  -187,  -187,  -110,  -187,
    -187,  -187,  -144,  -187,  -156,  -187
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    56,    57,    58,    59,    60,   132,   124,   125,   291,
     361,   362,   363,   364,   365,   366,   367,    61,    62,    63,
      64,    85,   238,   239,    65,   203,   204,   205,   206,    66,
     174,   119,   244,   311,   312,   313,   383,    67,   266,   337,
     105,   106,   107,   143,   144,   145,    68,   254,   255,   256,
     257,    69,   169,   170,   171,    70,    98,    99,   100,   101,
      71,   187,   188,   189,    72,    73,    74,    75,    76,   109,
     173,   386,   286,   344,   130,   131,    77,    78,   297,   230,
      79,   158,   159,   215,   211,   212,   213,   149,   133,   282,
     223,   207,    80,    81,   300,   301,   302,   370,   371,   402,
     372,   405,   406,   419,   420,   421
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   208,   305,   277,   269,   271,   209,   175,   368,   279,
     306,   390,     1,   376,   307,   292,   160,    82,   217,   166,
     285,     2,    83,   102,   164,   342,   108,     3,     4,     5,
     404,   280,   120,    84,   121,     6,     7,   377,   227,   221,
     409,   240,     8,     9,   126,   219,    10,   220,    11,   368,
      12,    13,   308,   240,   177,    14,   161,   127,   162,   128,
     228,   298,   299,   395,    15,   129,   147,   134,    16,   222,
     318,   148,   167,   172,    17,   176,    18,   150,   293,   165,
     294,   178,   122,   309,   229,    19,    20,   259,   214,    21,
      22,   298,   299,   216,    23,    24,   218,   343,    25,    26,
     179,   224,   225,   180,   226,   231,   111,    27,   338,   339,
     112,   242,   243,   258,   103,   263,   264,   378,   261,   104,
      28,    29,    30,   267,   379,   391,   122,    31,   168,   268,
     270,   261,   273,   274,   284,   278,   275,    32,   287,   289,
     163,   281,    33,   380,    34,   210,    35,    36,   310,   303,
     122,   414,   415,   416,   417,   418,    37,    38,    39,    40,
      41,    42,    43,    44,   290,   316,    45,   304,    46,   113,
     314,   315,   345,   295,   373,   385,   388,    47,   181,   341,
     374,   384,    48,    49,    50,   375,    51,    52,   398,   346,
     389,   392,   393,    53,    54,   381,   397,   296,   382,   347,
     399,   401,    -6,    55,     2,   394,   182,   183,   184,   185,
       3,     4,     5,   404,   186,   241,   114,   407,     6,     7,
     403,   340,   412,   408,   115,     8,     9,   116,   413,    10,
     411,    11,   425,    12,    13,   424,   348,   349,    14,   427,
     426,   283,   151,   152,   110,   262,   317,    15,   272,   117,
     276,    16,   260,   350,   118,   265,   288,    17,   146,    18,
     396,   410,   153,   423,   369,     0,     0,     0,    19,    20,
     245,   232,    21,    22,     0,   351,   319,    23,    24,     0,
       0,    25,    26,   352,     0,   353,     0,     0,     0,     0,
      27,     0,     0,   387,     0,   233,     0,     0,   234,     0,
     354,     0,   154,    28,    29,    30,     0,     0,     0,     0,
      31,     0,     0,   246,   247,   248,   249,     0,   355,   356,
      32,     0,     0,     0,     0,    33,     0,    34,     0,    35,
      36,     0,   155,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,    42,    43,    44,     0,     0,    45,
       0,    46,     0,     0,   357,     0,   358,     0,     0,     0,
      47,     0,     0,     0,   359,    48,    49,    50,   360,    51,
      52,     0,     0,     2,     0,     0,    53,    54,   400,     3,
       4,     5,   235,   236,     0,    -6,    55,     6,     7,   237,
     135,   136,   137,   138,     8,     9,     0,     0,    10,   156,
      11,     0,    12,    13,   157,    86,     0,    14,     0,     0,
      87,   250,     0,     0,     0,     0,    15,    88,     0,     0,
      16,   139,     0,   140,     0,   141,    17,     0,    18,   251,
       0,   142,     0,     0,   252,   253,     0,    19,    20,     0,
       0,    21,    22,     0,     0,     0,    23,    24,     0,     0,
      25,    26,   414,   415,   416,   417,   418,     0,     0,    27,
       0,   422,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,    28,    29,    30,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,   320,    32,
       0,     0,     0,     0,    33,     0,    34,   321,    35,    36,
       0,     0,     0,    90,    91,   322,     0,     0,    37,    38,
      39,    40,    41,    42,    43,    44,     0,     0,    45,     0,
      46,    92,     0,   323,   324,     0,    93,   325,     0,    47,
       0,     0,     0,   326,    48,    49,    50,     0,    51,    52,
     190,     0,   191,   192,     0,    53,    54,     0,     0,   193,
       0,   194,     0,    94,     0,    55,     0,     0,     0,     0,
     327,   328,     0,     0,   329,   330,   331,     0,   332,   333,
     334,     0,   335,     0,     0,     0,    95,    96,    97,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   196,
       0,   197,     0,     0,     0,     0,     0,   198,     0,   199,
       0,   336,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   202
};

static const yytype_int16 yycheck[] =
{
      15,    50,    31,   189,   163,   164,    64,    45,   151,    42,
      39,    64,     1,     4,    43,     5,    29,   191,    57,    45,
     206,    10,    64,    11,    39,    65,   163,    16,    17,    18,
     196,    64,    69,    64,    71,    24,    25,    28,    36,    34,
     206,    98,    31,    32,   163,    60,    35,    62,    37,   151,
      39,    40,    81,   110,     6,    44,    69,   163,    71,   163,
      58,   193,   194,   206,    53,   163,   163,    64,    57,    64,
     256,   163,    98,   163,    63,   163,    65,    64,    68,    64,
      70,    33,   163,   112,    82,    74,    75,   126,    64,    78,
      79,   193,   194,     0,    83,    84,   191,   137,    87,    88,
      52,    64,   163,    55,   163,   205,    22,    96,   267,   268,
      26,    64,    34,   163,   102,    64,   163,   108,   133,   107,
     109,   110,   111,    29,   115,   178,   163,   116,   154,    29,
      89,   146,    64,   202,    64,   163,   174,   126,    64,    64,
     153,   174,   131,   134,   133,   203,   135,   136,   177,    64,
     163,   197,   198,   199,   200,   201,   145,   146,   147,   148,
     149,   150,   151,   152,   191,    64,   155,   163,   157,    85,
     163,   163,    38,   163,   191,    29,    64,   166,   130,   163,
     202,   340,   171,   172,   173,   163,   175,   176,   374,     9,
      64,   163,   202,   182,   183,   186,   205,   187,   189,    19,
     204,   195,   191,   192,    10,   191,   158,   159,   160,   161,
      16,    17,    18,   196,   166,   105,   132,   403,    24,    25,
     202,   270,   408,   202,   140,    31,    32,   143,   205,    35,
     191,    37,   202,    39,    40,   191,    56,    57,    44,   425,
     191,   203,     7,     8,    12,   143,   254,    53,   169,   165,
     187,    57,   130,    73,   170,   158,   211,    63,    29,    65,
     370,   405,    27,   419,   300,    -1,    -1,    -1,    74,    75,
       3,    30,    78,    79,    -1,    95,   257,    83,    84,    -1,
      -1,    87,    88,   103,    -1,   105,    -1,    -1,    -1,    -1,
      96,    -1,    -1,   342,    -1,    54,    -1,    -1,    57,    -1,
     120,    -1,    67,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    46,    47,    48,    49,    -1,   138,   139,
     126,    -1,    -1,    -1,    -1,   131,    -1,   133,    -1,   135,
     136,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,   155,
      -1,   157,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   184,   171,   172,   173,   188,   175,
     176,    -1,    -1,    10,    -1,    -1,   182,   183,   393,    16,
      17,    18,   141,   142,    -1,   191,   192,    24,    25,   148,
      59,    60,    61,    62,    31,    32,    -1,    -1,    35,   164,
      37,    -1,    39,    40,   169,     8,    -1,    44,    -1,    -1,
      13,   144,    -1,    -1,    -1,    -1,    53,    20,    -1,    -1,
      57,    90,    -1,    92,    -1,    94,    63,    -1,    65,   162,
      -1,   100,    -1,    -1,   167,   168,    -1,    74,    75,    -1,
      -1,    78,    79,    -1,    -1,    -1,    83,    84,    -1,    -1,
      87,    88,   197,   198,   199,   200,   201,    -1,    -1,    96,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,   126,
      -1,    -1,    -1,    -1,   131,    -1,   133,    50,   135,   136,
      -1,    -1,    -1,   106,   107,    58,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,   155,    -1,
     157,   124,    -1,    76,    77,    -1,   129,    80,    -1,   166,
      -1,    -1,    -1,    86,   171,   172,   173,    -1,   175,   176,
      12,    -1,    14,    15,    -1,   182,   183,    -1,    -1,    21,
      -1,    23,    -1,   156,    -1,   192,    -1,    -1,    -1,    -1,
     113,   114,    -1,    -1,   117,   118,   119,    -1,   121,   122,
     123,    -1,   125,    -1,    -1,    -1,   179,   180,   181,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
      -1,   184,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    10,    16,    17,    18,    24,    25,    31,    32,
      35,    37,    39,    40,    44,    53,    57,    63,    65,    74,
      75,    78,    79,    83,    84,    87,    88,    96,   109,   110,
     111,   116,   126,   131,   133,   135,   136,   145,   146,   147,
     148,   149,   150,   151,   152,   155,   157,   166,   171,   172,
     173,   175,   176,   182,   183,   192,   208,   209,   210,   211,
     212,   224,   225,   226,   227,   231,   236,   244,   253,   258,
     262,   267,   271,   272,   273,   274,   275,   283,   284,   287,
     299,   300,   191,    64,    64,   228,     8,    13,    20,    72,
     106,   107,   124,   129,   156,   179,   180,   181,   263,   264,
     265,   266,    11,   102,   107,   247,   248,   249,   163,   276,
     263,    22,    26,    85,   132,   140,   143,   165,   170,   238,
      69,    71,   163,   213,   214,   215,   163,   163,   163,   163,
     281,   282,   213,   295,    64,    59,    60,    61,    62,    90,
      92,    94,   100,   250,   251,   252,   295,   163,   163,   294,
      64,     7,     8,    27,    67,    97,   164,   169,   288,   289,
      29,    69,    71,   153,   213,    64,    45,    98,   154,   259,
     260,   261,   163,   277,   237,   238,   163,     6,    33,    52,
      55,   130,   158,   159,   160,   161,   166,   268,   269,   270,
      12,    14,    15,    21,    23,    51,    91,    93,    99,   101,
     104,   127,   128,   232,   233,   234,   235,   298,   214,    64,
     203,   291,   292,   293,    64,   290,     0,   210,   191,   213,
     213,    34,    64,   297,    64,   163,   163,    36,    58,    82,
     286,   205,    30,    54,    57,   141,   142,   148,   229,   230,
     264,   248,    64,    34,   239,     3,    46,    47,    48,    49,
     144,   162,   167,   168,   254,   255,   256,   257,   163,   210,
     282,   213,   251,    64,   163,   289,   245,    29,    29,   245,
      89,   245,   260,    64,   202,   238,   269,   297,   163,    42,
      64,   174,   296,   233,    64,   297,   279,    64,   292,    64,
     191,   216,     5,    68,    70,   163,   187,   285,   193,   194,
     301,   302,   303,    64,   163,    31,    39,    43,    81,   112,
     177,   240,   241,   242,   163,   163,    64,   255,   297,   296,
      41,    50,    58,    76,    77,    80,    86,   113,   114,   117,
     118,   119,   121,   122,   123,   125,   184,   246,   245,   245,
     214,   163,    65,   137,   280,    38,     9,    19,    56,    57,
      73,    95,   103,   105,   120,   138,   139,   174,   176,   184,
     188,   217,   218,   219,   220,   221,   222,   223,   151,   302,
     304,   305,   307,   191,   202,   163,     4,    28,   108,   115,
     134,   186,   189,   243,   245,    29,   278,   214,    64,    64,
      64,   178,   163,   202,   191,   206,   305,   205,   297,   204,
     213,   195,   306,   202,   196,   308,   309,   297,   202,   206,
     309,   191,   297,   205,   197,   198,   199,   200,   201,   310,
     311,   312,   206,   311,   191,   202,   191,   297
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   207,   208,   209,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     211,   212,   212,   212,   212,   212,   213,   213,   214,   215,
     215,   216,   216,   217,   217,   217,   218,   219,   219,   219,
     219,   219,   219,   219,   219,   220,   220,   221,   221,   221,
     221,   221,   221,   222,   223,   224,   225,   225,   226,   226,
     226,   226,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   228,   228,   229,   229,   230,   230,   230,   230,   230,
     231,   232,   232,   233,   233,   233,   233,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   235,   235,   236,   236,
     236,   237,   237,   238,   238,   238,   238,   238,   238,   238,
     238,   239,   239,   240,   240,   240,   240,   241,   241,   242,
     242,   243,   243,   243,   243,   243,   243,   243,   244,   244,
     244,   244,   244,   244,   244,   244,   245,   245,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   247,   247,   248,   249,   249,
     249,   250,   250,   251,   252,   252,   252,   252,   252,   252,
     252,   252,   253,   254,   254,   255,   255,   255,   255,   255,
     256,   256,   257,   257,   257,   257,   258,   259,   259,   260,
     261,   261,   261,   262,   262,   263,   263,   264,   264,   265,
     265,   265,   265,   265,   265,   266,   266,   266,   266,   266,
     266,   267,   268,   268,   269,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   272,
     272,   272,   273,   273,   274,   274,   275,   275,   275,   276,
     276,   276,   277,   278,   278,   279,   279,   280,   280,   281,
     281,   282,   283,   283,   284,   284,   285,   285,   285,   285,
     286,   286,   286,   287,   288,   288,   289,   289,   289,   289,
     289,   289,   289,   290,   290,   291,   291,   292,   292,   293,
     294,   294,   295,   295,   296,   296,   296,   297,   297,   298,
     299,   300,   301,   301,   302,   303,   303,   304,   304,   305,
     306,   307,   308,   308,   309,   310,   310,   311,   312,   312,
     312,   312,   312
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
       1,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     1,     2,     2,     2,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     4,     1,     0,     0,     2,     2,     2,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     5,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       5,     1,     3,     2,     3,     1,     1,     2,     1,     5,
       4,     3,     2,     1,     6,     3,     2,     3,     1,     1,
       1,     1,     1
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
#line 382 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 2135 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 418 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			peer_node *my_node;

			my_node = create_peer_node((yyvsp[-2].Integer), (yyvsp[-1].Address_node), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.peers, my_node);
		}
#line 2146 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 437 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Address_node) = create_address_node((yyvsp[0].String), (yyvsp[-1].Integer)); }
#line 2152 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 442 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Address_node) = create_address_node((yyvsp[0].String), AF_UNSPEC); }
#line 2158 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 447 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = AF_INET; }
#line 2164 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 449 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = AF_INET6; }
#line 2170 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 454 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 2176 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 456 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2185 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 470 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 2191 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 486 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2197 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 488 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_uval((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2203 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 502 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2209 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 516 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			unpeer_node *my_node;

			my_node = create_unpeer_node((yyvsp[0].Address_node));
			if (my_node)
				APPEND_G_FIFO(cfgt.unpeers, my_node);
		}
#line 2221 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 537 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.broadcastclient = 1; }
#line 2227 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 539 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.manycastserver, (yyvsp[0].Address_fifo)); }
#line 2233 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 541 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.multicastclient, (yyvsp[0].Address_fifo)); }
#line 2239 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 543 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.mdnstries = (yyvsp[0].Integer); }
#line 2245 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 554 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *atrv;

			atrv = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			APPEND_G_FIFO(cfgt.vars, atrv);
		}
#line 2256 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 561 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.control_key = (yyvsp[0].Integer); }
#line 2262 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 563 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			cfgt.auth.cryptosw++;
			CONCAT_G_FIFOS(cfgt.auth.crypto_cmd_list, (yyvsp[0].Attr_val_fifo));
		}
#line 2271 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 568 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.keys = (yyvsp[0].String); }
#line 2277 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 570 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.keysdir = (yyvsp[0].String); }
#line 2283 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 572 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.request_key = (yyvsp[0].Integer); }
#line 2289 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 574 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.revoke = (yyvsp[0].Integer); }
#line 2295 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 576 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			/* [Bug 948] leaves it open if appending or
			 * replacing the trusted key list is the right
			 * way. In any case, either alternative should
			 * be coded correctly!
			 */
			DESTROY_G_FIFO(cfgt.auth.trusted_key_list, destroy_attr_val); /* remove for append */
			CONCAT_G_FIFOS(cfgt.auth.trusted_key_list, (yyvsp[0].Attr_val_fifo));
		}
#line 2309 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 586 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.ntp_signd_socket = (yyvsp[0].String); }
#line 2315 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 591 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 2321 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 593 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2330 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 601 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2336 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 603 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val) = NULL;
			cfgt.auth.revoke = (yyvsp[0].Integer);
			msyslog(LOG_WARNING,
				"'crypto revoke %d' is deprecated, "
				"please use 'revoke %d' instead.",
				cfgt.auth.revoke, cfgt.auth.revoke);
		}
#line 2349 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 628 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.orphan_cmds, (yyvsp[0].Attr_val_fifo)); }
#line 2355 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 633 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2364 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 638 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2373 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 646 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (double)(yyvsp[0].Integer)); }
#line 2379 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 648 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2385 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 650 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (double)(yyvsp[0].Integer)); }
#line 2391 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 652 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Basedate, (yyvsp[0].Integer)); }
#line 2397 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 679 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.stats_list, (yyvsp[0].Int_fifo)); }
#line 2403 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 681 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				cfgt.stats_dir = (yyvsp[0].String);
			} else {
				YYFREE((yyvsp[0].String));
				yyerror("statsdir remote configuration ignored");
			}
		}
#line 2416 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 690 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			filegen_node *fgn;

			fgn = create_filegen_node((yyvsp[-1].Integer), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.filegen_opts, fgn);
		}
#line 2427 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 700 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2436 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 705 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = NULL;
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2445 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 724 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 2451 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 726 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2460 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 734 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String));
			} else {
				(yyval.Attr_val) = NULL;
				YYFREE((yyvsp[0].String));
				yyerror("filegen file remote config ignored");
			}
		}
#line 2474 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 744 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				yyerror("filegen type remote config ignored");
			}
		}
#line 2487 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 753 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 2506 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 768 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 2512 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 798 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			CONCAT_G_FIFOS(cfgt.discard_opts, (yyvsp[0].Attr_val_fifo));
		}
#line 2520 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 802 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			CONCAT_G_FIFOS(cfgt.mru_opts, (yyvsp[0].Attr_val_fifo));
		}
#line 2528 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 806 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node((yyvsp[-1].Address_node), NULL, (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2540 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 814 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node((yyvsp[-3].Address_node), (yyvsp[-1].Address_node), (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2552 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 822 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node(NULL, NULL, (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2564 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 830 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 2583 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 845 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 2602 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 860 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *	rn;

			APPEND_G_FIFO((yyvsp[0].Int_fifo), create_int_node((yyvsp[-1].Integer)));
			rn = create_restrict_node(
				NULL, NULL, (yyvsp[0].Int_fifo), lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2615 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 872 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Int_fifo) = NULL; }
#line 2621 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 874 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2630 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 902 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2639 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 907 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2648 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 915 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2654 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 926 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2663 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 931 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2672 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 939 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2678 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 959 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			addr_opts_node *aon;

			aon = create_addr_opts_node((yyvsp[-1].Address_node), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.fudge, aon);
		}
#line 2689 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 969 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2698 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 974 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2707 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 982 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2713 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 984 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2719 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 986 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].Integer) >= 0 && (yyvsp[0].Integer) <= 16) {
				(yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				yyerror("fudge factor: stratum value not in [0..16], ignored");
			}
		}
#line 2732 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 995 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2738 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 997 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2744 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1018 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.rlimit, (yyvsp[0].Attr_val_fifo)); }
#line 2750 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1023 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2759 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1028 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2768 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1036 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2774 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1052 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.enable_opts, (yyvsp[0].Attr_val_fifo)); }
#line 2780 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1054 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.disable_opts, (yyvsp[0].Attr_val_fifo)); }
#line 2786 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1059 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2795 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1064 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2804 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1072 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 2810 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1074 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 2828 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1113 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.tinker, (yyvsp[0].Attr_val_fifo)); }
#line 2834 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1118 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2843 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1123 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2852 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1131 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2858 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1156 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;

			av = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2869 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1163 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;

			av = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2880 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1170 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;

			av = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2891 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1177 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 2911 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1193 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 2934 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1212 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { lex_flush_stack(); }
#line 2940 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1214 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { /* see drift_parm below for actions */ }
#line 2946 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1216 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.logconfig, (yyvsp[0].Attr_val_fifo)); }
#line 2952 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1218 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.phone, (yyvsp[0].String_fifo)); }
#line 2958 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1220 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { APPEND_G_FIFO(cfgt.setvar, (yyvsp[0].Set_var)); }
#line 2964 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1222 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			addr_opts_node *aon;

			aon = create_addr_opts_node((yyvsp[-1].Address_node), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.trap, aon);
		}
#line 2975 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1229 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.ttl, (yyvsp[0].Attr_val_fifo)); }
#line 2981 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1244 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
#ifndef LEAP_SMEAR
			yyerror("Built without LEAP_SMEAR support.");
#endif
		}
#line 2991 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1264 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 3006 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1275 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 3023 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1288 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				attr_val *av;
				av = create_attr_sval(T_Driftfile, estrdup(""));
				APPEND_G_FIFO(cfgt.vars, av);
			} else {
				yyerror("driftfile remote configuration ignored");
			}
		}
#line 3037 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1301 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Set_var) = create_setvar_node((yyvsp[-3].String), (yyvsp[-1].String), (yyvsp[0].Integer)); }
#line 3043 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1307 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 0; }
#line 3049 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1312 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 3055 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1314 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3064 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1322 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 3070 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1324 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), estrdup((yyvsp[0].Address_node)->address));
			destroy_address_node((yyvsp[0].Address_node));
		}
#line 3079 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1332 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3088 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1337 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3097 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1345 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
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
#line 3123 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1370 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			nic_rule_node *nrn;

			nrn = create_nic_rule_node((yyvsp[0].Integer), NULL, (yyvsp[-1].Integer));
			APPEND_G_FIFO(cfgt.nic_rules, nrn);
		}
#line 3134 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1377 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			nic_rule_node *nrn;

			nrn = create_nic_rule_node(0, (yyvsp[0].String), (yyvsp[-1].Integer));
			APPEND_G_FIFO(cfgt.nic_rules, nrn);
		}
#line 3145 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1405 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.reset_counters, (yyvsp[0].Int_fifo)); }
#line 3151 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1410 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 3160 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1415 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = NULL;
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 3169 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1439 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 3178 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1444 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 3187 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1452 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3196 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1457 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 3205 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1465 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival('i', (yyvsp[0].Integer)); }
#line 3211 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1471 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_rangeval('-', (yyvsp[-3].Integer), (yyvsp[-1].Integer)); }
#line 3217 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1476 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.String_fifo) = (yyvsp[-1].String_fifo);
			APPEND_G_FIFO((yyval.String_fifo), create_string_node((yyvsp[0].String)));
		}
#line 3226 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1481 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.String_fifo) = NULL;
			APPEND_G_FIFO((yyval.String_fifo), create_string_node((yyvsp[0].String)));
		}
#line 3235 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1489 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Address_fifo) = (yyvsp[-1].Address_fifo);
			APPEND_G_FIFO((yyval.Address_fifo), (yyvsp[0].Address_node));
		}
#line 3244 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1494 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Address_fifo) = NULL;
			APPEND_G_FIFO((yyval.Address_fifo), (yyvsp[0].Address_node));
		}
#line 3253 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1502 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].Integer) != 0 && (yyvsp[0].Integer) != 1) {
				yyerror("Integer value is not boolean (0 or 1). Assuming 1");
				(yyval.Integer) = 1;
			} else {
				(yyval.Integer) = (yyvsp[0].Integer);
			}
		}
#line 3266 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1510 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 1; }
#line 3272 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1511 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 0; }
#line 3278 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1515 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Double) = (double)(yyvsp[0].Integer); }
#line 3284 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1521 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = basedate_eval_string((yyvsp[0].String)); YYFREE((yyvsp[0].String)); }
#line 3290 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1529 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			sim_node *sn;

			sn =  create_sim_node((yyvsp[-2].Attr_val_fifo), (yyvsp[-1].Sim_server_fifo));
			APPEND_G_FIFO(cfgt.sim_details, sn);

			/* Revert from ; to \n for end-of-command */
			old_config_style = 1;
		}
#line 3304 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1546 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { old_config_style = 0; }
#line 3310 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1551 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-2].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[-1].Attr_val));
		}
#line 3319 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1556 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[-1].Attr_val));
		}
#line 3328 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1564 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-2].Integer), (yyvsp[0].Double)); }
#line 3334 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1574 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Sim_server_fifo) = (yyvsp[-1].Sim_server_fifo);
			APPEND_G_FIFO((yyval.Sim_server_fifo), (yyvsp[0].Sim_server));
		}
#line 3343 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1579 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Sim_server_fifo) = NULL;
			APPEND_G_FIFO((yyval.Sim_server_fifo), (yyvsp[0].Sim_server));
		}
#line 3352 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1587 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Sim_server) = ONLY_SIM(create_sim_server((yyvsp[-4].Address_node), (yyvsp[-2].Double), (yyvsp[-1].Sim_script_fifo))); }
#line 3358 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1592 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-1].Double); }
#line 3364 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1597 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Address_node) = (yyvsp[0].Address_node); }
#line 3370 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1602 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Sim_script_fifo) = (yyvsp[-1].Sim_script_fifo);
			APPEND_G_FIFO((yyval.Sim_script_fifo), (yyvsp[0].Sim_script));
		}
#line 3379 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1607 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Sim_script_fifo) = NULL;
			APPEND_G_FIFO((yyval.Sim_script_fifo), (yyvsp[0].Sim_script));
		}
#line 3388 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1615 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Sim_script) = ONLY_SIM(create_sim_script_info((yyvsp[-3].Double), (yyvsp[-1].Attr_val_fifo))); }
#line 3394 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1620 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-2].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[-1].Attr_val));
		}
#line 3403 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1625 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[-1].Attr_val));
		}
#line 3412 "ntp_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1633 "../../ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-2].Integer), (yyvsp[0].Double)); }
#line 3418 "ntp_parser.c" /* yacc.c:1646  */
    break;


#line 3422 "ntp_parser.c" /* yacc.c:1646  */
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
#line 1644 "../../ntpd/ntp_parser.y" /* yacc.c:1906  */


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

