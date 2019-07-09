if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]]; then
  CFLAGS="${CFLAGS} -fPIC"
fi &&

make CFLAGS="-DLUA_USE_POSIX \
             -DLUA_USE_DLOPEN \
             -DLUA_COMPAT_MODULE \
             $CFLAGS" \
     LDFLAGS="$LDFLAGS" linux
