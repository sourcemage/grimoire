# function installed_version () { echo 2.4.77; }  &&
if [[ $(installed_version "linux") == 2.4.* ]] ; then
        OPROFILEOPT="--with-linux=/usr/src/$(installed_version "linux")"
else
        OPROFILEOPT="--with-kernel-support"
fi   &&
  ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
             $OPROFILEOPT                     \
                       $OPTS                 &&
  make
