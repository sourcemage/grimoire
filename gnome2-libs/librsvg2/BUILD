if [ "$RSVGENGINE" == "y" ]; then
   OPTS="$OPTS --enable-gtk-theme"
else
   OPTS="$OPTS --disable-gtk-theme"
fi                                      &&

CFLAGS="${CFLAGS} -I/usr/include/nspr"  && 

if test "$(get_spell_provider $SPELL GECKO)" = firefox; then
  sedit  's:mozilla/plugins:firefox/plugins:'  moz-plugin/Makefile.in  &&
  # note: needs to be exported or configure won't see it
  export MOZILLA_CONFIG=firefox-config
elif test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  sedit  's:mozilla/plugins:seamonkey/plugins:'  moz-plugin/Makefile.in  &&
  export MOZILLA_CONFIG=seamonkey-config
fi

default_build
