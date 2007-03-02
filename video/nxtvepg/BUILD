sedit  "s:prefix.*=.*/usr/local:prefix = ${INSTALL_ROOT}/usr:"  Makefile &&
sed -i '/mandir  =/ s,man/man,share/&,' Makefile &&
make_single &&
make &&
make_normal
