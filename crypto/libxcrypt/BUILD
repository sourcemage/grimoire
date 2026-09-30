# keep libxcrypt out of libc's way
OPTS+=" --includedir=$INSTALL_ROOT/usr/include/xcrypt" &&
OPTS+=" --disable-xcrypt-compat-files" &&

OPTS="$BUILD_STATIC $OPTS" &&
OPTS="$OBSOLETE_APIS $OPTS" &&
OPTS="$OBSOLETE_STUBS $OPTS" &&
OPTS="$HASHES $OPTS" &&
OPTS="--disable-werror $OPTS" &&
CFLAGS="-Wno-error=strict-overflow" &&

default_build
