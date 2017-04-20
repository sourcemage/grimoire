# This seems wrong. Don't we have a standard thing for qtbase-dependent stuff?
if is_depends_enabled $SPELL qtbase; then
  . ${GRIMOIRE}/FUNCTIONS
  export PKG_CONFIG_PATH=$QT5BASE/lib/pkgconfig:$PKG_CONFIG_PATH
  OPTS="$OPTS --with-moc=$QT5BASE/bin/moc"
  OPTS="$OPTS --with-uic=$QT5BASE/bin/uic"
  OPTS="$OPTS --with-rcc=$QT5BASE/bin/rcc"
fi &&
default_build_configure &&
rake
