# disable pic won't be sufficient as this needs to be disabled also
# on 64bit(it builds only as 32)
CFLAGS=${CFLAGS/-fPIC}       &&
CFLAGS=${CFLAGS/-DPIC}       &&
CXXFLAGS=${CXXFLAGS/-fPIC}   &&
CXXFLAGS=${CXXFLAGS/-DPIC}   &&
make
