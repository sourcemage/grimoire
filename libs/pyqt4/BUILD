if [ $PYQT_BIG == y ];then
  VBIG=-c
fi &&
export QTDIR=/usr          &&
PATH=$QTDIR/bin/qt4:$PATH  &&
$PYTHON  ./configure.py --confirm-license $VBIG  -j $MAKE_NJOBS &&
make
