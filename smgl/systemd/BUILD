if [[ $SYSTEMD_GIT == y ]]
then
  ./autogen.sh    --prefix=${INSTALL_ROOT}/ \
              --sysconfdir=${INSTALL_ROOT}/etc \
           --localstatedir=${INSTALL_ROOT}/var \
                  --mandir=${INSTALL_ROOT}/usr/share/man \
                 --infodir=${INSTALL_ROOT}/usr/share/info \
              --includedir=${INSTALL_ROOT}/usr/include \
               --localedir=${INSTALL_ROOT}/usr/share/locale \
             --with-distro=other \
                           $OPTS
else
  ./configure     --prefix=${INSTALL_ROOT}/ \
              --sysconfdir=${INSTALL_ROOT}/etc \
           --localstatedir=${INSTALL_ROOT}/var \
                  --mandir=${INSTALL_ROOT}/usr/share/man \
                 --infodir=${INSTALL_ROOT}/usr/share/info \
              --includedir=${INSTALL_ROOT}/usr/include \
               --localedir=${INSTALL_ROOT}/usr/share/locale \
             --with-distro=other \
                           $OPTS
fi
make
