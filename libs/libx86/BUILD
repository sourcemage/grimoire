if  [[  "${SMGL_COMPAT_ARCHS[1]}"  ==  "x86_64" ]]; then
  OPTS="BACKEND=x86emu"
else
  OPTS=""
fi  &&

make  "LIBDIR=$INSTALL_ROOT/usr/lib  CFLAGS=$CFLAGS"  $OPTS
