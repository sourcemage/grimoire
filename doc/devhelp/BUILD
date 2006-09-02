if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-gecko=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
   OPTS="$OPTS --with-gecko=seamonkey"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
   OPTS="$OPTS --with-gecko=xulrunner"
else
   OPTS="$OPTS --with-gecko=mozilla"
fi &&

default_build
