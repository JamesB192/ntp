/*
 * nt_ppsimpl.c - PPS API client implementation
 *
 * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.
 * The contents of 'html/copyright.html' apply.
 * ----------------------------------------------------------------------
 * Most of this code is from the the original 'timepps.h' for windows
 * where these functions where coded as 'inline'. While this was perhaps
 * a convenient thing to do, using this amount of code as 'static inline'
 * functions is generally a Bad Idea (tm).
 *
 * Not to mention that there are some static variables that got duplicated
 * into the various modules...
 */

#include <config.h>

#include <stddef.h>	/* offsetof() */
#include <io.h>		/* _get_osfhandle() */

#include "timepps.h"
#include "ntp_stdlib.h"
#include "lib_strbuf.h"

static ppsapi_provider *	g_provider_list;
static ppsapi_provider *	g_curr_provider;

static pps_handle_t
internal_create_pps_handle(
	void *	prov_context
	)
{
	pps_unit_t *	punit = NULL;

	if (NULL == g_curr_provider)
		fprintf(stderr, "create_pps_handle: provider backend called me outside time_pps_create\n");
	else
		punit = calloc(1, sizeof(pps_unit_t));
	
	if (NULL != punit) {
		punit->provider = g_curr_provider;
		punit->context = prov_context;
		punit->magic = PPSAPI_MAGIC_UNIT;
	}
	return (pps_handle_t)punit;
}

static pps_unit_t *
unit_from_ppsapi_handle(
	pps_handle_t	handle
	)
{
	pps_unit_t *punit = (pps_unit_t *)handle;
	if (!(punit && PPSAPI_MAGIC_UNIT == punit->magic))
		punit = NULL;
	return punit;
}

/* ntpd on Windows only looks to errno after finding 'GetLastError()'
 * returns NO_ERROR.  To accomodate its use of msyslog in portable code
 * such as refclock_atom.c, this implementation always clears the
 * Windows error code using 'SetLastError(NO_ERROR)' when returning an
 * errno.  This is also a good idea for any non-ntpd clients as they
 * should rely only the errno for PPSAPI functions.
 */
static int
set_pps_errno(
	int	e
)
{
	SetLastError(NO_ERROR);
	errno = e;
	return -1;
}


/*Format a Windows errro into a temporary buffer from buffer lib */
static char *
fmt_err(
	DWORD ec
	)
{
	char * buff = NULL;
	char * endp = NULL;

	/* get buffer & format message, ensure termination */
	LIB_GETBUF(buff);
	FormatMessageA(
		FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		ec,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		buff, LIB_BUFLENGTH,
		NULL);
	buff[LIB_BUFLENGTH - 1] = '\0';
	/* strip trailing whitespace & CR/LF stuff & the trailing dot */
	endp = buff + strlen(buff);
	while (endp != buff && endp[-1] <= ' ')
		--endp;
	if (endp != buff && endp[-1] == '.')
		--endp;
	*endp = '\0';
	/* If windows fails to format this, resort to numeric output... */
	if (!*buff) {
		snprintf(buff, LIB_BUFLENGTH,
			 "(unknown windows error %lu / 0x%08lx)",
			 (unsigned long)ec, (unsigned long)ec);
	}
	/* That's it for now... */
	return buff;
}

/* Cleanup & error return for actual loading steps */
static int
cleanup_load(
	ppsapi_provider *	prov,
	HMODULE			hmod,
	int			errc
)
{
	/* if possible, decref the library handle */
	if (NULL != hmod)
		FreeLibrary(hmod);
	/* if possible, drop our provider structure */
	if (prov) {
		free(prov->short_name);
		free(prov->full_name);
		free(prov);
	}
	/* error code pass-through */
	return errc;
}

/* Get the directory path (!!) of the calling process. We want the true
 * 8bit character version, and we should not trust '_pgmptr' or
 * '_get_pgmptr()' too much. There's still some doubt around
 * 'GetModuleFileNameA()', but all in all this seems to be the most
 * reliable solution, even if it's a PITA with the buffer sizes.
 */
