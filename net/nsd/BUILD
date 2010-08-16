create_account nsd &&

OPTS="--enable-bind8-stats \
      --enable-nsid \
      --with-ssl=$INSTALL_ROOT/usr \
      --with-pidfile=$INSTALL_ROOT/var/nsd/nsd.pid \
      --with-zonesdir=$INSTALL_ROOT/var/nsd/zones \
      --with-dbfile=$INSTALL_ROOT/var/db/nsd/nsd.db \
      --with-difffile=$INSTALL_ROOT/var/db/nsd/ixfr.db \
      --with-xfrdfile=$INSTALL_ROOT/var/nsd/xfrd.state \
      $OPTS" &&

default_build
