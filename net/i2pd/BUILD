OPTS="${I2PD_OPTS} ${OPTS}" &&

make $OPTS all api api_client &&

if list_find "$LDFLAGS" "-s"; then
  make strip
fi
