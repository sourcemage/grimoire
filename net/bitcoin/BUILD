if is_depends_enabled $SPELL qt4; then
  PATH="$QT4DIR:$PATH"
else
  PATH="$QT5DIR:$PATH"
fi &&
db48="$INSTALL_ROOT/opt/db48" &&
CPPFLAGS="$CPPFLAGS -I$db48/include" &&
LDFLAGS="$LDFLAGS -L$db48/lib" &&
default_build
