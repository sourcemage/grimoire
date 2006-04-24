cd  make/linux   &&
sedit  "s:/usr/local:${INSTALL_ROOT}/usr:"  Makefile  &&
sedit  "s:^\(LIBEBML_INCLUDE_DIR=\).*$:\1${INSTALL_ROOT}/usr/include/ebml:"  \
       Makefile  &&
sedit  "s:^\(LIBEBML_LIB_DIR=\).*$:\1${INSTALL_ROOT}/usr/lib:"  \
       Makefile  &&
make
