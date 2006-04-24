OPTS="$OPTS --build=${BUILD}"
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

./configure --prefix=${TRACK_ROOT}/usr  \
        --sysconfdir=${TRACK_ROOT}/etc  \
            --bindir=${TRACK_ROOT}/bin  \
        --libexecdir=${TRACK_ROOT}/bin  \
     --localstatedir=${TRACK_ROOT}/var  \
            --mandir=${TRACK_ROOT}/usr/share/man   \
           --infodir=${TRACK_ROOT}/usr/share/info  \
                     $OPTS                 &&
make DESTDIR=$INSTALL_ROOT

