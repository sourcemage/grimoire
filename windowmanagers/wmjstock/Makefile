prefix=/usr/bin
CC     = gcc
CFLAGS = #-O2 -g #-Wall # I think this option is idiotic
INCDIR = -I/usr/X11R6/include/X11 -I/usr/X11R6/include -I/usr/i386-glibc20-linux/include
DESTDIR= /usr/X11R6
LIBDIR = -L/usr/X11R6/lib
# for linux
LIBS   = -lXpm -lX11 -lXext

OBJS   = jDockApp.o xutils.o jprintf.o

name=wmjstock
version=1.0

all:	${name}

jDockApp.o: jDockApp/jDockApp_main.xpm jDockApp/jDockApp.c
	cd $*; make $*.o

xutils.o: xutils/xutils.c
	cd $*; make $*.o

jprintf.o: jDockApp/jprintf.c
	cd jDockApp; make jprintf.o


${name}: $(OBJS) ${name}.c
	$(CC) $(CFLAGS) $(SYSTEM) -o ${name} $^ $(INCDIR) $(LIBDIR) $(LIBS)

install: all
	install -s -m 755 ./${name}  ${prefix}/${name}
	install -m 755 ./stockchk ${prefix}/stockchk

clean:
	rm -f *.o ${name}
