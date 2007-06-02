# avoid building examples, as they won't link properly
sed -i "/examples/D" CMakeLists.txt &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr ./   &&
make
