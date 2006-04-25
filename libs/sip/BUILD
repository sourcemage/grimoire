  sed -i "s/-O2//" specs/linux-g++ &&

  python ./configure.py  \
         CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS} -fno-exceptions"           &&
  make
