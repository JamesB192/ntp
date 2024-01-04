dnl ####################################################################
dnl OpenSSL support shared by top-level and sntp/configure.ac
dnl
dnl Provides command-line option --with-crypto, as well as deprecated
dnl options --with-openssl-incdir, --with-openssl-libdir..
dnl
dnl Specifying --with-openssl-libdir or --with-openssl-incdir skips
dnl pkg-config search.
dnl
dnl In the past, use of crypto would be silently disabled if the needed
dnl headers and library were not found.  Now --without-crypto must be
dnl used or configure will fail with an error.  It is now uncommon
dnl to want to build ntpd without crypto, so don't be quiet about it.
dnl
dnl Output AC_DEFINEs (for config.h)
dnl	OPENSSL		defined only if using OpenSSL
dnl
dnl Output variables:
dnl	ntp_openssl	yes if using OpenSSL, no otherwise
dnl	VER_SUFFIX	"o" if using OpenSSL
dnl
dnl Output substitutions:
dnl	CFLAGS_NTP	OpenSSL-specific flags added as needed, and
dnl			-Wstrict-prototypes for gcc if it does not
dnl			trigger a flood of warnings for each file
dnl			including OpenSSL headers.
dnl	CPPFLAGS_NTP	OpenSSL -Iincludedir flags added as needed.
dnl	LDADD_NTP	OpenSSL -L and -l flags added as needed.
dnl	LDFLAGS_NTP	OpenSSL runpath flags as needed.
dnl
dnl ####################################################################
m4_define([NTP_OPENSSL_VERBOSE_MSG],
    [
	dnl Remove dnl prefix from AC_MSG_NOTICE below for debug output.
	dnl Would prefer configure option but I don't know how to hide
	dnl that option from configure --help.
	dnl AC_MSG_NOTICE([$1])
    ])
dnl
AC_DEFUN([NTP_OPENSSL], [
AC_REQUIRE([AC_PROG_SED])dnl
AC_REQUIRE([NTP_PKG_CONFIG])dnl
AC_REQUIRE([NTP_VER_SUFFIX])dnl

AC_ARG_WITH(
    [crypto],
    [AS_HELP_STRING(
	[--with-crypto],
	[+ =openssl,libcrypto]
    )],
    [	dnl if given
	case "$with_crypto" in
	 yes)
	    with_crypto=openssl,libcrypto
	esac
    ],
    [with_crypto=openssl,libcrypto]	dnl if not given
)
AC_ARG_WITH(
    [openssl-libdir],
    [AS_HELP_STRING(
	[--with-openssl-libdir], 
	[+ =/something/reasonable]
    )]
)
AC_ARG_WITH(
    [openssl-incdir],
    [AS_HELP_STRING(
	[--with-openssl-incdir],
	[+ =search likely dirs]
    )]
)

ntp_openssl=no
ntp_openssl_from_pkg_config=no
ntp_ssl_incdir=
ntp_ssl_cflags=
ntp_ssl_cppflags=
ntp_ssl_libdir=
ntp_ssl_libs_L=
ntp_ssl_libs_l=
ntp_ssl_libs=
ntp_ssl_ldflags=

NTPSSL_SAVED_CFLAGS="$CFLAGS"
NTPSSL_SAVED_CPPFLAGS="$CPPFLAGS"
NTPSSL_SAVED_LIBS="$LIBS"
NTPSSL_SAVED_LDFLAGS="$LDFLAGS"

str="$with_crypto:${PKG_CONFIG:+notempty}:${with_openssl_libdir-notgiven}:${with_openssl_incdir-notgiven}"
NTP_OPENSSL_VERBOSE_MSG([$str])
AS_UNSET([str])

case "$with_crypto:${PKG_CONFIG:+notempty}:${with_openssl_libdir-notgiven}:${with_openssl_incdir-notgiven}" in
 no:*) ;;
 *:notempty:notgiven:notgiven)
    for pkg in `echo $with_crypto | $SED -e 's/,/ /'`; do
	AC_MSG_CHECKING([pkg-config for $pkg])
	if $PKG_CONFIG --exists $pkg ; then
	    ntp_ssl_cppflags="`$PKG_CONFIG --cflags-only-I $pkg`"
	    case "$ntp_ssl_incdir" in
	     '')
		ntp_ssl_incdir='not needed'
		;;
	     *)
		ntp_ssl_incdir="`echo $ntp_ssl_cppflags | $SED -e 's/-I//'`"
	    esac
	    ntp_ssl_cflags="`$PKG_CONFIG --cflags-only-other $pkg`"
	    ntp_ssl_libs_L="`$PKG_CONFIG --libs-only-L $pkg`"
	    case "$ntp_ssl_libs_L" in
	     '')
		ntp_ssl_libdir='not needed'
		;;
	     *)
		ntp_ssl_libdir="`echo $ntp_ssl_libs_L | $SED -e 's/-L//'`"
	    esac
	    ntp_ssl_libs_l="`$PKG_CONFIG --libs-only-l $pkg`"
	    ntp_ssl_libs="$ntp_ssl_libs_L $ntp_ssl_libs_l"
	    ntp_ssl_ldflags="`$PKG_CONFIG --libs-only-other $pkg`"
	    ntp_openssl=yes
	    ntp_openssl_from_pkg_config=yes
	    ntp_openssl_version="`$PKG_CONFIG --modversion $pkg`"
	    case "$ntp_openssl_version" in
	     *.*) ;;
	     *) ntp_openssl_version='(unknown)' ;;
	    esac
	    AC_MSG_RESULT([yes, version $ntp_openssl_version])

	    break
	fi
	AC_MSG_RESULT([no])
    done
    AS_UNSET([pkg])
