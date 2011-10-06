QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"
PATH="$QTDIR/bin/qt4:$PATH"
cd lib &&
qmake PREFIX=$INSTALL_ROOT/usr CONFIG+=create_prl &&
default_build_make &&
cd ${SOURCE_DIRECTORY}/translations &&
lrelease assistant_adp_*.ts
