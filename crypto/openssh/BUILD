CFLAGS+=" -Wno-deprecated-declarations"
create_account sshd  &&

./configure  --prefix=${INSTALL_ROOT}/usr            \
             --sysconfdir=${INSTALL_ROOT}/etc/ssh    \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --without-zlib-version-check            \
             $OPTS                                   &&

make
