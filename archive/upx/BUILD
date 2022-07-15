# XXX Build uses -Werror
cd $SOURCE_DIRECTORY/src &&
make CHECK_WHITESPACE="$TRACK_ROOT"/bin/true CXXFLAGS_WERROR="" all &&

if spell_installed perl; then
  cd $SOURCE_DIRECTORY/doc &&
  make upx.1
fi
