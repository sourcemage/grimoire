# Build is broken with as-needed, as of version 0.7.8.
# Patches floating around don't fix all issues we encounter.
LDFLAGS="$LDFLAGS -Wl,--no-as-needed" &&
if is_depends_enabled $SPELL qt4 ; then
  qt4_cmake_build
else
  cmake_build
fi
