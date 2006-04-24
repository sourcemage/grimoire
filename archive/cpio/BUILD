#
# The mt-st package installs the mt manpage
#
sedit  's: mt.1::'  doc/Makefile.am  &&
sedit  's: mt.1::'  doc/Makefile.in  &&

  OPTS="$OPTS --build=${BUILD}"
  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

  ./configure --prefix=${TRACK_ROOT}/usr  \
          --sysconfdir=${TRACK_ROOT}/etc  \
       --localstatedir=${TRACK_ROOT}/var  \
              --mandir=${TRACK_ROOT}/usr/share/man   \
             --infodir=${TRACK_ROOT}/usr/share/info  \
                       $OPTS                 &&
  make DESTDIR=$INSTALL_ROOT

