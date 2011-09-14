
QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"
 PATH="$QTDIR/bin/qt4:$PATH"

OPTS="$RECOLL_OPTS $OPTS"
default_build &&

if test "$RECOLLQ" = "y"
then
  make -C query
fi
