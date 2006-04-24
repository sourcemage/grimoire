cp    Makefile  Makefile.original
echo  "CFLAGS = $CFLAGS"  >  Makefile
grep  -v  "^CFLAGS"  Makefile.original  >>  Makefile

make  x86info
