sedit  "s/read a/a=0/"  scripts/pppoe-setup.in
sedit  's:docdir=.*:docdir=@prefix@/share/doc/rp-pppoe:'  src/Makefile.in
cd  src
./configure  --build=$BUILD                        \
             --prefix=$INSTALL_ROOT/usr            \
             --sysconfdir=$INSTALL_ROOT/etc        \
             --localstatedir=$INSTALL_ROOT/var     \
             --mandir=$INSTALL_ROOT/usr/share/man  \
             $OPTS                 &&
make                               &&
cd  ../gui                         &&
make
