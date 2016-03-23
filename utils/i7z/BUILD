make &&

if is_depends_enabled $SPELL qt4; then
  cd GUI &&
  QTDIR="${QTDIR:-$INSTALL_ROOT/opt/qt4}"
  PATH="$QTDIR/bin:$PATH"
  qmake PREFIX=$INSTALL_ROOT/usr &&
  make clean &&
  make
fi
