/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 51 "ntp_parser.y" /* yacc.c:1909  */

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

#line 471 "ntp_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NTP_PARSER_H_INCLUDED  */
