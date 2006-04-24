if [ "$DOCUMENTATION" = "n" ]; then

  ./configure --prefix=${INSTALL_ROOT}/usr  \
  --sysconfdir=${INSTALL_ROOT}/etc          \
  --localstatedir=${INSTALL_ROOT}/var       \
  --mandir=${INSTALL_ROOT}/usr/share/man    \
  --infodir=${INSTALL_ROOT}/usr/share/info  \
  --target=$HOST                            \
  $OPTS                                     &&
  make without_doc

else

  default_build

fi
