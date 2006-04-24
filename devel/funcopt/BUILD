(

  sedit  "s:\= pentium4:\= ${ARCHITECTURE}:"  Makefile  &&
  sedit  "s:-O3:${CXXFLAGS}:"                 Makefile  &&

  make  clean                          &&
  make                                 &&
  make  docs                           &&
  prepare_install                      &&
  cp  ecopt  /usr/bin                  &&
  mkdir  -p  /usr/share/docs/${SPELL}  &&
  cp docs/*  /usr/share/docs/${SPELL}

)  >  ${C_FIFO}  2>&1
