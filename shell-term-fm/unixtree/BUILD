find -name makefile | while read M; do
  # they should not redefine behavior of a standard variable
  sedit 's|CFLAGS|COMPILE_FLAGS|g' $M &&
  # don't redefine this variables inside makefiles
  sedit 's/^\(LIBXVT\|X11_LIBS\).*=.*//g' $M
done &&
make_single           &&
source build -r linux &&
if ! echo $OPTS | grep -q 'with-x'; then
  unset X11_LIBS &&
  unset X11_INCS &&
  unset XPMDIR &&
  export USE_X11=no &&
  export LIBXVT=libxvt-dummy
fi &&
make
