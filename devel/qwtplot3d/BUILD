if [[ $(get_spell_provider $SPELL QT) == qt4 ]]; then
  "$INSTALL_ROOT/usr/bin/qt4/qmake" qwtplot3d.pro
else
  "$INSTALL_ROOT/usr/bin/qmake" qwtplot3d.pro
fi &&
make
