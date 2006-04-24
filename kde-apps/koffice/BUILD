#gcc3.3 bugfix
if [[ $(gcc -dumpversion)   == 3.3* ]] ; then
  sedit  "s/-ansi//g"      configure  &&
  sedit  "s/-pedantic//g"  configure 
fi  &&

OPTS="$KOFFICE_KROSS  \
      $OPTS"          &&

source  $SECTION_DIRECTORY/KDE_BUILD
