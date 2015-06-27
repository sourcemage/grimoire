
QTDIR=/usr                              &&
local QTSCINT                           &&
if is_depends_enabled $SPELL qt4 ; then
  PATH=$QTDIR/bin/qt4:$PATH
  QTSCINT=Qt4Qt5
else
  QTSCINT=Qt3
fi &&
 cd $SOURCE_DIRECTORY/$QTSCINT          &&
 PATH=$INSTALL_ROOT/opt/qt4/bin:$PATH qmake qscintilla.pro &&
 make
