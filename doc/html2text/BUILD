sedit "s!BINDIR    = /usr/local/bin!BINDIR = ${INSTALL_ROOT}/usr/bin!" \
      Makefile.in &&
sedit "s!MANDIR    = /usr/local/man!MANDIR = ${INSTALL_ROOT}/usr/share/man!" \
      Makefile.in &&
sedit "s!DOCDOR    = /usr/share/doc/$SPELL!DOCDIR = ${INSTALL_ROOT}/usr/share/doc/$SPELL!" \
      Makefile.in &&
sedit "s!DEBUG=-O2 -g!DEBUG=$CFLAGS!" Makefile.in &&

default_build
