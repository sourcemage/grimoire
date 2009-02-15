if [[ $EX_VER == y ]];then
qt4_cmake_build
else
QTDIR="${QTDIR:-$INSTALL_ROOT/usr}" &&
PATH="$QTDIR/bin/qt4:$PATH" &&
qmake -set ZINT_INSTALL_LIBS ${INSTALL_ROOT}/usr/lib
qmake -set ZINT_INSTALL_HEADERS ${INSTALL_ROOT}/usr/include

qmake -set QUAZIP_INSTALL_LIBS ${INSTALL_ROOT}/usr/lib  &&
qmake -set QUAZIP_INSTALL_HEADERS ${INSTALL_ROOT}/usr/include &&

qmake -set EXARO_INSTALL_BINS ${INSTALL_ROOT}/usr/bin &&
qmake -set EXARO_INSTALL_LIBS ${INSTALL_ROOT}/usr/lib &&
qmake -set EXARO_INSTALL_HEADERS ${INSTALL_ROOT}/usr/include &&
qmake -set EXARO_INSTALL_PLUGINS ${INSTALL_ROOT}/usr/lib &&

qmake -set EXARO_INSTALL_MIMELNKS ${INSTALL_ROOT}/usr/share/mimelnk/application &&
qmake -set EXARO_INSTALL_MIMES ${INSTALL_ROOT}/usr/share/mime &&
qmake -set EXARO_INSTALL_MENUS ${INSTALL_ROOT}/usr/share/applications &&
qmake -set EXARO_INSTALL_ICONS ${INSTALL_ROOT}/usr/share/icons &&

qmake -set EXARO_INSTALL_TRANSLATIONS ${INSTALL_ROOT}/usr/share/eXaro/translations &&
qmake &&
make
fi
