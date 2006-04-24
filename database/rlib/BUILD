if  spell_ok  python;  then
  OPTS="--with-pythonver=`installed_version python|cut -c-3` $OPTS"
fi						&&

if  spell_ok  perl;  then
  local PP
  PP=`installed_version perl`
  OPTS="--with-perl-module=/usr/lib/perl5/site_perl/${PP}/*-linux-* $OPTS"
  OPTS="--with-perl-include=/usr/lib/perl5/${PP}/*-linux-*/CORE $OPTS"
fi                                              &&

default_build