esac
case "$with_crypto" in
 no) ;;
 *)
    case "$with_openssl_libdir" in
     '') ;;
     *)
	ntp_ssl_libdir="$with_openssl_libdir"
	ntp_ssl_libs_L="-L$with_openssl_libdir"
	ntp_ssl_libs_l="-lcrypto"
	ntp_ssl_libs="$ntp_ssl_libs_L $ntp_ssl_libs_l"
    esac
    case "$with_openssl_incdir" in
     '') ;;
     *)
	ntp_ssl_incdir="$with_openssl_incdir"
	ntp_ssl_cppflags="-I$with_openssl_incdir"
    esac
esac

NTP_OPENSSL_VERBOSE_MSG([OpenSSL Phase I checks:])
NTP_OPENSSL_VERBOSE_MSG([CPPFLAGS_NTP: ($CPPFLAGS_NTP)])
NTP_OPENSSL_VERBOSE_MSG([CFLAGS_NTP:   ($CFLAGS_NTP)])
NTP_OPENSSL_VERBOSE_MSG([LDADD_NTP:    ($LDADD_NTP)])
NTP_OPENSSL_VERBOSE_MSG([LDFLAGS_NTP:  ($LDFLAGS_NTP)])
NTP_OPENSSL_VERBOSE_MSG([ntp_openssl_from_pkg_config: $ntp_openssl_from_pkg_config])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_incdir:   ($ntp_ssl_incdir)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_libdir:   ($ntp_ssl_libdir)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_cflags:   ($ntp_ssl_cflags)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_cppflags: ($ntp_ssl_cppflags)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_libs_L:   ($ntp_ssl_libs_L)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_libs_l:   ($ntp_ssl_libs_l)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_libs:     ($ntp_ssl_libs)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_ldflags:  ($ntp_ssl_ldflags)])

