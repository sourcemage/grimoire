(

  ./configure  --host=$BUILD                             \
               --prefix=${INSTALL_ROOT}/usr              \
               --sysconfdir=${INSTALL_ROOT}/etc          \
               --localstatedir=${INSTALL_ROOT}/var       \
               $OPTS                                     &&
  sedit  "s% -L/usr/lib % %g"  printerconf/src/Makefile  &&
  make                                                   &&
  prepare_install                                        &&
  make    install

) > $C_FIFO 2>&1
