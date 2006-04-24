(

  sedit  "s/-O2/$CFLAGS/"  Makefile
  make                  &&
  prepare_install       &&
  cp     wwl  /usr/bin  &&
  chmod  755  /usr/bin/wwl

) > $C_FIFO 2>&1
