dnl 
dnl EDIT THIS FILE WITH CAUTION  (libopts.m4)
dnl 
dnl It has been AutoGen-ed  Sunday January  9, 2005 at 06:06:21 AM EST
dnl From the definitions    stdin
dnl and the template file   conftest.tpl
dnl
dnl @synopsis  INVOKE_LIBOPTS_MACROS
dnl
dnl  This macro will invoke the AutoConf macros specified in stdin
dnl  that have not been disabled with "omit-invocation".
dnl
AC_DEFUN([LIBOPTS_WITH_REGEX_HEADER],[
  AC_ARG_WITH([regex-header],
    AC_HELP_STRING([--with-regex-header], [a reg expr header is specified]),
    [libopts_cv_with_regex_header=${with_regex_header}],
    AC_CACHE_CHECK([whether a reg expr header is specified], libopts_cv_with_regex_header,
      libopts_cv_with_regex_header=no)
  ) # end of AC_ARG_WITH

  if test "X${libopts_cv_with_regex_header}" != Xno
  then
    AC_DEFINE_UNQUOTED([REGEX_HEADER],[<${libopts_cv_with_regex_header}>])
  else
    AC_DEFINE([REGEX_HEADER],[<regex.h>],[name of regex header file])
  fi
  
]) # end of AC_DEFUN of LIBOPTS_WITH_REGEX_HEADER


AC_DEFUN([LIBOPTS_WITHLIB_REGEX],[
  AC_ARG_WITH([libregex],
    AC_HELP_STRING([--with-libregex], [libregex installation prefix]),
    [libopts_cv_with_libregex_root=${with_libregex}],
    AC_CACHE_CHECK([whether with-libregex was specified], libopts_cv_with_libregex_root,
      libopts_cv_with_libregex_root=no)
  ) # end of AC_ARG_WITH libregex

  if test "${with_libguile+set}" = set && \
     test "${withval}" = no
  then ## disabled by request
    libopts_cv_with_libregex_root=no
    libopts_cv_with_libregex_cflags=no
    libopts_cv_with_libregex_libs=no
  else

  AC_ARG_WITH([libregex-cflags],
    AC_HELP_STRING([--with-libregex-cflags], [libregex compile flags]),
    [libopts_cv_with_libregex_cflags=${with_regex_cflags}],
    AC_CACHE_CHECK([whether with-libregex-cflags was specified], libopts_cv_with_libregex_cflags,
      libopts_cv_with_libregex_cflags=no)
  ) # end of AC_ARG_WITH libregex-cflags

  AC_ARG_WITH([libregex-libs],
    AC_HELP_STRING([--with-libregex-libs], [libregex link command arguments]),
    [libopts_cv_with_libregex_libs=${with_regex_libs}],
    AC_CACHE_CHECK([whether with-libregex-libs was specified], libopts_cv_with_libregex_libs,
      libopts_cv_with_libregex_libs=no)
  ) # end of AC_ARG_WITH libregex-libs

  case "X${libopts_cv_with_libregex_cflags}" in
  Xyes|Xno|X )
    case "X${libopts_cv_with_libregex_root}" in
    Xyes|Xno|X ) libopts_cv_with_libregex_cflags=no ;;
    * )        libopts_cv_with_libregex_cflags=-I${libopts_cv_with_libregex_root}/include ;;
    esac
  esac
  case "X${libopts_cv_with_libregex_libs}" in
  Xyes|Xno|X )
    case "X${libopts_cv_with_libregex_root}" in
    Xyes|Xno|X ) libopts_cv_with_libregex_libs=no ;;
    * )        libopts_cv_with_libregex_libs="-L${libopts_cv_with_libregex_root}/lib -lregex";;
    esac
  esac
  libopts_save_CPPFLAGS="${CPPFLAGS}"
  libopts_save_LIBS="${LIBS}"
  fi ## disabled by request

  case "X${libopts_cv_with_libregex_cflags}" in
  Xyes|Xno|X )
    libopts_cv_with_libregex_cflags="" ;;
  * ) CPPFLAGS="${CPPFLAGS} ${libopts_cv_with_libregex_cflags}" ;;
  esac
  case "X${libopts_cv_with_libregex_libs}" in
  Xyes|Xno|X )
    libopts_cv_with_libregex_libs="" ;;
  * )
    LIBS="${LIBS} ${libopts_cv_with_libregex_libs}" ;;
  esac
  LIBREGEX_CFLAGS=""
  LIBREGEX_LIBS=""
  AC_MSG_CHECKING([whether libregex functions properly])
  AC_CACHE_VAL([libopts_cv_with_libregex],[
  AC_TRY_RUN([@%:@include <stdio.h>
@%:@include <stdlib.h>
@%:@include <sys/types.h>
@%:@include REGEX_HEADER
static regex_t re;
void comp_re( const char* pzPat ) {
  int res = regcomp( &re, pzPat, REG_EXTENDED|REG_ICASE|REG_NEWLINE );
  if (res == 0) return;
  exit( res ); }
int main() {
  regmatch_t m@<:@2@:>@;
  comp_re( "^.*\@S|@"   );
  comp_re( "()|no.*" );
  comp_re( "."       );
  if (regexec( &re, "X", 2, m, 0 ) != 0)  return 1;
  if ((m@<:@0@:>@.rm_so != 0) || (m@<:@0@:>@.rm_eo != 1)) {
    fputs( "error: regex -->.<-- did not match\n", stderr );
    return 1;
  }
  return 0; }],
    [libopts_cv_with_libregex=yes], [libopts_cv_with_libregex=no],
    [libopts_cv_with_libregex=no]) # end of AC_TRY_RUN 
  ]) # end of AC_CACHE_VAL for libopts_cv_with_libregex
  AC_MSG_RESULT([${libopts_cv_with_libregex}])

  if test "X${libopts_cv_with_libregex}" = Xno
  then
    CPPFLAGS="${libopts_save_CPPFLAGS}"
    LIBS="${libopts_save_LIBS}"
        	cat >&2 <<'_EOF_'
