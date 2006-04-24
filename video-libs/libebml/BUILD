if use_gcc ^4.0; then
  # generates wrong code with -Os and higher
  CXXFLAGS="$CXXFLAGS -O1"
fi  &&
cd  make/linux   &&
sedit  "s:/usr/local:${INSTALL_ROOT}/usr:"  Makefile  &&
make
