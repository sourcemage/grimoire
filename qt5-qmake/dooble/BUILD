cd $SOURCE_DIRECTORY &&
if is_depends_enabled $SPELL qt6base;then
  CXXFLAGS+=" -Wno-deprecated" &&
  CXXFLAGS+=" -Wno-deprecated-declarations" &&
  CXXFLAGS+=" -Wno-switch" &&
  /opt/qt6/bin/qmake \
     QMAKE_CONFIG="$OPTS" QMAKE_CFLAGS="$CFLAGS" QMAKE_CXXFLAGS="$CXXFLAGS" \
  dooble.pro &&
  make
else
  qt5_build  
fi
