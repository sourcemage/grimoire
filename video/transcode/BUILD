if echo $OPTS | grep -q enable-lzo; then
  CFLAGS="$CFLAGS -I/usr/include/lzo" &&
  export CPPFLAGS="$CPPFLAGS -I/usr/include/lzo"
fi &&
OPTS="$OPTS --enable-v4l"  &&
make_single                &&
default_build              &&
make_normal
