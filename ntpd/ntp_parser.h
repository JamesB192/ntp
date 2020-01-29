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

#ifndef YY_YY__NTPD_NTP_PARSER_H_INCLUDED
# define YY_YY__NTPD_NTP_PARSER_H_INCLUDED
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
    T_Checkhash = 277,
    T_Clockstats = 278,
    T_Cohort = 279,
    T_ControlKey = 280,
    T_Crypto = 281,
    T_Cryptostats = 282,
    T_Ctl = 283,
    T_Day = 284,
    T_Default = 285,
    T_Digest = 286,
    T_Disable = 287,
    T_Discard = 288,
    T_Dispersion = 289,
    T_Double = 290,
    T_Driftfile = 291,
    T_Drop = 292,
    T_Dscp = 293,
    T_Ellipsis = 294,
    T_Else = 295,
    T_Enable = 296,
    T_End = 297,
    T_Epeer = 298,
    T_False = 299,
    T_File = 300,
    T_Filegen = 301,
    T_Filenum = 302,
    T_Flag1 = 303,
    T_Flag2 = 304,
    T_Flag3 = 305,
    T_Flag4 = 306,
    T_Flake = 307,
    T_Floor = 308,
    T_Freq = 309,
    T_Fudge = 310,
    T_Fuzz = 311,
    T_Host = 312,
    T_Huffpuff = 313,
    T_Iburst = 314,
    T_Ident = 315,
    T_Ignore = 316,
    T_Ignorehash = 317,
    T_Incalloc = 318,
    T_Incmem = 319,
    T_Initalloc = 320,
    T_Initmem = 321,
    T_Includefile = 322,
    T_Integer = 323,
    T_Interface = 324,
    T_Intrange = 325,
    T_Io = 326,
    T_Ippeerlimit = 327,
    T_Ipv4 = 328,
    T_Ipv4_flag = 329,
    T_Ipv6 = 330,
    T_Ipv6_flag = 331,
    T_Kernel = 332,
    T_Key = 333,
    T_Keys = 334,
    T_Keysdir = 335,
    T_Kod = 336,
    T_Mssntp = 337,
    T_Leapfile = 338,
    T_Leapsmearinterval = 339,
    T_Limited = 340,
    T_Link = 341,
    T_Listen = 342,
    T_Logconfig = 343,
    T_Logfile = 344,
    T_Loopstats = 345,
    T_Lowpriotrap = 346,
    T_Manycastclient = 347,
    T_Manycastserver = 348,
    T_Mask = 349,
    T_Maxage = 350,
    T_Maxclock = 351,
    T_Maxdepth = 352,
    T_Maxdist = 353,
    T_Maxmem = 354,
    T_Maxpoll = 355,
    T_Mdnstries = 356,
    T_Mem = 357,
    T_Memlock = 358,
    T_Minclock = 359,
    T_Mindepth = 360,
    T_Mindist = 361,
    T_Minimum = 362,
    T_Minjitter = 363,
    T_Minpoll = 364,
    T_Minsane = 365,
    T_Mode = 366,
    T_Mode7 = 367,
    T_Monitor = 368,
    T_Month = 369,
    T_Mru = 370,
    T_Multicastclient = 371,
    T_Nic = 372,
    T_Nolink = 373,
    T_Nomodify = 374,
    T_Nomrulist = 375,
    T_None = 376,
    T_Nonvolatile = 377,
    T_Noepeer = 378,
    T_Nopeer = 379,
    T_Noquery = 380,
    T_Noselect = 381,
    T_Noserve = 382,
    T_Notrap = 383,
    T_Notrust = 384,
    T_Ntp = 385,
    T_Ntpport = 386,
    T_NtpSignDsocket = 387,
    T_Orphan = 388,
    T_Orphanwait = 389,
    T_PCEdigest = 390,
    T_Panic = 391,
    T_Peer = 392,
    T_Peerstats = 393,
    T_Phone = 394,
    T_Pid = 395,
    T_Pidfile = 396,
    T_Poll = 397,
    T_Pool = 398,
    T_Port = 399,
    T_Preempt = 400,
    T_Prefer = 401,
    T_Protostats = 402,
    T_Pw = 403,
    T_Randfile = 404,
    T_Randomizepoll = 405,
    T_Randompoll = 406,
    T_Rawstats = 407,
    T_Refid = 408,
    T_Reftime = 409,
    T_Requestkey = 410,
    T_Reset = 411,
    T_Restrict = 412,
    T_Revoke = 413,
    T_Rlimit = 414,
    T_Saveconfigdir = 415,
    T_Server = 416,
    T_ServerFuzzReftime = 417,
    T_Setvar = 418,
    T_Source = 419,
    T_Stacksize = 420,
    T_Statistics = 421,
    T_Stats = 422,
    T_Statsdir = 423,
    T_Step = 424,
    T_Stepback = 425,
    T_Stepfwd = 426,
    T_Stepout = 427,
    T_Stratum = 428,
    T_String = 429,
    T_Sys = 430,
    T_Sysstats = 431,
    T_Tick = 432,
    T_Time1 = 433,
    T_Time2 = 434,
    T_Timer = 435,
    T_Timingstats = 436,
    T_Tinker = 437,
    T_Tos = 438,
    T_Trap = 439,
    T_True = 440,
    T_Trustedkey = 441,
    T_Ttl = 442,
    T_Type = 443,
    T_U_int = 444,
    T_UEcrypto = 445,
    T_UEcryptonak = 446,
    T_UEdigest = 447,
    T_Unconfig = 448,
    T_Unpeer = 449,
    T_Version = 450,
    T_WanderThreshold = 451,
    T_Week = 452,
    T_Wildcard = 453,
    T_Xleave = 454,
    T_Year = 455,
    T_Flag = 456,
    T_EOC = 457,
    T_Simulate = 458,
    T_Beep_Delay = 459,
    T_Sim_Duration = 460,
    T_Server_Offset = 461,
    T_Duration = 462,
    T_Freq_Offset = 463,
    T_Wander = 464,
    T_Jitter = 465,
    T_Prop_Delay = 466,
    T_Proc_Delay = 467
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
#define T_Checkhash 277
#define T_Clockstats 278
#define T_Cohort 279
#define T_ControlKey 280
#define T_Crypto 281
#define T_Cryptostats 282
#define T_Ctl 283
#define T_Day 284
#define T_Default 285
#define T_Digest 286
#define T_Disable 287
#define T_Discard 288
#define T_Dispersion 289
#define T_Double 290
#define T_Driftfile 291
#define T_Drop 292
#define T_Dscp 293
#define T_Ellipsis 294
#define T_Else 295
#define T_Enable 296
#define T_End 297
#define T_Epeer 298
#define T_False 299
#define T_File 300
#define T_Filegen 301
#define T_Filenum 302
#define T_Flag1 303
#define T_Flag2 304
#define T_Flag3 305
#define T_Flag4 306
#define T_Flake 307
#define T_Floor 308
#define T_Freq 309
#define T_Fudge 310
#define T_Fuzz 311
#define T_Host 312
#define T_Huffpuff 313
#define T_Iburst 314
#define T_Ident 315
#define T_Ignore 316
#define T_Ignorehash 317
#define T_Incalloc 318
#define T_Incmem 319
#define T_Initalloc 320
#define T_Initmem 321
#define T_Includefile 322
#define T_Integer 323
#define T_Interface 324
#define T_Intrange 325
#define T_Io 326
#define T_Ippeerlimit 327
#define T_Ipv4 328
#define T_Ipv4_flag 329
#define T_Ipv6 330
#define T_Ipv6_flag 331
#define T_Kernel 332
#define T_Key 333
#define T_Keys 334
#define T_Keysdir 335
#define T_Kod 336
#define T_Mssntp 337
#define T_Leapfile 338
#define T_Leapsmearinterval 339
#define T_Limited 340
#define T_Link 341
#define T_Listen 342
#define T_Logconfig 343
#define T_Logfile 344
#define T_Loopstats 345
#define T_Lowpriotrap 346
#define T_Manycastclient 347
#define T_Manycastserver 348
#define T_Mask 349
#define T_Maxage 350
#define T_Maxclock 351
#define T_Maxdepth 352
#define T_Maxdist 353
#define T_Maxmem 354
#define T_Maxpoll 355
#define T_Mdnstries 356
#define T_Mem 357
#define T_Memlock 358
#define T_Minclock 359
#define T_Mindepth 360
#define T_Mindist 361
#define T_Minimum 362
#define T_Minjitter 363
#define T_Minpoll 364
#define T_Minsane 365
#define T_Mode 366
#define T_Mode7 367
#define T_Monitor 368
#define T_Month 369
#define T_Mru 370
#define T_Multicastclient 371
#define T_Nic 372
#define T_Nolink 373
#define T_Nomodify 374
#define T_Nomrulist 375
#define T_None 376
#define T_Nonvolatile 377
#define T_Noepeer 378
#define T_Nopeer 379
#define T_Noquery 380
#define T_Noselect 381
#define T_Noserve 382
#define T_Notrap 383
#define T_Notrust 384
#define T_Ntp 385
#define T_Ntpport 386
#define T_NtpSignDsocket 387
#define T_Orphan 388
#define T_Orphanwait 389
#define T_PCEdigest 390
#define T_Panic 391
#define T_Peer 392
#define T_Peerstats 393
#define T_Phone 394
#define T_Pid 395
#define T_Pidfile 396
#define T_Poll 397
#define T_Pool 398
#define T_Port 399
#define T_Preempt 400
#define T_Prefer 401
#define T_Protostats 402
#define T_Pw 403
#define T_Randfile 404
#define T_Randomizepoll 405
#define T_Randompoll 406
#define T_Rawstats 407
#define T_Refid 408
#define T_Reftime 409
#define T_Requestkey 410
#define T_Reset 411
#define T_Restrict 412
#define T_Revoke 413
#define T_Rlimit 414
#define T_Saveconfigdir 415
#define T_Server 416
#define T_ServerFuzzReftime 417
#define T_Setvar 418
#define T_Source 419
#define T_Stacksize 420
#define T_Statistics 421
#define T_Stats 422
#define T_Statsdir 423
#define T_Step 424
#define T_Stepback 425
#define T_Stepfwd 426
#define T_Stepout 427
#define T_Stratum 428
#define T_String 429
#define T_Sys 430
#define T_Sysstats 431
#define T_Tick 432
#define T_Time1 433
#define T_Time2 434
#define T_Timer 435
#define T_Timingstats 436
#define T_Tinker 437
#define T_Tos 438
#define T_Trap 439
#define T_True 440
#define T_Trustedkey 441
#define T_Ttl 442
#define T_Type 443
#define T_U_int 444
#define T_UEcrypto 445
#define T_UEcryptonak 446
#define T_UEdigest 447
#define T_Unconfig 448
#define T_Unpeer 449
#define T_Version 450
#define T_WanderThreshold 451
#define T_Week 452
#define T_Wildcard 453
#define T_Xleave 454
#define T_Year 455
#define T_Flag 456
#define T_EOC 457
#define T_Simulate 458
#define T_Beep_Delay 459
#define T_Sim_Duration 460
#define T_Server_Offset 461
#define T_Duration 462
#define T_Freq_Offset 463
#define T_Wander 464
#define T_Jitter 465
#define T_Prop_Delay 466
#define T_Proc_Delay 467

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 52 "../../ntpd/ntp_parser.y" /* yacc.c:1909  */

	char *			String;
	double			Double;
	int			Integer;
	unsigned		U_int;
	gen_fifo *		Generic_fifo;
	attr_val *		Attr_val;
	attr_val_fifo *		Attr_val_fifo;
	int_fifo *		Int_fifo;
	randpoll_node *		Randpoll_node;
	string_fifo *		String_fifo;
	address_node *		Address_node;
	address_fifo *		Address_fifo;
	setvar_node *		Set_var;
	server_info *		Sim_server;
	server_info_fifo *	Sim_server_fifo;
	script_info *		Sim_script;
	script_info_fifo *	Sim_script_fifo;

#line 498 "../../ntpd/ntp_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY__NTPD_NTP_PARSER_H_INCLUDED  */
