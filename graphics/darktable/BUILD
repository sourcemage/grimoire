OPTS+=" -DCMAKE_BUILD_TYPE=Release"     &&
OPTS+=" -DDONT_INSTALL_GCONF_SCHEMAS=1" &&
OPTS+=" -DINSTALL_IOP_LEGACY=1"         &&
OPTS+=" -DINSTALL_IOP_EXPERIMENTAL=1"   &&
OPTS+=" -DBINARY_PACKAGE_BUILD=1"       &&
CFLAGS="${CFLAGS} -Wno-error=deprecated-declarations" \
  CXXFLAGS="${CXXFLAGS} -Wno-error=deprecated-declarations -fpermissive" cmake_build
