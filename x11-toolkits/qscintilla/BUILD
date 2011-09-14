
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
 make
