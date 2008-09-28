create_account postfix &&
create_account postdrop &&
create_account mail &&

mkdir -p "${INSTALL_ROOT}/var/spool/mail" &&
chmod 1777 "${INSTALL_ROOT}/var/spool/mail" &&
chown mail:mail "${INSTALL_ROOT}/var/spool/mail" &&
chgrp -R mail "${INSTALL_ROOT}/var/spool/mail" &&

# We want blank vars
local AUXLIBS="" &&
local CCARGS="" &&

if is_depends_enabled $SPELL openldap; then
    AUXLIBS="${AUXLIBS} -lldap -llber" &&
    CCARGS="${CCARGS} -DHAS_LDAP" &&
    message "${MESSAGE_COLOR}OpenLDAP requested: Using OpenLDAP${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL linux-pam; then
    AUXLIBS="${AUXLIBS} -lpam -lpam_misc" &&
    CCARGS="${CCARGS} -DHAS_PAM" &&
    message "${MESSAGE_COLOR}Linux-PAM requested: Using Linux-PAM${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL cyrus-sasl; then
    AUXLIBS="${AUXLIBS} -lsasl2" &&
    CCARGS="${CCARGS} -DUSE_SASL_AUTH -DUSE_CYRUS_SASL -I${INSTALL_ROOT}/usr/include/sasl" &&
    message "${MESSAGE_COLOR}Cyrus-SASL requested: Using Cyrus-SASL${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL mysql; then
    AUXLIBS="${AUXLIBS} -L${INSTALL_ROOT}/usr/lib -lmysqlclient -lz -lm" &&
    CCARGS="${CCARGS} -DHAS_MYSQL -I${INSTALL_ROOT}/usr/include/mysql" &&
    message "${MESSAGE_COLOR}MySQL requested: Using MySQL${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL postgresql; then
    AUXLIBS="${AUXLIBS} -L${INSTALL_ROOT}/usr/lib -lpq" &&
    CCARGS="${CCARGS} -DHAS_PGSQL -I${INSTALL_ROOT}/usr/include/pgsql" &&
    message "${MESSAGE_COLOR}PostgreSQL requested: Using PostgresSQL${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL openssl; then
    AUXLIBS="${AUXLIBS} -lssl -lcrypto" &&
    CCARGS="${CCARGS} -DHAS_SSL -DUSE_TLS -I${INSTALL_ROOT}/usr/include/openssl" &&
    message "${MESSAGE_COLOR}OpenSSL requested: Using OpenSSL for SSL/TLS${DEFAULT_COLOR}"
fi &&

# fix to get man pages to install in /usr/man
#sedit "s:/usr/local:${INSTALL_ROOT}/usr:" src/global/mail_params.h &&
CCARGS="${CCARGS} -DDEF_MANPAGE_DIR=\\\"${INSTALL_ROOT}/usr/share/man\\\"" &&


# NPTL glibc fix
if glibc_is_nptl; then
    AUXLIBS="${AUXLIBS} -lpthread"
fi &&

make makefiles \
     "OPTS=" \
     "OPT=${CFLAGS}" \
     "AUXLIBS=${AUXLIBS}" \
     "CCARGS=${CCARGS}" &&
make &&

# Fix directories in the main.cf
if [[ "${POSTFIX_PRE_EXISTING}" == "yes" ]]; then
    if [[ "${POSTFIX_FIX_MAINCF}" == "y" ]]; then
        # repair directories in the main.cf
        local MANPAGE_DIR="$(grep manpage_directory ${INSTALL_ROOT}/etc/postfix/main.cf | cut -d"=" -f2)" &&
        MANPAGE_DIR="${MANPAGE_DIR## }" &&

        if [[ "$MANPAGE_DIR" != "${INSTALL_ROOT}/usr/share/man" ]]; then
            sed -i -e "s|manpage_directory.*=.*|manpage_directory = ${INSTALL_ROOT}/usr/share/man|" \
                      ${INSTALL_ROOT}/etc/postfix/main.cf
        fi
    fi
fi
