if list_find "$DOVECOT_MAILSTORE" "all" ; then
OPTS="--with-storages=maildir,mbox,dbox,cydir $OPTS"
else
OPTS="--with-storages=$(echo $DOVECOT_MAILSTORE | tr " " ",") $OPTS"
fi                                              &&
OPTS="--with-notify=$DOVECOT_NOTIFY $OPTS"
#if [[ $DOVECOT_SSL == none ]]; then
#OPTS="--without-ssl $OPTS"
#fi                                              &&
# desired to have dev headers installed else it's hard
# to have external plugins built
OPTS="--without-vpopmail                        \
      --enable-header-install                   \
      --without-sia                             \
      --without-bsdauth                         \
      --with-ioloop=$DOVECOT_IOLOOP             \
      $DOVECOT_OPTS                             \
      $OPTS"                                    &&
default_build                                   &&
if [[ $DOVECOT_EXT_LDA == y ]]; then
pushd dovecot-${VERSION%.*}-sieve-$VERSION2     &&
OPTS="--with-dovecot=.."                        &&
default_build                                   &&
if [[ $DOVECOT_MANAGESIEVE == y ]]; then
pushd dovecot-${VERSION%.*}-managesieve-$VERSION3    &&
OPTS="--with-dovecot=../.. --with-dovecot-sieve=.."  &&
default_build                                   &&
popd
fi
popd
fi

