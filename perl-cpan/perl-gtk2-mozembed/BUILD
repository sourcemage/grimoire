perl Makefile.PL INSTALLDIRS=vendor $PERL_OPTS  &&
if test "$(get_spell_provider $SPELL GECKO)" = seamonkey; then
  # remove the b from MINOR VERSION as that breaks the version check macro
  sedit  's/0b/0/'  build/gtkmozembed2perl-version.h
fi  &&
make
