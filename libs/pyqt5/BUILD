cd $SOURCE_DIRECTORY &&
if [ $PYQT_BIG == y ];then
  VBIG=-c
fi &&
QMAKEPATH="$QT5DIR/bin"  &&
# Need to use the proper selected python.
PYTHON=$(get_spell_provider_file $SPELL PYTHON '/usr/bin/python[0-9\.]*$') &&
if [[ -z "$PYTHON" ]]; then
	message "${MESSAGE_COLOR}cannot determine python executable${DEFAULT_COLOR}" &&
	return 1
fi &&
$PYTHON  ./configure.py --confirm-license $VBIG  -j $MAKE_NJOBS --qmake=$QT5DIR/bin/qmake $OPTS&&
make
