(
  sedit "s/^CFLAGS =/CFLAGS +=/" Makefile	&&
  make                   &&
  make doc               &&
  prepare_install        &&
  cp clara /usr/bin      
) > $C_FIFO 2>&1
