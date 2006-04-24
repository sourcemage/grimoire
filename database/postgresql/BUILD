  ./configure  --build=$BUILD                          \
               --prefix=${INSTALL_ROOT}/usr            \
               --with-docdir=${INSTALL_ROOT}/usr/share/doc  \
               --mandir=${INSTALL_ROOT}/usr/share/man  \
               --sysconfdir=${INSTALL_ROOT}/etc        \
               --localstatedir=${INSTALL_ROOT}/var     \
               --enable-syslog          \
               --with-CXX               \
               --target=$HOST           \
               $OPTS                    &&
  make                                  &&
  cd      contrib/pgcrypto              &&
  make
