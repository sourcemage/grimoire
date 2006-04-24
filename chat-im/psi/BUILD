  if [ -d /usr/lib/kde3 ];then
    export KDEDIR=/usr/lib/kde3
  fi                                                        &&
  export QTDIR=/usr                                         &&
  ./configure --prefix=/usr $OPTS                           &&
  sedit "s/QTDIR)\/include/QTDIR)\/include\/qt/g" Makefile  &&
  make
