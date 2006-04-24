./configure  --build=$BUILD                         \
             --prefix=$INSTALL_ROOT/usr             \
             --sysconfdir=$INSTALL_ROOT/etc         \
             --infodir=/usr/share/info              \
             --mandir=/usr/share/man                \
             --localstatedir=$INSTALL_ROOT/var      \
             --mandir=$INSTALL_ROOT/usr/share/man   \
             $OPTS                                  &&

make_single                                         &&
make                                                &&
make_normal