static char*
get_module_path(void)
{
	static const size_t s_smax = 4096;

	char *	buff = NULL;
	char *	lsep;
	DWORD	slen, nlen;

	for (slen = 128; slen <= s_smax; slen <<= 1) {
		buff = realloc(buff, slen);
		if (NULL == buff)
			goto fail;
		nlen = GetModuleFileNameA(NULL, buff, slen);
		if (0 == nlen)
			goto fail;
		if (nlen < slen)
			break;
	}
	if (slen > s_smax)
		goto fail;
	lsep = strrchr(buff, '\\');
	if (NULL == lsep)
		goto fail;
	*++lsep = '\0';
	return realloc(buff, (size_t)(lsep - buff) + 1);

fail:
	free(buff);
	return NULL;
}

/* Iteration helper for the provider list. Naked names (without *any*
 * path) will be prepended with path to the executable running this
 * code. While this was not necessary until Win7, newer versions of
 * Windows seem to have tighter restrictions from where to load code, at
 * least as long as the binary is not signed.
 */
static char*
provlist_next_item(
	const char ** const ppath
	)
{
	static char *	s_modpath    /* = NULL */;
	static char	s_nullstr[1] /* = { '\0' } */;

	const char *	phead;
	const char *	ptail;
	char *		retv;
	char *		endp;
	int/*BOOL*/	nodir;
	int		ch;
	DWORD		slen;

	/* check if we're already done */
	if (NULL == (phead = *ppath))
		return NULL;
	/* Skip any leading ';' -- should not happen, but this is
	 * user-provided input after all...
	 */
	while (*phead == ';')
		++phead;
	/* check if we're already done */
	if (!*phead) {
		*ppath = NULL;
		return NULL;
	}
	/* Inspect the next section of input string. */
	nodir = TRUE;
	for (ptail = phead; (ch = *ptail) && ch != ';'; ++ptail)
		if (ch == '\\' || ch == '/')
			nodir = FALSE;
	/* Make sure we have a proper module path when we need one. */
	if (nodir && NULL == s_modpath) {
		s_modpath = get_module_path();
		if (NULL == s_modpath)
			s_modpath = s_nullstr;
	}

	/* Prepare buffer for copy of file name. */
	slen = (DWORD)(ptail - phead); /* 4GB string should be enough... */
	if (nodir && NULL != s_modpath) {
		/* Prepend full path to executable to the name. */
		endp = retv = malloc(strlen(s_modpath) + slen + 1);
		if (NULL != endp) {
			strcpy(endp, s_modpath);
			endp += strlen(endp);
		}
	} else {
		endp = retv = malloc(slen + 1u);
	}
	/* Copy with conversion from '/' to '\\' */
	if (NULL != endp) {
		while (phead != ptail) {
			ch = (u_char)*phead++;
			*endp++ = (ch != '/') ? ch : '\\';
		}
		*endp = '\0';
	}
	/*Update scan pointer & return result. */
	*ppath = (*ptail) ? (ptail + 1) : NULL;
	return retv;
}


