(

  make                                        &&
  prepare_install                             &&
  make  LINUX_INCLUDE_DIR=/usr/include/linux  \
        install                               &&
  cp kernel/*.h /usr/include/linux/

) > $C_FIFO 2>&1
