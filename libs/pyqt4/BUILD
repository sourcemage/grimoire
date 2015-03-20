if [ $PYQT_BIG == y ];then
  VBIG=-c
fi &&
export QTDIR=/usr          &&
PATH=$QTDIR/bin/qt4:$PATH  &&
# Need to use the proper selected python.
PYTHON=$(get_spell_provider_file $SPELL PYTHON '/usr/bin/python[0-9\.]*$')
$PYTHON  ./configure-ng.py --confirm-license $VBIG  -j $MAKE_NJOBS &&
make
