if list_find "$CASTFS_OPTS" "--enable-debug"; then
  CFLAGS="${CFLAGS/-O?/}" &&
  LDFLAGS="${LDFLAGS/-s/}"
fi &&

OPTS="--disable-xattr $CASTFS_OPTS $OPTS" &&
default_build
