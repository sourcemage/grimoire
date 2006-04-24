SHELL = /bin/sh

prefix = ${INSTALL_ROOT}/usr
exec_prefix = ${prefix}
srcdir = .


EXE = 

all:
	cd goo; $(MAKE)
	cd xpdf; $(MAKE) 
	cd src; $(MAKE)
	cd src; mv pdftohtml ../pdftohtml

clean:
	rm -f pdftohtml
	cd goo; $(MAKE) clean
	cd xpdf; $(MAKE) clean
	cd src; $(MAKE) clean

distdepend:
	rm -f pdftohtml
	cd goo; $(MAKE) distdepend
	cd xpdf; $(MAKE) distdepend
