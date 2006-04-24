create_account  exim  &&
create_account  mail  &&

mkdir  -p         $INSTALL_ROOT/var/spool/mail  &&
chmod  1777       $INSTALL_ROOT/var/spool/mail  &&
chown  exim:exim  $INSTALL_ROOT/var/spool/mail  &&

if  [  -e  $INSTALL_ROOT/var/spool/mail/db  ]
then
  chown  -R  exim:exim  $INSTALL_ROOT/var/spool/mail/db
fi  &&

if  [  -e  $INSTALL_ROOT/var/spool/mail/input  ]
then
  chown  -R  exim:exim  $INSTALL_ROOT/var/spool/mail/input
fi  &&

if  [  -e  $INSTALL_ROOT/var/spool/mail/log  ]
then
  chown  -R  exim:exim  $INSTALL_ROOT/var/spool/mail/log
fi  &&

if  [  -e  $INSTALL_ROOT/var/spool/mail/msglog  ]
then
  chown  -R  exim:exim  $INSTALL_ROOT/var/spool/mail/msglog
fi  &&

chgrp  -R  exim  $INSTALL_ROOT/var/spool/mail  &&

mkdir  -p  Local  &&

if  [  "$EXIM_XFREE86"  ==  "y"  ]
then
  cp  src/EDITME           Local/Makefile     &&
  cp  exim_monitor/EDITME  Local/eximon.conf
else
   grep  -v  "EXIM_MONITOR="  src/EDITME  >  Local/Makefile
fi  &&

if  [  "$EXIM_TCPWRAPPERS"  ==  "y"  ]
then
  echo  "USE_TCP_WRAPPERS=yes"  >> Local/Makefile  &&
  EXTRALIBS="$EXTRALIBS  -lwrap"
fi  &&

if  [  "$EXIM_LINUXPAM"  ==  "y"  ]
then
  echo  "SUPPORT_PAM=yes"  >>  Local/Makefile  &&
  if  spell_ok  tcp_wrappers
  then  EXTRALIBS="$EXTRALIBS  -lpam -ldl -lwrap"
  else  EXTRALIBS="$EXTRALIBS  -lpam -ldl"
  fi
fi  &&

if  [  "$EXIM_MYSQL"  ==  "y"  ]
then
  echo  "LOOKUP_MYSQL=yes"                      >>  Local/Makefile  &&
  echo  "LOOKUP_INCLUDE=-I /usr/include/mysql"  >>  Local/Makefile  &&
  LOOKUP_LIBS="$LOOKUP_LIBS  -lmysqlclient"
fi  &&

if  [  "$EXIM_PGSQL"  ==  "y"  ]
then
  echo  "LOOKUP_PGSQL=yes"  >>  Local/Makefile  &&
  LOOKUP_LIBS="$LOOKUP_LIBS  -lpq"
fi  &&

if  [  "$EXIM_OPENLDAP"  ==  "y"  ]
then
  echo  "LOOKUP_LDAP=yes"            >>  Local/Makefile  &&
  echo  "LDAP_LIB_TYPE=OPENLDAP2"    >>  Local/Makefile  &&
  LOOKUP_LIBS="$LOOKUP_LIBS  -lldap -llber"
fi  &&

if  [  "$OPENSSL"  ==  "y"  ]
then
  echo  "SUPPORT_TLS=yes"          >>  Local/Makefile  &&
  TLS_LIBS="$TLS_LIBS  -lssl -lcrypto"
fi  &&

if  [  "$GNUTLS"  ==  "y"  ]
then
  echo  "SUPPORT_TLS=yes"                    >>  Local/Makefile  &&
  echo  "USE_GNUTLS=yes"                     >>  Local/Makefile  &&
  TLS_LIBS="$TLS_LIBS  -lgnutls -ltasn1 -lgcrypt"
fi  &&

if  [  "$EXIM_MAILDIR"  ==  "y"  ]
then
  echo  "SUPPORT_MAILDIR=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_MAILSTORE"  ==  "y"  ]
then
  echo  "SUPPORT_MAILSTORE=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_MBX"  ==  "y"  ]
then
  echo  "SUPPORT_MBX=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_NIS"  ==  "y"  ]
then
  echo  "LOOKUP_NIS=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_NISPLUS"  ==  "y"  ]
then
  echo  "LOOKUP_NISPLUS=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_ORACLE"  ==  "y"  ]
then
  echo  "LOOKUP_ORACLE=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_PASSWD"  ==  "y"  ]
then
  echo  "LOOKUP_PASSWD=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_SCAN"  ==  "y"  ]
then
  echo  "WITH_CONTENT_SCAN=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_MD5"  ==  "y"  ]
then
  echo  "AUTH_CRAM_MD5=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_SASL"  ==  "y"  ]
then
  echo  "AUTH_CYRUS_SASL=yes"  >>  Local/Makefile  &&
  echo  "AUTH_LIBS=-lsasl2"    >>  Local/Makefile
fi  &&

if  [  "$EXIM_PLAINTEXT"  ==  "y"  ]
then
  echo  "AUTH_PLAINTEXT=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_SPA"  ==  "y"  ]
then
  echo  "AUTH_SPA=yes"  >>  Local/Makefile
fi  &&

if  [  "$EXIM_READLINE"  ==  "y"  ]
then
  echo  "USE_READLINE=yes"  >>  Local/Makefile  &&
  EXTRALIBS="$EXTRALIBS  -ldl"
fi  &&

echo  "LOOKUP_LIBS=$LOOKUP_LIBS"  >>  Local/Makefile  &&
echo  "EXTRALIBS=$EXTRALIBS"  >>  Local/Makefile  &&

if  [  "$EXIM_FROZEN"  ==  "y"  ]
then
  echo  "SUPPORT_MOVE_FROZEN_MESSAGES=yes"  >>  Local/Makefile
fi  &&

echo  "BIN_DIRECTORY=/usr/sbin"          >>  Local/Makefile  &&
echo  "CONFIGURE_FILE=/etc/exim.conf"    >>  Local/Makefile  &&
echo  "SPOOL_DIRECTORY=/var/spool/mail"  >>  Local/Makefile  &&
echo  "LOG_FILE_PATH=/var/log/exim_%s:"  >>  Local/Makefile  &&
echo  "CFLAGS=$CFLAGS"                   >>  Local/Makefile  &&
echo  "EXIM_UID=`id -u exim`"            >>  Local/Makefile  &&
echo  "EXIM_GID=`id -g exim`"            >>  Local/Makefile  &&
echo  "EXIM_USER=exim"                   >>  Local/Makefile  &&
echo  "EXIM_GROUP=exim"                  >>  Local/Makefile  &&

sedit  's:tail \-1:tail \-n 1:'  scripts/Configure-config.h  &&
make_single                                                  &&
make
