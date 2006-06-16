create_account  postfix   &&
create_account  postdrop  &&
create_account  mail      &&
 
mkdir  -p         ${INSTALL_ROOT}/var/spool/mail  &&
chmod  1777       ${INSTALL_ROOT}/var/spool/mail  &&
chown  mail:mail  ${INSTALL_ROOT}/var/spool/mail  &&
chgrp  -R  mail   ${INSTALL_ROOT}/var/spool/mail  &&

if  [  "$LDAP"  ==  "y"  ];  then
  AUXLIBS="-lldap -llber"  &&
  CCARGS="-DHAS_LDAP"      &&
  message "${MESSAGE_COLOR}Openldap detected: Using OpenLDAP${DEFAULT_COLOR}"
fi  &&

if  [  "$PAM"  ==  "y"  ];  then
  AUXLIBS="$AUXLIBS -lpam -lpam_misc"  &&
  CCARGS="$CCARGS  -DHAS_PAM"          &&
  message "${MESSAGE_COLOR}Linux-Pam detected: Using linux-pam${DEFAULT_COLOR}"
fi  &&

if  [  "$SASL"  ==  "y"  ];  then
  AUXLIBS="$AUXLIBS -lsasl2"                             &&
  CCARGS="$CCARGS  -DUSE_SASL_AUTH -I/usr/include/sasl"  &&
  message "${MESSAGE_COLOR}Cyrus-sasl detected: Using Cyrus-SASL${DEFAULT_COLOR}"
fi  &&

if  [  "$MYSQL"  ==  "y"  ];  then
  AUXLIBS="$AUXLIBS -L/usr/lib -lmysqlclient -lz -lm"  &&
  CCARGS="$CCARGS -DHAS_MYSQL -I/usr/include/mysql"    &&
  message "${MESSAGE_COLOR}MySQL detected: Using MySQL ${DEFAULT_COLOR}"
fi  &&

if  [  "$POSTGRES"  ==  "y"  ];  then
  AUXLIBS="$AUXLIBS -L/usr/lib -lpq"  &&
  CCARGS="$CCARGS -DHAS_PGSQL -I/usr/include/pgsql"    &&
  message "${MESSAGE_COLOR}PostgreSQL detected: Using PostgresSQL ${DEFAULT_COLOR}"
fi  &&

if  [  "$SSL"  ==  "y"  ];  then
  AUXLIBS="$AUXLIBS -lssl -lcrypto"                  &&
  CCARGS="$CCARGS -DHAS_SSL -I/usr/include/openssl"  &&
  message "${MESSAGE_COLOR}OpenSSL detected: Using OpenSSL for SSL ${DEFAULT_COLOR}"
fi  &&

if  [  "$SSL_TLS"  ==  "y"  ];  then
  AUXLIBS="$AUXLIBS -lssl -lcrypto"                  &&
  CCARGS="$CCARGS -DUSE_TLS -I/usr/include/openssl"  &&
  message "${MESSAGE_COLOR}OpenSSL detected: Using OpenSSL for TLS ${DEFAULT_COLOR}"
fi  &&

if  [  "$VDA"  ==  "y"  ];  then
    message "${MESSAGE_COLOR}Applying VDA Patch${DEFAULT_COLOR}"  &&
    patch -p1 < $NAME3
fi   &&

# fix to get man pages to install in /usr/man
#sedit  "s:/usr/local:${INSTALL_ROOT}/usr:"  src/global/mail_params.h  &&
CCARGS="$CCARGS -DDEF_MANPAGE_DIR=\\\"/usr/share/man\\\""  &&


# NPTL glibc fix
if  glibc_is_nptl; then
  AUXLIBS="$AUXLIBS  -lpthread"
fi  &&

make  makefiles           \
      "CC=gcc"            \
      "OPT=$CFLAGS"       \
      "AUXLIBS=$AUXLIBS"  \
      "CCARGS=$CCARGS"    &&
make
