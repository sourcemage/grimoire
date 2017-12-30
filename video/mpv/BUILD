OPTS="$MPV_OPTS $OPTS" &&

if is_depends_enabled $SPELL $(get_spell_provider $SPELL OPENGL); then
  local GLSELECT=n &&

  for provider in `gaze -q provides OPENGL`; do
    if spell_ok $provider && [[ $provider != mesalib ]]; then
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

OPTS+=" --bindir=${INSTALL_ROOT}/usr/bin --confdir=${INSTALL_ROOT}/etc/mpv" &&
waf_build
