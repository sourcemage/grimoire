# fix wine build problem
LDFLAGS=${LDFLAGS//-z combreloc/}               &&
OPTS="--disable-debug  \
      --disable-trace  \
      $OPTS"           &&

# touch non-existant file
touch programs/winetest/tests.rc                &&
default_build                                   &&

#
## Remove this after is_depends_enabled is integrated to stable sorcery.
#
source  "$GRIMOIRE/is_depends_enabled.function"  &&

if is_depends_enabled $SPELL docbook-utils;  then
  make  -C  documentation
fi
