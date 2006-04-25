if test "$(get_spell_provider $SPELL GECKO)" = "firefox"; then
   OPTS="$OPTS --with-mozilla=firefox"
elif test "$(get_spell_provider $SPELL GECKO)" = "seamonkey"; then
   OPTS="$OPTS --with-mozilla=seamonkey"
else
   OPTS="$OPTS --with-mozilla=mozilla"
fi &&

OPTS="${OPTS} --with-extensions="
if [ "${EPIPHANY_ACTIONS}" == "y" ]; then
   OPTS="${OPTS}actions,"
fi                                              &&
if [ "${EPIPHANY_ADBLOCK}" == "y" ]; then
   OPTS="${OPTS}adblock,"
fi                                              &&
if [ "${EPIPHANY_AUTORULOAD}" == "y" ]; then
   OPTS="${OPTS}auto-reload,"
fi                                             &&
if [ "${EPIPHANY_AUTOSCROLL}" == "y" ]; then
   OPTS="${OPTS}auto-scroller,"
fi                                             &&
#if [ "${EPIPHANY_BOOKTRAY}" == "y" ]; then
#   OPTS="${OPTS}bookmarks-tray,"
#fi                                              &&
if [ "${EPIPHANY_CERTS}" == "y" ]; then
   OPTS="${OPTS}certificates,"
fi                                              &&
if [ "${EPIPHANY_DASHBOARD}" == "y" ]; then
   OPTS="${OPTS}dashboard,"
fi                                              &&
if [ "${EPIPHANY_ERRORVIEWER}" == "y" ]; then
   OPTS="${OPTS}error-viewer,"
fi                                              &&
if [ "${EPIPHANY_EXTMANUI}" == "y" ]; then
   OPTS="${OPTS}extensions-manager-ui,"
fi                                              &&
if [ "${EPIPHANY_FAVICON}" == "y" ]; then
   OPTS="${OPTS}favicon,"
fi                                              &&
if [ "${EPIPHANY_GESTURES}" == "y" ]; then
   OPTS="${OPTS}gestures,"
fi                                              &&
if [ "${EPIPHANY_GMONKEY}" == "y" ]; then
   OPTS="${OPTS}greasemonkey,"
fi                                              &&
if [ "${EPIPHANY_IMAGEBAR}" == "y" ]; then
   OPTS="${OPTS}imagebar,"
fi                                              &&
if [ "${EPIPHANY_JAVACON}" == "y" ]; then
   OPTS="${OPTS}java-console,"
fi                                              &&
#if [ "${EPIPHANY_NETMON}" == "y" ]; then
#   OPTS="${OPTS}net-monitor,"
#fi                                              &&
if [ "${EPIPHANY_PAGEINFO}" == "y" ]; then
   OPTS="${OPTS}page-info,"
fi                                              &&
if [ "${EPIPHANY_PERMS}" == "y" ]; then
   OPTS="${OPTS}permissions,"
fi                                              &&
if [ "${EPIPHANY_PUSHSCROLL}" == "y" ]; then
   OPTS="${OPTS}push-scroller,"
fi                                              &&
if [ "${EPIPHANY_PYCON}" == "y" ]; then
   OPTS="${OPTS}python-console,"
fi                                              &&
if [ "${EPIPHANY_RSS}" == "y" ]; then
   OPTS="${OPTS}rss,"
fi                                              &&
if [ "${EPIPHANY_SAMPLE}" == "y" ]; then
   OPTS="${OPTS}sample,"
fi                                              &&
if [ "${EPIPHANY_SAMPLEMOZ}" == "y" ]; then
   OPTS="${OPTS}sample-mozilla,"
fi                                              &&
if [ "${EPIPHANY_SAMPLEPY}" == "y" ]; then
   OPTS="${OPTS}sample-python,"
fi                                              &&
if [ "${EPIPHANY_SELECTSTYLE}" == "y" ]; then
   OPTS="${OPTS}select-stylesheet,"
fi                                              &&
if [ "${EPIPHANY_SIDEBAR}" == "y" ]; then
   OPTS="${OPTS}sidebar,"
fi                                              &&
if [ "${EPIPHANY_SMARTBOOK}" == "y" ]; then
   OPTS="${OPTS}smart-bookmarks,"
fi                                              &&
if [ "${EPIPHANY_TABGROUP}" == "y" ]; then
   OPTS="${OPTS}tab-groups,"
fi                                              &&
if [ "${EPIPHANY_TABSMENU}" == "y" ]; then
   OPTS="${OPTS}tabsmenu,"
fi                                              &&
if [ "${EPIPHANY_TABSTATE}" == "y" ]; then
   OPTS="${OPTS}tab-states"
fi                     

default_build

