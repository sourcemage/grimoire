cd $SOURCE_DIRECTORY/mythtv &&
export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig" &&
OPTS+=" $ENABLE_DVB $ENABLE_OSS $ENABLE_FIREWIRE $ENABLE_JOYSTICK --disable-distcc\
       --qmake=$QT5DIR/bin/qmake \
       --disable-systemd_notify"  &&
./configure  --prefix=/usr $OPTS  &&
make 
