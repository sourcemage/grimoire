sedit  "s:/usr/local/bin:$INSTALL_ROOT/usr/bin:"  Makefile  &&
# disable optimizations, makes it a lot slower, but optimizations create
# a broken decoder
sedit  "s:^CFLAGS.*:CFLAGS = -Wall:"              Makefile  &&
make
