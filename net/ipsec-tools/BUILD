OPTS="--with-kernel-headers=$TRACK_ROOT/usr/include \
      --enable-shared \
      $OPTS" &&

# fixes compilation with GCC 4.4
CFLAGS="-fno-strict-aliasing $CFLAGS" &&

default_build
