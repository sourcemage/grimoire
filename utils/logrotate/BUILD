sed  -i  "s@\$(RPM_OPT_FLAGS)@$CFLAGS@"                   Makefile     &&
sed  -i  "s@BASEDIR = /usr@BASEDIR = $INSTALL_ROOT/usr@"  Makefile     &&
sed  -i  "s@MANDIR = \$(BASEDIR)/man@MANDIR = \$(BASEDIR)/share/man@"  \
         Makefile                                                      &&

make
