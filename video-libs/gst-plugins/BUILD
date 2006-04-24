OPTS="$OPTS --disable-examples --disable-tests"  &&
if spell_ok nvidia_driver; then
  # nvidia_driver breaks the opengl sink, bug #8361
  OPTS="$OPTS --disable-opengl"
fi  &&
if [ "$GST_PLUGINS_MP3" = "n" ]; then
  OPTS="$OPTS --disable-mad"
fi  &&
default_build
