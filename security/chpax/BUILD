(

  make                                                      &&
  prepare_install                                           &&
  cp chpax /usr/sbin                                        &&
  chmod 754 /usr/sbin/chpax                                 &&
  tr -d '\r' < $SOURCE_CACHE/chpax.sh > /usr/sbin/chpax.sh  &&
  chmod 754 /usr/sbin/chpax.sh                              &&
  {
    [ -e /etc/chpax.cfg ] ||
    cp $SOURCE_CACHE/chpax.cfg /etc
  }                                                         &&
  touch /etc/chpax.cfg


) > $C_FIFO 2>&1
