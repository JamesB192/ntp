/*
 * systime -- routines to fiddle a UNIX clock.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#ifdef HAVE_SYS_PARAM_H
# include <sys/param.h>
#endif
#ifdef HAVE_UTMP_H
# include <utmp.h>
#endif /* HAVE_UTMP_H */
#ifdef HAVE_UTMPX_H
# include <utmpx.h>
#endif /* HAVE_UTMPX_H */

#include "ntp_machine.h"
#include "ntp_fp.h"
#include "ntp_syslog.h"
#include "ntp_unixtime.h"
#include "ntp_stdlib.h"

#if defined SYS_WINNT
#include "ntp_timer.h"
extern DWORD units_per_tick;
static long last_Adj = 0;
#endif

#if defined SCO5_CLOCK
int sco5_oldclock;	/* runtime detection of new clock */
#endif /* SCO5_CLOCK */

#define MAXFREQ 500e-6

/*
 * These routines (init_systime, get_systime, step_systime, adj_systime)
 * implement an interface between the (more or less) system independent
 * bits of NTP and the peculiarities of dealing with the Unix system
 * clock.
 */
double sys_residual = 0;	/* residual from previous adjustment */
double sys_maxfreq = MAXFREQ;	/* max frequency correction */


/*
 * get_systime - return the system time in timestamp format biased by
 * the current time offset.
 */
void
get_systime(
	l_fp *now
	)
{
#if defined(HAVE_CLOCK_GETTIME) || defined(HAVE_GETCLOCK)
	struct timespec ts;
#else
	struct timeval tv;
#endif
	double dtemp;

	/*
	 * We use nanosecond time if we can get it. Watch out for
	 * rounding wiggles, which may overflow the fraction.
	 */
#if defined(HAVE_CLOCK_GETTIME) || defined(HAVE_GETCLOCK)
# ifdef HAVE_CLOCK_GETTIME
	(void) clock_gettime(CLOCK_REALTIME, &ts);
# else
	(void) getclock(TIMEOFDAY, &ts);
# endif
	now->l_i = ts.tv_sec + JAN_1970;
	dtemp = ts.tv_nsec * FRAC / 1e9;
	if (dtemp >= FRAC)
		now->l_i++;
	now->l_uf = (u_int32)dtemp;
#else /* HAVE_CLOCK_GETTIME */
	(void) GETTIMEOFDAY(&tv, (struct timezone *)0);
	now->l_i = tv.tv_sec + JAN_1970;

#if defined(SCO5_CLOCK) || defined(RELIANTUNIX_CLOCK)
#if defined(SCO5_CLOCK)
	if (sco5_oldclock == 1) {
#endif /* SCO5_CLOCK */
		/* fake better than 10ms resolution by interpolating 
	   	accumulated residual (in adj_systime(), see below) */
		dtemp = tv.tv_usec / 1e6;
		if (sys_residual < 5000e-6 && sys_residual > -5000e-6) {
			dtemp += sys_residual;
			if (dtemp < 0) {
				now->l_i--;
				dtemp++;
			}
		}
		dtemp *= FRAC;
#if defined(SCO5_CLOCK)
	}
	else	/* HEY!!! Watch this "else" statement ... */
#endif /* SCO5_CLOCK */
#endif /* SCO5_CLOCK || RELIANTUNIX_CLOCK */
	{	/* HEY!!! See that "else" statement up there??? */
		dtemp = tv.tv_usec * FRAC / 1e6;
	}

	if (dtemp >= FRAC)
		now->l_i++;
	now->l_uf = (u_int32)dtemp;
#endif /* HAVE_CLOCK_GETTIME */

}


/*
 * adj_systime - called once every second to make system time adjustments.
 * Returns 1 if okay, 0 if trouble.
 */
