OPTS="--without-hotplug $OPTS"            &&

./configure   --host=${HOST}              \
             --build=${BUILD}             \
            --prefix=${INSTALL_ROOT}/usr  \
        --sysconfdir=${INSTALL_ROOT}/etc  \
     --localstatedir=${INSTALL_ROOT}/var  \
                     $OPTS                &&
make_single                               &&
make
