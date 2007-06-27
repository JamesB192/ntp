/*
 * ntp_util.c - stuff I didn't have any other place for
 */
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "ntpd.h"
#include "ntp_io.h"
#include "ntp_unixtime.h"
#include "ntp_filegen.h"
#include "ntp_if.h"
#include "ntp_stdlib.h"
#include "ntp_assert.h"

#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#ifdef HAVE_SYS_IOCTL_H
# include <sys/ioctl.h>
#endif

#ifdef HAVE_IEEEFP_H
# include <ieeefp.h>
#endif
#ifdef HAVE_MATH_H
# include <math.h>
#endif

#ifdef  DOSYNCTODR
# if !defined(VMS)
#  include <sys/resource.h>
# endif /* VMS */
#endif

#if defined(VMS)
# include <descrip.h>
#endif /* VMS */

/*
 * Defines used by the leapseconds stuff
 */
#define	MAX_TAI	100			/* max TAI offset (s) */
#define	L_DAY	86400UL			/* seconds per day */
#define	L_YEAR	(L_DAY * 365)		/* days per year */
#define	L_LYEAR	(L_YEAR + L_DAY)	/* days per leap year */
#define	L_4YEAR	(L_LYEAR + 3 * L_YEAR)	/* days per leap cycle */
#define	L_CENT	(L_4YEAR * 25)		/* days per century */

/*
 * This contains odds and ends, including the hourly stats, various
 * configuration items, leapseconds stuff, etc.
 */
/*
 * File names
 */
static	char *key_file_name;		/* keys file name */
char	*leapseconds_file_name;		/* leapseconds file name */
char	*stats_drift_file;		/* frequency file name */
static	char *stats_temp_file;		/* temp frequency file name */
int stats_write_period = 3600;		/* seconds between writes. */

/*
 * Statistics file stuff
 */
#ifndef NTP_VAR
# ifndef SYS_WINNT
#  define NTP_VAR "/var/NTP/"		/* NOTE the trailing '/' */
# else
#  define NTP_VAR "c:\\var\\ntp\\"	/* NOTE the trailing '\\' */
# endif /* SYS_WINNT */
#endif

#ifndef MAXPATHLEN
# define MAXPATHLEN 256
#endif

#ifdef DEBUG_TIMING
static FILEGEN timingstats;
#endif
#ifdef OPENSSL
static FILEGEN cryptostats;
#endif /* OPENSSL */

static	char statsdir[MAXPATHLEN] = NTP_VAR;
static FILEGEN peerstats;
static FILEGEN loopstats;
static FILEGEN clockstats;
static FILEGEN rawstats;
static FILEGEN sysstats;

/*
 * This controls whether stats are written to the fileset. Provided
 * so that ntpdc can turn off stats when the file system fills up. 
 */
int stats_control;

/*
 * Initial frequency offset later passed to the loopfilter.
 */
double	old_drift;			/* current frequency */
static double prev_drift_comp;		/* last frequency update */

/*
 * Static prototypes
 */
static void leap_file(char *);

/*
 * init_util - initialize the utilities
 */
void
init_util(void)
{
	stats_drift_file = 0;
	stats_temp_file = 0;
	key_file_name = 0;
	filegen_register(&statsdir[0], "peerstats", &peerstats);
	filegen_register(&statsdir[0], "loopstats", &loopstats);
	filegen_register(&statsdir[0], "clockstats", &clockstats);
	filegen_register(&statsdir[0], "rawstats", &rawstats);
	filegen_register(&statsdir[0], "sysstats", &sysstats);
#ifdef OPENSSL
	filegen_register(&statsdir[0], "cryptostats", &cryptostats);
#endif /* OPENSSL */
#ifdef DEBUG_TIMING
	filegen_register(&statsdir[0], "timingstats", &timingstats);
#endif /* DEBUG_TIMING */

leap_file("/etc/ntp.leap");	/***** temp for debug *****/

}


/*
 * hourly_stats - print some interesting stats
 */
