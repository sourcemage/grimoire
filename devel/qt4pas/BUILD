#fpc qt4.pas           &&
QT4=/usr/lib          &&
QT4I=/usr/include     &&
g++ $CPPFLAGS -DBINUX -I. -I$QT4I -I$QT4I/Qt -I$QT4I/QtGui -I$QT4I/QtCore qtpas.cpp \
   -o libqt4intf.so -shared -fPIC -dPIC -L$QT4 -lQtCore -lQtGui -lQtNetwork -lQtWebKit\
    -Wl,-rpath,$QT4 \
   -Xlinker "-soname=libqt4intf.so"

