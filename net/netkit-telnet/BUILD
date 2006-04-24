  patch  -p1  <  $SCRIPT_DIRECTORY/gcc3.patch &&
  ./configure  --prefix=${INSTALL_ROOT}/usr  --with-c++-compiler=g++  $OPTS  &&
  sedit 's:/man:/share/man:'  MCONFIG  &&
  make  
