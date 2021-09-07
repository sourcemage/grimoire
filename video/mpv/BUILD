OPTS="$MPV_OPTS $OPTS" &&

if is_depends_enabled "${SPELL}" "smgl-gl_select"; then
  local GLSELECT=n &&

  for provider in `gaze -q provides OPENGL`; do
    if spell_ok $provider && [[ $provider != mesalib || $provider != mesa ]]; then
      GLSELECT=y
    fi
  done &&

  if [[ $GLSELECT == y ]]; then
    message "${MESSAGE_COLOR}NOTICE: Other OPENGL provider than mesalib is installed;" &&
    message "$SPELL requires active mesalib headers - switching it now." &&
    message "Don't forget to switch back via smgl-gl_select script.${DEFAULT_COLOR}\n" &&

    glselect mesa
  fi
fi &&

if [[ $(get_spell_provider $SPELL LIBAVCODEC) == "ffmpeg-svn" ]]; then
  OPTS+=" --enable-ffmpeg-strict-abi"
fi &&

OPTS+=" --bindir=${INSTALL_ROOT}/usr/bin --confdir=${INSTALL_ROOT}/etc/mpv" &&
waf_build
