if [ "${SMGL_COMPAT_ARCHS[1]}" ]; then
  CFLAGS="${CFLAGS} -fPIC"
fi &&

./configure --prefix=${INSTALL_ROOT}/usr                 \
        --sysconfdir=${INSTALL_ROOT}/etc                 \
     --localstatedir=${INSTALL_ROOT}/var                 \
            --mandir=${INSTALL_ROOT}/usr/share/man       \
           --infodir=${INSTALL_ROOT}/usr/share/info      \
                     $OPTS                               &&

make LDFLAGS="${LDFLAGS//-Wl,}"
