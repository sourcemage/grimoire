OPTS="$OPTS $PINENTRY_CURSES $PINENTRY_TTY" &&
if is_depends_enabled $SPELL qtbase;then
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig"
  export PATH+=":$QT5DIR/bin"
elif is_depends_enabled $SPELL qt4;then
  export PKG_CONFIG_PATH="$QT4DIR/lib/pkgconfig"
  export PATH+=":$QT4DIR/bin"
fi &&
CXXFLAGS+=" -std=c++11" &&
default_build
