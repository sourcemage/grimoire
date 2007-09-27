# avoid building examples, as they won't link properly
sed -i "/examples/D" CMakeLists.txt &&
# replace @ by :BOOL=ON in OPTS
local NN                                                &&
for NN in ASPELL FLTK SQLITE3 POSTGRESQL ODBC; do
  OPTS="${OPTS/@/:BOOL=ON}"
done                                                    &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr $OPTS ./ &&
make
