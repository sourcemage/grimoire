# Remove their CFLAGS, but make sure only literal CFLAGS definition is gone.
sedit 's|^CFLAGS="[^$]*"$|#\0|g' configure &&

message "Custom configuration: $LIRCOPTS" &&
OPTS="
  $OPTS
  $LIRCOPTS
  --with-kerneldir=${INSTALL_ROOT}/usr/src/linux-$(get_kernel_version)
  --with-moduledir=/lib/modules/$(get_kernel_version)/misc
" &&
default_build
