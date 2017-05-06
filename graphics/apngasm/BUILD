LIBS= &&
if is_depends_enabled $SPELL zopfli; then
  LIBS="$LIBS -lzopfli"
fi    &&
g++ $CPPFLAGS $CXXFLAGS $OPTS $LDFLAGS -o apngasm *.cpp -lpng -lz $LIBS
