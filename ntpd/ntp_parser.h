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
#line 51 "../../ntpd/ntp_parser.y" /* yacc.c:1909  */

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

#line 475 "../../ntpd/ntp_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
