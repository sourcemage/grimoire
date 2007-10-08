# avoid building examples, as they won't link properly
sed -i "/examples/D" CMakeLists.txt &&
# replace @ by :BOOL=ON in OPTS
OPTS="${OPTS//@/:BOOL=ON}"          &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr $OPTS ./ &&
make
