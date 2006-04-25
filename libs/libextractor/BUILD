./configure --prefix=${INSTALL_ROOT}/usr                           \
        --sysconfdir=${INSTALL_ROOT}/etc                           \
     --localstatedir=${INSTALL_ROOT}/var                           \
            --mandir=${INSTALL_ROOT}/usr/share/man                 \
           --infodir=${INSTALL_ROOT}/usr/share/info                \
                     $OPTS                                         &&

#
# Fix linking, otherwise it can't find the libs. :(
#
sedit  's:-lgobject-2.0:-L/usr/lib &:'  src/plugins/ole2/Makefile  &&
sedit  's:-lglib-2.0:-L/usr/lib &:'     src/plugins/ole2/Makefile  &&

make_single  &&
make         &&
make_normal
