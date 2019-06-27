libintl=
case "$HOST" in
*-musl) libintl=MUSL;;
*-gnu)  libintl=NONE;;
esac
make prefix="$INSTALL_ROOT/usr" LIBINTL="$libintl" CFLAGS="$CFLAGS" CC="$CC"
