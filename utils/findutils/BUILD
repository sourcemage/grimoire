OPTS="$FINDUTILS_OPTS $OPTS"
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

./configure --build=${BUILD} \
            --prefix=${TRACK_ROOT}/usr  \
        --sysconfdir=${TRACK_ROOT}/etc  \
        --libexecdir=${TRACK_ROOT}/usr/bin       \
     --localstatedir=${TRACK_ROOT}/var/cache  \
            --mandir=${TRACK_ROOT}/usr/share/man   \
           --infodir=${TRACK_ROOT}/usr/share/info  \
                       $OPTS                 &&

make DESTDIR=$INSTALL_ROOT
