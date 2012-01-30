OPTS="${OPTS} ${RSYSLOG_OPTS}" &&
if spell_ok systemd ; then
  OPTS="${OPTS} --with-systemdsystemunitdir=${INSTALL_ROOT}/lib/systemd/system"
fi
default_build