void
write_stats(void)
{
	FILE	*fp;
	double	ftemp;


#ifdef DOSYNCTODR
	struct timeval tv;
#if !defined(VMS)
	int	prio_set;
#endif
#ifdef HAVE_GETCLOCK
        struct timespec ts;
#endif
	int	o_prio;

	/*
	 * Sometimes having a Sun can be a drag.
	 *
	 * The kernel variable dosynctodr controls whether the system's
	 * soft clock is kept in sync with the battery clock. If it
	 * is zero, then the soft clock is not synced, and the battery
	 * clock is simply left to rot. That means that when the system
	 * reboots, the battery clock (which has probably gone wacky)
	 * sets the soft clock. That means ntpd starts off with a very
	 * confused idea of what time it is. It then takes a large
	 * amount of time to figure out just how wacky the battery clock
	 * has made things drift, etc, etc. The solution is to make the
	 * battery clock sync up to system time. The way to do THAT is
	 * to simply set the time of day to the current time of day, but
	 * as quickly as possible. This may, or may not be a sensible
	 * thing to do.
	 *
	 * CAVEAT: settimeofday() steps the sun clock by about 800 us,
	 *         so setting DOSYNCTODR seems a bad idea in the
	 *         case of us resolution
	 */

#if !defined(VMS)
	/*
	 * (prr) getpriority returns -1 on error, but -1 is also a valid
	 * return value (!), so instead we have to zero errno before the
	 * call and check it for non-zero afterwards.
	 */
	errno = 0;
	prio_set = 0;
	o_prio = getpriority(PRIO_PROCESS,0); /* Save setting */

	/*
	 * (prr) if getpriority succeeded, call setpriority to raise
	 * scheduling priority as high as possible.  If that succeeds
	 * as well, set the prio_set flag so we remember to reset
	 * priority to its previous value below.  Note that on Solaris
	 * 2.6 (and beyond?), both getpriority and setpriority will fail
	 * with ESRCH, because sched_setscheduler (called from main) put
	 * us in the real-time scheduling class which setpriority
	 * doesn't know about. Being in the real-time class is better
	 * than anything setpriority can do, anyhow, so this error is
	 * silently ignored.
	 */
	if ((errno == 0) && (setpriority(PRIO_PROCESS,0,-20) == 0))
		prio_set = 1;	/* overdrive */
#endif /* VMS */
#ifdef HAVE_GETCLOCK
        (void) getclock(TIMEOFDAY, &ts);
        tv.tv_sec = ts.tv_sec;
        tv.tv_usec = ts.tv_nsec / 1000;
#else /*  not HAVE_GETCLOCK */
	GETTIMEOFDAY(&tv,(struct timezone *)NULL);
#endif /* not HAVE_GETCLOCK */
	if (ntp_set_tod(&tv,(struct timezone *)NULL) != 0)
		msyslog(LOG_ERR, "can't sync battery time: %m");
#if !defined(VMS)
	if (prio_set)
		setpriority(PRIO_PROCESS, 0, o_prio); /* downshift */
#endif /* VMS */
#endif /* DOSYNCTODR */

	NLOG(NLOG_SYSSTATIST)
		msyslog(LOG_INFO,
		    "offset %.6f sec freq %.3f ppm error %.6f poll %d",
		    last_offset, drift_comp * 1e6, sys_jitter,
		    sys_poll);

	record_sys_stats();
	ftemp = fabs(prev_drift_comp - drift_comp); 
	prev_drift_comp = drift_comp;
	if (ftemp > clock_phi)
		return;

	if (stats_drift_file != 0) {
		if (state == 4) {
			if ((fp = fopen(stats_temp_file, "w")) == NULL)
			    {
				msyslog(LOG_ERR, "can't open %s: %m",
				    stats_temp_file);
				return;
			}
			fprintf(fp, "%.3f\n", drift_comp * 1e6);
			(void)fclose(fp);
			/* atomic */
#ifdef SYS_WINNT
			(void) _unlink(stats_drift_file); /* rename semantics differ under NT */
#endif /* SYS_WINNT */

#ifndef NO_RENAME
			(void) rename(stats_temp_file, stats_drift_file);
#else
			/* we have no rename NFS of ftp in use */
			if ((fp = fopen(stats_drift_file, "w")) == NULL)
			    {
				msyslog(LOG_ERR, "can't open %s: %m",
				    stats_drift_file);
				return;
			}
#endif

#if defined(VMS)
			/* PURGE */
			{
				$DESCRIPTOR(oldvers,";-1");
				struct dsc$descriptor driftdsc = {
					strlen(stats_drift_file), 0, 0,
					    stats_drift_file };
				while(lib$delete_file(&oldvers,
				    &driftdsc) & 1);
			}
#endif
		} else {
			/* XXX: Log a message at INFO level */
		}
	}
}


