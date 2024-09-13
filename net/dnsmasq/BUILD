if [[ "${DNSMASQ_RTC}" == y ]]; then
  OPTS="-DHAVE_BROKEN_RTC ${OPTS}"
fi &&

if [[ "${DNSMASQ_NO_ID}" == y ]]; then
  OPTS="-DNO_ID ${OPTS}"
fi &&

local i18_target &&

if is_depends_enabled $SPELL gettext; then
  i18_target="all-i18n"
fi &&

make COPTS="${DNSMASQ_OPTS} ${OPTS}" CFLAGS="${CFLAGS}" PREFIX="${INSTALL_ROOT}/usr" $i18n_target
