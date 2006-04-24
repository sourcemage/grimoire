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

if  [  "$SSL"  ==  "y"  ];  then
  AUXLIBS="$AUXLIBS -lssl -lcrypto"                  &&
  CCARGS="$CCARGS -DHAS_SSL -I/usr/include/openssl"  &&
  message "${MESSAGE_COLOR}OpenSSL detected: Using OpenSSL ${DEFAULT_COLOR}"
fi  &&

if  [  "$SSL_TLS"  ==  "y"  ];  then
    message "${MESSAGE_COLOR}Trying to patch Postfix for SSL/TLS support ${DEFAULT_COLOR}"  &&
    patch -Np1 < $SOURCE2_DIRECTORY/pfixtls.diff  || PATCH_FAILED=true  &&
    if [ "$PATCH_FAILED" == "true" ]; then
      message "${MESSAGE_COLOR}Patch failed... please do a cast -r -c postfix"  &&
      message "and answer no to the TLS/SSL patch question.${DEFAULT_COLOR}"  &&
      return 1
    fi
fi  &&

#
#  The PostgreSQL patch is outdated
#
#if  [  "$PGSQL"  ==  "y"  ];  then
  message "${MESSAGE_COLOR}Trying to patch for PostgreSQL support${DEFAULT_COLOR}"  &&
#  patch -Np1 < $SOURCE3_DIRECTORY/$SOURCE3  || PATCH_FAILED=true  &&
#  if [ "$PATCH_FAILED" == "true" ]; then
#      message "${MESSAGE_COLOR}Patch failed... please do a cast -r -c postfix"  &&
#      message "and answer no to the Postgresql patch question.${DEFAULT_COLOR}"  &&
#      return 1
#    fi  &&

#    AUXLIBS="$AUXLIBS /usr/lib/libpq.a -lcrypt"  &&
#    CCARGS="$CCARGS  -DHAS_PGSQL -I/usr/include/postgresql"  &&
#    mkdir -p ${INSTALL_ROOT}/usr/doc/$SPELL  &&
#    mkdir -p ${INSTALL_ROOT}/usr/doc/$SPELL/$NAME4  &&
#    cp -r $SOURCE4_DIRECTORY/$NAME4/* ${INSTALL_ROOT}/usr/doc/$SPELL/$NAME4
#fi  &&

if  [  "$VDA"  ==  "y"  ];  then
    message "${MESSAGE_COLOR}Trying to patch Postfix with VDA support${DEFAULT_COLOR}"  &&
    patch -Np1 < $SOURCE5_DIRECTORY/$NAME5   || PATCH_FAILED=true  &&
    if [ "$PATCH_FAILED" == "true" ]; then
      message "${MESSAGE_COLOR}Patch failed... please do a cast -r -c postfix"  &&
      message "and answer no to the VDA patch question.${DEFAULT_COLOR}"  &&
      return 1
    fi
fi   &&

# fix to get man pages to install in /usr/man

sedit  "s:/usr/local:${INSTALL_ROOT}/usr:"  src/global/mail_params.h  &&

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
