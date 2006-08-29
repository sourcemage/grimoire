make_single &&
  ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
                       $OPTS                 &&
sedit "s:RANLIB = @RANLIB@:RANLIB = /usr/bin/ranlib:" lib/Makefile  &&
make &&
make_normal &&
make install