case "$with_crypto" in
 no)
    ntp_openssl=no
    ;;
 *)
    ntp_ssl_libs_l="${ntp_ssl_libs_l:--lcrypto}"
    ntp_ssl_libs="$ntp_ssl_libs_L $ntp_ssl_libs_l"
    case "$ntp_ssl_libdir" in
     '')
	dnl ### set ntp_ssl_libdir ###

	AC_MSG_NOTICE([Searching for libcrypto without -L])
	AC_CHECK_LIB(
	    [crypto],
	    [EVP_MD_CTX_new],
	    [ntp_ssl_libdir='not needed']
	)
	dnl unconventional, using AC_CHECK_LIB repeatedly, clear cached result.
	AS_UNSET([ac_cv_lib_crypto_EVP_MD_CTX_new])
    esac
    case "$ntp_ssl_libdir" in
     '')
	ntp_ssl_libdir_search="/usr/lib /usr/lib/openssl /usr/sfw/lib"
	ntp_ssl_libdir_search="$ntp_ssl_libdir_search /usr/local/lib"
	ntp_ssl_libdir_search="$ntp_ssl_libdir_search /usr/local/ssl/lib"
	ntp_ssl_libdir_search="$ntp_ssl_libdir_search /opt/local/lib"
	ntp_ssl_libdir_search="$ntp_ssl_libdir_search /lib /lib64"
	;;
     *)
	ntp_ssl_libdir_search="$ntp_ssl_libdir"
    esac
    case $ntp_ssl_libdir_search in
     'not needed') ;;
     *)
	for i in $ntp_ssl_libdir_search not_found
	do
	    case "$i" in
	     not_found) ;;
	     *)
		AC_MSG_NOTICE([Searching for libcrypto in $i])
		LIBS="-L$i $NTPSSL_SAVED_LIBS"
		AC_CHECK_LIB(
		    [crypto],
		    [EVP_MD_CTX_new],
		    [break]
		)
		dnl unconventional, using AC_CHECK_LIB repeatedly, clear cached result.
		AS_UNSET([ac_cv_lib_crypto_EVP_MD_CTX_new])
	    esac
	done
	ntp_ssl_libdir="$i"
	ntp_ssl_libs_L="-L$i"
	ntp_ssl_libs="$ntp_ssl_libs_L $ntp_ssl_libs_l"
	LIBS="$NTPSSL_SAVED_LIBS"
	case "$ntp_ssl_libdir" in
	 not_found)
	    AC_MSG_ERROR([You may want to use --without-crypto, or]
			 [ add openssl.pc/libcrypto.pc to PKG_CONFIG_PATH,]
			 [ or use the --with-openssl-libdir=/some/path option to configure:]
			 [ libcrypto not found in $ntp_ssl_libdir_search.])
	esac
	AC_MSG_NOTICE([libcrypto found in $ntp_ssl_libdir])
    esac

    case "$ntp_openssl_from_pkg_config:$ntp_ssl_incdir" in
     'yes:not needed' | no:)
	AC_MSG_NOTICE([Searching for openssl/evp.h without -I])
	dnl force uncached AC_CHECK_HEADER
	AS_UNSET([ac_cv_header_openssl_evp_h])
	AC_CHECK_HEADER(
	    [openssl/evp.h],
	    [ntp_ssl_incdir='not needed']
	    )
    esac
    case "$ntp_ssl_incdir" in
     'not needed')
	    ntp_ssl_incdir_search="$ntp_ssl_incdir"
	    ;;
     *)
	AC_MSG_NOTICE([Searching for openssl include directory])
	case "$with_openssl_incdir" in
	 '')
	    case "$ntp_ssl_incdir" in
	     '')
		ntp_ssl_incdir_search="/usr/include /usr/sfw/include"
		ntp_ssl_incdir_search="$ntp_ssl_incdir_search /usr/local/include"
		ntp_ssl_incdir_search="$ntp_ssl_incdir_search /opt/local/include"
		ntp_ssl_incdir_search="$ntp_ssl_incdir_search /usr/local/ssl/include"
		;;
	     *)
	    esac
	    ;;
	 *)
	    ntp_ssl_incdir_search="$with_openssl_incdir"
	esac
	case $ntp_ssl_incdir_search in
	 'not needed') ;;
	 *)
	    for i in $ntp_ssl_incdir_search
	    do
		AC_MSG_NOTICE([Searching for openssl/evp.h in $i])
		CPPFLAGS="$NTPSSL_SAVED_CPPFLAGS $i"
		dnl force uncached AC_CHECK_HEADER
		AS_UNSET([ac_cv_header_openssl_evp_h])
		AC_CHECK_HEADER(
		    [openssl/evp.h],
		    [ntp_ssl_incdir="$i" ; break]
		    )
	    done
	    AS_UNSET([ac_cv_header_openssl_evp_h])
	    AS_UNSET([i])
	    CPPFLAGS="$NTPSSL_SAVED_CPPFLAGS"
	    case "$ntp_ssl_incdir" in
	     '')
		AC_MSG_ERROR([You may want to use --without-crypto, or]
			     [ add openssl.pc/libcrypto.pc to PKG_CONFIG_PATH,]
			     [ or use the --with-openssl-incdir=/some/path option to configure:]
			     [ usable openssl/evp.h not found in $ntp_ssl_incdir_search.])
	    esac
	    ntp_ssl_cppflags="-I$ntp_ssl_incdir"
	    AC_MSG_NOTICE([Found evp.h in $ntp_ssl_incdir/openssl])
	esac
    esac
    ntp_openssl=yes
