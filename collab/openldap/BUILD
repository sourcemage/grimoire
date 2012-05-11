#Fails to build without extra CPPFLAG
# See http://www.openldap.org/lists/openldap-bugs/200804/msg00074.html
CPPFLAGS="-D_GNU_SOURCE $CPPFLAGS" &&

if is_depends_enabled $SPELL db; then
  LDFLAGS="-ldb $LDFLAGS"
fi &&

# only add slapd options when actually building it
if echo $OPENLDAP_SLAPD | grep -q enable; then

  if [[ "${SLAPD_OVERLAYS}" == 'none' ]]; then
    message 'skipping overlays'
  elif [[ "${SLAPD_OVERLAYS}" == 'all' ]]; then
    message 'adding all overlays' &&
    OVERLAYS='--enable-overlays=mod'
  else
    for OVERLAY in ${SLAPD_OVERLAYS}; do
      OVERLAYS="${OVERLAYS} --enable-${OVERLAY}=mod"
    done
  fi

  SLAPD_OPTS="$OPENLDAP_SLAPD $SLAPD_ACL $SLAPD_ACI $SLAPD_DNSSRV 
              $SLAPD_MONITOR $SLAPD_CRYPT $SLAPD_CLEAR $SLAPD_REV 
              $SLAPD_SOCK $SLAPD_META $SLAPD_RELAY $OVERLAYS"
else
    SLAPD_OPTS="$OPENLDAP_SLAPD"
fi &&

OPTS="$OPTS
  $SLAPD_OPTS
  --enable-shared --enable-static
  --enable-dynamic
  --enable-local" &&

default_build
