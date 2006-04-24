(
 
  patch  -p1  <  $SCRIPT_DIRECTORY/portsentry-1.1-conf.patch &&
  patch       <  $SCRIPT_DIRECTORY/portsentry.c.patch &&

  PS_CONF='#define  CONFIG_FILE "/etc/portsentry.conf"' &&

  cp    portsentry_config.h  portsentry_config.h.original &&
  grep  -v  "CONFIG_FILE"    portsentry_config.h.original  \
                          >  portsentry_config.h &&
  echo  $PS_CONF         >>  portsentry_config.h &&

  cp    Makefile  Makefile.orig &&
  sed   "s/CFLAGS = -O -Wall/CFLAGS := -O -Wall \$\(CFLAGS\)/"  \
        Makefile.orig  >  Makefile  &&

  make  linux                       &&
  prepare_install                   &&
  cp  portsentry   /usr/sbin        &&
  mkdir  -p        /etc/portsentry  &&
  mkdir  -p        /var/portsentry  &&

  if  !  [  -f  /etc/portsentry.conf    ];  then
    sedit  "s:/usr/local/psionic:/etc:"  portsentry.conf &&
    cp  portsentry.conf  /etc/
  fi  &&

  if  !  [  -f             /etc/portsentry/portsentry.ignore  ];  then
    cp  portsentry.ignore  /etc/portsentry/portsentry.ignore
  fi &&

  if  !  [  -f             /etc/portsentry/portsentry.modes  ];  then
    cp  $SCRIPT_DIRECTORY/portsentry.modes  /etc/portsentry/portsentry.modes
  fi

) > $C_FIFO 2>&1
