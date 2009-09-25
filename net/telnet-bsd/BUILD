./configure  -prefix  ${INSTALL_ROOT}/usr            \
             -mandir  ${INSTALL_ROOT}/usr/share/man  \
             ${OPTS}                                 &&
if [[ "${TELNETBSD_CLIENT}" = 'y' ]]; then
  cd ${SOURCE_DIRECTORY}/telnet
fi &&
make
