if [[ "$GNUTLS_BRANCH" == stable-old ]]; then
  OPTS="--enable-openssl-compatibility ${OPTS}"
fi &&
OPTS="--with-default-trust-store-dir=$INSTALL_ROOT/etc/ssl/certs $OPTS" &&
default_build
