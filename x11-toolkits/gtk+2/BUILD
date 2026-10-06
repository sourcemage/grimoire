# bug #12668
export CFLAGS="${CFLAGS/-O3/-Os}"                    &&
# gcc 14+ makes incompatible pointer types an error (gtkitemfactory.c)
CFLAGS="-Wno-error=incompatible-pointer-types ${CFLAGS}" &&
default_build
