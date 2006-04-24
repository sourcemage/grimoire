OPTS="--with-unprivileged-user=anubis $OPTS"       &&
if [[ "$ANUBIS_TLS" == "none" ]]
then
  OPTS="--without-gnutls --without-openssl $OPTS"
fi                                                 &&
if [[ "$ANUBIS_DB" == "plaintext" ]]
then
  OPTS="--without-mysql --without-postgres --without-gdbm $OPTS"
fi                                                 &&
default_build

