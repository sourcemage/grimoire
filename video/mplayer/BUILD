invoke_gcc
# needed so it actually uses gcc 3.4
OPTS="$OPTS --cc=gcc"  &&

if [ "$MPLAYER_CVS" != "y" ]; then
  OPTS="$OPTS --enable-libavcodec"
else
  OPTS="$OPTS --with-extraincdir=/usr/include/ffmpeg"
fi  &&

# remove --enable-old-gtk for 1.0pre7try2 as it doesn't know that option
if [ "$MPLAYER_GUI" = "gtk+" -a "$MPLAYER_CVS" = "n" ]; then
  OPTS="${OPTS/--enable-old-gtk/}"
fi  &&

OPTS="$MPLAYER_OPTS $OPTS"  &&

CFLAGS= ./configure  --prefix=${INSTALL_ROOT}/usr    \
             --confdir=${TRACK_ROOT}/etc/mplayer     \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             $OPTS          &&

make
