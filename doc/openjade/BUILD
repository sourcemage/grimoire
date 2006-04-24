invoke_gcc                                               &&

./configure --prefix=${INSTALL_ROOT}/usr                 \
            --sysconfdir=${INSTALL_ROOT}/etc             \
            --localstatedir=${INSTALL_ROOT}/var          \
            --mandir=${INSTALL_ROOT}/usr/share/man       \
            --infodir=${INSTALL_ROOT}/usr/share/info     \
            --enable-http                                \
            --enable-default-catalog=/etc/sgml/catalog   \
            --enable-default-search-path=/usr/share/sgml \
            --datadir=/usr/share/sgml/OpenJade           \
            --enable-splibdir=${INSTALL_ROOT}/usr/lib    \
            $OPTS                                        &&

make

