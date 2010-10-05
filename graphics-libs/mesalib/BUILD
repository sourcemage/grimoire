local MESALIB_DRIVERS_CONF="${MESALIB_DRIVERS//\ /,}"  &&

case $MESALIB_GALLIUM in
  llvm)    OPTS="${OPTS} --enable-gallium-llvm" ;;
  svga)    OPTS="${OPTS} --enable-gallium-svga" ;;
  intel)   OPTS="${OPTS} --enable-gallium-intel" ;;
  i915)    OPTS="${OPTS} --enable-gallium-i915" ;;
  i965)    OPTS="${OPTS} --enable-gallium-i965" ;;
  radeon)  OPTS="${OPTS} --enable-gallium-radeon" ;;
  r600)    OPTS="${OPTS} --enable-gallium-r600" ;;
  nouveau) OPTS="${OPTS} --enable-gallium-nouveau" ;;
  swrast)  OPTS="${OPTS} --enable-gallium-swrast" ;;
  none)    OPTS="${OPTS} --disable-gallium" ;;
esac &&

OPTS="--with-driver=$MESALIB_BUILD                     \
      --with-dri-drivers=$MESALIB_DRIVERS_CONF         \
      $MESALIB_OPTS \
      $OPTS"                                           &&
default_build
