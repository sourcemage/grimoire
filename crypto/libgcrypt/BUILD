#
# Disable -O compiler flags; see HISTORY entry from 2008-01-07
#
# cryptsetup wants the static lib
OPTS+=" --enable-static" &&
if [[ "${SMGL_COMPAT_ARCHS[1]}" != "x86_64" ]]; then
  OPTS+=" --disable-shaext-support"
fi &&
default_build
