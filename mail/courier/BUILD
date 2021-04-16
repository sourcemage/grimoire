create_account courier &&

OPTS="${COURIER_OPTS}                             \
      --sysconfdir=${INSTALL_ROOT}/etc/courier    \
      --localstatedir=${INSTALL_ROOT}/var/courier \
      --datadir=${INSTALL_ROOT}/usr/share/courier \
      --with-shellpath=${PATH}                    \
      --disable-root-check                        \
      --with-mailuser=courier                     \
      --with-mailgroup=courier                    \
      --with-notice=unicode                       \
      ${OPTS}" &&

default_build
