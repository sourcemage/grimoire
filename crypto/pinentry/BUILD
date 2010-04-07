# fix bad moc files
if is_depends_enabled $SPELL qt4;then
  QTDIR=/usr/bin/qt4 &&
  PATH=$QTDIR:$PATH  &&
  cd qt4  &&
  moc pinentrydialog.h > pinentrydialog.moc   &&
  moc qsecurelineedit.h > qsecurelineedit.moc &&
  cd ..
fi  &&
OPTS="$OPTS $PINENTRY_CURSES"  &&
default_build
