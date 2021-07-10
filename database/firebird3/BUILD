CXXFLAGS+=" -Wno-narrowing -Wno-deprecated-declarations -Wno-invalid-offsetof" &&
CXXFLAGS+=" -fno-sized-deallocation -fno-delete-null-pointer-checks -flifetime-dse=1 -fcheck-new" &&
CXXFLAGS+=" -Wno-deprecated" &&
CXXFLAGS+=" -fPIC" &&
OPTS+=" -DCMAKE_CXX_STANDARD=11" &&
OPTS+=" -DCMAKE_C_STANDARD=11" &&
persistent_add FB_PREFIX               &&
FB_PREFIX=${INSTALL_ROOT}/opt &&
cmake_build $FB_PREFIX &&

cd $SOURCE_DIRECTORY/builddir &&
if is_depends_enabled $SPELL ninja-build-system; then
  ninja copy_files
else
  make copy_files
fi

