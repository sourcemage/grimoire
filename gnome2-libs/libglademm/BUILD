export SED=sed 					&&
patch -p1 < $SCRIPT_DIRECTORY/configure.patch	&&
autoconf					&&
CXXFLAGS+=' -std=gnu++11' && 
default_build