/* Try to load & init a provider DLL. (NOT a device instance!) */ 
static int
load_pps_provider(
	const char *	dllpath
	)
{
	static const char	msgfmt[] = "load_pps_provider: '%s': %s";

	char			short_name[16];
	char			full_name[64];
	ppsapi_provider *	prov = NULL;
	HMODULE			hmod = NULL;
	pppsapi_prov_init	pprov_init;
	int			errc;

	prov = calloc(1, sizeof(*prov));
	if (NULL == prov) {
		errc = errno;
		msyslog(LOG_WARNING, msgfmt, dllpath,
			strerror(errc));
		return errc;
	}
	
	hmod = LoadLibraryA(dllpath);
	if (NULL == hmod) {
		msyslog(LOG_WARNING, msgfmt, dllpath,
			fmt_err(GetLastError()));
		return cleanup_load(prov, hmod, ENOENT);
	}

	pprov_init = (pppsapi_prov_init)GetProcAddress(hmod, "ppsapi_prov_init");
	if (NULL == pprov_init) {
		msyslog(LOG_WARNING, msgfmt, dllpath,
			"main entry point not found");
		return cleanup_load(prov, hmod, EFAULT);
	}

	prov->caps = (*pprov_init)(PPSAPI_TIMEPPS_PROV_VER,
		&internal_create_pps_handle,
		&pps_ntp_timestamp_from_counter,
		short_name, sizeof(short_name),
		full_name, sizeof(full_name));
	if (!prov->caps) {
		msyslog(LOG_WARNING, msgfmt, dllpath,
			"no capabilities");
		return cleanup_load(prov, hmod, EACCES);
	}
	
	prov->short_name = (*short_name) ? _strdup(short_name) : NULL;
	prov->full_name  = (*full_name ) ? _strdup(full_name ) : NULL;
	if (NULL == prov->short_name || NULL == prov->full_name) {
		msyslog(LOG_WARNING, msgfmt, dllpath,
			"missing names");
		return cleanup_load(prov, hmod, EINVAL);
	}

	prov->ptime_pps_create = (provtime_pps_create)
		GetProcAddress(hmod, "prov_time_pps_create");
	prov->ptime_pps_destroy = (provtime_pps_destroy)
		GetProcAddress(hmod, "prov_time_pps_destroy");
	prov->ptime_pps_setparams = (provtime_pps_setparams)
		GetProcAddress(hmod, "prov_time_pps_setparams");
	prov->ptime_pps_fetch = (provtime_pps_fetch)
		GetProcAddress(hmod, "prov_time_pps_fetch");
	prov->ptime_pps_kcbind = (provtime_pps_kcbind)
		GetProcAddress(hmod, "prov_time_pps_kcbind");

	if (NULL == prov->ptime_pps_create    ||
	    NULL == prov->ptime_pps_destroy   ||
	    NULL == prov->ptime_pps_setparams ||
	    NULL == prov->ptime_pps_fetch     ||
	    NULL == prov->ptime_pps_kcbind     )
	{
		msyslog(LOG_WARNING, msgfmt, prov->short_name,
			"missing entry point");
		return cleanup_load(prov, hmod, EINVAL);
	}

	prov->next = g_provider_list;
	g_provider_list = prov;

	return 0;
}


int
time_pps_create(
	int		filedes,/* device file descriptor */
	pps_handle_t *	phandle	/* returned handle */
	)
{
	HANDLE			winhandle;
	const char *		dlls;
	char *			dll;
	ppsapi_provider *	prov;
	pps_handle_t		ppshandle;
	int			err;

	if (NULL == phandle)
		return set_pps_errno(EFAULT);

	winhandle = (HANDLE)_get_osfhandle(filedes);
	if (INVALID_HANDLE_VALUE == winhandle)
		return set_pps_errno(EBADF);

	/* For initial testing the list of PPSAPI backend providers is
	 * provided by the environment variable PPSAPI_DLLS, separated by
	 * semicolons such as
	 * PPSAPI_DLLS=c:\ntp\serial_ppsapi.dll;..\parport_ppsapi.dll
	 * There are a million better ways, such as a well-known registry
	 * key under which a value is created for each provider DLL
	 * installed, or even a platform-specific ntp.conf directive or
	 * command-line switch.
	 *
	 * [Bug 3139] Since nothing is more durable than a provisional
	 * implementation, we're still stuck with that...
	 */
	dlls = getenv("PPSAPI_DLLS");
	if (NULL != dlls && NULL == g_provider_list) {
		msyslog(LOG_INFO, "time_pps_create: load list '%s'",
			dlls);
	} else
		dlls = NULL;

	while (NULL != (dll = provlist_next_item(&dlls))) {
		err = load_pps_provider(dll);
		if (err) {
			msyslog(LOG_ERR, "time_pps_create: load failed (%s) --> %d / %s",
				dll, err, strerror(err));
		} else {
			msyslog(LOG_INFO, "time_pps_create: loaded '%s'",
				dll);
		}
		free(dll);
	}

	/* Hand off to each provider in turn until one returns a PPS
	 * handle or they've all declined.
	 *
	 * [Bug 3139] Since we potentially tried a series of DLLs, it's
	 * a good question what the returned error should be if all of
	 * them failed; Returning the error from the last attempt is as
	 * good as any but for single DLL (which is the normal case)
	 * this provides slightly more information.
	 */
	err = ENOEXEC;
	if (NULL == g_provider_list) {
		msyslog(LOG_ERR, "time_pps_create: %s",
			"no providers available");
		return set_pps_errno(err);
	}
	for (prov = g_provider_list; NULL != prov; prov = prov->next) {
		ppshandle = 0;
		g_curr_provider = prov;
		err = (*prov->ptime_pps_create)(winhandle, &ppshandle);
		g_curr_provider = NULL;
		if (!err && ppshandle) {
			*phandle = ppshandle;
			return 0;
		}
		msyslog(LOG_INFO, "time_pps_create: provider '%s' failed: %d / %s",
			prov->short_name, err, strerror(err));
	}
	msyslog(LOG_ERR, "time_pps_create: %s",
		"all providers failed");
	return set_pps_errno(err);
}


