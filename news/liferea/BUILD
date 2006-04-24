if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
  OPTS="$OPTS --enable-gecko=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  OPTS="$OPTS --enable-gecko=seamonkey"
else
  OPTS="$OPTS --enable-gecko=mozilla"
fi  &&
default_build
