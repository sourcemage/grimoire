create_account ntp &&

OPTS="--with-privsep-user=ntp \
      $OPTS" &&

# Allow multiple definitions for ld.bfd, required with binutils 2.35+
if ! is_version_less $(installed_version binutils) 2.35; then
  LDFLAGS+=" -Wl,--allow-multiple-definition"
fi &&
default_build
