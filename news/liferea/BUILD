if [[ "$LIFEREA_DEVEL" == "n" ]]; then
  if test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
    OPTS="$OPTS --with-gecko=seamonkey"
  elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
    OPTS="$OPTS --with-gecko=libxul-embedding"
  elif test "$(get_spell_provider $SPELL GECKO)" = mozilla; then
    OPTS="$OPTS --with-gecko=mozilla"
  fi
fi &&
default_build
