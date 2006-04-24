(
  ./configure  --prefix=/usr    \
	       --sysconfdir=/etc/raccess \	
               $OPTS            &&
  make                          &&
  prepare_install		&&
  make install  

) > $C_FIFO 2>&1  
