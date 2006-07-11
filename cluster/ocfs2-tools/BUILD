if  [  "$OCFS2_CONSOLE"  ==  "y"  ];  then
  OPTS="--enable-ocfs2console=yes ${OPTS}"
else
  OPTS="--enable-ocfs2console=no --disable-glibtest ${OPTS}"
fi  &&

make_single                                       &&

./configure  --build=$BUILD                       \
             --prefix=${INSTALL_ROOT}/usr         \
             --sbindir=${INSTALL_ROOT}/sbin       \
             --sysconfdir=${INSTALL_ROOT}/etc     \
             --localstatedir=${INSTALL_ROOT}/var  \
             --enable-dynamic-ctl                 \
             --enable-dynamic-fsck                \
             $OPTS                                &&

make                                              &&

make_normal
