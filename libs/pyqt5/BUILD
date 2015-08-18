cd $SOURCE_DIRECTORY &&
if [ $PYQT_BIG == y ];then
  VBIG=-c
fi &&
QMAKEPATH="$QT5DIR/bin"  &&
# Need to use the proper selected python.
PYTHON=$(get_spell_provider_file $SPELL PYTHON '/usr/bin/python[0-9\.]*$') &&
$PYTHON  ./configure.py --confirm-license $VBIG  -j $MAKE_NJOBS --qmake=$QT5DIR/bin/qmake $OPTS&&
make
