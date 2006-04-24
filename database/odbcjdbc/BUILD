if [ "$WHICH" == "stable" ]; then
  patch -p1 < ${SPELL_DIRECTORY}/gcc.diff
fi                                                              &&
if [ "$WHICH" == "devel" ]; then
  cd OdbcJdbc 
fi                                                              &&
  sedit "s|d:/Firebird|/usr/firebird|" Builds/makefile.environ	&&
  cd Builds/Gcc.lin						&&
# can't use patch because file in msdos format
  sed -i "s|-g |-DPIC -fPIC $CFLAGS |;s|/opt|/usr|;s|/odbc||;s|-sh|$LDFLAGS -sh|" \
       makefile.linux                                           &&

  make -f makefile.linux
