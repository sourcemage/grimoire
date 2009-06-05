QTDIR="${QTDIR:-$INSTALL_ROOT/usr}" &&
PATH="$QTDIR/bin/qt4:$PATH" &&
INCLUDE="${INSTALL_ROOT}/usr/include" &&

cd $SOURCE_DIRECTORY/generator &&
qmake PREFIX=$INSTALL_ROOT/usr &&
make &&
$SOURCE_DIRECTORY/generator/generator --include-paths=${INCLUDE} &&

cd $SOURCE_DIRECTORY/qtbindings &&
qmake PREFIX=$INSTALL_ROOT/usr &&
make
