OPTS="--with-notify=$DOVECOT_NOTIFY $OPTS"
#if [[ $DOVECOT_SSL == none ]]; then
#OPTS="--without-ssl $OPTS"
#fi                                              &&
# desired to have dev headers installed else it's hard
# to have external plugins built
OPTS="--without-vpopmail                            \
      --without-sia                                 \
      --without-bsdauth                             \
      --with-ioloop=$DOVECOT_IOLOOP                 \
      $DOVECOT_OPTS                                 \
      $OPTS"                                        &&
default_build                                       &&
if [[ $DOVECOT_PIGEONHOLE == y ]]; then
pushd dovecot-${BRANCH}-pigeonhole-${VERSION2}      &&
OPTS="$DOVECOT_PIGEONHOLE_OPTS --with-dovecot=.."   &&
default_build                                       &&
popd
fi

