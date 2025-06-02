if [[ $SQLITE_ENABLE_JSON1 == y ]];then
  CFLAGS="-DSQLITE_ENABLE_JSON1  $CFLAGS"
fi &&
if [[ $SQLITE_META == y ]]; then
  CFLAGS="-DSQLITE_ENABLE_COLUMN_METADATA=1 $CFLAGS"
fi &&

if [[ $SQLITE_SECURE_DELETE == y ]]; then
  CFLAGS="-DSQLITE_SECURE_DELETE $CFLAGS"
fi &&

if [[ $SQLITE_ENABLE_UNLOCK == y ]]; then
  CFLAGS="-DSQLITE_ENABLE_UNLOCK_NOTIFY $CFLAGS"
fi &&

if [[ $SQLITE_ENABLE_DBSTAT_VTAB == y ]]; then
  CFLAGS="-DSQLITE_ENABLE_DBSTAT_VTAB $CFLAGS"
fi &&

if [[ "${SQLITE_ENABLE_FTS3}" == "y" ]];then
  CFLAGS="-DSQLITE_ENABLE_FTS3 ${CFLAGS}"
fi &&

LDFLAGS="-ldl $LDFLAGS" &&
CFLAGS="${CFLAGS//-ffast-math}" &&
OPTS="$SQLITE_TSAFE $OPTS" &&

default_build &&

if [[ $SQLITE_VERSION == tea ]]; then
  # reset options to these
  OPTS="--with-tcl=$INSTALL_ROOT/usr/lib" &&

  cd tea &&
  default_build
fi
