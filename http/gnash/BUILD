#
# Copied from epiphany/BUILD
#
if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-firefox-prefix=$TRACK_ROOT/usr/lib/firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
   OPTS="$OPTS --with-firefox-prefix=$TRACK_ROOT/usr/lib/seamonkey"
else
   OPTS="$OPTS --with-firefox-prefix=$TRACK_ROOT/usr/lib/mozilla"
fi  &&

default_build
