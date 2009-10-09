CFLAGS+=-fPIC -I$(shell pwd)/include
LDFLAGS=-lpng -lGL
SHAREDLIBFLAGS=-shared
DESTDIR=$(INSTALL_ROOT)/usr/
DOCDIR=$(DESTDIR)/share/doc/libglpng

all: libglpng.a libglpng.so.1.45

libglpng.a: glpng.o
	ar rv $@ $<

libglpng.so.1.45: glpng.o
	gcc $(CFLAGS) $(SHAREDLIBFLAGS) -Wl,-soname=libglpng.so.1 -Wl,--whole-archive $< -Wl,--no-whole-archive $(LDFLAGS) -o $@

glpng.o: src/glpng.c
	gcc $(CFLAGS) -c $<

clean:
	rm glpng.o libglpng.*

install: libglpng.a libglpng.so.1.45
	for i in include include/GL lib; do \
		install -m 755 -d $(DESTDIR)/$$i; \
	done
	for i in $(DOCDIR) $(DOCDIR)/examples; do \
		install -m 755 -d $$i; \
	done
	install -m 644 glpng.htm $(DOCDIR)/glpng.html
	install -m 644 Example/Stunt.png Example/Test.c $(DOCDIR)/examples
	install -m 644 include/GL/glpng.h $(DESTDIR)/include/GL
	install -m 644 libglpng.* $(DESTDIR)/lib
	ln -s libglpng.so.1.45 $(DESTDIR)/lib/libglpng.so.1
	ln -s libglpng.so.1.45 $(DESTDIR)/lib/libglpng.so

.PHONY: clean install
