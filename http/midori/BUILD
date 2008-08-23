if [[ $MIDORI_VCS == y ]]; then
  ./waf --prefix=${INSTALL_ROOT}/usr configure &&
  ./waf build                                  
else
  OPTS="--prefix=${INSTALL_ROOT}/usr \
        --sysconfdir=${INSTALL_ROOT}/etc \
        --localstatedir=${INSTALL_ROOT}/var \
        --mandir=${INSTALL_ROOT}/usr/share/man \
        --infodir=${INSTALL_ROOT}/usr/share/info \
                 $OPTS" &&

  ./autogen.sh $OPTS &&
  make
fi
