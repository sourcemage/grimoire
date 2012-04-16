OPTS="$POPPLER_OPTS $OPTS" &&

# fixing issue #382
if is_depends_enabled $SPELL openjpeg; then
    CXXFLAGS="$CXXFLAGS -I${INSTALL_ROOT}/usr/include/openjpeg-1.5"
fi &&

# -lm fixes the ./configure problem (http://www.sourcemage.org/issues/15)
LDFLAGS="-lm $LDFLAGS" &&

if is_depends_enabled $SPELL qt4; then
  export PATH="$INSTALL_ROOT/usr/bin/qt4:$PATH"
fi &&

default_build
