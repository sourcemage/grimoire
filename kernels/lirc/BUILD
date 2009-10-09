# Remove their CFLAGS, but make sure only literal CFLAGS definition is gone.
sedit 's|^CFLAGS="[^$]*"$|#\0|g' configure &&
if [[ "$LIRC_ALL" == y ]]; then
  OPTS="$OPTS --with-driver=all"
else
  OPTS="$OPTS --with-driver=$LIRC_DRIVER"
fi &&
default_build
