if [[ $EXAMPLE == y ]]; then
  OPTS="$OPTS --enable-imfexamples"
fi &&

if [[ $RESTEST == y ]]; then
  OPTS="$OPTS --enable-imffuzztest"
fi &&

CXXFLAGS="${CXXFLAGS} -fpermissive" LDFLAGS="${LDFLAGS} -lpthread" default_build
