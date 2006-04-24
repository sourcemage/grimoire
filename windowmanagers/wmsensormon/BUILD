cd wmsensormon                                &&
sedit "s:/usr/local/bin:${INSTALL_ROOT}/usr/bin:g" Makefile  &&
sedit "s/CFLAGS = -Wall -O3/CFLAGS = $CFLAGS/" Makefile      &&
sedit "s:wmsensormon.1.bz2:wmsensormon.1:" Makefile          &&
make
