create_account postgres &&

# -ffast-math breaks compiling. this brings no side-effects
CFLAGS=${CFLAGS/-ffast-math/} &&

./configure --build=$BUILD                              \
            --prefix=${INSTALL_ROOT}/usr                \
            --with-docdir=${INSTALL_ROOT}/usr/share/doc \
            --mandir=${INSTALL_ROOT}/usr/share/man      \
            --sysconfdir=${INSTALL_ROOT}/etc            \
            --localstatedir=${INSTALL_ROOT}/var         \
            --enable-syslog                             \
            --with-CXX                                  \
            --target=$HOST                              \
            $OPTS                                       &&

make &&

# build cryptographic functions support by default
cd contrib/pgcrypto &&
make &&

if is_depends_enabled $SPELL libxml2; then
  cd ../xml2 &&
  make
fi
