CXXFLAGS+=" -Wno-narrowing -Wno-deprecated-declarations -Wno-invalid-offsetof" &&
CXXFLAGS+=" -fno-sized-deallocation -fno-delete-null-pointer-checks -flifetime-dse=1 -fcheck-new" &&
CXXFLAGS+=" -Wno-deprecated" &&
CXXFLAGS+=" -fPIC" &&
OPTS+=" -DCMAKE_CXX_STANDARD=11" &&
OPTS+=" -DCMAKE_C_STANDARD=11" &&
persistent_add FB_PREFIX               &&
FB_PREFIX=${INSTALL_ROOT}/opt/firebird3 &&
cmake_build $FB_PREFIX &&
if [[ $CMAKE_GEN == Ninja ]];then
  ninja copy_files
else
  make copy_files
fi

