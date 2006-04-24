sedit  's:/usr/local/share/aclocal:/usr/share/aclocal:'  configure  &&
sedit  's!$(srcdir)/Makefile.in:  Makefile.am .*!$(srcdir)/Makefile.in:!'  Makefile.in  &&
sedit  's!$(srcdir)/configure:  $(srcdir).*!$(srcdir)/configure:!'  Makefile.in &&
sedit  's!$(srcdir)/config.h.in:  $(top_srcdir).*!$(srcdir)/config.h.in:!'  Makefile.in  &&
default_build
