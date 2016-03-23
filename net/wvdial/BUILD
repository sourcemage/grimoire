# Take same care as for wvstreams with optimization flags,
# also disable as-needed linking as that breaks the build.
CPPFLAGS="-D_DEFAULT_SOURCE=1 $CPPFLAGS" \
CXXFLAGS="$CXXFLAGS -fno-tree-dce -fno-optimize-sibling-calls" \
CFLAGS="$CFLAGS -fno-tree-dce -fno-optimize-sibling-calls" \
LDFLAGS=${LDFLAGS/-Wl,--as-needed/} \
default_build
