./configure  --build=$BUILD                       \
             --prefix=${TRACK_ROOT}/usr         \
             --sysconfdir=${TRACK_ROOT}/etc     \
             --localstatedir=${TRACK_ROOT}/var  \
             $OPTS                                &&
make  clean                                       &&
make DESTDIR="${INSTALL_ROOT}/"
