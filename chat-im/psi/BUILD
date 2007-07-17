  if [ "$DEVEL" == "y" ]; then
     QTDIR=/usr    &&
     PATH=$QTDIR/bin/qt4:$PATH
  else
   if [ -d /usr/lib/kde3 ];then
     export KDEDIR=/usr/lib/kde3
   fi   
  fi                                                        &&
  export QTDIR=/usr                                         &&
  ./configure --prefix=/usr $OPTS                           &&
  sedit "s/QTDIR)\/include/QTDIR)\/include\/qt/g" Makefile  &&
  make_single     &&
  make            &&
  make_normal
