
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 11 "ntp_parser.y"

  #ifdef HAVE_CONFIG_H
  # include <config.h>
  #endif

  #include "ntpd.h"
  #include "ntp_machine.h"
  #include "ntp.h"
  #include "ntp_stdlib.h"
  #include "ntp_filegen.h"
  #include "ntp_data_structures.h"
  #include "ntp_scanner.h"
  #include "ntp_config.h"
  #include "ntp_crypto.h"

  #include "ntpsim.h"		/* HMS: Do we really want this all the time? */
				/* SK: It might be a good idea to always
				   include the simulator code. That way
				   someone can use the same configuration file
				   for both the simulator and the daemon
				*/


  struct FILE_INFO *ip_file;   /* Pointer to the configuration file stream */

  #define YYMALLOC	emalloc
  #define YYFREE	free
  #define YYERROR_VERBOSE
  #define YYMAXDEPTH	1000   /* stop the madness sooner */
  void yyerror (char *msg);
  extern int input_from_file;  /* 0=input from ntpq :config */
  extern int cryptosw;


/* Line 189 of yacc.c  */
#line 108 "ntp_parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Age = 258,
     T_All = 259,
     T_Allan = 260,
     T_Auth = 261,
     T_Autokey = 262,
     T_Automax = 263,
     T_Average = 264,
     T_Bclient = 265,
     T_Beacon = 266,
     T_Bias = 267,
     T_Broadcast = 268,
     T_Broadcastclient = 269,
     T_Broadcastdelay = 270,
     T_Burst = 271,
     T_Calibrate = 272,
     T_Calldelay = 273,
     T_Ceiling = 274,
     T_Clockstats = 275,
     T_Cohort = 276,
     T_ControlKey = 277,
     T_Crypto = 278,
     T_Cryptostats = 279,
     T_Day = 280,
     T_Default = 281,
     T_Disable = 282,
     T_Discard = 283,
     T_Dispersion = 284,
     T_Double = 285,
     T_Driftfile = 286,
     T_Drop = 287,
     T_Enable = 288,
     T_End = 289,
     T_False = 290,
     T_File = 291,
     T_Filegen = 292,
     T_Flag1 = 293,
     T_Flag2 = 294,
     T_Flag3 = 295,
     T_Flag4 = 296,
     T_Flake = 297,
     T_Floor = 298,
     T_Freq = 299,
     T_Fudge = 300,
     T_Host = 301,
     T_Huffpuff = 302,
     T_Iburst = 303,
     T_Ident = 304,
     T_Ignore = 305,
     T_Includefile = 306,
     T_Integer = 307,
     T_Interface = 308,
     T_Ipv4 = 309,
     T_Ipv4_flag = 310,
     T_Ipv6 = 311,
     T_Ipv6_flag = 312,
     T_Kernel = 313,
     T_Key = 314,
     T_Keys = 315,
     T_Keysdir = 316,
     T_Kod = 317,
     T_Mssntp = 318,
     T_Leapfile = 319,
     T_Limited = 320,
     T_Link = 321,
     T_Listen = 322,
     T_Logconfig = 323,
     T_Logfile = 324,
     T_Loopstats = 325,
     T_Lowpriotrap = 326,
     T_Manycastclient = 327,
     T_Manycastserver = 328,
     T_Mask = 329,
     T_Maxclock = 330,
     T_Maxdist = 331,
     T_Maxhop = 332,
     T_Maxpoll = 333,
     T_Minclock = 334,
     T_Mindist = 335,
     T_Minimum = 336,
     T_Minpoll = 337,
     T_Minsane = 338,
     T_Mode = 339,
     T_Monitor = 340,
     T_Month = 341,
     T_Multicastclient = 342,
     T_Nic = 343,
     T_Nolink = 344,
     T_Nomodify = 345,
     T_None = 346,
     T_Nopeer = 347,
     T_Noquery = 348,
     T_Noselect = 349,
     T_Noserve = 350,
     T_Notrap = 351,
     T_Notrust = 352,
     T_Ntp = 353,
     T_Ntpport = 354,
     T_NtpSignDsocket = 355,
     T_Orphan = 356,
     T_Panic = 357,
     T_Peer = 358,
     T_Peerstats = 359,
     T_Phone = 360,
     T_Pid = 361,
     T_Pidfile = 362,
     T_Pool = 363,
     T_Port = 364,
     T_Preempt = 365,
     T_Prefer = 366,
     T_Protostats = 367,
     T_Pw = 368,
     T_Qos = 369,
     T_RandFile = 370,
     T_Rawstats = 371,
     T_Refid = 372,
     T_Requestkey = 373,
     T_Restrict = 374,
     T_Revoke = 375,
     T_Saveconfigdir = 376,
     T_Server = 377,
     T_Setvar = 378,
     T_Sign = 379,
     T_Statistics = 380,
     T_Stats = 381,
     T_Statsdir = 382,
     T_Step = 383,
     T_Stepout = 384,
     T_Stratum = 385,
     T_String = 386,
     T_Sysstats = 387,
     T_Tick = 388,
     T_Time1 = 389,
     T_Time2 = 390,
     T_Timingstats = 391,
     T_Tinker = 392,
     T_Tos = 393,
     T_Trap = 394,
     T_True = 395,
     T_Trustedkey = 396,
     T_Ttl = 397,
     T_Type = 398,
     T_Unconfig = 399,
     T_Unpeer = 400,
     T_Version = 401,
     T_WanderThreshold = 402,
     T_Week = 403,
     T_Xleave = 404,
     T_Year = 405,
     T_Flag = 406,
     T_Void = 407,
     T_EOC = 408,
     T_Simulate = 409,
     T_Beep_Delay = 410,
     T_Sim_Duration = 411,
     T_Server_Offset = 412,
     T_Duration = 413,
     T_Freq_Offset = 414,
     T_Wander = 415,
     T_Jitter = 416,
     T_Prop_Delay = 417,
     T_Proc_Delay = 418
   };
