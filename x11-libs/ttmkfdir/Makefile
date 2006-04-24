FREETYPE_INCL=/usr/include/freetype
FREETYPE_LIB=-L/usr/lib -lttf

CC=gcc
CFLAGS=-Wall -pedantic -I$(FREETYPE_INCL)
LDFLAGS=$(FREETYPE_LIB) -s
BINDIR=/usr/bin

ttmkfdir: ttmkfdir.o
	$(CC) -o $@ $< $(LDFLAGS)

ttmkfdir.o: ttmkfdir.c panose.h ttos2val.h

install:
	install -s ttmkfdir $(BINDIR)
