(

  sedit  "s/-Wall/-Wall $CFLAGS/"  Makefile

  make                            &&
  prepare_install                 &&

  cp arpoison ${INSTALL_ROOT}/usr/sbin/arpoison  &&
  cp arpoison.8 ${INSTALL_ROOT}/usr/share/man/man8

) > $C_FIFO 2>&1