#endif
/* Tokens.  */
#define T_Age 258
#define T_All 259
#define T_Allan 260
#define T_Auth 261
#define T_Autokey 262
#define T_Automax 263
#define T_Average 264
#define T_Bclient 265
#define T_Beacon 266
#define T_Bias 267
#define T_Broadcast 268
#define T_Broadcastclient 269
#define T_Broadcastdelay 270
#define T_Burst 271
#define T_Calibrate 272
#define T_Calldelay 273
#define T_Ceiling 274
#define T_Clockstats 275
#define T_Cohort 276
#define T_ControlKey 277
#define T_Crypto 278
#define T_Cryptostats 279
#define T_Day 280
#define T_Default 281
#define T_Disable 282
#define T_Discard 283
#define T_Dispersion 284
#define T_Double 285
#define T_Driftfile 286
#define T_Drop 287
#define T_Enable 288
#define T_End 289
#define T_False 290
#define T_File 291
#define T_Filegen 292
#define T_Flag1 293
#define T_Flag2 294
#define T_Flag3 295
#define T_Flag4 296
#define T_Flake 297
#define T_Floor 298
#define T_Freq 299
#define T_Fudge 300
#define T_Host 301
#define T_Huffpuff 302
#define T_Iburst 303
#define T_Ident 304
#define T_Ignore 305
#define T_Includefile 306
#define T_Integer 307
#define T_Interface 308
#define T_Ipv4 309
#define T_Ipv4_flag 310
#define T_Ipv6 311
#define T_Ipv6_flag 312
#define T_Kernel 313
#define T_Key 314
#define T_Keys 315
#define T_Keysdir 316
#define T_Kod 317
#define T_Mssntp 318
#define T_Leapfile 319
#define T_Limited 320
#define T_Link 321
#define T_Listen 322
#define T_Logconfig 323
#define T_Logfile 324
#define T_Loopstats 325
#define T_Lowpriotrap 326
#define T_Manycastclient 327
#define T_Manycastserver 328
#define T_Mask 329
#define T_Maxclock 330
#define T_Maxdist 331
#define T_Maxhop 332
#define T_Maxpoll 333
#define T_Minclock 334
#define T_Mindist 335
#define T_Minimum 336
#define T_Minpoll 337
#define T_Minsane 338
#define T_Mode 339
#define T_Monitor 340
#define T_Month 341
#define T_Multicastclient 342
#define T_Nic 343
#define T_Nolink 344
#define T_Nomodify 345
#define T_None 346
#define T_Nopeer 347
#define T_Noquery 348
#define T_Noselect 349
#define T_Noserve 350
#define T_Notrap 351
#define T_Notrust 352
#define T_Ntp 353
#define T_Ntpport 354
#define T_NtpSignDsocket 355
#define T_Orphan 356
#define T_Panic 357
#define T_Peer 358
#define T_Peerstats 359
#define T_Phone 360
#define T_Pid 361
#define T_Pidfile 362
#define T_Pool 363
#define T_Port 364
#define T_Preempt 365
#define T_Prefer 366
#define T_Protostats 367
#define T_Pw 368
#define T_Qos 369
#define T_RandFile 370
#define T_Rawstats 371
#define T_Refid 372
#define T_Requestkey 373
#define T_Restrict 374
#define T_Revoke 375
#define T_Saveconfigdir 376
#define T_Server 377
#define T_Setvar 378
#define T_Sign 379
#define T_Statistics 380
#define T_Stats 381
#define T_Statsdir 382
#define T_Step 383
#define T_Stepout 384
#define T_Stratum 385
#define T_String 386
#define T_Sysstats 387
#define T_Tick 388
#define T_Time1 389
#define T_Time2 390
#define T_Timingstats 391
#define T_Tinker 392
#define T_Tos 393
#define T_Trap 394
#define T_True 395
#define T_Trustedkey 396
#define T_Ttl 397
#define T_Type 398
#define T_Unconfig 399
#define T_Unpeer 400
#define T_Version 401
#define T_WanderThreshold 402
#define T_Week 403
#define T_Xleave 404
#define T_Year 405
#define T_Flag 406
#define T_Void 407
#define T_EOC 408
#define T_Simulate 409
#define T_Beep_Delay 410
#define T_Sim_Duration 411
#define T_Server_Offset 412
#define T_Duration 413
#define T_Freq_Offset 414
#define T_Wander 415
#define T_Jitter 416
#define T_Prop_Delay 417
#define T_Proc_Delay 418




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 51 "ntp_parser.y"

    char   *String;
    double  Double;
    int     Integer;
    void   *VoidPtr;
    queue  *Queue;
    struct attr_val *Attr_val;
    struct address_node *Address_node;
    struct setvar_node *Set_var;

    /* Simulation types */
    server_info *Sim_server;
    script_info *Sim_script;



