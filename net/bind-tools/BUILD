./configure  --prefix=${INSTALL_ROOT}/usr             \
         --sysconfdir=${INSTALL_ROOT}/etc             \
      --localstatedir=${INSTALL_ROOT}/var             \
             --mandir=${INSTALL_ROOT}/usr/share/man   \
            --infodir=${INSTALL_ROOT}/usr/share/info  \
                      $OPTS                           &&

make_single  &&
#
# The order here is important
#
make -C lib/bind     &&
make -C lib/lwres    &&
make -C lib/dns      &&
make -C lib/isc      &&
make -C lib/isccfg   &&
make -C lib/bind9    &&
cd bin/dig           &&
make                 &&
make_normal
