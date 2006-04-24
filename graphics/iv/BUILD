(

  OLD_CFLAGS="-Wall -O6 -fomit-frame-pointer -funroll-loops"
  sedit  "s/$OLD_CFLAGS/$CFLAGS/"  iv/platforms.ini

  ./configure Linux --prefix=${INSTALL_ROOT}/usr &&
  sedit "s/MAKE = gmake/MAKE = make/" Makefile &&
  sedit "s/lgif/lungif/" iv/Makefile &&
  make all         &&
  prepare_install  &&
  make    install

) > $C_FIFO 2>&1
