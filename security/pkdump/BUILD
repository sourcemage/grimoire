(
  
  gcc $CFLAGS pkdump.c -o pkdump -lpthread	&&
  prepare_install				&&

  cp  -v  pkdump  /usr/sbin		&&
  mkdir  -p  /usr/share/pkdump		&&
  cp  -v  README.*  /usr/share/pkdump/
 
) >  $C_FIFO  2>&1  
