OPTS+=" --enable-dynamic-linking ${SYSLOG_NG_OPTS}"  &&

./configure  --build=$BUILD                          \
            --prefix=${TRACK_ROOT}/usr              \
             --sysconfdir=${TRACK_ROOT}/etc/syslog-ng \
             --localstatedir=${TRACK_ROOT}/var/run   \
             --sbindir=${TRACK_ROOT}/sbin            \
             --mandir=${TRACK_ROOT}/usr/share/man   \
             $OPTS                                   &&

make DESTDIR=${INSTALL_ROOT}
