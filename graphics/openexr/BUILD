if [[ $RESTEST == y ]]; then
  OPTS="$OPTS -DOPENEXR_RUN_FUZZ_TESTS=on"
fi &&

OPTS+=" -DBUILD_SHARED_LIBS=on" &&
OPTS+=" -DOPENEXR_INSTALL_PKG_CONFIG=on" &&
OPTS+=" -DOPENEXR_USE_CLANG_TIDY=off" &&
OPTS+=" -DBUILD_TESTING=off" &&
OPTS+=" -DOPENEXR_BUILD_EXAMPLES=OFF" &&
# On GCC, OPENEXR_EXPORT_TEMPLATE_INSTANCE expands to nothing (the branch
# defining it needs clang's __type_visibility__), so the explicit
# instantiations of TypedAttribute<> never export their ctor/dtor/typeinfo
# and exrheader and the examples fail to link.
OPTS+=" -DOPENEXR_USE_DEFAULT_VISIBILITY=ON" &&

CXXFLAGS="${CXXFLAGS} -fpermissive" LDFLAGS="${LDFLAGS} -lpthread" default_build
