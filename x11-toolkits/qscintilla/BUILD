QTDIR=/usr                              &&
if [ "$QTSCINT" = Qt4 ]; then
  PATH=$QTDIR/bin/qt4:$PATH
fi &&
 cd $SOURCE_DIRECTORY/$QTSCINT          &&
 qmake qscintilla.pro                   &&
# fix the generated Makefile, so that libqscintilla gets installed at the correct time
 patch -p0 < $SPELL_DIRECTORY/mk.diff.${QTSCINT/Q/q}   &&
 make

