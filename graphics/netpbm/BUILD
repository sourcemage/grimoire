if [[ "${NETPBM_SVN}" == 'y' ]]; then
  CONFIGFILE=config.mk
else
  CONFIGFILE=Makefile.config
fi &&
cp ${CONFIGFILE}.in $CONFIGFILE &&
cat >> $CONFIGFILE << EOF
DEFAULT_TARGET = nonmerge
NETPBMLIBTYPE=unixshared
NETPBMLIBSUFFIX=so
STATICLIB_TOO=n
CFLAGs = $CFLAGS
CFLAGS_MERGE = -Wno-missing-declarations -Wno-missing-prototypes -fno-common
LDRELOC = ld --reloc
LINKER_CAN_DO_EXPLICIT_LIBRARY = Y
LINKERISCOMPILER = Y
CFLAGS_SHLIN += -fPIC
NETPBM_DOCURL = http://netpbm.sourceforge.net/doc/
PNGLIB = libpng.so
SYMLINK = ln -sf
EOF
if list_find "$OPTS" yes-jpeg; then
  echo "JPEGLIB = libjpeg.so" >> $CONFIGFILE
fi &&
if list_find "$OPTS" yes-tiff; then
  echo "TIFFLIB = libtiff.so" >> $CONFIGFILE
fi &&
if list_find "$OPTS" yes-zlib; then
  echo "ZLIB = libz.so" >> $CONFIGFILE
fi &&
if list_find "$OPTS" yes-x11; then
  echo "X11LIB = /usr/lib/libX11.so" >> $CONFIGFILE
fi &&
if list_find "$OPTS" yes-svga; then
  echo "LINUXSVGALIB = libvga.so" >> $CONFIGFILE
fi &&
sedit "s/^\(CFLAGS =\)/\1 ${CFLAGS} /" $CONFIGFILE &&
make
