OPTS="${OPTS} --with-distro=none --with-avahi-user=avahi --with-avahi-group=avahi" &&
OPTS="${OPTS} --with-avahi-priv-access-group=netdev " &&

if [[ "$AVAHI_AUTOIPD" == 'y' ]]; then
  OPTS="${OPTS} --with-autoipd-user=avahi-autoipd --with-autoipd-group=avahi-autoipd"
fi &&

if [[ "$AVAHI_DAEMON" == 'n' ]]; then
  OPTS="${OPTS} --with-xml=none"
fi &&

if [[ "$AVAHI_NODBUS" == 'y' ]]; then
  OPTS="${OPTS} --disable-dbus"
fi &&

if [[ "$AVAHI_COMPAT_LIBDNS_SD" == 'y' ]]; then
  OPTS="$OPTS --enable-compat-libdns_sd"
fi &&

if [[ "$AVAHI_COMPAT_HOWL" == 'y' ]]; then
  OPTS="$OPTS --enable-compat-howl"
fi &&

default_build
