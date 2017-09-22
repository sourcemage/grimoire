cd "$SOURCE_DIRECTORY" &&
CM_BUILD_TYPE=Release &&
if is_depends_enabled $SPELL qtbase; then
  qt5_cmake_build
else
  cmake_build
fi
