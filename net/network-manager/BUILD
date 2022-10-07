OPTS+=" tests=no"
#OPTS+=" wext=false" #obsolete
OPTS+=" qt=false"
#OPTS+=" $NM_DOCS"
if is_depends_enabled $SPELL systemd; then
  OPTS+=" session_tracking=systemd"
else
  OPTS+=" session_tracking=elogind"
  OPTS+=" suspend_resume=elogind"
  OPTS+=" systemd_journal=false"
  OPTS+=" systemdsystemunitdir=no"
fi &&
if is_depends_enabled $SPELL iwd; then
  config_wifi_backend_default=iwd
else
  config_wifi_backend_default=wpa_supplicant
fi &&
default_build
