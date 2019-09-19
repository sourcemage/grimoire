SRC=$SOURCE_DIRECTORY/sources/$SPELL &&
cd $SRC &&
CPPFLAGS+="-Wno-cpp" &&
CXXFLAGS+=" -Wno-deprecated-declarations" &&
OPTS+=" -DDISABLE_DOCSTRINGS=1" &&
OPTS+=' -DBUILD_TESTS=0' &&
if is_depends_enabled shiboken2 python3; then
  OPTS+=" -DPYTHON_EXECUTABLE=${TRACK_ROOT}/usr/bin/python3"
else
  OPTS+=" -DPYTHON_EXECUTABLE=${TRACK_ROOT}/usr/bin/python"
fi &&
# install things to /usr
PATH="$QT5DIR/bin/:$PATH" &&
#export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig" &&
cmake_build

