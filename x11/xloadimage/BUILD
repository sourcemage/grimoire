#gcc3.3 needs this
for i in $(grep -rl varargs.h .)
	do sedit "s/varargs.h/stdarg.h/g" $i
done                                                            &&
#glibc stopped exporting this from libc
sedit '16i#include <errno.h>' img.c                             &&

cd jpeg 							&&
mv Makefile Makefile.orig 					&&
ln -s makefile.ansi Makefile 					&&
cd .. 								&&
xmkmf 								&&
cd jpeg 							&&
make libjpeg.a 							&&
cd .. 								&&
make
