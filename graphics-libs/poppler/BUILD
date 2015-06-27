OPTS="$POPPLER_OPTS $OPTS" &&

# -lm fixes the ./configure problem (http://www.sourcemage.org/issues/15)
LDFLAGS="-lm $LDFLAGS" &&

if is_depends_enabled $SPELL qt4; then
  export PATH="$INSTALL_ROOT/opt/qt4/bin:$PATH" &&
  export PKG_CONFIG_PATH="$INSTALL_ROOT/opt/qt4/lib/pkgconfig/"
fi &&

default_build
