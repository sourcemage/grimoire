default_build  &&

#
# Build shared library, too
#
pushd  ELFIO                                        &&
g++  $CXXFLAGS $LDFLAGS -shared *.o -o libelfio.so  &&
popd
