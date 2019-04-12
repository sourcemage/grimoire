if is_depends_enabled ${SPELL} llvm; then
  CXXFLAGS="-stdlib=libc++ -I${INSTALL_ROOT}/usr/include ${CXXFLAGS}" &&
  LDFLAGS="-lc++ -lc++abi ${LDFLAGS}"
fi &&

cmake_build
