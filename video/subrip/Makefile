#
# Makefile for subtitle2pgm + srttool
#

# use always:
DEFINES :=  
LIBS    := -lm 
INCLUDES :=

### enable ppm support ###
#DEFINES  += -D_HAVE_LIB_PPM_
#LIBS     += -lppm

### enable zlib support ###
DEFINES += -D_HAVE_ZLIB_
LIBS    += -lz

CC = gcc
WARN     = -Wall -Wstrict-prototypes 
COPT     = -g -O2  

CFLAGS = $(COPT) $(WARN) $(DEFINES) $(INCLUDES) 

# list of all files that are part of the package
PACKAGE_FILES = Makefile \
               subtitle2pgm.c subtitle2pgm.h spudec.c  spudec.h \
               srttool.c \
               vobsub.c vobsub.h subtitle2vobsub.c \
               pgm2txt \
               gocrfilter_en.sed gocrfilter_fr.sed gocrfilter_none.sed \
               gocrfilter_nl.sed \
               README  README.gocr  README.srttool \
               README.subtitle2pgm README.vobsub \
               ChangeLog

# Name of the package
PACKAGE = subrip

# version number
VERSION = `date +%Y%m%d`

# Main targets

TARGETS = subtitle2pgm srttool subtitle2vobsub

all:  $(TARGETS) 

# Generic Rules

%.o:%.c
	@echo Compiling $<
	@$(CC) -c $(CFLAGS) $<

# Dependencies
subtitle2pgm.o: subtitle2pgm.c spudec.h subtitle2pgm.h
spudec.o: spudec.c spudec.h

subtitle2vobsub.o: subtitle2vobsub.c vobsub.c vobsub.h  

# Target
subtitle2pgm: subtitle2pgm.o spudec.o
	@echo "Linking $@"
	@$(CC) $(LIBS) $^ -o $@  

subtitle2vobsub: subtitle2vobsub.o vobsub.o 
	@echo "Linking $@"
	@$(CC) $(LIBS) $^ -o $@  

srttool: srttool.o
	@echo "Linking $@"
	@$(CC) $(LIBS) -g $^ -o $@  

.PHONY: clean dist
clean:
	rm -f $(TARGETS) subtitle2pgm.o spudec.o srttool.o vobsub.o *~

dist:
	@mkdir $(PACKAGE)
	@cp $(PACKAGE_FILES) $(PACKAGE)
	@tar cvzf $(PACKAGE)-$(VERSION).tgz $(PACKAGE)
	@rm -rf $(PACKAGE)
	@mv $(PACKAGE)-$(VERSION).tgz ~/









