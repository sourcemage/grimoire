# requires at least -O2 to not segfault on startup with gcc 4.0
if ! echo "$CFLAGS" | grep -q -- '-O3'; then
  CFLAGS="$CFLAGS -O2"      &&
  CXXFLAGS="$CXXFLAGS -O2"
fi &&

OPTS="$EPIPHANY_TESTS \
      $OPTS" &&

make_single   &&
default_build &&
make_normal
