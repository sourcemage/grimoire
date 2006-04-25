if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-gecko=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
   OPTS="$OPTS --with-gecko=seamonkey"
else
   OPTS="$OPTS --with-gecko=mozilla"
fi &&

# requires at least -O2 to not segfault on startup with gcc 4.0
if ! echo "$CFLAGS" | grep -q -- '-O3'; then
  CFLAGS="$CFLAGS -O2"      &&
  CXXFLAGS="$CXXFLAGS -O2"
fi  &&
make_single    &&
default_build  &&
make_normal
