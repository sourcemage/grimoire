OPTS+=" $TRANSMISSION_I2P_OPTS --program-suffix=-i2p" &&

CFLAGS="-I../third-party ${CFLAGS}" &&

case "$HOST" in
*-musl)
  # The buildsystem assumes iconv is in libc
  export LIBS="-liconv"
  ;;
esac &&

default_build
