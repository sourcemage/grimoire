CXXFLAGS=-D__STDC_CONSTANT_MACROS &&
OPTS+=" -DCMAKE_BUILD_TYPE=Release -DBUILD_DOCS=0 -DBUILD_PERF_TESTS=0 \
  -DBUILD_TESTS=0" &&
if is_depends_enabled $SPELL qt4;then
  qt4_cmake_build
else
  CMAKE_GEN='Unix Makefiles'  &&
  cmake_build
fi
