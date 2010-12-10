QTDIR=$INSTALL_ROOT/usr/bin/qt4 &&
PATH="$QTDIR:$PATH"   &&
cd $SOURCE_DIRECTORY  &&
mkdir -p build        &&
cd build              &&
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_ROOT/usr $OPTS $SOURCE_DIRECTORY &&
make

