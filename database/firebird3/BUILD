persistent_add FB_PREFIX               &&
FB_PREFIX=${INSTALL_ROOT}/opt/firebird &&
cmake_build $FB_PREFIX &&
if [[ $CMAKE_GEN == Ninja ]];then
  ninja copy_files
else
  make copy_files
fi

