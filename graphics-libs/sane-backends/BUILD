CFLAGS+=' -Wno-error=maybe-uninitialized'
CFLAGS+=' -Wno-error=array-bounds='
CFLAGS+=' -Wno-error=unused-function'

#CFLAGS+=' -Wno-error=bidi-chars'
#CFLAGS+=' -Wno-error=format-truncation'
#CFLAGS+=' -Wno-error=tringop-overflow'
#CFLAGS+=' -Wno-error=nonnull'
#CFLAGS+=' -Wno-error='
#CFLAGS+=' -Wno-error='
create_group scanner &&

if [[ $IPV6 == y ]]; then
  OPTS="$OPTS --enable-ipv6"
else
  OPTS="$OPTS --disable-ipv6"
fi &&

if [[ "$SANE_BUILD_LOCAL" == n ]]; then
  OPTS="$OPTS --disable-local-backends"
fi &&

#OPTS="--disable-latex \
#      --with-docdir=$INSTALL_ROOT/usr/share/doc/sane-backends \
#      $OPTS" &&

default_build
