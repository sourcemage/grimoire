if   test "$(get_spell_provider $SPELL GECKO)" = "firefox"; then
  OPTS="--with-jsapi-include=/usr/include/firefox/js/"  &&
  LDFLAGS="-L/usr/lib/firefox -Wl,-rpath -Wl,/usr/lib/firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = "seamonkey"; then
  OPTS="--with-jsapi-include=/usr/include/seamonkey-$(installed_version seamonkey)/js"  &&
  LDFLAGS="-L/usr/lib/seamonkey -Wl,-rpath -Wl,/usr/lib/seamonkey"
elif test "$(get_spell_provider $SPELL GECKO)" = "xulrunner"; then
  OPTS="--with-jsapi-include=/usr/include/xulrunner-$(installed_version xulrunner)/js"  &&
  LDFLAGS="-L/usr/lib/xulrunner -Wl,-rpath -Wl,/usr/lib/xulrunner"
else
  OPTS="--with-jsapi-include=/usr/include/mozilla-$(installed_version mozilla)/js"  &&
  LDFLAGS="-L/usr/lib/mozilla -Wl,-rpath -Wl,/usr/lib/mozilla"
fi  &&
default_build
