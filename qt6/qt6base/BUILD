CXXFLAGS+=' -D_LARGEFILE64_SOURCE' &&
if [ libressl = "$(get_spell_provider "$SPELL" SSL)" ]; then
  OPTS+=' -DQT_FEATURE_dtls=OFF'
fi &&

# compress the MIME database with the zstd program, not CMake's archive API:
# that needs CMake built against a libarchive with zstd, which depends on
# build order ("CMake was not built with zstd support")
OPTS+=' -DQT_AVOID_CMAKE_ARCHIVING_API=ON' &&

OPTS+=" $QT6_EXAMPLE $QT6_TESTS" &&
OPTS+=" $QT6_DEBUG  $QT6_PCH" &&
#      --linker=$QT_LINKER"    &&
message opts=$OPTS &&
default_build

