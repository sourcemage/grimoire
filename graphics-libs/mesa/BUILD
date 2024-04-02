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

if is_depends_enabled "${SPELL}" libva &&
 ! list_find "${MESA_VA_CODECS}" "none"; then
  OPTS+=" video-codecs=${MESA_VA_CODECS// /,}"
fi &&

local vulkan=${MESA_VULKAN//none} &&
local gallium=${MESA_GALLIUM//none} &&

# for NVK
if list_find "${MESA_VULKAN}" "nouveau"; then
  python3 bin/git_sha1_gen.py --output src/git_sha1.h
fi &&

OPTS+=" gallium-drivers=${gallium// /,} \
     vulkan-drivers=${vulkan// /,} \
          platforms=${MESA_EGL// /,} \
                glx=${MESA_GLX// /,} \
              tools=${MESA_TOOLS// /,} \
     $MESA_GLES1 $MESA_GLES2" &&

default_build