/*
 * stats_config - configure the stats operation
 */
void
stats_config(
	int item,
	const char *invalue	/* only one type so far */
	)
{
	FILE *fp;
	const char *value;
	int len;

	/*
	 * Expand environment strings under Windows NT, since the
	 * command interpreter doesn't do this, the program must.
	 */
#ifdef SYS_WINNT
	char newvalue[MAX_PATH], parameter[MAX_PATH];

	if (!ExpandEnvironmentStrings(invalue, newvalue, MAX_PATH)) {
 		switch(item) {
		    case STATS_FREQ_FILE:
			strcpy(parameter,"STATS_FREQ_FILE");
			break;

		    case STATS_LEAP_FILE:
			strcpy(parameter,"STATS_LEAP_FILE");
			break;

		    case STATS_STATSDIR:
			strcpy(parameter,"STATS_STATSDIR");
			break;

		    case STATS_PID_FILE:
			strcpy(parameter,"STATS_PID_FILE");
			break;

		    default:
			strcpy(parameter,"UNKNOWN");
			break;
		}
		value = invalue;
		msyslog(LOG_ERR,
		    "ExpandEnvironmentStrings(%s) failed: %m\n",
		    parameter);
	} else {
		value = newvalue;
	}
#else    
	value = invalue;
#endif /* SYS_WINNT */

	switch(item) {
	    case STATS_FREQ_FILE:
		if (stats_drift_file != 0) {
			(void) free(stats_drift_file);
			(void) free(stats_temp_file);
			stats_drift_file = 0;
			stats_temp_file = 0;
		}

		if (value == 0 || (len = strlen(value)) == 0)
		    break;

		stats_drift_file = (char*)emalloc((u_int)(len + 1));
#if !defined(VMS)
		stats_temp_file = (char*)emalloc((u_int)(len +
		    sizeof(".TEMP")));
#else
		stats_temp_file = (char*)emalloc((u_int)(len +
		    sizeof("-TEMP")));
#endif /* VMS */
		memmove(stats_drift_file, value, (unsigned)(len+1));
		memmove(stats_temp_file, value, (unsigned)len);
#if !defined(VMS)
		memmove(stats_temp_file + len, ".TEMP",
		    sizeof(".TEMP"));
#else
		memmove(stats_temp_file + len, "-TEMP",
		    sizeof("-TEMP"));
#endif /* VMS */

		/*
		 * Open drift file and read frequency. If the file is
		 * missing or contains errors, tell the loop to reset.
		 */
		if ((fp = fopen(stats_drift_file, "r")) == NULL) {
			old_drift = 1e9;
			break;
		}
		if (fscanf(fp, "%lf", &old_drift) != 1) {
			msyslog(LOG_ERR, "Frequency format error in %s", 
			    stats_drift_file);
			old_drift = 1e9;
			fclose(fp);
			break;

		}
		fclose(fp);
		old_drift /= 1e6;
		prev_drift_comp = old_drift;
		msyslog(LOG_INFO,
		    "frequency initialized %.3f PPM from %s",
			old_drift * 1e6, stats_drift_file);

		leap_file("/etc/ntp.leap");

		break;
	
	    case STATS_STATSDIR:

		/*
		 * HMS: the following test is insufficient:
		 * - value may be missing the DIR_SEP
		 * - we still need the filename after it
		 */
		if (strlen(value) >= sizeof(statsdir)) {
			msyslog(LOG_ERR,
			    "value for statsdir too long (>%d, sigh)",
			    (int)sizeof(statsdir) - 1);
		} else {
			l_fp now;
			int add_dir_sep;
			int value_l = strlen(value);

			/* Add a DIR_SEP unless we already have one. */
			if (value_l == 0)
				add_dir_sep = 0;
			else
				add_dir_sep = (DIR_SEP ==
				    value[value_l - 1]);

			if (add_dir_sep)
			    snprintf(statsdir, sizeof(statsdir),
				"%s%c", value, DIR_SEP);
			else
			    snprintf(statsdir, sizeof(statsdir),
				"%s", value);

			get_systime(&now);
			if(peerstats.prefix == &statsdir[0] &&
			    peerstats.fp != NULL) {
				fclose(peerstats.fp);
				peerstats.fp = NULL;
				filegen_setup(&peerstats, now.l_ui);
			}
			if(loopstats.prefix == &statsdir[0] &&
			    loopstats.fp != NULL) {
				fclose(loopstats.fp);
				loopstats.fp = NULL;
				filegen_setup(&loopstats, now.l_ui);
			}
			if(clockstats.prefix == &statsdir[0] &&
			    clockstats.fp != NULL) {
				fclose(clockstats.fp);
				clockstats.fp = NULL;
				filegen_setup(&clockstats, now.l_ui);
			}
			if(rawstats.prefix == &statsdir[0] &&
			    rawstats.fp != NULL) {
				fclose(rawstats.fp);
				rawstats.fp = NULL;
				filegen_setup(&rawstats, now.l_ui);
			}
			if(sysstats.prefix == &statsdir[0] &&
			    sysstats.fp != NULL) {
				fclose(sysstats.fp);
				sysstats.fp = NULL;
				filegen_setup(&sysstats, now.l_ui);
			}
#ifdef OPENSSL
			if(cryptostats.prefix == &statsdir[0] &&
			    cryptostats.fp != NULL) {
				fclose(cryptostats.fp);
				cryptostats.fp = NULL;
				filegen_setup(&cryptostats, now.l_ui);
			}
#endif /* OPENSSL */
		}
		break;

	    case STATS_PID_FILE:
		if ((fp = fopen(value, "w")) == NULL) {
			msyslog(LOG_ERR, "Can't open %s: %m", value);
			break;
		}
		fprintf(fp, "%d", (int) getpid());
		fclose(fp);;
		break;

	    case STATS_LEAP_FILE:
		leapseconds_file_name = invalue;
		break;

	    default:
		/* oh well */
		break;
	}
}


