ln -s makefile.gcc Makefile	    &&

sedit \
  "s|/usr/local|$INSTALL_ROOT/usr|;s|^MYCPPFLAGS=|MYCPPFLAGS=$CFLAGS|;s|^MYLDFLAGS=|MYLDFLAGS=$LDFLAGS|" \
  Makefile		                &&

make
