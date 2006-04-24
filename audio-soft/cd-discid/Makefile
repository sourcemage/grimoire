INSTALL = /usr/bin/install -c

# Installation directories
DESTDIR =
prefix = ${DESTDIR}/usr
exec_prefix = ${prefix}
mandir = ${prefix}/share/man/man1
bindir = ${exec_prefix}/bin
etcdir = ${DESTDIR}/etc

exec=cd-discid
source=${exec}.c
man=${exec}.1

all: ${source}
	gcc ${CFLAGS} -o ${exec} ${source} 

install:
	$(INSTALL) -d -m 755 $(bindir)
	$(INSTALL) -m 755 -o 0 -s ${exec} $(bindir)
	$(INSTALL) -d -m 755 $(mandir)
	$(INSTALL) -m 644 -o 0 ${man} $(mandir)

