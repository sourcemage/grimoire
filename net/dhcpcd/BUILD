./configure  --build=$BUILD                         \
             --prefix=${TRACK_ROOT}                 \
             --sysconfdir=${TRACK_ROOT}/etc         \
             --mandir=${TRACK_ROOT}/usr/share/man   \
             --infodir=${TRACK_ROOT}/usr/share/info \
             --localstatedir=${TRACK_ROOT}/var      \
             $OPTS                     &&

make DESTDIR=${INSTALL_ROOT}