/*
 * record_peer_stats - write peer statistics to file
 *
 * file format:
 * day (mjd)
 * time (s past UTC midnight)
 * peer (ip address)
 * peer status word (hex)
 * peer offset (s)
 * peer delay (s)
 * peer error bound (s)
 * peer error (s)
*/
void
record_peer_stats(
	struct sockaddr_storage *addr,
	int	status,
	double	offset,
	double	delay,
	double	dispersion,
	double	skew
	)
{
	l_fp	now;
	u_long	day;

	if (!stats_control)
		return;

	get_systime(&now);
	filegen_setup(&peerstats, now.l_ui);
	day = now.l_ui / 86400 + MJD_1900;
	now.l_ui %= 86400;
	if (peerstats.fp != NULL) {
		fprintf(peerstats.fp,
		    "%lu %s %s %x %.9f %.9f %.9f %.9f\n", day,
		    ulfptoa(&now, 3), stoa(addr), status, offset,
		    delay, dispersion, skew);
		fflush(peerstats.fp);
	}
}


/*
 * record_loop_stats - write loop filter statistics to file
 *
 * file format:
 * day (mjd)
 * time (s past midnight)
 * offset (s)
 * frequency (approx ppm)
 * time constant (log base 2)
 */
void
record_loop_stats(
	double	offset,
	double	freq,
	double	jitter,
	double	stability,
	int spoll
	)
{
	l_fp	now;
	u_long	day;

	if (!stats_control)
		return;

	get_systime(&now);
	filegen_setup(&loopstats, now.l_ui);
	day = now.l_ui / 86400 + MJD_1900;
	now.l_ui %= 86400;
	if (loopstats.fp != NULL) {
		fprintf(loopstats.fp, "%lu %s %.9f %.3f %.9f %.6f %d\n",
		    day, ulfptoa(&now, 3), offset, freq * 1e6, jitter,
		    stability * 1e6, spoll);
		fflush(loopstats.fp);
	}
}


