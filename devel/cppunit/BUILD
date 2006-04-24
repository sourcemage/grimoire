(

  ./configure  --prefix=/usr        \
               --sysconfdir=/etc    \
               --localstatedir=/var \
	           $OPTS                &&
  make                              &&
  make    check                     &&
  prepare_install                   &&
  make    install

) > $C_FIFO 2>&1
