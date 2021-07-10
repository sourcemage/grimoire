create_account masqmail &&
create_account mail &&

OPTS="--with-user=masqmail \
      --with-group=masqmail \
      --with-spooldir=$INSTALL_ROOT/var/spool/masqmail \
      $MASQMAIL_OPTS \
      $OPTS" &&

default_build
