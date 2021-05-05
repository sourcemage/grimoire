# XXX workaround for linking issue with GCC 11
case "$HOST" in
  (*-musl)
    CXXFLAGS+=' -static-libstdc++'
    ;;
esac &&

OPTS+=' --enable-shared --disable--static' &&
LDFLAGS+=" -lintl" &&
default_build
