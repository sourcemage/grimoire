  # don't make it track all info files in /usr/share/info
#  sedit  's:${COPYDESTS} ${infodir}:${COPYDESTS}:'  Makefile.in  &&
  # Fixes Bug #2938
  export  LDFLAGS="${LDFLAGS/-z combreloc/}"  &&
if [ "$CVS" == "y" ]; then
  # Crashes with -03
  export  CFLAGS="${CFLAGS//-O3/-O2}"      &&
  
  OPTS="$OPTS --build=${BUILD}"

  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

  ./configure --prefix=${INSTALL_ROOT}/usr  \
              --sysconfdir=${INSTALL_ROOT}/etc  \
              --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
              --infodir=${INSTALL_ROOT}/usr/share/info  \
              $OPTS                 &&
  make bootstrap
else 
  # add support for AMD64 (modified patch from Gentoo)
  patch -p1 < $SCRIPT_DIRECTORY/emacs-21-amd64.diff &&
  default_build
fi
