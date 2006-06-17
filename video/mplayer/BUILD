if [[ $MPLAYER_SVN = y ]]; then
  OPTS="$OPTS --with-extraincdir=/usr/include/ffmpeg"
fi  &&

OPTS="$MPLAYER_OPTS $OPTS"  &&

CFLAGS= ./configure  --prefix=${INSTALL_ROOT}/usr    \
             --confdir=${TRACK_ROOT}/etc/mplayer     \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             $OPTS          &&

make
