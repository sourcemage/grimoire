create_account ratbox &&

OPTS="--sysconfdir=$INSTALL_ROOT/etc/ircd-ratbox \
     --with-rundir=$INSTALL_ROOT/var/run/rserv \
     --with-logdir=$INSTALL_ROOT/var/log/ircd-ratbox \
    --with-nicklen=$RSERV_NICKLEN \
   --with-topiclen=$RSERV_TOPICLEN \
 --with-userreglen=$RSERV_USERREGLEN \
                   $RSERV_OPTS \
                   $OPTS" &&

make_single &&
default_build &&
make_normal
