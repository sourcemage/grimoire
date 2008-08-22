  QTDIR=/usr    &&
  PATH=$QTDIR/bin/qt4:$PATH
  export QTDIR=/usr                                         &&
  ./configure --prefix=/usr $OPTS                           &&
  sedit "s/QTDIR)\/include/QTDIR)\/include\/qt/g" Makefile  &&
  make_single     &&
  make            &&
  make_normal