/* Line 214 of yacc.c  */
#line 487 "ntp_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 499 "ntp_parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  171
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   666

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  167
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  243
/* YYNRULES -- Number of states.  */
#define YYNSTATES  381

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   418

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   164,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   165,     2,   166,     2,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    15,    16,    18,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    38,    40,
      44,    47,    49,    51,    53,    55,    57,    59,    62,    65,
      67,    70,    72,    74,    77,    79,    81,    84,    87,    90,
      92,    94,    96,    98,   100,   103,   106,   109,   112,   114,
     116,   118,   121,   124,   127,   130,   133,   136,   139,   142,
     145,   148,   150,   151,   154,   156,   159,   162,   165,   168,
     171,   174,   177,   180,   182,   185,   188,   191,   194,   197,
     200,   203,   206,   209,   212,   215,   218,   221,   225,   228,
     230,   232,   234,   236,   238,   240,   242,   244,   246,   249,
     251,   254,   257,   259,   261,   263,   265,   267,   269,   271,
     273,   275,   277,   279,   282,   286,   290,   295,   300,   306,
     307,   310,   312,   314,   316,   318,   320,   322,   324,   326,
     328,   330,   332,   334,   336,   338,   341,   343,   346,   349,
     352,   356,   359,   361,   364,   367,   370,   373,   376,   379,
     382,   385,   388,   391,   394,   396,   398,   400,   402,   404,
     406,   408,   410,   413,   416,   418,   421,   424,   427,   430,
     433,   436,   439,   441,   445,   447,   450,   453,   456,   459,
     462,   465,   468,   471,   474,   477,   480,   483,   487,   490,
     493,   495,   498,   499,   504,   508,   511,   513,   516,   519,
     522,   524,   526,   530,   534,   536,   538,   540,   542,   544,
     546,   548,   550,   553,   555,   558,   560,   563,   565,   567,
     569,   571,   573,   575,   581,   583,   587,   590,   594,   598,
     601,   603,   609,   614,   618,   621,   623,   630,   634,   637,
     641,   645,   649,   653
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     168,     0,    -1,   169,    -1,   169,   170,   153,    -1,   170,
     153,    -1,     1,   153,    -1,    -1,   171,    -1,   177,    -1,
     179,    -1,   180,    -1,   187,    -1,   193,    -1,   184,    -1,
     198,    -1,   201,    -1,   204,    -1,   207,    -1,   223,    -1,
     172,   173,   175,    -1,   172,   173,    -1,   122,    -1,   108,
      -1,   103,    -1,    13,    -1,    72,    -1,   174,    -1,    55,
     131,    -1,    57,   131,    -1,   131,    -1,   175,   176,    -1,
     176,    -1,     7,    -1,    12,   222,    -1,    16,    -1,    48,
      -1,    59,    52,    -1,    82,    52,    -1,    78,    52,    -1,
      94,    -1,   110,    -1,   111,    -1,   140,    -1,   149,    -1,
     142,    52,    -1,    84,    52,    -1,   146,    52,    -1,   178,
     173,    -1,   144,    -1,   145,    -1,    14,    -1,    73,   220,
      -1,    87,   220,    -1,     8,    52,    -1,    22,    52,    -1,
      23,   181,    -1,    60,   131,    -1,    61,   131,    -1,   118,
      52,    -1,   141,   218,    -1,   100,   131,    -1,   182,    -1,
      -1,   182,   183,    -1,   183,    -1,    46,   131,    -1,    49,
     131,    -1,   113,   131,    -1,   115,   131,    -1,   120,    52,
      -1,   124,   131,    -1,   138,   185,    -1,   185,   186,    -1,
     186,    -1,    19,    52,    -1,    43,    52,    -1,    21,   221,
      -1,   101,    52,    -1,    80,   222,    -1,    76,   222,    -1,
      79,   222,    -1,    75,   222,    -1,    83,    52,    -1,    11,
      52,    -1,    77,    52,    -1,   125,   188,    -1,   127,   131,
      -1,    37,   189,   190,    -1,   188,   189,    -1,   189,    -1,
      20,    -1,    24,    -1,    70,    -1,   104,    -1,   116,    -1,
     132,    -1,   136,    -1,   112,    -1,   190,   191,    -1,   191,
      -1,    36,   131,    -1,   143,   192,    -1,    66,    -1,    89,
      -1,    33,    -1,    27,    -1,    91,    -1,   106,    -1,    25,
      -1,   148,    -1,    86,    -1,   150,    -1,     3,    -1,    28,
     196,    -1,   119,   173,   194,    -1,   119,    26,   194,    -1,
     119,    55,    26,   194,    -1,   119,    57,    26,   194,    -1,
     119,   174,    74,   174,   194,    -1,    -1,   194,   195,    -1,
      42,    -1,    50,    -1,    62,    -1,    63,    -1,    65,    -1,
      71,    -1,    90,    -1,    92,    -1,    93,    -1,    95,    -1,
      96,    -1,    97,    -1,    99,    -1,   146,    -1,   196,   197,
      -1,   197,    -1,     9,    52,    -1,    81,    52,    -1,    85,
      52,    -1,    45,   173,   199,    -1,   199,   200,    -1,   200,
      -1,   134,   222,    -1,   135,   222,    -1,   130,    52,    -1,
     117,   131,    -1,    38,   221,    -1,    39,   221,    -1,    40,
     221,    -1,    41,   221,    -1,    33,   202,    -1,    27,   202,
      -1,   202,   203,    -1,   203,    -1,     6,    -1,    10,    -1,
      17,    -1,    58,    -1,    85,    -1,    98,    -1,   126,    -1,
     137,   205,    -1,   205,   206,    -1,   206,    -1,     5,   222,
      -1,    29,   222,    -1,    44,   222,    -1,    47,   222,    -1,
     102,   222,    -1,   128,   222,    -1,   129,   222,    -1,   214,
      -1,    51,   131,   170,    -1,    34,    -1,    15,   222,    -1,
      18,    52,    -1,   133,   222,    -1,    31,   208,    -1,    64,
     131,    -1,   107,   131,    -1,    69,   131,    -1,    68,   212,
      -1,   105,   219,    -1,   121,   131,    -1,   123,   209,    -1,
     139,   174,    -1,   139,   174,   210,    -1,   142,   218,    -1,
     114,   131,    -1,   131,    -1,   131,    30,    -1,    -1,   131,
     164,   131,    26,    -1,   131,   164,   131,    -1,   210,   211,
      -1,   211,    -1,   109,    52,    -1,    53,   174,    -1,   212,
     213,    -1,   213,    -1,   131,    -1,   215,   217,   216,    -1,
     215,   217,   131,    -1,    53,    -1,    88,    -1,     4,    -1,
      54,    -1,    56,    -1,    67,    -1,    50,    -1,    32,    -1,
     218,    52,    -1,    52,    -1,   219,   131,    -1,   131,    -1,
     220,   173,    -1,   173,    -1,    52,    -1,   140,    -1,    35,
      -1,    52,    -1,    30,    -1,   224,   165,   225,   227,   166,
      -1,   154,    -1,   225,   226,   153,    -1,   226,   153,    -1,
     155,   164,   222,    -1,   156,   164,   222,    -1,   227,   228,
      -1,   228,    -1,   230,   165,   229,   231,   166,    -1,   157,
     164,   222,   153,    -1,   122,   164,   173,    -1,   231,   232,
      -1,   232,    -1,   158,   164,   222,   165,   233,   166,    -1,
     233,   234,   153,    -1,   234,   153,    -1,   159,   164,   222,
      -1,   160,   164,   222,    -1,   161,   164,   222,    -1,   162,
     164,   222,    -1,   163,   164,   222,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   296,   296,   300,   301,   302,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   336,
     342,   351,   352,   353,   354,   355,   359,   360,   361,   365,
     369,   370,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   397,   405,   406,
     416,   418,   420,   431,   433,   435,   440,   442,   444,   446,
     448,   453,   455,   459,   460,   464,   466,   468,   470,   472,
     474,   484,   489,   490,   494,   496,   498,   500,   502,   504,
     506,   508,   510,   512,   514,   524,   526,   535,   543,   544,
     548,   550,   552,   554,   556,   558,   560,   562,   567,   574,
     584,   594,   603,   612,   621,   622,   626,   627,   628,   629,
     630,   631,   632,   641,   645,   650,   655,   668,   681,   689,
     690,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   711,   712,   716,   717,   718,
     726,   731,   732,   736,   738,   740,   742,   744,   746,   748,
     750,   759,   761,   766,   773,   783,   784,   785,   786,   787,
     788,   789,   805,   809,   810,   814,   815,   816,   817,   818,
     819,   820,   829,   830,   846,   852,   854,   856,   858,   860,
     863,   865,   876,   878,   880,   890,   892,   894,   896,   898,
     903,   905,   909,   913,   915,   920,   922,   926,   927,   931,
     932,   936,   951,   956,   964,   965,   969,   970,   971,   975,
     976,   977,   987,   988,   992,   993,   997,   998,  1002,  1011,
    1012,  1016,  1017,  1026,  1041,  1045,  1046,  1050,  1051,  1055,
    1056,  1060,  1065,  1069,  1073,  1074,  1078,  1083,  1084,  1088,
    1090,  1092,  1094,  1096
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Age", "T_All", "T_Allan", "T_Auth",
  "T_Autokey", "T_Automax", "T_Average", "T_Bclient", "T_Beacon", "T_Bias",
  "T_Broadcast", "T_Broadcastclient", "T_Broadcastdelay", "T_Burst",
  "T_Calibrate", "T_Calldelay", "T_Ceiling", "T_Clockstats", "T_Cohort",
  "T_ControlKey", "T_Crypto", "T_Cryptostats", "T_Day", "T_Default",
  "T_Disable", "T_Discard", "T_Dispersion", "T_Double", "T_Driftfile",
  "T_Drop", "T_Enable", "T_End", "T_False", "T_File", "T_Filegen",
  "T_Flag1", "T_Flag2", "T_Flag3", "T_Flag4", "T_Flake", "T_Floor",
  "T_Freq", "T_Fudge", "T_Host", "T_Huffpuff", "T_Iburst", "T_Ident",
  "T_Ignore", "T_Includefile", "T_Integer", "T_Interface", "T_Ipv4",
  "T_Ipv4_flag", "T_Ipv6", "T_Ipv6_flag", "T_Kernel", "T_Key", "T_Keys",
  "T_Keysdir", "T_Kod", "T_Mssntp", "T_Leapfile", "T_Limited", "T_Link",
  "T_Listen", "T_Logconfig", "T_Logfile", "T_Loopstats", "T_Lowpriotrap",
  "T_Manycastclient", "T_Manycastserver", "T_Mask", "T_Maxclock",
  "T_Maxdist", "T_Maxhop", "T_Maxpoll", "T_Minclock", "T_Mindist",
  "T_Minimum", "T_Minpoll", "T_Minsane", "T_Mode", "T_Monitor", "T_Month",
  "T_Multicastclient", "T_Nic", "T_Nolink", "T_Nomodify", "T_None",
  "T_Nopeer", "T_Noquery", "T_Noselect", "T_Noserve", "T_Notrap",
  "T_Notrust", "T_Ntp", "T_Ntpport", "T_NtpSignDsocket", "T_Orphan",
  "T_Panic", "T_Peer", "T_Peerstats", "T_Phone", "T_Pid", "T_Pidfile",
  "T_Pool", "T_Port", "T_Preempt", "T_Prefer", "T_Protostats", "T_Pw",
  "T_Qos", "T_RandFile", "T_Rawstats", "T_Refid", "T_Requestkey",
  "T_Restrict", "T_Revoke", "T_Saveconfigdir", "T_Server", "T_Setvar",
  "T_Sign", "T_Statistics", "T_Stats", "T_Statsdir", "T_Step", "T_Stepout",
  "T_Stratum", "T_String", "T_Sysstats", "T_Tick", "T_Time1", "T_Time2",
  "T_Timingstats", "T_Tinker", "T_Tos", "T_Trap", "T_True", "T_Trustedkey",
  "T_Ttl", "T_Type", "T_Unconfig", "T_Unpeer", "T_Version",
  "T_WanderThreshold", "T_Week", "T_Xleave", "T_Year", "T_Flag", "T_Void",
  "T_EOC", "T_Simulate", "T_Beep_Delay", "T_Sim_Duration",
  "T_Server_Offset", "T_Duration", "T_Freq_Offset", "T_Wander", "T_Jitter",
  "T_Prop_Delay", "T_Proc_Delay", "'='", "'{'", "'}'", "$accept",
  "configuration", "command_list", "command", "server_command",
  "client_type", "address", "ip_address", "option_list", "option",
  "unpeer_command", "unpeer_keyword", "other_mode_command",
  "authentication_command", "crypto_command_line", "crypto_command_list",
  "crypto_command", "orphan_mode_command", "tos_option_list", "tos_option",
  "monitoring_command", "stats_list", "stat", "filegen_option_list",
  "filegen_option", "filegen_type", "access_control_command",
  "ac_flag_list", "access_control_flag", "discard_option_list",
  "discard_option", "fudge_command", "fudge_factor_list", "fudge_factor",
  "system_option_command", "system_option_list", "system_option",
  "tinker_command", "tinker_option_list", "tinker_option",
  "miscellaneous_command", "drift_parm", "variable_assign",
  "trap_option_list", "trap_option", "log_config_list",
  "log_config_command", "interface_command", "interface_nic",
  "nic_rule_class", "nic_rule_action", "integer_list", "string_list",
  "address_list", "boolean", "number", "simulate_command",
  "sim_conf_start", "sim_init_statement_list", "sim_init_statement",
  "sim_server_list", "sim_server", "sim_server_offset", "sim_server_name",
  "sim_act_list", "sim_act", "sim_act_stmt_list", "sim_act_stmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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
     415,   416,   417,   418,    61,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   167,   168,   169,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   171,
     171,   172,   172,   172,   172,   172,   173,   173,   173,   174,
     175,   175,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   177,   178,   178,
     179,   179,   179,   180,   180,   180,   180,   180,   180,   180,
     180,   181,   181,   182,   182,   183,   183,   183,   183,   183,
     183,   184,   185,   185,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   187,   187,   187,   188,   188,
     189,   189,   189,   189,   189,   189,   189,   189,   190,   190,
     191,   191,   191,   191,   191,   191,   192,   192,   192,   192,
     192,   192,   192,   193,   193,   193,   193,   193,   193,   194,
     194,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   196,   196,   197,   197,   197,
     198,   199,   199,   200,   200,   200,   200,   200,   200,   200,
     200,   201,   201,   202,   202,   203,   203,   203,   203,   203,
     203,   203,   204,   205,   205,   206,   206,   206,   206,   206,
     206,   206,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     208,   208,   208,   209,   209,   210,   210,   211,   211,   212,
     212,   213,   214,   214,   215,   215,   216,   216,   216,   217,
     217,   217,   218,   218,   219,   219,   220,   220,   221,   221,
     221,   222,   222,   223,   224,   225,   225,   226,   226,   227,
     227,   228,   229,   230,   231,   231,   232,   233,   233,   234,
     234,   234,   234,   234
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     1,     1,     2,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     4,     4,     5,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     2,     2,
       3,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     2,
       1,     2,     0,     4,     3,     2,     1,     2,     2,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     5,     1,     3,     2,     3,     3,     2,
       1,     5,     4,     3,     2,     1,     6,     3,     2,     3,
       3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    24,    50,     0,     0,     0,    62,     0,
       0,   192,     0,   174,     0,     0,     0,   204,     0,     0,
       0,     0,     0,    25,     0,     0,   205,     0,    23,     0,
       0,    22,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,   224,     0,
       2,     0,     7,     0,     8,     0,     9,    10,    13,    11,
      12,    14,    15,    16,    17,   172,     0,    18,     0,     5,
      53,   222,   221,   175,   176,    54,     0,     0,     0,     0,
       0,     0,    55,    61,    64,   155,   156,   157,   158,   159,
     160,   161,   152,   154,     0,     0,     0,   113,   136,   190,
     178,   151,    90,    91,    92,    93,    97,    94,    95,    96,
       0,     0,     0,    29,     0,    26,     6,    56,    57,   179,
     201,   182,   200,   181,   217,    51,    52,    60,   215,   183,
     180,   189,    58,   119,     0,     0,   119,    26,   184,     0,
     185,    85,    89,    86,   177,     0,     0,     0,     0,     0,
       0,     0,   162,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,    73,   186,   213,    59,
     188,     1,     0,     4,    20,    47,   211,   210,   209,     0,
       0,    65,    66,    67,    68,    69,    70,    63,   153,   137,
     138,   139,   135,   191,   105,   104,     0,   102,   103,     0,
      87,    99,    27,    28,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   142,   173,   199,   216,   214,   115,   119,
     119,   114,     0,     0,    88,   165,   166,   167,   168,   169,
     170,   171,   163,    83,    74,   220,   218,   219,    76,    75,
      81,    79,    84,    80,    78,    82,    77,    72,     0,     0,
     187,   196,   212,     3,    32,     0,    34,    35,     0,     0,
       0,     0,    39,    40,    41,    42,     0,     0,    43,    19,
      31,   206,   207,   208,   203,   202,     0,     0,     0,     0,
     100,   112,   108,   110,   106,   107,   109,   111,   101,    98,
     147,   148,   149,   150,   146,   145,   143,   144,   141,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   120,   116,   117,   119,   194,   198,   197,
     195,    33,    36,    38,    37,    45,    44,    46,    30,     0,
       0,     0,     0,     0,   230,     0,   226,   118,   193,   227,
     228,     0,   225,   223,   229,     0,   233,     0,     0,     0,
       0,     0,   235,     0,     0,   231,   234,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,   238,   239,   240,   241,   242,   243,
     237
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    49,    50,    51,    52,    53,   124,   115,   269,   270,
      54,    55,    56,    57,    82,    83,    84,    58,   165,   166,
      59,   141,   110,   200,   201,   288,    60,   218,   313,    97,
      98,    61,   212,   213,    62,    92,    93,    63,   152,   153,
      64,   100,   140,   250,   251,   121,   122,    65,    66,   275,
     179,   169,   129,   125,   238,    73,    67,    68,   278,   279,
     333,   334,   348,   335,   351,   352,   365,   366
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
     123,  -130,   -22,  -136,  -136,   -10,   -21,   -15,    49,     2,
       5,   -91,     2,  -136,   143,    -8,   -88,  -136,   -86,   -79,
     -73,   -67,   -58,  -136,    -8,    -8,  -136,   -56,  -136,   -55,
     -43,  -136,   -42,     4,   -19,   -35,  -136,   -34,   143,   -17,
     -10,    30,   292,     3,    31,    31,  -136,  -136,  -136,    50,
     273,   -54,  -136,    -8,  -136,    -8,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   -16,  -136,   -26,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,     9,    11,    12,    13,
      81,    16,  -136,    49,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,     2,  -136,    96,    97,   100,     5,  -136,   125,
    -136,     2,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
     -18,    22,    34,  -136,    63,  -136,   415,  -136,  -136,  -136,
    -136,   -67,  -136,  -136,  -136,    -8,    -8,  -136,  -136,    35,
    -136,  -136,  -136,  -136,    -5,    -2,  -136,    87,  -136,     8,
    -136,   143,  -136,  -136,  -136,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,    30,  -136,   126,   130,   -13,   133,   -10,   -10,
     134,   -10,   -10,   136,   137,   292,  -136,   -48,  -136,   142,
     142,  -136,    46,  -136,   457,  -136,  -136,  -136,  -136,    -1,
    -128,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,    44,  -136,  -136,    29,
     -18,  -136,  -136,  -136,   -13,   -13,   -13,   -13,    69,   149,
     -10,   -10,    63,  -136,  -136,  -136,  -136,  -136,   520,  -136,
    -136,   520,     3,    71,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,     3,   151,
     -48,  -136,  -136,  -136,  -136,   -10,  -136,  -136,   152,   153,
     154,   155,  -136,  -136,  -136,  -136,   156,   157,  -136,   457,
    -136,  -136,  -136,  -136,  -136,  -136,    48,    53,   -93,    61,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,   520,   520,  -136,   192,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   -10,
     -10,    55,    67,  -109,  -136,    56,  -136,   520,  -136,  -136,
    -136,    -8,  -136,  -136,  -136,    65,  -136,    60,    74,   -10,
      70,  -125,  -136,    72,   -10,  -136,  -136,  -136,    62,   -81,
      75,    76,    79,    85,    88,   -94,    80,   -10,   -10,   -10,
     -10,   -10,  -136,    82,  -136,  -136,  -136,  -136,  -136,  -136,
    -136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   -46,  -136,  -136,    -9,   -32,  -136,   -33,
    -136,  -136,  -136,  -136,  -136,  -136,   146,  -136,  -136,    73,
    -136,  -136,   -28,  -136,    51,  -136,  -136,  -135,  -136,  -136,
     160,  -136,  -136,    41,  -136,   242,   -75,  -136,  -136,   106,
    -136,  -136,  -136,  -136,    19,  -136,   145,  -136,  -136,  -136,
    -136,   218,  -136,   245,  -113,   -40,  -136,  -136,  -136,    -7,
    -136,   -61,  -136,  -136,  -136,   -78,  -136,   -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -7