/*
 * record_clock_stats - write clock statistics to file
 *
 * file format:
 * day (mjd)
 * time (s past midnight)
 * peer (ip address)
 * text message
 */
void
record_clock_stats(
	struct sockaddr_storage *addr,
	const char *text
	)
{
	l_fp	now;
	u_long	day;

	if (!stats_control)
		return;

	get_systime(&now);
	filegen_setup(&clockstats, now.l_ui);
	day = now.l_ui / 86400 + MJD_1900;
	now.l_ui %= 86400;
	if (clockstats.fp != NULL) {
		fprintf(clockstats.fp, "%lu %s %s %s\n", day,
		    ulfptoa(&now, 3), stoa(addr), text);
		fflush(clockstats.fp);
	}
}


/*
 * record_raw_stats - write raw timestamps to file
 *
 * file format
 * time (s past midnight)
 * peer ip address
 * local ip address
 * t1 t2 t3 t4 timestamps
 */
void
record_raw_stats(
        struct sockaddr_storage *srcadr,
        struct sockaddr_storage *dstadr,
	l_fp	*t1,
	l_fp	*t2,
	l_fp	*t3,
	l_fp	*t4
	)
{
	l_fp	now;
	u_long	day;

	if (!stats_control)
		return;

	get_systime(&now);
	filegen_setup(&rawstats, now.l_ui);
	day = now.l_ui / 86400 + MJD_1900;
	now.l_ui %= 86400;
	if (rawstats.fp != NULL) {
                fprintf(rawstats.fp, "%lu %s %s %s %s %s %s %s\n", day,
		    ulfptoa(&now, 3), stoa(srcadr), dstadr ? 
		    stoa(dstadr) : "-",	ulfptoa(t1, 9), ulfptoa(t2, 9),
		    ulfptoa(t3, 9), ulfptoa(t4, 9));
		fflush(rawstats.fp);
	}
}


/*
 * record_sys_stats - write system statistics to file
 *
 * file format
 * time (s past midnight)
 * time since startup (hr)
 * packets recieved
 * packets processed
 * current version
 * previous version
 * bad version
 * access denied
 * bad length or format
 * bad authentication
 * rate exceeded
 */
void
record_sys_stats(void)
{
	l_fp	now;
	u_long	day;

	if (!stats_control)
		return;

	get_systime(&now);
	filegen_setup(&sysstats, now.l_ui);
	day = now.l_ui / 86400 + MJD_1900;
	now.l_ui %= 86400;
	if (sysstats.fp != NULL) {
                fprintf(sysstats.fp,
		    "%lu %s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu\n",
		    day, ulfptoa(&now, 3), sys_stattime / 3600,
		    sys_received, sys_processed, sys_newversionpkt,
		    sys_oldversionpkt, sys_unknownversion,
		    sys_restricted, sys_badlength, sys_badauth,
		    sys_limitrejected);
		fflush(sysstats.fp);
		proto_clr_stats();
	}
}


#ifdef OPENSSL
/*
 * record_crypto_stats - write crypto statistics to file
 *
 * file format:
 * day (mjd)
 * time (s past midnight)
 * peer (ip address)
 * text message
 */
