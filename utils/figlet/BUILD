  sedit "s/CFLAGS = .*/CFLAGS = $CFLAGS/" Makefile
  sedit "s:DESTDIR = .*:DESTDIR = $INSTALL_ROOT/usr/games/:" Makefile
  sedit "s:MANDIR = .*:MANDIR = $INSTALL_ROOT/usr/share/man/man6/:" Makefile
  sedit "s:DEFAULTFONTDIR = .*:DEFAULTFONTDIR = $INSTALL_ROOT/usr/share/figlet/:" Makefile
  sedit "s/DEFAULTFONTDIR = fonts//" Makefile

  make                    &&

  chmod 755 figlist       &&
  chmod 755 showfigfonts
