OPTS="KERNELDIR=${INSTALL_ROOT}/usr/src/linux ${OPTS}" &&

if ! is_depends_enabled ${SPELL} iproute2; then
  OPTS="WITH_SYSTEMDUNITS=no ${OPTS}"
fi &&

cd src &&

make ${OPTS}
