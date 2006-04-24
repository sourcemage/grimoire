  mv  -f  Makefile.DIST                     Makefile  &&
  sedit  "s/-O2/$CFLAGS/"                   Makefile  &&
  make  all                                           &&
  mv  xmars.man  xmars.6                              &&
  gzip  -9  xmars.6 
