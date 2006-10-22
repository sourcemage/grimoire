cd ${SOURCE_DIRECTORY}/build/ac &&
autoreconf                      &&

OPTS="$OPTS --build=${BUILD}"

[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

./configure --prefix=${INSTALL_ROOT}/usr              \
            --sysconfdir=${INSTALL_ROOT}/etc          \
            --localstatedir=${INSTALL_ROOT}/var       \
            --mandir=${INSTALL_ROOT}/usr/share/man    \
            --infodir=${INSTALL_ROOT}/usr/share/info  \
            $OPTS                                     &&

cd ${SOURCE_DIRECTORY}          &&

make
