if echo $OPTS | grep -q with-ssl; then
  message "${MESSAGE_COLOR}Building with OpenSSL...${DEFAULT_COLOR}" &&
  ALPINE_OPTS="${ALPINE_OPTS}                                        \
           --with-ssl-dir=$INSTALL_ROOT/usr                          \
           --with-ssl-certs-dir=$INSTALL_ROOT/etc/ssl/certs          \
           --with-ssl-include-dir=$INSTALL_ROOT/usr/include/openssl  \
           --with-ssl-lib-dir=$INSTALL_ROOT/usr/lib"
else
  message "${MESSAGE_COLOR}Building without OpenSSL...${DEFAULT_COLOR}"
fi &&

OPTS="${OPTS} --with-system-pinerc=/etc/pinerc --with-c-client-target=slx ${ALPINE_OPTS}" &&
default_build
