mkdir -p ${SOURCE_DIRECTORY}/build &&
cd ${SOURCE_DIRECTORY}/build       &&
prepare_cmake_flags                &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr -DSYSCONFDIR=$INSTALL_ROOT/etc $OPTS ../src &&
default_build_make
