# this is recommended by the author
CFLAGS=${CFLAGS/-O3/-O2}      &&
CXXFLAGS=${CXXFLAGS/-O3/-O2}  &&
# doesn't compile with -DPIC -fPIC, bug #8426
disable_pic  &&
if   test "$(get_spell_provider $SPELL GECKO)" = "firefox"; then
  OPTS="--with-jsapi-include=/usr/include/firefox/js/"  &&
  LDFLAGS="-L/usr/lib/firefox -Wl,-rpath -Wl,/usr/lib/firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = "seamonkey"; then
  OPTS="--with-jsapi-include=/usr/include/seamonkey-$(installed_version seamonkey)/js"  &&
  LDFLAGS="-L/usr/lib/seamonkey -Wl,-rpath -Wl,/usr/lib/seamonkey"
else
  OPTS="--with-jsapi-include=/usr/include/mozilla-$(installed_version mozilla)/js"  &&
  LDFLAGS="-L/usr/lib/mozilla -Wl,-rpath -Wl,/usr/lib/mozilla"
fi  &&
default_build
