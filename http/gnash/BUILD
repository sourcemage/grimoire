CXXFLAGS=${CXXFLAGS/-Os/-O2}
CFLAGS=${CFLAGS/-Os/-O2}
OPTS="$GNASH_OPTS $OPTS"  &&
if [[ "$GNASH_MEMORY" == "posix" ]]; then
  list_add OPTS "--with-shm=posix"
else
  list_add OPTS "--with-shm=sysv"
fi                        &&
default_build
