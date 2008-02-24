(

  ./configure  --prefix=${INSTALL_ROOT}/usr                    \
               --infodir=${INSTALL_ROOT}/usr/share/info        \
               --mandir=${INSTALL_ROOT}/usr/share/man          \
               $OPTS                &&
  make                              &&
  prepare_install                   &&
  make    install

) > $C_FIFO 2>&1
