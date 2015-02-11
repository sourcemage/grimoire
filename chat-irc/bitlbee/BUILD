if list_find "$LDFLAGS" "-s"; then
  OPTS="--strip=1 $OPTS"
else
  OPTS="--strip=0 $OPTS"
fi &&

# BUILD file required because of --etcdir path
# no --sysconfdir is recognized by the bitlbee Makefile
./configure --prefix="$INSTALL_ROOT/usr" \
            --etcdir="$INSTALL_ROOT/etc/bitlbee" \
                     $BITLBEE_OPTS \
                     $OPTS &&

make &&

if [[ "$BITLBEE_BITLBEED" == y ]]; then
  cd ${SOURCE_DIRECTORY}/utils &&
  gcc $CFLAGS bitlbeed.c -o bitlbeed &&

  if list_find "$LDFLAGS" "-s"; then
    strip bitlbeed
  fi &&
  cd ..
fi
