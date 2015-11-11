persistent_add FB_PREFIX               &&
FB_PREFIX=${INSTALL_ROOT}/opt/firebird &&
cd $SOURCE_DIRECTORY/build &&
cmake -DCMAKE_INSTALL_PREFIX=$FB_PREFIX \
      -DCMAKE_INSTALL_LOCALSTATEDIR=$INSTALL_ROOT/var \
      -DCMAKE_BUILD_TYPE=$CM_BUILD_TYPE \
      $OPTS $SOURCE_DIRECTORY &&
make &&
make copy_files
