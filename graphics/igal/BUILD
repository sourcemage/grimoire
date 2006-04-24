(

  sedit "s#DESTDIR=/usr/local#DESTDIR=/usr#" Makefile 	&&
  sedit "s#/usr/local/lib/igal#/usr/lib/igal#" igal	&&
  sedit "s#haveim = 0;#haveim = 1;#" igal		&&

  prepare_install                                	&&
  make    install

) > $C_FIFO 2>&1  
