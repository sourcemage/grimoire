if is_depends_enabled $SPELL qt4; then
  QTDIR="$QT4DIR"
else
  QTDIR="$QT5DIR"
fi &&
PATH="$QTDIR/bin:$PATH" &&
export PKG_CONFIG_PATH="$QTDIR/lib/pkgconfig" &&
db48="$INSTALL_ROOT/opt/db48" &&
CPPFLAGS="$CPPFLAGS -I$db48/include" &&
LDFLAGS="$LDFLAGS -L$db48/lib" &&
default_build
