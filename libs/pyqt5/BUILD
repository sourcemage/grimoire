if [ $PYQT_BIG == y ];then
  VBIG=-c
fi &&
QMAKEPATH="$QT5DIR/bin"  &&
# in some cases, we set a symlink to python in the source directory
PATH="$QMAKEPATH:$SOURCE_DIRECTORY:$PATH" &&
$PYTHON  ./configure.py --confirm-license $VBIG
 &&
make
