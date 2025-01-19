# XXX The use of the initial-exec TLS model requires non-standard arrangements
#     by the loader, only implemented by glibc, and causes dlopen of libGL to
#     fail under several circumstances.  By using the gnu2 TLS dialect, the
#     global-dynamic model becomes as efficient as initial-exec in most
#     circumstances, and works with reduced performance where initial-exec
#     prevents loading altogether.  This is accompanied by a patch removing the
#     use of initial-exec and the related asm stubs.
CFLAGS="$CFLAGS -mtls-dialect=gnu2" &&
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
    MESA_TOOLS="${MESA_TOOLS## }"
    MESA_TOOLS="${MESA_TOOLS%% }"
    ;;
esac &&

# Remove -DPIC from compiler flags, produces build errors
CXXFLAGS="${CXXFLAGS//-DPIC}" &&

local link_llvm_shared
case "$MESA_LINK_LLVM_SHARED" in
  shared) link_llvm_shared="y" ;;
  static) link_llvm_shared="n" ;;
esac

meson_opt list "platforms" "$MESA_PLATFORMS" &&

meson_opt boolean "amd-use-llvm"           "$MESA_AMD_LLVM" &&
meson_opt boolean "draw-use-llvm"          "$MESA_DRAW_LLVM" &&
meson_opt feature "egl"                    "$MESA_EGL" &&
meson_opt boolean "gallium-nine"           "$MESA_GALLIUM_D3D9" &&
meson_opt boolean "gallium-d3d10umd"       "$MESA_GALLIUM_D3D10" &&
meson_opt feature "gallium-d3d12-graphics" "$MESA_GALLIUM_D3D12_PIPELINE" &&
meson_opt feature "gallium-d3d12-video"    "$MESA_GALLIUM_D3D12_VIDEO" &&
meson_opt boolean "gallium-extra-hud"      "$MESA_GALLIUM_HUD" &&
meson_opt feature "gallium-opencl"         "$MESA_OPENCL" &&
meson_opt boolean "gallium-rusticl"        "$MESA_RUSTICL" &&
meson_opt feature "gallium-xa"             "$MESA_GALLIUM_XA" &&
meson_opt feature "gbm"                    "$MESA_GBM" &&
meson_opt feature "gles1"                  "$MESA_GLES1" &&
meson_opt feature "gles2"                  "$MESA_GLES23" &&
meson_opt feature "glvnd"                  "$MESA_GLVND" &&
meson_opt choice  "glx"                    "$MESA_GLX" &&
meson_opt boolean "glx-direct"             "$MESA_GLX_DIRECT" &&
meson_opt boolean "glx-read-only-text"     "$MESA_GLX_READONLY" &&
meson_opt boolean "gpuvis"                 "$MESA_GPUVIS" &&
meson_opt feature "intel-rt"               "$MESA_INTEL_RAYTRACE" &&
meson_opt boolean "llvm-orcjit"            "$MESA_LLVM_ORCJIT" &&
meson_opt boolean "opencl-spirv"           "$MESA_OPENCL_SPIRV" &&
meson_opt boolean "opengl"                 "$MESA_OPENGL" &&
meson_opt boolean "osmesa"                 "$MESA_OSMESA" &&
meson_opt boolean "perfetto"               "$MESA_PERFETTO" &&
meson_opt feature "shader-cache"           "$MESA_SHADER_CACHE" &&
meson_opt feature "shared-llvm"            "$link_llvm_shared" &&
meson_opt boolean "spirv-to-dxil"          "$MESA_SPIRV_DXIL" &&
meson_opt boolean "teflon"                 "$MESA_TEFLON" &&
meson_opt feature "xlib-lease"             "$MESA_XLIB_LEASE" &&
meson_opt feature "xmlconfig"              "$MESA_XMLCONFIG" &&

if [ -z "$MESA_GALLIUM" ] || list_find "$MESA_GALLIUM" none ;then
  meson_opt list "gallium-drivers" ""
else
  meson_opt list "gallium-drivers" "$MESA_GALLIUM"
fi &&

if [ -n "$MESA_RUSTICL_DRIVERS" ] ;then
  meson_opt list "gallium-rusticl-enable-drivers" "$MESA_RUSTICL_DRIVERS"
fi &&

if [[ "$MESA_EGL" == y ]] && [ -n "$MESA_EGL_DEFAULT" ] ;then
  meson_opt choice "egl-native-platform" "$MESA_EGL_DEFAULT"
fi &&

if [ -z "$MESA_LIBCLC_STATIC_LINK" ] || list_find "$MESA_LIBCLC_STATIC_LINK" none ;then
  meson_opt list "static-libclc" ""
else
  meson_opt list "static-libclc" "$MESA_LIBCLC_STATIC_LINK"
fi &&

if [ -n "$MESA_PERFETTO_SOURCES" ] ;then
  meson_opt list "datasources" "$MESA_PERFETTO_SOURCES"
fi &&

if [ -z "$MESA_TOOLS" ] || list_find "$MESA_TOOLS" none ;then
  meson_opt list "tools" ""
else
  meson_opt list "tools" "$MESA_TOOLS"
fi &&

if [ -z "$MESA_VIDEO_CODECS" ] || list_find "$MESA_VIDEO_CODECS" none ;then
  meson_opt list "video-codecs" ""
else
  meson_opt list "video-codecs" "$MESA_VIDEO_CODECS"
fi &&

if [ -z "$MESA_VULKAN" ] || list_find "$MESA_VULKAN" none ;then
  meson_opt list "vulkan-drivers" ""
else
  meson_opt list "vulkan-drivers" "$MESA_VULKAN"
fi &&

if [ -z "$MESA_VULKAN_LAYERS" ] || list_find "$MESA_VULKAN_LAYERS" none ;then
  meson_opt list "vulkan-layers" ""
else
  meson_opt list "vulkan-layers" "$MESA_VULKAN_LAYERS"
fi &&

OPTS="${OPTS//  / }" &&
OPTS="${OPTS## }" &&
OPTS="${OPTS%% }" &&
default_build
