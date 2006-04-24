# we disable the 'magicktest' because configure can build but not
# link the Magick test prog and refuses to belive in Magick 
./configure  --disable-magicktest  \
              --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
                       $OPTS                 &&
make
