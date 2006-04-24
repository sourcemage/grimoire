(
  patch -p0<$SCRIPT_DIRECTORY/cl.patch &&
  sedit "s/-mpentium -O6 -Wall -ffast-math -fomit-frame-pointer -finline-functions -fexpensive-optimizations/$CFLAGS/" Makefile &&
  sedit "s!/usr/local/bin!/usr/bin!" Makefile &&
  make clean                  &&
  make                        &&
  prepare_install             &&
  make    install

) > $C_FIFO 2>&1
