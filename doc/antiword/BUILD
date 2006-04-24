rm Makefile &&
echo  "CFLAGS = $CFLAGS -DNDEBUG"  >  Makefile &&
grep  -v  "^CFLAGS"  Makefile.Linux  >>  Makefile &&
sedit  "s!/usr/local!${INSTALL_ROOT}/usr!"  Makefile &&

make
