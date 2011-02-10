if [[ $FORTRAN == "n" ]]; then
  OPTS="$OPTS --disable-fortran"
fi &&
CFLAGS="${CFLAGS/-Os/}" &&

OPTS="$OPTS $FFTW_THREADS $FFTW_OPTS --disable-fma" &&
OPTS="$OPTS --enable-shared"                        &&
OPTS="$OPTS --enable-type-prefix"                   &&

COMMON_OPTS="${OPTS}"                               &&


cd $SOURCE_DIRECTORY/fftw-single-$VERSION           &&
OPTS="$COMMON_OPTS --enable-float $FFTW_FLOATOPTS"  &&
default_build                                       &&

cd $SOURCE_DIRECTORY/fftw-double-$VERSION           &&
OPTS="$COMMON_OPTS $FFTW_DOUBLEOPTS"                &&
default_build                                       &&

cd $SOURCE_DIRECTORY/fftw-longdouble-$VERSION       &&
OPTS="$COMMON_OPTS --enable-long-double"            &&
default_build
