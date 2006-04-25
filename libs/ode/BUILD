disable_pic  &&
sedit  '/C_FLAGS+/d'  config/makefile.unix-gcc  &&
sedit  's/)1/)/'  Makefile                      &&

make_single  &&
make  PLATFORM=unix-gcc  OPT=""  C_OPT="$CFLAGS"  configure  ode-lib
