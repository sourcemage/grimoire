# fix configure so it uses -mmmx, necessary to compile on gcc 4.0.x
if use_gcc ^4; then
  patch  configure  $SCRIPT_DIRECTORY/liboil-configure-fix.diff
fi  &&
make_single    &&
default_build  &&
make_normal