static const yytype_int16 yytable[] =
{
     144,   221,   137,   271,   172,   248,   114,   133,    85,   194,
     142,   167,    86,   331,    94,   195,   176,   188,   196,    87,
      71,   219,   235,    69,   220,   136,   188,   276,   277,   331,
      70,    74,   281,   350,   177,   145,   134,    75,   135,   236,
      99,   355,    72,   116,   174,   117,   175,   111,   197,   112,
     171,   178,   118,   272,   282,   273,   132,   343,   119,   146,
      88,   249,   276,   277,   120,   360,   361,   362,   363,   364,
     214,   198,   372,   123,   147,   127,   128,   148,   360,   361,
     362,   363,   364,   168,   314,   315,    95,    89,   130,   131,
      96,   290,   291,   292,   293,    76,   138,   139,    77,   173,
      90,   204,   205,   206,   207,   225,   226,   227,   228,   229,
     230,   231,   113,   224,   143,   283,   216,   216,   240,   241,
     284,   243,   244,   113,     1,   199,   202,   237,    91,   203,
     274,     2,   149,   185,   113,   285,     3,     4,     5,   180,
     181,     6,   182,   183,   184,     7,     8,   186,   189,   190,
       9,    10,   191,   202,    11,   193,    12,    13,   150,   151,
      14,   222,    78,   102,    79,   203,   217,   103,    15,    80,
     296,   297,   223,    81,    16,   280,    17,   286,   233,   287,
     208,   337,   234,    18,    19,   239,   242,    20,   245,   246,
     316,    21,    22,   209,   252,    23,    24,   210,   211,   253,
     294,   295,   317,   319,   322,   323,   324,   325,   326,   327,
      25,    26,   329,   104,   336,   321,   318,   330,   338,   341,
     342,   345,   347,    27,   349,   357,    28,   359,    29,   187,
      30,    31,   350,   374,   354,   380,   328,    32,   247,   367,
     368,    33,    34,   369,    35,    36,    37,   105,    38,   370,
      39,   289,   371,   298,   101,   106,    40,   192,   232,   107,
      41,    42,    43,   170,    44,    45,   215,    46,    47,   320,
     126,   332,   344,   356,     0,   108,    -6,    48,   373,   109,
       0,     2,     0,     0,     0,     0,     3,     4,     5,   339,
     340,     6,     0,     0,     0,     7,     8,     0,     0,     0,
       9,    10,     0,   154,    11,     0,    12,    13,     0,   353,
      14,   155,     0,   156,   358,     0,     0,     0,    15,     0,
       0,     0,     0,     0,    16,     0,    17,   375,   376,   377,
     378,   379,   346,    18,    19,   157,     0,    20,     0,     0,
       0,    21,    22,     0,     0,    23,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,     0,   158,   159,   160,
       0,   161,   162,    27,     0,   163,    28,     0,    29,     0,
      30,    31,     0,     0,     0,     0,     0,    32,     0,     0,
       0,    33,    34,   164,    35,    36,    37,     0,    38,     0,
      39,     0,     0,     0,     0,     0,    40,     0,     0,     0,
      41,    42,    43,     0,    44,    45,     0,    46,    47,     0,
       0,     0,     0,     2,     0,     0,    -6,    48,     3,     4,
       5,     0,     0,     6,     0,     0,     0,     7,     8,     0,
       0,     0,     9,    10,     0,     0,    11,     0,    12,    13,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,   254,     0,    16,     0,    17,   255,
       0,     0,     0,   256,     0,    18,    19,     0,     0,    20,
       0,     0,     0,    21,    22,     0,     0,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,   258,     0,    28,     0,
      29,     0,    30,    31,     0,     0,     0,     0,     0,    32,
       0,     0,     0,    33,    34,   259,    35,    36,    37,   260,
      38,   261,    39,     0,     0,     0,     0,     0,    40,     0,
       0,   262,    41,    42,    43,     0,    44,    45,     0,    46,
      47,     0,   299,     0,     0,     0,     0,   263,   264,    48,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   301,   302,     0,   303,     0,     0,     0,     0,
       0,   304,     0,     0,     0,     0,     0,   265,     0,   266,
       0,     0,     0,   267,     0,     0,   268,     0,     0,     0,
     305,     0,   306,   307,     0,   308,   309,   310,     0,   311,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   312
};