int
time_pps_destroy(
	pps_handle_t handle
	)
{
	pps_unit_t *	punit = unit_from_ppsapi_handle(handle);
	int		err   = 0;

	/* Check for valid arguments */
	if (NULL == punit)
		return set_pps_errno(EBADF);
	/* Call provider. Note the handle is gone anyway... */
	err = (*punit->provider->ptime_pps_destroy)(punit, punit->context);
	free(punit);
	if (err)
		return set_pps_errno(err);
	return 0;
}


int
time_pps_setparams(
	pps_handle_t handle,
	const pps_params_t *params
	)
{
	pps_unit_t *	punit = unit_from_ppsapi_handle(handle);
	int		err   = 0;

	/* Check for valid arguments */
	if (NULL == punit)
		return set_pps_errno(EBADF);
	if (NULL == params)
		return set_pps_errno(EFAULT);
	/* Call provider */
	err = (*punit->provider->ptime_pps_setparams)(punit, punit->context, params);
	if (err)
		return set_pps_errno(err);
	return 0;
}


int
time_pps_getparams(
	pps_handle_t	handle,
	pps_params_t *	params_buf
	)
{
	pps_unit_t *	punit = unit_from_ppsapi_handle(handle);

	/* Check for valid arguments */
	punit;
	if (NULL == punit)
		return set_pps_errno(EBADF);
	if (NULL == params_buf)
		return set_pps_errno(EFAULT);
	/* Copy out parameters */
	*params_buf = punit->params;
	return 0;
}


int
time_pps_getcap(
	pps_handle_t	handle,
	int *		pmode
	)
{
	pps_unit_t *	punit = unit_from_ppsapi_handle(handle);

	/* Check for valid arguments */
	if (NULL == punit)
		return set_pps_errno(EBADF);
	if (NULL == pmode)
		return set_pps_errno(EFAULT);
	/* Copy out capabilities */
		*pmode = punit->provider->caps;
	return 0;
}


int
time_pps_fetch(
	pps_handle_t		handle,
	const int		tsformat,
	pps_info_t *		pinfo,
	const struct timespec *	ptimeout
	)
{
	pps_unit_t *	punit = unit_from_ppsapi_handle(handle);
	int		err   = 0;

	/* Check for valid arguments */
	if (NULL == punit)
		return set_pps_errno(EBADF);
	if (NULL == pinfo)
		return set_pps_errno(EFAULT);
	/* Fetch timestamps */
	err = (*punit->provider->ptime_pps_fetch)(punit,
		punit->context,
		tsformat,
		pinfo,
		ptimeout);

	if (err)
		return set_pps_errno(err);
	return 0;
}


int
time_pps_kcbind(
	pps_handle_t handle,
	const int kernel_consumer,
	const int edge, const int tsformat
	)
{
	pps_unit_t *	punit = unit_from_ppsapi_handle(handle);
	int		err   = 0;

	/* Check for valid arguments */
	if (NULL == punit)
		return set_pps_errno(EBADF);
	/* Call provider */
	err = (*punit->provider->ptime_pps_kcbind)(
		punit,
		punit->context,
		kernel_consumer,
		edge,
		tsformat);

	if (err)
		return set_pps_errno(err);
	return 0;
}

/* -*- that's all folks! -*- */
