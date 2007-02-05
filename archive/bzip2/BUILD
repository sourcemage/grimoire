sedit  "s/-O2/-fPIC ${CFLAGS}/;s|)/man|)/share/man|;/^LDFLAGS/d"  Makefile  &&
sedit  's/\$(PREFIX)\/bin/\$(EPREFIX)\/bin/g'                     Makefile  &&
sedit  "s/-O2/${CFLAGS}/;s|)/man|)/share/man|;/^LDFLAGS/d"            \
       Makefile-libbz2_so                                                   &&
if [[ "$BZIP2_ROOT" == "y" ]]; then 
  make "PREFIX=$INSTALL_ROOT/usr" "EPREFIX=$INSTALL_ROOT"
else
  make "PREFIX=$INSTALL_ROOT/usr" "EPREFIX=$INSTALL_ROOT/usr"
fi &&
make  -f  Makefile-libbz2_so
