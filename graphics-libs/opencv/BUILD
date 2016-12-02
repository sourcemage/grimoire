CXXFLAGS=-D__STDC_CONSTANT_MACROS &&
OPTS+=" -DCMAKE_BUILD_TYPE=Release -DBUILD_DOCS=0 -DBUILD_PERF_TESTS=0 \
  -DBUILD_TESTS=0" &&
# PCH fails, at least with, with GCC 6.2
OPTS+=" -DENABLE_PRECOMPILED_HEADERS=0" &&

if is_depends_enabled $SPELL qt4;then
  qt4_cmake_build
else
  cmake_build
fi
