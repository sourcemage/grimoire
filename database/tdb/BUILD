OPTS="$TDB_OPTS $OPTS" &&

if [[ $TDB_MMAP == y ]]; then
  CFLAGS="-DHAVE_MMAP=1 $CFLAGS"
fi &&

if [[ $TDB_NOLOCK == y ]]; then
  CFLAGS="-DNOLOCK=1 $CFLAGS"
fi &&

default_build
