# don't make it track all info files in /usr/share/info
#  sedit  's:${COPYDESTS} ${infodir}:${COPYDESTS}:'  Makefile.in  &&

# Fixes Bug #2938
export  LDFLAGS="${LDFLAGS/-z combreloc/}"  &&

#
# Fails to link if using -Wl,-O1
#
export LDFLAGS="${LDFLAGS//-Wl,-O1/}"  &&

if [ "$VCS" == "y" ]; then
  # Crashes with -O3
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
  default_build
fi
