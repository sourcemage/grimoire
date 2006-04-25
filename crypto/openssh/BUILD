create_account sshd  &&
if [ "$SELINUX" == "y" ] ; then
  patch -p1 < $SCRIPT_DIRECTORY/openssh-3.9_p1-selinux.diff
fi &&
./configure  --prefix=${INSTALL_ROOT}/usr            \
             --sysconfdir=${INSTALL_ROOT}/etc/ssh    \
             --with-md5-passwords                    \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             $OPTS                                   &&

make
