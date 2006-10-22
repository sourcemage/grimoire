cp  unix/Makefile  .  &&
sedit  "s/CFLAGS = -O2/CFLAGS := \$(CFLAGS)/" Makefile &&
sedit  "s:/usr/local:/usr:"    Makefile  &&
sedit  "s:/man/:/share/man/:"  Makefile  &&

make  generic
