if [ "$XINELIB" == "n" ]; then
   sedit 's:xine_artsplugin:-xine_artsplugin:' subdirs  &&
   OPTS="$OPTS  --disable-xinetest"
fi                                                      &&

OPTS="$KDEMULTIMEDIA_CDDA $OPTS"                        &&
#patch -p0 < $SCRIPT_DIRECTORY/x86_64.patch              &&
source  $SECTION_DIRECTORY/KDE_BUILD
