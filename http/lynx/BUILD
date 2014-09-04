mkdir  -p  /var/lib/lynx &&

OPTS="$LYNX_OPTS $OPTS" &&

./configure   --host=$BUILD                         \
              --prefix=$INSTALL_ROOT/usr            \
              --libdir=$INSTALL_ROOT/var/lib/lynx   \
              --sysconfdir=$INSTALL_ROOT/etc        \
              --mandir=$INSTALL_ROOT/usr/share/man  \
              $OPTS  &&
make
