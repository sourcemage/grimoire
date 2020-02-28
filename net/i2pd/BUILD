. "${GRIMOIRE}/FUNCTIONS" &&

OPTS="${I2PD_OPTS} ${OPTS}" &&

if spell_ok gcc && is_version_less $(installed_version gcc) 4.7; then
  LDFLAGS="-lboost_chrono ${LDFLAGS}"
fi &&

make $OPTS all api api_client &&

if list_find "$LDFLAGS" "-s"; then
  make strip
fi
