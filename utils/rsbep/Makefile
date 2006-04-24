CC=gcc
CFLAGS=-O3 -fomit-frame-pointer

all: rsbep dvr

rsbep: rsbep.o rs32asm.o rs32.o Makefile
	$(CC) $(CFLAGS) -o rsbep rsbep.o rs32.o rs32asm.o

rs32asm.o: rs32asm.s Makefile
	as rs32asm.s -o rs32asm.o

rs32.o: rs32.c rs32.h Makefile
	$(CC) $(CFLAGS) -o rs32.o -c rs32.c

rsbep.o: rsbep.c rs32.h Makefile
	$(CC) $(CFLAGS) -DASM_I386 -c rsbep.c

dvr: dvr.c
	$(CC) $(CFLAGS) -o dvr dvr.c

clean:
	rm *.o -f
	rm rsbep -f

install:
	install rsbep           /usr/bin
	strip                   /usr/bin/rsbep
	install tar2dv.sh       /usr/bin
	install dv2ver.sh 	/usr/bin
	install dv2tar.sh       /usr/bin
	install dvr             /usr/bin
	strip           	/usr/bin/dvr
