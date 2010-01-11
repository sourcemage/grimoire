if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-gecko-engine=firefox"
fi &&
if test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
   OPTS="$OPTS --with-gecko-engine=seamonkey"
fi &&
if test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
   OPTS="$OPTS --with-gecko-engine=libxul"
fi &&

# requires at least -O2 to not segfault on startup with gcc 4.0
if ! echo "$CFLAGS" | grep -q -- '-O3'; then
  CFLAGS="$CFLAGS -O2"      &&
  CXXFLAGS="$CXXFLAGS -O2"
fi  &&
OPTS="$OPTS --enable-gtkmozembed"
#CFLAGS="$CFLAGS -I/usr/include/nspr" &&
#CXXFLAGS="$CXXFLAGS -I/usr/include/nspr" &&
default_build
