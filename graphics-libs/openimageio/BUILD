mkdir -p ${SOURCE_DIRECTORY}/build &&
cd ${SOURCE_DIRECTORY}/build       &&
CFLAGS="-Wno-error=deprecated-declarations $CFLAGS" &&
CXXFLAGS="-Wno-error=deprecated-declarations $CXXFLAGS" &&
prepare_cmake_flags                &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr -DSYSCONFDIR=$INSTALL_ROOT/etc $OPTS .. &&
default_build_make
