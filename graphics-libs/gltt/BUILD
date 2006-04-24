(

  patch  -p1  <  $SCRIPT_DIRECTORY/gcc3.patch             &&
  ./configure  --prefix=/usr                              \
               --with-ttf-includes=/usr/include/freetype  \
               --with-ttf-libraries=/usr/lib              \
               $OPTS                                      &&
  make                                                    &&
  make  install

) > $C_FIFO 2>&1
