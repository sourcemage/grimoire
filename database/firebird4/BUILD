CXXFLAGS+=" -Wno-narrowing -Wno-deprecated-declarations -Wno-invalid-offsetof" &&
#CXXFLAGS+=" -fno-sized-deallocation -fno-delete-null-pointer-checks -flifetime-dse=1 -fcheck-new" &&
CXXFLAGS+=" -Wno-deprecated" &&
CXXFLAGS+=" -Wno-stringop-overflow" &&
CXXFLAGS+=" -fPIC" &&
persistent_add FB_PREFIX               &&
export FB_PREFIX=${INSTALL_ROOT}/opt/firebird4 &&
cmake_build $FB_PREFIX &&

cd $SOURCE_DIRECTORY/build &&
if is_depends_enabled $SPELL ninja-build-system; then
#if [[ $CMAKE_GEN == Ninja ]];then
  ninja copy_files
else
  make copy_files
fi
