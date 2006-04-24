  patch  -p1  <  ${SCRIPT_DIRECTORY}/gcc-3.3.patch  &&
  invoke_gcc     &&
  ./configure  --prefix=/usr        \
               --sysconfdir=/etc    \
               --localstatedir=/var \
               --disable-debug      \
               $OPTS                &&
  make
