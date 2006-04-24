# this is recommended by the author
CFLAGS=${CFLAGS/-O3/-O2}      &&
CXXFLAGS=${CXXFLAGS/-O3/-O2}  &&
# doesn't compile with -DPIC -fPIC, bug #8426
CFLAGS=${CFLAGS/-DPIC/}       &&
CFLAGS=${CFLAGS/-fPIC/}       &&
CXXFLAGS=${CXXFLAGS/-DPIC/}   &&
CXXFLAGS=${CXXFLAGS/-fPIC/}   &&
default_build
