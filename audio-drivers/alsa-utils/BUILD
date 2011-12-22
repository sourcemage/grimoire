if [[ $ALSA_UTILS_BRANCH == scm ]]; then
  OPTS="--prefix=${INSTALL_ROOT}/usr \
    --sysconfdir=${INSTALL_ROOT}/etc \
 --localstatedir=${INSTALL_ROOT}/var \
        --mandir=${INSTALL_ROOT}/usr/share/man \
       --infodir=${INSTALL_ROOT}/usr/share/info \
                 $OPTS" &&
  ./gitcompile $OPTS
else
  default_build
fi
