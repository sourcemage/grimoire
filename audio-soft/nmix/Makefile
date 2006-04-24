INSTALL = /usr/bin/install -c

# Installation directories
DESTDIR =
prefix = ${DESTDIR}/usr
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin

exec=nmix
source=mix.c

all: ${source}
	gcc ${CFLAGS} -o ${exec} -lncurses ${source} 

install:
	$(INSTALL) -d -m 755 $(bindir)
	$(INSTALL) -m 755 -o 0 -s ${exec} $(bindir)

