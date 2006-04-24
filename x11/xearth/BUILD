(

  mv  -f  Makefile.DIST                     Makefile  &&
  sedit  "s/-O2/$CFLAGS/"                   Makefile  &&
  sedit  's/LDFLAGS =/LDFLAGS = -L\/usr\/X11R6\/lib/'  Makefile  &&
  make  all                                           &&
  mv  xearth.man  xearth.6                            &&
  gzip  -9  xearth.6                                  &&
  prepare_install                                     &&
  install  -m  755  xearth      /usr/X11R6/bin/       &&
  install  -m  644  xearth.6.gz  /usr/man/man6

)  >  $C_FIFO  2>&1
