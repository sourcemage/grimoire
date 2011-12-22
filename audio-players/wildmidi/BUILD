OPTS="${OPTS} --with-wildmidi-cfg=/etc/wildmidi.cfg" &&
sedit 's/-Wall //' configure &&
./configure --prefix=${INSTALL_ROOT}/usr  \
            --sysconfdir=${INSTALL_ROOT}/etc  \
            --localstatedir=${INSTALL_ROOT}/var  \
            --mandir=${INSTALL_ROOT}/usr/share/man   \
            --infodir=${INSTALL_ROOT}/usr/share/info  \
            $OPTS  &&
make
