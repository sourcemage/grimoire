# I am confused about that. According to
# https://bugs.freedesktop.org/show_bug.cgi?id=70471
# llvm-config output should contain -fno-rtti.
CXXFLAGS+=" -fno-rtti" &&

local vulkan_drivers=${MESALIB_VULKAN// /,} &&
vulkan_drivers=${vulkan_drivers//none/no} &&

OPTS+=" --with-dri-drivers=${MESALIB_DRIVERS// /,} \
    --with-gallium-drivers=${MESALIB_GALLIUM// /,} \
     --with-vulkan-drivers=${vulkan_drivers} \
      --with-platforms=${MESA_EGL//\ /,} \
                 ${MESALIB_OPTS}" &&
default_build
