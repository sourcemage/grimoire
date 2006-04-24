leave_config()  {
  if  [  -f  ${INSTALL_ROOT}/etc/pnm2ppa.conf  ];  then
    sedit  "s/^.*INSTALL.*pnm2ppa.conf.*$/#/"  Makefile
  fi
}

(

  sedit  "s:-O2 :$CFLAGS :"  Makefile                     &&
  sedit  "s:/usr/local/:${INSTALL_ROOT}/usr/:"  Makefile  &&

  make                                                    &&
  prepare_install                                         &&
  leave_config                                            &&
  make    install

) > $C_FIFO 2>&1
