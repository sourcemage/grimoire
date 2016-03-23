# I am confused about that. According to
# https://bugs.freedesktop.org/show_bug.cgi?id=70471
# llvm-config output should contain -fno-rtti.
CXXFLAGS+=" -fno-rtti" &&
OPTS="--with-dri-drivers=${MESALIB_DRIVERS// /,} \
      --with-gallium-drivers=${MESALIB_GALLIUM// /,} \
      $MESALIB_OPTS \
      --with-egl-platforms=${MESA_EGL//\ /,}  \
      $OPTS" && 
echo "OPTS=$OPTS" &&
default_build
