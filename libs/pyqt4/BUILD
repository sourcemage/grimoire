if [ $PYQT_BIG == y ];then
  VBIG=-c
fi                                               &&
export QTDIR=/usr                                &&
PATH=$QTDIR/bin/qt4:$PATH                        &&
#export QMAKESPEC=/usr/share/qt4/mkspecs/default/ &&
python  ./configure.py --confirm-license $VBIG   &&
make
