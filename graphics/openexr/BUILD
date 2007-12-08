if [[ $EXAMPLE == y ]]; then
  OPTS="$OPTS --enable-imfexamples"
fi &&

if [[ $RESTEST == y ]]; then
  OPTS="$OPTS --enable-imffuzztest"
fi &&

PTHREAD_LIBS="-lpthread" default_build
