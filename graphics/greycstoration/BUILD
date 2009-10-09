cd src  &&
sedit "s:CFLAGS   =:CFLAGS   = ${CFLAGS}:" Makefile   &&
sedit "s:LDFLAGS  =:LDFLAGS  = ${LDFLAGS}:" Makefile  &&
sedit "s:/usr:${TRACK_ROOT}/usr:" Makefile            &&
sedit "s:/X11R6::" Makefile                           &&
make linux
