#sedit  "s/^CFLAGS_SHLIB =/CFLAGS_SHLIB = ${CFLAGS}/" Makefile.config.in &&
#sedit  "s/^\(CFLAGS_FOR_BUILD = \)\$(CFLAGS)/\1${CFLAGS}/" Makefile.config.in &&
echo  -e  "\ngnu\nregular\nshared\ny\n\n\n\n\n\n\n\n\n\n\n\n\n\n"  |
#  Ignores  $OPTS
# to get our OPTS and CFLAGS, etc we'll need to sed Makefile.config.in
./configure                        &&
# I have no idea how netpbm gets its standard set
# of cflags, the entries in Makefile.config.in are all
# commented out!
sedit  "s/^\(CFLAGS =\)/\1 ${CFLAGS} /" Makefile.config &&
if list_find "$OPTS" no-x11
then
  message "disabling X11 stuff" &&
  sedit 's/^\(X11LIB =\).*$/\1 NONE/' \
  Makefile.config &&
  sedit 's/^\(X11HDR_DIR =\).*$/\1/' \
  Makefile.config
fi &&
if list_find "$OPTS" no-svga
then
  message "disabling svgalib stuff" &&
  sedit 's/^\(LINUXSVGALIB =\).*$/\1 NONE/' \
  Makefile.config &&
  sedit 's/^\(LINUXSVGAHDR_DIR =\).*$/\1/' \
  Makefile.config
fi &&
make_single                        &&

make  &&

if [ -e /tmp/netpbm ]; then
   rm -rf /tmp/netpbm              
fi                                 &&
make  package  pkgdir=/tmp/netpbm  &&
make_normal
