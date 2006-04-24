(
  cd src

  ./configure  --prefix=/usr            \
               $OPTS                    &&
  make                                  &&
  prepare_install                       &&
  make    install

  cd ..
) > $C_FIFO 2>&1

