OPTS="--enable-shadowgrp --build=${BUILD} $OPTS" &&

if [[ $CROSS_INSTALL == on ]]; then
  OPTS="--host=${HOST} $OPTS"
fi &&

./configure --prefix=${TRACK_ROOT}/usr  \
        --sysconfdir=${TRACK_ROOT}/etc  \
     --localstatedir=${TRACK_ROOT}/var  \
            --mandir=${TRACK_ROOT}/usr/share/man   \
           --infodir=${TRACK_ROOT}/usr/share/info  \
                     $OPTS                 &&

make DESTDIR=$INSTALL_ROOT