I cannot detect POSIX compliant regcomp/regexec routines.
These are required for AutoGen to work correctly.  If you have
such a library present on your system, you must specify it by
setting the LIBS environment variable, e.g., "LIBS='-lregex'".
If you do not have such a library on your system, then you should
download and install, for example, the one from:
    ftp://ftp.gnu.org/gnu/rx/
_EOF_
AC_MSG_ERROR([Cannot find working POSIX regex library])
  fi
  
]) # end of AC_DEFUN of LIBOPTS_WITHLIB_REGEX


AC_DEFUN([LIBOPTS_RUN_PATHFIND],[
  AC_MSG_CHECKING([whether pathfind(3) works])
  AC_CACHE_VAL([libopts_cv_run_pathfind],[
  AC_TRY_RUN([@%:@include <string.h>
@%:@include <stdlib.h>
int main (int argc, char** argv) {
   char* pz = pathfind( getenv( "PATH" ), "sh", "x" );
   return (pz == 0) ? 1 : 0;
}],
    [libopts_cv_run_pathfind=yes],[libopts_cv_run_pathfind=no],[libopts_cv_run_pathfind=no]
  ) # end of TRY_RUN
  ]) # end of AC_CACHE_VAL for libopts_cv_run_pathfind
  AC_MSG_RESULT([${libopts_cv_run_pathfind}])

  if test "X${libopts_cv_run_pathfind}" != Xno
  then
    AC_DEFINE([HAVE_PATHFIND],[1],
        [Define this if pathfind(3) works])
  fi
  
]) # end of AC_DEFUN of LIBOPTS_RUN_PATHFIND


AC_DEFUN([LIBOPTS_RUN_STRFTIME],[
  AC_MSG_CHECKING([whether strftime() works])
  AC_CACHE_VAL([libopts_cv_run_strftime],[
  AC_TRY_RUN([@%:@include <time.h>
@%:@include <string.h>
char t_buf@<:@ 64 @:>@;
int main() {
  static const char z@<:@@:>@ = "Thursday Aug 28 240";
  struct tm tm;
  tm.tm_sec   = 36;  /* seconds after the minute @<:@0, 61@:>@  */
  tm.tm_min   = 44;  /* minutes after the hour @<:@0, 59@:>@ */
  tm.tm_hour  = 12;  /* hour since midnight @<:@0, 23@:>@ */
  tm.tm_mday  = 28;  /* day of the month @<:@1, 31@:>@ */
  tm.tm_mon   =  7;  /* months since January @<:@0, 11@:>@ */
  tm.tm_year  = 86;  /* years since 1900 */
  tm.tm_wday  =  4;  /* days since Sunday @<:@0, 6@:>@ */
  tm.tm_yday  = 239; /* days since January 1 @<:@0, 365@:>@ */
  tm.tm_isdst =  1;  /* flag for daylight savings time */
  strftime( t_buf, sizeof( t_buf ), "%A %b %d %j", &tm );
  return (strcmp( t_buf, z ) != 0); }],
    [libopts_cv_run_strftime=yes],[libopts_cv_run_strftime=no],[libopts_cv_run_strftime=no]
  ) # end of TRY_RUN
  ]) # end of AC_CACHE_VAL for libopts_cv_run_strftime
  AC_MSG_RESULT([${libopts_cv_run_strftime}])

  if test "X${libopts_cv_run_strftime}" != Xno
  then
    AC_DEFINE([HAVE_STRFTIME],[1],
        [Define this if strftime() works])
  fi
  
]) # end of AC_DEFUN of LIBOPTS_RUN_STRFTIME


