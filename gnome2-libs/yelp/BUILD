if [ "$YELPMAN" == "y" ]; then
   OPTS="$OPTS --enable-man"
fi  &&

if [ "$YELPINFO" == "y" ]; then
   OPTS="$OPTS --enable-info"
fi  &&

if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-mozilla=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
   OPTS="$OPTS --with-mozilla=seamonkey"
else
   OPTS="$OPTS --with-mozilla=mozilla"
fi  &&

default_build
