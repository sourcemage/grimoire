case "$HOST" in
  (*-musl)
    # non-standard function name expected by rc
    CFLAGS+=' -D__va_copy=va_copy'
    ;;
esac &&
OPTS="--bindir=/bin $OPTS"    &&
default_build
