if [ "$UNIHAN" == "y" ]; then
   OPTS="$OPTS --enable-unihan"
else
   OPTS="$OPTS --disable-unihan"
fi                               &&

if ! is_depends_enabled $SPELL gtk-doc; then
  OPTS="$OPTS --disable-scrollkeeper" &&
  sedit 's/help//' Makefile.in &&
  sedit 's/^HELP_DIR.*/HELP_DIR =/' Makefile.in &&
  sedit '/DIST_SUBDIRS/s/help//' Makefile.in
fi &&

default_build
