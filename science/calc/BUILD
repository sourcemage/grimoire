case "$HOST" in
  (*-musl)
    OPTS+=' HAVE_FPOS=-DHAVE_NO_FPOS'
    ;;
esac &&
make -j1 $OPTS \
     DEBUG= \
     EXTRA_CFLAGS="$CFLAGS" \
     EXTRA_LDFLAGS="$LDFLAGS"
