create_account nsd &&

OPTS="--with-ssl=$INSTALL_ROOT/usr \
      --with-pidfile=$INSTALL_ROOT/var/nsd/nsd.pid \
      --with-zonesdir=$INSTALL_ROOT/var/nsd/zones \
      --with-dbfile=$INSTALL_ROOT/var/db/nsd/nsd.db \
      --with-xfrdir=$INSTALL_ROOT/var/nsd/xfr \
      --with-xfrdfile=$INSTALL_ROOT/var/nsd/xfrd.state \
      $NSD_OPTS \
      $OPTS" &&

default_build
