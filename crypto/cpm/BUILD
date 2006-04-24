sedit 's:libxml:libxml2/libxml:' interface_xml.h &&
sedit 's:libxml:libxml2/libxml:' xml.h           &&
sedit 's:mandir=.*:mandir=@mandir@:' Makefile.in &&

OPTS="$OPTS --with-crack-dict=/usr/lib/cracklib/pw_dict --mandir=/usr/share/man" &&

default_build
