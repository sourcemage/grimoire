prefix = /usr
bindir = $(prefix)/bin

VPATH = $(CURDIR)/v0100

CC = gcc
override CFLAGS += -DHOST_LINUX

targets = smlrc smlrl smlrcc

all: $(targets)

install: all
	install -m755 -t $(bindir) $(targets)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: all install
