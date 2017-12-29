NULL=
BUILT_SOURCES =
CLEANFILES =
noinst_LIBRARIES = libaes128cmac.a

check_PROGRAMS = validate-aes test-aes-openssl
validate_aes_LDADD = -L. -laes128cmac
test_aes_openssl_LDADD = -lcrypto

libaes128cmac_a_SOURCES =	\
	aes-omac1.c		\
	aes.h			\
	aes_wrap.h		\
	build_config.h		\
	common.h		\
	includes.h		\
	os.h			\
	wpa_debug.h		\
	wpabuf.h		\
	$(NULL)

validate_aes_SOURCES =	\
	rfc4493-test.c	\
	$(NULL)
