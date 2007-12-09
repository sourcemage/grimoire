PREFIX=/usr    &&
PATH=$PREFIX/bin/qt4:$PATH  &&
QMAKE_CFLAGS_RELEASE=$CFLAGS  &&
QMAKE_CXXFLAGS_RELEASE=$CXXFLAGS  &&
QMAKE_LFLAGS_RELEASE=$LDFLAGS  &&
cd $SOURCE_DIRECTORY &&
./WebKitTools/Scripts/build-webkit \
  --qmakearg=WEBKIT_INC_DIR=$PREFIX/include/WebKit \
  --qmakearg=WEBKIT_LIB_DIR=$PREFIX/lib --gtk

