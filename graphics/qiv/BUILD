if ! echo $OPTS | grep -q xinerama; then
  sedit  "s/^GTD_XINERAMA/#GTD_XINERAMA/"  Makefile
fi  &&
if ! echo $OPTS | grep -q exif; then
  sedit  "s/^EXIF/#EXIF/"  Makefile
fi  &&
make
