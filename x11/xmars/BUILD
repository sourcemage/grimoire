(

  mv  -f  Makefile.DIST                     Makefile  &&
  sedit  "s/-O2/$CFLAGS/"                   Makefile  &&
  make  all                                           &&
  mv  xmars.man  xmars.6                              &&
  gzip  -9  xmars.6                                   &&
  prepare_install                                     &&
  install  -m  755  xearth      /usr/X11R6/bin/xmars  &&
  mkdir  -p  /usr/man/man6                            &&
  install  -m  644  xmars.6.gz  /usr/man/man6

)  >  $C_FIFO  2>&1
