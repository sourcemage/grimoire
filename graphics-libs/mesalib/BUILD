local MESALIB_DRIVERS_CONF="${MESALIB_DRIVERS//\ /,}"  &&

case $MESALIB_GALLIUM in
  none) OPTS="${OPTS} --disable-gallium" ;;
  intel) OPTS="${OPTS} --enable-gallium-intel" ;;
  radeon) OPTS="${OPTS} --enable-gallium-radeon --disable-gallium-intel" ;;
  nouveau) OPTS="${OPTS} --enable-gallium-nouveau --disable-gallium-intel" ;;
  all) OPTS="${OPTS} --enable-gallium-intel --enable-gallium-radeon --enable-gallium-nouveau" ;;
esac &&
OPTS="--with-driver=$MESALIB_BUILD                     \
      --with-dri-drivers=$MESALIB_DRIVERS_CONF         \
      $OPTS"                                           &&
default_build
