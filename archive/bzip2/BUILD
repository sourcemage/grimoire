sedit  "s/-O/-fPIC ${CFLAGS}/;s|)/man|)/share/man|;/^LDFLAGS/d"  Makefile  &&
sedit  "s/-O/${CFLAGS}/;s|)/man|)/share/man|;/^LDFLAGS/d"            \
       Makefile-libbz2_so                                                   &&

rm  -vf  ${INSTALL_ROOT}/usr/bin/bzgrep   &&
rm  -vf  ${INSTALL_ROOT}/usr/bin/bzegrep  &&
rm  -vf  ${INSTALL_ROOT}/usr/bin/bzfgrep  &&
rm  -vf  ${INSTALL_ROOT}/usr/bin/bzless   &&
rm  -vf  ${INSTALL_ROOT}/usr/bin/bzcmp    &&

make  PREFIX=${INSTALL_ROOT}/usr  &&
make  -f  Makefile-libbz2_so
