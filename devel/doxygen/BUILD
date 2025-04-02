. "$GRIMOIRE/build_system_handler.function" &&

OPTS="$OPTS $ENGLISH_ONLY" &&
OPTS="$OPTS -DGIT_EXECUTABLE=/bin/false" && # Don't try to use Git during build

if is_depends_enabled "$SPELL" qt6base ;then
  PATH="$QT6DIR/bin/:$PATH"
fi &&

if is_depends_enabled "$SPELL" fmt ;then
  export CXXFLAGS="$CXXFLAGS -DSPDLOG_FMT_EXTERNAL=ON"
fi &&

cmake_build
