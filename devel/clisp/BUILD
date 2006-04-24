ln  -s  /dev/null  src/config.cache  &&
./configure  --prefix=/usr  $OPTS    &&
cd src                      &&
./makemake   --prefix=/usr  --with-dynamic-ffi  $OPTS  >  Makefile  &&
make  config.lisp           &&
make_single                 &&
make                        &&
make_normal
