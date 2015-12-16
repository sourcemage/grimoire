if is_depends_enabled $SPELL qt4; then
  export PKG_CONFIG_PATH=$QT4DIR/lib/pkgconfig &&
  PATH+=":$QT4DIR/bin"
fi  &&
if is_depends_enabled $SPELL qtbase; then
  export PKG_CONFIG_PATH=$QT5DIR/lib/pkgconfig &&
  PATH+=":$QT5DIR/bin"
fi  &&

default_build

