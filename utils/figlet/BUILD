case "$HOST" in
*-gnu) ;;
*-musl)
  CFLAGS+=" -D__BEGIN_DECLS= -D__END_DECLS="
  ;;
esac &&
make CFLAGS="$CFLAGS"
