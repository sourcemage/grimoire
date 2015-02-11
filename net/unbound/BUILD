create_account unbound &&

if [[ "$UNBOUND_SSL" == "nss" ]]; then
  CPPFLAGS="`nss-config --cflags` $CPPFLAGS" &&
  CPPFLAGS="`nspr-config --cflags` $CPPFLAGS"
fi &&

OPTS="--with-pidfile=$INSTALL_ROOT/var/run/unbound/unbound.pid \
      $UNBOUND_OPTS \
      $OPTS" &&

default_build
