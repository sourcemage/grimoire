sedit  "s:-g squid:-g root:" Makefile  &&
sedit  "s:-o squid:-o root:" Makefile  &&
sedit  "s:/usr/local/squirm:/usr:"  Makefile  &&
sedit  "s:/usr/etc:/etc/squirm:"  Makefile  &&
sedit  "s:/usr/log:/var/log/squirm:"  Makefile  &&
cd $SOURCE_DIRECTORY/regex &&
./configure                &&
make clean                 &&
make                       &&
cp -p regex.h regex.o ..   &&
cd ..                      &&
make
