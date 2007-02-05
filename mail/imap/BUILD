if  [  "$IMAP_MAILSUBDIR"  ==  "y"  ];  then
  patch  -p1  <  $SCRIPT_DIRECTORY/mailsubdir.patch
fi  &&

if  [  "$IMAP_SSL"  ==  "y"  ];  then
  message "${MESSAGE_COLOR}Building with OpenSSL...${DEFAULT_COLOR}" &&
  SSLOPTS="SSLTYPE=unix                     \
           SSLCERTS=/etc/ssl/certs          \
           SSLINCLUDE=/usr/include/openssl  \
           SSLLIB=/usr/lib                  \
           SSLTYPE=unix"
else
  message "${MESSAGE_COLOR}Building without OpenSSL...${DEFAULT_COLOR}" &&
  SSLOPTS="SSLTYPE=none"
fi  &&

if  [  "$IMAP_PAM"  ==  "y"  ];  then
  message "${MESSAGE_COLOR}Building with PAM...${DEFAULT_COLOR}"     &&
  TARGET=lnp
else
  TARGET=slx
fi  &&

yes | make EXTRACFLAGS="$CFLAGS" $SSLOPTS $TARGET
