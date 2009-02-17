# fix wine build problem
LDFLAGS=${LDFLAGS//-z combreloc/} &&

# touch non-existant file
touch programs/winetest/tests.rc &&
default_build &&


if is_depends_enabled $SPELL docbook-utils; then
  make -C documentation
fi
