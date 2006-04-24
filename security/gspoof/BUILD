(

  sedit  "s/local\///"                 Makefile
  sedit  "s/-O3 -ansi -Wall/$CFLAGS/"  Makefile

  make gtk           &&
  prepare_install    &&
  make install

) > $C_FIFO 2>&1