AC_DEFUN([LIBOPTS_RUN_FOPEN_BINARY],[
  AC_MSG_CHECKING([whether fopen accepts "b" mode])
  AC_CACHE_VAL([libopts_cv_run_fopen_binary],[
  AC_TRY_RUN([@%:@include <stdio.h>
int main (int argc, char** argv) {
FILE* fp = fopen("conftest.@S|@ac_ext", "rb");
return (fp == NULL) ? 1 : fclose(fp); }],
    [libopts_cv_run_fopen_binary=yes],[libopts_cv_run_fopen_binary=no],[libopts_cv_run_fopen_binary=no]
  ) # end of TRY_RUN
  ]) # end of AC_CACHE_VAL for libopts_cv_run_fopen_binary
  AC_MSG_RESULT([${libopts_cv_run_fopen_binary}])

  if test "X${libopts_cv_run_fopen_binary}" != Xno
  then
    AC_DEFINE([FOPEN_BINARY_FLAG],"b",
	[fopen(3) accepts a 'b' in the mode flag])
  else
    AC_DEFINE([FOPEN_BINARY_FLAG],"",
	[fopen(3) accepts a 'b' in the mode flag])
  fi
  
]) # end of AC_DEFUN of LIBOPTS_RUN_FOPEN_BINARY


AC_DEFUN([LIBOPTS_RUN_FOPEN_TEXT],[
  AC_MSG_CHECKING([whether fopen accepts "t" mode])
  AC_CACHE_VAL([libopts_cv_run_fopen_text],[
  AC_TRY_RUN([@%:@include <stdio.h>
int main (int argc, char** argv) {
FILE* fp = fopen("conftest.@S|@ac_ext", "rt");
return (fp == NULL) ? 1 : fclose(fp); }],
    [libopts_cv_run_fopen_text=yes],[libopts_cv_run_fopen_text=no],[libopts_cv_run_fopen_text=no]
  ) # end of TRY_RUN
  ]) # end of AC_CACHE_VAL for libopts_cv_run_fopen_text
  AC_MSG_RESULT([${libopts_cv_run_fopen_text}])

  if test "X${libopts_cv_run_fopen_text}" != Xno
  then
    AC_DEFINE([FOPEN_TEXT_FLAG],"t",
	[fopen(3) accepts a 't' in the mode flag])
  else
    AC_DEFINE([FOPEN_TEXT_FLAG],"",
	[fopen(3) accepts a 't' in the mode flag])
  fi
  
]) # end of AC_DEFUN of LIBOPTS_RUN_FOPEN_TEXT


AC_DEFUN([INVOKE_LIBOPTS_MACROS],[
  # Check to see if a reg expr header is specified.
  LIBOPTS_WITH_REGEX_HEADER

  # Check to see if a working libregex can be found.
  LIBOPTS_WITHLIB_REGEX

  # Check to see if pathfind(3) works.
  LIBOPTS_RUN_PATHFIND

  # Check to see if strftime() works.
  LIBOPTS_RUN_STRFTIME

  # Check to see if fopen accepts "b" mode.
  LIBOPTS_RUN_FOPEN_BINARY

  # Check to see if fopen accepts "t" mode.
  LIBOPTS_RUN_FOPEN_TEXT
  
]) # end AC_DEFUN of INVOKE_LIBOPTS_MACROS

