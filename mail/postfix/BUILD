create_account postfix &&
create_account postdrop &&
create_account mail &&

# always correct permissions for older setups
install -vm 2775 -d -o mail -g mail "$INSTALL_ROOT/var/spool/mail" &&

# We want blank vars
local AUXLIBS="-L$INSTALL_ROOT/usr/lib -L$INSTALL_ROOT/lib -lm" &&
local CCARGS="" &&

case "$HOST" in
  (*-musl)
    # XXX incomplete NIS implementation on musl
    CCARGS+=' -DNO_NIS'
    ;;
esac &&

if is_depends_enabled $SPELL pcre; then
    AUXLIBS="$AUXLIBS -lpcre" &&
    CCARGS="$CCARGS -DHAS_PCRE" &&
    message "${MESSAGE_COLOR}PCRE requested: Using PCRE${DEFAULT_COLOR}"
else
    CCARGS="$CCARGS -DNO_PCRE"
fi &&

if is_depends_enabled $SPELL openldap; then
    AUXLIBS="$AUXLIBS -lldap -llber" &&
    CCARGS="$CCARGS -DHAS_LDAP" &&
    message "${MESSAGE_COLOR}OpenLDAP requested: Using OpenLDAP${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL linux-pam; then
    AUXLIBS="$AUXLIBS -lpam -lpam_misc" &&
    CCARGS="$CCARGS -DHAS_PAM" &&
    message "${MESSAGE_COLOR}Linux-PAM requested: Using Linux-PAM${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL dovecot || is_depends_enabled $SPELL cyrus-sasl; then
    CCARGS="$CCARGS -DUSE_SASL_AUTH"
fi &&

if is_depends_enabled $SPELL dovecot; then
    CCARGS="$CCARGS -DDEF_SERVER_SASL_TYPE=\\\"dovecot\\\"" &&
    message "${MESSAGE_COLOR}Dovecot SASL requested: Using Dovecot SASL${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL cyrus-sasl; then
    AUXLIBS="$AUXLIBS -lsasl2" &&
    CCARGS="$CCARGS -DUSE_CYRUS_SASL -I$INSTALL_ROOT/usr/include/sasl" &&
    message "${MESSAGE_COLOR}Cyrus-SASL requested: Using Cyrus-SASL${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL db; then
    AUXLIBS="$AUXLIBS -ldb"
    CCARGS="$CCARGS -DHAS_DB -I$INSTALL_ROOT/usr/include" &&
    message "${MESSAGE_COLOR}Berkeley DB requested: Using Berkeley DB${DEFAULT_COLOR}"
else
    CCARGS="$CCARGS -DNO_DB"
fi &&

if is_depends_enabled $SPELL sqlite; then
    AUXLIBS="$AUXLIBS -lsqlite3"
    CCARGS="$CCARGS -DHAS_SQLITE -I$INSTALL_ROOT/usr/include" &&
    message "${MESSAGE_COLOR}SQLite requested: Using SQLite${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL mysql; then
    AUXLIBS="$AUXLIBS -lmysqlclient -lz" &&
    CCARGS="$CCARGS -DHAS_MYSQL -I$INSTALL_ROOT/usr/include/mysql" &&
    message "${MESSAGE_COLOR}MySQL requested: Using MySQL${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL postgresql; then
    AUXLIBS="$AUXLIBS -lpq" &&
    CCARGS="$CCARGS -DHAS_PGSQL -I$INSTALL_ROOT/usr/include/pgsql" &&
    message "${MESSAGE_COLOR}PostgreSQL requested: Using PostgresSQL${DEFAULT_COLOR}"
fi &&

if is_depends_enabled $SPELL $(get_spell_provider $SPELL SSL); then
    AUXLIBS="$AUXLIBS -lssl -lcrypto" &&
    CCARGS="$CCARGS -DHAS_SSL -DUSE_TLS -I$INSTALL_ROOT/usr/include/openssl" &&
    message "${MESSAGE_COLOR}SSL library requested: Using $(get_spell_provider $SPELL SSL) for SSL/TLS${DEFAULT_COLOR}"
fi &&

# fix to get man pages to install in /usr/share/man
CCARGS="$CCARGS -DDEF_MANPAGE_DIR=\\\"$INSTALL_ROOT/usr/share/man\\\"" &&

# NPTL glibc fix
if glibc_is_nptl; then
    AUXLIBS="$AUXLIBS -lpthread"
fi &&

make makefiles \
     "OPTS=" \
     "OPT=$CFLAGS" \
     "AUXLIBS=$AUXLIBS" \
     "CCARGS=$CCARGS" &&
make
