/* A Bison parser, made from /backroom/ntp-dev/A.whimsy/ntpd/../../ntpd/ntp_parser.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	T_Age	257
# define	T_Allan	258
# define	T_Auth	259
# define	T_Autokey	260
# define	T_Automax	261
# define	T_Average	262
# define	T_Bclient	263
# define	T_Beacon	264
# define	T_Broadcast	265
# define	T_Broadcastclient	266
# define	T_Broadcastdelay	267
# define	T_Burst	268
# define	T_Calibrate	269
# define	T_Calldelay	270
# define	T_Ceiling	271
# define	T_Cert	272
# define	T_Clockstats	273
# define	T_Cohort	274
# define	T_ControlKey	275
# define	T_Crypto	276
# define	T_Cryptostats	277
# define	T_Day	278
# define	T_Default	279
# define	T_Disable	280
# define	T_Discard	281
# define	T_Dispersion	282
# define	T_Double	283
# define	T_Driftfile	284
# define	T_DriftMinutes	285
# define	T_Enable	286
# define	T_End	287
# define	T_False	288
# define	T_File	289
# define	T_Filegen	290
# define	T_Flag1	291
# define	T_Flag2	292
# define	T_Flag3	293
# define	T_Flag4	294
# define	T_Floor	295
# define	T_Freq	296
# define	T_Fudge	297
# define	T_Gqpar	298
# define	T_Host	299
# define	T_Huffpuff	300
# define	T_IPv4_address	301
# define	T_IPv6_address	302
# define	T_Iburst	303
# define	T_Ident	304
# define	T_Iffpar	305
# define	T_Ignore	306
# define	T_Includefile	307
# define	T_Integer	308
# define	T_Interface	309
# define	T_Kernel	310
# define	T_Key	311
# define	T_Keys	312
# define	T_Keysdir	313
# define	T_Kod	314
# define	T_Leap	315
# define	T_Limited	316
# define	T_Link	317
# define	T_Logconfig	318
# define	T_Logfile	319
# define	T_Loopstats	320
# define	T_Lowpriotrap	321
# define	T_Manycastclient	322
# define	T_Manycastserver	323
# define	T_Mask	324
# define	T_Maxclock	325
# define	T_Maxdist	326
# define	T_Maxhop	327
# define	T_Maxpoll	328
# define	T_Minclock	329
# define	T_Mindist	330
# define	T_Minimum	331
# define	T_Minpoll	332
# define	T_Minsane	333
# define	T_Mode	334
# define	T_Monitor	335
# define	T_Month	336
# define	T_Multicastclient	337
# define	T_Mvpar	338
# define	T_Nolink	339
# define	T_Nomodify	340
# define	T_None	341
# define	T_Nopeer	342
# define	T_Noquery	343
# define	T_Noselect	344
# define	T_Noserve	345
# define	T_Notrap	346
# define	T_Notrust	347
# define	T_Novolley	348
# define	T_Ntp	349
# define	T_Ntpport	350
# define	T_Orphan	351
# define	T_Panic	352
# define	T_Peer	353
# define	T_Peerstats	354
# define	T_Phone	355
# define	T_Pid	356
# define	T_Pidfile	357
# define	T_Pool	358
# define	T_Port	359
# define	T_Pps	360
# define	T_Preempt	361
# define	T_Prefer	362
# define	T_Pw	363
# define	T_RandFile	364
# define	T_Rawstats	365
# define	T_Refid	366
# define	T_Requestkey	367
# define	T_Restrict	368
# define	T_Revoke	369
# define	T_Server	370
# define	T_Setvar	371
# define	T_Sign	372
# define	T_Statistics	373
# define	T_Stats	374
# define	T_Statsdir	375
# define	T_Step	376
# define	T_Stepout	377
# define	T_Stratum	378
# define	T_String	379
# define	T_Sysstats	380
# define	T_Tick	381
# define	T_Time1	382
# define	T_Time2	383
# define	T_Tinker	384
# define	T_Tos	385
# define	T_Trap	386
# define	T_True	387
# define	T_Trustedkey	388
# define	T_Ttl	389
# define	T_Type	390
# define	T_Version	391
# define	T_Week	392
# define	T_Year	393
# define	T_Flag	394
# define	T_Void	395
# define	T_EOC	396
# define	T_Simulate	397
# define	T_Beep_Delay	398
# define	T_Sim_Duration	399
# define	T_Server_Offset	400
# define	T_Duration	401
# define	T_Freq_Offset	402
# define	T_Wander	403
# define	T_Jitter	404
# define	T_Prop_Delay	405
# define	T_Proc_Delay	406

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

  #include "ntpsim.h"		/* HMS: Do we really want this all the time? */
                                /* SK: It might be a good idea to always
				   include the simulator code. That way
				   someone can use the same configuration file
				   for both the simulator and the daemon
				*/

  /*  #include "ntp_parser.h"     SK: Arent't we generating this using bison?
				   This was not an issue when we were 
				   directly including the source file. However,
				   we will need a seperate description of the
				   tokens in the scanner.
				*/


  struct FILE_INFO *ip_file;   /* Pointer to the configuration file stream */

  #define YYERROR_VERBOSE
  void yyerror (char *msg);

  /* SK: The following is a terrible hack to allow the NTP code to be built
   * without OPENSSL. The following symbols need to be defined in the 
   * here because bison will balk at the presence of a C like preprocesser 
   * directive in the rules section.
   *
   * There should be a better way of doing this...
   */
#ifndef OPENSSL
  #define CRYPTO_CONF_NONE  0     
  #define CRYPTO_CONF_PRIV  1     
  #define CRYPTO_CONF_SIGN  2     
  #define CRYPTO_CONF_LEAP  3     
  #define CRYPTO_CONF_KEYS  4     
  #define CRYPTO_CONF_CERT  5     
  #define CRYPTO_CONF_RAND  6     
  #define CRYPTO_CONF_TRST  7     
  #define CRYPTO_CONF_IFFPAR 8    
  #define CRYPTO_CONF_GQPAR 9     
  #define CRYPTO_CONF_MVPAR 10    
  #define CRYPTO_CONF_PW    11    
 #define CRYPTO_CONF_IDENT 12    
#endif

