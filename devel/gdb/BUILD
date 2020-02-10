OPTS="$OPTS --disable-werror"    &&

disable_pic                      &&
disable_fortify_source           &&

mkdir build                      &&
cd    build                      &&

 ../configure --prefix=${INSTALL_ROOT}/usr                 \
          --sysconfdir=${INSTALL_ROOT}/etc                 \
       --localstatedir=${INSTALL_ROOT}/var                 \
              --mandir=${INSTALL_ROOT}/usr/share/man       \
             --infodir=${INSTALL_ROOT}/usr/share/info      \
                       $OPTS &&

default_build_make