int
adj_systime(
	double now
	)
{
	double dtemp;
	struct timeval adjtv;
	u_char isneg = 0;
#if !defined SYS_WINNT && !defined SYS_CYGWIN32
	struct timeval oadjtv;
#else
	int rc;
   long dwTimeAdjustment;
#endif

	/*
	 * Add the residual from the previous adjustment to the new
	 * adjustment, bound and round.
	 */
	dtemp = sys_residual + now;
	sys_residual = 0;
	if (dtemp < 0) {
		isneg = 1;
		dtemp = -dtemp;
	}

#if defined(SCO5_CLOCK) || defined(RELIANTUNIX_CLOCK)
#if defined(SCO5_CLOCK)
	if (sco5_oldclock == 1) {
#endif /* SCO5_CLOCK */
		/* accumulate changes until we have enough to adjust a tick */
		if (dtemp < 5000e-6) {
			if (isneg) sys_residual = -dtemp;
			else sys_residual = dtemp;
			dtemp = 0;
		}
		else {
			if (isneg) sys_residual = 10000e-6 - dtemp;
			else sys_residual = dtemp - 10000e-6;
			dtemp = 10000e-6;
		}
#if defined(SCO5_CLOCK)
	}
	else {
		if (dtemp > sys_maxfreq)
			dtemp = sys_maxfreq;
	}
#endif /* SCO5_CLOCK */
#else  /* SCO5_CLOCK || RELIANTUNIX_CLOCK */
  	if (dtemp > sys_maxfreq)
  		dtemp = sys_maxfreq;
#endif /* SCO5_CLOCK */

#ifdef SYS_WINNT
	dtemp = dtemp * 1000000.0;
#else
	dtemp = dtemp * 1e6 + .5;
#endif
	if (isneg)
		dtemp = -dtemp;
	adjtv.tv_sec = 0;
	adjtv.tv_usec = (int32)dtemp;

#if defined SYS_WINNT || defined SYS_CYGWIN32	
	/* dtemp is in micro seconds. NT uses 100 ns units,
	 * so a unit change in dwTimeAdjustment corresponds
	 * to slewing 10 ppm. 
	 * Calculate the number of 100ns units to add, 
	 * and leave the remainder in dtemp */
	dwTimeAdjustment = dtemp / 10;
	dtemp +=  (double) -dwTimeAdjustment * 10.0;	
	dwTimeAdjustment += units_per_tick;

	/* only adjust the clock if adjustment changes */
	if (last_Adj != dwTimeAdjustment) { 	
			last_Adj = dwTimeAdjustment;  
# ifdef DEBUG
		if (debug > 1) 
			printf("SetSystemTimeAdjustment( %ld)\n", dwTimeAdjustment);			
# endif
			rc = !SetSystemTimeAdjustment(dwTimeAdjustment, FALSE);
	}
	else rc = 0;
	if (rc)
#else
	/*
	 * Here we do the actual adjustment. If for some reason the adjtime()
	 * call fails, like it is not implemented or something like that,
	 * we honk to the log. If the previous adjustment did not complete,
	 * we correct the residual offset.
	 */
	/* casey - we need a posix type thang here */
	if (adjtime(&adjtv, &oadjtv) < 0)
#endif /* SYS_WINNT */
	{
		msyslog(LOG_ERR, "Can't adjust time: %m");
		return 0;
	} 
	else {
#if !defined (SYS_WINNT) && !defined (SYS_CYGWIN32)
	sys_residual += oadjtv.tv_usec / 1e6;
#else
	sys_residual = dtemp / 1000000.0;
#endif /* SYS_WINNT */
	}
#ifdef DEBUG
	if (debug > 6)
		printf("adj_systime: adj %.9f -> remaining residual %.9f\n", now, sys_residual);
#endif
	return 1;
}


/*
 * step_systime - step the system clock.
 */