dnl @synopsis  LIBOPTS_CHECK
dnl
dnl If autoopts-config works, add the linking information to LIBS.
dnl Otherwise, add ``libopts-23.1.14''
dnl to SUBDIRS and run all the config tests that the library needs.
dnl
AC_DEFUN([LIBOPTS_CHECK],[
# Check for standard headers.
# ----------------------------------------------------------------------
# =================
# AC_HEADER_STDC
# =================
AC_HEADER_STDC
# =================
# AC_HEADER_DIRENT
# =================
AC_HEADER_DIRENT

# ----------------------------------------------------------------------
# AC_CHECK_HEADERS Check for list of headers.
# ----------------------------------------------------------------------
AC_CHECK_HEADERS(dlfcn.h errno.h fcntl.h libgen.h memory.h netinet/in.h \
    setjmp.h sys/mman.h sys/param.h sys/poll.h sys/procset.h sys/select.h \
    sys/socket.h sys/stropts.h sys/time.h sys/un.h sys/wait.h unistd.h)

# --------------------------------------------
# Verify certain entries from AC_CHECK_HEADERS
# --------------------------------------------
for f in sys_types sys_mman sys_param sys_stat sys_wait \
         string errno stdlib memory setjmp
do eval as_ac_var=\${ac_cv_header_${f}_h+set}
   test "${as_ac_var}" = set || \
     AC_MSG_ERROR([You must have ${f}.h on your system])
done

# =================
# AC_CHECK_HEADERS: stdarg.h is present define HAVE_STDARG_H, otherwise
# if varargs.h is present define HAVE_VARARGS_H.
# =================
AC_CHECK_HEADERS(stdarg.h varargs.h, break)
if test `eval echo '${'$as_ac_Header'}'` != yes; then
  AC_MSG_ERROR([You must have either stdarg.h or varargs.h on your system])
fi

# =================
# Similarly for the string.h and strings.h headers
# =================
AC_CHECK_HEADERS(string.h strings.h, break)
if test `eval echo '${'$as_ac_Header'}'` != yes; then
  AC_MSG_ERROR([You must have either string.h or strings.h on your system])
fi

# =================
# ...and limits headers
# =================
AC_CHECK_HEADERS(limits.h sys/limits.h values.h, break)
if test `eval echo '${'$as_ac_Header'}'` != yes; then
  AC_MSG_ERROR([You must have limits.h, sys/limits.h or values.h on your system])
fi

# =================
# ...and directory read headers
# =================
AC_CHECK_HEADERS(dirent.h ndir.h sys/ndir.h, break)

# ----------------------------------------------------------------------
# AC_CHECK_LIB for SVR4 libgen, and use it if it defines pathfind.
# ----------------------------------------------------------------------
AC_CHECK_LIB(gen, pathfind)
  AC_MSG_CHECKING([whether autoopts-config can be found])
  AC_ARG_WITH([autoopts-config],
        AC_HELP_STRING([--with-autoopts-config],
                   [specify the config-info script]),
    [lo_cv_with_autoopts_config=${with_autoopts_config}],
    AC_CACHE_CHECK([whether autoopts-config is specified],
       lo_cv_with_autoopts_config,
       lo_cv_with_autoopts_config=autoopts-config)
  ) # end of AC_ARG_WITH
  AC_CACHE_VAL([lo_cv_test_autoopts],[
    aoconfig=${lo_cv_with_autoopts_config}
    lo_cv_test_autoopts=`${aoconfig} --libs` 2> /dev/null
    if test $? -ne 0 -o -z "$lo_cv_test_autoopts"
    then lo_cv_test_autoopts=no; fi
  ]) # end of CACHE_VAL
  AC_MSG_RESULT([${lo_cv_test_autoopts}])

  if test "X${lo_cv_test_autoopts}" != Xno
  then
    LIBOPTS_LDADD="${lo_cv_test_autoopts}"
    LIBOPTS_CFLAGS="`${aoconfig} --cflags`"
    NEED_LIBOPTS_DIR=''
  else
    LIBOPTS_LDADD='$(top_builddir)/libopts/libopts.la'
    LIBOPTS_CFLAGS='-I$(top_srcdir)/libopts'
    INVOKE_LIBOPTS_MACROS
    NEED_LIBOPTS_DIR=true
  fi
  AM_CONDITIONAL([NEED_LIBOPTS], [test -n "${NEED_LIBOPTS_DIR}"])
  AC_SUBST(LIBOPTS_LDADD)
  AC_SUBST(LIBOPTS_CFLAGS)
  AC_CONFIG_FILES([libopts/Makefile])
]) # end of AC_DEFUN of LIBOPTS_CHECK
