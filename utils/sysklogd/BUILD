patch  -p1  <  $SCRIPT_DIRECTORY/sysklogd-1.4.1-kernel_header.patch         &&
sedit  "s:BINDIR = /usr/sbin:BINDIR=$INSTALL_ROOT/sbin:"          Makefile  &&
sedit  "s:MANDIR = /usr/man:MANDIR=$INSTALL_ROOT/usr/share/man:"  Makefile  &&
make
