sedit  "s:/usr/local/lib/libepplet.la:/usr/lib/libepplet.la:"  \
        src/Makefile.am                                        &&

EROOT=$INSTALL_ROOT/usr  EBIN=$INSTALL_ROOT/usr/bin   \
./autogen.sh  --build=$BUILD                          \
             --prefix=${INSTALL_ROOT}/usr             \
         --sysconfdir=${INSTALL_ROOT}/etc             \
      --localstatedir=${INSTALL_ROOT}/var             \
             --mandir=${INSTALL_ROOT}/usr/share/man   \
            --infodir=${INSTALL_ROOT}/usr/share/info  \
                      $OPTS                           &&

sedit  's:\-lX11:& -lGL:'  src/Makefile  &&

make
