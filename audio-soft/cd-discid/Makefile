INSTALL = install
install_bin_flags =
install_bin = $(INSTALL) -m555 $(install_bin_flags)
install_doc = $(INSTALL) -m444
install_dir = $(INSTALL) -m755 -d

# Installation directories
DESTDIR =
prefix = /usr
exec_prefix = $(prefix)
mandir = $(prefix)/share/man/man1
bindir = $(exec_prefix)/bin
etcdir = /etc

exec = cd-discid
manpages = $(exec:=.1)

all: $(exec)
install: install-bin install-man

$(exec): $(exec).o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $@.o

install-bin: $(exec)
	$(install_dir) $(DESTDIR)$(bindir)
	$(install_bin) $(exec) $(DESTDIR)$(bindir)

install-man: $(manpages)
	$(install_dir) $(DESTDIR)$(mandir)
	$(install_doc) $(manpages) $(DESTDIR)$(mandir)

install-strip:
	$(MAKE) install_bin_flags=-s install


.PHONY: all install install-bin install-man install-strip
