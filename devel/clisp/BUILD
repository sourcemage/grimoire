./configure  --prefix=$INSTALL_ROOT/usr  \
             --with-dynamic-ffi          \
             $OPTS  .                    &&

./makemake   --prefix=$INSTALL_ROOT/usr  \
             --with-dynamic-ffi          \
             $OPTS                       \
  >  Makefile                            &&

make_single        &&
make  config.lisp  &&
make               &&
make_normal
