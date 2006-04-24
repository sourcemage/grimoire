(

  make                                        &&
  prepare_install                             &&

  # Install binaries...
  install  -m  755  bin/*  /usr/X11R6/bin     &&

  # Install static libraries...
  install  -m  755  lib/*  /usr/lib           &&

  # Install documentation...
  D_DIR="/usr/share/doc/${SPELL}/${VERSION}"  &&
  install  -d  -m  755  ${D_DIR}              &&
  cd  ${D_DIR}                                &&
  unpack  ${SOURCE5}  ${MD5[4]}

)  >  $C_FIFO  2>&1
