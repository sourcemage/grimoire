(
  sedit "s/\$(MAKEFLAGS)//" Makefile.in	&&
  ./configure 	--prefix=/usr \
		--with-httpddir=/usr/doc/hypermail/docs \
		--sysconfdir=/etc $OPTS &&

  make                          &&

  prepare_install               &&

  make install			

) > $C_FIFO 2>&1

