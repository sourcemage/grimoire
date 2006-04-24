(
  # make gather_docs pick this file up
  cp  tpsetup/transproxy  transproxyrc                        &&

  make CFLAGS="$CFLAGS -D_REENTRANT" LDFLAGS="$LDFLAGS"       &&
  make -C tpserv CC="cc" CFLAGS="$CFLAGS" LIBS="$LDFLAGS"     &&

  prepare_install                                             &&

  install  -m 755  hunt tpserv/tpserv /usr/bin/               &&
  install  -m 644  man/hunt.1 /usr/man/man1/hunt.1

) > $C_FIFO 2>&1

