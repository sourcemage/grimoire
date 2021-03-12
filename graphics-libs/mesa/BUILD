case "$HOST" in
*-gnu) ;;
*)
  local unportable=(intel intel-ui)
  message "${PROBLEM_COLOR}WARNING:$DEFAULT_COLOR" \
    "Disabling non-portable tools: ${unportable[*]}"
  MESA_TOOLS=" ${MESA_TOOLS} "
  for i in "${unportable[@]}"; do
    MESA_TOOLS="${MESA_TOOLS// $i / }"
  done
  MESA_TOOLS="${MESA_TOOLS# }"
  MESA_TOOLS="${MESA_TOOLS% }"
  ;;
esac
#LDFLAGS=''  &&
#CXXFLAGS='' &&
local vulkan=${MESA_VULKAN//none} &&
local gallium=${MESA_GALLIUM//none} &&
local dri=${MESA_DRI//none} &&
OPTS+=" dri-drivers=${dri// /,} \
    gallium-drivers=${gallium// /,} \
     vulkan-drivers=${vulkan// /,} \
          platforms=${MESA_EGL// /,} \
                glx=${MESA_GLX// /,} \
              tools=${MESA_TOOLS// /,} \
         swr-arches=${MESA_ARCH// /,} \
     $MESA_GLES1 $MESA_GLES2" &&
echo "OPTS=$OPTS" &&

#PREFIX=/opt/mesa &&
PREFIX=/usr &&
default_build
