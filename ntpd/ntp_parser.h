/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    T_Bclient = 267,
    T_Beacon = 268,
    T_Broadcast = 269,
    T_Broadcastclient = 270,
    T_Broadcastdelay = 271,
    T_Burst = 272,
    T_Calibrate = 273,
    T_Ceiling = 274,
    T_Clockstats = 275,
    T_Cohort = 276,
    T_ControlKey = 277,
    T_Crypto = 278,
    T_Cryptostats = 279,
    T_Ctl = 280,
    T_Day = 281,
    T_Default = 282,
    T_Digest = 283,
    T_Disable = 284,
    T_Discard = 285,
    T_Dispersion = 286,
    T_Double = 287,
    T_Driftfile = 288,
    T_Drop = 289,
    T_Ellipsis = 290,
    T_Enable = 291,
    T_End = 292,
    T_False = 293,
    T_File = 294,
    T_Filegen = 295,
    T_Filenum = 296,
    T_Flag1 = 297,
    T_Flag2 = 298,
    T_Flag3 = 299,
    T_Flag4 = 300,
    T_Flake = 301,
    T_Floor = 302,
    T_Freq = 303,
    T_Fudge = 304,
    T_Host = 305,
    T_Huffpuff = 306,
    T_Iburst = 307,
    T_Ident = 308,
    T_Ignore = 309,
    T_Incalloc = 310,
    T_Incmem = 311,
    T_Initalloc = 312,
    T_Initmem = 313,
    T_Includefile = 314,
    T_Integer = 315,
    T_Interface = 316,
    T_Intrange = 317,
    T_Io = 318,
    T_Ipv4 = 319,
    T_Ipv4_flag = 320,
    T_Ipv6 = 321,
    T_Ipv6_flag = 322,
    T_Kernel = 323,
    T_Key = 324,
    T_Keys = 325,
    T_Keysdir = 326,
    T_Kod = 327,
    T_Mssntp = 328,
    T_Leapfile = 329,
    T_Limited = 330,
    T_Link = 331,
    T_Listen = 332,
    T_Logconfig = 333,
    T_Logfile = 334,
    T_Loopstats = 335,
    T_Lowpriotrap = 336,
    T_Manycastclient = 337,
    T_Manycastserver = 338,
    T_Mask = 339,
    T_Maxage = 340,
    T_Maxclock = 341,
    T_Maxdepth = 342,
    T_Maxdist = 343,
    T_Maxmem = 344,
    T_Maxpoll = 345,
    T_Mdnstries = 346,
    T_Mem = 347,
    T_Memlock = 348,
    T_Minclock = 349,
    T_Mindepth = 350,
    T_Mindist = 351,
    T_Minimum = 352,
    T_Minpoll = 353,
    T_Minsane = 354,
    T_Mode = 355,
    T_Mode7 = 356,
    T_Monitor = 357,
    T_Month = 358,
    T_Mru = 359,
    T_Multicastclient = 360,
    T_Nic = 361,
    T_Nolink = 362,
    T_Nomodify = 363,
    T_Nomrulist = 364,
    T_None = 365,
    T_Nonvolatile = 366,
    T_Nopeer = 367,
    T_Noquery = 368,
    T_Noselect = 369,
    T_Noserve = 370,
    T_Notrap = 371,
    T_Notrust = 372,
    T_Ntp = 373,
    T_Ntpport = 374,
    T_NtpSignDsocket = 375,
    T_Orphan = 376,
    T_Orphanwait = 377,
    T_Panic = 378,
    T_Peer = 379,
    T_Peerstats = 380,
    T_Phone = 381,
    T_Pid = 382,
    T_Pidfile = 383,
    T_Pool = 384,
    T_Port = 385,
    T_Preempt = 386,
    T_Prefer = 387,
    T_Protostats = 388,
    T_Pw = 389,
    T_Randfile = 390,
    T_Rawstats = 391,
    T_Refid = 392,
    T_Requestkey = 393,
    T_Reset = 394,
    T_Restrict = 395,
    T_Revoke = 396,
    T_Rlimit = 397,
    T_Saveconfigdir = 398,
    T_Server = 399,
    T_Setvar = 400,
    T_Source = 401,
    T_Stacksize = 402,
    T_Statistics = 403,
    T_Stats = 404,
    T_Statsdir = 405,
    T_Step = 406,
    T_Stepback = 407,
    T_Stepfwd = 408,
    T_Stepout = 409,
    T_Stratum = 410,
    T_String = 411,
    T_Sys = 412,
    T_Sysstats = 413,
    T_Tick = 414,
    T_Time1 = 415,
    T_Time2 = 416,
    T_Timer = 417,
    T_Timingstats = 418,
    T_Tinker = 419,
    T_Tos = 420,
    T_Trap = 421,
    T_True = 422,
    T_Trustedkey = 423,
    T_Ttl = 424,
    T_Type = 425,
    T_U_int = 426,
    T_Unconfig = 427,
    T_Unpeer = 428,
    T_Version = 429,
    T_WanderThreshold = 430,
    T_Week = 431,
    T_Wildcard = 432,
    T_Xleave = 433,
    T_Year = 434,
    T_Flag = 435,
    T_EOC = 436,
    T_Simulate = 437,
    T_Beep_Delay = 438,
    T_Sim_Duration = 439,
    T_Server_Offset = 440,
    T_Duration = 441,
    T_Freq_Offset = 442,
    T_Wander = 443,
    T_Jitter = 444,
    T_Prop_Delay = 445,
    T_Proc_Delay = 446
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
#define T_Bclient 267
#define T_Beacon 268
#define T_Broadcast 269
#define T_Broadcastclient 270
#define T_Broadcastdelay 271
#define T_Burst 272
#define T_Calibrate 273
#define T_Ceiling 274
#define T_Clockstats 275
#define T_Cohort 276
#define T_ControlKey 277
#define T_Crypto 278
#define T_Cryptostats 279
#define T_Ctl 280
#define T_Day 281
#define T_Default 282
#define T_Digest 283
#define T_Disable 284
#define T_Discard 285
#define T_Dispersion 286
#define T_Double 287
#define T_Driftfile 288
#define T_Drop 289
#define T_Ellipsis 290
#define T_Enable 291
#define T_End 292
#define T_False 293
#define T_File 294
#define T_Filegen 295
#define T_Filenum 296
#define T_Flag1 297
#define T_Flag2 298
#define T_Flag3 299
#define T_Flag4 300
#define T_Flake 301
#define T_Floor 302
#define T_Freq 303
#define T_Fudge 304
#define T_Host 305
#define T_Huffpuff 306
#define T_Iburst 307
#define T_Ident 308
#define T_Ignore 309
#define T_Incalloc 310
#define T_Incmem 311
#define T_Initalloc 312
#define T_Initmem 313
#define T_Includefile 314
#define T_Integer 315
#define T_Interface 316
#define T_Intrange 317
#define T_Io 318
#define T_Ipv4 319
#define T_Ipv4_flag 320
#define T_Ipv6 321
#define T_Ipv6_flag 322
#define T_Kernel 323
#define T_Key 324
#define T_Keys 325
#define T_Keysdir 326
#define T_Kod 327
#define T_Mssntp 328
#define T_Leapfile 329
#define T_Limited 330
#define T_Link 331
#define T_Listen 332
#define T_Logconfig 333
#define T_Logfile 334
#define T_Loopstats 335
#define T_Lowpriotrap 336
#define T_Manycastclient 337
#define T_Manycastserver 338
#define T_Mask 339
#define T_Maxage 340
#define T_Maxclock 341
#define T_Maxdepth 342
#define T_Maxdist 343
#define T_Maxmem 344
#define T_Maxpoll 345
#define T_Mdnstries 346
#define T_Mem 347
#define T_Memlock 348
#define T_Minclock 349
#define T_Mindepth 350
#define T_Mindist 351
#define T_Minimum 352
#define T_Minpoll 353
#define T_Minsane 354
#define T_Mode 355
#define T_Mode7 356
#define T_Monitor 357
#define T_Month 358
#define T_Mru 359
#define T_Multicastclient 360
#define T_Nic 361
#define T_Nolink 362
#define T_Nomodify 363
#define T_Nomrulist 364
#define T_None 365
#define T_Nonvolatile 366
#define T_Nopeer 367
#define T_Noquery 368
#define T_Noselect 369
#define T_Noserve 370
#define T_Notrap 371
#define T_Notrust 372
#define T_Ntp 373
#define T_Ntpport 374
#define T_NtpSignDsocket 375
#define T_Orphan 376
#define T_Orphanwait 377
#define T_Panic 378
#define T_Peer 379
#define T_Peerstats 380
#define T_Phone 381
#define T_Pid 382
#define T_Pidfile 383
#define T_Pool 384
#define T_Port 385
#define T_Preempt 386
#define T_Prefer 387
#define T_Protostats 388
#define T_Pw 389
#define T_Randfile 390
#define T_Rawstats 391
#define T_Refid 392
#define T_Requestkey 393
#define T_Reset 394
#define T_Restrict 395
#define T_Revoke 396
#define T_Rlimit 397
#define T_Saveconfigdir 398
#define T_Server 399
#define T_Setvar 400
#define T_Source 401
#define T_Stacksize 402
#define T_Statistics 403
#define T_Stats 404
#define T_Statsdir 405
#define T_Step 406
#define T_Stepback 407
#define T_Stepfwd 408
#define T_Stepout 409
#define T_Stratum 410
#define T_String 411
#define T_Sys 412
#define T_Sysstats 413
#define T_Tick 414
#define T_Time1 415
#define T_Time2 416
#define T_Timer 417
#define T_Timingstats 418
#define T_Tinker 419
#define T_Tos 420
#define T_Trap 421
#define T_True 422
#define T_Trustedkey 423
#define T_Ttl 424
#define T_Type 425
#define T_U_int 426
#define T_Unconfig 427
#define T_Unpeer 428
#define T_Version 429
#define T_WanderThreshold 430
#define T_Week 431
#define T_Wildcard 432
#define T_Xleave 433
#define T_Year 434
#define T_Flag 435
#define T_EOC 436
#define T_Simulate 437
#define T_Beep_Delay 438
#define T_Sim_Duration 439
#define T_Server_Offset 440
#define T_Duration 441
#define T_Freq_Offset 442
#define T_Wander 443
#define T_Jitter 444
#define T_Prop_Delay 445
#define T_Proc_Delay 446

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 54 "ntp_parser.y" /* yacc.c:1909  */

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

#line 455 "ntp_parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (struct FILE_INFO *ip_file);

#endif /* !YY_YY_NTP_PARSER_H_INCLUDED  */
