if [[ $FORTRAN == "n" ]]; then
  OPTS="$OPTS --disable-fortran"
fi &&
CFLAGS="${CFLAGS/-Os/}" &&
OPTS="$OPTS $FFTW_THREADS $FFTW_OPTS --disable-fma" &&
cd $SOURCE_DIRECTORY/fftw-single-$VERSION  &&
./configure  --prefix=${INSTALL_ROOT}/usr  \
             --enable-shared               \
             --enable-float                \
             --enable-type-prefix          \
      $OPTS $FFTW_FLOATOPTS                &&
make                                       &&
cd $SOURCE_DIRECTORY/fftw-double-$VERSION  &&
./configure  --prefix=${INSTALL_ROOT}/usr  \
             --enable-shared               \
             --enable-type-prefix          \
      $OPTS $FFTW_DOUBLEOPTS               &&
make                                       &&
cd $SOURCE_DIRECTORY/fftw-longdouble-$VERSION  &&
./configure  --prefix=${INSTALL_ROOT}/usr  \
             --enable-shared               \
             --enable-long-double          \
             --enable-type-prefix          \
      $OPTS                                &&
make
