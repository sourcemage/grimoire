if ! spell_ok gettext; then
  aclocal                                   &&
  automake                                  &&
  sedit 's/AM_GNU_GETTEXT.*//' configure.ac &&
  autoconf                                  &&
  sedit 's/ po//'              Makefile.*
fi                                          &&
default_build

