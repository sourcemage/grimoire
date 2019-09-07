OPTS="-DHAVE_RULES=true $OPTS" &&
if is_depends_enabled $SPELL qtbase; then
  qt5_cmake_build
else
  cmake_build
fi
