#stupid qt4 spell
PATH="$PATH:/usr/bin/qt4"                                       &&
disable_pic                                                     &&
QTDIR=${QTDIR:-$INSTALL_ROOT/usr}                               &&
OPTS="$ENABLE_DVB $ENABLE_OSS $ENABLE_FIREWIRE $ENABLE_JOYSTICK \
      --disable-distcc --qmake=/usr/bin/qt4/qmake               \
      $OPTS"				                        &&
./configure  --prefix=/usr $OPTS                                &&
make
