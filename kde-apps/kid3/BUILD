OPTS="$KID3_KDE $OPTS"  &&

if [[ $KID3_KDE == "--with-kde" ]]
then
  default_build
else
  OPTS="$OPTS --build=${BUILD}"
  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"
  ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
                       $OPTS                 &&
  ./make_qtonly.sh
fi
