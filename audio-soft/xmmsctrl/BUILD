( 
  sedit "s:^PREFIX.*:PREFIX=$INSTALL_ROOT/usr:" Makefile &&
  make                                       &&
  prepare_install                            &&
  make    install
  
) > $C_FIFO 2>&1

