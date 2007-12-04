if [[ $MPLAYER_SVN = y ]]; then
  OPTS="$OPTS --with-extraincdir=${INSTALL_ROOT}/usr/include/ffmpeg"
fi  &&

disable_pic                 &&

OPTS="$MPLAYER_OPTS $OPTS"  &&

CFLAGS= ./configure  --prefix=${INSTALL_ROOT}/usr    \
             --confdir=${TRACK_ROOT}/etc/mplayer   \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             $OPTS          &&

make
