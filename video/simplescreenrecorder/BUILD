# XXX workaround for linking issue with GCC 11
case "$HOST" in
  (*-musl)
    LDFLAGS+=" -static-libstdc++"
    ;;
esac &&
default_build
