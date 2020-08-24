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
