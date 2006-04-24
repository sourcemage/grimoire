  OPTS="$OPTS --build=${BUILD} ${NANO_OPTS}"
  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

  ./configure --prefix=${TRACK_ROOT}/usr  \
          --sysconfdir=${TRACK_ROOT}/etc  \
       --localstatedir=${TRACK_ROOT}/var  \
              --mandir=${TRACK_ROOT}/usr/share/man   \
             --infodir=${TRACK_ROOT}/usr/share/info  \
                       $OPTS                 &&
  make DESTDIR=$INSTALL_ROOT

