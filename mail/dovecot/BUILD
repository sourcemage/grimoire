#LDFLAGS="$LDFLAGS -lc"
# disableing what we don't have available
if [[ $DOVECOT_EXT_LDA == y ]]; then
OPTS="--with-deliver $OPTS"
else
OPTS="--without-deliver $OPTS"
fi                                              &&
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
pushd dovecot-sieve-*                           &&
OPTS="--with-dovecot=.."                        &&
default_build                                   &&
popd
fi
# when the dspam plugin will get updated to work in
# a multiuser environment this will be usefull
#pushd src/plugins/dspam                         
#gcc -fPIC -shared -Wall  -I../../ -I../../lib    \
#   -I../../../ -I../../lib-storage              \
#   -I../../lib-mail  -I../../lib-imap           \
#   -I../../imap/ -DHAVE_CONFIG_H dspam.c        \
#   -o lib_dspam.so                              
#popd

