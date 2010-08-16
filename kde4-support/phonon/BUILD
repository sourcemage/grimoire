QTDIR=$INSTALL_ROOT/usr/bin/qt4 &&
PATH="$QTDIR:$PATH"   &&
KDE4DIR=$INSTALL_ROOT/opt/kde4 &&
cd $SOURCE_DIRECTORY  &&
mkdir -p build        &&
cd build              &&
cmake -DCMAKE_INSTALL_PREFIX=$KDE4DIR  $OPTS $SOURCE_DIRECTORY &&
make

