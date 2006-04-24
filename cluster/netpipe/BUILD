(
  prepare_install						&&	
  make  tcp							&&
  install  -m 755  NPtcp      ${INSTALL_ROOT}/usr/bin  		&&
  mkdir -p ${INSTALL_ROOT}/usr/share/doc/$SPELL/  		&&	
  install -m 0644 dox/netpipe_paper.ps ${INSTALL_ROOT}/usr/share/doc/$SPELL/netpipe_paper.ps
  if spell_ok mpich
  then
    sedit  "s/MPI_ARCH   =.*$/MPI_ARCH   =LINUX/"  makefile
    sedit  "s/-lmpi/-lmpich/"  makefile
    make  mpi							&&
    install  -m 755  NPmpi    ${INSTALL_ROOT}/usr/bin
  fi 
 
  if spell_ok pvm
  then
    make  pvm							&&
    install  -m 755  NPpvm    ${INSTALL_ROOT}/usr/bin
  fi

) > $C_FIFO 2>&1

