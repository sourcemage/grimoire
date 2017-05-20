OPTS="--disable-dependency-tracking $OPTS"  &&

# help configure to find needed QT4 binaries
# if not exported, configure doesn't find them
if is_depends_enabled $SPELL qt4; then
  export PKG_CONFIG_PATH=$QT4DIR/lib/pkgconfig
fi  &&
if is_depends_enabled $SPELL qtbase; then
  export PKG_CONFIG_PATH=$QT5DIR/lib/pkgconfig
fi  &&

if is_depends_enabled $SPELL goom; then
  LDFLAGS=${LDFLAGS/-Wl,--as-needed}
fi &&
BUILDCC=gcc default_build
