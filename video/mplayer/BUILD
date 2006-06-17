# needed so it actually uses gcc 3.4
OPTS="$OPTS --cc=gcc"  &&

if [[ $MPLAYER_SVN = n ]]; then
  OPTS="$OPTS --enable-libavcodec"
else
  OPTS="$OPTS --with-extraincdir=/usr/include/ffmpeg"
fi  &&

# remove --enable-old-gtk for 1.0pre7try2 as it doesn't know that option
if [[ $MPLAYER_GUI = gtk+ && $MPLAYER_SVN = n ]]; then
  OPTS="${OPTS/--enable-old-gtk/}"
fi  &&
if [ "$MPLAYER_JOYSTICK" = "y" ]; then
  OPTS="$OPTS --enable-joystick"
fi  &&
if [ "$MPLAYER_OSD_MENU" = "y" ]; then
  OPTS="$OPTS --enable-menu"
fi  &&
if [ "$MPLAYER_MENCODER" = "n" ]; then
  OPTS="$OPTS --disable-mencoder"
fi  &&

CFLAGS= ./configure  --prefix=${INSTALL_ROOT}/usr    \
             --confdir=${TRACK_ROOT}/etc/mplayer     \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             $OPTS          &&

make
