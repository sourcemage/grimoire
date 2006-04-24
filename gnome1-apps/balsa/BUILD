(

  ./configure  --prefix=/usr            \
               --disable-more-warnings  \
               --enable-gtkhtml         \
	       $OPTS			&&
  make                                  &&
  prepare_install                       &&
  make    install

) > $C_FIFO 2>&1
