OPTS="$OPTS --enable-gpl --enable-gpl3 --disable-debug $MLT_KDEN $MLT_KINO $MLT_SCALE"  &&        
if is_depends_enabled $SPELL qtbase;then
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig" &&
  PATH="$QT5DIR/bin:$PATH"
fi &&
if is_depends_enabled $SPELL qt4;then
  export PKG_CONFIG_PATH="$QT4DIR/lib/pkgconfig" &&
  PATH="$QT4DIR/bin:$PATH"
fi &&
default_build
