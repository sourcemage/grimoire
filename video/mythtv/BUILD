#sedit  "s:/usr/local:$INSTALL_ROOT/usr:"  configure     &&
#sedit  "s:/usr/local:$INSTALL_ROOT/usr:"  settings.pro  &&
invoke_gcc
./configure  --prefix=/usr  --disable-distcc  $OPTS     &&
qmake  mythtv.pro                                       &&
make
