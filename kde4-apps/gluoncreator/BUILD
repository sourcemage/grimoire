cd $SOURCE_DIRECTORY/creator &&
  prepare_environment                             &&

  mkdir -p build                                  &&
  cd build                                        &&
  cmake -DCMAKE_INSTALL_PREFIX="$KDE4DIR"         \
        -DCMAKE_BUILD_TYPE=$KDE_DEBUG_OPTION      \
        $OPTS ../                                 &&
  make

