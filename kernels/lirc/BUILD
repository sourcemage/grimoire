# Remove their CFLAGS, but make sure only literal CFLAGS definition is gone.
sedit 's|^CFLAGS="[^$]*"$|#\0|g' configure &&
default_build
