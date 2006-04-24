if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-gecko-engine=firefox"
fi &&
if test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
   OPTS="$OPTS --with-gecko-engine=seamonkey"
fi &&
if test "$(get_spell_provider $SPELL GECKO)" = mozilla; then
   OPTS="$OPTS --with-gecko-engine=mozilla"
fi &&
if test "$(get_spell_provider $SPELL GECKO)" = mozilla-nightly; then
   OPTS="$OPTS --with-gecko-engine=mozilla"
fi &&
default_build
