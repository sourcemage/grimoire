if is_depends_enabled $SPELL qtbase; then
  PATH+=":$QT5DIR/bin"
  PKG_CONFIG_PATH+=":$QT5DIR/lib/pkgconfig"
fi &&
export CXXFLAGS="$CXXFLAGS -pthread" &&
FFLAGS=$CFLAGS default_build
