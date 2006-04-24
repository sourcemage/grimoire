./configure  --build=$BUILD                           \
            --prefix=${INSTALL_ROOT}/usr              \
        --sysconfdir=${INSTALL_ROOT}/etc              \
     --localstatedir=${INSTALL_ROOT}/var              \
    --with-kerneldir=/lib/modules/$(uname -r)/build/  \
                     $OPTS                            &&
make_single                                           &&
make
