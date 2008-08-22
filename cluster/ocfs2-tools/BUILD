local MY_OPTS="--enable-dynamic-ctl --enable-dynamic-fsck ${OPTS}"  &&

unset OPTS                                        &&

if  [  "$OCFS2_CONSOLE"  ==  "y"  ];  then
  MY_OPTS="--enable-ocfs2console=yes ${MY_OPTS}"
else
  MY_OPTS="--enable-ocfs2console=no --disable-glibtest ${MY_OPTS}"
fi  &&

./configure  --build=$BUILD                       \
             --prefix=${INSTALL_ROOT}/usr         \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --sbindir=${INSTALL_ROOT}/sbin       \
             --sysconfdir=${INSTALL_ROOT}/etc     \
             --localstatedir=${INSTALL_ROOT}/var  \
             --enable-dynamic-ctl                 \
             --enable-dynamic-fsck                \
             $MY_OPTS                             &&

make
