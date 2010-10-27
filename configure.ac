dnl Ensure that this file is processed with autoconf 2.50 or newer
dnl Don't even think about removing this check!
AC_PREREQ(2.50)

AC_INIT(Makefile.am)

AM_INIT_AUTOMAKE(libxmlccwrap,0.0.12)

AC_PROG_CXX
AC_LANG_CPLUSPLUS
AC_PROG_INSTALL

AC_DISABLE_STATIC
AC_PROG_LIBTOOL
AM_PROG_LIBTOOL

AC_CHECK_LIB(xml2,main)
AC_CHECK_LIB(xslt,main)

AC_OUTPUT([Makefile \
          xmlccwrap/Makefile \
          html/Makefile \
          html/pics/Makefile \
	  testlib/Makefile ])
	  
echo "
$PACKAGE $VERSION
configuration:
--------------

 compiler ....... : ${CXX} 
 --prefix ....... : ${prefix}
 --exec-prefix .. : ${exec_prefix}
 

 Now type 'make' to build $PACKAGE $VERSION.
"	  
