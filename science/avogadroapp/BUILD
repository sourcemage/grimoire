OPTS+=' -DBUILD_SHARED_LIBS=1' &&  # avoid need for hdf5
if is_depends_enabled $SPELL qt6base;then
  OPTS+='  -DQT_VERSION=6'
fi &&
cmake_build
