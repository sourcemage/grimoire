create_account "jabber" &&

OPTS="$OPTS $JABBERD_PIPE $JABBERD_ANON $JABBERD_FS $JABBERD_DEBUG\
 $JABBERD_NAD_DEBUG $JABBERD_POOL_DEBUG $JABBERD_DEVELOPER\
 --enable-MIO=$JABBERD_MIO --sysconfdir=${INSTALLROOT}/etc/jabberd" &&
if [[ "$JABBER_SASL" == "cyrus-sasl" ]]; then
  OPTS="$OPTS --enable-cyrus --disable-gsasl"
else
  OPTS="$OPTS --enable-gsasl --disable-cyrus"
fi

default_build
