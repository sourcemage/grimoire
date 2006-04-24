(
  sedit  "s/NET = true/# NET = true/"                Makefile
  sedit  "s/UNKNOWN_CD = true/# UNKNOWN_CD = true/"  Makefile
  sedit  "s/\/dev\/cdroms\/cdrom0/\/devices\/cdroms\/cdrom0/" Makefile

  make  PREFIX=/usr  &&
  prepare_install    &&
  make  PREFIX=/usr install

) > $C_FIFO 2>&1
