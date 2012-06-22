#Fails to build without extra CPPFLAG
# See http://www.openldap.org/lists/openldap-bugs/200804/msg00074.html
CPPFLAGS="-D_GNU_SOURCE $CPPFLAGS" &&

if is_depends_enabled $SPELL db; then
  LDFLAGS="-ldb $LDFLAGS"
fi &&

if is_depends_enabled $SPELL nss; then
  CPPFLAGS="-I$INSTALL_ROOT/usr/include/nss \
            -I$INSTALL_ROOT/usr/include/nspr \
            $CPPFLAGS"
fi &&

if list_find "$OPENLDAP_OPTS" "--disable-slapd"; then
  OPTS="--disable-backends \
        --disable-overlays \
        $OPTS"
else
  if list_find "$SLAPD_OVERLAYS" "all"; then
    OPTS="--enable-overlays=mod $OPTS"
  elif list_find "$SLAPD_OVERLAYS" "none"; then
    OPTS="--disable-overlays $OPTS"
  else
    for o in $SLAPD_OVERLAYS; do
      OPTS="--enable-${o}=mod $OPTS"
    done
  fi
fi &&

OPTS="--enable-static \
      --enable-shared \
      --enable-dynamic \
      --enable-local \
      --without-fetch \
      $OPENLDAP_OPTS \
      $OPTS" &&

default_build
