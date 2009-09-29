
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
     T_Maxpoll = 332,
     T_Minclock = 333,
     T_Mindist = 334,
     T_Minimum = 335,
     T_Minpoll = 336,
     T_Minsane = 337,
     T_Mode = 338,
     T_Monitor = 339,
     T_Month = 340,
     T_Multicastclient = 341,
     T_Nic = 342,
     T_Nolink = 343,
     T_Nomodify = 344,
     T_None = 345,
     T_Nopeer = 346,
     T_Noquery = 347,
     T_Noselect = 348,
     T_Noserve = 349,
     T_Notrap = 350,
     T_Notrust = 351,
     T_Ntp = 352,
     T_Ntpport = 353,
     T_NtpSignDsocket = 354,
     T_Orphan = 355,
     T_Panic = 356,
     T_Peer = 357,
     T_Peerstats = 358,
     T_Phone = 359,
     T_Pid = 360,
     T_Pidfile = 361,
     T_Pool = 362,
     T_Port = 363,
     T_Preempt = 364,
     T_Prefer = 365,
     T_Protostats = 366,
     T_Pw = 367,
     T_Qos = 368,
     T_Randfile = 369,
     T_Rawstats = 370,
     T_Refid = 371,
     T_Requestkey = 372,
     T_Restrict = 373,
     T_Revoke = 374,
     T_Saveconfigdir = 375,
     T_Server = 376,
     T_Setvar = 377,
     T_Sign = 378,
     T_Statistics = 379,
     T_Stats = 380,
     T_Statsdir = 381,
     T_Step = 382,
     T_Stepout = 383,
     T_Stratum = 384,
     T_String = 385,
     T_Sysstats = 386,
     T_Tick = 387,
     T_Time1 = 388,
     T_Time2 = 389,
     T_Timingstats = 390,
     T_Tinker = 391,
     T_Tos = 392,
     T_Trap = 393,
     T_True = 394,
     T_Trustedkey = 395,
     T_Ttl = 396,
     T_Type = 397,
     T_Unconfig = 398,
     T_Unpeer = 399,
     T_Version = 400,
     T_WanderThreshold = 401,
     T_Week = 402,
     T_Wildcard = 403,
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
#define T_Maxpoll 332
#define T_Minclock 333
#define T_Mindist 334
#define T_Minimum 335
#define T_Minpoll 336
#define T_Minsane 337
#define T_Mode 338
#define T_Monitor 339
#define T_Month 340
#define T_Multicastclient 341
#define T_Nic 342
#define T_Nolink 343
#define T_Nomodify 344
#define T_None 345
#define T_Nopeer 346
#define T_Noquery 347
#define T_Noselect 348
#define T_Noserve 349
#define T_Notrap 350
#define T_Notrust 351
#define T_Ntp 352
#define T_Ntpport 353
#define T_NtpSignDsocket 354
#define T_Orphan 355
#define T_Panic 356
#define T_Peer 357
#define T_Peerstats 358
#define T_Phone 359
#define T_Pid 360
#define T_Pidfile 361
#define T_Pool 362
#define T_Port 363
#define T_Preempt 364
#define T_Prefer 365
#define T_Protostats 366
#define T_Pw 367
#define T_Qos 368
#define T_Randfile 369
#define T_Rawstats 370
#define T_Refid 371
#define T_Requestkey 372
#define T_Restrict 373
#define T_Revoke 374
#define T_Saveconfigdir 375
#define T_Server 376
#define T_Setvar 377
#define T_Sign 378
#define T_Statistics 379
#define T_Stats 380
#define T_Statsdir 381
#define T_Step 382
#define T_Stepout 383
#define T_Stratum 384
#define T_String 385
#define T_Sysstats 386
#define T_Tick 387
#define T_Time1 388
#define T_Time2 389
#define T_Timingstats 390
#define T_Tinker 391
#define T_Tos 392
#define T_Trap 393
#define T_True 394
#define T_Trustedkey 395
#define T_Ttl 396
#define T_Type 397
#define T_Unconfig 398
#define T_Unpeer 399
#define T_Version 400
#define T_WanderThreshold 401
#define T_Week 402
#define T_Wildcard 403
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

/* Line 1676 of yacc.c  */
#line 50 "ntp_parser.y"

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



/* Line 1676 of yacc.c  */
#line 395 "ntp_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


