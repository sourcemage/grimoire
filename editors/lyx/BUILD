CFLAGS=${CFLAGS/-O3/-O2}     &&
CXXFLAGS=${CXXFLAGS/-O3/-O2} &&
if is_depends_enabled "$SPELL" qtbase; then
  OPTS="$OPTS --enable-qt5 --with-qt-dir=$QT5DIR"
else
  OPTS="$OPTS --with-qt-dir=$QT4DIR"
fi &&
PATH="$QTDIR/bin:$PATH" &&
default_build
