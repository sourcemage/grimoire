OPTS="$OPTS $FFTW_THREADS"                 &&

cd $SOURCE_DIRECTORY/fftw-single-$VERSION  &&
./configure  --prefix=${INSTALL_ROOT}/usr  \
             --enable-shared               \
             --enable-single               \
             --enable-i386-hacks           \
             --enable-type-prefix          \
      $OPTS                                &&
make                                       &&
cd $SOURCE_DIRECTORY/fftw-double-$VERSION  &&
./configure  --prefix=${INSTALL_ROOT}/usr  \
             --enable-shared               \
             --enable-i386-hacks           \
             --enable-type-prefix          \
      $OPTS                                &&
make
