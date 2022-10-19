OPTS="$XHOST_OPTS $OPTS"  &&
if is_depends_enabled "$SPELL" libtirpc; then
  CFLAGS+=" $(pkg-config libtirpc --cflags)" &&
  LIBS+=" $(pkg-config libtirpc --libs)" &&
  export LIBS
fi &&
default_build
