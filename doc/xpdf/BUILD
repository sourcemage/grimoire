OPTS+=" -DMULTITHREADED=ON ${A4_PAPER}" &&

if is_depends_enabled "$SPELL" qtbase; then
  # To enable finding Qt5
  PATH="$QT5DIR/bin:$PATH" &&
  # RPATH isn't being added by CMake
  LDFLAGS="$LDFLAGS -Wl,-rpath=$QT5DIR/lib"
fi &&

cmake_build
