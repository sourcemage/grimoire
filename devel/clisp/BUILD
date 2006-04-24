#
# This unset is needed to fix:
# configure: loading cache ../config.cache
# configure: error: `CFLAGS' has changed since the previous run:
# configure:   former value:  -O -march=pentium4 -mmmx -mfpmath=sse -msse
#   -msse2 -pipe -DPIC -fPIC -Os
# configure:   current value: -W -Wswitch -Wcomment -Wpointer-arith -Wimplicit
#   -Wreturn-type -Wmissing-declarations -Wno-sign-compare -O2
#   -fexpensive-optimizations -DUNICODE -DDYNAMIC_FFI -I.
# configure: error: changes in the environment can compromise the build
# configure: error: run `make distclean' and/or `rm ../config.cache' and start
#   over
#
# The prior symlink below to fix it started causing problems with clisp 2.37
# and libsigsegv support.
#
#ln  -sf  /dev/null  src/config.cache     &&
#

unset  CFLAGS  &&

./configure  --prefix=$INSTALL_ROOT/usr  \
             --with-dynamic-ffi          \
             $OPTS                       &&

cd  src                                  &&
./makemake   --prefix=$INSTALL_ROOT/usr  \
             --with-dynamic-ffi          \
             $OPTS                       \
  >  Makefile                            &&

make_single        &&
make  config.lisp  &&
make               &&
make_normal
