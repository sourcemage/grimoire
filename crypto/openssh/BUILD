create_account sshd  &&

./configure  --prefix=${INSTALL_ROOT}/usr            \
             --sysconfdir=${INSTALL_ROOT}/etc/ssh    \
             --with-md5-passwords                    \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             $OPTS                                   &&

make
