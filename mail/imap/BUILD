cd "${SOURCE_DIRECTORY}" &&

if is_depends_enabled $SPELL openssl; then
    message "${MESSAGE_COLOR}Building with OpenSSL...${DEFAULT_COLOR}" &&
    SSLOPTS="SSLTYPE=unix \
             SSLCERTS="${INSTALL_ROOT}/etc/ssl/certs" \
             SSLINCLUDE="${INSTALL_ROOT}/usr/include/openssl" \
             SSLLIB="${INSTALL_ROOT}/usr/lib" \
             SSLTYPE=unix"
else
    message "${MESSAGE_COLOR}Building without OpenSSL...${DEFAULT_COLOR}" &&
    SSLOPTS="SSLTYPE=none"
fi &&

if is_depends_enabled $SPELL linux-pam; then
    message "${MESSAGE_COLOR}Building with PAM...${DEFAULT_COLOR}"     &&
    TARGET=lnp
else
    TARGET=slx
fi &&

yes | make ${SSLOPTS} EXTRACFLAGS="${CFLAGS}" ${TARGET}
