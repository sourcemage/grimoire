(

  ./configure  --prefix=/usr         \
               --with-guess-winsize  \
	       $OPTS		     &&
  make                               &&
  prepare_install                    &&
  make    install 

) > $C_FIFO 2>&1
