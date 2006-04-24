  export COREDIR=$SOURCE_DIRECTORY/core                     &&
  export EBQTDIR=$SOURCE_DIRECTORY/ebqt                     && 
#core
  cd $COREDIR                                              &&
  ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var                  &&
  make                                                      &&
#ebqt
  cd $EBQTDIR                                           &&
    ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var                  &&
  make
