if echo $OPTS | grep -q with-openssl; then
  message "${MESSAGE_COLOR}Building with OpenSSL...${DEFAULT_COLOR}" &&
  SSLOPTS="SSLTYPE=unix                                 \
           SSLCERTS=$INSTALL_ROOT/etc/ssl/certs         \
           SSLINCLUDE=$INSTALL_ROOT/usr/include/openssl \
           SSLLIB=$INSTALL_ROOT/usr/lib                 \
           SSLTYPE=unix"
else
  message "${MESSAGE_COLOR}Building without OpenSSL...${DEFAULT_COLOR}" &&
  SSLOPTS='SSLTYPE=none'
fi &&
if echo $OPTS | grep -q with-pam; then
  TARGET=lnp
else
  TARGET=slx
fi &&

# the trick to building c-client only is to remove the target named "bundled"
# from the dependents list of default target "build"
sedit 's|^\(build:.*\)bundled|\1|g' Makefile &&

yes | make $SSLOPTS EXTRACFLAGS="$CFLAGS" $TARGET
