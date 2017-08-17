CXXFLAGS="-D_GLIBCXX_USE_NANOSLEEP ${CXXFLAGS}" &&

if is_depends_enabled ${SPELL} boost; then
  LDFLAGS="-lboost_regex ${LDFLAGS}"
fi &&

OPTS="-DCMAKE_INSTALL_MANDIR=${INSTALL_ROOT}/usr/share/man ${OPTS}" &&

cmake_build
