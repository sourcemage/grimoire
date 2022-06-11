OPTS+=" CONFIG+=no-update CONFIG+=no-embed-qt-translations CONFIG+=no-g15"

if [[ "$MUMBLE_SERVER" == 'n' ]]; then
    OPTS="$OPTS CONFIG+=no-server"
fi

if [[ "$MUMBLE_CLIENT" == 'n' ]]; then
    OPTS="$OPTS CONFIG+=no-client"
fi

if [[ "$MUMBLE_OVERLAY" == 'n' ]]; then
    OPTS="$OPTS CONFIG+=no-overlay"
fi

PATH=/opt/qt5/bin:$PATH &&

echo qmake -recursive main.pro $OPTS QMAKE_CFLAGS="$CFLAGS" QMAKE_CXXFLAGS="$CXXFLAGS" &&
qmake -recursive main.pro \
  $OPTS \
  QMAKE_CFLAGS="$CFLAGS" \
  QMAKE_CXXFLAGS="$CXXFLAGS" \
  QMAKE_CXXFLAGS+=-DCELT_SET_VBR_RATE=CELT_SET_BITRATE &&
make

#PATH=/opt/qt5/bin:$PATH &&
#qmake main.pro $OPTS \
#      QMAKE_CFLAGS="$CFLAGS" \
#      QMAKE_CXXFLAGS="$CXXFLAGS" \
#      QMAKE_CXXFLAGS+=-DCELT_SET_VBR_RATE=CELT_SET_BITRATE &&
## XXX -DCELT_SET_VBR_RATE=... is needed to compile against celt 0.11
#make_single &&
#make &&
#make_normal
