if [ $PYQT_BIG == y ];then
  VBIG=-c
fi                                               &&
persistent_add QTDIR=/usr                        &&
PATH=$QTDIR/bin/qt4:$PATH                        &&
#persistent_add QMAKESPEC=/usr/share/qt4/mkspecs/default/ &&
/bin/echo "yes" | python  ./configure.py $VBIG   &&
make
