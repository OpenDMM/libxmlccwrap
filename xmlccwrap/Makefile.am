lib_LTLIBRARIES = libxmlccwrap.la

INCLUDES = -I$(top_srcdir) `xml2-config --cflags` `xslt-config --cflags`
  
libxmlccwrap_la_LDFLAGS = -release $(VERSION)
libxmlccwrap_la_SOURCES=xmlccwrap.cc libxmlexport.cc

pkginclude_HEADERS = xmlccwrap.h libxmlexport.h
pkgincludedir= $(includedir)/xmlccwrap
