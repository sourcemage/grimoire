if [[ $SQLITE_META == y ]]; then
  CFLAGS="-DSQLITE_ENABLE_COLUMN_METADATA=1 $CFLAGS"
fi &&

if [[ $SQLITE_SECURE_DELETE == y ]]; then
  CFLAGS="-DSQLITE_SECURE_DELETE $CFLAGS"
fi &&

LDFLAGS="-ldl $LDFLAGS" &&
CFLAGS="${CFLAGS//-ffast-math}" &&
OPTS="--enable-load-extension $SQLITE_TSAFE $OPTS" &&

default_build
