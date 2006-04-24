  ./configure  Linux  --prefix=${INSTALL_ROOT}/usr  --CFLAGS="$CFLAGS"  $OPTS	&&
  sedit "s/gmake/make/" Makefile                                &&
### addding -lstdc++ so it finds the g++ symbols needed by some object files
  sedit "s/..\/fio.o/& -lstdc++/" endeavour2/utils/Makefile     &&
  make   all
