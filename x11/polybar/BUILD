OPTS="${POLYBAR_OPTS} ${OPTS}" &&

# disable buggy options (see https://github.com/jaagr/polybar/issues/1730)
OPTS="-DWITH_XRENDER=OFF \
      -DWITH_XDAMAGE=OFF \
      -DWITH_XSYNC=OFF \
      ${OPTS}" &&

if is_depends_enabled ${SPELL} llvm && is_depends_enabled ${SPELL} ccache; then
  CXXFLAGS="-Wno-error=unused-command-line-argument ${CXXFLAGS}"
fi &&

cmake_build