esac	dnl building with SSL ($with_crypto not "no")

case "$ntp_openssl:$ntp_ssl_libdir" in
 'yes:not needed')
    ;;
 yes:*)
    CFLAGS="$NTPSSL_SAVED_CFLAGS $ntp_ssl_cflags"
    CPPFLAGS="$NTPSSL_SAVED_CPPFLAGS $ntp_ssl_cppflags"
    LIBS="$ntp_ssl_libs $NTPSSL_SAVED_LIBS"
    LDFLAGS="$ntp_ssl_ldflags $NTPSSL_SAVED_LDFLAGS"
    dnl ### test if runpath is needed for crypto ###
    AC_CACHE_CHECK(
	[if crypto works without runpath],
	[ntp_cv_ssl_without_runpath],
	[AC_RUN_IFELSE(
	    [AC_LANG_PROGRAM(
		[[
		    #include "openssl/evp.h"
		]],
		[[
		    if (!EVP_MD_CTX_new()) {
			return 1;
		    }
		]]
	    )],
	    [ntp_cv_ssl_without_runpath=yes],
	    [ntp_cv_ssl_without_runpath=no],
	    [ntp_cv_ssl_without_runpath=yes]		dnl cross-compile
	)]
    )
    case "$ntp_cv_ssl_without_runpath" in
     no)
	AC_CACHE_CHECK(
	    [if crypto needs -Wl,-rpath,$ntp_ssl_libdir],
	    [ntp_cv_ssl_needs_dashWl_rpath],
	    [
		LDFLAGS="$ntp_ssl_ldflags -Wl,-rpath,$ntp_ssl_libdir $NTPSSL_SAVED_LDFLAGS"
		AC_RUN_IFELSE(
		    [AC_LANG_PROGRAM(
			[[
			    #include "openssl/evp.h"
			]],
			[[
			    if (!EVP_MD_CTX_new()) {
				return 1;
			    }
			]]
		    )],
		    [ntp_cv_ssl_needs_dashWl_rpath=yes],
		    [ntp_cv_ssl_needs_dashWl_rpath=no]
		)
	    ]
	)
	case "$ntp_cv_ssl_needs_dashWl_rpath" in
	 yes)
	    ntp_ssl_ldflags="$ntp_ssl_ldflags -Wl,-rpath,$ntp_ssl_libdir"
	    ;;
	 no)
	    AC_CACHE_CHECK(
		[if crypto needs -R$ntp_ssl_libdir],
		[ntp_cv_ssl_needs_dashR],
		[
		    LDFLAGS="$NTPSSL_SAVED_LDFLAGS $ntp_ssl_ldflags -R$ntp_ssl_libdir"
		    AC_RUN_IFELSE(
			[AC_LANG_PROGRAM(
			    [[
				#include "openssl/evp.h"
			    ]],
			    [[
				if (!EVP_MD_CTX_new()) {
				    return 1;
				}
			    ]]
			)],
			[ntp_cv_ssl_needs_dashR=yes],
			[ntp_cv_ssl_needs_dashR=no]
		    )
		]
	    )
	    case "$ntp_cv_ssl_needs_dashR" in
	     yes)
		ntp_ssl_ldflags="$ntp_ssl_ldflags -R$ntp_ssl_libdir"
	    esac
	    case "$build:$ntp_cv_ssl_needs_dashR" in
	     $host:no)
		AC_MSG_FAILURE(
		    [Unable to run program using crypto, check openssl.pc or]
		    [ libcrypto.pc are in PKG_CONFIG_PATH, or provide]
		    [ --with-openssl-libdir=/some/path])
	    esac
	esac
    esac
esac	dnl ntp_openssl was yes

NTP_OPENSSL_VERBOSE_MSG([OpenSSL Phase II checks:])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_incdir:   ($ntp_ssl_incdir)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_libdir:   ($ntp_ssl_libdir)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_cflags:   ($ntp_ssl_cflags)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_cppflags: ($ntp_ssl_cppflags)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_libs_L:   ($ntp_ssl_libs_L)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_libs_l:   ($ntp_ssl_libs_l)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_libs:     ($ntp_ssl_libs)])
NTP_OPENSSL_VERBOSE_MSG([ntp_ssl_ldflags:  ($ntp_ssl_ldflags)])

