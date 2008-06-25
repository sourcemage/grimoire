if [ "$SKIPSTONE_WEBKIT" = 'n' ]; then
  default_build
else
  ./configure  --prefix=${INSTALL_ROOT}/usr             \
               --sysconfdir=${INSTALL_ROOT}/etc         \
               --infodir=${INSTALL_ROOT}/usr/share/info \
               --mandir=${INSTALL_ROOT}/usr/share/man   \
               --localstatedir=${INSTALL_ROOT}/var      \
               --disable-mozilla                        \
               $OPTS                                    &&
  cd src                                                &&
  make -f Makefile.webkit
fi
