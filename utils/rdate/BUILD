  patch  -p1  <  ${SCRIPT_DIRECTORY}/gcc-3.3.patch  &&
  sedit  "s/-O2/$CFLAGS/"  Makefile                 &&
sed -i "s,man/man1,share/&," Makefile &&

  make 
