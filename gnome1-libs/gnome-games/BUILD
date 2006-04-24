(

  export  CFLAGS="$CFLAGS  -I/usr/include/gdk-pixbuf-1.0"

  ./configure  --prefix=${INSTALL_ROOT}/usr        \
               --bindir=${INSTALL_ROOT}/usr/games  \
               --sysconfdir=${INSTALL_ROOT}/etc    &&
  make                                             &&
  prepare_install                                  &&
  make    install

) > $C_FIFO 2>&1
