OPTS="$OPTS --build=${BUILD}"
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

./configure  --build=$BUILD                       \
             --prefix=${TRACK_ROOT}/usr         \
             --sysconfdir=${TRACK_ROOT}/etc     \
             --localstatedir=${TRACK_ROOT}/var  \
             $OPTS                                &&

make DESTDIR=$INSTALL_ROOT

