CFLAGS+=" -isystem \"$INSTALL_ROOT\"/usr/include/bsd -DLIBBSD_OVERLAY" &&
CFLAGS+=" -isystem \"$INSTALL_ROOT\"/usr/include/tirpc" &&
bmake \
    CFLAGS="$CFLAGS" \
    LDFLAGS="${LDFLAGS//-Wl,--as-needed} -lbsd -ltirpc"
