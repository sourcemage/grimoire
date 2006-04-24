sedit  's:$(prefix)/doc/GtkAda/:$(prefix)/share/doc/gtkada/:'  \
  docs/gtkada_rm/Makefile.in  &&
sedit  's:$(prefix)/doc/GtkAda/:$(prefix)/share/doc/gtkada/:'  \
  docs/gtkada_ug/Makefile.in  &&
# unset CFLAGS because gnat-bin is based on gcc 2.8.1 which doesn't know
# most modern flags we use
unset CFLAGS  &&
OPTS="$OPTS --with-GL-prefix=${INSTALL_ROOT}/usr/X11R6"  &&
default_build
