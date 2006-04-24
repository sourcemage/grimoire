(
  ./configure  --prefix=/usr				\
               --with-qtdir=/usr			\
               --with-qt-includes=/usr/include/qt	\
               $OPTS                 			&&
  make                               			&&
  prepare_install					&&
  make install

) > $C_FIFO 2>&1