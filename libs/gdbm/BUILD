sedit  "s/-O/$CFLAGS/"  Makefile.in

# Looks like gdbm uses INSTALL_ROOT in its scripts, so we end up 
# with a concatenation of INSTALL_ROOT, not very nice...
./configure  --prefix=/usr              \
             --infodir=/usr/share/info  \
             --mandir=/usr/share/man    \
             $OPTS                &&
make
