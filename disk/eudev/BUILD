cd $SOURCE_DIRECTORY &&

./configure \
      --prefix=$INSTALL_ROOT \
      --with-rootprefix=$INSTALL_ROOT \
      --with-rootlibdir=$INSTALL_ROOT/lib \
      --datarootdir=$INSTALL_ROOT/usr/share \
      --includedir=$INSTALL_ROOT/usr/include \
      --libdir=$INSTALL_ROOT/usr/lib \
      $UDEV_OPTS $UDEV_PERSIST $OPTS &&
make
