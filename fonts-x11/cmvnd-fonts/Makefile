sources != find -name \*.bdf -o -name \*.otb
fonts   := ${sources:.bdf=.pcf.gz}
all: ${fonts} config.mk

.bdf.pcf.gz:
	bdftopcf $< | gzip -9 > $@.tmp
	mv $@.tmp $@

install:
	install -d ${fontsdir}
	install -m444 ${fonts} ${fontsdir}

.PHONY: all install
.SUFFIXES: .pcf.gz .bdf
prefix = /usr/local
datarootdir = ${prefix}/share
fontsdir = ${datarootdir}/fonts/misc
-include config.mk
config.mk:
	@>>$@ echo fontsdir = ${fontsdir}
