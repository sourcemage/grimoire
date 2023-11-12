if [[ $RESTEST == y ]]; then
  OPTS="$OPTS -DOPENEXR_RUN_FUZZ_TESTS=on"
fi &&

OPTS+=" -DBUILD_SHARED_LIBS=on" &&
OPTS+=" -DOPENEXR_INSTALL_PKG_CONFIG=on" &&
OPTS+=" -DOPENEXR_USE_CLANG_TIDY=off" &&
OPTS+=" -DBUILD_TESTING=off" &&

CXXFLAGS="${CXXFLAGS} -fpermissive" LDFLAGS="${LDFLAGS} -lpthread" default_build
