COPTS="$COPTS $DNSMASQ_IDN $DNSMASQ_RTC $DNSMASQ_TFTP $DNSMASQ_DHCP $DNSMASQ_SCRIPT"
if is_depends_enabled $SPELL dbus; then
    COPTS="$COPTS -DHAVE_DBUS"
fi &&
if is_depends_enabled $SPELL gettext; then
    make AWK=gawk PREFIX=/usr CFLAGS="$CFLAGS $COPTS" all-i18n
else
    make AWK=gawk PREFIX=/usr CFLAGS="$CFLAGS $COPTS"
fi
