sedit "s/^UNIX_CFLAGS/# UNIX_CFLAGS/" Makefile    &&
sedit "s/^UNIX_LDFLAGS/# UNIX_LDFLAGS/" Makefile  &&

sedit "s/^CFLAGS=/CFLAGS=$CFLAGS/" Makefile     &&
sedit "s/^LDFLAGS=/LDFLAGS=$LDFLAGS/" Makefile  &&

make unix
