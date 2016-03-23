. "${GRIMOIRE}/FUNCTIONS" &&

if spell_ok libxext && is_version_less $(installed_version libxext) 1.3.0; then
  message "${MESSAGE_COLOR}Old version of ${SPELL_COLOR}libxext${MESSAGE_COLOR} detected, forcing NO_XSYNC=1...${DEFAULT_COLOR}" &&

  list_add COMPTON_OPTS "NO_XSYNC=1"
fi &&

make ${OPTS} ${COMPTON_OPTS}
