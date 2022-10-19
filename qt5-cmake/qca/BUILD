if is_depends_enabled $SPELL qt6base; then
  OPTS+=' QT6=1'
fi &&
CXXFLAGS+=" -Wno-cpp -fpermissive"
OPTS+=' -DBUILD_TESTS=0'
default_build
