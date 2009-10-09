# fix bad moc files
if is_depends_enabled $SPELL qt4;then
  MOC=/usr/bin/qt4/moc &&
  cd qt4  &&
  $MOC pinentrydialog.h > pinentrydialog.moc   &&
  $MOC qsecurelineedit.h > qsecurelineedit.moc &&
  cd ..
fi  &&
OPTS="$OPTS $PINENTRY_CURSES"  &&
default_build
