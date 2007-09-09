QTDIR=${QTDIR:-$INSTALL_ROOT/usr}                       &&
OPTS="$ENABLE_DVB \
      $OPTS"				                          &&
./configure  --prefix=/usr  --disable-distcc  $OPTS     &&
qmake  mythtv.pro                                       &&
make
