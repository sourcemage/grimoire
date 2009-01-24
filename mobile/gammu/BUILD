if is_depends_enabled $SPELL mysql || is_depends_enabled $SPELL postgresql; then
   OPTS="-DWITH_BACKUP=ON $OPTS"
fi &&
 
OPTS="-DBUILD_SHARED_LIBS=ON $OPTS" &&
cmake_build
