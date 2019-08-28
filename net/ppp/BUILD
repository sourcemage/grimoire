create_group  ppp  &&

./configure --prefix="$INSTALL_ROOT/usr" \
        --sysconfdir="$INSTALL_ROOT/etc" &&

case "$HOST" in
*-musl) CFLAGS+=' -D"__P(x)=x"' ;;
esac &&
make COPTS="$CFLAGS $LDFLAGS"
