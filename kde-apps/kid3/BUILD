OPTS="$KID3_KDE $OPTS"  &&

if [[ $KID3_KDE == "--with-kde" ]]
then
  default_build
else
  cd $SOURCE_DIRECTORY/kid3-qt &&
  OPTS="$OPTS --build=${BUILD}"
  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"
  ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
                       $OPTS &&
  sed -i -e 's/-lFLAC/-lFLAC++ -lFLAC/' kid3/Makefile &&
  make
fi
