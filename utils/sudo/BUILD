local editor="$(get_spell_provider $SPELL TEXT-EDITOR)" &&

if [[ -n ${editor} ]]; then
  hash $editor &&
  editor=$(hash -t $editor) &&

  OPTS="$OPTS --with-editor=$editor"
fi &&

default_build
