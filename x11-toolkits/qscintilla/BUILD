QTDIR=/usr                              &&
local QTSCINT                           &&
if is_depends_enabled $SPELL qt4;then
  PATH=$QTDIR/bin/qt4:$PATH
  QTSCINT=Qt4
else
  QTSCINT=Qt3
fi &&
 cd $SOURCE_DIRECTORY/$QTSCINT          &&
 qmake qscintilla.pro                   &&
# fix the generated Makefile, so that libqscintilla gets installed at the correct time
 patch -p0 < $SPELL_DIRECTORY/mk.diff.${QTSCINT/Q/q}   &&
 make

