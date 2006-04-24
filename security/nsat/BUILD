(
  sedit  "s/\/usr\/local\/bin/\/usr\/bin/"  Makefile.in  &&
  sedit  "s/\/usr\/local\/man/\/usr\/man/"  Makefile.in  &&
  sedit  "s/\/usr\/local\/share\/nsat/\/usr\/share\/nsat/"  Makefile.in  &&
  sedit  "s/\/usr\/local\/share\/nsat/\/usr\/share\/nsat/"  src/lang.h  &&
  ./configure  --prefix=/usr    \
               $OPTS            &&
  make                          &&
  prepare_install		&&
  make install  

) > $C_FIFO 2>&1  
