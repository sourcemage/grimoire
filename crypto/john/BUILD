cd  src  &&

sedit  "s/-c -Wall -O2 -fomit-frame-pointer/-c -Wall $CFLAGS/"  Makefile &&
sedit  "s/ -m486//"  Makefile &&

make_single &&
make clean ${JOHN_CPU}
