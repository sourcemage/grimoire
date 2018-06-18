SRC=$SOURCE_DIRECTORY/sources/$SPELL &&
cd $SRC &&
CPPFLAGS+="-Wno-cpp" &&
CXXFLAGS+=" -Wno-deprecated-declarations"
OPTS+=" -DDISABLE_DOCSTRINGS=1"
OPTS+=' -DBUILD_TESTS=0' &&
# install things to /usr
PATH="$QT5DIR/bin/:$PATH" &&
#export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig" &&
cmake_build

