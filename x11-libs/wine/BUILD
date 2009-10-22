# touch non-existant file
touch programs/winetest/tests.rc &&

#
# Fixes http://bugs.winehq.com/show_bug.cgi?id=17406
#
if grep -q "\-O3" <<< $CFLAGS; then
  CFLAGS="-fno-guess-branch-probability $CFLAGS"      &&
  CXXFLAGS="-fno-guess-branch-probability $CXXFLAGS"
fi  &&

OPTS="${OPTS} ${WINE64}" &&

default_build                     &&

if is_depends_enabled $SPELL docbook-utils; then
  make -C documentation
fi