void
record_crypto_stats(
	struct sockaddr_storage *addr,
	const char *text
	)
{
	l_fp	now;
	u_long	day;

	if (!stats_control)
		return;

	get_systime(&now);
	filegen_setup(&cryptostats, now.l_ui);
	day = now.l_ui / 86400 + MJD_1900;
	now.l_ui %= 86400;
	if (cryptostats.fp != NULL) {
		if (addr == NULL)
			fprintf(cryptostats.fp, "%lu %s %s\n",
			    day, ulfptoa(&now, 3), text);
		else
			fprintf(cryptostats.fp, "%lu %s %s %s\n",
			    day, ulfptoa(&now, 3), stoa(addr), text);
		fflush(cryptostats.fp);
	}
}
#endif /* OPENSSL */


#ifdef DEBUG_TIMING
/*
 * record_timing_stats - write timing statistics to file
 *
 * file format:
 * day (mjd)
 * time (s past midnight)
 * text message
 */
void
record_timing_stats(
	const char *text
	)
{
	static unsigned int flshcnt;
	l_fp	now;
	u_long	day;

	if (!stats_control)
		return;

	get_systime(&now);
	filegen_setup(&timingstats, now.l_ui);
	day = now.l_ui / 86400 + MJD_1900;
	now.l_ui %= 86400;
	if (timingstats.fp != NULL) {
		fprintf(timingstats.fp, "%lu %s %s\n", day, lfptoa(&now,
		    3), text);
		if (++flshcnt % 100 == 0)
			fflush(timingstats.fp);
	}
}
#endif


/*
 * leap_file - read leapseconds file
 *
 * Read the ERTS leapsecond file in NIST text format and extract the
 * NTP seconds of the latest leap and TAI offset after the leap.
 */
static void
leap_file(
	char	*cp		/* file name */
	)
{
	FILE	*str;		/* file handle */
	char	buf[NTP_MAXSTRLEN];	/* file line buffer */
	u_long	leapsec;	/* NTP time at leap */
	u_long	expire;		/* NTP time when file expires */
	int	offset;		/* TAI offset at leap (s) */
	char	filename[MAXFILENAME]; /* name of leapseconds file */
	char	*dp;
	int	i;

	NTP_REQUIRE(cp != NULL);

	/*
	 * Open the file and discard comment lines. If the first
	 * character of the file name is not '/', prepend the keys
	 * directory string. If the file is not found, ignore; if found
	 * with errors, report to the log and ignore.
	 */
	if (*cp == '/')
		strcpy(filename, cp);
	else
		snprintf(filename, MAXFILENAME, "%s/%s", keysdir, cp);
	if ((str = fopen(filename, "r")) == NULL)
		return;

	/*
	 * Read and parse the leapseconds file. Empty lines and comments
	 * are ignored. Other lines must begin with two integers
	 * followed by junk or comments. The first integer is the NTP
	 * seconds at the leap, the second is the TAI offset after the
	 * leap. The second word must equal the initial insertion of ten
	 * seconds on 1 January 1972 plus one second for each succeeding
	 * insertion.
	 */
	i = TAI_1972;
	expire = 0;
	while (i < MAX_TAI) {
		dp = fgets(buf, NTP_MAXSTRLEN - 1, str);
		if (dp == NULL)
			break;

		if (strlen(buf) < 1)
			continue;

		if (buf[0] == '#') {
			if (buf[1] == '@') {
				if (sscanf(&buf[2], "%lu", &expire) !=
				    1)
					break;
			}
		}
		continue;

		if (sscanf(buf, "%lu %d", &leapsec, &offset) != 2)
			continue;

		if (i != offset) 
			break;
		i++;
	}
	fclose(str);
	if (dp != NULL) {
		msyslog(LOG_INFO, "leapseconds %s error",  cp);
	} else {
		sys_tai = offset;
		leap_ins = leapsec;
		leap_expire = expire;
		msyslog(LOG_INFO,
		    "TAI offset %d s at %lu file %s expire %lu",
		    sys_tai, leap_ins, cp, leap_expire);
	}
}


/*
 * leap_month - returns seconds until the end of the month.
 */
