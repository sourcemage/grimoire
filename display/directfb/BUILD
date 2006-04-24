if  [  -f  /usr/include/linux/fusion.h  ];  then
  OPTS="$OPTS --enable-multi"
fi  &&

OPTS="--enable-linux-input           \
      --with-gfxdrivers=$gfxdrivers  \
      $OPTS"                         &&

export CPPFLAGS="$CPPFLAGS -I/usr/include/libmpeg3/"  &&

default_build
