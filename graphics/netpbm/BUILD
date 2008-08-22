cp Makefile.config.in Makefile.config &&
cat >> Makefile.config << EOF
DEFAULT_TARGET = nonmerge
NETPBMLIBTYPE=unixshared
NETPBMLIBSUFFIX=so
STATICLIB_TOO=n
CFLAGS = -O3 -ffast-math -pedantic -fno-common -Wall -Wno-uninitialized -Wmissing-declarations -Wimplicit -Wwrite-strings -Wmissing-prototypes -Wundef
CFLAGS_MERGE = -Wno-missing-declarations -Wno-missing-prototypes
LDRELOC = ld --reloc
LINKER_CAN_DO_EXPLICIT_LIBRARY = Y
LINKERISCOMPILER = Y
CFLAGS_SHLIN += -fPIC
NETPBM_DOCURL = http://netpbm.sourceforge.net/doc/
EOF
if list_find "$OPTS" yes-jpeg; then
  echo "JPEGLIB = libjpeg.so" >> Makefile.config
fi &&
if list_find "$OPTS" yes-tiff; then
  echo "TIFFLIB = libtiff.so" >> Makefile.config
fi &&
if list_find "$OPTS" yes-zlib; then
  echo "ZLIB = libz.so" >> Makefile.config
fi &&
if list_find "$OPTS" yes-x11; then
  echo "X11LIB = /usr/lib/libX11.so" >> Makefile.config
fi &&
if list_find "$OPTS" yes-svga; then
  echo "LINUXSVGALIB = libvga.so" >> Makefile.config
fi &&
sedit "s/^\(CFLAGS =\)/\1 ${CFLAGS} /" Makefile.config &&
make_single &&
make &&
if [ -e /tmp/netpbm ]; then
   rm -rf /tmp/netpbm              
fi &&
make package pkgdir=/tmp/netpbm &&
make_normal
