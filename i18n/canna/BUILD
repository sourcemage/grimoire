(
  sedit "s:/usr/local/canna:${INSTALL_ROOT}/usr:"             Canna.conf  &&
  sedit "s:/usr/spool/canna:${INSTALL_ROOT}/var/spool/canna:" Canna.conf  &&
  xmkmf            &&
  make Makefiles   &&
  make canna       &&
  prepare_install  &&
  make install     &&
  make install.man
) > $C_FIFO 2>&1
