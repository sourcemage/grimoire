if [[ $RESTEST == y ]]; then
  OPTS="$OPTS -DOPENEXR_RUN_FUZZ_TESTS=on"
fi &&

CXXFLAGS="${CXXFLAGS} -fpermissive" LDFLAGS="${LDFLAGS} -lpthread" cmake_build
