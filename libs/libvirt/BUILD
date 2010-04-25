OPTS="$LIBVIRT_REMOTE    \
      $LIBVIRT_LIBVIRTD  \
      $OPTS"             &&

#
# Fails to compile with -Wl,--as-needed
#
LDFLAGS=${LDFLAGS/-Wl,--as-needed} &&

default_build
