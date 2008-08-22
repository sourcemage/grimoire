sed -i "s|-Werror||;s|-g|${CFLAGS}|" CMakeLists.txt &&
OPTS="-DPHYSFS_BUILD_STATIC=0 $OPTS"                             &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr $OPTS   .       &&
make
