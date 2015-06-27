# fix bad moc files
if is_depends_enabled $SPELL qt4;then
  export QTDIR=$INSTALL_ROOT/opt/qt4 &&
  export PATH=$QTDIR/bin:$PATH  &&
  export PKG_CONFIG_PATH=$QTDIR/lib/pkgconfig/ &&
  cd qt4  &&
  moc pinentrydialog.h > pinentrydialog.moc   &&
  moc qsecurelineedit.h > qsecurelineedit.moc &&
  cd ..
fi  &&
OPTS="$OPTS $PINENTRY_CURSES $PINENTRY_TTY" MOC="$QTDIR/bin/moc" CXXFLAGS="-std=c++11 ${CXXFLAGS}" default_build
