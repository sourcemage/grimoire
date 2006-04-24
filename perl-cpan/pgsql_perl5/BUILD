(

  export POSTGRES_INCLUDE=${INSTALL_ROOT}/usr/include
  export POSTGRES_LIB=${INSTALL_ROOT}/usr/lib
  perl Makefile.PL
  make             &&
  #make test        &&
  prepare_install  &&
  make    install

) > $C_FIFO 2>&1
