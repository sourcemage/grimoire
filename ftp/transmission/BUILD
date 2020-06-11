OPTS="$TRANSMISSION_OPTS $OPTS" &&

CFLAGS="-I../third-party ${CFLAGS}" &&

case "$HOST" in
*-musl)
  # The buildsystem assumes iconv is in libc
  export LIBS="-liconv"
  ;;
esac &&

default_build
