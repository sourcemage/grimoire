(

  patch  -p0  <  ${SCRIPT_DIRECTORY}/Makefile.in.patch  &&

  ./configure.sh  --prefix=${INSTALL_ROOT}/usr          \
                  $OPTS                                 &&
  make                                                  &&
  prepare_install                                       &&
  make    install

) > $C_FIFO 2>&1
