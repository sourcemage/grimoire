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
make_single                        &&
if [[ "$(get_spell_provider $SPELL  X11-SERVER)" != "xorg-server" ]]; then
  make X11LIB=/usr/X11R6/lib/libX11.so
else
  make X11LIB=/usr/lib/libX11.so
fi                                 &&
if [ -e /tmp/netpbm ]; then
   rm -rf /tmp/netpbm              
fi                                 &&
make  package  pkgdir=/tmp/netpbm  &&
make_normal
