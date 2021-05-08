if is_depends_enabled ${SPELL} llvm; then
  disable_stack_clash_protection &&
  CC=clang CXX=clang++ CFLAGS="$CFLAGS" CXXFLAGS="$CXXFLAGS" ./configure --prefix=$INSTALL_ROOT/usr $OPTS
else
  ./configure --prefix=$INSTALL_ROOT/usr $OPTS
fi &&

# necessary for linking:
ulimit -n 65535 &&

default_build_make
