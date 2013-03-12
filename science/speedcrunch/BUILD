QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"
PATH="$QTDIR/bin/qt4:$PATH"
cd $SOURCE_DIRECTORY  &&
mkdir -p build        &&
cd build              &&
prepare_cmake_flags   &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr -DSYSCONFDIR=$INSTALL_ROOT/etc $OPTS ../src &&
make &&
if ! [ -f "$SOURCE_DIRECTORY"/src/ca.qm ]; then
  lrelease "$SOURCE_DIRECTORY"/src/speedcrunch.pro
fi
