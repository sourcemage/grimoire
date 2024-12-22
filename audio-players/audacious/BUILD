if is_depends_enabled ${SPELL} llvm; then
  OPTS="CXX=clang++ ${OPTS}" &&

  CXXFLAGS="-stdlib=libc++ ${CXXFLAGS}" &&
  LDFLAGS="-lc++ -lc++abi ${LDFLAGS}"
fi &&

OPTS+=" buildstamp=SMGL" &&
if is_depends_enabled ${SPELL} qt6base;then
  export QT6DIR=$INSTALL_ROOT/opt/qt6
  export PKG_CONFIG_PATH="$QT6DIR/lib/pkgconfig"
fi &&
default_build
