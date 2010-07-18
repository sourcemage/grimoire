if [ "$GST_PLUGINS_UGLY_MP3" = "y" ]; then
  OPTS="--enable-mad $OPTS"
else
  OPTS="--disable-mad $OPTS"
fi  &&
# disabled x264 plugin as it is not compatible with the current API
OPTS="$OPTS --disable-x264" &&
default_build
