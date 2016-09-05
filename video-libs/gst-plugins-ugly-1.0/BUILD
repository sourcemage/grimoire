if [ "$GST_PLUGINS_UGLY_MP3" = "y" ]; then
  OPTS="--enable-mad $OPTS"
else
  OPTS="--disable-mad $OPTS"
fi  &&
if [[ $GST_PLUGINS_UGLY_EXPERIMENTAL == "y" ]]; then
  OPTS+=" --enable-experimental"
fi &&
default_build
