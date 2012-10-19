QTDIR="${QTDIR:-$INSTALL_ROOT/usr}" &&
PATH="$QTDIR/bin/qt4:$PATH" &&

cd meshlab/src/external &&
qmake PREFIX=$INSTALL_ROOT/usr -recursive external.pro &&
make &&

cd .. &&
qmake PREFIX=$INSTALL_ROOT/usr -recursive meshlab_full.pro &&
make
