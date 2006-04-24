create_account  courier                                  &&

OPTS="      --datadir=${INSTALL_ROOT}/usr/share/courier  \
         --sysconfdir=${INSTALL_ROOT}/etc/courier        \
      --localstatedir=${INSTALL_ROOT}/var/courier        \
      --without-stdheaderdir                             \
       --with-mailuser=courier                           \
      --with-mailgroup=courier                           \
      --disable-root-check                               \
      --with-shellpath=${PATH}                           \
      ${OPTS}"                                           &&

default_build
