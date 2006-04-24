#  ./configure --prefix=${INSTALL_ROOT}/usr $OPTS &&
  sed -i -e \
"s/-03/$CFLAGS/;s/\$(IBPP_PATH)//g;s/-L//;s:-I:-I/usr/include:" \
		Makefile	&&
  make
