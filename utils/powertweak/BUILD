(
  sedit "s/-O2/$CFLAGS/" configure.in	&&
  autoconf		&&
  ./configure --prefix=/usr $OPTS &&
  make                   &&
  prepare_install        &&
  make    install        &&
  mkdir -p /usr/doc/$SPELL	&&
  cp -rPp Documentation/ /usr/doc/$SPELL

) > $C_FIFO 2>&1
