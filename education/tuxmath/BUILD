(

  sedit  "s:/local::"                Makefile
  sedit  "s/-O2/$CFLAGS/"            Makefile
  sedit  "s:/usr/bin/:/usr/games/:"  Makefile
  make             &&
  prepare_install  &&
  mkdir -p ${INSTALL_ROOT}/usr/games &&
  make    install

) > $C_FIFO 2>&1
