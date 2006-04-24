if [[ "${DOVECOT_SSL:-none}" == 'none' ]]; then
  OPTS="$OPTS --without-ssl"
fi &&

if [[ "$DOVECOT_EXT_LDA" == 'y' ]]; then
  OPTS="$OPTS --without-deliver"
else
  OPTS="$OPTS --with-deliver"
fi &&

default_build &&

if [[ "$DOVECOT_EXT_LDA" == 'y' ]]; then
  pushd dovecot-lda-* &&
  ./configure \
    --prefix=$INSTALL_ROOT/usr \
    --sysconfdir=$INSTALL_ROOT/etc \
    --localstatedir=$INSTALL_ROOT/var \
    --with-dovecot=.. &&
  make &&
  popd
fi
