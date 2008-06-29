cd src &&
sedit '1iIPEPREFIX = /usr' config.pri &&
sedit '34i#include <cstring>' ipelib/ipedct.cpp &&
sedit '41i#include <cstring>' ipelib/ipepdfwriter.cpp &&
# needs qt4 qmake or it links against qt3
$INSTALL_ROOT/usr/bin/qt4/qmake &&
make
