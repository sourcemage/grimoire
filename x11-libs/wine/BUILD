# touch non-existant file
touch programs/winetest/tests.rc &&

#
# Fixes http://bugs.winehq.com/show_bug.cgi?id=17406
#
CFLAGS=${CFLAGS/-O3/-O2}      &&
CXXFLAGS=${CXXFLAGS/-O3/-O2}  &&
default_build                 &&

if is_depends_enabled $SPELL docbook-utils; then
  make -C documentation
fi
