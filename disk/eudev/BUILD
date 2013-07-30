cd $SOURCE_DIRECTORY &&

./configure prefix=$INSTALL_ROOT \
      --with-rootprefix=$INSTALL_ROOT \
      --with-rootlibdir=$INSTALL_ROOT/lib \
      --datarootdir=$INSTALL_ROOT/usr/share \
      --includedir=$INSTALL_ROOT/usr/include \
      --libdir=$INSTALL_ROOT/usr/lib \
      --with-firmware-path=$INSTALL_ROOT/lib/firmware \
      $UDEV_OPTS $UDEV_PERSIST $UDEV_MOD $OPTS &&
make
