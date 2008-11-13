if test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  OPTS="$OPTS --with-gecko=seamonkey --disable-webkit"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
  OPTS="$OPTS --with-gecko=libxul-embedding --disable-webkit"
elif test "$(get_spell_provider $SPELL GECKO)" = mozilla; then
  OPTS="$OPTS --with-gecko=mozilla --disable-webkit"
fi  &&
default_build