dnl check for linking with -lcrypto failure, and try -lcrypto -lz.
dnl Helps m68k-atari-mint
dnl
dnl Needs work with the changes to run-test whether runpath is needed.
dnl Probably needs to be moved ahead of runpath testing.
dnl hart@ is reaching out to MiNT users to try to find a tester.
dnl Meanwhile can be forced by passing both ntp_cv_bare_lcrypto=no
dnl and ntp_cv_lcrypto_lz=yes on the configure command line.
dnl
case "$ntp_openssl:$ntp_openssl_from_pkg_config" in
 yes:no)
    CFLAGS="$NTPSSL_SAVED_CFLAGS $ntp_ssl_cflags"
    CPPFLAGS="$NTPSSL_SAVED_CPPFLAGS $ntp_ssl_cppflags"
    LIBS="$ntp_ssl_libs $NTPSSL_SAVED_LIBS"
    LDFLAGS="$ntp_ssl_ldflags $NTPSSL_SAVED_LDFLAGS"
    AC_CACHE_CHECK(
	[if linking with $ntp_ssl_libs_l alone works],
	[ntp_cv_bare_lcrypto],
	[AC_LINK_IFELSE(
	    [AC_LANG_PROGRAM(
		[[
		    #include "openssl/evp.h"
		]],
		[[
		    EVP_MD_CTX_new();
		]]
	    )],
	    [ntp_cv_bare_lcrypto=yes],
	    [ntp_cv_bare_lcrypto=no]
	)]
    )
    case "$ntp_cv_bare_lcrypto" in
     no)
	LIBS="-$ntp_ssl_libs -lz $NTPSSL_SAVED_LIBS"
	AC_CACHE_CHECK(
	    [if linking with $ntp_ssl_libs_l -lz works],
	    [ntp_cv_lcrypto_lz],
	    [AC_LINK_IFELSE(
		[AC_LANG_PROGRAM(
		    [[
			#include "openssl/evp.h"
		    ]],
		    [[
			EVP_MD_CTX_new();
		    ]]
		)],
		[ntp_cv_lcrypto_lz=yes],
		[ntp_cv_lcrypto_lz=no]
	    )]
	)
	case "$ntp_cv_lcrypto_lz" in
	 yes)
	     ntp_ssl_libs_l="$ntp_ssl_libs_l -lz"
	     ntp_ssl_libs="$ntp_ssl_libs_L $ntp_ssl_libs_l"
	esac
    esac	dnl linking with -lcrypto alone fails
esac		dnl using SSL and not from pkg-config

dnl
dnl Older OpenSSL headers have a number of callback prototypes inside
dnl other function prototypes which trigger copious warnings with gcc's
dnl -Wstrict-prototypes, which is included in -Wall.
dnl
dnl An example:
dnl
dnl int i2d_RSA_NET(const RSA *a, unsigned char **pp, 
dnl		  int (*cb)(), int sgckey);
dnl		  ^^^^^^^^^^^
dnl
case "$ntp_openssl:$GCC" in
 yes:yes)
    CFLAGS="$NTP_SAVED_CFLAGS $ntp_ssl_cflags -Werror"
    CPPFLAGS="$NTPSSL_SAVED_CPPFLAGS $ntp_ssl_cppflags"
    LIBS="$ntp_ssl_libs $NTPSSL_SAVED_LIBS"
    LDFLAGS="$ntp_ssl_ldflags $NTPSSL_SAVED_LDFLAGS"
    AC_CACHE_CHECK(
	[If $CC supports -Werror],
	[ntp_cv_gcc_supports_Werror],
	[AC_COMPILE_IFELSE(
	    [AC_LANG_PROGRAM([], [])],
	    [ntp_cv_gcc_supports_Werror=yes],
	    [ntp_cv_gcc_supports_Werror=no]
	)]
    )
    case "ntp_cv_gcc_supports_Werror" in
     no)
	ntp_use_Wstrict_prototypes=yes
	;;
     yes)
	CFLAGS="$CFLAGS -Wstrict-prototypes"
	AC_CACHE_CHECK(
	    [if OpenSSL triggers warnings],
	    [ntp_cv_ssl_triggers_warnings],
	    [AC_COMPILE_IFELSE(
		[AC_LANG_PROGRAM(
		    [[
			#include "openssl/asn1_mac.h"
			#include "openssl/bn.h"
			#include "openssl/err.h"
			#include "openssl/evp.h"
			#include "openssl/pem.h"
			#include "openssl/rand.h"
			#include "openssl/x509v3.h"
		    ]],
		    [[
			/* empty body */
		    ]]
		)],
		[ntp_cv_ssl_triggers_warnings=no],
		[ntp_cv_ssl_triggers_warnings=yes]
	    )]
	)
	case "$ntp_cv_ssl_triggers_warnings" in
	 yes)
	    ntp_use_Wstrict_prototypes=no
	    ;;
	 *)
	    ntp_use_Wstrict_prototypes=yes
	esac
    esac
    case "$ntp_use_Wstrict_prototypes" in
     no)
	ntp_ssl_cflags="$ntp_ssl_cflags -Wno-strict-prototypes"
	;;
     *)
	ntp_ssl_cflags="$ntp_ssl_cflags -Wstrict-prototypes"
    esac
    ;;
 no:yes)
    dnl gcc without OpenSSL
    ntp_ssl_cflags="$ntp_ssl_cflags -Wstrict-prototypes"
