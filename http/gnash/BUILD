CXXFLAGS=${CXXFLAGS/-Os/-O2}
CFLAGS=${CFLAGS/-Os/-O2}
OPTS="$GNASH_OPTS $OPTS"  &&
sed -i '/^LIBS/s/\(.*\)/\1 -lboost_system/' \
  gui/Makefile.in utilities/Makefile.in &&
if [[ "$GNASH_MEMORY" == "posix" ]]; then
  list_add OPTS "--with-shm=posix"
else
  list_add OPTS "--with-shm=sysv"
fi                        &&
default_build
