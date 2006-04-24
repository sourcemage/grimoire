sedit "s:/usr/local/share:/usr/share/:" electricsheep.c  &&
sedit "s/-Werror//" ./mpeg2dec/configure  &&

  ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
                       $OPTS                 &&
  make
