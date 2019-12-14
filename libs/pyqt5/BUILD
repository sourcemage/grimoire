cd $SOURCE_DIRECTORY &&
if [ $PYQT_BIG == y ];then
  VBIG=-c
fi &&
QMAKEPATH="$QT5DIR/bin"  &&

python3 ./configure.py --confirm-license $VBIG  -j $MAKE_NJOBS --qmake=$QT5DIR/bin/qmake $OPTS &&
make
