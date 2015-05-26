bmake \
    CFLAGS="$CFLAGS -isystem $INSTALL_ROOT/usr/include/bsd -DLIBBSD_OVERLAY" \
    LDFLAGS="${LDFLAGS//-Wl,--as-needed} -lbsd"
