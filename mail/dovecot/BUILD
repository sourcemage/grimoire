#LDFLAGS="$LDFLAGS -lc"
# disableing what we don't have available
OPTS="--without-vpopmail                        \
      --without-sia                             \
      --without-bsdauth                         \
      --with-ioloop=$DOVECOT_IOLOOP             \
      $DOVECOT_OPTS                             \
      $OPTS"                                    &&
default_build                                   &&
pushd dovecot-sieve-1.0.1                       &&
OPTS="--with-dovecot=.."                        &&
default_build                                   &&
popd
# when the dspam plugin will get updated to work in
# a multiuser environment this will be usefull
#pushd src/plugins/dspam                         
#gcc -fPIC -shared -Wall  -I../../ -I../../lib    \
#   -I../../../ -I../../lib-storage              \
#   -I../../lib-mail  -I../../lib-imap           \
#   -I../../imap/ -DHAVE_CONFIG_H dspam.c        \
#   -o lib_dspam.so                              
#popd

