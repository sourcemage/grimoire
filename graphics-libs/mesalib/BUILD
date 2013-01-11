local MESALIB_DRIVERS_CONF="${MESALIB_DRIVERS//\ /,}"  &&

if [[ "x${MESALIB_BRANCH}" == "xdevelopment" ||
      "x${MESALIB_BRANCH}" == "xscm"         ]]; then
  case $MESALIB_GALLIUM in
       llvm)  OPTS="${OPTS} --enable-gallium-llvm"                 ;;
       i915)  MESALIB_GALLIUM_CONF="$MESALIB_GALLIUM_CONF,i915"    ;;
    nouveau)  MESALIB_GALLIUM_CONF="$MESALIB_GALLIUM_CONF,nouveau" ;;
       r300)  MESALIB_GALLIUM_CONF="$MESALIB_GALLIUM_CONF,r300"    ;;
       r600)  MESALIB_GALLIUM_CONF="$MESALIB_GALLIUM_CONF,r600"    ;;
       svga)  MESALIB_GALLIUM_CONF="$MESALIB_GALLIUM_CONF,svga"    ;;
     swrast)  MESALIB_GALLIUM_CONF="$MESALIB_GALLIUM_CONF,swrast"  ;;
  esac &&

  OPTS="--with-gallium-drivers=$MESALIB_GALLIUM_CONF  \
        $OPTS"
else
  case $MESALIB_GALLIUM in
    llvm)    OPTS="${OPTS} --enable-gallium-llvm" ;;
    svga)    OPTS="${OPTS} --enable-gallium-svga" ;;
    intel)   OPTS="${OPTS} --enable-gallium-intel" ;;
    i915)    OPTS="${OPTS} --enable-gallium-i915" ;;
    i965)    OPTS="${OPTS} --enable-gallium-i965" ;;
    radeon)  OPTS="${OPTS} --enable-gallium-radeon --disable-gallium-intel"
       LDFLAGS="${LDFLAGS/-s/}" ;;
    r600)    OPTS="${OPTS} --enable-gallium-r600" ;;
    nouveau) OPTS="${OPTS} --enable-gallium-nouveau --disable-gallium-intel" ;;
    swrast)  OPTS="${OPTS} --enable-gallium-swrast" ;;
    none)    OPTS="${OPTS} --disable-gallium" ;;
  esac
fi &&

OPTS="--with-driver=$MESALIB_BUILD  \
        --with-dri-drivers=$MESALIB_DRIVERS_CONF  \
      --with-egl-platforms=${MESA_EGL//\ /,}  \
      $MESALIB_OPTS  \
      $OPTS"                                           &&
default_build
