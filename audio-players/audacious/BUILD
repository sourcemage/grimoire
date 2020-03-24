if is_depends_enabled ${SPELL} llvm; then
  OPTS="CXX=clang++ ${OPTS}" &&

  CXXFLAGS="-stdlib=libc++ ${CXXFLAGS}" &&
  LDFLAGS="-lc++ -lc++abi ${LDFLAGS}"
fi &&

OPTS="--with-buildstamp=SMGL $OPTS" &&

default_build
