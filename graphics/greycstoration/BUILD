cd src  &&
sedit "s:CFLAGS   =:CFLAGS   = ${CFLAGS}:" Makefile   &&
sedit "s:LDFLAGS  =:LDFLAGS  = ${LDFLAGS}:" Makefile  &&
sedit "s:/usr:${TRACK_ROOT}/usr:" Makefile  &&
if  check_if_xorg_modular_libs  ;  then
  sedit "s:/X11R6::" Makefile
fi  &&
make linux
