if is_depends_enabled $SPELL qt4; then
  export QTDIR="$QT4DIR"
else
  export QTDIR="$QT5DIR"
fi &&
export  PATH="$QTDIR/bin:$PATH" &&
export QMAKE="$QTDIR/bin/qmake" &&
default_build
