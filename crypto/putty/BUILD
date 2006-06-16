cd unix  &&

sedit "s:/usr/local:/usr:" Makefile.gtk &&
sedit "s:(prefix)/man:(prefix)/share/man:" Makefile.gtk &&
sedit "s:-O2 -Wall -Werror -g:$CFLAGS:" Makefile.gtk &&

make -f Makefile.gtk
