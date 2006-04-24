(

  ./configure  --prefix=${INSTALL_ROOT}/usr  \
               $OPTS                         &&
  make                                       &&
  prepare_install                            &&
  make    install                            &&
  make    install_filters

) > $C_FIFO 2>&1
