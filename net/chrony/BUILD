./configure --prefix=${INSTALL_ROOT}/usr \
            --mandir=${INSTALL_DIR}/usr/share/man \
           --infodir=${INSTALL_DIR}/usr/share/info \
                     ${CHRONY_OPTS} ${OPTS} &&
make &&

if is_depends_enabled $SPELL texinfo; then
  make docs
fi
