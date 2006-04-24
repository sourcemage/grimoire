 cd qt                                  &&
 qmake qscintilla.pro                   &&

# fix the generated Makefile, so that libqscintilla gets installed at the correct time
#
 patch -p0 < $SPELL_DIRECTORY/mk.diff   &&
 make

