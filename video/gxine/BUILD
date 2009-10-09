if test "$(get_spell_provider $SPELL GECKO)" = "seamonkey"; then
  JS_CFLAGS="-I/usr/include/seamonkey-$(installed_version seamonkey)/js"  &&
  LDFLAGS="-L/usr/lib/seamonkey -Wl,-rpath -Wl,/usr/lib/seamonkey"
elif test "$(get_spell_provider $SPELL GECKO)" = "xulrunner"; then
  xulversion=$(installed_version xulrunner) &&
  JS_CFLAGS="-I/usr/include/xulrunner-${xulversion:0:3}/unstable"  &&
  LDFLAGS="-L/usr/lib/xulrunner -Wl,-rpath -Wl,/usr/lib/xulrunner"
fi  &&
# JS1_LIBS is used to completely ignore the madness of gxines JS lib detection,
# whatever configure does, the one actually used in the build is JS1_LIBS
JS1_LIBS="-lmozjs"  &&
export JS_CFLAGS JS1_LIBS  &&
default_build
