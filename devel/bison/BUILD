  OPTS="$OPTS --build=${BUILD}"
  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

  ./configure --prefix=${TRACK_ROOT}/usr  \
          --sysconfdir=${TRACK_ROOT}/etc  \
       --localstatedir=${TRACK_ROOT}/var  \
              --mandir=${TRACK_ROOT}/usr/share/man   \
             --infodir=${TRACK_ROOT}/usr/share/info  \
                       $OPTS                 &&
  sedit  's/examples //'  Makefile           &&  # breaks sans-g++ systems, and examples aren't needed
  make DESTDIR=$INSTALL_ROOT