u_long
leap_month(
	u_long	sec		/* current NTP second */
	)
{
	u_long	ltemp;
	u_long	*ptr;
	u_long	year[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
		    31}; 
	u_long	lyear[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30,
		    31}; 

	/*
	 * Find current leap cycle.
	 */
	ltemp = sec;
	while (ltemp >= L_CENT)
		ltemp -= L_CENT;
	while (ltemp >= L_4YEAR)
		ltemp -= L_4YEAR;

	/*
	 * We are within four years of the target. If in leap year, use
	 * leap year month table; otherwise, use year month table.
	 */
	if (ltemp < L_LYEAR) {
		ptr = lyear;
	} else {
		ptr = year;
		ltemp -= L_LYEAR;
		while (ltemp >= L_YEAR)
			ltemp -= L_YEAR;
	}

	/*
	 * We are within one year of the target. Find the month of the
	 * leap.
	 */
	while (ltemp >= *ptr * L_DAY)
		ltemp -= *ptr++ * L_DAY;

	/*
	 * The result is the number of seconds until the end of the
	 * month when the leap is to occur.
	 */
	return (*ptr * L_DAY - ltemp - L_DAY);
}


/*
 * getauthkeys - read the authentication keys from the specified file
 */
void
getauthkeys(
	const char *keyfile
	)
{
	int len;

	len = strlen(keyfile);
	if (len == 0)
		return;
	
	if (key_file_name != 0) {
		if (len > (int)strlen(key_file_name)) {
			(void) free(key_file_name);
			key_file_name = 0;
		}
	}

	if (key_file_name == 0) {
#ifndef SYS_WINNT
		key_file_name = (char*)emalloc((u_int) (len + 1));
#else
		key_file_name = (char*)emalloc((u_int)  (MAXPATHLEN));
#endif
	}
#ifndef SYS_WINNT
 	memmove(key_file_name, keyfile, (unsigned)(len+1));
#else
	if (!ExpandEnvironmentStrings(keyfile, key_file_name,
	    MAXPATHLEN)) {
		msyslog(LOG_ERR,
		    "ExpandEnvironmentStrings(KEY_FILE) failed: %m\n");
	}
#endif /* SYS_WINNT */
	authreadkeys(key_file_name);
}


/*
 * rereadkeys - read the authentication key file over again.
 */
void
rereadkeys(void)
{
	if (key_file_name != 0)
	    authreadkeys(key_file_name);
}


/*
 * sock_hash - hash an sockaddr_storage structure
 */
int
sock_hash(
	struct sockaddr_storage *addr
	)
{
	int hashVal;
	int i;
	int len;
	char *ch;
	hashVal = 0;
	len = 0;

	/*
	 * We can't just hash the whole thing because there are hidden
	 * fields in sockaddr_in6 that might be filled in by recvfrom(),
	 * so just use the family, port and address.
	 */
	ch = (char *)&addr->ss_family;
	hashVal = 37 * hashVal + (int)*ch;
	if (sizeof(addr->ss_family) > 1) {
		ch++;
		hashVal = 37 * hashVal + (int)*ch;
	}
	switch(addr->ss_family) {
	case AF_INET:
		ch = (char *)&((struct sockaddr_in *)addr)->sin_addr;
		len = sizeof(struct in_addr);
		break;

	case AF_INET6:
		ch = (char *)&((struct sockaddr_in6 *)addr)->sin6_addr;
		len = sizeof(struct in6_addr);
		break;
	}

	for (i = 0; i < len ; i++)
		hashVal = 37 * hashVal + (int)*(ch + i);
	hashVal = hashVal % 128;  /* % MON_HASH_SIZE hardcoded */
	if (hashVal < 0)
		hashVal += 128;
	return hashVal;
}


#if notyet
/*
 * ntp_exit - document explicitly that ntpd has exited
 */
void
ntp_exit(int retval)
{
	msyslog(LOG_ERR, "EXITING with return code %d", retval);
	exit(retval);
}
#endif
