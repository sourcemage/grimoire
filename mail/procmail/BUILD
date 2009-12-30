patch -p1 < $SPELL_DIRECTORY/procmail-3.22-glibc-2.10.patch &&
sedit  "s:LOCKINGTEST=__defaults__:LOCKINGTEST=/tmp:"  Makefile
sedit  's:$(BASENAME)/man:$(BASENAME)/share/man:'      Makefile
make  init  &&
make
