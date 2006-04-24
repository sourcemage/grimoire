(

  ./configure  --prefix=${INSTALL_ROOT}/usr                      \
               --sysconfdir=${INSTALL_ROOT}/etc                  \
               --localstatedir=${INSTALL_ROOT}/var               \
               --with-messages=${INSTALL_ROOT}/var/log/messages  &&
  make                                                           &&
  prepare_install                                                &&
  make    install

) > $C_FIFO 2>&1
