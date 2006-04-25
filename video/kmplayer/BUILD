if ! list_find "$BACKENDS" "xine"; then
  OPTS="$OPTS --without-xine"
fi  &&
if ! list_find "$BACKENDS" "gstreamer"; then
  OPTS="$OPTS --without-gstreamer"
fi  &&

default_build
