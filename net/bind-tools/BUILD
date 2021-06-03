disable_reject_underlinking &&
./configure  --prefix=${INSTALL_ROOT}/usr             \
         --sysconfdir=${INSTALL_ROOT}/etc             \
      --localstatedir=${INSTALL_ROOT}/var             \
             --mandir=${INSTALL_ROOT}/usr/share/man   \
            --infodir=${INSTALL_ROOT}/usr/share/info  \
            --without-libjson                         \
            --disable-fuzzing                         \
                      $OPTS                           &&

make_single  &&
#
# The order here is important
#
make -C lib          &&
make -C bin/delv     &&
make -C bin/dig      &&
make -C bin/nsupdate &&
make -C bin/dnssec   &&
make -C doc/man man  &&

make_normal
