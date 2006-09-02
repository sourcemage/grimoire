if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-mozilla=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
   OPTS="$OPTS --with-mozilla=seamonkey"
elif test "$(get_spell_provider $SPELL GECKO)" = xulrunner; then
   OPTS="$OPTS --with-mozilla=xulrunner"
else
   OPTS="$OPTS --with-mozilla=mozilla"
fi  &&

default_build
