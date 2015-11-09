CXXFLAGS=-D__STDC_CONSTANT_MACROS &&
OPTS+=" -DCMAKE_BUILD_TYPE=Release -DBUILD_DOCS=0 -DBUILD_PERF_TESTS=0 \
  -DBUILD_TESTS=0 -Wno-dev" &&
if [[ $CV_CONTRIB != none ]];then
 OPTS+=" -DOPENCV_EXTRA_MODULES_PATH=$SOURCE_DIRECTORY/contrib"
fi &&

OPTS+=" -DOPENCV_MODULES_DISABLED_USER_ST=\"$CV_DISABLE\""
OPTS+=" -DIPPROOT=$SOURCE_DIRECTORY/ippicv_lnx" &&

if is_depends_enabled $SPELL qtbase;then
  qt5_cmake_build
else
  cmake_build
fi
