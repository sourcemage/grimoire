cd js/src &&

CFLAGS="-DJS_C_STRINGS_ARE_UTF8 $CFLAGS" &&

#
# Only strip if the user wants us to
#
if echo $LDFLAGS | grep -q -- '-s'; then
  OPTS="--enable-strip $OPTS"
else
  OPTS="--disable-strip $OPTS"
fi &&

default_build
