  mv  -f  Makefile.DIST                     Makefile  &&
  sedit  "s/-O2/$CFLAGS/"                   Makefile  &&
  sedit  's/LDFLAGS =/LDFLAGS = -L\/usr\/X11R6\/lib/'  Makefile  &&
  make  all                                           &&
  mv  xearth.man  xearth.6                            &&
  gzip  -9  xearth.6
