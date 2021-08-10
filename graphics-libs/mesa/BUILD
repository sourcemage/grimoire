# XXX The use of the initial-exec TLS model requires non-standard arrangements
#     by the loader, only implemented by glibc, and causes dlopen of libGL to
#     fail under several circumstances.  By using the gnu2 TLS dialect, the
#     global-dynamic model becomes as efficient as initial-exec in most
#     circumstances, and works with reduced performance where initial-exec
#     prevents loading altogether.  This is accompanied by a patch removing the
#     use of initial-exec and the related asm stubs.
CFLAGS+=" -mtls-dialect=gnu2" &&
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
esac &&
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
        use-elf-tls=false \
     $MESA_GLES1 $MESA_GLES2" &&
echo "OPTS=$OPTS" &&
PREFIX=/usr &&
default_build
