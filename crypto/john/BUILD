cd  src  &&

sedit  "s/-c -Wall -O2 -fomit-frame-pointer/-c -Wall $CFLAGS/"  Makefile
sedit  "s/ -m486//"  Makefile

if grep mmx /proc/cpuinfo > /dev/null
then
  make linux-x86-mmx
else
  make linux-x86-any
fi
