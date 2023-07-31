/*
 * lib_strbuf.h - definitions for routines which use the common string buffers
 */
#ifndef LIB_STRBUF_H
#define LIB_STRBUF_H

#include <ntp_types.h>
#include <ntp_malloc.h>			/* for zero_mem() */

/*
 * Sizes of things
 */
#define LIB_NUMBUF	10
#define	LIB_BUFLENGTH	128

extern char *	lib_stringbuf[LIB_NUMBUF];
extern int	lib_nextbuf;
extern int	lib_inited;
extern int	ipv4_works;
extern int	ipv6_works;

extern	void	init_lib(void);

/*
 * Macro to get a pointer to the next buffer
 */
#define	LIB_GETBUF(bufp)						\
	do {								\
		if (!lib_inited) {					\
			init_lib();					\
		}							\
		zero_mem(lib_stringbuf[lib_nextbuf], LIB_BUFLENGTH);	\
		(bufp) = lib_stringbuf[lib_nextbuf++];			\
		lib_nextbuf %= COUNTOF(lib_stringbuf);			\
	} while (FALSE)

#endif	/* LIB_STRBUF_H */
