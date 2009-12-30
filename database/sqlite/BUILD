if [[ $SQLITE_META == y ]]; then
  CFLAGS="-DSQLITE_ENABLE_COLUMN_METADATA=1 $CFLAGS"
fi &&

LDFLAGS="-ldl $LDFLAGS" &&
CFLAGS="${CFLAGS//-ffast-math}" &&
OPTS="--enable-load-extension $SQLITE_TSAFE $OPTS" &&

default_build
