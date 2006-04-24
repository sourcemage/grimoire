  patch -p1 < $SCRIPT_DIRECTORY/zoo-gcc3.3.patch &&
  sedit  "s:-O3:$CFLAGS:"  makefile  &&
  make    linux
