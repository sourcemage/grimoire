CXXFLAGS+=" -Wno-deprecated-declarations" &&
# -Ofast breaks other projects (Firefox)
CFLAGS="${CFLAGS//-Ofast/-O2}" &&
CXXFLAGS="${CXXFLAGS//-Ofast/-O2}" &&

if is_depends_enabled ${SPELL} llvm; then
  disable_stack_clash_protection &&
  CC=clang CXX=clang++ CFLAGS="$CFLAGS" CXXFLAGS="$CXXFLAGS"
fi &&
./configure --prefix=$INSTALL_ROOT/usr $OPTS &&

# necessary for linking:
ulimit -n 65535 &&
# don't bother with the make phase, do dummy install immediately
mkdir "$SOURCE_DIRECTORY/fake" &&
make install DESTDIR="$SOURCE_DIRECTORY/fake"
