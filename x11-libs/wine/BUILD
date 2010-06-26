# touch non-existant file
touch programs/winetest/tests.rc &&

#
# Fixes http://bugs.winehq.com/show_bug.cgi?id=17406
#
if grep -q "\-O3" <<< $CFLAGS; then
  CFLAGS="-fno-guess-branch-probability $CFLAGS"      &&
  CXXFLAGS="-fno-guess-branch-probability $CXXFLAGS"
fi  &&

#
# Fixes http://bugs.winehq.org/show_bug.cgi?id=22316
#
if [[ ${SMGL_COMPAT_ARCHS[1]} == "ia32" ]] && $(grep -q "mfpmath=sse" <<< $CFLAGS); then
  CFLAGS="-mincoming-stack-boundary=2 $CFLAGS" &&
  CXXFLAGS="-mincoming-stack-boundary=2 $CXXFLAGS"
fi &&

OPTS="${OPTS} ${WINE64}" &&

default_build                     &&

if is_depends_enabled $SPELL docbook-utils; then
  make -C documentation
fi
