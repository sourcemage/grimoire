cd src &&
sed -i '1 i\ IPEPREFIX  = /usr' config.pri &&
# needs qt4 qmake or it links against qt3
$INSTALL_ROOT/usr/bin/qt4/qmake &&
make
