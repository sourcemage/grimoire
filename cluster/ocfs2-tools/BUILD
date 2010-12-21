./configure  --build=$BUILD                       \
             --prefix=${INSTALL_ROOT}/usr         \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --sbindir=${INSTALL_ROOT}/sbin       \
             --sysconfdir=${INSTALL_ROOT}/etc     \
             --localstatedir=${INSTALL_ROOT}/var  \
             --enable-dynamic-ctl                 \
             --enable-dynamic-fsck                \
             --disable-glibtest                   \
             $OCFS2_TOOLS_OPTS                    &&

make_single &&
make &&
make_normal
