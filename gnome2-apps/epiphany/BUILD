if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
   OPTS="$OPTS --with-mozilla=firefox"
else
   OPTS="$OPTS --with-mozilla=mozilla"
fi &&

make_single    &&
default_build  &&
make_normal
