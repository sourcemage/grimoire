(
  sedit "/CFLAGS/d" src/Makefile.am		&&
  sedit "s|AM_GNU_GETTEXT||" configure.in	&&
  ./configure --prefix=/usr $OPTS 		&&
  make                   	&&
  prepare_install        	&&
  make    install        	
#  mkdir -p /usr/doc/pxtools	&&
#  cp README /usr/doc/pxtools/	&&
#  cp doc/*.txt /usr/doc/pxtools/

) > $C_FIFO 2>&1
