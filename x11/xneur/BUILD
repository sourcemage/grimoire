if list_find "$XNEUR_SOUND" "none"; then
  OPTS="$OPTS --with-sound=no"
fi  &&
if list_find "$XNEUR_SPELL" "none"; then
  OPTS="$OPTS --with-spell=no"
fi  &&
sed -i "s;-Werror -g0;-g0;" configure &&
default_build
