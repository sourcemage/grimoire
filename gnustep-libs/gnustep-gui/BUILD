if test "$(get_spell_provider $SPELL LIBGIF)" = giflib; then
  OPTS="--disable-ungif --enable-libgif $OPTS"
fi &&
if test "$(get_spell_provider $SPELL LIBGIF)" = libungif; then
  OPTS="--enable-ungif --disable-libgif $OPTS"
fi &&
default_build