#line 69 "ntp_parser.y"
#ifndef YYSTYPE
typedef union {
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
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 1
#endif



#define	YYFINAL		361
#define	YYFLAG		-32768
#define	YYNTBASE	158

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 406 ? yytranslate[x] : 220)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const short yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   154,     2,   155,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   153,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   156,     2,   157,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     6,     9,    12,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    39,    42,
      44,    46,    48,    50,    52,    54,    56,    59,    61,    63,
      66,    68,    70,    72,    74,    77,    80,    83,    85,    87,
      89,    91,    94,    97,   100,   102,   105,   108,   111,   114,
     117,   120,   123,   126,   129,   132,   135,   138,   140,   143,
     146,   149,   152,   155,   158,   161,   164,   167,   170,   173,
     176,   178,   181,   184,   187,   190,   193,   196,   199,   202,
     205,   208,   211,   214,   217,   221,   224,   226,   228,   230,
     232,   234,   236,   238,   241,   243,   246,   249,   251,   253,
     255,   257,   259,   261,   263,   265,   267,   269,   271,   274,
     278,   282,   288,   289,   292,   294,   296,   298,   300,   302,
     304,   306,   308,   310,   312,   314,   316,   319,   321,   324,
     327,   330,   334,   337,   339,   342,   345,   348,   351,   354,
     357,   360,   363,   366,   369,   372,   374,   376,   378,   380,
     382,   384,   386,   388,   391,   394,   396,   399,   402,   405,
     408,   411,   414,   417,   421,   423,   426,   429,   432,   436,
     439,   442,   445,   448,   451,   454,   458,   461,   462,   464,
     469,   473,   476,   478,   481,   484,   487,   489,   492,   494,
     496,   498,   500,   503,   505,   508,   510,   513,   515,   517,
     519,   521,   523,   525,   531,   533,   537,   540,   544,   548,
     551,   553,   559,   564,   568,   570,   572,   575,   577,   584,
     588,   591,   595,   599,   603,   607
};
static const short yyrhs[] =
{
     159,     0,   159,   160,   142,     0,   160,   142,     0,     1,
     142,     0,     0,   161,     0,   167,     0,   168,     0,   174,
       0,   180,     0,   171,     0,   185,     0,   188,     0,   191,
       0,   194,     0,   207,     0,   162,   163,   165,     0,   162,
     163,     0,   116,     0,   104,     0,    99,     0,    11,     0,
      68,     0,   164,     0,   125,     0,    54,   125,     0,    47,
       0,    48,     0,   165,   166,     0,   166,     0,     6,     0,
      14,     0,    49,     0,    57,    54,     0,    78,    54,     0,
      74,    54,     0,    90,     0,   107,     0,   108,     0,   133,
       0,   135,    54,     0,    80,    54,     0,   137,    54,     0,
      12,     0,    12,    94,     0,    69,   204,     0,    83,   204,
       0,     6,    54,     0,    21,    54,     0,    22,   169,     0,
      58,   125,     0,    59,   125,     0,   113,    54,     0,   115,
      54,     0,   134,   202,     0,   169,   170,     0,   170,     0,
      18,   125,     0,    61,   125,     0,   110,   125,     0,    45,
     125,     0,   118,   125,     0,    50,   125,     0,    51,   125,
       0,    44,   125,     0,    84,   125,     0,   109,   125,     0,
     131,   172,     0,   172,   173,     0,   173,     0,    17,    54,
       0,    41,    54,     0,    20,   205,     0,    97,    54,     0,
      76,   206,     0,    72,   206,     0,    75,   206,     0,    71,
     206,     0,    79,    54,     0,    10,    54,     0,    73,    54,
       0,   119,   175,     0,   121,   125,     0,    36,   176,   177,
       0,   175,   176,     0,   176,     0,    19,     0,    23,     0,
      66,     0,   100,     0,   111,     0,   126,     0,   177,   178,
       0,   178,     0,    35,   125,     0,   136,   179,     0,    63,
       0,    85,     0,    32,     0,    26,     0,    87,     0,   102,
       0,    24,     0,   138,     0,    82,     0,   139,     0,     3,
       0,    27,   183,     0,   114,   163,   181,     0,   114,    25,
     181,     0,   114,   164,    70,   164,   181,     0,     0,   181,
     182,     0,    52,     0,    60,     0,    62,     0,    67,     0,
      86,     0,    88,     0,    89,     0,    91,     0,    92,     0,
      93,     0,    96,     0,   137,     0,   183,   184,     0,   184,
       0,     8,    54,     0,    77,    54,     0,    81,    54,     0,
      43,   163,   186,     0,   186,   187,     0,   187,     0,   128,
     206,     0,   129,   206,     0,   124,    54,     0,   112,   125,
       0,    37,   205,     0,    38,   205,     0,    39,   205,     0,
      40,   205,     0,    32,   189,     0,    26,   189,     0,   189,
     190,     0,   190,     0,     5,     0,     9,     0,    15,     0,
      56,     0,    81,     0,    95,     0,   120,     0,   130,   192,
       0,   192,   193,     0,   193,     0,     4,   206,     0,    28,
     206,     0,    42,   206,     0,    46,   206,     0,    98,   206,
       0,   122,   206,     0,   123,   206,     0,    53,   125,   160,
       0,    33,     0,    13,   206,     0,    16,    54,     0,   127,
     206,     0,    30,   125,   195,     0,   103,   125,     0,    65,
     125,     0,     7,    54,     0,    64,   199,     0,   101,   203,
       0,   117,   196,     0,   132,   164,   197,     0,   135,   202,
       0,     0,    54,     0,   125,   153,   125,    25,     0,   125,
     153,   125,     0,   197,   198,     0,   198,     0,   105,    54,
       0,    55,   164,     0,   199,   200,     0,   200,     0,   201,
     125,     0,   125,     0,   154,     0,   155,     0,   153,     0,
     202,    54,     0,    54,     0,   203,   125,     0,   125,     0,
     204,   163,     0,   163,     0,    54,     0,   133,     0,    34,
       0,    54,     0,    29,     0,   208,   156,   209,   211,   157,
       0,   143,     0,   209,   210,   142,     0,   210,   142,     0,
     144,   153,   206,     0,   145,   153,   206,     0,   211,   212,
       0,   212,     0,   214,   156,   213,   216,   157,     0,   146,
     153,   206,   142,     0,   116,   153,   215,     0,   164,     0,
     125,     0,   216,   217,     0,   217,     0,   147,   153,   206,
     156,   218,   157,     0,   218,   219,   142,     0,   219,   142,
       0,   148,   153,   206,     0,   149,   153,   206,     0,   150,
     153,   206,     0,   151,   153,   206,     0,   152,   153,   206,
       0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   300,   304,   305,   310,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   337,   343,   352,
     353,   354,   355,   356,   360,   361,   362,   378,   379,   383,
     384,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   411,   413,   415,   417,   428,   430,
     432,   438,   440,   442,   444,   446,   451,   452,   456,   458,
     460,   462,   464,   466,   468,   470,   472,   474,   484,   489,
     490,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   524,   526,   528,   536,   537,   541,   543,   545,
     547,   549,   551,   556,   557,   561,   562,   563,   564,   565,
     566,   570,   571,   572,   573,   574,   575,   576,   585,   587,
     592,   597,   605,   606,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   625,   626,   630,   631,
     632,   640,   645,   646,   650,   652,   654,   656,   658,   660,
     662,   664,   673,   675,   680,   681,   685,   686,   687,   688,
     689,   690,   692,   700,   704,   705,   709,   710,   711,   712,
     713,   714,   715,   723,   739,   745,   747,   749,   751,   754,
     756,   758,   761,   763,   765,   767,   769,   773,   774,   779,
     781,   787,   788,   792,   793,   798,   799,   803,   804,   821,
     822,   823,   832,   833,   837,   838,   842,   843,   847,   856,
     857,   861,   862,   870,   885,   889,   890,   894,   895,   899,
     900,   904,   909,   913,   917,   918,   922,   923,   927,   932,
     933,   937,   939,   941,   943,   945
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "T_Age", "T_Allan", "T_Auth", "T_Autokey", 
  "T_Automax", "T_Average", "T_Bclient", "T_Beacon", "T_Broadcast", 
  "T_Broadcastclient", "T_Broadcastdelay", "T_Burst", "T_Calibrate", 
  "T_Calldelay", "T_Ceiling", "T_Cert", "T_Clockstats", "T_Cohort", 
  "T_ControlKey", "T_Crypto", "T_Cryptostats", "T_Day", "T_Default", 
  "T_Disable", "T_Discard", "T_Dispersion", "T_Double", "T_Driftfile", 
  "T_DriftMinutes", "T_Enable", "T_End", "T_False", "T_File", "T_Filegen", 
  "T_Flag1", "T_Flag2", "T_Flag3", "T_Flag4", "T_Floor", "T_Freq", 
  "T_Fudge", "T_Gqpar", "T_Host", "T_Huffpuff", "T_IPv4_address", 
  "T_IPv6_address", "T_Iburst", "T_Ident", "T_Iffpar", "T_Ignore", 
  "T_Includefile", "T_Integer", "T_Interface", "T_Kernel", "T_Key", 
  "T_Keys", "T_Keysdir", "T_Kod", "T_Leap", "T_Limited", "T_Link", 
  "T_Logconfig", "T_Logfile", "T_Loopstats", "T_Lowpriotrap", 
  "T_Manycastclient", "T_Manycastserver", "T_Mask", "T_Maxclock", 
  "T_Maxdist", "T_Maxhop", "T_Maxpoll", "T_Minclock", "T_Mindist", 
  "T_Minimum", "T_Minpoll", "T_Minsane", "T_Mode", "T_Monitor", "T_Month", 
  "T_Multicastclient", "T_Mvpar", "T_Nolink", "T_Nomodify", "T_None", 
  "T_Nopeer", "T_Noquery", "T_Noselect", "T_Noserve", "T_Notrap", 
  "T_Notrust", "T_Novolley", "T_Ntp", "T_Ntpport", "T_Orphan", "T_Panic", 
  "T_Peer", "T_Peerstats", "T_Phone", "T_Pid", "T_Pidfile", "T_Pool", 
  "T_Port", "T_Pps", "T_Preempt", "T_Prefer", "T_Pw", "T_RandFile", 
  "T_Rawstats", "T_Refid", "T_Requestkey", "T_Restrict", "T_Revoke", 
  "T_Server", "T_Setvar", "T_Sign", "T_Statistics", "T_Stats", 
  "T_Statsdir", "T_Step", "T_Stepout", "T_Stratum", "T_String", 
  "T_Sysstats", "T_Tick", "T_Time1", "T_Time2", "T_Tinker", "T_Tos", 
  "T_Trap", "T_True", "T_Trustedkey", "T_Ttl", "T_Type", "T_Version", 
  "T_Week", "T_Year", "T_Flag", "T_Void", "T_EOC", "T_Simulate", 
  "T_Beep_Delay", "T_Sim_Duration", "T_Server_Offset", "T_Duration", 
  "T_Freq_Offset", "T_Wander", "T_Jitter", "T_Prop_Delay", "T_Proc_Delay", 
  "'='", "'+'", "'-'", "'{'", "'}'", "configuration", "command_list", 
  "command", "server_command", "client_type", "address", "ip_address", 
  "option_list", "option", "other_mode_command", "authentication_command", 
  "crypto_command_list", "crypto_command", "orphan_mode_command", 
  "tos_option_list", "tos_option", "monitoring_command", "stats_list", 
  "stat", "filegen_option_list", "filegen_option", "filegen_type", 
  "access_control_command", "ac_flag_list", "access_control_flag", 
  "discard_option_list", "discard_option", "fudge_command", 
  "fudge_factor_list", "fudge_factor", "system_option_command", 
  "system_option_list", "system_option", "tinker_command", 
  "tinker_option_list", "tinker_option", "miscellaneous_command", 
  "drift_parm", "variable_assign", "trap_option_list", "trap_option", 
  "log_config_list", "log_config_command", "log_config_prefix", 
  "integer_list", "string_list", "address_list", "boolean", "number", 
  "simulate_command", "sim_conf_start", "sim_init_statement_list", 
  "sim_init_statement", "sim_server_list", "sim_server", 
  "sim_server_offset", "sim_server_name", "sim_address", "sim_act_list", 
  "sim_act", "sim_act_stmt_list", "sim_act_stmt", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,   158,   159,   159,   159,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   161,   161,   162,
     162,   162,   162,   162,   163,   163,   163,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   167,   167,   167,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   169,   169,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   172,
     172,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   174,   174,   174,   175,   175,   176,   176,   176,
     176,   176,   176,   177,   177,   178,   178,   178,   178,   178,
     178,   179,   179,   179,   179,   179,   179,   179,   180,   180,
     180,   180,   181,   181,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   183,   183,   184,   184,
     184,   185,   186,   186,   187,   187,   187,   187,   187,   187,
     187,   187,   188,   188,   189,   189,   190,   190,   190,   190,
     190,   190,   190,   191,   192,   192,   193,   193,   193,   193,
     193,   193,   193,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   195,   195,   196,
     196,   197,   197,   198,   198,   199,   199,   200,   200,   201,
     201,   201,   202,   202,   203,   203,   204,   204,   205,   205,
     205,   206,   206,   207,   208,   209,   209,   210,   210,   211,
     211,   212,   213,   214,   215,   215,   216,   216,   217,   218,
     218,   219,   219,   219,   219,   219
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     3,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     5,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     2,
       2,     3,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     3,     1,     2,     2,     2,     3,     2,
       2,     2,     2,     2,     2,     3,     2,     0,     1,     4,
       3,     2,     1,     2,     2,     2,     1,     2,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     5,     1,     3,     2,     3,     3,     2,
       1,     5,     4,     3,     1,     1,     2,     1,     6,     3,
       2,     3,     3,     3,     3,     3
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       0,     0,     0,     0,    22,    44,     0,     0,     0,     0,
       0,     0,     0,     0,   164,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,    21,     0,     0,    20,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   204,     1,     0,     6,     0,     7,     8,    11,
       9,    10,    12,    13,    14,    15,    16,     0,     4,    48,
     171,    45,   202,   201,   165,   166,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    57,   146,
     147,   148,   149,   150,   151,   152,   143,   145,     0,     0,
       0,   108,   127,   177,   142,    87,    88,    89,    90,    91,
      92,     0,    27,    28,     0,    25,     0,    24,     5,    51,
      52,   188,   191,   189,   190,   172,   186,     0,   170,   197,
      46,    47,   195,   173,   169,    53,   112,   112,    24,    54,
       0,   174,    82,    86,    83,   167,     0,     0,     0,     0,
       0,     0,     0,   153,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    70,     0,   193,
      55,   176,     0,     3,    18,     0,    58,    65,    61,    63,
      64,    59,    66,    67,    60,    62,    56,   144,   128,   129,
     130,   126,   178,   168,   100,    99,     0,    97,    98,     0,
      84,    94,    26,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   133,   163,   185,   187,   196,   194,   110,   109,
       0,     0,    85,   156,   157,   158,   159,   160,   161,   162,
     154,    80,    71,   200,   198,   199,    73,    72,    78,    76,
      81,    77,    75,    79,    74,    69,     0,     0,   175,   182,
     192,     2,    31,    32,    33,     0,     0,     0,     0,    37,
      38,    39,    40,     0,     0,    17,    30,     0,     0,     0,
       0,    95,   107,   103,   105,   101,   102,   104,   106,    96,
      93,   138,   139,   140,   141,   137,   136,   134,   135,   132,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   113,   112,   180,   184,   183,   181,    34,    36,
      35,    42,    41,    43,    29,     0,     0,     0,     0,     0,
     210,     0,   206,   111,   179,   207,   208,     0,   205,   203,
     209,     0,   215,   214,   213,     0,     0,     0,     0,     0,
     217,     0,     0,   211,   216,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,     0,   220,   221,   222,   223,   224,   225,   219,     0,
       0,     0
};

