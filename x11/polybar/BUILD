OPTS="${POLYBAR_OPTS} ${OPTS}" &&

if is_depends_enabled ${SPELL} llvm && is_depends_enabled ${SPELL} ccache; then
  CXXFLAGS="-Wno-error=unused-command-line-argument ${CXXFLAGS}"
fi &&

cmake_build
