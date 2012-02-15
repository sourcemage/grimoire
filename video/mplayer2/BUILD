#disable_pic                 &&

OPTS="$MPLAYER_OPTS $MPLAYER_IVTV $OPTS"  &&

CFLAGS= ./configure  --prefix=${INSTALL_ROOT}/usr  \
             --confdir=${TRACK_ROOT}/etc/mplayer   \
             $OPTS  &&

if is_depends_enabled $SPELL openal; then
  make
else
  make_single &&
  make &&
  make_normal
fi
