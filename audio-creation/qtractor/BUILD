OPTS="$OPTS --with-qt=${INSTALL_ROOT}/usr/bin/qt4"  \
default_build_configure                             &&

QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"  &&
PATH="$QTDIR/bin/qt4:$PATH"          &&
qmake                                &&
make
