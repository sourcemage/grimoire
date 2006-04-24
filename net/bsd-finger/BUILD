./configure --prefix=$INSTALL_ROOT/usr                                 \
                     $OPTS                                             &&

sedit                                                                  \
  "s@MANDIR=$INSTALL_ROOT/usr/man@MANDIR=$INSTALL_ROOT/usr/share/man@" \
  MCONFIG  &&

make
