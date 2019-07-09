create_account memcached &&

if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]]; then
  OPTS="--enable-64bit $OPTS"
else
  OPTS="--disable-64bit $OPTS"
fi &&

OPTS="$MEMCACHED_OPTS $OPTS" &&

default_build
