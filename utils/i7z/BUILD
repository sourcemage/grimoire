make &&

if is_depends_enabled $SPELL qt4; then
  cd GUI &&
  QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"
  PATH="$QTDIR/bin/qt4:$PATH"
  qmake PREFIX=$INSTALL_ROOT/usr &&
  make clean &&
  make
fi
