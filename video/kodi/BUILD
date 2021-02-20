OPTS+=" -DCORE_PLATFORM_NAME=X11" &&
OPTS+=" -DAPP_RENDER_SYSTEM=gl"   &&

if ! (get_spell_provider "${SPELL}" "LIBAVCODEC" 2> /dev/null); then
  check_tmp_noexec /tmp 
fi &&

default_build &&

if ! (get_spell_provider "${SPELL}" "LIBAVCODEC" 2> /dev/null); then
  check_tmp_noexec /tmp  
fi
