if [[ $FORTRAN == "n" ]]; then
  OPTS="$OPTS --disable-fortran"
fi &&

# Ensure we got shared libs. It is expected nowadays.
COMMON_OPTS="$OPTS --enable-shared"  &&

if [[ "$FFTW_THREADS" == y ]]; then
  COMMON_OPTS+=" --enable-threads"
else
  COMMON_OPTS+=" --disable-threads"
fi &&
if [[ "$FFTW_OPENMP" == y ]]; then
  COMMON_OPTS+=" --enable-openmp"
else
  COMMON_OPTS+=" --disable-openmp"
fi &&

# There are others available via custom configure.
# We just enable a runtime-chosen set of optimizations that should
# benefit the masses.
case $FFTW_VECTOR in
  sse)
    SINGLE_OPTS+=' --enable-sse'
  ;;
  sse2)
    SINGLE_OPTS+=' --enable-sse'
    DOUBLE_OPTS+=' --enable-sse2'
  ;;
  avx)
    SINGLE_OPTS+=' --enable-sse --enable-avx'
    DOUBLE_OPTS+=' --enable-sse2 --enable-avx'
  ;;
  avx2)
    SINGLE_OPTS+=' --enable-sse --enable-avx2'
    DOUBLE_OPTS+=' --enable-sse2 --enable-avx2'
  ;;
esac &&

# Build each precision by itself.
for p in $FFTW_PRECISION; do
  case "$p" in
    double)
      OPTS="$COMMON_OPTS $DOUBLE_OPTS" &&
      cd "$SOURCE_DIRECTORY/double"
    ;;
    single)
      OPTS="$COMMON_OPTS $SINGLE_OPTS --enable-float" &&
      cd "$SOURCE_DIRECTORY/$p"
    ;;
    longdouble)
      OPTS="$COMMON_OPTS --enable-long-double" &&
      cd "$SOURCE_DIRECTORY/$p"
    ;;
  esac &&
  default_build || exit 1
done
