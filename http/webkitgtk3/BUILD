OPTS="$WEBKIT_SVG $WEBKIT_WEBGL $OPTS" &&

CFLAGS+=" -fpermissive"   &&
CXXFLAGS+=" -fpermissive" &&

default_build_configure &&
make -j1 DerivedSources/WebCore/JSNode.h &&
default_build_make
