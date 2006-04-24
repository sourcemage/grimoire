if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
  OPTS="$OPTS --with-mozilla=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  OPTS="$OPTS --with-mozilla=seamonkey"
elif test "$(get_spell_provider $SPELL GECKO)" = mozilla; then
  OPTS="$OPTS --with-mozilla=mozilla"
else
  OPTS="$OPTS --without-mozilla"
fi  &&
default_build
