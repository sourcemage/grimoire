# this is a special build proc for qtwebengine, with additional parameters
qt5_build() {
# qmake uses its own flag settings
  qmake QMAKE_CONFIG="$OPTS" QMAKE_CFLAGS="$CFLAGS" QMAKE_CXXFLAGS="$CXXFLAGS"\
    PREFIX=${1-$QT5DIR} LIBDIR=$QT5DIR/lib *.pro &&
#    -- -system-ffmpeg -webengine-icu &&
  make
}

OPTS+=" -shared"  &&
if list_find "$CXXFLAGS" -Os; then
  OPTS+=" -optimize-size"
fi &&

qt5_build
