CXXFLAGS+=' -D_LARGEFILE64_SOURCE' &&
if [ libressl = "$(get_spell_provider "$SPELL" SSL)" ]; then
  OPTS+=' -DQT_FEATURE_dtls=OFF'
fi &&

OPTS+=" $QT6_EXAMPLE $QT6_TESTS" &&
OPTS+=" $QT6_DEBUG  $QT6_PCH" &&
#      --linker=$QT_LINKER"    &&
message opts=$OPTS &&
default_build

