sedit  "s:CFLAGS=-O2 -Wall:CFLAGS=$CFLAGS:"  Makefile      &&
sedit  's:/usr/local/:/usr/:'                Makefile      &&
sedit  "s:CFLAGS=-O2 -Wall:CFLAGS=$CFLAGS:"  src/Makefile  &&
sedit  's:/usr/local/:/usr/:'                src/Makefile  &&
make_single                                                &&
make                                                       &&
make_normal
