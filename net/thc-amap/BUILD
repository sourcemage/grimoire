./configure                                &&
sedit "s:/usr/local:/:" Makefile           &&
sedit "s:/bin:usr/bin:" Makefile           &&
sedit "s:/etc:etc/amap:" Makefile          &&
sedit "s:/man/man1:usr/man/man1:" Makefile &&
sedit "s:/usr/local:/usr:" amap.h          &&
sedit "s:AMAP_PREFIX:\"/\":" amap-lib.c    &&
sedit "s:etc/:etc/amap/:" amap-lib.c       &&
make
