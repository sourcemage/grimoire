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

# Generic SIMD for all.
# If you enable long double precision, that won't work with any SIMD.
DOUBLE_OPTS="--enable-generic-simd128 --enable-generic-simd256" &&
SINGLE_OPTS=$DOUBLE_OPTS &&

# You can add PPC and ARM opts here. See:
# http://www.fftw.org/fftw3_doc/Installation-on-Unix.html
if [[ ${SMGL_COMPAT_ARCHS[1]} == x86_64 ]]; then
  MORE_DOUBLE_OPTS="--enable-sse2 --enable-avx" &&
  if ! is_version_less "$(installed_version gcc)" 4.9; then
    MORE_DOUBLE_OPTS+="--enable-avx2 --enable-avx512 --enable-avx-128-fma"
  fi &&
  MORE_SINGLE_OPTS="--enable-sse $MORE_DOUBLE_OPTS"
elif [[ ${SMGL_COMPAT_ARCHS[1]} == ia32 ]]; then
  MORE_DOUBLE_OPTS="--enable-sse2" &&
  MORE_SINGLE_OPTS="--enable-sse --enable-sse2"
fi &&

DOUBLE_OPTS+=" $MORE_DOUBLE_OPTS" &&
SINGLE_OPTS+=" $MORE_SINGLE_OPTS" &&

# Build each precision by itself.
for p in $FFTW_PRECISION; do
  bdir="$SOURCE_DIRECTORY/build/$p" &&
  mkdir -p "$bdir" &&
  case "$p" in
    double)
      OPTS="$COMMON_OPTS $DOUBLE_OPTS"
    ;;
    single)
      OPTS="$COMMON_OPTS $SINGLE_OPTS --enable-float"
    ;;
    longdouble)
      OPTS="$COMMON_OPTS --enable-long-double"
    ;;
  esac &&
  cd $bdir &&
  printf '#!/bin/sh\nexec ../../configure "$@"\n' > configure &&
  chmod +x configure &&
  default_build || exit 1
done
