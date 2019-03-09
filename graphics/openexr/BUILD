if [[ $RESTEST == y ]]; then
  OPTS="$OPTS -DOPENEXR_RUN_FUZZ_TESTS=on"
fi &&

OPTS="$OPTS -DOPENEXR_NAMESPACE_VERSIONING=off"

CXXFLAGS="${CXXFLAGS} -fpermissive" LDFLAGS="${LDFLAGS} -lpthread" cmake_build
