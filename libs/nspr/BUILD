cd nspr &&
if [[ ${SMGL_COMPAT_ARCHS[0]} == 64 ]]; then
  OPTS="--enable-64bit $OPTS"
fi &&
OPTS="$OPTS --with-mozilla --enable-optimize" &&

LDFLAGS="-lstdc++ $LDFLAGS" &&

default_build
