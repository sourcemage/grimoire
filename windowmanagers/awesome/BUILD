sed -i "s|-Werror||;s|-g|${CFLAGS}|" CMakeLists.txt    &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr $OPTS . &&
make
