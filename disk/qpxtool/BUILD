QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"
PATH="$QTDIR/bin/qt4:$PATH"
make cli  &&
if is_depends_enabled $SPELL qt4
then
  make gui
fi
