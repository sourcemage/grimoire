cp  unix/Makefile  .  &&
sedit  "s/CFLAGS = -O2/CFLAGS := \$(CFLAGS)/" Makefile &&
sedit  "s:/usr/local:/usr:"    Makefile  &&
sedit  "s:/man/:/share/man/:"  Makefile  &&

#fix bug in Makefile
sedit 's:$(INSTALL):$(INSTALL_PROGRAM):' Makefile &&
make  generic
