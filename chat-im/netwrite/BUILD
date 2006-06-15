  mkdir -p $INSTALL_ROOT/usr/share/man/man8             &&
  patch  -p1  <  $SCRIPT_DIRECTORY/netwrite-0.17.patch  &&
  sedit "s:PREFIX/man:PREFIX/share/man:g"  configure    &&
  ./configure  --prefix=$INSTALL_ROOT/usr  \
  $OPTS                       &&
  make
