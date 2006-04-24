invoke_gcc                                                  &&
patch -p1 < $SCRIPT_DIRECTORY/OpenSP-1.5.1-LITLEN-1.patch   &&
patch -p1 < $SCRIPT_DIRECTORY/OpenSP-1.5.1-gcc34-1.patch    &&

./configure --prefix=${INSTALL_ROOT}/usr                    \
            --sysconfdir=${INSTALL_ROOT}/etc                \
            --localstatedir=${INSTALL_ROOT}/var             \
            --mandir=${INSTALL_ROOT}/usr/share/man          \
            --infodir=${INSTALL_ROOT}/usr/share/info        \
            --enable-http                                   \
            --enable-xml-messages                           \
            --enable-default-catalog=/etc/sgml/catalog      \
            --enable-default-search-path=/usr/share/sgml    \
            --enable-splibdir=${INSTALL_ROOT}/usr/lib       \
            $OPTS                                           &&

make pkgdatadir=/usr/share/sgml/OpenSP

