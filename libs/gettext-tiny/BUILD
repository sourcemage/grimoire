libintl=
case "$HOST" in
*-musl) libintl=MUSL;;
*-gnu)  libintl=NONE;;
esac
make LIBINTL="$libintl" CFLAGS="$CFLAGS" CC="$CC"
