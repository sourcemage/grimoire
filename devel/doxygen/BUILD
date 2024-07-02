OPTS="$ENGLISH_ONLY  $OPTS"
if is_depends_enabled $SPELL qt6base;then
  PATH="$QT6DIR/bin/:$PATH"
fi &&
if is_depends_enabled $SPELL fmt;then
  export CXXFLAGS+=' -DSPDLOG_FMT_EXTERNAL=ON'
fi &&

cmake_build
