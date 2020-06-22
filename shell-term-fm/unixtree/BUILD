make_single           &&
source build -r linux &&
if ! echo $OPTS | grep -q 'with-x'; then
  unset X11_LIBS &&
  unset X11_INCS &&
  unset XPMDIR &&
  export USE_X11=no &&
  export LIBXVT=libxvt-dummy
fi &&
make OPTS="$CFLAGS"
