OPTS+=" --disable-builddir" &&
case "$HOST" in
*-musl)
  # The buildsystem assumes iconv is in libc
  export LIBS="-liconv"
  ;;
esac &&
default_build
