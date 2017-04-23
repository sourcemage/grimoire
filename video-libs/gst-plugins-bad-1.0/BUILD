if ! is_depends_enabled $SPELL gobject-introspection; then
  OPTS+=" --disable-introspection"
fi &&
OPTS="$OPTS --disable-examples"  &&
if [[ $GST_PLUGINS_BAD_EXPERIMENTAL == "y" ]]; then
  OPTS+=" --enable-experimental"
fi &&
default_build
