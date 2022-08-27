case "$HOST" in
*-musl)
  OPTS+=" --disable-backtrace"
  ;;
esac
OPTS+=" --exec-prefix=${INSTALL_ROOT} --with-pkgconfigdir=${INSTALL_ROOT}/usr/lib/pkgconfig" &&
OPTS+=" --disable-static" &&

default_build
