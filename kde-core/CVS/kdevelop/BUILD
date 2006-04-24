(

  make -f admin/Makefile.common cvs-clean  
  make -f Makefile.cvs                     

  ./configure  --prefix=/usr        \
               --sysconfdir=/etc    \
               --localstatedir=/var \
               --enable-debug       \
	           $OPTS                &&
  make  -Wno-deprecated             &&
  prepare_install                   &&
  make    install

) > $C_FIFO 2>&1
