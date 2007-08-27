  OPTS="$OPTS --build=${BUILD}"
  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

  ./configure --prefix=${TRACK_ROOT}/usr  \
          --sysconfdir=${TRACK_ROOT}/etc  \
       --localstatedir=${TRACK_ROOT}/var  \
              --mandir=${TRACK_ROOT}/usr/share/man   \
             --infodir=${TRACK_ROOT}/usr/share/info  \
                       $OPTS                 &&
if ! is_depends_enabled texinfo;  then
 message "texinfo is DISabled"
 sedit 's/lib\ doc\ src/lib\ src/' Makefile
fi                                           &&

make DESTDIR=$INSTALL_ROOT
