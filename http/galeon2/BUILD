# this should use get_spell_provider to check which provider the user chose,
# but that function isn't in stable sorcery yet
# default to using mozilla if both mozilla and firefox are installed, building
# against firefox results in less features
if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-mozilla=firefox"
else
   OPTS="$OPTS --with-mozilla=mozilla"
fi &&

default_build
