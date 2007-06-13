if [[ "${PILOTLINK_THREAD}" == "y" ]]; then
   OPTS="--enable-threads ${OPTS}"
fi                                                &&

OPTS="--disable-debug --enable-conduits ${OPTS}"  &&

make_single                                       &&
default_build                                     &&
make_normal
