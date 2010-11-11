OPTS="$OPTS --build=${BUILD}"
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

FORCE_UNSAFE_CONFIGURE=1 ./configure --prefix=${INSTALL_ROOT}/usr  \
        --sysconfdir=${INSTALL_ROOT}/etc  \
            --bindir=${INSTALL_ROOT}/bin  \
        --libexecdir=${INSTALL_ROOT}/bin  \
     --localstatedir=${INSTALL_ROOT}/var  \
            --mandir=${INSTALL_ROOT}/usr/share/man   \
           --infodir=${INSTALL_ROOT}/usr/share/info  \
                     $OPTS                 &&
make