static const short yydefgoto[] =
{
     359,    43,    44,    45,    46,   119,   107,   255,   256,    47,
      48,    77,    78,    49,   156,   157,    50,   132,   101,   190,
     191,   269,    51,   208,   292,    91,    92,    52,   201,   202,
      53,    86,    87,    54,   143,   144,    55,   183,   131,   238,
     239,   115,   116,   117,   160,   123,   120,   226,    64,    56,
      57,   259,   260,   309,   310,   326,   311,   324,   329,   330,
     343,   344
};

static const short yypact[] =
{
       8,  -130,   -31,   -27,-32768,   -62,   -18,   -11,    -8,   190,
      -2,    -3,   -77,    -2,-32768,    62,    40,   -66,   -60,   -54,
      47,   -45,-32768,    40,    40,-32768,   -35,   -33,-32768,    30,
      35,    32,-32768,   -17,    62,    -6,   -18,    22,   139,    15,
      80,    80,-32768,   163,    -5,-32768,    40,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,   -15,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,    21,    23,    33,
      36,    46,    52,    53,    57,    58,    61,   190,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,    -2,-32768,    93,   103,
     133,    -3,-32768,   137,    -2,-32768,-32768,-32768,-32768,-32768,
  -32768,   -10,-32768,-32768,    67,-32768,   221,-32768,   308,-32768,
  -32768,-32768,-32768,-32768,-32768,    47,-32768,    69,-32768,-32768,
      40,    40,-32768,    72,-32768,-32768,-32768,-32768,   128,-32768,
      50,-32768,    62,-32768,-32768,-32768,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,    22,-32768,   150,   151,     3,   155,   -18,
     -18,   159,   -18,   -18,   165,   166,   139,-32768,   -49,-32768,
     169,   169,    75,-32768,   325,   -48,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,    99,-32768,-32768,    28,
     -10,-32768,-32768,     3,     3,     3,     3,   100,   172,   -18,
     -18,   221,-32768,-32768,-32768,-32768,-32768,-32768,   385,   385,
      15,   105,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,    15,   175,   -49,-32768,
  -32768,-32768,-32768,-32768,-32768,   179,   183,   184,   185,-32768,
  -32768,-32768,-32768,   188,   189,   325,-32768,    91,    92,   -46,
     106,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,   222,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   -18,   -18,    96,   108,  -108,
  -32768,   101,-32768,   385,-32768,-32768,-32768,   -30,-32768,-32768,
  -32768,   117,-32768,-32768,-32768,   112,   121,   -18,   118,  -102,
  -32768,   130,   -18,-32768,-32768,-32768,   119,   104,   120,   132,
     134,   136,   148,   205,   141,   -18,   -18,   -18,   -18,   -18,
  -32768,   144,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   281,
     292,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,   -39,-32768,-32768,    12,   -29,-32768,    48,-32768,
  -32768,-32768,   225,-32768,-32768,   160,-32768,-32768,    -1,-32768,
     114,-32768,-32768,  -125,-32768,-32768,   216,-32768,-32768,   116,
  -32768,   305,   -47,-32768,-32768,   180,-32768,-32768,-32768,-32768,
      84,-32768,   210,-32768,   285,-32768,   303,   -41,   -36,-32768,
  -32768,-32768,    73,-32768,    19,-32768,-32768,-32768,-32768,     7,
  -32768,     0
};


