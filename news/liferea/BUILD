if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
  OPTS="$OPTS --enable-gecko=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  OPTS="$OPTS --enable-gecko=seamonkey"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
  OPTS="$OPTS --enable-xulrunner"
else
  OPTS="$OPTS --enable-gecko=mozilla"
fi  &&
default_build
