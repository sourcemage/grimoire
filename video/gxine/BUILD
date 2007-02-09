if   test "$(get_spell_provider $SPELL GECKO)" = "firefox"; then
  JS_CFLAGS="-I/usr/include/firefox/js/"  &&
  LDFLAGS="-L/usr/lib/firefox -Wl,-rpath -Wl,/usr/lib/firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = "seamonkey"; then
  JS_CFLAGS="-I/usr/include/seamonkey-$(installed_version seamonkey)/js"  &&
  LDFLAGS="-L/usr/lib/seamonkey -Wl,-rpath -Wl,/usr/lib/seamonkey"
elif test "$(get_spell_provider $SPELL GECKO)" = "xulrunner"; then
  JS_CFLAGS="-I/usr/include/xulrunner-$(installed_version xulrunner)/js"  &&
  LDFLAGS="-L/usr/lib/xulrunner -Wl,-rpath -Wl,/usr/lib/xulrunner"
else
  JS_CFLAGS="-I/usr/include/mozilla-$(installed_version mozilla)/js"  &&
  LDFLAGS="-L/usr/lib/mozilla -Wl,-rpath -Wl,/usr/lib/mozilla"
fi  &&
# JS1_LIBS is used to completely ignore the madness of gxines JS lib detection,
# whatever configure does, the one actually used in the build is JS1_LIBS
JS1_LIBS="-lmozjs"  &&
export JS_CFLAGS JS1_LIBS  &&
default_build
