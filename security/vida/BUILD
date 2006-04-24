(

  patch -p1 < $SCRIPT_DIRECTORY/DNSPatch-1.1.2 &&

  sedit  "s:CFLAGS = -Wall -O2:CFLAGS = $CFLAGS:"  Makefile	&&  
  make								&&

  prepare_install						&&

  make  install				&&
  mkdir  -p  /usr/share/vida		&&
  cp  -v  README  /usr/share/vida/

) >  $C_FIFO  2>&1  
