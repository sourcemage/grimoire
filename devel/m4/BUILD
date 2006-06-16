OPTS="$OPTS --build=${BUILD}"
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

./configure  --build=$BUILD                \
             --prefix=${TRACK_ROOT}/usr    \
             --infodir=/usr/share/info     \
             $OPTS                         &&
make DESTDIR=$INSTALL_ROOT

