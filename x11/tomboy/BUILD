if [ "$TOMBOY_CVS" == "y" ] ; then
    ./autogen.sh  --prefix=${INSTALL_ROOT}/usr  \
              --sysconfdir=${INSTALL_ROOT}/etc  \
           --localstatedir=${INSTALL_ROOT}/var  \
                  --mandir=${INSTALL_ROOT}/usr/share/man   \
                 --infodir=${INSTALL_ROOT}/usr/share/info  \
                           $OPTS                 &&
    make
else
    default_build
fi
