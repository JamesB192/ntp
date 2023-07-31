/*
 * lib_strbuf.c - init_lib() and library string storage
 */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <isc/net.h>
#include <isc/result.h>

#include "ntp_fp.h"
#include "ntp_stdlib.h"

/*
 * Storage declarations
 */
static char	lib_stringbuf_storage[LIB_NUMBUF * LIB_BUFLENGTH];
char *		lib_stringbuf[LIB_NUMBUF];
int		lib_nextbuf;
int		lib_inited;
int		ipv4_works;
int		ipv6_works;
int		debug;

/*
 * initialization routine.  Might be needed if the code is ROMized.
 */
void
init_lib(void)
{
	u_int		u;

	if (lib_inited)
		return;
	ipv4_works = (ISC_R_SUCCESS == isc_net_probeipv4());
	ipv6_works = (ISC_R_SUCCESS == isc_net_probeipv6());
	init_systime();
	/* avoid -Wrestrict warnings by keeping a pointer to each buffer */
	lib_stringbuf[0] = lib_stringbuf_storage;
	for (u = 1; u < COUNTOF(lib_stringbuf); u++) {
		lib_stringbuf[u] = lib_stringbuf[u - 1] + LIB_BUFLENGTH;
	}

	lib_inited = TRUE;
}
