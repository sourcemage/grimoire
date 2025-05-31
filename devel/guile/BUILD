OPTS="--disable-error-on-warning $OPTS" &&
# not C23 compatible yet (3.0.10)
CFLAGS="${CFLAGS//-ffast-math } -std=gnu17" &&
LDFLAGS+=" -L$INSTALL_ROOT/lib" &&
default_build
