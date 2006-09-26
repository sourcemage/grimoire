cd src                                                      &&
make -f Makefile.bootstrap makefile                         &&
sedit  "s/^CFLAGS\(.*\)/CFLAGS\1\ $CFLAGS/" Makefile        &&
sedit  "s/^CXXFLAGS\(.*\)/CXXFLAGS\1\ $CXXFLAGS/" Makefile  &&
make