esac	dnl checking for gcc problems with -Werror and -Wstrict-prototypes

AC_MSG_CHECKING([if we will use crypto])
AC_MSG_RESULT([$ntp_openssl])

case "$ntp_openssl" in
 yes)
    VER_SUFFIX=o
    AC_CHECK_HEADERS([openssl/cmac.h openssl/hmac.h])
    AC_DEFINE([OPENSSL], [], [Use OpenSSL?])
    dnl We don't want -Werror for the EVP_MD_do_all_sorted check
    CFLAGS="$NTPSSL_SAVED_CFLAGS"
    AC_CHECK_FUNCS([EVP_MD_do_all_sorted])
    CPPFLAGS_NTP="$CPPFLAGS_NTP $ntp_ssl_cppflags"
    CFLAGS_NTP="$CFLAGS_NTP $ntp_ssl_cflags"
    LDADD_NTP="$ntp_ssl_libs $LDADD_NTP"
    LDFLAGS_NTP="$ntp_ssl_ldflags $LDFLAGS_NTP"
esac

NTP_OPENSSL_VERBOSE_MSG([OpenSSL final checks:])
NTP_OPENSSL_VERBOSE_MSG([ntp_openssl: $ntp_openssl])
NTP_OPENSSL_VERBOSE_MSG([CPPFLAGS_NTP: ($CPPFLAGS_NTP)])
NTP_OPENSSL_VERBOSE_MSG([CFLAGS_NTP:   ($CFLAGS_NTP)])
NTP_OPENSSL_VERBOSE_MSG([LDADD_NTP:    ($LDADD_NTP)])
NTP_OPENSSL_VERBOSE_MSG([LDFLAGS_NTP:  ($LDFLAGS_NTP)])

CFLAGS="$NTPSSL_SAVED_CFLAGS"
CPPFLAGS="$NTPSSL_SAVED_CPPFLAGS"
LIBS="$NTPSSL_SAVED_LIBS"
LDFLAGS="$NTPSSL_SAVED_LDFLAGS"

AS_UNSET([NTPSSL_SAVED_CFLAGS])
AS_UNSET([NTPSSL_SAVED_CPPFLAGS])
AS_UNSET([NTPSSL_SAVED_LIBS])
AS_UNSET([NTPSSL_SAVED_LDFLAGS])
AS_UNSET([ntp_use_Wstrict_prototypes])
AS_UNSET([ntp_openssl_from_pkg_config])
AS_UNSET([ntp_openssl_version])
AS_UNSET([ntp_ssl_cflags])
AS_UNSET([ntp_ssl_cppflags])
AS_UNSET([ntp_ssl_libdir_search])
AS_UNSET([ntp_ssl_incdir_search])
AS_UNSET([ntp_ssl_libdir])
AS_UNSET([ntp_ssl_incdir])
AS_UNSET([ntp_ssl_libs_l])
AS_UNSET([ntp_ssl_libs_L])
AS_UNSET([ntp_ssl_ldflags])

])
dnl end of AC_DEFUN([NTP_OPENSSL])
dnl ======================================================================
