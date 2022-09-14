case "$HOST" in
*-musl)
  OPTS+=" --disable-backtrace"
  ;;
esac &&
OPTS+=" --exec-prefix=${INSTALL_ROOT}/
             --bindir=${INSTALL_ROOT}/sbin
  --with-pkgconfigdir=${INSTALL_ROOT}/usr/lib/pkgconfig
            --disable-static" &&

default_build
