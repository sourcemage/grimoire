  ./configure  --prefix=$INSTALL_ROOT/usr         \
               --sysconfdir=$INSTALL_ROOT/etc     \
               --localstatedir=$INSTALL_ROOT/var  \
               --enable-compat                    \
               --disable-debug                    \
	       $OPTS                     &&
make_single    &&
make           &&
make_normal
