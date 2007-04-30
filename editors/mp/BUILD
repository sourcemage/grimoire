sedit 's:./mkinstalldirs $(PREFIX)/share/doc/$(APPNAME):./mkinstalldirs $(PREFIX)/share/doc/mp:' makefile.in  &&
sedit 's:-install -m 644 $(DOCS) $(PREFIX)/share/doc/$(APPNAME):-install -m 644 $(DOCS) $(PREFIX)/share/doc/mp:'  \
makefile.in  &&
./config.sh --prefix=$INSTALL_ROOT/usr --docdir=$INSTALL_ROOT/usr/share/doc/$SPELL $OPTS &&
make