int
step_systime(
	double now
	)
{
	struct timeval timetv, adjtv, oldtimetv;
	int isneg = 0;
	double dtemp;
#if defined(HAVE_CLOCK_GETTIME) || defined(HAVE_GETCLOCK)
	struct timespec ts;
#endif

	dtemp = sys_residual + now;
	if (dtemp < 0) {
		isneg = 1;
		dtemp = - dtemp;
		adjtv.tv_sec = (int32)dtemp;
		adjtv.tv_usec = (u_int32)((dtemp - (double)adjtv.tv_sec) *
					  1e6 + .5);
	} else {
		adjtv.tv_sec = (int32)dtemp;
		adjtv.tv_usec = (u_int32)((dtemp - (double)adjtv.tv_sec) *
					  1e6 + .5);
	}
#if defined(HAVE_CLOCK_GETTIME) || defined(HAVE_GETCLOCK)
#ifdef HAVE_CLOCK_GETTIME
	(void) clock_gettime(CLOCK_REALTIME, &ts);
#else
	(void) getclock(TIMEOFDAY, &ts);
#endif
	timetv.tv_sec = ts.tv_sec;
	timetv.tv_usec = ts.tv_nsec / 1000;
#else /*  not HAVE_GETCLOCK */
	(void) GETTIMEOFDAY(&timetv, (struct timezone *)0);
#endif /* not HAVE_GETCLOCK */

	oldtimetv = timetv;

#ifdef DEBUG
	if (debug)
		printf("step_systime: step %.6f residual %.6f\n", now, sys_residual);
#endif
	if (isneg) {
		timetv.tv_sec -= adjtv.tv_sec;
		timetv.tv_usec -= adjtv.tv_usec;
		if (timetv.tv_usec < 0) {
			timetv.tv_sec--;
			timetv.tv_usec += 1000000;
		}
	} else {
		timetv.tv_sec += adjtv.tv_sec;
		timetv.tv_usec += adjtv.tv_usec;
		if (timetv.tv_usec >= 1000000) {
			timetv.tv_sec++;
			timetv.tv_usec -= 1000000;
		}
	}
	if (ntp_set_tod(&timetv, (struct timezone *)0) != 0) {
		msyslog(LOG_ERR, "Can't set time of day: %m");
		return (0);
	}
	sys_residual = 0;

#ifdef NEED_HPUX_ADJTIME
	/*
	 * CHECKME: is this correct when called by ntpdate?????
	 */
	_clear_adjtime();
#endif

	/*
	 * FreeBSD, for example, has:
	 * struct utmp {
	 *	   char    ut_line[UT_LINESIZE];
	 *	   char    ut_name[UT_NAMESIZE];
	 *	   char    ut_host[UT_HOSTSIZE];
	 *	   long    ut_time;
	 * };
	 * and appends line="|", name="date", host="", time for the OLD
	 * and appends line="{", name="date", host="", time for the NEW
	 * to _PATH_WTMP .
	 *
	 * Some OSes have utmp, some have utmpx.
	 */

	/*
	 * Write old and new time entries in utmp and wtmp if step adjustment
	 * is greater than one second.
	 *
	 * This might become even Uglier...
	 */
	if (oldtimetv.tv_sec != timetv.tv_sec)
	{
#ifdef HAVE_UTMP_H
		struct utmp ut;
#endif
#ifdef HAVE_UTMPX_H
		struct utmpx utx;
#endif

#ifdef HAVE_UTMP_H
		memset((char *)&ut, 0, sizeof(ut));
#endif
#ifdef HAVE_UTMPX_H
		memset((char *)&utx, 0, sizeof(utx));
#endif

		/* UTMP */

#ifdef UPDATE_UTMP
# ifdef HAVE_PUTUTLINE
		ut.ut_type = OLD_TIME;
		(void)strcpy(ut.ut_line, OTIME_MSG);
		ut.ut_time = oldtimetv.tv_sec;
		pututline(&ut);
		setutent();
		ut.ut_type = NEW_TIME;
		(void)strcpy(ut.ut_line, NTIME_MSG);
		ut.ut_time = timetv.tv_sec;
		pututline(&ut);
		endutent();
# else /* not HAVE_PUTUTLINE */
# endif /* not HAVE_PUTUTLINE */
#endif /* UPDATE_UTMP */

		/* UTMPX */

#ifdef UPDATE_UTMPX
# ifdef HAVE_PUTUTXLINE
		utx.ut_type = OLD_TIME;
		(void)strcpy(utx.ut_line, OTIME_MSG);
		utx.ut_tv = oldtimetv;
		pututxline(&utx);
		setutxent();
		utx.ut_type = NEW_TIME;
		(void)strcpy(utx.ut_line, NTIME_MSG);
		utx.ut_tv = timetv;
		pututxline(&utx);
		endutxent();
# else /* not HAVE_PUTUTXLINE */
# endif /* not HAVE_PUTUTXLINE */
#endif /* UPDATE_UTMPX */

		/* WTMP */

#ifdef UPDATE_WTMP
# ifdef HAVE_PUTUTLINE
		utmpname(WTMP_FILE);
		ut.ut_type = OLD_TIME;
		(void)strcpy(ut.ut_line, OTIME_MSG);
		ut.ut_time = oldtimetv.tv_sec;
		pututline(&ut);
		ut.ut_type = NEW_TIME;
		(void)strcpy(ut.ut_line, NTIME_MSG);
		ut.ut_time = timetv.tv_sec;
		pututline(&ut);
		endutent();
# else /* not HAVE_PUTUTLINE */
# endif /* not HAVE_PUTUTLINE */
#endif /* UPDATE_WTMP */

		/* WTMPX */

#ifdef UPDATE_WTMPX
# ifdef HAVE_PUTUTXLINE
		utx.ut_type = OLD_TIME;
		utx.ut_tv = oldtimetv;
		(void)strcpy(utx.ut_line, OTIME_MSG);
#  ifdef HAVE_UPDWTMPX
		updwtmpx(WTMPX_FILE, &utx);
#  else /* not HAVE_UPDWTMPX */
#  endif /* not HAVE_UPDWTMPX */
# else /* not HAVE_PUTUTXLINE */
# endif /* not HAVE_PUTUTXLINE */
# ifdef HAVE_PUTUTXLINE
		utx.ut_type = NEW_TIME;
		utx.ut_tv = timetv;
		(void)strcpy(utx.ut_line, NTIME_MSG);
#  ifdef HAVE_UPDWTMPX
		updwtmpx(WTMPX_FILE, &utx);
#  else /* not HAVE_UPDWTMPX */
#  endif /* not HAVE_UPDWTMPX */
# else /* not HAVE_PUTUTXLINE */
# endif /* not HAVE_PUTUTXLINE */
#endif /* UPDATE_WTMPX */

	}
	return (1);
}
