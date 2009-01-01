create_account "jabber" &&
# their configure complains about anything higher than -O2 but as that might
# not be desired in all cases just removing it completly
CFLAGS=${CFLAGS/-O3}  &&
CFLAGS=${CFLAGS/-Os}  &&
OPTS="$JABBERD_OPTS --enable-mio=$JABBERD_MIO --with-sasl=${JABBERD_SASL/-sasl} --sysconfdir=${INSTALLROOT}/etc/jabberd $OPTS" &&

default_build
