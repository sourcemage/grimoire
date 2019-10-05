if [[ $RESTEST == y ]]; then
  OPTS="$OPTS -DOPENEXR_RUN_FUZZ_TESTS=on"
fi &&

OPTS+=" -DBUILD_SHARED_LIBS=on" &&
OPTS+=" -DOPENEXR_NAMESPACE_VERSIONING=off" &&

CXXFLAGS="${CXXFLAGS} -fpermissive" LDFLAGS="${LDFLAGS} -lpthread" default_build
