QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"    &&
PATH="$QTDIR/bin/qt4:$PATH"            &&

cd  "$SOURCE_DIRECTORY"                &&
WebKitTools/Scripts/build-webkit --qt  &&

cd  WebKitBuild/Release                &&
make
