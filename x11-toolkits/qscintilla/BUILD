
QTDIR=/usr                              &&
local QTSCINT                           &&
if is_depends_enabled $SPELL qt4 ; then
  PATH=$QTDIR/bin/qt4:$PATH
  QTSCINT=Qt4
else
  QTSCINT=Qt3
fi &&
 cd $SOURCE_DIRECTORY/$QTSCINT          &&
 qmake qscintilla.pro                   &&
 make  					# &&

# todo: the following the c++ bindings to be installed,
#       better put it into another spell:
# if is_depends_enabled $SPELL python ; then
#   cd $SOURCE_DIRECTORY/Python		&&
#   python configure.py			&&
#   make
# fi
