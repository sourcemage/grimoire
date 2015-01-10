COPTS="$COPTS  $DNSMASQ_RTC $DNSMASQ_TFTP $DNSMASQ_DHCP $DNSMASQ_SCRIPT"
make COPTS="$OPTS $COPTS" &&
if is_depends_enabled $SPELL gettext; then
  make all-i18n
fi
