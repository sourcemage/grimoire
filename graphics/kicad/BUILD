# XXX workaround for linking issue with GCC 11
case "$HOST" in
  (*-musl)
    CXXFLAGS+=' -static-libstdc++'
    ;;
esac &&
OPTS+=' -DKICAD_USE_OCE=OFF' &&
cmake_build