#define	YYLAST		522


static const short yytable[] =
{
     135,   128,   209,    79,   162,    88,   236,    80,   307,     1,
     158,    62,    58,    81,     2,     3,   184,   102,   103,     4,
       5,     6,   185,    59,     7,   186,   136,    60,   106,     8,
       9,   262,    61,   133,    10,    11,    63,   223,    12,   177,
      13,    14,   127,    65,    15,   328,    66,   177,    93,   319,
     137,    16,   263,   187,    82,   333,   237,   224,   164,   108,
     126,    17,   102,   103,   138,   109,    18,    19,   139,   203,
     307,   110,    20,    21,    89,   188,    22,    23,    90,    83,
     118,    95,   102,   103,   125,    96,   129,   102,   103,   104,
     122,    24,   124,    84,   104,   322,   257,   258,   257,   258,
     213,   214,   215,   216,   217,   218,   219,    25,   130,    26,
     264,    27,    28,   228,   229,   265,   231,   232,    85,   134,
     140,    29,    30,    31,    32,    33,   189,    34,    97,    35,
     266,   212,   206,   206,   159,    36,   225,   163,    37,    38,
      39,   165,    40,    41,   141,   142,   166,   178,   167,   145,
      -5,    42,   271,   272,   273,   274,   146,   179,   168,   147,
     105,   169,    98,   277,   278,   105,   267,   268,   313,     2,
       3,   170,   111,    99,     4,     5,     6,   171,   172,     7,
     148,   293,   173,   174,     8,     9,   175,   180,   100,    10,
      11,   182,   192,    12,   205,    13,    14,   207,   210,    15,
     112,   113,   114,   211,   221,   222,    16,   295,    67,   227,
     149,   150,   151,   230,   152,   153,    17,   241,   154,   233,
     234,    18,    19,   240,   261,   275,   276,    20,    21,   296,
     294,    22,    23,   298,    68,    69,   155,   299,   300,   301,
      70,    71,   302,   303,   305,   306,    24,   314,   312,   317,
     318,    72,   338,   339,   340,   341,   342,   321,   193,   194,
     195,   196,    25,   325,    26,   327,    27,    28,   328,   315,
     316,   332,   335,   345,    73,   337,    29,    30,    31,    32,
      33,   360,    34,   352,    35,   346,   358,   347,   323,   348,
      36,   331,   361,    37,    38,    39,   336,    40,    41,    74,
      75,   349,   176,   304,   270,    -5,    42,   181,    76,   353,
     354,   355,   356,   357,     2,     3,   235,   279,    94,     4,
       5,     6,   297,   220,     7,   204,   161,   121,   320,     8,
       9,   242,   308,   197,    10,    11,   334,     0,    12,   243,
      13,    14,     0,   351,    15,   198,     0,     0,     0,   199,
     200,    16,     0,   338,   339,   340,   341,   342,     0,     0,
       0,    17,   350,     0,     0,     0,    18,    19,     0,     0,
       0,     0,    20,    21,   244,     0,    22,    23,     0,     0,
       0,     0,   245,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,   246,
       0,     0,     0,   247,     0,   248,     0,    25,     0,    26,
       0,    27,    28,     0,     0,   249,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,    35,
       0,     0,   250,   251,     0,    36,     0,   280,    37,    38,
      39,     0,    40,    41,     0,   281,     0,   282,     0,     0,
       0,    42,   283,     0,     0,     0,     0,     0,   252,     0,
     253,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,   285,   286,     0,   287,   288,   289,     0,
       0,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291
};

