(

  ./configure  --prefix=${INSTALL_ROOT}/usr         \
               --sysconfdir=${INSTALL_ROOT}/etc     \
               --localstatedir=${INSTALL_ROOT}/var  \
               --disable-debug       \
	       --enable-final        \
	       $OPTS                 &&
  make                               &&
  make    install

) > $C_FIFO 2>&1
