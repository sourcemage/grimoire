export    CFLAGS="$CFLAGS -I/usr/include/freetype2"
export  CXXFLAGS="$CFLAGS"
export  CPPFLAGS="$CPPFLAGS -I/usr/include/freetype2"

export      OPTS="$OPTS --enable-multithreaded"

patch -p1 < $SOURCE_CACHE/$SOURCE2  &&
default_build
