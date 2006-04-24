(

  sedit  "s/^LDFLAGS = .*/& $LDFLAGS/"  Makefile  &&
  make  &&
  prepare_install  &&
  make  PREFIX="${INSTALL_ROOT}/usr"  install

) > $C_FIFO 2>&1

