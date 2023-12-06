disable_pic                 &&

OPTS="$MPLAYER_OPTS $OPTS"  &&

CFLAGS= ./configure  --prefix=${INSTALL_ROOT}/usr    \
             --confdir=${TRACK_ROOT}/etc/mplayer   \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             $OPTS          &&

if is_depends_enabled $SPELL openal; then
  make
else
  make_single &&
  make &&
  make_normal
fi
