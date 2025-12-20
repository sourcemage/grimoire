OPTS="--disable-error-on-warning $OPTS" &&
# not C23 compatible yet (3.0.10)
force_dialect gnu17 &&
CFLAGS="${CFLAGS//-ffast-math }" &&
LDFLAGS+=" -L$INSTALL_ROOT/lib" &&
default_build
