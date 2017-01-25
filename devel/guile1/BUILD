OPTS="--disable-error-on-warning $OPTS" &&
OPTS="--program-suffix=1 $OPTS"         &&
OPTS="--disable-static $OPTS"           &&
OPTS="--enable-posix $OPTS"             &&
CFLAGS="${CFLAGS//-ffast-math }"        &&
LDFLAGS+=" -L$INSTALL_ROOT/lib"         &&
default_build
