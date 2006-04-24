prefix=/usr/bin
CC     = gcc
CFLAGS = #-O2 -g #-Wall # I think this option is idiotic
INCDIR = -I/usr/X11R6/include/X11 -I/usr/X11R6/include -I/usr/i386-glibc20-linux/include
DESTDIR= /usr/X11R6
LIBDIR = -L/usr/X11R6/lib
# for linux
LIBS   = -lXpm -lX11 -lXext
OBJS   = jDockApp.o xutils.o jprintf.o

name=wmjmail
version=1.6

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
	install -m 755 ./mailchk ${prefix}/mailchk

clean:
	rm -f *.o ${name} ${name}.c *.orig *.rej *.3

.SUFFIXES: .c .jet

.jet.c:
	cp -v $< $@
	patch < Andre.Merzky.patch
	patch < Andre.Merzky.audio.patch
	patch < Jet.post-andre.patch
	patch < Jet.stat.patch
