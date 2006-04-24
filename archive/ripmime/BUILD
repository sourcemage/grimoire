sedit "/^CFLAGS/d;s|/usr/local|${INSTALL_ROOT}/usr|" Makefile  &&
sedit "s/^CFLAGS =/CFLAGS+=/" tnef/Makefile                    &&
sedit "/^CFLAGS/d" ripOLE/Makefile                             &&
make                                                           &&
make  libripmime
