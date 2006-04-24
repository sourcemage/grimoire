(
  sedit  "s/-g/$CFLAGS/"           Makefile                &&
  sedit  "s/-Wall/-Wall $CFLAGS/"  scintilla/gtk/makefile  &&
  make                                                     &&
  prepare_install                                          &&
  make    install

) > $C_FIFO 2>&1

