create_account sshd  &&

./configure  --prefix=${INSTALL_ROOT}/usr            \
             --sysconfdir=${INSTALL_ROOT}/etc/ssh    \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             $SSH_MD5 $OPTS                                   &&

make
