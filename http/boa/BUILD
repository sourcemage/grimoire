(

  ./configure  &&
  make         &&
  prepare_install  &&
  install  -m 755  src/boa  /usr/bin/boa  &&
  install  -m 644  docs/boa.8  /usr/share/man/man8

) > $C_FIFO 2>&1