static const short yycheck[] =
{
      36,    30,   127,     5,    43,     8,    55,     9,   116,     1,
      39,    29,   142,    15,     6,     7,    26,    47,    48,    11,
      12,    13,    32,    54,    16,    35,     4,    54,    16,    21,
      22,     3,    94,    34,    26,    27,    54,    34,    30,    86,
      32,    33,    30,    54,    36,   147,    54,    94,   125,   157,
      28,    43,    24,    63,    56,   157,   105,    54,    46,   125,
      25,    53,    47,    48,    42,   125,    58,    59,    46,   108,
     116,   125,    64,    65,    77,    85,    68,    69,    81,    81,
     125,    19,    47,    48,    54,    23,    54,    47,    48,    54,
     125,    83,   125,    95,    54,   125,   144,   145,   144,   145,
     136,   137,   138,   139,   140,   141,   142,    99,   125,   101,
      82,   103,   104,   149,   150,    87,   152,   153,   120,   125,
      98,   113,   114,   115,   116,   117,   136,   119,    66,   121,
     102,   132,   120,   121,    54,   127,   133,   142,   130,   131,
     132,   156,   134,   135,   122,   123,   125,    54,   125,    10,
     142,   143,   193,   194,   195,   196,    17,    54,   125,    20,
     125,   125,   100,   199,   200,   125,   138,   139,   293,     6,
       7,   125,   125,   111,    11,    12,    13,   125,   125,    16,
      41,   210,   125,   125,    21,    22,   125,    54,   126,    26,
      27,    54,   125,    30,   125,    32,    33,   125,    70,    36,
     153,   154,   155,   153,    54,    54,    43,   236,    18,    54,
      71,    72,    73,    54,    75,    76,    53,   142,    79,    54,
      54,    58,    59,    54,   125,   125,    54,    64,    65,    54,
     125,    68,    69,    54,    44,    45,    97,    54,    54,    54,
      50,    51,    54,    54,   153,   153,    83,    25,   142,   153,
     142,    61,   148,   149,   150,   151,   152,   156,    37,    38,
      39,    40,    99,   146,   101,   153,   103,   104,   147,   305,
     306,   153,   142,   153,    84,   156,   113,   114,   115,   116,
     117,     0,   119,   142,   121,   153,   142,   153,   317,   153,
     127,   327,     0,   130,   131,   132,   332,   134,   135,   109,
     110,   153,    77,   255,   190,   142,   143,    91,   118,   345,
     346,   347,   348,   349,     6,     7,   156,   201,    13,    11,
      12,    13,   238,   143,    16,   115,    41,    24,   309,    21,
      22,     6,   259,   112,    26,    27,   329,    -1,    30,    14,
      32,    33,    -1,   343,    36,   124,    -1,    -1,    -1,   128,
     129,    43,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    53,   157,    -1,    -1,    -1,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    49,    -1,    68,    69,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    80,    -1,    99,    -1,   101,
      -1,   103,   104,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,    -1,   119,    -1,   121,
      -1,    -1,   107,   108,    -1,   127,    -1,    52,   130,   131,
     132,    -1,   134,   135,    -1,    60,    -1,    62,    -1,    -1,
      -1,   143,    67,    -1,    -1,    -1,    -1,    -1,   133,    -1,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    88,    89,    -1,    91,    92,    93,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/gnu/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


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
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 315 "/usr/local/gnu/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 4:
#line 311 "ntp_parser.y"
{ 
                    fprintf(stderr, "PARSE ERROR!! At Line: %d\n", 
                            ip_file->line_no);
                    fprintf(stderr, "Line Ignored!!\n");
                }
    break;
case 17:
#line 338 "ntp_parser.y"
{ 
                        struct peer_node *my_node =  create_peer_node(yyvsp[-2].Integer, yyvsp[-1].Address_node, yyvsp[0].Queue); 
                        if (my_node)
                            enqueue(my_config.peers, my_node);                        
                    }
    break;
case 18:
#line 344 "ntp_parser.y"
{ 
                        struct peer_node *my_node = create_peer_node(yyvsp[-1].Integer, yyvsp[0].Address_node, NULL); 
                        if (my_node)
                            enqueue(my_config.peers, my_node);                        
                    }
    break;
case 19:
#line 352 "ntp_parser.y"
{ yyval.Integer = T_Server; }
    break;
case 20:
#line 353 "ntp_parser.y"
{ yyval.Integer = T_Pool; }
    break;
case 21:
#line 354 "ntp_parser.y"
{ yyval.Integer = T_Peer; }
    break;
case 22:
#line 355 "ntp_parser.y"
{ yyval.Integer = T_Broadcast; }
    break;
case 23:
#line 356 "ntp_parser.y"
{ yyval.Integer = T_Manycastclient; }
    break;
case 24:
#line 360 "ntp_parser.y"
{ yyval.Address_node = yyvsp[0].Address_node; }
    break;
case 25:
#line 361 "ntp_parser.y"
{ yyval.Address_node = create_address_node(yyvsp[0].String, default_ai_family); }
    break;
case 26:
#line 363 "ntp_parser.y"
{
                        if (yyvsp[-1].Integer == -4)
                            yyval.Address_node = create_address_node(yyvsp[0].String, AF_INET);
                        else if (yyvsp[-1].Integer == -6)
                            yyval.Address_node = create_address_node(yyvsp[0].String, AF_INET6);
                        else {
                            yyerror("Invalid address type specified. Assuming default.\n");
                            yyval.Address_node = create_address_node(yyvsp[0].String, default_ai_family);
                        }
                    }
    break;
case 27:
#line 378 "ntp_parser.y"
{ yyval.Address_node = create_address_node(yyvsp[0].String, AF_INET); }
    break;
case 28:
#line 379 "ntp_parser.y"
{ yyval.Address_node = create_address_node(yyvsp[0].String, AF_INET6); }
    break;
case 29:
#line 383 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 30:
#line 384 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 31:
#line 389 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, FLAG_SKEY | FLAG_AUTHENABLE); }
    break;
case 32:
#line 390 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, FLAG_BURST); }
    break;
case 33:
#line 391 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, FLAG_IBURST); }
    break;
case 34:
#line 392 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Key, yyvsp[0].Integer); }
    break;
case 35:
#line 393 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Minpoll, yyvsp[0].Integer); }
    break;
case 36:
#line 394 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Maxpoll, yyvsp[0].Integer); }
    break;
case 37:
#line 395 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, FLAG_NOSELECT);}
    break;
case 38:
#line 396 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, FLAG_PREEMPT); }
    break;
case 39:
#line 397 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, FLAG_PREFER); }
    break;
case 40:
#line 398 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, FLAG_TRUE); }
    break;
case 41:
#line 399 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Ttl, yyvsp[0].Integer); }
    break;
case 42:
#line 400 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Mode, yyvsp[0].Integer); }
    break;
case 43:
#line 401 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Version, yyvsp[0].Integer); }
    break;
case 44:
#line 412 "ntp_parser.y"
{ my_config.broadcastclient = SIMPLE; }
    break;
case 45:
#line 414 "ntp_parser.y"
{ my_config.broadcastclient = NOVOLLEY;  }
    break;
case 46:
#line 416 "ntp_parser.y"
{ append_queue(my_config.manycastserver, yyvsp[0].Queue);  }
    break;
case 47:
#line 418 "ntp_parser.y"
{ append_queue(my_config.multicastclient, yyvsp[0].Queue);  }
    break;
case 48:
#line 429 "ntp_parser.y"
{ my_config.auth.autokey = yyvsp[0].Integer;  }
    break;
case 49:
#line 431 "ntp_parser.y"
{ my_config.auth.control_key = yyvsp[0].Integer;  }
    break;
case 50:
#line 433 "ntp_parser.y"
{ if (my_config.auth.crypto_cmd_list != NULL) 
					append_queue(my_config.auth.crypto_cmd_list, yyvsp[0].Queue); 
		 		else 
					my_config.auth.crypto_cmd_list = yyvsp[0].Queue;
			}
    break;
case 51:
#line 439 "ntp_parser.y"
{ my_config.auth.keys = yyvsp[0].String;  }
    break;
case 52:
#line 441 "ntp_parser.y"
{ my_config.auth.keysdir = yyvsp[0].String;  }
    break;
case 53:
#line 443 "ntp_parser.y"
{ my_config.auth.requested_key = yyvsp[0].Integer;  }
    break;
case 54:
#line 445 "ntp_parser.y"
{ my_config.auth.revoke = yyvsp[0].Integer;  }
    break;
case 55:
#line 447 "ntp_parser.y"
{ my_config.auth.trusted_key_list = yyvsp[0].Queue;  }
    break;
case 56:
#line 451 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 57:
#line 452 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 58:
#line 457 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_CERT, yyvsp[0].String); }
    break;
case 59:
#line 459 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_LEAP, yyvsp[0].String); }
    break;
case 60:
#line 461 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_RAND, yyvsp[0].String); }
    break;
case 61:
#line 463 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_PRIV, yyvsp[0].String); }
    break;
case 62:
#line 465 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_SIGN, yyvsp[0].String); }
    break;
case 63:
#line 467 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_IDENT, yyvsp[0].String); }
    break;
case 64:
#line 469 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_IFFPAR, yyvsp[0].String); }
    break;
case 65:
#line 471 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_GQPAR, yyvsp[0].String); }
    break;
case 66:
#line 473 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_MVPAR, yyvsp[0].String); }
    break;
case 67:
#line 475 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CRYPTO_CONF_PW, yyvsp[0].String); }
    break;
case 68:
#line 485 "ntp_parser.y"
{ append_queue(my_config.orphan_cmds,yyvsp[0].Queue);  }
    break;
case 69:
#line 489 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 70:
#line 490 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 71:
#line 495 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_CEILING, (double)yyvsp[0].Integer); }
    break;
case 72:
#line 497 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_FLOOR, (double)yyvsp[0].Integer); }
    break;
case 73:
#line 499 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_COHORT, (double)yyvsp[0].Integer); }
    break;
case 74:
#line 501 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_ORPHAN, (double)yyvsp[0].Integer); }
    break;
case 75:
#line 503 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_MINDISP, yyvsp[0].Double); }
    break;
case 76:
#line 505 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_MAXDIST, yyvsp[0].Double); }
    break;
case 77:
#line 507 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_MINCLOCK, yyvsp[0].Double); }
    break;
case 78:
#line 509 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_MAXCLOCK, yyvsp[0].Double); }
    break;
case 79:
#line 511 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_MINSANE, (double)yyvsp[0].Integer); }
    break;
case 80:
#line 513 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_BEACON, (double)yyvsp[0].Integer); }
    break;
case 81:
#line 515 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(PROTO_MAXHOP, (double)yyvsp[0].Integer); }
    break;
case 82:
#line 525 "ntp_parser.y"
{ append_queue(my_config.stats_list, yyvsp[0].Queue);  }
    break;
case 83:
#line 527 "ntp_parser.y"
{ my_config.stats_dir = yyvsp[0].String;  }
    break;
case 84:
#line 529 "ntp_parser.y"
{
                        enqueue(my_config.filegen_opts, 
                                create_filegen_node(yyvsp[-1].VoidPtr, yyvsp[0].Queue));                         
                    }
    break;
case 85:
#line 536 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].VoidPtr); }
    break;
case 86:
#line 537 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].VoidPtr); }
    break;
case 87:
#line 542 "ntp_parser.y"
{ yyval.VoidPtr = create_pval("clockstats"); }
    break;
case 88:
#line 544 "ntp_parser.y"
{ yyval.VoidPtr = create_pval("cryptostats"); }
    break;
case 89:
#line 546 "ntp_parser.y"
{ yyval.VoidPtr = create_pval("loopstats"); }
    break;
case 90:
#line 548 "ntp_parser.y"
{ yyval.VoidPtr = create_pval("peerstats"); }
    break;
case 91:
#line 550 "ntp_parser.y"
{ yyval.VoidPtr = create_pval("rawstats"); }
    break;
case 92:
#line 552 "ntp_parser.y"
{ yyval.VoidPtr = create_pval("sysstats"); }
    break;
case 93:
#line 556 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 94:
#line 557 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 95:
#line 561 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(T_File, yyvsp[0].String); }
    break;
case 96:
#line 562 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Type, yyvsp[0].Integer); }
    break;
case 97:
#line 563 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, T_Link); }
    break;
case 98:
#line 564 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, T_Nolink); }
    break;
case 99:
#line 565 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, T_Enable); }
    break;
case 100:
#line 566 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, T_Disable); }
    break;
case 101:
#line 570 "ntp_parser.y"
{ yyval.Integer = FILEGEN_NONE; }
    break;
case 102:
#line 571 "ntp_parser.y"
{ yyval.Integer = FILEGEN_PID; }
    break;
case 103:
#line 572 "ntp_parser.y"
{ yyval.Integer = FILEGEN_DAY; }
    break;
case 104:
#line 573 "ntp_parser.y"
{ yyval.Integer = FILEGEN_WEEK; }
    break;
case 105:
#line 574 "ntp_parser.y"
{ yyval.Integer = FILEGEN_MONTH; }
    break;
case 106:
#line 575 "ntp_parser.y"
{ yyval.Integer = FILEGEN_YEAR; }
    break;
case 107:
#line 576 "ntp_parser.y"
{ yyval.Integer = FILEGEN_AGE; }
    break;
case 108:
#line 586 "ntp_parser.y"
{   append_queue(my_config.discard_opts, yyvsp[0].Queue); }
    break;
case 109:
#line 588 "ntp_parser.y"
{ 
                        enqueue(my_config.restrict_opts, 
                                create_restrict_node(yyvsp[-1].Address_node, NULL, yyvsp[0].Queue, ip_file->line_no));                          
                    }
    break;
case 110:
#line 593 "ntp_parser.y"
{ 
                        enqueue(my_config.restrict_opts, 
                                create_restrict_node(NULL, NULL, yyvsp[0].Queue, ip_file->line_no)); 
                    }
    break;
case 111:
#line 598 "ntp_parser.y"
{ 
                        enqueue(my_config.restrict_opts, 
                                create_restrict_node(yyvsp[-3].Address_node, yyvsp[-1].Address_node, yyvsp[0].Queue, ip_file->line_no)); 
                    }
    break;
case 112:
#line 605 "ntp_parser.y"
{ yyval.Queue = create_queue(); }
    break;
case 113:
#line 606 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].VoidPtr); }
    break;
case 114:
#line 610 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_IGNORE); }
    break;
case 115:
#line 611 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_DEMOBILIZE); }
    break;
case 116:
#line 612 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_LIMITED); }
    break;
case 117:
#line 613 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_LPTRAP); }
    break;
case 118:
#line 614 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_NOMODIFY); }
    break;
case 119:
#line 615 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_NOPEER); }
    break;
case 120:
#line 616 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_NOQUERY); }
    break;
case 121:
#line 617 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_DONTSERVE); }
    break;
case 122:
#line 618 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_NOTRAP); }
    break;
case 123:
#line 619 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_DONTTRUST); }
    break;
case 124:
#line 620 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RESM_NTPONLY); }
    break;
case 125:
#line 621 "ntp_parser.y"
{ yyval.VoidPtr = create_ival(RES_VERSION); }
    break;
case 126:
#line 625 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 127:
#line 626 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 128:
#line 630 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Average, yyvsp[0].Integer); }
    break;
case 129:
#line 631 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Minimum, yyvsp[0].Integer); }
    break;
case 130:
#line 632 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Monitor, yyvsp[0].Integer); }
    break;
case 131:
#line 641 "ntp_parser.y"
{ enqueue(my_config.fudge, create_addr_opts_node(yyvsp[-1].Address_node, yyvsp[0].Queue));  }
    break;
case 132:
#line 645 "ntp_parser.y"
{ enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 133:
#line 646 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 134:
#line 651 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(CLK_HAVETIME1, yyvsp[0].Double); }
    break;
case 135:
#line 653 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(CLK_HAVETIME2, yyvsp[0].Double); }
    break;
case 136:
#line 655 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(CLK_HAVEVAL1,  yyvsp[0].Integer); }
    break;
case 137:
#line 657 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(CLK_HAVEVAL2,  yyvsp[0].String); }
    break;
case 138:
#line 659 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(CLK_HAVEFLAG1, yyvsp[0].Integer); }
    break;
case 139:
#line 661 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(CLK_HAVEFLAG2, yyvsp[0].Integer); }
    break;
case 140:
#line 663 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(CLK_HAVEFLAG3, yyvsp[0].Integer); }
    break;
case 141:
#line 665 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(CLK_HAVEFLAG4, yyvsp[0].Integer); }
    break;
case 142:
#line 674 "ntp_parser.y"
{ append_queue(my_config.enable_opts,yyvsp[0].Queue);  }
    break;
case 143:
#line 676 "ntp_parser.y"
{ append_queue(my_config.disable_opts,yyvsp[0].Queue);  }
    break;
case 144:
#line 680 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 145:
#line 681 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 146:
#line 685 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, PROTO_AUTHENTICATE); }
    break;
case 147:
#line 686 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, PROTO_BROADCLIENT); }
    break;
case 148:
#line 687 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, PROTO_CAL); }
    break;
case 149:
#line 688 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, PROTO_KERNEL); }
    break;
case 150:
#line 689 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, PROTO_MONITOR); }
    break;
case 151:
#line 690 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, PROTO_NTP); }
    break;
case 152:
#line 692 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Flag, PROTO_FILEGEN); }
    break;
case 153:
#line 700 "ntp_parser.y"
{ append_queue(my_config.tinker, yyvsp[0].Queue);  }
    break;
case 154:
#line 704 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 155:
#line 705 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 156:
#line 709 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(LOOP_ALLAN, yyvsp[0].Double); }
    break;
case 157:
#line 710 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(LOOP_PHI, yyvsp[0].Double); }
    break;
case 158:
#line 711 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(LOOP_FREQ, yyvsp[0].Double); }
    break;
case 159:
#line 712 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(LOOP_HUFFPUFF, yyvsp[0].Double); }
    break;
case 160:
#line 713 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(LOOP_PANIC, yyvsp[0].Double); }
    break;
case 161:
#line 714 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(LOOP_MAX, yyvsp[0].Double); }
    break;
case 162:
#line 715 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(LOOP_MINSTEP, yyvsp[0].Double); }
    break;
case 163:
#line 724 "ntp_parser.y"
{
                    if (curr_include_level >= MAXINCLUDELEVEL) {
                        fprintf(stderr, "getconfig: Maximum include file level exceeded.\n");
                        msyslog(LOG_INFO, "getconfig: Maximum include file level exceeded.");
                    }
                    else {
                        fp[curr_include_level + 1] = F_OPEN(FindConfig(yyvsp[-1].String), "r");
                        if (fp[curr_include_level + 1] == NULL) {
                            fprintf(stderr, "getconfig: Couldn't open <%s>\n", FindConfig(yyvsp[-1].String));
                            msyslog(LOG_INFO, "getconfig: Couldn't open <%s>", FindConfig(yyvsp[-1].String));
                        }
                        else
                            ip_file = fp[++curr_include_level];
                    }
                }
    break;
case 164:
#line 740 "ntp_parser.y"
{
                    while (curr_include_level != -1) 
                        FCLOSE(fp[curr_include_level--]);
                }
    break;
case 165:
#line 746 "ntp_parser.y"
{ enqueue(my_config.vars, create_attr_dval(T_Broadcastdelay, yyvsp[0].Double));  }
    break;
case 166:
#line 748 "ntp_parser.y"
{ enqueue(my_config.vars, create_attr_ival(T_Calldelay, yyvsp[0].Integer));  }
    break;
case 167:
#line 750 "ntp_parser.y"
{ enqueue(my_config.vars, create_attr_dval(T_Tick, yyvsp[0].Double));  }
    break;
case 168:
#line 752 "ntp_parser.y"
{ enqueue(my_config.vars, create_attr_sval(T_Driftfile, yyvsp[-1].String)); }
    break;
case 169:
#line 755 "ntp_parser.y"
{ enqueue(my_config.vars, create_attr_sval(T_Pidfile, yyvsp[0].String));  }
    break;
case 170:
#line 757 "ntp_parser.y"
{ enqueue(my_config.vars, create_attr_sval(T_Logfile, yyvsp[0].String));  }
    break;
case 171:
#line 759 "ntp_parser.y"
{ enqueue(my_config.vars, create_attr_ival(T_Automax, yyvsp[0].Integer));  }
    break;
case 172:
#line 762 "ntp_parser.y"
{ append_queue(my_config.logconfig, yyvsp[0].Queue);  }
    break;
case 173:
#line 764 "ntp_parser.y"
{ append_queue(my_config.phone, yyvsp[0].Queue);  }
    break;
case 174:
#line 766 "ntp_parser.y"
{ enqueue(my_config.setvar, yyvsp[0].Set_var);  }
    break;
case 175:
#line 768 "ntp_parser.y"
{ enqueue(my_config.trap, create_addr_opts_node(yyvsp[-1].Address_node, yyvsp[0].Queue));  }
    break;
case 176:
#line 770 "ntp_parser.y"
{ append_queue(my_config.ttl, yyvsp[0].Queue); }
    break;
case 177:
#line 773 "ntp_parser.y"
{ /* Null command */ }
    break;
case 178:
#line 775 "ntp_parser.y"
{ enqueue(my_config.vars, create_attr_ival(T_DriftMinutes, yyvsp[0].Integer)); }
    break;
case 179:
#line 780 "ntp_parser.y"
{ yyval.Set_var = create_setvar_node(yyvsp[-3].String, yyvsp[-1].String, DEF); }
    break;
case 180:
#line 782 "ntp_parser.y"
{ yyval.Set_var = create_setvar_node(yyvsp[-2].String, yyvsp[0].String, 0); }
    break;
case 181:
#line 787 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 182:
#line 788 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 183:
#line 792 "ntp_parser.y"
{ yyval.Attr_val = create_attr_ival(T_Port, yyvsp[0].Integer); }
    break;
case 184:
#line 793 "ntp_parser.y"
{ yyval.Attr_val = create_attr_pval(T_Interface, yyvsp[0].Address_node); }
    break;
case 185:
#line 798 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Attr_val); }
    break;
case 186:
#line 799 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Attr_val); }
    break;
case 187:
#line 803 "ntp_parser.y"
{ yyval.Attr_val = create_attr_sval(yyvsp[-1].Integer, yyvsp[0].String); }
    break;
case 188:
#line 805 "ntp_parser.y"
{ 
                    /* YUCK!! This is needed because '+' and '-' are not special characters 
                     * while '=' is. 
                     * We really need a better way of defining strings
                     */
                    char prefix = yyvsp[0].String[0];
                    char *type = &(yyvsp[0].String[1]);
                    if (prefix != '+' && prefix != '-') {
                        yyerror("Logconfig prefix is not '+', '-' or '='\n");
                    }
                    else
                        yyval.Attr_val = create_attr_sval(prefix, type);
                }
    break;
case 189:
#line 821 "ntp_parser.y"
{ yyval.Integer = '+'; }
    break;
case 190:
#line 822 "ntp_parser.y"
{ yyval.Integer = '-'; }
    break;
case 191:
#line 823 "ntp_parser.y"
{ yyval.Integer = '='; }
    break;
case 192:
#line 832 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, create_ival(yyvsp[0].Integer)); }
    break;
case 193:
#line 833 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(create_ival(yyvsp[0].Integer)); }
    break;
case 194:
#line 837 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, create_pval(yyvsp[0].String)); }
    break;
case 195:
#line 838 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(create_pval(yyvsp[0].String)); }
    break;
case 196:
#line 842 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Address_node); }
    break;
case 197:
#line 843 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Address_node); }
    break;
case 198:
#line 848 "ntp_parser.y"
{ 
                    if (yyvsp[0].Integer != 0 && yyvsp[0].Integer != 1) {
                        yyerror("Integer value is not boolean (0 or 1). Assuming 1");
                        yyval.Integer = 1;
                    }
                    else
                        yyval.Integer = yyvsp[0].Integer; 
                }
    break;
case 199:
#line 856 "ntp_parser.y"
{ yyval.Integer = 1; }
    break;
case 200:
#line 857 "ntp_parser.y"
{ yyval.Integer = 0; }
    break;
case 201:
#line 861 "ntp_parser.y"
{ yyval.Double = (double)yyvsp[0].Integer; }
    break;
case 202:
#line 862 "ntp_parser.y"
{ yyval.Double = yyvsp[0].Double; }
    break;
case 203:
#line 871 "ntp_parser.y"
{
                 my_config.sim_details = create_sim_node(yyvsp[-2].Queue, yyvsp[-1].Queue);

                 /* Reset the old_config_style variable */
                 old_config_style = 1;
             }
    break;
case 204:
#line 885 "ntp_parser.y"
{ old_config_style = 0; }
    break;
case 205:
#line 889 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-2].Queue, yyvsp[-1].Attr_val); }
    break;
case 206:
#line 890 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[-1].Attr_val); }
    break;
case 207:
#line 894 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(T_Beep_Delay, yyvsp[0].Double); }
    break;
case 208:
#line 895 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(T_Sim_Duration, yyvsp[0].Double); }
    break;
case 209:
#line 899 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Sim_server); }
    break;
case 210:
#line 900 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Sim_server); }
    break;
case 211:
#line 905 "ntp_parser.y"
{ yyval.Sim_server = create_sim_server(yyvsp[-4].Address_node, yyvsp[-2].Double, yyvsp[-1].Queue); }
    break;
case 212:
#line 909 "ntp_parser.y"
{ yyval.Double = yyvsp[-1].Double; }
    break;
case 213:
#line 913 "ntp_parser.y"
{ yyval.Address_node = yyvsp[0].Address_node; }
    break;
case 214:
#line 917 "ntp_parser.y"
{ yyval.Address_node = yyvsp[0].Address_node; }
    break;
case 215:
#line 918 "ntp_parser.y"
{ yyval.Address_node = create_address_node(yyvsp[0].String, T_String); }
    break;
case 216:
#line 922 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-1].Queue, yyvsp[0].Sim_script); }
    break;
case 217:
#line 923 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[0].Sim_script); }
    break;
case 218:
#line 928 "ntp_parser.y"
{ yyval.Sim_script = create_sim_script_info(yyvsp[-3].Double, yyvsp[-1].Queue); }
    break;
case 219:
#line 932 "ntp_parser.y"
{ yyval.Queue = enqueue(yyvsp[-2].Queue, yyvsp[-1].Attr_val); }
    break;
case 220:
#line 933 "ntp_parser.y"
{ yyval.Queue = enqueue_in_new_queue(yyvsp[-1].Attr_val); }
    break;
case 221:
#line 938 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(T_Freq_Offset, yyvsp[0].Double); }
    break;
case 222:
#line 940 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(T_Wander, yyvsp[0].Double); }
    break;
case 223:
#line 942 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(T_Jitter, yyvsp[0].Double); }
    break;
case 224:
#line 944 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(T_Prop_Delay, yyvsp[0].Double); }
    break;
case 225:
#line 946 "ntp_parser.y"
{ yyval.Attr_val = create_attr_dval(T_Proc_Delay, yyvsp[0].Double); }
    break;
}

#line 705 "/usr/local/gnu/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 950 "ntp_parser.y"


/* KEYWORDS
 * --------
 */

void yyerror (char *msg)
{
    int retval;
    if (input_from_file)
        fprintf(stderr, "%s\n", msg);
    else {
        /* Save the error message in the correct buffer */
        retval = snprintf(remote_config.err_msg + remote_config.err_pos, 
                          MAXLINE - remote_config.err_pos, 
                          "%s\n", msg);

        /* Increment the value of err_pos */
        if (retval > 0)
            remote_config.err_pos += retval;
        
        /* Increment the number of errors */
        ++remote_config.no_errors;
    }
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

