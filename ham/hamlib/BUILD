(

  sedit  "s:-O2:$CFLAGS:g"  configure  &&

  ./configure  --prefix=/usr  $OPTS    &&

  make                                 &&
  prepare_install                      &&
  make    install

)  >  $C_FIFO  2>&1
