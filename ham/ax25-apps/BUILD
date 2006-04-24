(

  ./configure  --prefix=/usr         \
               --sysconfdir=/etc     \
               --localstatedir=/var  \
               $OPTS                 &&
  make                               &&
  prepare_install                    &&
  make    install-strip              &&

if    query  "Do you want the example config files?"  n
  then  make installconf
fi

) > $C_FIFO 2>&1


