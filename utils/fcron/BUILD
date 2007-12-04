create_account fcron

local editor
editor=`which ${EDITOR%% *} 2> /dev/null` ||
editor=`which nano`

OPTS="--with-answer-all=no \
      --with-editor=$editor \
      --localstatedir=$INSTALL_ROOT/var \
      --with-piddir=$INSTALL_ROOT/var/run \
      --with-fifodir=$INSTALL_ROOT/var/run \
      --with-spooldir=$INSTALL_ROOT/var/spool/fcron \
      $OPTS"  &&
default_build
