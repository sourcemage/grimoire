persistent_add QTDIR=/usr                                 &&
PATH=$QTDIR/bin/qt4:$PATH                                 &&
./configure --prefix=/usr $OPTS                           &&
sedit "s/QTDIR)\/include/QTDIR)\/include\/qt/g" Makefile  &&
make_single     &&
make            &&
make_normal
