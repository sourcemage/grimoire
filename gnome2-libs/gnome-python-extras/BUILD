if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-gtkmozembed=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
   OPTS="$OPTS --with-gtkmozembed=seamonkey"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
   OPTS="$OPTS --with-gtkmozembed=xulrunner"
else
   OPTS="$OPTS --with-gtkmozembed=mozilla"
fi &&

default_build
