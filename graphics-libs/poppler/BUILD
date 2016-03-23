OPTS="$POPPLER_OPTS $OPTS" &&

# -lm fixes the ./configure problem (http://www.sourcemage.org/issues/15)
LDFLAGS="-lm $LDFLAGS" &&

if is_depends_enabled $SPELL qt4; then
  export PATH="$QT4DIR/bin:$PATH" &&
  export PKG_CONFIG_PATH="$QT4DIR/lib/pkgconfig/"
fi &&
if is_depends_enabled $SPELL qtbase; then
  export PATH="$QT5DIR/bin:$PATH" &&
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig/"
fi &&

default_build
