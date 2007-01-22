if [ "${ODE_SNAP}" == "y" ]; then
  disable_pic  &&
  make_single  &&
  sedit  '/C_FLAGS+/d'  config/makefile.unix-gcc  &&
  sedit  's/)1/)/'  Makefile                      &&
  make  PLATFORM=unix-gcc  OPT=""  C_OPT="$CFLAGS"  configure  ode-lib  $DRAWSTUFF_LIB
else
  default_build
fi
