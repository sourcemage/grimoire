if is_depends_enabled ${SPELL} llvm; then
  CC=clang CXX=clang++ ./configure --prefix=$INSTALL_ROOT/usr $OPTS
else
  ./configure --prefix=$INSTALL_ROOT/usr $OPTS
fi &&

make