static const yytype_int16 yycheck[] =
{
      40,   136,    34,     4,    50,    53,    15,    26,     6,    27,
      38,    43,    10,   122,     9,    33,    32,    92,    36,    17,
      30,    26,    35,   153,    26,    34,   101,   155,   156,   122,
      52,    52,     3,   158,    50,     5,    55,    52,    57,    52,
     131,   166,    52,   131,    53,   131,    55,    55,    66,    57,
       0,    67,   131,    54,    25,    56,    52,   166,   131,    29,
      58,   109,   155,   156,   131,   159,   160,   161,   162,   163,
     116,    89,   166,   131,    44,   131,   131,    47,   159,   160,
     161,   162,   163,    52,   219,   220,    81,    85,   131,   131,
      85,   204,   205,   206,   207,    46,   131,   131,    49,   153,
      98,    38,    39,    40,    41,   145,   146,   147,   148,   149,
     150,   151,   131,   141,   131,    86,   125,   126,   158,   159,
      91,   161,   162,   131,     1,   143,   131,   140,   126,   131,
     131,     8,   102,    52,   131,   106,    13,    14,    15,   165,
     131,    18,   131,   131,   131,    22,    23,   131,    52,    52,
      27,    28,    52,   131,    31,    30,    33,    34,   128,   129,
      37,    74,   113,    20,   115,   131,   131,    24,    45,   120,
     210,   211,   164,   124,    51,   131,    53,   148,    52,   150,
     117,   316,    52,    60,    61,    52,    52,    64,    52,    52,
     222,    68,    69,   130,    52,    72,    73,   134,   135,   153,
     131,    52,   131,    52,    52,    52,    52,    52,    52,    52,
      87,    88,   164,    70,   153,   255,   248,   164,    26,   164,
     153,   165,   157,   100,   164,   153,   103,   165,   105,    83,
     107,   108,   158,   153,   164,   153,   269,   114,   165,   164,
     164,   118,   119,   164,   121,   122,   123,   104,   125,   164,
     127,   200,   164,   212,    12,   112,   133,    97,   152,   116,
     137,   138,   139,    45,   141,   142,   121,   144,   145,   250,
      25,   278,   333,   351,    -1,   132,   153,   154,   365,   136,
      -1,     8,    -1,    -1,    -1,    -1,    13,    14,    15,   329,
     330,    18,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,
      27,    28,    -1,    11,    31,    -1,    33,    34,    -1,   349,
      37,    19,    -1,    21,   354,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,   367,   368,   369,
     370,   371,   341,    60,    61,    43,    -1,    64,    -1,    -1,
      -1,    68,    69,    -1,    -1,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    79,    80,   100,    -1,    83,   103,    -1,   105,    -1,
     107,   108,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,   118,   119,   101,   121,   122,   123,    -1,   125,    -1,
     127,    -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,   142,    -1,   144,   145,    -1,
      -1,    -1,    -1,     8,    -1,    -1,   153,   154,    13,    14,
      15,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    27,    28,    -1,    -1,    31,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,     7,    -1,    51,    -1,    53,    12,
      -1,    -1,    -1,    16,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    69,    -1,    -1,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    59,    -1,   103,    -1,
     105,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,   118,   119,    78,   121,   122,   123,    82,
     125,    84,   127,    -1,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    94,   137,   138,   139,    -1,   141,   142,    -1,   144,
     145,    -1,    42,    -1,    -1,    -1,    -1,   110,   111,   154,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,   140,    -1,   142,
      -1,    -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    -1,
      90,    -1,    92,    93,    -1,    95,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     8,    13,    14,    15,    18,    22,    23,    27,
      28,    31,    33,    34,    37,    45,    51,    53,    60,    61,
      64,    68,    69,    72,    73,    87,    88,   100,   103,   105,
     107,   108,   114,   118,   119,   121,   122,   123,   125,   127,
     133,   137,   138,   139,   141,   142,   144,   145,   154,   168,
     169,   170,   171,   172,   177,   178,   179,   180,   184,   187,
     193,   198,   201,   204,   207,   214,   215,   223,   224,   153,
      52,    30,    52,   222,    52,    52,    46,    49,   113,   115,
     120,   124,   181,   182,   183,     6,    10,    17,    58,    85,
      98,   126,   202,   203,     9,    81,    85,   196,   197,   131,
     208,   202,    20,    24,    70,   104,   112,   116,   132,   136,
     189,    55,    57,   131,   173,   174,   131,   131,   131,   131,
     131,   212,   213,   131,   173,   220,   220,   131,   131,   219,
     131,   131,    52,    26,    55,    57,   173,   174,   131,   131,
     209,   188,   189,   131,   222,     5,    29,    44,    47,   102,
     128,   129,   205,   206,    11,    19,    21,    43,    75,    76,
      77,    79,    80,    83,   101,   185,   186,   174,    52,   218,
     218,     0,   170,   153,   173,   173,    32,    50,    67,   217,
     165,   131,   131,   131,   131,    52,   131,   183,   203,    52,
      52,    52,   197,    30,    27,    33,    36,    66,    89,   143,
     190,   191,   131,   131,    38,    39,    40,    41,   117,   130,
     134,   135,   199,   200,   170,   213,   173,   131,   194,    26,
      26,   194,    74,   164,   189,   222,   222,   222,   222,   222,
     222,   222,   206,    52,    52,    35,    52,   140,   221,    52,
     222,   222,    52,   222,   222,    52,    52,   186,    53,   109,
     210,   211,    52,   153,     7,    12,    16,    48,    59,    78,
      82,    84,    94,   110,   111,   140,   142,   146,   149,   175,
     176,     4,    54,    56,   131,   216,   155,   156,   225,   226,
     131,     3,    25,    86,    91,   106,   148,   150,   192,   191,
     221,   221,   221,   221,   131,    52,   222,   222,   200,    42,
      50,    62,    63,    65,    71,    90,    92,    93,    95,    96,
      97,    99,   146,   195,   194,   194,   174,   131,   174,    52,
     211,   222,    52,    52,    52,    52,    52,    52,   176,   164,
     164,   122,   226,   227,   228,   230,   153,   194,    26,   222,
     222,   164,   153,   166,   228,   165,   173,   157,   229,   164,
     158,   231,   232,   222,   164,   166,   232,   153,   222,   165,
     159,   160,   161,   162,   163,   233,   234,   164,   164,   164,
     164,   164,   166,   234,   153,   222,   222,   222,   222,   222,
     153
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 303 "ntp_parser.y"
    {
			/* I will need to incorporate much more fine grained
			 * error messages. The following should suffice for
			 * the time being.
			 */
			msyslog(LOG_ERR, 
				"syntax error in %s line %d, column %d",
				ip_file->fname,
				ip_file->err_line_no,
				ip_file->err_col_no);
		}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 337 "ntp_parser.y"
    {
			struct peer_node *my_node =  create_peer_node((yyvsp[(1) - (3)].Integer), (yyvsp[(2) - (3)].Address_node), (yyvsp[(3) - (3)].Queue));
			if (my_node)
				enqueue(cfgt.peers, my_node);
		}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 343 "ntp_parser.y"
    {
			struct peer_node *my_node = create_peer_node((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Address_node), NULL);
			if (my_node)
				enqueue(cfgt.peers, my_node);
		}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 360 "ntp_parser.y"
    { (yyval.Address_node) = create_address_node((yyvsp[(2) - (2)].String), AF_INET); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 361 "ntp_parser.y"
    { (yyval.Address_node) = create_address_node((yyvsp[(2) - (2)].String), AF_INET6); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 365 "ntp_parser.y"
    { (yyval.Address_node) = create_address_node((yyvsp[(1) - (1)].String), 0); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 369 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val)); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 370 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val)); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 374 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, FLAG_SKEY); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 375 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Double)); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 376 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, FLAG_BURST); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 377 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, FLAG_IBURST); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 378 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 379 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 380 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 381 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, FLAG_NOSELECT); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 382 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, FLAG_PREEMPT); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 383 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, FLAG_PREFER); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 384 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, FLAG_TRUE); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 385 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, FLAG_XLEAVE); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 386 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 387 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 388 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 398 "ntp_parser.y"
    {
			struct unpeer_node *my_node = create_unpeer_node((yyvsp[(2) - (2)].Address_node));
			if (my_node)
				enqueue(cfgt.unpeers, my_node);
		}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 417 "ntp_parser.y"
    { cfgt.broadcastclient = 1; }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 419 "ntp_parser.y"
    { append_queue(cfgt.manycastserver, (yyvsp[(2) - (2)].Queue)); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 421 "ntp_parser.y"
    { append_queue(cfgt.multicastclient, (yyvsp[(2) - (2)].Queue)); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 432 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer))); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 434 "ntp_parser.y"
    { cfgt.auth.control_key = (yyvsp[(2) - (2)].Integer); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 436 "ntp_parser.y"
    { 
			cryptosw++;
			append_queue(cfgt.auth.crypto_cmd_list, (yyvsp[(2) - (2)].Queue));
		}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 441 "ntp_parser.y"
    { cfgt.auth.keys = (yyvsp[(2) - (2)].String); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 443 "ntp_parser.y"
    { cfgt.auth.keysdir = (yyvsp[(2) - (2)].String); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 445 "ntp_parser.y"
    { cfgt.auth.request_key = (yyvsp[(2) - (2)].Integer); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 447 "ntp_parser.y"
    { cfgt.auth.trusted_key_list = (yyvsp[(2) - (2)].Queue); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 449 "ntp_parser.y"
    { cfgt.auth.ntp_signd_socket = (yyvsp[(2) - (2)].String); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 455 "ntp_parser.y"
    { (yyval.Queue) = create_queue(); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 459 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val)); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 460 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val)); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 465 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_sval(CRYPTO_CONF_PRIV, (yyvsp[(2) - (2)].String)); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 467 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_sval(CRYPTO_CONF_IDENT, (yyvsp[(2) - (2)].String)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 469 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_sval(CRYPTO_CONF_PW, (yyvsp[(2) - (2)].String)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 471 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_sval(CRYPTO_CONF_RAND, (yyvsp[(2) - (2)].String)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 473 "ntp_parser.y"
    { cfgt.auth.revoke = (yyvsp[(2) - (2)].Integer); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 475 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_sval(CRYPTO_CONF_SIGN, (yyvsp[(2) - (2)].String)); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 485 "ntp_parser.y"
    { append_queue(cfgt.orphan_cmds,(yyvsp[(2) - (2)].Queue)); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 489 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val)); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 490 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val)); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 495 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_CEILING, (double)(yyvsp[(2) - (2)].Integer)); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 497 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_FLOOR, (double)(yyvsp[(2) - (2)].Integer)); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 499 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_COHORT, (double)(yyvsp[(2) - (2)].Integer)); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 501 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_ORPHAN, (double)(yyvsp[(2) - (2)].Integer)); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 503 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_MINDISP, (yyvsp[(2) - (2)].Double)); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 505 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_MAXDIST, (yyvsp[(2) - (2)].Double)); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 507 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_MINCLOCK, (yyvsp[(2) - (2)].Double)); }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 509 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_MAXCLOCK, (yyvsp[(2) - (2)].Double)); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 511 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_MINSANE, (double)(yyvsp[(2) - (2)].Integer)); }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 513 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_BEACON, (double)(yyvsp[(2) - (2)].Integer)); }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 515 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(PROTO_MAXHOP, (double)(yyvsp[(2) - (2)].Integer)); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 525 "ntp_parser.y"
    { append_queue(cfgt.stats_list, (yyvsp[(2) - (2)].Queue)); }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 527 "ntp_parser.y"
    {
			if (input_from_file)
				cfgt.stats_dir = (yyvsp[(2) - (2)].String);
			else {
				free((yyvsp[(2) - (2)].String));
				yyerror("statsdir remote configuration ignored");
			}
		}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 536 "ntp_parser.y"
    {
			enqueue(cfgt.filegen_opts,
				create_filegen_node((yyvsp[(2) - (3)].VoidPtr), (yyvsp[(3) - (3)].Queue)));
		}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 543 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].VoidPtr)); }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 544 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].VoidPtr)); }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 549 "ntp_parser.y"
    { (yyval.VoidPtr) = create_pval("clockstats"); }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 551 "ntp_parser.y"
    { (yyval.VoidPtr) = create_pval("cryptostats"); }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 553 "ntp_parser.y"
    { (yyval.VoidPtr) = create_pval("loopstats"); }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 555 "ntp_parser.y"
    { (yyval.VoidPtr) = create_pval("peerstats"); }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 557 "ntp_parser.y"
    { (yyval.VoidPtr) = create_pval("rawstats"); }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 559 "ntp_parser.y"
    { (yyval.VoidPtr) = create_pval("sysstats"); }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 561 "ntp_parser.y"
    { (yyval.VoidPtr) = create_pval("timingstats"); }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 563 "ntp_parser.y"
    { (yyval.VoidPtr) = create_pval("protostats"); }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 568 "ntp_parser.y"
    {
			if ((yyvsp[(2) - (2)].Attr_val) != NULL)
				(yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val));
			else
				(yyval.Queue) = (yyvsp[(1) - (2)].Queue);
		}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 575 "ntp_parser.y"
    {
			if ((yyvsp[(1) - (1)].Attr_val) != NULL)
				(yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val));
			else
				(yyval.Queue) = create_queue();
		}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 585 "ntp_parser.y"
    {
			if (input_from_file)
				(yyval.Attr_val) = create_attr_sval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].String));
			else {
				(yyval.Attr_val) = NULL;
				free((yyvsp[(2) - (2)].String));
				yyerror("filegen file remote configuration ignored");
			}
		}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 595 "ntp_parser.y"
    {
			if (input_from_file)
				(yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer));
			else {
				(yyval.Attr_val) = NULL;
				yyerror("filegen type remote configuration ignored");
			}
		}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 604 "ntp_parser.y"
    {
			if (input_from_file)
				(yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer));
			else {
				(yyval.Attr_val) = NULL;
				yyerror("filegen link remote configuration ignored");
			}
		}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 613 "ntp_parser.y"
    {
			if (input_from_file)
				(yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer));
			else {
				(yyval.Attr_val) = NULL;
				yyerror("filegen nolink remote configuration ignored");
			}
		}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 621 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer)); }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 622 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer)); }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 626 "ntp_parser.y"
    { (yyval.Integer) = FILEGEN_NONE; }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 627 "ntp_parser.y"
    { (yyval.Integer) = FILEGEN_PID; }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 628 "ntp_parser.y"
    { (yyval.Integer) = FILEGEN_DAY; }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 629 "ntp_parser.y"
    { (yyval.Integer) = FILEGEN_WEEK; }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 630 "ntp_parser.y"
    { (yyval.Integer) = FILEGEN_MONTH; }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 631 "ntp_parser.y"
    { (yyval.Integer) = FILEGEN_YEAR; }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 632 "ntp_parser.y"
    { (yyval.Integer) = FILEGEN_AGE; }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 642 "ntp_parser.y"
    {   
			append_queue(cfgt.discard_opts, (yyvsp[(2) - (2)].Queue));
		}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 646 "ntp_parser.y"
    {
			enqueue(cfgt.restrict_opts,
				create_restrict_node((yyvsp[(2) - (3)].Address_node), NULL, (yyvsp[(3) - (3)].Queue), ip_file->line_no));
		}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 651 "ntp_parser.y"
    {
			enqueue(cfgt.restrict_opts,
				create_restrict_node(NULL, NULL, (yyvsp[(3) - (3)].Queue), ip_file->line_no));
		}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 656 "ntp_parser.y"
    {
			enqueue(cfgt.restrict_opts,
				create_restrict_node(
					create_address_node(
						estrdup("0.0.0.0"), 
						AF_INET),
					create_address_node(
						estrdup("255.255.255.255"), 
						AF_INET),
					(yyvsp[(4) - (4)].Queue), 
					ip_file->line_no));
		}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 669 "ntp_parser.y"
    {
			enqueue(cfgt.restrict_opts,
				create_restrict_node(
					create_address_node(
						estrdup("::"), 
						AF_INET6),
					create_address_node(
						estrdup("ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff"),
						AF_INET6),
					(yyvsp[(4) - (4)].Queue), 
					ip_file->line_no));
		}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 682 "ntp_parser.y"
    {
			enqueue(cfgt.restrict_opts,
				create_restrict_node((yyvsp[(2) - (5)].Address_node), (yyvsp[(4) - (5)].Address_node), (yyvsp[(5) - (5)].Queue), ip_file->line_no));
		}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 689 "ntp_parser.y"
    { (yyval.Queue) = create_queue(); }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 690 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].VoidPtr)); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 694 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_TIMEOUT); }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 695 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_IGNORE); }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 696 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_KOD); }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 697 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_MSSNTP); }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 698 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_LIMITED); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 699 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_LPTRAP); }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 700 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_NOMODIFY); }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 701 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_NOPEER); }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 702 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_NOQUERY); }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 703 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_DONTSERVE); }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 704 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_NOTRAP); }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 705 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_DONTTRUST); }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 706 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RESM_NTPONLY); }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 707 "ntp_parser.y"
    { (yyval.VoidPtr) = create_ival(RES_VERSION); }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 711 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val)); }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 712 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val)); }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 716 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 717 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 718 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 727 "ntp_parser.y"
    { enqueue(cfgt.fudge, create_addr_opts_node((yyvsp[(2) - (3)].Address_node), (yyvsp[(3) - (3)].Queue))); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 731 "ntp_parser.y"
    { enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val)); }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 732 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val)); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 737 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(CLK_HAVETIME1, (yyvsp[(2) - (2)].Double)); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 739 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(CLK_HAVETIME2, (yyvsp[(2) - (2)].Double)); }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 741 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(CLK_HAVEVAL1,  (yyvsp[(2) - (2)].Integer)); }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 743 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_sval(CLK_HAVEVAL2,  (yyvsp[(2) - (2)].String)); }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 745 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(CLK_HAVEFLAG1, (yyvsp[(2) - (2)].Integer)); }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 747 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(CLK_HAVEFLAG2, (yyvsp[(2) - (2)].Integer)); }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 749 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(CLK_HAVEFLAG3, (yyvsp[(2) - (2)].Integer)); }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 751 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(CLK_HAVEFLAG4, (yyvsp[(2) - (2)].Integer)); }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 760 "ntp_parser.y"
    { append_queue(cfgt.enable_opts, (yyvsp[(2) - (2)].Queue));  }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 762 "ntp_parser.y"
    { append_queue(cfgt.disable_opts, (yyvsp[(2) - (2)].Queue));  }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 767 "ntp_parser.y"
    {
			if ((yyvsp[(2) - (2)].Attr_val) != NULL)
				(yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val));
			else
				(yyval.Queue) = (yyvsp[(1) - (2)].Queue);
		}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 774 "ntp_parser.y"
    {
			if ((yyvsp[(1) - (1)].Attr_val) != NULL)
				(yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val));
			else
				(yyval.Queue) = create_queue();
		}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 783 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer)); }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 784 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer)); }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 785 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer)); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 786 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer)); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 787 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer)); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 788 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer)); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 790 "ntp_parser.y"
    { 
			if (input_from_file)
				(yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[(1) - (1)].Integer));
			else {
				(yyval.Attr_val) = NULL;
				yyerror("enable/disable stats remote configuration ignored");
			}
		}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 805 "ntp_parser.y"
    { append_queue(cfgt.tinker, (yyvsp[(2) - (2)].Queue)); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 809 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val)); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 810 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val)); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 814 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(LOOP_ALLAN, (yyvsp[(2) - (2)].Double)); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 815 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(LOOP_PHI, (yyvsp[(2) - (2)].Double)); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 816 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(LOOP_FREQ, (yyvsp[(2) - (2)].Double)); }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 817 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(LOOP_HUFFPUFF, (yyvsp[(2) - (2)].Double)); }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 818 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(LOOP_PANIC, (yyvsp[(2) - (2)].Double)); }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 819 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(LOOP_MAX, (yyvsp[(2) - (2)].Double)); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 820 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval(LOOP_MINSTEP, (yyvsp[(2) - (2)].Double)); }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 831 "ntp_parser.y"
    {
			if (curr_include_level >= MAXINCLUDELEVEL) {
				fprintf(stderr, "getconfig: Maximum include file level exceeded.\n");
				msyslog(LOG_ERR, "getconfig: Maximum include file level exceeded.");
			}
			else {
				fp[curr_include_level + 1] = F_OPEN(FindConfig((yyvsp[(2) - (3)].String)), "r");
				if (fp[curr_include_level + 1] == NULL) {
					fprintf(stderr, "getconfig: Couldn't open <%s>\n", FindConfig((yyvsp[(2) - (3)].String)));
					msyslog(LOG_ERR, "getconfig: Couldn't open <%s>", FindConfig((yyvsp[(2) - (3)].String)));
				}
				else
					ip_file = fp[++curr_include_level];
			}
		}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 847 "ntp_parser.y"
    {
			while (curr_include_level != -1)
				FCLOSE(fp[curr_include_level--]);
		}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 853 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_dval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Double))); }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 855 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer))); }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 857 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_dval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Double))); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 859 "ntp_parser.y"
    { /* Null action, possibly all null parms */ }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 861 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_sval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].String))); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 864 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_sval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].String))); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 866 "ntp_parser.y"
    {
			if (input_from_file)
				enqueue(cfgt.vars,
					create_attr_sval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].String)));
			else {
				free((yyvsp[(2) - (2)].String));
				yyerror("logfile remote configuration ignored");
			}
		}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 877 "ntp_parser.y"
    { append_queue(cfgt.logconfig, (yyvsp[(2) - (2)].Queue)); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 879 "ntp_parser.y"
    { append_queue(cfgt.phone, (yyvsp[(2) - (2)].Queue)); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 881 "ntp_parser.y"
    {
			if (input_from_file)
				enqueue(cfgt.vars,
					create_attr_sval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].String)));
			else {
				free((yyvsp[(2) - (2)].String));
				yyerror("saveconfigdir remote configuration ignored");
			}
		}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 891 "ntp_parser.y"
    { enqueue(cfgt.setvar, (yyvsp[(2) - (2)].Set_var)); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 893 "ntp_parser.y"
    { enqueue(cfgt.trap, create_addr_opts_node((yyvsp[(2) - (2)].Address_node), NULL)); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 895 "ntp_parser.y"
    { enqueue(cfgt.trap, create_addr_opts_node((yyvsp[(2) - (3)].Address_node), (yyvsp[(3) - (3)].Queue))); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 897 "ntp_parser.y"
    { append_queue(cfgt.ttl, (yyvsp[(2) - (2)].Queue)); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 899 "ntp_parser.y"
    { enqueue(cfgt.qos, create_attr_sval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].String))); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 904 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_sval(T_Driftfile, (yyvsp[(1) - (1)].String))); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 906 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_dval(T_WanderThreshold, (yyvsp[(2) - (2)].Double)));
			  enqueue(cfgt.vars, create_attr_sval(T_Driftfile, (yyvsp[(1) - (2)].String))); }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 909 "ntp_parser.y"
    { enqueue(cfgt.vars, create_attr_sval(T_Driftfile, "\0")); }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 914 "ntp_parser.y"
    { (yyval.Set_var) = create_setvar_node((yyvsp[(1) - (4)].String), (yyvsp[(3) - (4)].String), DEF); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 916 "ntp_parser.y"
    { (yyval.Set_var) = create_setvar_node((yyvsp[(1) - (3)].String), (yyvsp[(3) - (3)].String), 0); }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 921 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val)); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 922 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val)); }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 926 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_ival((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Integer)); }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 927 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_pval((yyvsp[(1) - (2)].Integer), (yyvsp[(2) - (2)].Address_node)); }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 931 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Attr_val)); }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 932 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Attr_val)); }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 937 "ntp_parser.y"
    {
			char prefix = (yyvsp[(1) - (1)].String)[0];
			char *type = (yyvsp[(1) - (1)].String) + 1;
			
			if (prefix != '+' && prefix != '-' && prefix != '=') {
				yyerror("Logconfig prefix is not '+', '-' or '='\n");
			}
			else
				(yyval.Attr_val) = create_attr_sval(prefix, estrdup(type));
			YYFREE((yyvsp[(1) - (1)].String));
		}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 952 "ntp_parser.y"
    {
			enqueue(cfgt.nic_rules,
				create_nic_rule_node((yyvsp[(3) - (3)].Integer), NULL, (yyvsp[(2) - (3)].Integer)));
		}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 957 "ntp_parser.y"
    {
			enqueue(cfgt.nic_rules,
				create_nic_rule_node(0, (yyvsp[(3) - (3)].String), (yyvsp[(2) - (3)].Integer)));
		}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 987 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), create_ival((yyvsp[(2) - (2)].Integer))); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 988 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue(create_ival((yyvsp[(1) - (1)].Integer))); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 992 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), create_pval((yyvsp[(2) - (2)].String))); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 993 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue(create_pval((yyvsp[(1) - (1)].String))); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 997 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Address_node)); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 998 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Address_node)); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1003 "ntp_parser.y"
    {
			if ((yyvsp[(1) - (1)].Integer) != 0 && (yyvsp[(1) - (1)].Integer) != 1) {
				yyerror("Integer value is not boolean (0 or 1). Assuming 1");
				(yyval.Integer) = 1;
			}
			else
				(yyval.Integer) = (yyvsp[(1) - (1)].Integer);
		}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1011 "ntp_parser.y"
    { (yyval.Integer) = 1; }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1012 "ntp_parser.y"
    { (yyval.Integer) = 0; }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1016 "ntp_parser.y"
    { (yyval.Double) = (double)(yyvsp[(1) - (1)].Integer); }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1027 "ntp_parser.y"
    {
			cfgt.sim_details = create_sim_node((yyvsp[(3) - (5)].Queue), (yyvsp[(4) - (5)].Queue));

			/* Reset the old_config_style variable */
			old_config_style = 1;
		}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1041 "ntp_parser.y"
    { old_config_style = 0; }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1045 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (3)].Queue), (yyvsp[(2) - (3)].Attr_val)); }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1046 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (2)].Attr_val)); }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1050 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval((yyvsp[(1) - (3)].Integer), (yyvsp[(3) - (3)].Double)); }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1051 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval((yyvsp[(1) - (3)].Integer), (yyvsp[(3) - (3)].Double)); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1055 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Sim_server)); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1056 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Sim_server)); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1061 "ntp_parser.y"
    { (yyval.Sim_server) = create_sim_server((yyvsp[(1) - (5)].Address_node), (yyvsp[(3) - (5)].Double), (yyvsp[(4) - (5)].Queue)); }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1065 "ntp_parser.y"
    { (yyval.Double) = (yyvsp[(3) - (4)].Double); }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1069 "ntp_parser.y"
    { (yyval.Address_node) = (yyvsp[(3) - (3)].Address_node); }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1073 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (2)].Queue), (yyvsp[(2) - (2)].Sim_script)); }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1074 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (1)].Sim_script)); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1079 "ntp_parser.y"
    { (yyval.Sim_script) = create_sim_script_info((yyvsp[(3) - (6)].Double), (yyvsp[(5) - (6)].Queue)); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1083 "ntp_parser.y"
    { (yyval.Queue) = enqueue((yyvsp[(1) - (3)].Queue), (yyvsp[(2) - (3)].Attr_val)); }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1084 "ntp_parser.y"
    { (yyval.Queue) = enqueue_in_new_queue((yyvsp[(1) - (2)].Attr_val)); }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1089 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval((yyvsp[(1) - (3)].Integer), (yyvsp[(3) - (3)].Double)); }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1091 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval((yyvsp[(1) - (3)].Integer), (yyvsp[(3) - (3)].Double)); }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1093 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval((yyvsp[(1) - (3)].Integer), (yyvsp[(3) - (3)].Double)); }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1095 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval((yyvsp[(1) - (3)].Integer), (yyvsp[(3) - (3)].Double)); }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1097 "ntp_parser.y"
    { (yyval.Attr_val) = create_attr_dval((yyvsp[(1) - (3)].Integer), (yyvsp[(3) - (3)].Double)); }
    break;



/* Line 1455 of yacc.c  */
#line 3810 "ntp_parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1101 "ntp_parser.y"


void yyerror (char *msg)
{
	int retval;

	ip_file->err_line_no = ip_file->prev_token_line_no;
	ip_file->err_col_no = ip_file->prev_token_col_no;
	
	msyslog(LOG_ERR, 
		"line %d column %d %s", 
		ip_file->err_line_no,
		ip_file->err_col_no,
		msg);
	if (!input_from_file) {
		/* Save the error message in the correct buffer */
		retval = snprintf(remote_config.err_msg + remote_config.err_pos,
				  MAXLINE - remote_config.err_pos,
				  "column %d %s",
				  ip_file->err_col_no, msg);

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


/* Initial Testing function -- ignore
int main(int argc, char *argv[])
{
	ip_file = FOPEN(argv[1], "r");
	if (!ip_file) {
		fprintf(stderr, "ERROR!! Could not open file: %s\n", argv[1]);
	}
	key_scanner = create_keyword_scanner(keyword_list);
	print_keyword_scanner(key_scanner, 0);
	yyparse();
	return 0;
}
*/


