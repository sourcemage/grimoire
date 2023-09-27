cd $SOURCE_DIRECTORY &&
if is_depends_enabled $SPELL qt6base;then
  /opt/qt6/bin/qmake \
     QMAKE_CONFIG="$OPTS" QMAKE_CFLAGS="$CFLAGS" QMAKE_CXXFLAGS="$CXXFLAGS" \
  qalculate-qt.pro PREFIX=$INSTALL_ROOT/usr &&
  make
else
  qt5_build  
fi
