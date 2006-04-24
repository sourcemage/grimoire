if test "$(get_spell_provider $SPELL GECKO)" = "firefox"; then
   OPTS="$OPTS --with-mozilla=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = "seamonkey"; then
   OPTS="$OPTS --with-mozilla=seamonkey"
else
   OPTS="$OPTS --with-mozilla=mozilla"
fi &&

if [ "$BUILDALL" == "y" ] ; then
   if grep -q "epiphany:dbus:on:optional:" $DEPENDS_STATUS -a grep -q 'BUILDUTF8="y"' /etc/sorcery/local/depends/pcre.p ; then
      OPTS="$OPTS --with-extensions=really-all"
   else
      OPTS="$OPTS --with-extensions=all"
   fi
fi &&

default_build
