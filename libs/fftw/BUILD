if list_find "$CFLAGS" sse2; then
	DOUBLEOPTS="$DOUBLEOPTS --enable-sse2"
fi
if list_find "$CFLAGS" sse; then
	FLOATOPTS="$FLOATOPTS --enable-sse"
fi
if list_find "$CFLAGS" altivec; then
	FLOATOPTS="$FLOATOPTS --enable-altivec"
fi
if list_find "$CFLAGS" 3dnow; then
	FLOATOPTS="$FLOATOPTS --enable-k7"
fi
if list_find "$CFLAGS" powerpc; then
	OPTS="$OPTS --enable-fma"
fi
if [[ $FORTRAN == "n" ]]; then
	OPTS="$OPTS --disable-fortran"
fi
CFLAGS="${CFLAGS/-Os/}"
OPTS="$OPTS $FFTW_THREADS"                 &&

cd $SOURCE_DIRECTORY/fftw-single-$VERSION  &&
./configure  --prefix=${INSTALL_ROOT}/usr  \
             --enable-shared               \
             --enable-float                \
             --enable-type-prefix          \
      $OPTS $FLOATOPTS                     &&
make                                       &&
cd $SOURCE_DIRECTORY/fftw-double-$VERSION  &&
./configure  --prefix=${INSTALL_ROOT}/usr  \
             --enable-shared               \
             --enable-type-prefix          \
      $OPTS $DOUBLEOPTS                    &&
make                                       &&
cd $SOURCE_DIRECTORY/fftw-longdouble-$VERSION  &&
./configure  --prefix=${INSTALL_ROOT}/usr  \
             --enable-shared               \
             --enable-long-double          \
             --enable-type-prefix          \
      $OPTS                                &&
make
