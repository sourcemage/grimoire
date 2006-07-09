CFLAGS="$CFLAGS -I/usr/include/freetype2"
CXXFLAGS="$CFLAGS"
CPPFLAGS="$CPPFLAGS -I/usr/include/freetype2"
OPTS="$OPTS --enable-multithreaded $A4_PAPER"

patch -p1 < $SOURCE_CACHE/$SOURCE2  &&
default_build
