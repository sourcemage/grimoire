# prevent doxygen error
sedit "s/ doc//" Makefile.in  &&
make_single    &&
OPTS="$OPTS --disable-error-on-warning"  &&
default_build  &&
make_normal

