OPTS="--enable-dynamic-linking $OPTS"  &&

#sedit  "s/-O2/$CFLAGS/"  configure

./configure  --build=$BUILD                          \
            --prefix=${TRACK_ROOT}/usr              \
             --sysconfdir=${TRACK_ROOT}/etc          \
             --localstatedir=${TRACK_ROOT}/var/run   \
             --sbindir=${TRACK_ROOT}/sbin            \
             --mandir=${TRACK_ROOT}/usr/share/man   \
             $OPTS                                   &&

make DESTDIR=${INSTALL_ROOT}
