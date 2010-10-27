INCLUDES = -I$(top_srcdir) `xml2-config --cflags`

noinst_PROGRAMS=testlib
testlib_SOURCES=testlib.cc
testlib_LDADD=../xmlccwrap/libxmlccwrap.la

EXTRA_DIST = test_badquot.xml \
		test_badxml.xml \
		test.xsl \
		test_data.xml
