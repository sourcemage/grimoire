(

  OPTIMZATIONS="${OPTIMIZATIONS/strip/}"    &&

  ./configure --prefix=${INSTALL_ROOT}/usr  \
              $OPTS                         &&
  make                                      &&
  prepare_install                           &&
  make install

) > $C_FIFO 2>&1

