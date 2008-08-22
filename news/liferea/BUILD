if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
  OPTS="$OPTS --enable-gecko=firefox --disable-xulrunner"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  OPTS="$OPTS --enable-gecko=seamonkey --disable-xulrunner"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
  OPTS="$OPTS --enable-xulrunner --disable-gecko"
elif test "$(get_spell_provider $SPELL GECKO)" = mozilla; then
  OPTS="$OPTS --enable-gecko=mozilla --disable-xulrunner"
fi  &&
default_build
