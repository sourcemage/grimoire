sedit  "s/-O2/${CFLAGS}/"  Makefile          &&
sedit  "s/^lib64 .*/lib64 := lib/"  Makefile &&
sedit  "s/-ffast-math//" Makefile            &&
make_single                                  &&
make  -e  XSCPT=''  DESTDIR=${INSTALL_ROOT}
