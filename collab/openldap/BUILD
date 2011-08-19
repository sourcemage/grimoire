#Fails to build without extra CPPFLAG
# See http://www.openldap.org/lists/openldap-bugs/200804/msg00074.html
CPPFLAGS="-D_GNU_SOURCE $CPPFLAGS" &&

if [[ "$SLAPD_LDBM" == "db" ]]; then
  LDFLAGS="-ldb $LDFLAGS"
fi &&

OPTS="$OPTS
  $OPENLDAP_SLAPD $SLAPD_ACI $SLAPD_DNSSRV $SLAPD_MONITOR
  $OPENLDAP_SLURPD
  --enable-shared --enable-static
  --enable-dynamic
  --enable-local" &&

default_build
