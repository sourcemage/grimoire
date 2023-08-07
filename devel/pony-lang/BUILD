make libs build_flags="-j${MAKE_NJOBS}" prefix="${INSTALL_ROOT}/usr" &&

if ! is_depends_enabled $SPELL llvm; then
  make configure prefix="${INSTALL_ROOT}/usr" CC=gcc CXX=g++
else
  make configure prefix="${INSTALL_ROOT}/usr"
fi &&

make build prefix="${INSTALL_ROOT}/usr"
