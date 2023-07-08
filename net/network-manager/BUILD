OPTS="$NM_TESTS $OPTS"
#OPTS="wext=false $OPTS" #obsolete
OPTS="qt=false $OPTS"
OPTS="$NM_DOCS $OPTS"
if ! is_depends_enabled "$SPELL" systemd; then
  OPTS="systemd_journal=false $OPTS"
  OPTS="systemdsystemunitdir=no $OPTS"
fi &&

OPTS="config_wifi_backend_default=${DEFAULT_WIFI:-wpa_supplicant} $OPTS"
OPTS="config_dhcp_default=${DEFAULT_DHCP:-internal} $OPTS"
OPTS="$NM_CRYPTO $OPTS"
OPTS="$LOGGING_BACKEND_OPT $OPTS"
OPTS="$SUSPEND_RESUME_OPT $OPTS"
OPTS="$SESSION_TRACKING_OPT $OPTS"

if [ -n "$LINUX_FIRMWARE" ] ;then
  OPTS="kernel_firmware_dir=${LINUX_FIRMWARE} $OPTS"
fi &&

# disable stripping
# if stripping is enabled the build fails with "no symbols" errors
LDFLAGS="${LDFLAGS//[, ]-s/}" &&
LDFLAGS="${LDFLAGS//-s[, ]/}" &&
LDFLAGS="${LDFLAGS//^-s$/}" &&

default_build
