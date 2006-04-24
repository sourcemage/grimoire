  sed -i "s/-O2//" specs/linux-g++ &&

  python ./configure.py -l qt-mt  -p linux-g++ INCDIR_QT=/usr/include/qt \
         CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS} -fno-exceptions"           &&
  make
